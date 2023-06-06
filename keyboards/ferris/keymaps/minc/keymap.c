#include QMK_KEYBOARD_H

// Home row mods
#define HR_A    LGUI_T(KC_A)
#define HR_S    LALT_T(KC_S)
#define HR_D    LCTL_T(KC_D)
#define HR_F    LSFT_T(KC_F)
#define HR_J    LSFT_T(KC_J)
#define HR_K    LCTL_T(KC_K)
#define HR_L    LALT_T(KC_L)
#define HR_SCLN LGUI_T(KC_SCLN)

// Layers
enum Layers {
  U_BASE,
  U_NAV,
  U_SYM0,
  U_SYM1,
  U_NUM,
};

// Base layer thumbs
#define LT_ESC  LT(U_NAV, KC_ESC)
#define LT_BSPC LT(U_SYM0, KC_BSPC)
#define LT_ENT  LT(U_SYM1, KC_ENT)
#define LT_SPC  LT(U_NUM, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [U_BASE] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
    HR_A,    HR_S,    HR_D,    HR_F,    KC_G,           KC_H,    HR_J,  HR_K,    HR_L,   HR_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                               LT_ESC,  LT_SPC,         LT_BSPC, LT_ENT
  ),
  [U_NAV] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        KC_INS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,
                               XXXXXXX, _______,        _______, _______
  ),
  [U_SYM0] = LAYOUT(
    KC_DLR,  KC_AMPR, KC_PIPE, KC_LPRN, KC_RPRN,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_COLN, KC_EQL,  KC_ASTR, KC_UNDS, KC_TILD,        XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_EXLM, KC_HASH, KC_PERC, KC_DQT,  KC_CIRC,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               KC_LCBR, KC_RCBR,        XXXXXXX, _______
  ),
  [U_SYM1] = LAYOUT(
    XXXXXXX, XXXXXXX, KC_BSLS, KC_LBRC, KC_RBRC,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_AT,   KC_PLUS, KC_QUES, KC_MINS, KC_GRV,         XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               KC_LT,   KC_GT,          _______, XXXXXXX
  ),
  [U_NUM] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TAB,         XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,
    XXXXXXX, C(KC_X), C(KC_C), C(KC_V), XXXXXXX,        XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX,
                               _______, XXXXXXX,        _______, KC_0
  ),
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_ESC: return true;
        case LT_BSPC: return true;
        case LT_ENT: return true;
        default: return false;
    }
}
