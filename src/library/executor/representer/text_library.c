/*
 * Copyright (C) 1999-2023. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI. If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// ascii
//

#include "../../../executor/representer/deserialiser/ascii/ascii_deserialiser.c"
#include "../../../executor/representer/serialiser/ascii/ascii_serialiser.c"

//
// csv
//

#include "../../../executor/representer/deserialiser/csv/content_csv_deserialiser.c"
#include "../../../executor/representer/deserialiser/csv/csv_deserialiser.c"
#include "../../../executor/representer/deserialiser/csv/flag_csv_deserialiser.c"
#include "../../../executor/representer/deserialiser/csv/header_csv_deserialiser.c"
#include "../../../executor/representer/deserialiser/csv/index_csv_deserialiser.c"
#include "../../../executor/representer/deserialiser/csv/part_csv_deserialiser.c"
#include "../../../executor/representer/deserialiser/csv/preparation_csv_deserialiser.c"
#include "../../../executor/representer/deserialiser/csv/properties_csv_deserialiser.c"
#include "../../../executor/representer/deserialiser/csv/source_csv_deserialiser.c"

//
// joined string
//

#include "../../../executor/representer/deserialiser/joined_string/index_joined_string_deserialiser.c"
#include "../../../executor/representer/deserialiser/joined_string/joined_string_deserialiser.c"
#include "../../../executor/representer/deserialiser/joined_string/list_joined_string_deserialiser.c"
#include "../../../executor/representer/deserialiser/joined_string/properties_joined_string_deserialiser.c"
#include "../../../executor/representer/deserialiser/joined_string/reference_joined_string_deserialiser.c"
#include "../../../executor/representer/deserialiser/joined_string/value_joined_string_deserialiser.c"

#include "../../../executor/selector/joined_string/begin_joined_string_selector.c"
#include "../../../executor/selector/joined_string/end_joined_string_selector.c"
#include "../../../executor/selector/joined_string/quotation_end_joined_string_selector.c"
#include "../../../executor/selector/joined_string/value_end_joined_string_selector.c"

//
// newline
//

#include "../../../executor/selector/newline/newline_selector.c"

//
// textline list
//

#include "../../../executor/representer/deserialiser/textline_list/content_textline_list_deserialiser.c"
#include "../../../executor/representer/deserialiser/textline_list/element_textline_list_deserialiser.c"
#include "../../../executor/representer/deserialiser/textline_list/index_textline_list_deserialiser.c"
#include "../../../executor/representer/deserialiser/textline_list/part_textline_list_deserialiser.c"
#include "../../../executor/representer/deserialiser/textline_list/textline_list_deserialiser.c"

//
// whitespace
//

#include "../../../executor/representer/deserialiser/whitespace/whitespace_deserialiser.c"

#include "../../../executor/selector/whitespace/non_whitespace_selector.c"
#include "../../../executor/selector/whitespace/whitespace_selector.c"
