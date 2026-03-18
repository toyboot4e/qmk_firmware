// Notes:
// - "middle row": two-key combo of two rows in the same column.

#include QMK_KEYBOARD_H

enum layer_names {
    _L0 = 0,
    _L1,
};

enum custom_keycodes {
    KC_STENO = SAFE_RANGE,
};

// combo:
// https://docs.qmk.fm/features/combo
enum combos_names {
    MID_C1 = 0,
    MID_C2,
    MID_C3,
    MID_C4,
    MID_C5,

    MID_C6,
    MID_C7,
    MID_C8,
    MID_C9,
    MID_C10,
};

// Layer 0:
//      0     1     2     3     4     5                   6     7     8     9     10    11
//   ┌─────┬─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┬─────┐
// 0 │     │  q  │  w  │  e  │  r  │  t  │             │  y  │  u  │  i  │  o  │  p  │     │
//   ├─────┼a/WIN┼──s──┼──d──┼──f──┼──g──┤             ├──h──┼──j──┼──k──┼──l──┼;/WIN┼─────┤
// 1 │     │z/SHF│  x  │  c  │  v  │  b  │             │  n  │  m  │  ,  │  .  │//ALT│     │
//   └─────┴─────┴─────┴─────┴─────┴─────┘             └─────┴─────┴─────┴─────┴─────┴─────┘
//                           ┌───────────┐   ┌─────┐   ┌───────────┐
//                        2  │           │   │Steno│   │           │
//                           ├─────┬─────┤   └─────┘   ├─────┬─────┤
//                        3  │LNG1/│ SPC │             │LNG2/│ENTER│
//                           │CTRL │ /L1 │             │SHIFT│/L2  │
//                           └─────┴─────┘             └─────┴─────┘

// Deduplicate the key codes for `keymaps` and `key_combos` here:

// left hand side:
const uint16_t key_l0_r0_c0 = QK_BOOT;
const uint16_t key_l0_r0_c1 = MT(MOD_LGUI, KC_Q);
const uint16_t key_l0_r0_c2 = KC_W;
const uint16_t key_l0_r0_c3 = KC_E;
const uint16_t key_l0_r0_c4 = KC_R;
const uint16_t key_l0_r0_c5 = KC_T;

const uint16_t key_l0_mid_c1 = MT(MOD_LGUI, KC_A);
const uint16_t key_l0_mid_c2 = KC_S;
const uint16_t key_l0_mid_c3 = KC_D;
const uint16_t key_l0_mid_c4 = KC_F;
const uint16_t key_l0_mid_c5 = KC_G;

const uint16_t key_l0_r1_c0 = KC_NO;
const uint16_t key_l0_r1_c1 = MT(MOD_LSFT, KC_Z);
const uint16_t key_l0_r1_c2 = KC_X;
const uint16_t key_l0_r1_c3 = KC_C;
const uint16_t key_l0_r1_c4 = KC_V;
const uint16_t key_l0_r1_c5 = KC_B;

// right hand side:
const uint16_t key_l0_r0_c6  = KC_Y;
const uint16_t key_l0_r0_c7  = KC_U;
const uint16_t key_l0_r0_c8  = KC_I;
const uint16_t key_l0_r0_c9  = KC_O;
const uint16_t key_l0_r0_c10 = KC_P;
const uint16_t key_l0_r0_c11 = KC_NO;

const uint16_t key_l0_mid_c6  = KC_H;
const uint16_t key_l0_mid_c7  = KC_J;
const uint16_t key_l0_mid_c8  = KC_K;
const uint16_t key_l0_mid_c9  = KC_L;
const uint16_t key_l0_mid_c10 = KC_SEMICOLON;

const uint16_t key_l0_r1_c6  = KC_N;
const uint16_t key_l0_r1_c7  = KC_M;
const uint16_t key_l0_r1_c8  = KC_COMMA;
const uint16_t key_l0_r1_c9  = KC_DOT;
const uint16_t key_l0_r1_c10 = KC_SLASH;
const uint16_t key_l0_r1_c11 = KC_NO;

// Layer 1:
//      0     1     2     3     4     5                   6     7     8     9     10    11
//   ┌─────┬─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┬─────┐
// 0 │     │  q  │  w  │  e  │  r  │  t  │             │  y  │  u  │  i  │  o  │  p  │     │
//   ├─────┼a/WIN┼──s──┼──d──┼──f──┼──g──┤             ├──h──┼──j──┼──k──┼──l──┼;/WIN┼─────┤
// 1 │     │z/SHF│  x  │  c  │  v  │  b  │             │  n  │  m  │  ,  │  .  │//ALT│     │
//   └─────┴─────┴─────┴─────┴─────┴─────┘             └─────┴─────┴─────┴─────┴─────┴─────┘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0
    [_L0] = LAYOUT(
        // row 0
        key_l0_r0_c0, key_l0_r0_c1, key_l0_r0_c2, key_l0_r0_c3, key_l0_r0_c4, key_l0_r0_c5, key_l0_r0_c6, key_l0_r0_c7, key_l0_r0_c8, key_l0_r0_c9, key_l0_r0_c10, key_l0_r0_c11,

        // row 1
        key_l0_r1_c0, key_l0_r1_c1, key_l0_r1_c2, key_l0_r1_c3, key_l0_r1_c4, key_l0_r1_c5, key_l0_r1_c6, key_l0_r1_c7, key_l0_r1_c8, key_l0_r1_c9, key_l0_r1_c10, key_l0_r1_c11,

        // row 2
        KC_NO, KC_STENO, KC_NO,

        // row 3
        MT(MOD_LCTL, KC_LNG2), LT(_L1, KC_SPACE), MT(MOD_LSFT, KC_LNG1), KC_ENT),

    // Layer 1
    [_L1] = LAYOUT(
        // row 0
        key_l0_r0_c0, KC_Z, key_l0_r0_c2, key_l0_r0_c3, key_l0_r0_c4, key_l0_r0_c5, key_l0_r0_c6, key_l0_r0_c7, key_l0_r0_c8, key_l0_r0_c9, key_l0_r0_c10, key_l0_r0_c11,

        // row 1
        key_l0_r1_c0, key_l0_r1_c1, key_l0_r1_c2, key_l0_r1_c3, key_l0_r1_c4, key_l0_r1_c5, key_l0_r1_c6, key_l0_r1_c7, key_l0_r1_c8, key_l0_r1_c9, key_l0_r1_c10, key_l0_r1_c11,

        // row 2, ro2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

// Combos for the middle row illusion:
const uint16_t PROGMEM combo_l0_mid_c1[] = {key_l0_r0_c1, key_l0_r1_c1, COMBO_END};
const uint16_t PROGMEM combo_l0_mid_c2[] = {key_l0_r0_c2, key_l0_r1_c2, COMBO_END};
const uint16_t PROGMEM combo_l0_mid_c3[] = {key_l0_r0_c3, key_l0_r1_c3, COMBO_END};
const uint16_t PROGMEM combo_l0_mid_c4[] = {key_l0_r0_c4, key_l0_r1_c4, COMBO_END};
const uint16_t PROGMEM combo_l0_mid_c5[] = {key_l0_r0_c5, key_l0_r1_c5, COMBO_END};

const uint16_t PROGMEM combo_l0_mid_c6[]  = {key_l0_r0_c6, key_l0_r1_c6, COMBO_END};
const uint16_t PROGMEM combo_l0_mid_c7[]  = {key_l0_r0_c7, key_l0_r1_c7, COMBO_END};
const uint16_t PROGMEM combo_l0_mid_c8[]  = {key_l0_r0_c8, key_l0_r1_c8, COMBO_END};
const uint16_t PROGMEM combo_l0_mid_c9[]  = {key_l0_r0_c9, key_l0_r1_c9, COMBO_END};
const uint16_t PROGMEM combo_l0_mid_c10[] = {key_l0_r0_c10, key_l0_r1_c10, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_l0_mid_c1, key_l0_mid_c1),
    COMBO(combo_l0_mid_c2, key_l0_mid_c2),
    COMBO(combo_l0_mid_c3, key_l0_mid_c3),
    COMBO(combo_l0_mid_c4, key_l0_mid_c4),
    COMBO(combo_l0_mid_c5, key_l0_mid_c5),

    //
    COMBO(combo_l0_mid_c6, key_l0_mid_c6),
    COMBO(combo_l0_mid_c7, key_l0_mid_c7),
    COMBO(combo_l0_mid_c8, key_l0_mid_c8),
    COMBO(combo_l0_mid_c9, key_l0_mid_c9),
    COMBO(combo_l0_mid_c10, key_l0_mid_c10),
};

// Returns whether to delagate the key event handling to QMK's default.
// https://docs.qmk.fm/custom_quantum_functions#example-process-record-user-implementation
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void matrix_scan_user(void) {
    //
}
