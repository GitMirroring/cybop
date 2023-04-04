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

#ifndef ASTRONOMY_TIME_SCALE_MODEL_SOURCE
#define ASTRONOMY_TIME_SCALE_MODEL_SOURCE

//
// Library interface
//

#include "constant.h"

/** The epsilon double astronomy time scale model. */
static double EPSILON_DOUBLE_ASTRONOMY_TIME_SCALE_MODEL_ARRAY[] = { 2.2204460492503131E-16 };
static double* EPSILON_DOUBLE_ASTRONOMY_TIME_SCALE_MODEL = EPSILON_DOUBLE_ASTRONOMY_TIME_SCALE_MODEL_ARRAY;

//
// The constants below were taken from:
// http://www.astro-toolbox.com/
//

/*??
static double SpeedOfLight         = 299792458.0;
static double EarthEquatorialRadius= 6378137.0;
static double EarthOblateness      = 1.0/298.2572;
static double AstronomicalUnit     = 149.5978707E9;
// new value for 1 au = 1.49597870691(30)e11

static double Epsilon2000       = 84381.448;
static double Planck            = 6.62607e-34;

static double JD19              = 2415020.0;
static double J1900             = 2415020.0;
static double JD20              = 2451545.0;
static double J2000             = 2451545.0;
static double BD19              = 2415020.31352;
static double B1900             = 2415020.31352;
static double TropicalYear      = 365.24219879;
static double SiderealYear      = 365.25636042;
static double SiderealDay       = 86164.0989038;
static double TDT_TAI           = 32.184;
static double TAI_UTC           = 35.0; // as of 2012/09/05

static double JulianEphemZero   = 2440000.0;
static double JulianComputerZero   = 2440587.5;

static double GM_Sun            =132712438000.0E9;
static double GM_Earth          =      398600.5E9;
static double GM_Moon           =        4902.799703E9;
static double GM_EarthMoon      =      403503.2997E9;
static double GM_Mercury        =       22032.08015E9;
static double GM_Venus          =      324858.7609E9;
static double GM_Mars           =       42828.28596E9;
static double GM_Jupiter        =   126712596.6E9;
static double GM_Saturn         =    37939519.15E9;
static double GM_Uranus         =     5780158.449E9;
static double GM_Neptune        =     6871307.756E9;
static double GM_SolarSystem    = 132890534800.0E9;

static double Pi             = 3.14159265358979323846;
static double HalfPi            = 0.5*Pi;
static double TwoPi          = 2.0*Pi;

static double RadianToDegree    = 180.0/Pi;
static double DegreeToRadian    = Pi/180.0;
static double Radian2Degree     = 180.0/Pi;
static double Degree2Radian     = Pi/180.0;

static double Epsilon           = 2.2204460492503131E-15;
static double EpsilonRelative   = 1.0 - Epsilon;

static double Parsec            = AstronomicalUnit*648000.0/Pi;
*/

/* ASTRONOMY_TIME_SCALE_MODEL_SOURCE */
#endif
