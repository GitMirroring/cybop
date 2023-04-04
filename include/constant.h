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

#ifndef CONSTANT_HEADER
#define CONSTANT_HEADER

//
// integer
//
// CAUTION! These integer constants do actually belong into section "model".
// However, since other constants definitions make use of them, they have to
// be included FIRST, yet before any other files.
//

#include "constant/model/cyboi/state/integer/hundred_integer_state_cyboi_model.h"
#include "constant/model/cyboi/state/integer/integer_state_cyboi_model.h"
#include "constant/model/cyboi/state/integer/negative_integer_state_cyboi_model.h"
#include "constant/model/cyboi/state/integer/tenthousand_integer_state_cyboi_model.h"
#include "constant/model/cyboi/state/integer/thousand_integer_state_cyboi_model.h"

//
// channel
//

#include "constant/channel/cyboi/cyboi_channel.h"

//
// encoding
//

#include "constant/encoding/cyboi/cyboi_encoding.h"

//
// format
//

#include "constant/format/cyboi/logic_cyboi_format.h"
#include "constant/format/cyboi/state_cyboi_format.h"

//
// language
//

#include "constant/language/cyboi/state_cyboi_language.h"

//
// model
//

#include "constant/model/character_code/ascii/ascii_character_code_model.h"

#include "constant/model/character_code/dos/dos_437_character_code_model.h"
#include "constant/model/character_code/dos/dos_850_character_code_model.h"

#include "constant/model/character_code/iso_6429/c0_iso_6429_character_code_model.h"
#include "constant/model/character_code/iso_6429/c1_iso_6429_character_code_model.h"

#include "constant/model/character_code/iso_8859/iso_8859_10_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_11_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_12_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_13_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_14_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_15_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_16_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_1_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_2_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_3_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_4_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_5_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_6_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_7_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_8_character_code_model.h"
#include "constant/model/character_code/iso_8859/iso_8859_9_character_code_model.h"

#include "constant/model/character_code/unicode/unicode_character_code_model.h"

#include "constant/model/character_code/windows/windows_1252_character_code_model.h"

#include "constant/model/cyboi/help/help_cyboi_model.h"

#include "constant/model/cyboi/identification/identification_cyboi_model.h"

#include "constant/model/cyboi/operation_mode/operation_mode_cyboi_model.h"

#include "constant/model/cyboi/option/log_level_option_cyboi_model.h"

#include "constant/model/cyboi/state/boolean_state_cyboi_model.h"
#include "constant/model/cyboi/state/double_state_cyboi_model.h"
#include "constant/model/cyboi/state/mathematics_state_cyboi_model.h"
#include "constant/model/cyboi/state/pointer_state_cyboi_model.h"
#include "constant/model/cyboi/state/state_cyboi_model.h"

#include "constant/model/eeb/error_code_eeb_model.h"

#include "constant/model/file/open_mode_file_model.h"

#include "constant/model/language/lcid_language_model.h"

#include "constant/model/service/port_service_model.h"
#include "constant/model/service/protocol_service_model.h"

//
// name
//

#include "constant/name/cyboi/option/option_cyboi_name.h"

#include "constant/name/cyboi/state/client_state_cyboi_name.h"
#include "constant/name/cyboi/state/complex_state_cyboi_name.h"
#include "constant/name/cyboi/state/datetime_state_cyboi_name.h"
#include "constant/name/cyboi/state/duration_state_cyboi_name.h"
#include "constant/name/cyboi/state/fraction_state_cyboi_name.h"
#include "constant/name/cyboi/state/input_output_state_cyboi_name.h"
#include "constant/name/cyboi/state/internal_memory_state_cyboi_name.h"
#include "constant/name/cyboi/state/item_state_cyboi_name.h"
#include "constant/name/cyboi/state/part_state_cyboi_name.h"
#include "constant/name/cyboi/state/primitive_state_cyboi_name.h"
#include "constant/name/cyboi/state/server_state_cyboi_name.h"
#include "constant/name/cyboi/state/vector_state_cyboi_name.h"

//
// type
//

#include "constant/type/cyboi/state_cyboi_type.h"

/* CONSTANT_HEADER */
#endif
