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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ERROR_CODE_EEB_MODEL_CONSTANT_HEADER
#define ERROR_CODE_EEB_MODEL_CONSTANT_HEADER

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// These constants represent error codes (server response codes),
// which are sent from a server back to the client that had sent the request.
//
// Description in german language:
// "eEB Fehler falls die Krankenkasse keine Ersatzbescheinigung ausstellen kann"
//
// Code system reference:
// https://gematik.de/fhir/eeb/CodeSystem/EEBErrorcodeCS
//
// Abbreviation:
// eEB - elektronische Ersatzbescheinigung
//

//
// 1xx - data (Daten)
//

/** The continue 100 error code eeb model. */
static unsigned char* CONTINUE_100_ERROR_CODE_EEB_MODEL = "100 Der Patient ist nicht bei der adressierten Krankenkasse versichert.";
static int* CONTINUE_100_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_71_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 101 error code eeb model. */
static unsigned char* CONTINUE_101_ERROR_CODE_EEB_MODEL = "101 Die übermittelte eEB entspricht nicht den Vorgaben und/oder ist nicht lesbar.";
static int* CONTINUE_101_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_81_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 110 error code eeb model. */
static unsigned char* CONTINUE_110_ERROR_CODE_EEB_MODEL = "110 Der Patient ist nicht eindeutig identifizierbar.";
static int* CONTINUE_110_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_52_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 111 error code eeb model. */
static unsigned char* CONTINUE_111_ERROR_CODE_EEB_MODEL = "111 Das angefragte Leistungsdatum ist unplausibel.";
static int* CONTINUE_111_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 112 error code eeb model. */
static unsigned char* CONTINUE_112_ERROR_CODE_EEB_MODEL = "112 Es liegt für den Patienten kein gültiges Versichertenverhältnis zum angefragten Leistungsdatum vor.";
static int* CONTINUE_112_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_103_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 120 error code eeb model. */
static unsigned char* CONTINUE_120_ERROR_CODE_EEB_MODEL = "120 Die Einwilligung des Patienten zur Freigabe der Bescheinigungsübermittlung an die Praxis liegt nicht vor.";
static int* CONTINUE_120_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_109_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 130 error code eeb model. */
static unsigned char* CONTINUE_130_ERROR_CODE_EEB_MODEL = "130 Es liegt ein Sonderfall/ eine Ausnahme vor. Bitten Sie den Patienten, mit der Krankenkasse Kontakt aufzunehmen.";
static int* CONTINUE_130_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_115_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// 2xx - signature (Signatur)
//

/** The continue 201 error code eeb model. */
static unsigned char* CONTINUE_201_ERROR_CODE_EEB_MODEL = "201 Die Signatur der eEB-Anfrage ist nicht gültig, da ein fehlerhaftes Zertifikat verwendet wurde oder nicht alle zur Zertifikatsprüfung erforderlichen Komponenten bzw. Ressourcen zur Verfügung standen.";
static int* CONTINUE_201_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_202_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 202 error code eeb model. */
static unsigned char* CONTINUE_202_ERROR_CODE_EEB_MODEL = "202 Die Signaturprüfung der eEB-Anfrage hat ergeben, dass die signierten Daten nicht mit den übermittelten Daten der eEB-Anfrage übereinstimmen.";
static int* CONTINUE_202_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_144_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 210 error code eeb model. */
static unsigned char* CONTINUE_210_ERROR_CODE_EEB_MODEL = "210 Die eEB-Anfrage ist nicht signiert. Die eEB-Anfrage ist ggf. manipuliert worden.";
static int* CONTINUE_210_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_84_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 211 error code eeb model. */
static unsigned char* CONTINUE_211_ERROR_CODE_EEB_MODEL = "211 Die Signatur der eEB-Anfrage konnte aufgrund eines falschen Formats nicht geprüft werden.";
static int* CONTINUE_211_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_93_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// 3xx - message (Nachricht)
//

/** The continue 307 error code eeb model. */
static unsigned char* CONTINUE_307_ERROR_CODE_EEB_MODEL = "307 Übermittlung ist fehlgeschlagen. Grund hierfür ist, dass die KIM-Nachricht zwar als eine verschlüsselte KIM-Nachricht gekennzeichnet wurde, aber auf Grund des falschen Formats nicht von der Krankenkasse entschlüsselt werden konnte.";
static int* CONTINUE_307_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_235_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 309 error code eeb model. */
static unsigned char* CONTINUE_309_ERROR_CODE_EEB_MODEL = "309 Übermittlung ist fehlgeschlagen. Grund hierfür ist, dass für die KIM-Nachricht keine Signatur vorhanden ist.";
static int* CONTINUE_309_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_112_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 310 error code eeb model. */
static unsigned char* CONTINUE_310_ERROR_CODE_EEB_MODEL = "310 Übermittlung ist fehlgeschlagen. Grund hierfür ist, dass die Signatur für die KIM-Nachricht aufgrund des falschen Formats nicht geprüft werden konnte.";
static int* CONTINUE_310_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_154_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 311 error code eeb model. */
static unsigned char* CONTINUE_311_ERROR_CODE_EEB_MODEL = "311 Die Integrität der Nachricht wurde verletzt. Die Prüfung der Signatur hat ergeben, dass die Nachricht manipuliert wurde.";
static int* CONTINUE_311_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_124_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The continue 313 error code eeb model. */
static unsigned char* CONTINUE_313_ERROR_CODE_EEB_MODEL = "313 Die KIM-Nachricht konnte auf Grund eines nicht verfügbaren Schlüssels nicht entschlüsselt werden.";
static int* CONTINUE_313_ERROR_CODE_EEB_MODEL_COUNT = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ERROR_CODE_EEB_MODEL_CONSTANT_HEADER */
#endif
