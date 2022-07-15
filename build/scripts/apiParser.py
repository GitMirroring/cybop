import os
import unittest
import re
from re import Pattern
from apiWriter import Writer
from apiData import ApiItem, ApiProperty


class Parser:
    def __init__(self):
        self.api_regex = re.compile(
            "\/\*\*\s(?P<brief>.*)([\*\s]*?)(?=Description:)([\W\w\s]*?)static wchar_t\* .*(?P<type>LOGIC|STATE).* = L\"(?P<name>.*)\";")
        self.description_regex = re.compile("Description:\s(?P<description>[\W\w\s]*?)(Examples:|Properties:|(\*\/))")
        self.example_regex = re.compile("Examples:\s \*\s(?P<examples>[\W\w]*?)(Properties:|(\*\/))")
        self.property_regex = re.compile("@param (?P<name>.*) \((?P<required>.*)\) \[(?P<format>.*)\]: (?P<description>.*)")
        #self.channel_regex = re.compile("^(?:static wchar_t\* )[A-Z_]+(?: = L\")(?P<channel>.+)(?:\";)")
        self.basePath = os.path.join(os.path.dirname(__file__), '..', '..')
        self.path_to_format = os.path.join(self.basePath, 'src', 'constant', 'format', 'cybol')

    def parse_structure(self):
        api_items = []
        for path, dirs, files in os.walk(self.path_to_format):
            for file in files:
                api_items.extend(self.parse_api_javadoc(os.path.join(path, file)))

        return api_items

    def parse_api_javadoc(self, path_to_file: str):
        with open(path_to_file) as file_content:
            all_matched = re.findall(self.api_regex, file_content.read())
            return list(map(lambda x: self.__parse_javadoc_content(x), all_matched))

    def __parse_javadoc_content(self, api_element: Pattern[str]):
        api_item = ApiItem(api_element[4], api_element[0].lstrip(' *'), api_element[3].lower())
        content = api_element[2]
        api_item.description = ' '.join(
            list(filter(None,
                        map(lambda x: x.lstrip('*').lstrip(' *'),
                            self.description_regex.match(content).group("description").split(os.linesep)))))
        examples = self.example_regex.search(content)
        if examples:
            api_item.examples = os.linesep.join(list(map(lambda x: x[3:], examples.group("examples").rstrip(' *\n').split(os.linesep))))

        properties = self.property_regex.findall(content)
        for x in properties:
            api_item.properties.append(ApiProperty(x[0], x[1], x[2], x[3]))

        return api_item


class MyTestCase(unittest.TestCase):
    def test_parsing_logic(self):
        parser = Parser()
        result = parser.parse_api_javadoc('../../src/constant/format/cybol/logic/calculate_logic_cybol_format.c')
        self.assertEqual(1, len(result))
        self.assertEqual('The calculate/add logic cybol format.', result[0].brief)
        self.assertEqual('calculate/add', result[0].name)
        self.assertEqual('calculate', result[0].group)
        self.assertEqual('add', result[0].specifier)
        self.assertEqual('logic', result[0].type)
        self.assertEqual('Adds the operand to the result. CAUTION! Do NOT use the "add" operation for characters! They may be concatenated by using the "modify/append" or "modify/overwrite" operation. CAUTION! There are several ways to use addition, with unary or binary operators. This function works like an UNARY operator. The "result" parametre represents the FIRST operand; the "operand" parametre the SECOND.', result[0].description)
        self.assertIsNotNone(result[0].examples)
        self.assertEqual(5, len(result[0].properties))

    def test_parsing_state(self):
        parser = Parser()
        result = parser.parse_api_javadoc('../../src/constant/format/cybol/state/number_state_cybol_format.c')
        self.assertEqual(1, len(result))
        self.assertEqual('The number/integer state cybol format.', result[0].brief)
        self.assertEqual('number/integer', result[0].name)
        self.assertEqual('number', result[0].group)
        self.assertEqual('integer', result[0].specifier)
        self.assertEqual('state', result[0].type)
        self.assertEqual('An integer is a datum of integral data type, a data type that represents some range of mathematical integers. It is allowed to contain negative values. The standard type used internally is "int" with 32 Bits. It has a value range from −2,147,483,648 to 2,147,483,647, which is from −(2^31) to 2^31 - 1.', result[0].description)
        self.assertIsNotNone(result[0].examples)
        self.assertEqual(0, len(result[0].properties))

    def test_parsing_whole_structure(self):
        parser = Parser()
        api_items = parser.parse_structure()

        self.assertEqual(2, len(api_items))

        writer = Writer(api_items)
        writer.update_api_data()


if __name__ == '__main__':
    unittest.main()

