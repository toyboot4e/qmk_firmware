#include QMK_KEYBOARD_H

enum layer_names {
    _L0 = 0,
};

enum custom_keycodes {
    KC_STENO = SAFE_RANGE,
};

// clang-format off
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
        QK_BOOT, KC_Q, KC_W, KC_E, KC_R, KC_T,            KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_NO,
        KC_NO,   KC_Z, KC_X, KC_C, KC_V, KC_B,            KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                                KC_NO,         KC_STENO,  KC_NO,
                                KC_LNG1, KC_SPACE,        KC_LNG2, KC_ENT
    ),
};
// clang-format on

// combo:
// https://docs.qmk.fm/features/combo
enum combos_names {
    Q_Z = 0,
    W_X,
    E_C,
    R_V,
    T_B,

    Y_N,
    U_M,
    I_COMMA,
    O_DOT,
    P_SLASH,
};

const uint16_t PROGMEM combo_q_z[] = {KC_Q, KC_Z, COMBO_END};
const uint16_t PROGMEM combo_w_x[] = {KC_W, KC_X, COMBO_END};
const uint16_t PROGMEM combo_e_c[] = {KC_E, KC_C, COMBO_END};
const uint16_t PROGMEM combo_r_v[] = {KC_R, KC_V, COMBO_END};
const uint16_t PROGMEM combo_t_b[] = {KC_T, KC_B, COMBO_END};

const uint16_t PROGMEM combo_y_n[]     = {KC_Y, KC_N, COMBO_END};
const uint16_t PROGMEM combo_u_m[]     = {KC_U, KC_M, COMBO_END};
const uint16_t PROGMEM combo_i_comma[] = {KC_I, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo_o_dot[]   = {KC_O, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_p_slash[] = {KC_P, KC_SLASH, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    COMBO(combo_q_z, KC_A),
    COMBO(combo_w_x, KC_S),
    COMBO(combo_e_c, KC_D),
    COMBO(combo_r_v, KC_F),
    COMBO(combo_t_b, KC_G),

    COMBO(combo_y_n, KC_H),
    COMBO(combo_u_m, KC_J),
    COMBO(combo_i_comma, KC_K),
    COMBO(combo_o_dot, KC_L),
    COMBO(combo_p_slash, KC_SEMICOLON),
};
// clang-format on

// Returns whether to delagate the key event handling to QMK's default.
// https://docs.qmk.fm/custom_quantum_functions#example-process-record-user-implementation
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void matrix_scan_user(void) {
    //
}
