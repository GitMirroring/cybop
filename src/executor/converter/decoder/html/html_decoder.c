/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTML_DECODER_SOURCE
#define HTML_DECODER_SOURCE

#include "../../../../constant/type/cybol/text_cybol_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/channel/cybol_channel.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../../logger/logger.c"
#include "../../../../executor/accessor/getter/compound_getter.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"

/**
 * Decodes the html into a model.
 *
 * @param p0 the destination item (pointer reference)
 * @param p1 the source data
 * @param p2 the source count
 */
void decode_html(void* p0, void* p1, void* p2) {
}

/* HTML_DECODER_SOURCE */
#endif
