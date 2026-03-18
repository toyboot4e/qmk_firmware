// Notes:
// - "middle row": two-key combo of two rows in the same column.

#include QMK_KEYBOARD_H

enum layer_names {
    _L0 = 0,
    _L1,
    _L2,
};

enum custom_keycodes {
    KC_STENO = SAFE_RANGE,
};

// combo:
// https://docs.qmk.fm/features/combo
enum combos_names {
    COMBO_L0_MID_C1 = 0,
    COMBO_L0_MID_C2,
    COMBO_L0_MID_C3,
    COMBO_L0_MID_C4,
    COMBO_L0_MID_C5,
    COMBO_L0_MID_C6,
    COMBO_L0_MID_C7,
    COMBO_L0_MID_C8,
    COMBO_L0_MID_C9,
    COMBO_L0_MID_C10,

    COMBO_L1_MID_C1,
    COMBO_L1_MID_C2,
    COMBO_L1_MID_C3,
    COMBO_L1_MID_C4,
    COMBO_L1_MID_C5,
    COMBO_L1_MID_C6,
    COMBO_L1_MID_C7,
    COMBO_L1_MID_C8,
    COMBO_L1_MID_C9,
    COMBO_L1_MID_C10,

    COMBO_L2_MID_C1,
    COMBO_L2_MID_C2,
    COMBO_L2_MID_C3,
    COMBO_L2_MID_C4,
    COMBO_L2_MID_C5,
    COMBO_L2_MID_C6,
    COMBO_L2_MID_C7,
    COMBO_L2_MID_C8,
    COMBO_L2_MID_C9,
    COMBO_L2_MID_C10,
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
// 0 │     │  F1 │  F2 │  F3 │  F4 │  F5 │             │  F6 │  F7 │  F8 │  F9 │  F10│     │
//   ├─────┼──TAB┼─ESC─┼──|──┼──'──┼─DEL─┤             ├─PgUp┼──M1─┼──↑──┼──M2─┼──F11┼─────┤
// 1 │     │=/SHF│  1  │  \  │  "  │ BSPC│             │  n  │  ←  │  ↓  │  →  │  F12│     │
//   └─────┴─────┴─────┴─────┴─────┴─────┘             └─────┴─────┴─────┴─────┴─────┴─────┘

// left hand side:
const uint16_t key_l1_r0_c1 = MT(MOD_LGUI, KC_F1);
const uint16_t key_l1_r0_c2 = KC_F2;
const uint16_t key_l1_r0_c3 = KC_F3;
const uint16_t key_l1_r0_c4 = KC_F4;
const uint16_t key_l1_r0_c5 = KC_F5;

const uint16_t key_l1_mid_c1 = MT(MOD_LGUI, KC_TAB);
const uint16_t key_l1_mid_c2 = KC_ESC;
const uint16_t key_l1_mid_c3 = KC_PIPE;
const uint16_t key_l1_mid_c4 = KC_QUOT;
const uint16_t key_l1_mid_c5 = KC_DEL;

const uint16_t key_l1_r1_c1 = MT(MOD_LSFT, KC_EQL);
const uint16_t key_l1_r1_c2 = KC_1;
const uint16_t key_l1_r1_c3 = KC_BACKSLASH;
const uint16_t key_l1_r1_c4 = KC_DQUO;
const uint16_t key_l1_r1_c5 = KC_BSPC;

// right hand side:
const uint16_t key_l1_r0_c6  = KC_F6;
const uint16_t key_l1_r0_c7  = KC_F7;
const uint16_t key_l1_r0_c8  = KC_F8;
const uint16_t key_l1_r0_c9  = KC_F9;
const uint16_t key_l1_r0_c10 = KC_F10;

const uint16_t key_l1_mid_c6  = KC_PGUP;
const uint16_t key_l1_mid_c7  = MS_BTN1;
const uint16_t key_l1_mid_c8  = KC_UP;
const uint16_t key_l1_mid_c9  = MS_BTN2;
const uint16_t key_l1_mid_c10 = KC_F11;

const uint16_t key_l1_r1_c6  = KC_N;
const uint16_t key_l1_r1_c7  = KC_LEFT;
const uint16_t key_l1_r1_c8  = KC_DOWN;
const uint16_t key_l1_r1_c9  = KC_RIGHT;
const uint16_t key_l1_r1_c10 = KC_F12;

// Layer 2:
//      0     1     2     3     4     5                   6     7     8     9     10    11
//   ┌─────┬─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┬─────┐
// 0 │     │  "  │  7  │  8  │  9  │  (  │             │  )  │  !  │  ^  │  @  │  $  │     │
//   ├─────┼+/WIN┼──4──┼──5──┼──6──┼──[──┤             ├──]──┼──= ─┼──+──┼──#──┼──:──┼─────┤
// 1 │     │=/SHF│  1  │  2  │  3  │  {  │             │  }  │  _  │  =  │  `  │  0  │     │
//   └─────┴─────┴─────┴─────┴─────┴─────┘             └─────┴─────┴─────┴─────┴─────┴─────┘

// left hand side:
const uint16_t key_l2_r0_c1 = MT(MOD_LGUI, KC_DQUO);
const uint16_t key_l2_r0_c2 = KC_7;
const uint16_t key_l2_r0_c3 = KC_8;
const uint16_t key_l2_r0_c4 = KC_9;
const uint16_t key_l2_r0_c5 = KC_LPRN;

const uint16_t key_l2_mid_c1 = MT(MOD_LGUI, KC_PPLS);
const uint16_t key_l2_mid_c2 = KC_4;
const uint16_t key_l2_mid_c3 = KC_5;
const uint16_t key_l2_mid_c4 = KC_6;
const uint16_t key_l2_mid_c5 = KC_LBRC;

const uint16_t key_l2_r1_c1 = MT(MOD_LSFT, KC_EQL);
const uint16_t key_l2_r1_c2 = KC_1;
const uint16_t key_l2_r1_c3 = KC_2;
const uint16_t key_l2_r1_c4 = KC_3;
const uint16_t key_l2_r1_c5 = KC_LCBR;

// right hand side:
const uint16_t key_l2_r0_c6  = KC_RPRN;
const uint16_t key_l2_r0_c7  = KC_EXLM;
const uint16_t key_l2_r0_c8  = KC_CIRC;
const uint16_t key_l2_r0_c9  = KC_AT;
const uint16_t key_l2_r0_c10 = KC_DLR;

const uint16_t key_l2_mid_c6  = KC_RBRC;
const uint16_t key_l2_mid_c7  = KC_EQL;
const uint16_t key_l2_mid_c8  = KC_PPLS;
const uint16_t key_l2_mid_c9  = KC_NUHS;
const uint16_t key_l2_mid_c10 = KC_COLON;

const uint16_t key_l2_r1_c6  = KC_RCBR;
const uint16_t key_l2_r1_c7  = KC_UNDS;
const uint16_t key_l2_r1_c8  = KC_EQUAL;
const uint16_t key_l2_r1_c9  = KC_GRV;
const uint16_t key_l2_r1_c10 = KC_0;

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
        MT(MOD_LCTL, KC_LNG2), LT(_L1, KC_SPACE), MT(MOD_LSFT, KC_LNG1), LT(_L2, KC_ENT)),

    // Layer 1
    [_L1] = LAYOUT(
        // row 0
        KC_TRNS, key_l1_r0_c1, key_l1_r0_c2, key_l1_r0_c3, key_l1_r0_c4, key_l1_r0_c5, key_l1_r0_c6, key_l1_r0_c7, key_l1_r0_c8, key_l1_r0_c9, key_l1_r0_c10, KC_TRNS,

        // row 1
        KC_TRNS, key_l1_r1_c1, key_l1_r1_c2, key_l1_r1_c3, key_l1_r1_c4, key_l1_r1_c5, key_l1_r1_c6, key_l1_r1_c7, key_l1_r1_c8, key_l1_r1_c9, key_l1_r1_c10, KC_TRNS,

        // row 2, ro2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    // Layer 2
    [_L2] = LAYOUT(
        // row 0
        KC_TRNS, key_l2_r0_c1, key_l2_r0_c2, key_l2_r0_c3, key_l2_r0_c4, key_l2_r0_c5, key_l2_r0_c6, key_l2_r0_c7, key_l2_r0_c8, key_l2_r0_c9, key_l2_r0_c10, KC_TRNS,

        // row 1
        KC_TRNS, key_l2_r1_c1, key_l2_r1_c2, key_l2_r1_c3, key_l2_r1_c4, key_l2_r1_c5, key_l2_r1_c6, key_l2_r1_c7, key_l2_r1_c8, key_l2_r1_c9, key_l2_r1_c10, KC_TRNS,

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

const uint16_t PROGMEM combo_l1_mid_c1[] = {key_l1_r0_c1, key_l1_r1_c1, COMBO_END};
const uint16_t PROGMEM combo_l1_mid_c2[] = {key_l1_r0_c2, key_l1_r1_c2, COMBO_END};
const uint16_t PROGMEM combo_l1_mid_c3[] = {key_l1_r0_c3, key_l1_r1_c3, COMBO_END};
const uint16_t PROGMEM combo_l1_mid_c4[] = {key_l1_r0_c4, key_l1_r1_c4, COMBO_END};
const uint16_t PROGMEM combo_l1_mid_c5[] = {key_l1_r0_c5, key_l1_r1_c5, COMBO_END};

const uint16_t PROGMEM combo_l1_mid_c6[]  = {key_l1_r0_c6, key_l1_r1_c6, COMBO_END};
const uint16_t PROGMEM combo_l1_mid_c7[]  = {key_l1_r0_c7, key_l1_r1_c7, COMBO_END};
const uint16_t PROGMEM combo_l1_mid_c8[]  = {key_l1_r0_c8, key_l1_r1_c8, COMBO_END};
const uint16_t PROGMEM combo_l1_mid_c9[]  = {key_l1_r0_c9, key_l1_r1_c9, COMBO_END};
const uint16_t PROGMEM combo_l1_mid_c10[] = {key_l1_r0_c10, key_l1_r1_c10, COMBO_END};

const uint16_t PROGMEM combo_l2_mid_c1[] = {key_l2_r0_c1, key_l2_r1_c1, COMBO_END};
const uint16_t PROGMEM combo_l2_mid_c2[] = {key_l2_r0_c2, key_l2_r1_c2, COMBO_END};
const uint16_t PROGMEM combo_l2_mid_c3[] = {key_l2_r0_c3, key_l2_r1_c3, COMBO_END};
const uint16_t PROGMEM combo_l2_mid_c4[] = {key_l2_r0_c4, key_l2_r1_c4, COMBO_END};
const uint16_t PROGMEM combo_l2_mid_c5[] = {key_l2_r0_c5, key_l2_r1_c5, COMBO_END};

const uint16_t PROGMEM combo_l2_mid_c6[]  = {key_l2_r0_c6, key_l2_r1_c6, COMBO_END};
const uint16_t PROGMEM combo_l2_mid_c7[]  = {key_l2_r0_c7, key_l2_r1_c7, COMBO_END};
const uint16_t PROGMEM combo_l2_mid_c8[]  = {key_l2_r0_c8, key_l2_r1_c8, COMBO_END};
const uint16_t PROGMEM combo_l2_mid_c9[]  = {key_l2_r0_c9, key_l2_r1_c9, COMBO_END};
const uint16_t PROGMEM combo_l2_mid_c10[] = {key_l2_r0_c10, key_l2_r1_c10, COMBO_END};

combo_t key_combos[] = {
    // Layer 0
    [COMBO_L0_MID_C1]  = COMBO(combo_l0_mid_c1, key_l0_mid_c1),
    [COMBO_L0_MID_C2]  = COMBO(combo_l0_mid_c2, key_l0_mid_c2),
    [COMBO_L0_MID_C3]  = COMBO(combo_l0_mid_c3, key_l0_mid_c3),
    [COMBO_L0_MID_C4]  = COMBO(combo_l0_mid_c4, key_l0_mid_c4),
    [COMBO_L0_MID_C5]  = COMBO(combo_l0_mid_c5, key_l0_mid_c5),
    [COMBO_L0_MID_C6]  = COMBO(combo_l0_mid_c6, key_l0_mid_c6),
    [COMBO_L0_MID_C7]  = COMBO(combo_l0_mid_c7, key_l0_mid_c7),
    [COMBO_L0_MID_C8]  = COMBO(combo_l0_mid_c8, key_l0_mid_c8),
    [COMBO_L0_MID_C9]  = COMBO(combo_l0_mid_c9, key_l0_mid_c9),
    [COMBO_L0_MID_C10] = COMBO(combo_l0_mid_c10, key_l0_mid_c10),

    // Layer 1
    [COMBO_L1_MID_C1]  = COMBO(combo_l1_mid_c1, key_l1_mid_c1),
    [COMBO_L1_MID_C2]  = COMBO(combo_l1_mid_c2, key_l1_mid_c2),
    [COMBO_L1_MID_C3]  = COMBO(combo_l1_mid_c3, key_l1_mid_c3),
    [COMBO_L1_MID_C4]  = COMBO(combo_l1_mid_c4, key_l1_mid_c4),
    [COMBO_L1_MID_C5]  = COMBO(combo_l1_mid_c5, key_l1_mid_c5),
    [COMBO_L1_MID_C6]  = COMBO(combo_l1_mid_c1, key_l1_mid_c1),
    [COMBO_L1_MID_C7]  = COMBO(combo_l1_mid_c2, key_l1_mid_c2),
    [COMBO_L1_MID_C8]  = COMBO(combo_l1_mid_c3, key_l1_mid_c3),
    [COMBO_L1_MID_C9]  = COMBO(combo_l1_mid_c4, key_l1_mid_c4),
    [COMBO_L1_MID_C10] = COMBO(combo_l1_mid_c5, key_l1_mid_c5),

    // Layer 2
    [COMBO_L2_MID_C1]  = COMBO(combo_l2_mid_c1, key_l2_mid_c1),
    [COMBO_L2_MID_C2]  = COMBO(combo_l2_mid_c2, key_l2_mid_c2),
    [COMBO_L2_MID_C3]  = COMBO(combo_l2_mid_c3, key_l2_mid_c3),
    [COMBO_L2_MID_C4]  = COMBO(combo_l2_mid_c4, key_l2_mid_c4),
    [COMBO_L2_MID_C5]  = COMBO(combo_l2_mid_c5, key_l2_mid_c5),
    [COMBO_L2_MID_C6]  = COMBO(combo_l2_mid_c6, key_l2_mid_c6),
    [COMBO_L2_MID_C7]  = COMBO(combo_l2_mid_c7, key_l2_mid_c7),
    [COMBO_L2_MID_C8]  = COMBO(combo_l2_mid_c8, key_l2_mid_c8),
    [COMBO_L2_MID_C9]  = COMBO(combo_l2_mid_c9, key_l2_mid_c9),
    [COMBO_L2_MID_C10] = COMBO(combo_l2_mid_c10, key_l2_mid_c10),
};

// Returns whether to delagate the key event handling to QMK's default.
// https://docs.qmk.fm/custom_quantum_functions#example-process-record-user-implementation
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void matrix_scan_user(void) {
    //
}
