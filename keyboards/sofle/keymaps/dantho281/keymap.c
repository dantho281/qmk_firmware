#include QMK_KEYBOARD_H
#include <keymap_extras/keymap_dvorak.h>

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _DVORAK,
    _QWERTY,
    _DLOWER,
    _RAISE,
    _QLOWER,
    _ADJUST,
};

enum custom_keycodes {
    KC_DVORAK = SAFE_RANGE,
    KC_QWERTY,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_THUMB_SWAP,
    KC_THUMB_LEFT,
    KC_THUMB_RIGHT,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /LThumb /       \RThumb\  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_DVORAK] = LAYOUT( \
  DV_GRV,   DV_1,   DV_2,    DV_3,    DV_4,    DV_5,                     DV_6,    DV_7,    DV_8,    DV_9,    DV_0,  DV_SLSH, \
  KC_TAB,   DV_QUOT,DV_COMM, DV_DOT,  DV_P,    DV_Y,                     DV_F,    DV_G,    DV_C,    DV_R,    DV_L,  KC_BSPC, \
  KC_ESC,   DV_A,   DV_O,    DV_E,    DV_U,    DV_I,                     DV_D,    DV_H,    DV_T,    DV_N,    DV_S,  DV_MINS, \
  KC_LSFT,  DV_SCLN,DV_Q,    DV_J,    DV_K,    DV_X, KC_MUTE,    XXXXXXX,DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,  KC_RSFT, \
                 KC_LGUI,KC_LALT,KC_LCTRL, KC_LOWER, KC_THUMB_LEFT,      KC_THUMB_RIGHT,  KC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI \
),
[_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, \
  KC_TAB,   KC_Q, KC_W, KC_E,  KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \
  KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z ,KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    XXXXXXX,KC_N,    KC_M,    KC_COMM,    KC_DOT,    KC_SLSH,  KC_RSFT, \
                 KC_LGUI,KC_LALT,KC_LCTRL, KC_LOWER, KC_THUMB_LEFT,      KC_THUMB_RIGHT,  KC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ?   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /LThumb /       \RThumb\  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_DLOWER] = LAYOUT( \
  DV_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,\
  DV_QUES,  DV_1,    DV_2,    DV_3,    DV_4,    DV_5,                        DV_6,    DV_7,    DV_8,    DV_9,   DV_0,    KC_F12, \
  _______,  DV_EXLM, DV_AT,   DV_HASH, DV_DLR,  DV_PERC,                     DV_CIRC, DV_AMPR, DV_ASTR, DV_LPRN,DV_RPRN, DV_PIPE, \
  _______,  DV_EQL,  DV_MINS, DV_PLUS, DV_LCBR, DV_RCBR, _______,   _______, DV_LBRC, DV_RBRC, DV_SCLN, DV_COLN,DV_BSLS, _______, \
                       _______, _______, _______, _______, _______,_______, _______, _______, _______, _______\
),
[_QLOWER] = LAYOUT( \
  KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,\
  KC_QUES,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_F12, \
  _______,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,KC_RPRN, KC_PIPE, \
  _______,  KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,   _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN,KC_BSLS, _______, \
                       _______, _______, _______, _______, _______,_______, _______, _______, _______, _______\
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | Ins  | Pscr | Menu |      |      |                    | PgUp |      |  Up  |      |      | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------| PgDn | Left | Down | Right|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |-------|    |-------|      |      |      |      |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /LThumb /       \RThumb\  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______ , _______ , _______ , _______, _______,                      _______,  _______, _______,  _______ ,  _______ ,_______, \
  _______, KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX,  XXXXXXX,                      KC_PGUP, _______, KC_UP,   _______, _______, KC_BSPC, \
  _______, KC_LALT, KC_LCTL,   KC_LSFT, XXXXXXX,  KC_CAPS,                      KC_PGDN, KC_LEFT,  KC_DOWN, KC_RGHT,  KC_DEL,   KC_BSPC, \
  _______, _______, _______,   _______, _______, XXXXXXX,  _______,  _______,  XXXXXXX, _______, XXXXXXX, _______,  XXXXXXX,  _______, \
                         _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |DVORAK|QWERTY|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|SPCENT|      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /LThumb /       \RThumb\  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RESET  , XXXXXXX,KC_DVORAK,KC_QWERTY,XXXXXXX,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX,CG_TOGG, KC_THUMB_SWAP,  XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  )
};

/* Space Enter swap */
bool swap_space_enter = false;

#ifdef OLED_ENABLE
    #include "bongocat.c" // Bongo cat OLED code
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                if (get_highest_layer(default_layer_state) == _DVORAK) {
                    layer_on(_DLOWER);
                    update_tri_layer(_DLOWER, _RAISE, _ADJUST);
                } else if (get_highest_layer(default_layer_state) == _QWERTY) {
                    layer_on(_QLOWER);
                    update_tri_layer(_QLOWER, _RAISE, _ADJUST);
                }
            } else {
                if (get_highest_layer(default_layer_state) == _DVORAK) {
                    layer_off(_DLOWER);
                    update_tri_layer(_DLOWER, _RAISE, _ADJUST);
                } else if (get_highest_layer(default_layer_state) == _QWERTY) {
                    layer_off(_QLOWER);
                    update_tri_layer(_QLOWER, _RAISE, _ADJUST);
                }
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                if (get_highest_layer(default_layer_state) == _DVORAK) {
                    update_tri_layer(_DLOWER, _RAISE, _ADJUST);
                } else if (get_highest_layer(default_layer_state) == _QWERTY) {
                    update_tri_layer(_QLOWER, _RAISE, _ADJUST);
                }
            } else {
                layer_off(_RAISE);
                if (get_highest_layer(default_layer_state) == _DVORAK) {
                    update_tri_layer(_DLOWER, _RAISE, _ADJUST);
                } else if (get_highest_layer(default_layer_state) == _QWERTY) {
                    update_tri_layer(_QLOWER, _RAISE, _ADJUST);
                }
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        /* Space Enter swap */
        case KC_THUMB_SWAP:
            if (record->event.pressed) {
                swap_space_enter = !swap_space_enter;
            }
            return false;
            break;
        case KC_THUMB_LEFT:
            if (record->event.pressed) {
                if (swap_space_enter) {
                    register_code(KC_SPC);
                } else {
                    register_code(KC_ENT);
                }
            } else {
                if (swap_space_enter) {
                    unregister_code(KC_SPC);
                } else {
                    unregister_code(KC_ENT);
                }
            }
            return false;
        case KC_THUMB_RIGHT:
            if (record->event.pressed) {
                if (swap_space_enter) {
                    register_code(KC_ENT);
                } else {
                    register_code(KC_SPC);
                }
            } else {
                if (swap_space_enter) {
                    unregister_code(KC_ENT);
                } else {
                    unregister_code(KC_SPC);
                }
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE
    #include "encoder.c"
#endif
