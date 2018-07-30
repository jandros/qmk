#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

//#define SHFT_CAPS TD(DOUBLE_SHIFT)


enum custom_layers {
    L_QWERTY,
    //L_COLEMAK,
    L_PADS,
    L_GAMING,
    L_ARROWS,
    L_MOUSE,
    L_UTIL
};

/* //tap dance appears to be broken
enum tap_dances{
    DOUBLE_SHIFT = 0
};
*/

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_QWERTY] = LAYOUT_ergodox(  // layer 0 : default
/*
 * left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |   =   |  0  |  2  |  3  |  4  |  5  | ESC |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |   \   |  Q  |  W  |  E  |  R  |  T  |LCK-2|
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |  TAB  |  A  |  S  |  D  |  F  |  G  +-----+
 *    +-------+-----+-----+-----+-----+-----+LCK-1|
 *    | LSHIFT|  Z  |  X  |  C  |  V  |  B  |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |LGUI |  `  |  \  |     |LYR M|
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |LCTRL| LALT|
 *                                  +-----+-----+-----+
 *                                  |     |     | HOME|
 *                                  |BKSPC| DEL +-----+
 *                                  |     |     | END |
 *                                  +-----+-----+-----+
 */
        KC_EQL,    KC_1,   KC_2,    KC_3,    KC_4,    KC_5, KC_ESC,
        KC_BSLS,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, TG(L_GAMING),
        KC_TAB,    KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, MO(L_PADS),
        KC_LGUI,   KC_GRV, KC_BSLS, KC_NO, MO(L_MOUSE),
                                                      KC_LCTL, KC_LALT,
                                                               KC_HOME,
                                             KC_BSPC, KC_DELT, KC_END,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |LCK-3|  6  |  7  |  8  |  9  |  0  |   -   |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |  [  |  Y  |  U  |  I  |  O  |  P  |   ]   |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+  H  |  J  |  K  |  L  |  ;  |   '   |
 *        | f2  +-----+-----+-----+-----+-----+-------+
 *        |     |  N  |  M  |  ,  |  .  |  /  | RSHIFT|
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |lyr->|lock |     |     | RGUI|
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    | RALT|RCTRL|
 *    +-----+-----+-----+
 *    | PGUP|     |     |
 *    +-----+ ENT | SPC |
 *    | PGDN|     |     |
 *    +-----+-----+-----+
 */
             TG(L_UTIL),  KC_6,   KC_7,    KC_8,      KC_9,   KC_0,     KC_MINS,
             KC_LBRC,     KC_Y,   KC_U,    KC_I,      KC_O,   KC_P,     KC_RBRC,
                          KC_H,   KC_J,    KC_K,      KC_L,   KC_SCLN,  KC_QUOT,
             MO(L_PADS),  KC_N,   KC_M,    KC_COMM,   KC_DOT, KC_SLSH,  KC_RSFT,
                           MO(L_ARROWS), KC_LOCK, KC_NO,  KC_NO, KC_RGUI,
             KC_RALT, KC_RCTL,
             KC_PGUP,
             KC_PGDN, KC_ENT, KC_SPC
    ),

[L_PADS] = LAYOUT_ergodox( //Layer 1 : number pads
/* left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     | f10 | f11 | f12 |     |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     | f9  | f8  | f7  |     |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     | f6  | f5  | f4  |     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     | f3  | f2  | f1  |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |play |mute |
 *                                  +-----+-----+-----+
 *                                  |     |     |VOL+ |
 *                                  |prev |next +-----+
 *                                  |     |     |VOL- |
 *                                  +-----+-----+-----+
 */
        KC_TRNS, KC_TRNS,   KC_F10, KC_F11,   KC_F12,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_F9,   KC_F8,   KC_F7,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_F6,   KC_F5,   KC_F4,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_F3,   KC_F2,   KC_F1,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                             KC_MPLY, KC_MUTE,
                                                                      KC_VOLU,
                                                    KC_MPRV, KC_MNXT, KC_VOLD,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |NMLCK| P/  | P*  | P-  |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     | P7  | P8  | P9  | P+  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     | P4  | P5  | P6  | P+  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     | P1  | P2  | P3  |PENT |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     | P.  |PENT |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     | P0  |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
        KC_TRNS,  KC_TRNS, KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_7,       KC_8,        KC_9,           KC_KP_PLUS,  KC_TRNS,
                  KC_TRNS, KC_4,       KC_5,        KC_6,           KC_KP_PLUS,  KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_1,       KC_2,        KC_3,           KC_KP_ENTER, KC_TRNS,
        KC_TRNS,  KC_TRNS,     KC_KP_DOT,      KC_KP_ENTER, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_KP_0
),

[L_GAMING] = LAYOUT_ergodox( //Layer 2 : gaming
/* left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    | LSHFT |     |     |     |     |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  | SPC |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                              KC_TRNS, KC_TRNS,
                                                                       KC_TRNS,
                                                      KC_SPC, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_3,    KC_KP_ENTER, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_KP_DOT,  KC_KP_ENTER, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_KP_0
),

[L_ARROWS] = LAYOUT_ergodox( //Layer 3 : arrows
/* left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     | UP  |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     | LEFT| DOWN|RIGHT|     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_3,    KC_KP_ENTER, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_KP_DOT,  KC_KP_ENTER, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_KP_0
),[L_MOUSE] = LAYOUT_ergodox( // Layer 4: mouse emulation
/* Left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     | MU  |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     | ML  | MD  | RM  |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+ LB  | RB  |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
        KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_MS_UP,    KC_TRNS,        KC_TRNS,     KC_TRNS,
                  KC_TRNS,  KC_MS_LEFT, KC_MS_DOWN,  KC_MS_RIGHT,    KC_TRNS,     KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,
            KC_TRNS,    KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_MS_BTN1, KC_MS_BTN2
),

[L_UTIL] = LAYOUT_ergodox( // Layer 5: flash/utility
/* Left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    | FLASH |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
        RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     | FLASH |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
        KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,     RESET,
        KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,
        KC_TRNS,    KC_TRNS,     KC_KP_DOT,      KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
),
};


/*qk_tap_dance_action_t tap_dance_actions[] = {
        // simple tap dance
        [DOUBLE_SHIFT] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT,KC_CAPSLOCK)
};*/

/* no idea what this does...
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(L1)                // FN1 - Momentary Layer 1 (Function)
};
*/
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

//Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
