#include QMK_KEYBOARD_H
#include "process_unicode.h"
#include <sendstring_german.h>

//make iris/rev2:cineafx

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _MACRO 4

#define CUSTOMMACRO(MACROKEYCODE, DOWN) case MACROKEYCODE : \
      if (record->event.pressed) { \
        DOWN \
      } \
      break;

#define PYRAMID(AMOUNT) \
int i; \
register_code(KC_LCTRL); \
for(i = 0; i< AMOUNT ; i++) { \
	tap_code(KC_V); \
	_delay_ms(50); \
	tap_code(KC_ENTER); \
	_delay_ms(50); \
} \
for(i = 0; i< AMOUNT ; i++) { \
	tap_code(KC_BSPACE); \
	_delay_ms(50); \
	tap_code(KC_ENTER); \
	_delay_ms(50); \
} \
unregister_code(KC_LCTRL);

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MACRO,
  TRUELULW,
  PAJASHRU,
  HEAD,
  OKAY,
  FDM,
  PP_H,
  D_PP_H,
  D_PP_HCOMF,
  D_PP_HALL,
  APPDATA,
  NICEMEME,
  ARMALOGI,
  ARMAMISS,
  PYRA5,
  PYRA10,
  PYRA20,
};


// #define KC_ KC_TRNS
#define _______ KC_TRNS

// #define KC_LOWR LOWER
// #define KC_RASE RAISE
// #define KC_RST RESET
// #define KC_BL_S BL_STEP
// #define KC_DBUG DEBUG


#define KC_SNUBS RSFT(KC_NUBS)
#define CTRL_ESC LCTL_T(KC_ESC)


enum unicode_names {
  LAB,
  RAB,
  SQUBL,
  SQUBR,
  CURBL,
  CURBR,
  PPIPE,
  TTILD,
  BBSL,
  NOCHAR
};

const uint32_t PROGMEM unicode_map[] = {
  [LAB]   = 0x3008,  // 〈
  [RAB]   = 0x3009,  // 〉
  [SQUBL] = 0x005B,  // [
  [SQUBR] = 0x005D,  // ]
  [CURBL] = 0x007B,  // {
  [CURBR] = 0x007D,  // }
  [PPIPE] = 0x007C,  // |
  [TTILD] = 0x007E,  // ~
  [BBSL] = 0x005C,   // backslash
  [NOCHAR] = 0xE0000 // <not a character>
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
     KC_GESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,KC_MINS ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
     KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,KC_LBRC ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
     KC_LCTL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                        KC_H   , KC_J   , KC_K   , KC_L   ,KC_SCLN ,KC_QUOT ,
  //|--------+--------+--------+--------+--------+--------+--------.    ,--------|--------+--------+--------+--------+--------+--------|
     KC_LSFT , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,KC_LGUI,       MACRO  , KC_N   , KC_M   ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //`--------+--------+--------+--+-+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
                                   KC_LALT , LOWER  ,KC_SPC  ,              KC_ENT , RAISE  ,KC_BSPC
  //                              `--------+--------+--------'            `--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
     KC_GRV  , _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, KC_EQL ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                       KC_INS  ,KC_PGUP ,KC_HOME ,KC_PGDN ,KC_PSCR ,KC_RBRC ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
     _______ , _______, _______, _______, _______, _______,                       KC_LEFT ,KC_DOWN , KC_UP  ,KC_RGHT , _______,KC_BSLS ,
  //|--------+--------+--------+--------+--------+--------+--------.    ,--------|--------+--------+--------+--------+--------+--------|
     _______ ,KC_NUBS ,KC_SNUBS, _______, _______, _______, _______,     KC_SLCK ,KC_END  , _______, _______, _______, _______, _______,
  //`--------+--------+--------+--+-+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
                                _______, _______, _______,              _______, _______, KC_DEL
  //                  			  `--------+--------+--------'            `--------+--------+--------'
  ),

  [_RAISE] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                        X(BBSL),X(CURBL),X(SQUBL),X(SQUBR),X(CURBR), KC_F12 ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 ,                        KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 ,
  //|--------+--------+--------+--------+--------+--------+--------.    ,--------|--------+--------+--------+--------+--------+--------|
      _______,KC_NUBS ,KC_SNUBS,X(PPIPE),X(TTILD), _______, KC_CAPS,     KC_PAUS , X(LAB) , X(RAB) , _______, _______, KC_F24 , _______,
  //`--------+--------+--------+--+-+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
                                    _______, _______, _______,              _______, _______, KC_DEL
  //                              `~--------+--------+--------'            `--------+--------+--------'
  ),

  [_ADJUST] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      MI_C_3 , MI_Cs_3, MI_D_3 , MI_Ds_3, MI_E_3 , MI_F_3 ,                            MI_Fs_3, MI_G_3 , MI_Gs_3, MI_A_3 , MI_As_3, MI_B_3 ,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      MI_C_2 , MI_Cs_2, MI_D_2 , MI_Ds_2, MI_E_2 , MI_F_2 ,                            MI_Fs_2, MI_G_2 , MI_Gs_2, MI_A_2 , MI_As_2, MI_B_2 ,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      MI_C_1 , MI_Cs_1, MI_D_1 , MI_Ds_1, MI_E_1 , MI_F_1 ,                            MI_Fs_1, MI_G_1 , MI_Gs_1, MI_A_1 , MI_As_1, MI_B_1 ,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      MI_C   , MI_Cs  , MI_D   , MI_Ds  , MI_E   , MI_F   , MI_OCTD,          MI_OCTU, MI_Fs  , MI_G   , MI_Gs  , MI_A   , MI_As  , MI_B   ,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______,_______,               _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  ),

  [_MACRO] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, PYRA5  , PYRA10 , PYRA20 , _______, _______,                          X(NOCHAR), _______, _______, _______, _______, UC_M_WC,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, APPDATA,TRUELULW,                           D_PP_H,D_PP_HCOMF,D_PP_HALL,_______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______,PAJASHRU, _______, FDM    , _______,                           PP_H , _______, OKAY   ,ARMALOGI, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, KC_ALGR,          _______,NICEMEME,ARMAMISS, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,               _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
   // case QWERTY:
   //   if (record->event.pressed) {
   //     persistent_default_layer_set(1UL<<_QWERTY);
   //   }
   //   return false;
   //   break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case MACRO:
      if (record->event.pressed) {
        layer_on(_MACRO);
      } else {
        layer_off(_MACRO);
      }
      return false;
      break;

	//MACROS
	CUSTOMMACRO(TRUELULW, SEND_STRING("+:regional_indicator_t:" SS_TAP(X_ENTER)); \
                        SEND_STRING("+:regional_indicator_r:" SS_TAP(X_ENTER)); \
                        SEND_STRING("+:regional_indicator_u:" SS_TAP(X_ENTER)); \
                        SEND_STRING("+:regional_indicator_e:" SS_TAP(X_ENTER)); \
                        SEND_STRING("+:LULW" SS_TAP(X_ENTER)); \
              )
	CUSTOMMACRO(PAJASHRU,	SEND_STRING(" pajaShrugL pajaW pajaShrugR ");)
	CUSTOMMACRO(HEAD, 		SEND_STRING(" forsenHead ");)
	CUSTOMMACRO(OKAY, 		SEND_STRING(" pupperK forsenK ");)
	CUSTOMMACRO(FDM, 		  SEND_STRING(" FeelsDankMan ");)
	CUSTOMMACRO(PP_H, 	  SEND_STRING(" pupperH ");)
	CUSTOMMACRO(D_PP_H,   SEND_STRING("+:pupperH:" SS_TAP(X_ENTER));)
	CUSTOMMACRO(D_PP_HCOMF, SEND_STRING("+:pupperH:" SS_TAP(X_ENTER)); \
                          SEND_STRING("+:pupperHcomfz:" SS_TAP(X_ENTER));)
  CUSTOMMACRO(D_PP_HALL,  SEND_STRING("+:pupperH:" SS_TAP(X_ENTER)); \
                          SEND_STRING("+:pupperHcomfz:" SS_TAP(X_ENTER)); \
                          SEND_STRING("+:pupperHtomato:" SS_TAP(X_ENTER)); \
                          SEND_STRING("+:pupperHpride:" SS_TAP(X_ENTER)); \
                          SEND_STRING("+:pupperHsanta:" SS_TAP(X_ENTER)); \
                          SEND_STRING("+:pupperHsnowglobe:" SS_TAP(X_ENTER)); \
                          SEND_STRING("+:pupperHornament:" SS_TAP(X_ENTER));)
	CUSTOMMACRO(APPDATA, 	register_code(KC_LGUI);
							register_code(KC_R);
							unregister_code(KC_R);
							unregister_code(KC_LGUI);
							_delay_ms(100);
							SEND_STRING("%appdata%"SS_TAP(X_ENTER));
		)
	CUSTOMMACRO(NICEMEME,	send_unicode_hex_string("006E 036B 0069 0364 0063 036B 0065 0364");)
	CUSTOMMACRO(ARMALOGI, SEND_STRING("-#login"SS_TAP(X_ENTER));)
	CUSTOMMACRO(ARMAMISS, SEND_STRING("-#missions"SS_TAP(X_ENTER));)
	CUSTOMMACRO(PYRA5, PYRAMID(5))
	CUSTOMMACRO(PYRA10, PYRAMID(10))
	CUSTOMMACRO(PYRA20, PYRAMID(20))
  }
  return true;
}
