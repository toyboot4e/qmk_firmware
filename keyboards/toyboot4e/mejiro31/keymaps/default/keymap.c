#define KEYMAP_DEFAULT

#include QMK_KEYBOARD_H

enum layer_names {
    _L0 = 0,
};

enum custom_keycodes {
    KC_NO_OP = SAFE_RANGE,
    KC_STENO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // KEYBOARD (LAYER 0)
    // ┌─────┬─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┬─────┐
    // │     │  q  │  w  │  e  │  r  │  t  │             │  y  │  u  │  i  │  o  │  p  │     │
    // ├─────┼a/WIN┼──s──┼──d──┼──f──┼──g──┤             ├──h──┼──j──┼──k──┼──l──┼;/WIN┼─────┤
    // │     │z/SHF│  x  │  c  │  v  │  b  │             │  n  │  m  │  ,  │  .  │//ALT│     │
    // └─────┴─────┴─────┴─────┴─────┴─────┘             └─────┴─────┴─────┴─────┴─────┴─────┘
    //                         ┌───────────┐             ┌───────────┐
    //                         │           │             │           │
    //                         ├─────┬─────┤   ┌─────┐   ├─────┬─────┤
    //                         │LANG1│ SPC │   │Steno│   │LANG2│ENTER│
    //                         │/CTRL│ /L1 │   │     │   │SHIFT│/L2  │
    //                         └─────┴─────┘   └─────┘   └─────┴─────┘
    [_L0] = LAYOUT(
        QK_BOOT,  KC_Q, KC_W, KC_E, KC_R, KC_T,           KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_NO_OP,
        KC_NO_OP, KC_Z, KC_X, KC_C, KC_V, KC_B,           KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO_OP,
                                KC_NO_OP,      KC_STENO,  KC_NO_OP,
                                KC_LNG1, KC_SPACE,        KC_LNG2, KC_ENT
    ),
};

// Returns whether to delagate the key event handling to QMK's default.
// https://docs.qmk.fm/custom_quantum_functions#example-process-record-user-implementation
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void matrix_scan_user(void) {
    //
}
