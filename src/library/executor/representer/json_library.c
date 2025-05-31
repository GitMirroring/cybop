/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// backslash escape
//

#include "../../../executor/representer/deserialiser/backslash_escape/backslash_escape_deserialiser.c"
#include "../../../executor/representer/serialiser/backslash_escape/backslash_escape_serialiser.c"

//
// digit
//

#include "../../../executor/selector/digit/decimal_digit_selector.c"
#include "../../../executor/selector/digit/hexadecimal_digit_selector.c"

//
// json
//

#include "../../../executor/representer/deserialiser/json/array_json_deserialiser.c"
#include "../../../executor/representer/deserialiser/json/constraints_json_deserialiser.c"
#include "../../../executor/representer/deserialiser/json/json_deserialiser.c"
#include "../../../executor/representer/deserialiser/json/member_json_deserialiser.c"
#include "../../../executor/representer/deserialiser/json/number_json_deserialiser.c"
#include "../../../executor/representer/deserialiser/json/object_json_deserialiser.c"
#include "../../../executor/representer/deserialiser/json/string_json_deserialiser.c"
#include "../../../executor/representer/deserialiser/json/value_json_deserialiser.c"

#include "../../../executor/representer/serialiser/json/break_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/comma_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/constraints_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/content_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/element_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/format_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/indentation_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/json_serialiser.c"
#include "../../../executor/representer/serialiser/json/level_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/part_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/prefix_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/separation_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/space_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/string_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/suffix_json_serialiser.c"
#include "../../../executor/representer/serialiser/json/tabulator_json_serialiser.c"

#include "../../../executor/selector/json/begin_value_json_selector.c"
#include "../../../executor/selector/json/end_number_json_selector.c"
#include "../../../executor/selector/json/end_string_json_selector.c"
#include "../../../executor/selector/json/type_string_json_selector.c"

//
// sign
//

#include "../../../executor/selector/sign/sign_selector.c"
