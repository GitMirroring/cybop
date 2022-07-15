import os
from itertools import groupby
from jinja2 import Template
from apiData import ApiItem

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

    def update_api_data(self):
        for type_group_key, grouped_by_types_list in groupby(self.api_items, key=lambda element: element.type):
            type_group = list(grouped_by_types_list)
            self.__write_type_groups(type_group, type_group_key)
            for group_key, grouped_by_group_list in groupby(type_group, key=lambda element: element.group):
                group = list(grouped_by_group_list)
                self.__write_groups(group, type_group_key, group_key)
                # skipping type_group template at the moment
                for element in group:
                    self.__write_specifier(element)
                    self.__write_examples(element)
                    self.__write_properties(element)

    def __write_type_groups(self, elements, type):
        type_template = Template(type_template_raw)
        type_template_content = type_template.render(elements=elements, type=type)
        file_path = os.path.join(self.spec_output_path, type + '.cybol')
        self.__write_file(file_path, type_template_content)

    def __write_groups(self, elements, type, group):
        group_template = Template(group_template_raw)
        group_template_content = group_template.render(elements=elements, type=type)
        file_path = os.path.join(self.spec_output_path, type, group + '.cybol')
        self.__write_file(file_path, group_template_content)

    def __write_specifier(self, element: ApiItem):
        specifier_template = Template(specifier_template_raw)
        specifier_template_content = specifier_template.render(element=element)
        file_path = os.path.join(self.spec_output_path, element.type, element.group, element.specifier + '.cybol')
        self.__write_file(file_path, specifier_template_content)

    def __write_examples(self, element: ApiItem):
        file_path = os.path.join(self.spec_output_path, element.type, element.group, element.specifier, 'examples.txt')
        self.__write_file(file_path, element.examples)

    def __write_properties(self, element: ApiItem):
        if len(element.properties) > 0:
            properties_template = Template(properties_template_raw)
            properties_template_content = properties_template.render(properties=element.properties)
            file_path = os.path.join(self.spec_output_path, element.type, element.group, element.specifier, 'properties.cybol')
            self.__write_file(file_path, properties_template_content)

    def __write_file(self, path_to_file: str, content: str):
        os.makedirs(os.path.dirname(path_to_file), exist_ok=True)
        with open(path_to_file, 'w') as outfile:
            outfile.write(content)
