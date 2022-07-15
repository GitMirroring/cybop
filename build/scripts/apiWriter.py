import os
from itertools import groupby
from jinja2 import Template
from apiData import ApiItem

variable_template_raw = '''<node>{% for element in elements %}
    <node name="{{ element.name }}" channel="inline" format="text/plain" model="{{ element.name }}"/>{% endfor %}
</node>
'''

type_template_raw = '''<node>{% for element in elements %}
    <node name="{{ element.group }}" channel="file" format="element/part" model="api-generator/spec/{{ type }}/{{ element.group }}.cybol"/>{% endfor %}
</node>
'''

group_template_raw = '''<node>{% for element in elements %}
    <node name="{{ element.specifier }}" channel="file" format="element/part" model="api-generator/spec/{{ type }}/{{ element.group }}/{{ element.specifier }}.cybol"/>{% endfor %}
</node>
'''

specifier_template_raw = '''<node>
    <node name="description" channel="inline" format="text/plain" model="{{ element.description}}"/>
    <node name="examples" channel="file" format="text/plain" model="api-generator/spec/{{ element.type }}/{{ element.group }}/{{ element.specifier }}/examples.txt"/>{% if element.properties|length > 0 %}
    <node name="properties" channel="file" format="element/part" model="api-generator/spec/{{ element.type }}/{{ element.group }}/{{ element.specifier }}/properties.cybol"/>{% endif %}
</node>

'''
properties_template_raw = '''<node>{% for property in properties %}
    <node name="{{ property.name }}" channel="inline" format="text/plain" model="">
        <node name="required" channel="inline" format="logicvalue/boolean" model="{{ property.required }}"/>
        <node name="format" channel="inline" format="text/plain" model="{{ property.format }}"/>
        <node name="description" channel="inline" format="text/plain" model="{{ property.description }}"/>
    </node>{% endfor %}
</node>

'''


class Writer:
    def __init__(self, api_items: []):
        self.api_items = api_items
        self.basePath = os.path.join(os.path.dirname(__file__), '..', '..')
        self.path_to_format = os.path.join(self.basePath, 'src', 'constant', 'format', 'cybol')
        self.spec_output_path = os.path.join(self.basePath, 'tools', 'api-generator', 'spec')
        self.variable_types = { 'encoding', 'channel' }

    def update_api_data(self):
        for type_group_key, grouped_by_types_list in groupby(self.api_items, key=lambda element: element.type):
            type_group = list(grouped_by_types_list)
            if type_group_key in self.variable_types:
                self.__write_variable_groups(type_group, type_group_key)
            else:
                self.__write_type_groups(type_group, type_group_key)
                for group_key, grouped_by_group_list in groupby(type_group, key=lambda element: element.group):
                    group = list(grouped_by_group_list)
                    self.__write_groups(group, type_group_key, group_key)
                    # skipping type_group template at the moment
                    for element in group:
                        self.__write_specifier(element)
                        self.__write_examples(element)
                        self.__write_properties(element)

    def __write_variable_groups(self, elements, type):
        file_path = os.path.join(self.spec_output_path, type + '.cybol')
        os.makedirs(os.path.dirname(file_path), exist_ok=True)
        Template(variable_template_raw).stream(elements=elements).dump(file_path)

    def __write_type_groups(self, elements, type):
        file_path = os.path.join(self.spec_output_path, type + '.cybol')
        os.makedirs(os.path.dirname(file_path), exist_ok=True)
        Template(type_template_raw).stream(elements=elements, type=type).dump(file_path)

    def __write_groups(self, elements, type, group):
        file_path = os.path.join(self.spec_output_path, type, group + '.cybol')
        os.makedirs(os.path.dirname(file_path), exist_ok=True)
        Template(group_template_raw).stream(elements=elements, type=type).dump(file_path)

    def __write_specifier(self, element: ApiItem):
        file_path = os.path.join(self.spec_output_path, element.type, element.group, element.specifier + '.cybol')
        os.makedirs(os.path.dirname(file_path), exist_ok=True)
        Template(specifier_template_raw).stream(element=element).dump(file_path)

    def __write_examples(self, element: ApiItem):
        file_path = os.path.join(self.spec_output_path, element.type, element.group, element.specifier, 'examples.txt')
        os.makedirs(os.path.dirname(file_path), exist_ok=True)
        with open(file_path, 'w') as outfile:
            outfile.write(element.examples)

    def __write_properties(self, element: ApiItem):
        if len(element.properties) > 0:
            file_path = os.path.join(self.spec_output_path, element.type, element.group, element.specifier, 'properties.cybol')
            os.makedirs(os.path.dirname(file_path), exist_ok=True)
            Template(properties_template_raw).stream(properties=element.properties).dump(file_path)
