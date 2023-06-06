// Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#pragma once

// Good defaults for home row modifiers
#define TAPPING_TERM 200
// #define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define QUICK_TAP_TERM 0
#define RETRO_TAPPING

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Handle master/slave detection on low cost Promicro
#ifdef __AVR__
#    define SPLIT_USB_DETECT
#endif
