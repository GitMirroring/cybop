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

#ifndef XDT_HEADER
#define XDT_HEADER

//
// CAUTION! The following header files are included here so that
// it gets easier for other source files to use them by just
// including this ONE file instead of many.
//

//
// model
//

#include "constant/model/xdt/field_description_xdt_model.h"

//
// name
//

#include "constant/name/cyboi/xdt/field_xdt_cyboi_name.h"
#include "constant/name/cyboi/xdt/record_xdt_cyboi_name.h"

#include "constant/name/xdt/bdt_xdt_name.h"
#include "constant/name/xdt/field_xdt_name.h"
#include "constant/name/xdt/gdt_xdt_name.h"
#include "constant/name/xdt/record_xdt_name.h"

//
// Loading of a shared object (dynamic library)
//
// A shared object (.so) library gets loaded when needed
// at runtime. This kind of loading happens AUTOMATICALLY.
// The necessary machine language instructions got added to the
// binary executable by the compiler and linker during translation.
//

//
// Keyword "extern"
//
// A function is declared with storage class "extern"
// by DEFAULT, even if the keyword "extern" is missing.
// The keyword "extern" has NO influence on the source code in
// terms of optimisation or the like and thus is NOT necessary.
// It is just a HINT to the reader (developer) indicating that
// the function is implemented in an EXTERNAL source file.
// A COMMENT like this one can be used as hint, instead of that keyword.
//

void deserialise_xdt(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void deserialise_xdt_bdt(void* p0, void* p1, void* p2, void* p3);
void deserialise_xdt_bdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_xdt_bdt_field_compound(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void deserialise_xdt_bdt_fields(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void deserialise_xdt_bdt_record(void* p0, void* p1, void* p2, void* p3);
void deserialise_xdt_bdt_records(void* p0, void* p1, void* p2, void* p3);
void deserialise_xdt_datetime_ddmmyyyy(void* p0, void* p1, void* p2);
void deserialise_xdt_datetime_ddmmyyyy_elements(void* p0, void* p1);
void deserialise_xdt_datetime_mmyy(void* p0, void* p1, void* p2);
void deserialise_xdt_datetime_mmyy_elements(void* p0, void* p1);
void deserialise_xdt_datetime_qyyyy(void* p0, void* p1, void* p2);
void deserialise_xdt_datetime_qyyyy_elements(void* p0, void* p1);
void deserialise_xdt_datetime_qyyyy_quarter(void* p0, void* p1, void* p2);
void deserialise_xdt_duration_ddmmyyyyddmmyyyy(void* p0, void* p1, void* p2);
void deserialise_xdt_duration_hhmmhhmm(void* p0, void* p1, void* p2);
void deserialise_xdt_duration_yyyy(void* p0, void* p1, void* p2);
void deserialise_xdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void deserialise_xdt_field_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_xdt_field_content(void* p0, void* p1, void* p2, void* p3);
void deserialise_xdt_field_format(void* p0, void* p1);
void deserialise_xdt_field_hierarchy(void* p0, void* p1);
void deserialise_xdt_field_identification(void* p0, void* p1, void* p2, void* p3, void* p4);
void deserialise_xdt_field_line(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void deserialise_xdt_field_lines(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void deserialise_xdt_field_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void deserialise_xdt_field_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void deserialise_xdt_field_size(void* p0, void* p1, void* p2, void* p3);
void deserialise_xdt_field_type(void* p0, void* p1);
void deserialise_xdt_gdt(void* p0, void* p1, void* p2, void* p3);
void deserialise_xdt_ldt(void* p0, void* p1, void* p2, void* p3);
void deserialise_xdt_record(void* p0, void* p1, void* p2);
void deserialise_xdt_record_field(void* p0, void* p1, void* p2, void* p3, void* p4);
void deserialise_xdt_record_fields(void* p0, void* p1, void* p2);
void deserialise_xdt_record_part(void* p0, void* p1, void* p2);
void deserialise_xdt_standard(void* p0, void* p1, void* p2, void* p3, void* p4);

void select_xdt_bdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void select_xdt_bdt_field_compound_end(void* p0, void* p1, void* p2);
void select_xdt_bdt_field_compound_end_1210(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1250(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1271(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1290(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1297(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1298(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1299(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1301(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1303(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1305(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1330(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1400(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1500(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1502(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1503(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1600(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1702(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_1800(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_2002(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_201(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_203(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_207(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_212(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_213(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_250(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_252(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_2803(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_300(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_301(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_302(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_304(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3050(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_307(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3101(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3120(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3301(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3310(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3399(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3423(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3425(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3454(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3465(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3472(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3501(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3504(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3505(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3510(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3511(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3515(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3528(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3531(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3541(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3602(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3622(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3623(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3632(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3637(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3649(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3650(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3651(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3652(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3653(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3655(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3656(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3657(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3658(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3659(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3660(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3661(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3662(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3669(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3672(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3673(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3689(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3700(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_3702(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_4217(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_4218(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_4234(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_4235(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_4244(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_5000(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_5001(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_5012(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_5020(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_5035(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_5042(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6000(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6001(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6007(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6011(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6200(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6201(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6202(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6206(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6207(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6208(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6210(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6212(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6226(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6228(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6230(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6235(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6285(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6290(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6300(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6302(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6306(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6310(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6312(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6325(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6330(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_6332(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_80(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_8000(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_8010(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_8401(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_8410(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_8411(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_8430(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_8445(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_8510(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_8520(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_919(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_920(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_925(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_9260(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_9801(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_9802(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_9806(void* p0, void* p1);
void select_xdt_bdt_field_compound_end_9900(void* p0, void* p1);
void select_xdt_bdt_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void select_xdt_field_hierarchy(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void select_xdt_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

void serialise_xdt(void* p0, void* p1, void* p2, void* p3, void* p4);
void serialise_xdt_datetime_ddmmyyyy(void* p0, void* p1);
void serialise_xdt_datetime_mmyy(void* p0, void* p1, void* p2);
void serialise_xdt_datetime_qyyyy(void* p0, void* p1, void* p2);
void serialise_xdt_datetime_qyyyy_quarter(void* p0, void* p1);
void serialise_xdt_duration_ddmmyyyyddmmyyyy(void* p0, void* p1, void* p2);
void serialise_xdt_duration_hhmmhhmm(void* p0, void* p1, void* p2);
void serialise_xdt_duration_yyyy(void* p0, void* p1, void* p2);
void serialise_xdt_field_description(void* p0, void* p1);
void serialise_xdt_field_model(void* p0, void* p1, void* p2, void* p3);

/* XDT_HEADER */
#endif
