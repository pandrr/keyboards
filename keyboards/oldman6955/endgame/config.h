// Copyright 2024 dreipunkteinsvier (@dreipunkteinsvier)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define AUDIO_PWM_DRIVER PWMD5
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#define AUDIO_PIN GP10
#ifdef AUDIO_ENABLE
    #define AUDIO_INIT_DELAY
    #define AUDIO_CLICKY
 //  #define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f
    #define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

#define STARTUP_SOUND E__NOTE(_E6), E__NOTE(_A6), ED_NOTE(_E7),



#define NO_AUTO_SHIFT_ALPHA
#define TAPPING_TERM 170
// #define PERMISSIVE_HOLD_PER_KEY
// #define TAPPING_TERM_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
