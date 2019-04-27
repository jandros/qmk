/* Copyright 2018 pequenininho
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
 /*
 * This keymap is modified from my planck version, to account for the additional keys in the id75.
 * It requires my config.h from the Pequenininho user area to include the intellij key shortcuts.
 */
#include QMK_KEYBOARD_H
#include "pequenininho.h"


enum idobo_layers {
	_QWERTY,
	_RAISE,
	_LOWER,
	_ADJUST
};





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY 
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     |        |        |        | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |        |        |        | Y      | U      | I      | O      | P      | BKSP   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | A      | S      | D      | F      | G      |        |        |        | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      |        |        |        | N      | M      | ,      | .      | /      | ENTER  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | LOCK   | LOWER  | SPACE  |        |        |        | SPACE  | RAISE  | LEFT   | DOWN   | UP     | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QWERTY] = LAYOUT_ortho_5x15(
   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  IJ_RECN, IJ_OPNF, IJ_OPNC, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   IJ_GDEC, IJ_GEN,  IJ_USAG, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   IJ_BK,   IJ_ACTN, IJ_FWD,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   IJ_FMT,  IJ_RFTR, IJ_PRAM, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
   KC_LCTL, KC_LGUI, KC_LALT, KC_LOCK, LOWER,   KC_SPC, IJ_PROJ, IJ_VCS,  IJ_SRCT, KC_SPC,  RAISE,   KC_LEFT, RALTD,   RGUIU,   RCTLR  \
 ),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      | Home |  UP  | End  |Pg_up |      |      |      |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | PSCR |      | LEFT | DOWN | RGHT |Pg_dn |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |     Ins     |      | Home |Pg_dn |Pg_up | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x15(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_GRV,  _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_DEL,  \
  KC_PSCR, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, _______, _______, KC_MINUS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_INS,  _______, _______, _______, KC_INS,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END 
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F10 |  F7  |  F8  |  F9  |      |      |   7  |   8  |   9  |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F4  |  F5  |  F6  |      |      |   4  |   5  |   6  |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F12 |  F3  |  F2  |  F1  |      |      |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      0      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x15(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_GRV,  KC_F10,  KC_F9,   KC_F8,   KC_F7,   _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, KC_DEL , \
  _______, KC_F11,  KC_F6,   KC_F5,   KC_F4,   _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, KC_BSLS, \
  _______, KC_F12,  KC_F3,   KC_F2,   KC_F1,   _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______, _______, _______, _______, _______, KC_0,    _______, _______, _______,  KC_0,   _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      | Click|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x15(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
  _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, _______, _______, _______, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL , \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, _______, _______, _______, AG_SWAP, _______,  _______,  _______,  _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   _______, _______, _______, MI_OFF,  TERM_ON, TERM_OFF, _______, CK_TOGG, _______, \
  _______, _______, _______, _______, _______, _______,  _______, _______, _______,_______, _______, _______,  _______, _______, _______
)
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}