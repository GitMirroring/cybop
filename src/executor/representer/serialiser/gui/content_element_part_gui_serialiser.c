/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTENT_ELEMENT_PART_GUI_SERIALISER_SOURCE
#define CONTENT_ELEMENT_PART_GUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"

#ifndef __APPLE__ 
	#include "../../../../executor/representer/serialiser/gui/properties_gui_serialiser.c"
#endif

#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void serialise_gui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);

/**
 * Serialises the part element content into gui.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the source model data
 * @param p5 the source model count
 * @param p6 the source properties data
 * @param p7 the source properties count
 * @param p8 the source whole properties data
 * @param p9 the source whole properties count
 * @param p10 the knowledge memory part
 * @param p11 the format
 */
void serialise_gui_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui part element content.");

fwprintf(stdout, L"TEST serialise gui part element content model count: %i\n", *((int*) p5));
fwprintf(stdout, L"TEST serialise gui part element content properties count: %i\n", *((int*) p7));
	
	#ifndef __APPLE__ 
    	// Append properties.
	    serialise_gui_properties(p0, p1, p2, p3, p6, p7, p8, p9, p10);

    	// Serialise embedded model.
    	serialise_gui(p0, p1, p2, p3, p4, p5, p6, p7, p10, p11);
    #else
    	//?? Apple complete gui adaptions needed
    #endif
}

/* CONTENT_ELEMENT_PART_GUI_SERIALISER_SOURCE */
#endif
