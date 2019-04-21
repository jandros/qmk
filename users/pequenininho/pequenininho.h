#ifndef PEQUENININHO_H
#define PEQUENININHO_H
/***************************************************
 * intellij shortcuts
***************************************************/

// open class
#define IJ_OPNC LCTL(KC_N)

// open file
#define IJ_OPNF LSFT(LCTL(KC_N))

// generate code
#define IJ_GEN LALT(KC_INS)

// back
#define IJ_BK LALT(LCTL(KC_LEFT))

// forward
#define IJ_FWD LALT(LCTL(KC_RGHT))

// format code
#define IJ_FMT LALT(LCTL(KC_L))

// rename
#define IJ_RNAM LSFT(KC_F6)

// refactor
#define IJ_RFTR LCTL(LALT(LSFT(KC_T)))

// go to declaration
#define IJ_GDEC LCTL(KC_B)

// find usages
#define IJ_USAG LALT(KC_F7)

// recent files
#define IJ_RECN LCTL(KC_E)


/***************************************************
 * Basic definitions for ortho keyboards
 ***************************************************/
#define LOWER TT(_LOWER)
#define RAISE TT(_RAISE)
#define RALTD RALT_T(KC_DOWN)
#define RGUIU RGUI_T(KC_UP)
#define RCTLR RCTL_T(KC_RGHT)

#endif