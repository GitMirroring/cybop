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
 * @author Franziska Wehner
 */

#ifndef ISO_8859_11_CHARACTER_CODE_MODEL_CONSTANT_HEADER
#define ISO_8859_11_CHARACTER_CODE_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//

//
// ISO/IEC 8859 is a joint ISO and IEC series of standards for 8-bit character encodings.
// The series of standards consists of numbered parts, such as ISO/IEC 8859-1, ISO/IEC 8859-2, etc.
// There are 15 parts, excluding the abandoned ISO/IEC 8859-12.
// The ISO working group maintaining this series of standards has been disbanded.
// ISO/IEC 8859 parts 1, 2, 3, and 4 were originally Ecma International standard ECMA-94.
//
// While "ISO/IEC 8859" (without hyphen) does NOT define
// any characters for ranges 0x00-0x1F and 0x7F-0x9F,
// the "ISO-8859" (WITH hyphen and WITHOUT "IEC") standard
// registered with the IANA specifies non-printable
// control characters within these FREE areas.
// Therefore, both are related and do NOT conflict.
//
// CAUTION! The "ISO/IEC 8859-11" did NOT get assigned an
// IANA charset "ISO-8859-11", presumably because it was
// almost identical to the Thai Industrial Standard (TIS) 620.
//
// This file contains ISO/IEC 8859-11 character code constants:
// Latin/Thai
//

//
// The ascii characters in range 0x00-0x7F are NOT repeated here
//

//
// The non-printable control characters in range 0x80-0x9F
// are NOT defined, since an "ISO-8859-11" does NOT exist.
//

//
// The printable characters in range 0xA0-0xFF
//

/** The no-break space iso-8859-11 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA0 };
static unsigned char* NO_BREAK_SPACE_ISO_8859_11_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character ko kai iso-8859-11 character code model. U+00A1 */
static unsigned char THAI_CHARACTER_KO_KAI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA1 };
static unsigned char* THAI_CHARACTER_KO_KAI_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_KO_KAI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character kho khai iso-8859-11 character code model. U+00A2 */
static unsigned char THAI_CHARACTER_KHO_KHAI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA2 };
static unsigned char* THAI_CHARACTER_KHO_KHAI_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_KHO_KHAI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character kho khuat iso-8859-11 character code model. U+00A3 */
static unsigned char THAI_CHARACTER_KHO_KHUAT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA3 };
static unsigned char* THAI_CHARACTER_KHO_KHUAT_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_KHO_KHUAT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character kho khwai iso-8859-11 character code model. U+00A4 */
static unsigned char THAI_CHARACTER_KHO_KHWAI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA4 };
static unsigned char* THAI_CHARACTER_KHO_KHWAI_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_KHO_KHWAI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character kho khon iso-8859-11 character code model. U+00A5 */
static unsigned char THAI_CHARACTER_KHO_KHON_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA5 };
static unsigned char* THAI_CHARACTER_KHO_KHON_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_KHO_KHON_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character kho rakhang iso-8859-11 character code model. U+00A6 */
static unsigned char THAI_CHARACTER_KHO_RAKHANG_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA6 };
static unsigned char* THAI_CHARACTER_KHO_RAKHANG_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_KHO_RAKHANG_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character ngo ngu iso-8859-11 character code model. U+00A7 */
static unsigned char THAI_CHARACTER_NGO_NGU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA7 };
static unsigned char* THAI_CHARACTER_NGO_NGU_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_NGO_NGU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character cho chan iso-8859-11 character code model. U+00A8 */
static unsigned char THAI_CHARACTER_CHO_CHAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA8 };
static unsigned char* THAI_CHARACTER_CHO_CHAN_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_CHO_CHAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character cho ching iso-8859-11 character code model. U+00A9 */
static unsigned char THAI_CHARACTER_CHO_CHING_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA9 };
static unsigned char* THAI_CHARACTER_CHO_CHING_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_CHO_CHING_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character cho chang iso-8859-11 character code model. U+00AA */
static unsigned char THAI_CHARACTER_CHO_CHANG_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAA };
static unsigned char* THAI_CHARACTER_CHO_CHANG_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_CHO_CHANG_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character so so iso-8859-11 character code model. U+00AB */
static unsigned char THAI_CHARACTER_SO_SO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAB };
static unsigned char* THAI_CHARACTER_SO_SO_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SO_SO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character cho choe iso-8859-11 character code model. U+00AC */
static unsigned char THAI_CHARACTER_CHO_CHOE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAC };
static unsigned char* THAI_CHARACTER_CHO_CHOE_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_CHO_CHOE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character yo ying iso-8859-11 character code model. U+00AD */
static unsigned char THAI_CHARACTER_YO_YING_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAD };
static unsigned char* THAI_CHARACTER_YO_YING_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_YO_YING_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character do chada iso-8859-11 character code model. U+00AE */
static unsigned char THAI_CHARACTER_DO_CHADA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAE };
static unsigned char* THAI_CHARACTER_DO_CHADA_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_DO_CHADA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character to patak iso-8859-11 character code model. U+00AF */
static unsigned char THAI_CHARACTER_TO_PATAK_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAF };
static unsigned char* THAI_CHARACTER_TO_PATAK_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_TO_PATAK_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character tho than iso-8859-11 character code model. U+00B0 */
static unsigned char THAI_CHARACTER_THO_THAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB0 };
static unsigned char* THAI_CHARACTER_THO_THAN_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_THO_THAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character tho nangmontho iso-8859-11 character code model. U+00B1 */
static unsigned char THAI_CHARACTER_THO_NANGMONTHO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB1 };
static unsigned char* THAI_CHARACTER_THO_NANGMONTHO_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_THO_NANGMONTHO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character tho phuthao iso-8859-11 character code model. U+00B2 */
static unsigned char THAI_CHARACTER_THO_PHUTHAO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB2 };
static unsigned char* THAI_CHARACTER_THO_PHUTHAO_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_THO_PHUTHAO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character no nen iso-8859-11 character code model. U+00B3 */
static unsigned char THAI_CHARACTER_NO_NEN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB3 };
static unsigned char* THAI_CHARACTER_NO_NEN_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_NO_NEN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character do dek iso-8859-11 character code model. U+00B4 */
static unsigned char THAI_CHARACTER_DO_DEK_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB4 };
static unsigned char* THAI_CHARACTER_DO_DEK_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_DO_DEK_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character to tao iso-8859-11 character code model. U+00B5 */
static unsigned char THAI_CHARACTER_TO_TAO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB5 };
static unsigned char* THAI_CHARACTER_TO_TAO_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_TO_TAO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character tho thung iso-8859-11 character code model. U+00B6 */
static unsigned char THAI_CHARACTER_THO_THUNG_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB6 };
static unsigned char* THAI_CHARACTER_THO_THUNG_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_THO_THUNG_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character tho thahan iso-8859-11 character code model. U+00B7 */
static unsigned char THAI_CHARACTER_THO_THAHAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB7 };
static unsigned char* THAI_CHARACTER_THO_THAHAN_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_THO_THAHAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character tho thong iso-8859-11 character code model. U+00B8 */
static unsigned char THAI_CHARACTER_THO_THONG_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB8 };
static unsigned char* THAI_CHARACTER_THO_THONG_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_THO_THONG_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character no nu iso-8859-11 character code model. U+00B9 */
static unsigned char THAI_CHARACTER_NO_NU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB9 };
static unsigned char* THAI_CHARACTER_NO_NU_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_NO_NU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character bo baimai iso-8859-11 character code model. U+00BA */
static unsigned char THAI_CHARACTER_BO_BAIMAI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBA };
static unsigned char* THAI_CHARACTER_BO_BAIMAI_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_BO_BAIMAI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character po pla iso-8859-11 character code model. U+00BB */
static unsigned char THAI_CHARACTER_PO_PLA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBB };
static unsigned char* THAI_CHARACTER_PO_PLA_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_PO_PLA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character pho phung iso-8859-11 character code model. U+00BC */
static unsigned char THAI_CHARACTER_PHO_PHUNG_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBC };
static unsigned char* THAI_CHARACTER_PHO_PHUNG_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_PHO_PHUNG_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character fo fa iso-8859-11 character code model. U+00BD */
static unsigned char THAI_CHARACTER_FO_FA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBD };
static unsigned char* THAI_CHARACTER_FO_FA_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_FO_FA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character pho phan iso-8859-11 character code model. U+00BE */
static unsigned char THAI_CHARACTER_PHO_PHAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBE };
static unsigned char* THAI_CHARACTER_PHO_PHAN_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_PHO_PHAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character fo fan iso-8859-11 character code model. U+00BF */
static unsigned char THAI_CHARACTER_FO_FAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBF };
static unsigned char* THAI_CHARACTER_FO_FAN_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_FO_FAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character pho samphao iso-8859-11 character code model. U+00C0 */
static unsigned char THAI_CHARACTER_PHO_SAMPHAO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC0 };
static unsigned char* THAI_CHARACTER_PHO_SAMPHAO_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_PHO_SAMPHAO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character mo ma iso-8859-11 character code model. U+00C1 */
static unsigned char THAI_CHARACTER_MO_MA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC1 };
static unsigned char* THAI_CHARACTER_MO_MA_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_MO_MA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character yo yak iso-8859-11 character code model. U+00C2 */
static unsigned char THAI_CHARACTER_YO_YAK_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC2 };
static unsigned char* THAI_CHARACTER_YO_YAK_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_YO_YAK_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character ro rua iso-8859-11 character code model. U+00C3 */
static unsigned char THAI_CHARACTER_RO_RUA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC3 };
static unsigned char* THAI_CHARACTER_RO_RUA_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_RO_RUA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character ru iso-8859-11 character code model. U+00C4 */
static unsigned char THAI_CHARACTER_RU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC4 };
static unsigned char* THAI_CHARACTER_RU_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_RU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character lo ling iso-8859-11 character code model. U+00C5 */
static unsigned char THAI_CHARACTER_LO_LING_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC5 };
static unsigned char* THAI_CHARACTER_LO_LING_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_LO_LING_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character lu iso-8859-11 character code model. U+00C6 */
static unsigned char THAI_CHARACTER_LU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC6 };
static unsigned char* THAI_CHARACTER_LU_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_LU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character wo waen iso-8859-11 character code model. U+00C7 */
static unsigned char THAI_CHARACTER_WO_WAEN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC7 };
static unsigned char* THAI_CHARACTER_WO_WAEN_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_WO_WAEN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character so sala iso-8859-11 character code model. U+00C8 */
static unsigned char THAI_CHARACTER_SO_SALA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC8 };
static unsigned char* THAI_CHARACTER_SO_SALA_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SO_SALA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character so rusi iso-8859-11 character code model. U+00C9 */
static unsigned char THAI_CHARACTER_SO_RUSI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC9 };
static unsigned char* THAI_CHARACTER_SO_RUSI_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SO_RUSI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character so sua iso-8859-11 character code model. U+00CA */
static unsigned char THAI_CHARACTER_SO_SUA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xCA };
static unsigned char* THAI_CHARACTER_SO_SUA_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SO_SUA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character ho hip iso-8859-11 character code model. U+00CB */
static unsigned char THAI_CHARACTER_HO_HIP_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xCB };
static unsigned char* THAI_CHARACTER_HO_HIP_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_HO_HIP_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character lo chula iso-8859-11 character code model. U+00CC */
static unsigned char THAI_CHARACTER_LO_CHULA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xCC };
static unsigned char* THAI_CHARACTER_LO_CHULA_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_LO_CHULA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character o ang iso-8859-11 character code model. U+00CD */
static unsigned char THAI_CHARACTER_O_ANG_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xCD };
static unsigned char* THAI_CHARACTER_O_ANG_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_O_ANG_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character ho nokhuk iso-8859-11 character code model. U+00CE */
static unsigned char THAI_CHARACTER_HO_NOKHUK_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xCE };
static unsigned char* THAI_CHARACTER_HO_NOKHUK_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_HO_NOKHUK_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character paiyannoi iso-8859-11 character code model. U+00CF */
static unsigned char THAI_CHARACTER_PAIYANNOI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xCF };
static unsigned char* THAI_CHARACTER_PAIYANNOI_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_PAIYANNOI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara a iso-8859-11 character code model. U+00D0 */
static unsigned char THAI_CHARACTER_SARA_A_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD0 };
static unsigned char* THAI_CHARACTER_SARA_A_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_A_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character mai han-akat iso-8859-11 character code model. U+00D1 */
static unsigned char THAI_CHARACTER_MAI_HAN_AKAT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD1 };
static unsigned char* THAI_CHARACTER_MAI_HAN_AKAT_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_MAI_HAN_AKAT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara aa iso-8859-11 character code model. U+00D2 */
static unsigned char THAI_CHARACTER_SARA_AA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD2 };
static unsigned char* THAI_CHARACTER_SARA_AA_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_AA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara am iso-8859-11 character code model. U+00D3 */
static unsigned char THAI_CHARACTER_SARA_AM_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD3 };
static unsigned char* THAI_CHARACTER_SARA_AM_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_AM_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara i iso-8859-11 character code model. U+00D4 */
static unsigned char THAI_CHARACTER_SARA_I_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD4 };
static unsigned char* THAI_CHARACTER_SARA_I_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_I_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara ii iso-8859-11 character code model. U+00D5 */
static unsigned char THAI_CHARACTER_SARA_II_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD5 };
static unsigned char* THAI_CHARACTER_SARA_II_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_II_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara ue iso-8859-11 character code model. U+00D6 */
static unsigned char THAI_CHARACTER_SARA_UE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD6 };
static unsigned char* THAI_CHARACTER_SARA_UE_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_UE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara uee iso-8859-11 character code model. U+00D7 */
static unsigned char THAI_CHARACTER_SARA_UEE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD7 };
static unsigned char* THAI_CHARACTER_SARA_UEE_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_UEE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara u iso-8859-11 character code model. U+00D8 */
static unsigned char THAI_CHARACTER_SARA_U_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD8 };
static unsigned char* THAI_CHARACTER_SARA_U_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_U_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara uu iso-8859-11 character code model. U+00D9 */
static unsigned char THAI_CHARACTER_SARA_UU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD9 };
static unsigned char* THAI_CHARACTER_SARA_UU_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_UU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character phinthu iso-8859-11 character code model. U+00DA */
static unsigned char THAI_CHARACTER_PHINTHU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xDA };
static unsigned char* THAI_CHARACTER_PHINTHU_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_PHINTHU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character symbol baht iso-8859-11 character code model. U+00DF */
static unsigned char THAI_CURRENCY_SYMBOL_BAHT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xDF };
static unsigned char* THAI_CURRENCY_SYMBOL_BAHT_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CURRENCY_SYMBOL_BAHT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara e iso-8859-11 character code model. U+00E0 */
static unsigned char THAI_CHARACTER_SARA_E_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE0 };
static unsigned char* THAI_CHARACTER_SARA_E_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_E_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara ae iso-8859-11 character code model. U+00E1 */
static unsigned char THAI_CHARACTER_SARA_AE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE1 };
static unsigned char* THAI_CHARACTER_SARA_AE_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_AE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara o iso-8859-11 character code model. U+00E2 */
static unsigned char THAI_CHARACTER_SARA_O_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE2 };
static unsigned char* THAI_CHARACTER_SARA_O_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_O_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara ai maimuan iso-8859-11 character code model. U+00E3 */
static unsigned char THAI_CHARACTER_SARA_AI_MAIMUAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE3 };
static unsigned char* THAI_CHARACTER_SARA_AI_MAIMUAN_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_AI_MAIMUAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character sara ai maimalai iso-8859-11 character code model. U+00E4 */
static unsigned char THAI_CHARACTER_SARA_AI_MAIMALAI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE4 };
static unsigned char* THAI_CHARACTER_SARA_AI_MAIMALAI_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_SARA_AI_MAIMALAI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character kakkhangyao iso-8859-11 character code model. U+00E5 */
static unsigned char THAI_CHARACTER_LAKKHANGYAO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE5 };
static unsigned char* THAI_CHARACTER_LAKKHANGYAO_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_LAKKHANGYAO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character maiyamok iso-8859-11 character code model. U+00E6 */
static unsigned char THAI_CHARACTER_MAIYAMOK_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE6 };
static unsigned char* THAI_CHARACTER_MAIYAMOK_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_MAIYAMOK_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character maitaikhu iso-8859-11 character code model. U+00E7 */
static unsigned char THAI_CHARACTER_MAITAIKHU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE7 };
static unsigned char* THAI_CHARACTER_MAITAIKHU_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_MAITAIKHU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character mai ek iso-8859-11 character code model. U+00E8 */
static unsigned char THAI_CHARACTER_MAI_EK_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE8 };
static unsigned char* THAI_CHARACTER_MAI_EK_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_MAI_EK_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character mai tho iso-8859-11 character code model. U+00E9 */
static unsigned char THAI_CHARACTER_MAI_THO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE9 };
static unsigned char* THAI_CHARACTER_MAI_THO_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_MAI_THO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character mai tri iso-8859-11 character code model. U+00EA */
static unsigned char THAI_CHARACTER_MAI_TRI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEA };
static unsigned char* THAI_CHARACTER_MAI_TRI_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_MAI_TRI_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character mai chattawa iso-8859-11 character code model. U+00EB */
static unsigned char THAI_CHARACTER_MAI_CHATTAWA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEB };
static unsigned char* THAI_CHARACTER_MAI_CHATTAWA_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_MAI_CHATTAWA_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character thanthakhat iso-8859-11 character code model. U+00EC */
static unsigned char THAI_CHARACTER_THANTHAKHAT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEC };
static unsigned char* THAI_CHARACTER_THANTHAKHAT_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_THANTHAKHAT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character nikhahit iso-8859-11 character code model. U+00ED */
static unsigned char THAI_CHARACTER_NIKHAHIT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xED };
static unsigned char* THAI_CHARACTER_NIKHAHIT_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_NIKHAHIT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character yamakkan iso-8859-11 character code model. U+00EE */
static unsigned char THAI_CHARACTER_YAMAKKAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEE };
static unsigned char* THAI_CHARACTER_YAMAKKAN_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_YAMAKKAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character fongman iso-8859-11 character code model. U+00EF */
static unsigned char THAI_CHARACTER_FONGMAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEF };
static unsigned char* THAI_CHARACTER_FONGMAN_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_FONGMAN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai digit zero iso-8859-11 character code model. U+00F0 */
static unsigned char THAI_DIGIT_ZERO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF0 };
static unsigned char* THAI_DIGIT_ZERO_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_DIGIT_ZERO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai digit one iso-8859-11 character code model. U+00F1 */
static unsigned char THAI_DIGIT_ONE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF1 };
static unsigned char* THAI_DIGIT_ONE_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_DIGIT_ONE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai digit two iso-8859-11 character code model. U+00F2 */
static unsigned char THAI_DIGIT_TWO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF2 };
static unsigned char* THAI_DIGIT_TWO_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_DIGIT_TWO_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai digit three iso-8859-11 character code model. U+00F3 */
static unsigned char THAI_DIGIT_THREE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF3 };
static unsigned char* THAI_DIGIT_THREE_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_DIGIT_THREE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai digit four iso-8859-11 character code model. U+00F4 */
static unsigned char THAI_DIGIT_FOUR_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF4 };
static unsigned char* THAI_DIGIT_FOUR_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_DIGIT_FOUR_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai digit five iso-8859-11 character code model. U+00F5 */
static unsigned char THAI_DIGIT_FIVE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF5 };
static unsigned char* THAI_DIGIT_FIVE_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_DIGIT_FIVE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai digit six iso-8859-11 character code model. U+00F6 */
static unsigned char THAI_DIGIT_SIX_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF6 };
static unsigned char* THAI_DIGIT_SIX_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_DIGIT_SIX_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai digit seven iso-8859-11 character code model. U+00F7 */
static unsigned char THAI_DIGIT_SEVEN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF7 };
static unsigned char* THAI_DIGIT_SEVEN_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_DIGIT_SEVEN_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai digit eight iso-8859-11 character code model. U+00F8 */
static unsigned char THAI_DIGIT_EIGHT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF8 };
static unsigned char* THAI_DIGIT_EIGHT_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_DIGIT_EIGHT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai digit nine iso-8859-11 character code model. U+00F9 */
static unsigned char THAI_DIGIT_NINE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF9 };
static unsigned char* THAI_DIGIT_NINE_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_DIGIT_NINE_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character angkhankhu iso-8859-11 character code model. U+00FA */
static unsigned char THAI_CHARACTER_ANGKHANKHU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xFA };
static unsigned char* THAI_CHARACTER_ANGKHANKHU_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_ANGKHANKHU_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/** The thai character khomut iso-8859-11 character code model. U+00FB */
static unsigned char THAI_CHARACTER_KHOMUT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY[] = { 0xFB };
static unsigned char* THAI_CHARACTER_KHOMUT_ISO_8859_11_CHARACTER_CODE_MODEL = THAI_CHARACTER_KHOMUT_ISO_8859_11_CHARACTER_CODE_MODEL_ARRAY;

/* ISO_8859_11_CHARACTER_CODE_MODEL_CONSTANT_HEADER */
#endif
