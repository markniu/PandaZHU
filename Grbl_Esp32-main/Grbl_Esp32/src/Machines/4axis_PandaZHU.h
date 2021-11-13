#pragma once
// clang-format off

/*
    4axis_external_driver.h
    Part of Grbl_ESP32

    Pin assignments for the buildlog.net 4-axis external driver board
    https://github.com/markniu/PandaZHU

    

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MACHINE_NAME            "4 Axis PandaZHU Board"

#ifdef N_AXIS
        #undef N_AXIS
#endif
#ifdef USE_RMT_STEPS
#undef USE_RMT_STEPS  // Suppress unused variable warning
#endif

#define N_AXIS 4

#define X_STEP_PIN              101
#define X_DIRECTION_PIN         100
#define Y_STEP_PIN              103
#define Y_DIRECTION_PIN         102
#define Z_STEP_PIN              105
#define Z_DIRECTION_PIN         104
#define A_STEP_PIN              107
#define A_DIRECTION_PIN         106
#define STEPPERS_DISABLE_PIN    128 
#define STEPPERS_DISABLE_PIN_Y    128
#define STEPPERS_DISABLE_PIN_Z    128
#define STEPPERS_DISABLE_PIN_A    128
/*
#define SPINDLE_TYPE            SpindleType::PWM // only one spindle at a time
*/

#define SPINDLE_OUTPUT_PIN      0
#define SPINDLE_ENABLE_PIN      22


#define SPINDLE_TYPE            SpindleType::PWM // only one spindle at a time
//#define VFD_RS485_TXD_PIN		GPIO_NUM_17
//#define VFD_RS485_RXD_PIN		GPIO_NUM_4
//#define VFD_RS485_RTS_PIN		GPIO_NUM_16

#define X_LIMIT_PIN             4
#define Y_LIMIT_PIN             35
#define Z_LIMIT_PIN             21

#if (N_AXIS != 3)
        #define A_LIMIT_PIN     15
#endif

#define PROBE_PIN               13
#define COOLANT_MIST_PIN        118

