#include QMK_KEYBOARD_H
#include <stdio.h>
#include "oled_setup.c"
#include "oled_setup.h"

#define L2_ENT LT(_Layer2, KC_ENT)
#define L3_ESC LT(_Layer3, KC_ESC)

#define L1_BSPC LT(_Layer1, KC_BSPC)
#define L2_SPC LT(_Layer2, KC_SPC)

#define C_Z LCTL_T(KC_Z)
#define A_X LALT_T(KC_X)
#define G_C LGUI_T(KC_C)
#define S_V LSFT_T(KC_V)

#define S_M LSFT_T(KC_M)
#define G_COMM LGUI_T(KC_COMM)
#define A_DOT LALT_T(KC_DOT)
#define C_SLSH LCTL_T(KC_SLSH)

#define S_D LSFT_T(KC_D)
#define S_H LSFT_T(KC_H)

#define A_PIPE LALT_T(KC_PIPE)
#define G_LBRC LGUI_T(KC_LBRC)
#define S_RBRC LSFT_T(KC_RBRC)

#define SS1 SGUI(KC_4)
#define SS2 SGUI(KC_5)

#define WF A(KC_RIGHT)
#define WB A(KC_LEFT)

#define LF G(KC_RIGHT)
#define LB G(KC_LEFT)

#define SF S(KC_RIGHT)
#define SB S(KC_LEFT)

#define DLEFT C(KC_LEFT)
#define DRIGHT C(KC_RIGHT)

#define TABLEFT S(C(KC_TAB))
#define TABRIGHT C(KC_TAB)

#define BACK G(KC_LBRC)
#define FORWARD G(KC_RBRC)

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
};

enum layer {
    _COLEMAK,
    _QWERTY,
    _Layer1,
    _Layer2,
    _Layer3,
    _Layer4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
    KC_TAB,        KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,        KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_EQL,
    L3_ESC,        KC_A,    KC_S,    KC_D,   KC_F,   KC_G,        KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,
    OSM(MOD_LSFT), C_Z,     A_X,     G_C,    S_V,    KC_B,        KC_N,   S_M,    G_COMM, A_DOT,   C_SLSH,  OSM(MOD_RSFT),
                            KC_DEL, KC_BSPC, OSL(_Layer1),        OSL(_Layer2), KC_SPC, KC_ENT
  ),

  [_COLEMAK] = LAYOUT_split_3x6_3(
    KC_TAB,        KC_Q,    KC_W,    KC_F,   KC_P,   KC_B,        KC_J,   KC_L,   KC_U,   KC_Y,    KC_SCLN, KC_EQL,
    L3_ESC,        KC_A,    KC_R,    KC_S,   KC_T,   KC_G,        KC_M,   KC_N,   KC_E,   KC_I,    KC_O,    KC_QUOT,
    OSM(MOD_LSFT), C_Z,     A_X,     G_C,    S_D,    KC_V,        KC_K,   S_H,    G_COMM, A_DOT,   C_SLSH,  OSM(MOD_RSFT),
                            KC_DEL, KC_BSPC, OSL(_Layer1),        OSL(_Layer2), KC_SPC, KC_ENT
  ),

  [_Layer1] = LAYOUT_split_3x6_3(
    _______, _______, _______, KC_LCBR, KC_RCBR, _______,         _______, KC_7, KC_8,    KC_9,    KC_PAST, KC_PEQL,
    _______, _______, KC_BSLS, KC_LPRN, KC_RPRN, _______,         KC_DOT,  KC_4, KC_5,    KC_6,    KC_PPLS, KC_MINS,
    _______, KC_LCTL, KC_PIPE, G_LBRC,  S_RBRC,  _______,         KC_COMM, KC_1, KC_2,    KC_3,    KC_PSLS, _______,
                               _______, _______, _______,         _______, _______, KC_0
  ),

  /* [_Layer1] = LAYOUT_split_3x6_3( */
  /*   _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PEQL, */
  /*   _______, _______, KC_BSLS, KC_LPRN, KC_RPRN, _______,         _______, KC_LCBR, KC_RCBR, _______, KC_PPLS, KC_MINS, */
  /*   _______, KC_LCTL, KC_PIPE, G_LBRC,  S_RBRC,  _______,         _______, _______, KC_DOT,  KC_COMM, KC_PSLS, _______, */
  /*                              _______, _______, _______,         _______, _______, _______ */
  /* ), */

  [_Layer2] = LAYOUT_split_3x6_3(
    _______, _______, _______, KC_VOLD, KC_VOLU, _______,         _______, KC_AMPR, KC_ASTR, KC_LPRN, _______, _______,
    _______, _______, KC_MRWD, KC_MPLY, KC_MFFD, _______,         _______, KC_DLR,  KC_PERC, KC_CIRC, KC_TILD, KC_UNDS,
    _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,         _______, KC_EXLM, KC_AT,   KC_HASH, KC_GRV,  TO(_Layer3),
                               _______, _______, _______,         _______, _______, _______
  ),

  [_Layer3] = LAYOUT_split_3x6_3(
    _______, _______, KC_MS_D, KC_MS_U, KC_MS_BTN1, _______,      _______, BACK,    TABLEFT, TABRIGHT, FORWARD, _______,
    _______, _______, SS1,     SS2,     HYPR(KC_F), _______,      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, DLEFT,   DRIGHT,
    _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,    _______,      LB,      WB,      WF,      LF,       _______, _______,
                                 _______, _______,  _______,      TO(0), _______, KC_DEL
  ),

  [_Layer4] = LAYOUT_split_3x6_3(
    RESET,   _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, COLEMAK, QWERTY,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,         _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _Layer1, _Layer2, _Layer4);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L2_ENT:
            return TAPPING_TERM - 106;
        case L3_ESC:
            return TAPPING_TERM - 95;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
    }
    return true;
}
