import unittest
from apiWriter import Writer
from apiParser import Parser


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

        self.assertEqual(59, len(api_items))

        writer = Writer(api_items)
        writer.update_api_data()


if __name__ == '__main__':
    unittest.main()
