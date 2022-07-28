enum corne_layers {
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_DVORAK = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_THUMB_SWAP,
    KC_THUMB_LEFT,
    KC_THUMB_RIGHT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_split_3x6_3(
            KC_TAB, DV_QUOT, DV_COMM, DV_DOT, DV_P, DV_Y,   DV_F, DV_G, DV_C, DV_R, DV_L, KC_BSPC,
            KC_LSFT, DV_A, DV_O, DV_E, DV_U, DV_I,           DV_D, DV_H, DV_T, DV_N, DV_S, DV_MINS,
            KC_LCTRL, DV_SCLN, DV_Q, DV_J, DV_K, DV_X,       DV_B, DV_M, DV_W, DV_V, DV_Z, KC_ESC,
                    KC_LGUI, KC_LOWER, KC_THUMB_LEFT,       KC_THUMB_RIGHT, KC_RAISE, KC_RALT
    ),
    [_LOWER] = LAYOUT_split_3x6_3(
            DV_GRV, DV_1, DV_2, DV_3, DV_4, DV_5,       DV_6, DV_7, DV_8, DV_9, DV_0, KC_ESC,
            DV_QUES, DV_EQL, DV_MINS, DV_PLUS, DV_LCBR, DV_RCBR,    DV_LBRC, DV_RBRC, DV_SCLN, DV_COLN, DV_BSLS, DV_SLSH,
            _______, DV_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                _______, _______, _______,                      _______, _______, _______
    ),
    [_RAISE] = LAYOUT_split_3x6_3(
            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,   KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
            KC_TAB, KC_ESC, KC_LALT, KC_LCTL, KC_LSFT, KC_CAPS,     KC_PGUP, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, KC_BSPC,
            KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL, KC_BSPC,
            _______, _______, _______,                              _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_split_3x6_3(
            RESET, XXXXXXX, KC_DVORAK, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, CG_TOGG, KC_THUMB_SWAP, XXXXXXX, XXXXXXX,     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
            _______, _______, _______,      _______, _______, _______
    )
};

bool swap_space_enter = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
        case KC_THUMB_RIGHT:
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
    }
    return true;
}
