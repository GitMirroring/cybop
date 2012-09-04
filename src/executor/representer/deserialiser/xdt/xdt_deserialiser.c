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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_DESERIALISER_SOURCE
#define XDT_DESERIALISER_SOURCE

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/xdt/field_xdt_cyboi_name.c"
#include "../../../../constant/name/cyboi/xdt/record_xdt_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/name/xdt/field_xdt_name.c"
#include "../../../../constant/name/xdt/package_xdt_name.c"
#include "../../../../constant/name/xdt/record_xdt_name.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

//
// The "x DatenTransfer" (xDT) is the German version of
// "Electronic Data Interchange" (EDI) for medical practices.
// Here is an extract from xDT documentation, issued by the
// "Kassenaerztliche Bundesvereinigung" (KBV) at:
// http://www.kbv.de/ita/4274.html
//
// Aufbau und Struktur des "AbrechnungsDatenTransfer" (ADT)
//
// Der ADT ist eine Datenschnittstelle, die aufgrund ihrer fruehen Entstehung,
// Mitte der achtziger Jahre, wenig Anknuepfungspunkte zu den erst spaeter im
// Zusammenhang mit der zunehmenden EDI-Etablierung bekannten Standards besitzt.
// Natuerlich gibt es Parallelen, beispielsweise zu
// "EDI for Administration, Commerce and Transport" (EDIFACT),
// die in der artverwandten Zielsetzung begruendet liegen.
// Die ADT-Syntax ist der von "Abstract Syntax Notation" (ASN) ASN.1 aehnlich.
//
// Eine wesentliche Besonderheit des ADT besteht darin, dass jedes Feld im
// Grunde einen eigenen Satz darstellt. Das heisst, es enthaelt in sich wieder
// die Elemente Laenge, Feldkennung, Feldinhalt und Feldende.
//
// Die einzelnen Felder haben alle einen eindeutigen Namen in Form einer
// numerischen Feldkennung. Es gibt wenige Felder mit in der Groesse
// feststehenden Feldinhalten, die meisten sind variabel, was sich mit einer
// vorlaufenden Feldlaenge leicht bewerkstelligen laesst. Darueber hinaus
// werden als Endemarkierung eines Feldes die ASCII-Werte 13 und 10,
// gleichbedeutend mit Carriage return und Linefeed, verlangt.
//
// Jedes Feld hat die gleiche Struktur. Alle Informationen sind als
// ASCII-Zeichen dargestellt. Gemaess der Feldkennung wird der zugehoerige
// Eintrag der Feldtabelle herangezogen.
//
// Fuer die Laengenberechnung eines Feldes gilt die Regel: Feldinhalt + 9
//
// Struktur eines Datenfeldes
//
// -----------------------------------------------------------------------------
// Feldteil         Laenge [Byte]       Bedeutung
// -----------------------------------------------------------------------------
// Laenge           3                   Feldlaenge in Bytes
// Kennung          4                   Feldkennung
// Inhalt           variabel            Abrechnungsinformationen
// Ende             2                   ASCII-Wert 13 = CR (Wagenruecklauf)
//                                      ASCII-Wert 10 = LF (Zeilenvorschub)
// -----------------------------------------------------------------------------
//
// Here is an extract from the German "Arztpraxis Wiegand" (APW) documentation,
// available at:
// http://www.apw-wiegand.de/
//
// Patientennummerkonvertierung:
// Beim BDT ... werden die Patientennummern nach folgender Formel konvertiert:
// Stelle 1: immer 1
// Stelle 2-3: Parallelabrechnungsnummer (meist 01)
// Stelle 4-5: 1. Stelle der APW-PatNr umgewandelt in Alphabet-Rangfolge (z.B. a->01, z->26)
// Stelle 6-7: 2. Stelle der APW-PatNr umgewandelt in Alphabet-Rangfolge
// ab Stelle 8: ab Stelle 3 der APW-PatNr
//

//
// Forward declarations.
//

//?? void deserialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

/**
 * Deserialises the model.
 *
 * @param p0 the destination name (pointer reference)
 * @param p1 the destination name count (pointer reference)
 * @param p2 the destination name size (pointer reference)
 * @param p3 the destination type (pointer reference)
 * @param p4 the destination type count (pointer reference)
 * @param p5 the destination type size (pointer reference)
 * @param p6 the destination model (pointer reference)
 * @param p7 the destination model count (pointer reference)
 * @param p8 the destination model size (pointer reference)
 * @param p9 the destination properties (pointer reference)
 * @param p10 the destination properties count (pointer reference)
 * @param p11 the destination properties size (pointer reference)
 * @param p12 the source model
 * @param p13 the source model count
 * @param p14 the source type
 * @param p15 the source type count
 * @param p16 the source name
 * @param p17 the source name count
 */
void deserialise_xdt_deserialise_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    if (p11 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int** ds = (int**) p11;

        if (p10 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int** dc = (int**) p10;

            if (p8 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int** ms = (int**) p8;

                if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int** mc = (int**) p7;

                    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        int** as = (int**) p5;

                        if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            int** ac = (int**) p4;

                            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                int** ns = (int**) p2;

                                if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                    int** nc = (int**) p1;

                                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise model.");

/*??
                                    allocate_part(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p14, p15);

                                    // Decode name.
                                    overwrite_array(p0, p16, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p17, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                                    // Decode type.
                                    overwrite_array(p3, p14, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p15, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p4, p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                                    // Decode model.
                                    deserialise(p6, (void*) *mc, (void*) *ms, p9, (void*) *dc, (void*) *ds, p12, p13, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p14, p15);
*/

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise model. The name count is null.");
                                }

                            } else {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise model. The name size is null.");
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise model. The type count is null.");
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise model. The type size is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise model. The model count is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise model. The model size is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise model. The properties count is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise model. The properties size is null.");
    }
}

/**
 * Deserialises an xdt format byte array into a compound model.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 * @param p4 the format
 */
void deserialise_xdt(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
    if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p7;

        if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void* s = (void*) p6;

            if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                void** dd = (void**) p3;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    void** dm = (void**) p0;

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt format into compound model.");

                    // The remaining bytes in the source byte array.
                    int rem = *sc;
                    // The xdt package size.
                    int ps = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    // The xdt package content.
                    void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;
                    int pcc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    // The xdt package header.
                    void* ph = *NULL_POINTER_STATE_CYBOI_MODEL;
                    int phc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    // The xdt package footer.
                    void* pf = *NULL_POINTER_STATE_CYBOI_MODEL;
                    int pfc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                        if (rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                            break;
                        }

                        // CAUTION! The data package section pointer s
                        // has to be handed over as REFERENCE, because it
                        // gets manipulated in the called operations and
                        // these have to store their result in s.
                        // If temporary variables (function parametres) were used,
                        // their values would be lost when the called operation is left.
                        deserialise_xdt_package((void*) &ps, (void*) &ph, (void*) &phc, (void*) &pf, (void*) &pfc, (void*) &pc, (void*) &pcc, (void*) &s, (void*) &rem);

                        if (ps > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                            // Decrement remaining bytes in the source byte array.
                            rem = rem - ps;

                            // Select xdt package.
                            deserialise_xdt_select_package(*dm, p1, p2, *dd, p4, p5,
                                pc, (void*) &pcc, ph, (void*) &phc, pf, (void*) &pfc);

                        } else {

                            // If the xdt package size is zero or smaller, then
                            // increment the source xdt byte array index by one,
                            // in order to ensure that this loop will finally
                            // find an end.
                            s = s + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                            rem = rem - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                        }

                        // Reset xdt package size.
                        ps = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // Reset xdt package content.
                        pc = *NULL_POINTER_STATE_CYBOI_MODEL;
                        pcc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // Reset xdt package header.
                        ph = *NULL_POINTER_STATE_CYBOI_MODEL;
                        phc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // Reset xdt package footer.
                        pf = *NULL_POINTER_STATE_CYBOI_MODEL;
                        pfc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt. The destination compound model is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt. The destination compound properties is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt. The source byte array is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt. The source byte array count is null.");
    }
*/
}

/* XDT_DESERIALISER_SOURCE */
#endif
