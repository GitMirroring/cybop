/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// imap
//

//?? TODO

//
// imf (internet message format)
//
// Metaphor:
//
// Where smtp is considered the "envelope", imf data are the "letter".
//

//?? TODO

//
// pop3
//

//?? TODO

//
// smtp
//

//?? #include "../../../executor/representer/deserialiser/smtp_command/argument_smtp_command_deserialiser.c"
//?? #include "../../../executor/representer/deserialiser/smtp_command/command_smtp_command_deserialiser.c"
//?? #include "../../../executor/representer/deserialiser/smtp_command/insensitiveness_smtp_command_deserialiser.c"
//?? #include "../../../executor/representer/deserialiser/smtp_command/reference_smtp_command_deserialiser.c"

#include "../../../executor/representer/deserialiser/smtp_response/code_smtp_response_deserialiser.c"
#include "../../../executor/representer/deserialiser/smtp_response/smtp_response_deserialiser.c"
#include "../../../executor/representer/deserialiser/smtp_response/text_smtp_response_deserialiser.c"

#include "../../../executor/selector/smtp_response/code_smtp_response_selector.c"
#include "../../../executor/selector/smtp_response/text_smtp_response_selector.c"
