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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// character reference
//

#include "../../../executor/representer/deserialiser/character_reference/any_character_reference_deserialiser.c"
#include "../../../executor/representer/deserialiser/character_reference/character_reference_deserialiser.c"
#include "../../../executor/representer/deserialiser/character_reference/decimal_character_reference_deserialiser.c"
#include "../../../executor/representer/deserialiser/character_reference/entity_character_reference_deserialiser.c"
#include "../../../executor/representer/deserialiser/character_reference/hexadecimal_character_reference_deserialiser.c"
#include "../../../executor/representer/deserialiser/character_reference/html_character_reference_deserialiser.c"

#include "../../../executor/representer/serialiser/character_reference/character_character_reference_serialiser.c"
#include "../../../executor/representer/serialiser/character_reference/character_reference_serialiser.c"
#include "../../../executor/representer/serialiser/character_reference/data_character_reference_serialiser.c"
#include "../../../executor/representer/serialiser/character_reference/html_character_reference_serialiser.c"
#include "../../../executor/representer/serialiser/character_reference/xml_character_reference_serialiser.c"

#include "../../../executor/selector/character_reference/begin_character_reference_selector.c"
#include "../../../executor/selector/character_reference/end_character_reference_selector.c"

//
// css
//

//?? TODO

//
// html
//

#include "../../../executor/representer/deserialiser/html/html_deserialiser.c"

#include "../../../executor/representer/serialiser/html/attribute_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/attributes_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/begin_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/break_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/constraints_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/content_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/doctype_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/element_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/empty_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/end_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/filled_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/html_serialiser.c"
#include "../../../executor/representer/serialiser/html/indentation_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/part_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/primitive_html_serialiser.c"
#include "../../../executor/representer/serialiser/html/void_html_serialiser.c"

//
// percent encoding
//

#include "../../../executor/representer/deserialiser/percent_encoding/character_percent_encoding_deserialiser.c"
#include "../../../executor/representer/deserialiser/percent_encoding/data_percent_encoding_deserialiser.c"
#include "../../../executor/representer/deserialiser/percent_encoding/percent_encoding_deserialiser.c"

#include "../../../executor/representer/serialiser/percent_encoding/byte_percent_encoding_serialiser.c"
#include "../../../executor/representer/serialiser/percent_encoding/bytes_percent_encoding_serialiser.c"
#include "../../../executor/representer/serialiser/percent_encoding/character_percent_encoding_serialiser.c"
#include "../../../executor/representer/serialiser/percent_encoding/data_percent_encoding_serialiser.c"
#include "../../../executor/representer/serialiser/percent_encoding/percent_encoding_serialiser.c"

#include "../../../executor/selector/percent_encoding/begin_percent_encoding_selector.c"
