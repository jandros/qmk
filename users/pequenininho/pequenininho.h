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

// VCS Tool Window
#define IJ_VCS LALT(KC_9)

// Project Tool Window 
#define IJ_PROJ LALT(KC_1)

// Structure Tool Window
#define IJ_SRCT LALT(KC_7)

// Parameters popup
#define IJ_PRAM LCTL(KC_P)

// Find Action
#define IJ_ACTN LCTL(LSFT(KC_A))

/***************************************************
 *  shortcuts
***************************************************/
// Auto Fix
#define CR_AUTO LSFT(LALT(KC_DOT))

// Go To Reference
#define CR_GREF LSFT(KC_F12)

// Go To Definition
#define CR_GDEF KC_F12

//Go To File
#define CR_GFIL LCTL(KC_O)

// Go To Implementation
#define CR_GIMP LCTL(KC_F12)

// Peek Definition
#define CR_PDEF LCTL(LSFT(KC_F10))

// Peek Implementation
#define CR_PIMP LCTL(LSFT(KC_F12))

// Split
#define CR_SPLT LCTL(KC_SLASH)

// Back
#define CR_BACK LCTL(LALT(KC_MINUS))

//Forward
#define CR_FWD LCTL(LSFT(KC_MINUS))

// Open Previous Editor
#define CR_PREE LCTL(KC_PGUP)

// Open Next Editor
#define CR_NEXE LCTL(KC_PGDN)

// Format
#define CR_FRMT LCTL(LSFT(KC_I))

// 

/***************************************************
 * Basic definitions for ortho keyboards
 ***************************************************/
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define RALTD RALT_T(KC_DOWN)
#define RGUIU RGUI_T(KC_UP)
#define RCTLR RCTL_T(KC_RGHT)
#define RGUIR RGUI_T(KC_RGHT)
#define RCTLU RCTL_T(KC_UP)

#endif