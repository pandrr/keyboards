//
// YANKBOARD
//


#include "features/achordion.h"


#include QMK_KEYBOARD_H

#define HO_G MT(MOD_LSFT,KC_G)
#define HO_M MT(MOD_RSFT,KC_M)

#define HO_A MT(MOD_LALT,KC_A)
// #define HO_S MT(MOD_LALT,KC_S)
// #define HO_R HYPR_T(KC_R)
// #define HO_T MT(MOD_LGUI,KC_T)

// #define HO_N MT(MOD_RGUI,KC_N)
// #define HO_E HYPR_T(KC_E)
// #define HO_I MT(MOD_RALT,KC_I)
#define HO_O MT(MOD_LALT,KC_O)
#define HO_SLSH HYPR_T(KC_SLSH)


#define ESCMD MT(MOD_LGUI,KC_ESC)
#define ENTCTL MT(MOD_LCTL,KC_ENTER)

enum custom_keycodes {
    VIM_CMD = SAFE_RANGE,
    VIM_LEAD,
    VIM_FILES,
    VIM_BUFS,
    VIM_QFP,
    VIM_QFN,
    VIM_COPY,
    VIM_PASTE,
    VIM_QUIT,
    VIM_SAVE,
    VIM_WL,
    VIM_WR,
    VIM_WU,
    VIM_WD,
    VIM_TABN,
    VIM_TABP,
    VIM_TABNEW
};
/*
     *
     * DUAL:
     * ┌────┬────┬────┬────┬────┐          ┌────┬────┬────┬────┬────┐
     * │   ESC   (    [    {    │          │    }    ]    )    │    │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │    │    │    │    │    │          │    │    │    │    :    │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │    │    │    │    │    │          │    │    │    │    │    │
     * └────┴────┴────┼────┼────┼────┐┌────┼────┼────┼────┴────┴────┘
     *                │    │    │    ││    │    │    │
     *                └────┴────┴────┘└────┴────┴────┘
     */

const uint16_t PROGMEM combo1[] = {KC_Q, KC_W, COMBO_END};

const uint16_t PROGMEM combo2[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo4[] = {KC_P, KC_B, COMBO_END};

const uint16_t PROGMEM combo5[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM combo6[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM combo7[] = {KC_U, KC_Y, COMBO_END};

const uint16_t PROGMEM combo8[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo1, KC_ESC),
    COMBO(combo2, LSFT(KC_9)),     // (
    COMBO(combo3, KC_LBRC),        // [
    COMBO(combo4, LSFT(KC_LBRC)),  // {
    COMBO(combo5, LSFT(KC_RBRC)),  // }
    COMBO(combo6, KC_RBRC),        // ]
    COMBO(combo7, LSFT(KC_0)),     // )
    COMBO(combo8, LSFT(KC_SCLN)),  // :
};
void housekeeping_task_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (tap_hold_record->event.key.row  >= 2) { return true; }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    if (!process_achordion(keycode, record)) { return false; }


    if (record->event.pressed)
    {
        switch (keycode)
        {
            case VIM_CMD:
                tap_code(KC_ESC);
                SEND_STRING(":");
                return false;
            case VIM_LEAD:
                tap_code(KC_ESC);
                SEND_STRING(" ");
                return false;

            case VIM_WL:
                tap_code(KC_ESC);
                SEND_STRING(SS_LCTL("w"));
                SEND_STRING("h");
                return false;
            case VIM_WR:
                tap_code(KC_ESC);
                SEND_STRING(SS_LCTL("w"));
                SEND_STRING("l");
                return false;
            case VIM_WU:
                tap_code(KC_ESC);
                SEND_STRING(SS_LCTL("w"));
                SEND_STRING("k");
                return false;
            case VIM_WD:
                tap_code(KC_ESC);
                SEND_STRING(SS_LCTL("qw"));
                SEND_STRING("j");
                return false;
            case VIM_QUIT:
                tap_code(KC_ESC);
                SEND_STRING(":qa!");
                tap_code(KC_ENTER);
                return false;
            case VIM_FILES:
                tap_code(KC_ESC);
                SEND_STRING(" ff");
                return false;
            case VIM_BUFS:
                tap_code(KC_ESC);
                SEND_STRING(" fb");
                return false;

            case VIM_QFN:
                tap_code(KC_ESC);
                SEND_STRING(":cnext");
                return false;
            case VIM_QFP:
                tap_code(KC_ESC);
                SEND_STRING(":cprev");
                return false;

            case VIM_TABN:
                tap_code(KC_ESC);
                SEND_STRING(":tabn");
                tap_code(KC_ENTER);
                return false;
            case VIM_TABP:
                tap_code(KC_ESC);
                SEND_STRING(":tabp");
                tap_code(KC_ENTER);
                return false;
            case VIM_TABNEW:
                tap_code(KC_ESC);
                SEND_STRING(":tabnew");
                tap_code(KC_ENTER);
                return false;

            case VIM_COPY:
                tap_code(KC_ESC);
                send_string_with_delay("\"+y",30);
                return false;
            case VIM_PASTE:
                tap_code(KC_ESC);
                send_string_with_delay("\"+p",30);
                return false;
            case VIM_SAVE:
                tap_code(KC_ESC);
                send_string_with_delay(":EslintFixAll",1);
                tap_code(KC_ENTER);
                tap_code(KC_ESC);
                send_string_with_delay(":w",1);
                tap_code(KC_ENTER);
                return false;
        }
    }
  return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *
     * HOLD:
     * ┌────┬────┬────┬────┬────┐          ┌────┬────┬────┬────┬────┐
     * │    │    │    │    │    │          │    │    │    │    │    │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │alt │    │    │    │shft│          │shft│    │    │    │ alt│
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │SHFT│    │    │    │    │          │    │    │    │    │hypr│
     * └────┴────┴────┼────┼────┼────┐┌────┼────┼────┼────┴────┴────┘
     *                │nums│CMD │    ││    │    │NAV │
     *                └────┴────┴────┘└────┴────┴────┘
     *
     */
    [0] = LAYOUT_ortho36(
    //  #######  #######  #######  #######  #######     #######  #######  #######  #######  #######
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSPC,
        HO_A,    KC_S,    KC_R,    KC_T,    HO_G,       HO_M,    KC_N,    KC_E,    KC_I,    HO_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,    KC_COMM, KC_DOT,  HO_SLSH,
                          KC_LCTL, KC_LGUI, KC_ENTER,   KC_SPACE,MO(2),MO(3)
    //  #######  #######  #######  #######  #######     #######  #######  #######  #######  #######
    ),
    [1] = LAYOUT_ortho36(
    //  #######  #######  #######  #######  #######     #######  #######  #######  #######  #######
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        KC_A,    KC_S,    KC_R,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                          _______, _______, _______,    _______, _______, _______
    //  #######  #######  #######  #######  #######     #######  #######  #######  #######  #######
    ),
    /*
     * NAV
     *
     * ┌────┬────┬───┬────┬────┐          ┌────┬────┬────┬────┬────┐
     * │ESC │ (  │ ) │SC  │SC  │          │    │    │    │    │    │
     * │    │    │   │TAB │TAB │          │    │    │ UP │    │DEL │
     * ├────┼────┼───┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │TAB │ [  │ ] │STAB│TAB │          │UP  │ <- │DOWN│ -> │ENTR│
     * ├────┼────┼───┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │    │    │   │SCMD│CMD │          │    │    │    │    │    │
     * │SHFT│ {  │ } │TAB │TAB │          │DN  │ M1 │ M2 │ M3 │SHFT│
     * └────┴────┴───┼────┼────┼────┐┌────┼────┼────┼────┴────┴────┘
     *               │HYPR│    │    ││    │    │XXXX│
     *               └────┴────┴────┘└────┴────┴────┘
     *
     */
    [2] = LAYOUT_ortho36(
    //  #######  #######        #######        #######             #######         ######    ########  #######   ########  ########
        KC_ESC,  LSFT(KC_9),    LSFT(KC_0),     LCTL(LSFT(KC_TAB)), LCTL(KC_TAB),   _______,  _______,  KC_UP,    _______,  KC_DEL,
        KC_TAB,  KC_LBRC,       KC_RBRC,       LSFT(KC_TAB),       KC_TAB,         MS_WHLU,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_ENTER,
      MOD_LSFT, LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(LGUI(KC_TAB)), LGUI(KC_TAB),   MS_WHLD,  LGUI(KC_F13),  MS_BTN2,  MS_BTN3, MOD_RSFT,
                        KC_HYPR, _______,       VIM_LEAD ,                          _______,  _______,  _______
    //  #######  #######        #######        #######                             #######   #######   #######   #######  #######  #######
    ),

    /*
     * NUMS
     *
     * ┌────┬────┬────┬────┬────┐          ┌────┬────┬────┬────┬────┐
     * │ 1  │ 2  │ 3  │ 4  │ 5  │          │ 6  │ 7  │ 8  │ 9  │ 0  │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │ !  │ @  │ #  │ $  │ %  │          │ ^  │ &  │ *  │ :  │ ;  │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │ \  │ |  │ "  │ '  │ `  │          │ ~  │ -  │ +  │ =  │ _  │
     * └────┴────┴────┼────┼────┼────┐┌────┼────┼────┼────┴────┴────┘
     *                │XXXX│    │    ││    │VIM │BRAC│
     *                └────┴────┴────┘└────┴────┴────┘
     */
    [3] = LAYOUT_ortho36(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5), LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),KC_SCLN,LSFT(KC_SCLN),
        KC_BACKSLASH, LSFT(KC_BACKSLASH), LSFT(KC_QUOTE), KC_QUOTE, KC_GRAVE,    LSFT(KC_GRAVE), KC_MINUS, LSFT(KC_EQUAL), KC_EQUAL, LSFT(KC_MINUS),
                          MO(4), _______, _______,    _______,MO(4), MO(5)
    ),

    //
    //  VIM SHORTCUTS
    //
    [4] = LAYOUT_ortho36(
    //  #######  #######  #######    #######  #######     #######  #######  #######  #######  #######
        VIM_QUIT,_______, VIM_FILES, _______, VIM_BUFS,    VIM_QFP, _______, VIM_WU, _______, QK_BOOT,
        _______, VIM_SAVE,VIM_TABP,  VIM_TABN,VIM_TABNEW,   VIM_QFN, VIM_WL, VIM_WD, VIM_WR, VIM_CMD,
        _______, _______, VIM_COPY,  _______, VIM_PASTE,    _______, _______, _______, _______, _______,
                          _______,   _______, _______,    _______, _______, _______
    //  #######  #######  #######  #######  #######     #######  #######  #######  #######  #######
    ),



    /*
     * BRACKETS
     *
     * ┌────┬────┬────┬────┬────┐          ┌────┬────┬────┬────┬────┐
     * │    │    │    │    │    │          │    │PLAY│VOLU│VOLD│    │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │    │ (  │ [  │ {  │ ;  │          │ :  │ }  │ ]  │ )  │    │
     * ├────┼────┼────┼────┼────┤          ├────┼────┼────┼────┼────┤
     * │    │    │    │    │    │          │    │    │    │    │    │
     * └────┴────┴────┼────┼────┼────┐┌────┼────┼────┼────┴────┴────┘
     *                │XXXX│    │    ││    │    │XXXX│
     *                └────┴────┴────┘└────┴────┴────┘
     */
    [5] = LAYOUT_ortho36(
    //  #######  #######  #######  #######  #######     #######  #######  #######  #######  #######
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      _______, _______, KC_K, _______, _______,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,     _______, KC_H, KC_J, KC_L, _______,
        KC_F11,  KC_F12,  _______, _______, _______,    _______, _______, _______, _______, _______,
                          _______, _______, _______,    _______, _______, _______
    //  #######  #######  #######  #######  #######     #######  #######  #######  #######  #######
    )
};



