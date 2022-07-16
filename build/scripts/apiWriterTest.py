import unittest
from unittest import mock
from unittest.mock import call

from apiWriter import Writer
from apiData import ApiItem


class ApiWriterTest(unittest.TestCase):

    @mock.patch('builtins.open')
    @mock.patch('apiWriter.os.makedirs')
    def test_update_api_data(self, make_dir_mock, file_open_mock):
        api_items = [
            ApiItem('channel', '', 'channel')
        ]

        Writer(api_items).update_api_data()

        make_dir_calls = [
            call('/Users/enrico/cybop/build/scripts/../../tools/api-generator/spec', exist_ok=True)
        ]
        make_dir_mock.assert_has_calls(make_dir_calls)

        file_open_mock.assert_any_call('/Users/enrico/cybop/build/scripts/../../doc/cybol/api/channel.txt', 'w')
        file_open_mock.assert_any_call('/Users/enrico/cybop/build/scripts/../../tools/api-generator/spec/channel.cybol', 'wb')

        write_calls = [
            call('channel')
        ]
        file_handle = file_open_mock()
        print('calls to the file:\n', file_handle.mock_calls, end ='\n\n')
        print('calls to write:\n', file_handle.write.mock_calls, end ='\n\n')
        file_handle.write.assert_has_calls(write_calls)


if __name__ == '__main__':
    unittest.main()
