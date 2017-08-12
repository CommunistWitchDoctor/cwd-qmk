#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"

#define BASE 0 // default layer
#define NAV 1 // nav keys
#define NUM 2 // numpad keys


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = KEYMAP(KC_MINUS,KC_1,KC_2,KC_3,KC_4,KC_5,KC_LEAD,KC_TAB,KC_Q,KC_W,KC_F,KC_P,KC_G,MO(2),KC_ESCAPE,KC_A,KC_R,KC_S,KC_T,KC_D,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_LEFT,KC_GRAVE,KC_BSLASH,KC_LALT,KC_LGUI,CTL_T(KC_NO),KC_UP,KC_HOME,KC_END,KC_SPACE,KC_ENTER,MO(1),KC_MINUS,KC_6,KC_7,KC_8,KC_9,KC_0,KC_EQUAL,KC_LBRACKET,KC_J,KC_L,KC_U,KC_Y,KC_SCOLON,KC_RBRACKET,KC_H,KC_N,KC_E,KC_I,KC_O,KC_QUOTE,KC_RIGHT,KC_K,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,KC_RCTRL,KC_LGUI,KC_RALT,KC_APPLICATION,TO(1),KC_PGUP,KC_DOWN,KC_PGDOWN,MO(1),KC_DELETE,KC_BSPACE),

  [1] = KEYMAP(KC_TRANSPARENT,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F11,KC_CAPSLOCK,KC_TRANSPARENT,KC_HOME,KC_UP,KC_PGUP,KC_TRANSPARENT,TG(2),KC_INSERT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_END,KC_TRANSPARENT,KC_PGDOWN,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,KC_BSPACE,KC_DELETE,KC_TRANSPARENT,KC_F12,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_TRANSPARENT,TG(2),KC_DOWN,KC_RIGHT,KC_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,TO(0),KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_ENTER,KC_SPACE),

  [2] = KEYMAP(RESET,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,KC_ENTER,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NUMLOCK,KC_KP_SLASH,KC_KP_ASTERISK,KC_KP_MINUS,RESET,KC_TRANSPARENT,KC_TRANSPARENT,KC_KP_7,KC_KP_8,KC_KP_9,KC_KP_PLUS,KC_TRANSPARENT,KC_TRANSPARENT,KC_KP_4,KC_KP_5,KC_KP_6,KC_KP_PLUS,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_KP_1,KC_KP_2,KC_KP_3,KC_KP_ENTER,KC_TRANSPARENT,KC_KP_0,KC_KP_0,KC_KP_DOT,KC_KP_ENTER,TO(0),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_DELETE,KC_BSPACE),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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
    
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
            
            LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_FOUR_KEYS(KC_N, KC_A, KC_V, KC_Y) {
      SEND_STRING("What the fuck did you just fucking say about me, you little bitch?");
    }
  }
            
            
            
    }

};
