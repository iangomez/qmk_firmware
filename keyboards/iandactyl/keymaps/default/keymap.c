#include QMK_KEYBOARD_H
#include "print.h"

#define ALT_F9 MT(MOD_LALT, KC_F9)  // Alt F9
#define LT1_A LT(1,KC_A)            // _ARROWS
// #define LT2_S LT(2,KC_S)         // _F_KEYS
#define LT3_D LT(3,KC_D)            // _NUMPAD
#define LT4_F LT(4,KC_F)            // _SYMBOLS
#define LT3_CLN LT(3,KC_SCLN)       // _NUMPAD
#define SFT_GRV LSFT_T(KC_GRV)      // Grave Shift


#define _MAIN     0
#define _ARROWS   1
// #define _F_KEYS   
#define _NUMPAD   3
#define _SYMBOLS  4

enum custom_keycodes {
  TAB_ESC, // Tab Escape
  WIN_SS,  // Windows screenshot
  MAC_SS,  // Mac snagit screenshot
  MISCTRL, // Mission Control
  FOCUS_D, // Focus macos dock
};
const rgblight_segment_t PROGMEM layer_rgb_0[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_RED});
const rgblight_segment_t PROGMEM layer_rgb_1[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM layer_rgb_2[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_BLUE});
const rgblight_segment_t PROGMEM layer_rgb_3[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_PURPLE});
const rgblight_segment_t PROGMEM layer_rgb_4[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_YELLOW});
const rgblight_segment_t PROGMEM layer_rgb_5[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_ORANGE});

// Define the layers array pointing to each individual layer
const rgblight_segment_t* const PROGMEM layer_rgb[] = {
  layer_rgb_0,
  layer_rgb_1,
  layer_rgb_2,
  layer_rgb_3,
  layer_rgb_4,
  layer_rgb_5
};

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = get_highest_layer(state);
  
  // Activate the RGB lighting for the current layer
  rgblight_set_layer_state(0, layer == _MAIN);
  rgblight_set_layer_state(1, layer == _ARROWS);
  // rgblight_set_layer_state(2, layer == _F_KEYS);
  rgblight_set_layer_state(3, layer == _NUMPAD);
  rgblight_set_layer_state(4, layer == _SYMBOLS);

  return state;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=false;
  debug_matrix=false;
  rgblight_layers = layer_rgb;
}

tap_dance_action_t tap_dance_actions[] = {
  [TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
};

// Keymaps 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT_5x6(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                   KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                   KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    ALT_F9,         LT1_A,          KC_S,           LT3_D,          LT4_F,          KC_G,                   KC_H,           KC_J,           KC_K,           KC_L,           LT3_CLN,        KC_QUOTE,       
    SFT_GRV,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                   KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLASH,       MAC_SS,   
                                    KC_NO,          KC_NO,                                                                                  KC_NO,          KC_NO, 
                                                                    KC_SPACE,       KC_LSFT,                KC_BSPC,        KC_ENTER,
                                                                    KC_NO,          KC_LGUI,                KC_LCTL,        KC_NO,
                                                                    KC_NO,          MISCTRL,                KC_NO,          KC_NO  
  ),
  [_ARROWS] = LAYOUT_5x6(
    _______,        _______,        _______,        _______,        QK_REBOOT,      QK_BOOT,                _______,        _______,        _______,        _______,        _______,        _______, 
    _______,        _______,        _______,        KC_ESC,        _______,        _______,                _______,        KC_HOME,        KC_UP,          KC_END,        _______,        _______, 
    _______,        _______,        KC_LCTL,        KC_LSFT,        KC_LALT,        KC_DEL,                 _______,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       _______,        _______, 
    _______,        _______,        _______,        _______,        _______,        _______,                _______,        _______,        _______,        _______,        _______,        _______, 
                                    _______,        _______,                                                                                _______,        _______, 
                                                                    _______,        _______,                _______,        _______,
                                                                    _______,        _______,                _______,        _______,
                                                                    _______,        _______,                _______,        _______  
  ),
  [_NUMPAD] = LAYOUT_5x6(
    _______,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                  KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         _______, 
    _______,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                KC_NUM,         KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_NO,          _______, 
    _______,        KC_CIRC,        KC_AMPR,        KC_ASTR,        _______,        _______,                KC_KP_0,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_NO,          _______, 
    _______,        _______,        _______,        _______,        _______,        _______,                KC_KP_DOT,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_NO,          _______,
                                    _______,        _______,                                                                                _______,        _______, 
                                                                    _______,        _______,                _______,        _______,
                                                                    _______,        _______,                _______,        _______,
                                                                    _______,        _______,                _______,        _______  
  ),
  [_SYMBOLS] = LAYOUT_5x6(
    _______,        _______,        _______,        _______,        _______,        _______,                _______,        _______,        _______,        _______,        _______,        _______,
    _______,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                KC_TILD,        KC_LCBR,        KC_RCBR,        _______,        _______,        _______,
    _______,        KC_CIRC,        KC_AMPR,        KC_ASTR,        _______,        _______,                KC_GRV,         KC_LPRN,        KC_RPRN,        KC_UNDS,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,                _______,        KC_LBRC,        KC_RBRC,        _______,        _______,        _______,
                                    _______,        _______,                                                                                _______,        _______, 
                                                                    _______,        _______,                _______,        _______,
                                                                    _______,        _______,                _______,        _______,
                                                                    _______,        _______,                _______,        _______  
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case WIN_SS:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_S))));
    }
    break;
    
    case MAC_SS:
    if (record->event.pressed) {
      tap_code16(C(S(KC_C)));  // Ctrl + Shift + C, Snagit
    }
    break;

    case MISCTRL:
    if (record->event.pressed) {
        tap_code16(C(KC_UP));
    }
    break;
    
    case FOCUS_D:
    if (record->event.pressed) {
      tap_code16(C(KC_F3));  // Control + F3 to focus Dock
    }
    break;
  }
  
  #ifdef CONSOLE_ENABLE
  dprintf("KL: kc: 0x%04X, row,col:[%2u, %2u]\n",
    keycode, record->event.key.row, record->event.key.col);
  #endif
    
  return true;  
}
  