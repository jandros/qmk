#include QMK_KEYBOARD_H
#include "pequenininho.h"

#define DEFAULT_LAYER_COLOR HSV_ORANGE
#define RAISE_LAYER_COLOR HSV_RED
#define LOWER_LAYER_COLOR HSV_BLUE
#define MAC_LAYER_COLOR HSV_SPRINGGREEN

extern keymap_config_t keymap_config;

enum nyquist_layers {
    _QWERTY = 0,
    _MAC,
    _LOWER,
    _RAISE,
    _ADJUST,
};
// useful for identifying which LED is which
const rgblight_segment_t PROGMEM qwerty[] = RGBLIGHT_LAYER_SEGMENTS(
{0,1, HSV_WHITE},
{1,1, HSV_RED},
{2,1, HSV_ORANGE},
{3,1, HSV_AZURE},
{4,1, HSV_GREEN},
{5,1, HSV_TEAL},
{6,1, HSV_BLUE},
{7,1, HSV_PURPLE},
{8,1, HSV_MAGENTA},
{9,1, HSV_SPRINGGREEN},
{10,1, HSV_CORAL},
{11,1, HSV_CHARTREUSE}
);

const rgblight_segment_t PROGMEM lower[] = RGBLIGHT_LAYER_SEGMENTS(
{0, 12, LOWER_LAYER_COLOR}
);

const rgblight_segment_t PROGMEM raise[] = RGBLIGHT_LAYER_SEGMENTS(
{0, 12, RAISE_LAYER_COLOR}
);

const rgblight_segment_t PROGMEM adjust[] = RGBLIGHT_LAYER_SEGMENTS(
{0,3, LOWER_LAYER_COLOR},
{3,3, RAISE_LAYER_COLOR},
{6,3,LOWER_LAYER_COLOR},
{9,3, RAISE_LAYER_COLOR}
);

const rgblight_segment_t PROGMEM mac[] = RGBLIGHT_LAYER_SEGMENTS(
{0,1, MAC_LAYER_COLOR},
{6,1, MAC_LAYER_COLOR}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(lower, raise, adjust, mac);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Lock |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT , \
  KC_LCTL, KC_LGUI, KC_LALT, KC_LOCK, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, RALTD,    RGUIU,    RCTLR \
),

/* MAC
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MAC] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , \
  KC_LGUI, KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, RCTLU,   RGUIR \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
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
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_GRV,  KC_F10,  KC_F9,   KC_F8,   KC_F7,   _______, _______, KC_7,    KC_8,    KC_9,    _______, KC_DEL , \
  _______, KC_F11,  KC_F6,   KC_F5,   KC_F4,   _______, _______, KC_4,    KC_5,    KC_6,    _______, KC_BSLS, \
  _______, KC_F12,  KC_F3,   KC_F2,   KC_F1,   _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______, _______, _______, _______, _______, KC_0,    KC_0,    _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
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
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_GRV,  _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______, KC_LPRN, KC_RPRN, KC_DEL,  \
  KC_PSCR, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_MINUS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_INS,  KC_INS,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,TG(_MAC), _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif



void keyboard_post_init_user(void) {
    rgblight_mode_noeeprom(0);
    rgblight_sethsv_noeeprom(DEFAULT_LAYER_COLOR);
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t newState = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(0, layer_state_cmp(newState, _LOWER));
    rgblight_set_layer_state(1, layer_state_cmp(newState, _RAISE));
    rgblight_set_layer_state(2, layer_state_cmp(newState, _ADJUST));
    rgblight_set_layer_state(3, layer_state_cmp(newState, _MAC));
    return newState;
}



void suspend_power_down_user(void) {
    rgblight_disable();
}

void suspend_wakeup_init_user(void) {
    rgblight_enable();
}


bool led_update_user(led_t led_state) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        default:
            return true;
    }
}
