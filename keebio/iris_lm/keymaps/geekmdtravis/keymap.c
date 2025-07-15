// Copyright 2023 Danny Nguyen (@nooges)
// Adapted from ZSA Voyager keymap
// SPDX-License-Identifier: GPL-2.0-or-later

#include "wait.h"
#include "keycodes.h"
#include "modifiers.h"
#include QMK_KEYBOARD_H
enum custom_layers {
    _COLEMAK_DH,
    // _QWERTY,
    _SYMBOLS,
    _FUNCTIONS,
    _NUMPAD,
    _MOUSE,
    _LAYER_SELECT
};

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,
};

// Defines for tap dances
#define TD_ESC_LGUI TD(DANCE_2)
#define TD_BSPC_RALT TD(DANCE_5)
  
void keyboard_post_init_user(void) {
    eeconfig_init();
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────────┬─────────────────┬───┬───┬─────────────────┬────────────────┐                  ┌─────┬─────────────────┬───┬───┬─────────────────┬─────────────┐
//    │ TD(DANCE_0) │        1        │ 2 │ 3 │        4        │       5        │                  │  6  │        7        │ 8 │ 9 │        0        │ TD(DANCE_3) │
//    ├─────────────┼─────────────────┼───┼───┼─────────────────┼────────────────┤                  ├─────┼─────────────────┼───┼───┼─────────────────┼─────────────┤
//    │     tab     │        q        │ w │ f │        p        │       b        │                  │  j  │        l        │ u │ y │        ;        │     del     │
//    ├─────────────┼─────────────────┼───┼───┼─────────────────┼────────────────┤                  ├─────┼─────────────────┼───┼───┼─────────────────┼─────────────┤
//    │ MO(_MOUSE)  │ MT(MOD_LCTL, a) │ r │ s │ MT(MOD_LSFT, t) │ LT(_NUMPAD, g) │                  │  m  │ MT(MOD_RSFT, n) │ e │ i │ MT(MOD_RCTL, o) │      '      │
//    ├─────────────┼─────────────────┼───┼───┼─────────────────┼────────────────┼──────┬───────────┼─────┼─────────────────┼───┼───┼─────────────────┼─────────────┤
//    │ TD(DANCE_1) │ LT(_SYMBOLS, z) │ x │ c │        d        │       v        │ lalt │   ralt    │  k  │        h        │ , │ . │ LT(_SYMBOLS, /) │ TD(DANCE_4) │
//    └─────────────┴─────────────────┴───┴───┼─────────────────┼────────────────┼──────┼───────────┼─────┼─────────────────┼───┴───┴─────────────────┴─────────────┘
//                                            │      lgui       │      ent       │ esc  │ bACKSPACE │ spc │      rgui       │
//                                            └─────────────────┴────────────────┴──────┴───────────┴─────┴─────────────────┘
[_COLEMAK_DH] = LAYOUT(
  TD(DANCE_0) , KC_1               , KC_2 , KC_3 , KC_4               , KC_5              ,                          KC_6     , KC_7               , KC_8     , KC_9   , KC_0                   , TD(DANCE_3),
  KC_TAB      , KC_Q               , KC_W , KC_F , KC_P               , KC_B              ,                          KC_J     , KC_L               , KC_U     , KC_Y   , KC_SCLN                , KC_DEL     ,
  MO(_MOUSE)  , MT(MOD_LCTL, KC_A) , KC_R , KC_S , MT(MOD_LSFT, KC_T) , LT(_NUMPAD, KC_G) ,                          KC_M     , MT(MOD_RSFT, KC_N) , KC_E     , KC_I   , MT(MOD_RCTL, KC_O)     , KC_QUOTE   ,
  TD(DANCE_1) , LT(_SYMBOLS, KC_Z) , KC_X , KC_C , KC_D               , KC_V              , KC_LALT , KC_RALT      , KC_K     , KC_H               , KC_COMMA , KC_DOT , LT(_SYMBOLS, KC_SLASH) , TD(DANCE_4),
                                                   KC_LGUI            , KC_ENTER          , KC_ESC  , KC_BACKSPACE , KC_SPACE , KC_RGUI
),

//    ┌────┬─────┬────┬────┬─────┬─────┐           ┌─────┬─────┬────┬────┬─────┬────┐
//    │ no │ no  │ no │ no │ no  │ no  │           │ no  │ no  │ no │ no │ no  │ no │
//    ├────┼─────┼────┼────┼─────┼─────┤           ├─────┼─────┼────┼────┼─────┼────┤
//    │ no │ no  │ _  │ |  │  [  │  ]  │           │  {  │  }  │ +  │ -  │  :  │ no │
//    ├────┼─────┼────┼────┼─────┼─────┤           ├─────┼─────┼────┼────┼─────┼────┤
//    │ no │  !  │ @  │ #  │  $  │  %  │           │  ^  │  &  │ *  │ (  │  )  │ no │
//    ├────┼─────┼────┼────┼─────┼─────┼─────┬─────┼─────┼─────┼────┼────┼─────┼────┤
//    │ no │     │ ?  │ =  │  `  │  ~  │ no  │ no  │  \  │  /  │ <  │ >  │     │ no │
//    └────┴─────┴────┴────┼─────┼─────┼─────┼─────┼─────┼─────┼────┴────┴─────┴────┘
//                         │     │     │     │     │     │     │
//                         └─────┴─────┴─────┴─────┴─────┴─────┘
[_SYMBOLS] = LAYOUT(
  KC_NO , KC_NO   , KC_NO   , KC_NO    , KC_NO    , KC_NO   ,                     KC_NO   , KC_NO    , KC_NO   , KC_NO    , KC_NO   , KC_NO,
  KC_NO , KC_NO   , KC_UNDS , KC_PIPE  , KC_LBRC  , KC_RBRC ,                     KC_LCBR , KC_RCBR  , KC_PLUS , KC_MINUS , KC_COLN , KC_NO,
  KC_NO , KC_EXLM , KC_AT   , KC_HASH  , KC_DLR   , KC_PERC ,                     KC_CIRC , KC_AMPR  , KC_ASTR , KC_LPRN  , KC_RPRN , KC_NO,
  KC_NO , _______ , KC_QUES , KC_EQUAL , KC_GRAVE , KC_TILD , KC_NO   , KC_NO   , KC_BSLS , KC_SLASH , KC_LABK , KC_RABK  , _______ , KC_NO,
                                         _______  , _______ , _______ , _______ , _______ , _______
),

//    ┌─────┬────┬────┬────┬────┬────┐         ┌────┬─────┬─────┬─────┬─────┬────┐
//    │     │ no │ no │ no │ no │ no │         │ no │ f13 │ f14 │ f15 │ f16 │ no │
//    ├─────┼────┼────┼────┼────┼────┤         ├────┼─────┼─────┼─────┼─────┼────┤
//    │ no  │ no │ no │ no │ no │ no │         │ no │ f9  │ f10 │ f11 │ f12 │ no │
//    ├─────┼────┼────┼────┼────┼────┤         ├────┼─────┼─────┼─────┼─────┼────┤
//    │ no  │ no │ no │ no │ no │ no │         │ no │ f5  │ f6  │ f7  │ f8  │ no │
//    ├─────┼────┼────┼────┼────┼────┼────┬────┼────┼─────┼─────┼─────┼─────┼────┤
//    │ no  │ no │ no │ no │ no │ no │ no │ no │ f1 │ f2  │ f3  │ f4  │ no  │ no │
//    └─────┴────┴────┴────┼────┼────┼────┼────┼────┼─────┼─────┴─────┴─────┴────┘
//                         │ no │ no │ no │ no │ no │ no  │
//                         └────┴────┴────┴────┴────┴─────┘
[_FUNCTIONS] = LAYOUT(
  _______ , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                 KC_NO , KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_NO,
  KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                 KC_NO , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO,
  KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                 KC_NO , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_NO,
  KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_F1 , KC_F2  , KC_F3  , KC_F4  , KC_NO  , KC_NO,
                                    KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO
),

//    ┌─────┬────┬────┬────┬────┬─────┐         ┌──────┬────┬───┬───┬──────┬────────┐
//    │     │ no │ no │ no │ no │ no  │         │  no  │ (  │ ) │ [ │  ]   │  bspc  │
//    ├─────┼────┼────┼────┼────┼─────┤         ├──────┼────┼───┼───┼──────┼────────┤
//    │ no  │ no │ no │ no │ no │ no  │         │ kp_+ │ 7  │ 8 │ 9 │ kp_* │   no   │
//    ├─────┼────┼────┼────┼────┼─────┤         ├──────┼────┼───┼───┼──────┼────────┤
//    │ no  │ no │ no │ no │ no │     │         │ kp_- │ 4  │ 5 │ 6 │ kp_/ │   no   │
//    ├─────┼────┼────┼────┼────┼─────┼────┬────┼──────┼────┼───┼───┼──────┼────────┤
//    │ no  │ no │ no │ no │ no │ no  │ no │ no │  no  │ 1  │ 2 │ 3 │  no  │ kp_ent │
//    └─────┴────┴────┴────┼────┼─────┼────┼────┼──────┼────┼───┴───┴──────┴────────┘
//                         │ no │ no  │ no │ .  │  0   │ no │
//                         └────┴─────┴────┴────┴──────┴────┘
[_NUMPAD] = LAYOUT(
  _______ , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO   ,                  KC_NO       , KC_LPRN , KC_RPRN , KC_LBRC , KC_RBRC        , KC_BSPC    ,
  KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO   ,                  KC_KP_PLUS  , KC_7    , KC_8    , KC_9    , KC_KP_ASTERISK , KC_NO      ,
  KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , _______ ,                  KC_KP_MINUS , KC_4    , KC_5    , KC_6    , KC_KP_SLASH    , KC_NO      ,
  KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO   , KC_NO , KC_NO  , KC_NO       , KC_1    , KC_2    , KC_3    , KC_NO          , KC_KP_ENTER,
                                    KC_NO , KC_NO   , KC_NO , KC_DOT , KC_0        , KC_NO
),

//    ┌─────┬──────┬──────┬──────┬────┬────┐           ┌──────┬──────┬──────┬──────┬────┬────┐
//    │     │  no  │  no  │  no  │ no │ no │           │  no  │  no  │  no  │  no  │ no │ no │
//    ├─────┼──────┼──────┼──────┼────┼────┤           ├──────┼──────┼──────┼──────┼────┼────┤
//    │ no  │  no  │  up  │  no  │ no │ no │           │  no  │ wh_u │ ms_u │ wh_d │ no │ no │
//    ├─────┼──────┼──────┼──────┼────┼────┤           ├──────┼──────┼──────┼──────┼────┼────┤
//    │     │ left │ down │ rght │ no │ no │           │  no  │ ms_l │ ms_d │ ms_r │ no │ no │
//    ├─────┼──────┼──────┼──────┼────┼────┼────┬──────┼──────┼──────┼──────┼──────┼────┼────┤
//    │ no  │  no  │  no  │  no  │ no │ no │ no │  no  │  no  │  no  │ btn3 │  no  │ no │ no │
//    └─────┴──────┴──────┴──────┼────┼────┼────┼──────┼──────┼──────┼──────┴──────┴────┴────┘
//                               │ no │ no │ no │ btn2 │ btn1 │  no  │
//                               └────┴────┴────┴──────┴──────┴──────┘
[_MOUSE] = LAYOUT(
  _______ , KC_NO   , KC_NO   , KC_NO    , KC_NO , KC_NO ,                      KC_NO      , KC_NO       , KC_NO      , KC_NO         , KC_NO , KC_NO,
  KC_NO   , KC_NO   , KC_UP   , KC_NO    , KC_NO , KC_NO ,                      KC_NO      , KC_MS_WH_UP , KC_MS_UP   , KC_MS_WH_DOWN , KC_NO , KC_NO,
  _______ , KC_LEFT , KC_DOWN , KC_RIGHT , KC_NO , KC_NO ,                      KC_NO      , KC_MS_LEFT  , KC_MS_DOWN , KC_MS_RIGHT   , KC_NO , KC_NO,
  KC_NO   , KC_NO   , KC_NO   , KC_NO    , KC_NO , KC_NO , KC_NO , KC_NO      , KC_NO      , KC_NO       , KC_MS_BTN3 , KC_NO         , KC_NO , KC_NO,
                                           KC_NO , KC_NO , KC_NO , KC_MS_BTN2 , KC_MS_BTN1 , KC_NO
),

//    ┌─────┬────┬────┬─────┬────┬────┐         ┌────┬─────────────┬──────────────┬──────────────┬────┬────┐
//    │     │ no │ no │ no  │ no │ no │         │ no │     no      │      no      │      no      │ no │ no │
//    ├─────┼────┼────┼─────┼────┼────┤         ├────┼─────────────┼──────────────┼──────────────┼────┼────┤
//    │ no  │ no │ no │ no  │ no │ no │         │ no │ TD(DANCE_6) │ TD(DANCE_7)  │ TD(DANCE_8)  │ no │ no │
//    ├─────┼────┼────┼─────┼────┼────┤         ├────┼─────────────┼──────────────┼──────────────┼────┼────┤
//    │ no  │ no │ no │ no  │ no │ no │         │ no │ TD(DANCE_9) │ TD(DANCE_10) │ TD(DANCE_11) │ no │ no │
//    ├─────┼────┼────┼─────┼────┼────┼────┬────┼────┼─────────────┼──────────────┼──────────────┼────┼────┤
//    │ no  │ no │ no │     │ no │ no │ no │ no │ no │     no      │              │      no      │ no │ no │
//    └─────┴────┴────┴─────┼────┼────┼────┼────┼────┼─────────────┼──────────────┴──────────────┴────┴────┘
//                          │ no │ no │ no │ no │ no │     no      │
//                          └────┴────┴────┴────┴────┴─────────────┘
[_LAYER_SELECT] = LAYOUT(
  _______ , KC_NO , KC_NO , KC_NO   , KC_NO , KC_NO ,                 KC_NO , KC_NO       , KC_NO        , KC_NO        , KC_NO , KC_NO,
  KC_NO   , KC_NO , KC_NO , KC_NO   , KC_NO , KC_NO ,                 KC_NO , TD(DANCE_6) , TD(DANCE_7)  , TD(DANCE_8)  , KC_NO , KC_NO,
  KC_NO   , KC_NO , KC_NO , KC_NO   , KC_NO , KC_NO ,                 KC_NO , TD(DANCE_9) , TD(DANCE_10) , TD(DANCE_11) , KC_NO , KC_NO,
  KC_NO   , KC_NO , KC_NO , _______ , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO       , _______      , KC_NO        , KC_NO , KC_NO,
                                      KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO
)
};

const uint16_t PROGMEM combo0[] = { MT(MOD_LCTL, KC_A), KC_R, KC_S, MT(MOD_LSFT, KC_T), COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_S, KC_D, MT(MOD_LSFT, KC_F), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, CW_TOGG),
    COMBO(combo1, CW_TOGG),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TAB:
            return TAPPING_TERM + 50;
        case MT(MOD_LCTL, KC_A):
            return TAPPING_TERM + 50;
        case LT(_SYMBOLS, KC_Z):
            return TAPPING_TERM + 50;
        case TD_ESC_LGUI:
            return TAPPING_TERM + 50;
        case MT(MOD_RCTL, KC_O):
            return TAPPING_TERM + 50;
        case LT(_SYMBOLS, KC_SLASH):
            return TAPPING_TERM + 50;
        case TD_BSPC_RALT:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

// Layer color function
layer_state_t layer_state_set_user(layer_state_t state) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    switch (get_highest_layer(state)) {
        case _COLEMAK_DH:
            rgb_matrix_sethsv(HSV_PURPLE);
            break;
        /*case _QWERTY:
            rgb_matrix_sethsv(HSV_CYAN);
            break;*/
        case _SYMBOLS:
            rgb_matrix_sethsv(HSV_RED);
            break;
        case _FUNCTIONS:
            rgb_matrix_sethsv(HSV_ORANGE);
            break;
        case _NUMPAD:
            rgb_matrix_sethsv(HSV_GREEN);
            break;
        case _MOUSE:
            rgb_matrix_sethsv(HSV_YELLOW);
            break;
        case _LAYER_SELECT:
            rgb_matrix_sethsv(HSV_WHITE);
            break;
    }
    return state;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[12];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_HOLD: layer_on(_LAYER_SELECT); break
        case DOUBLE_HOLD: layer_on(_FUNCTIONS); break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_HOLD:
          layer_off(_LAYER_SELECT);
        break;
              case DOUBLE_HOLD:
                layer_off(_FUNCTIONS);
                break;
    }
    dance_state[0].step = 0;
}
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_HOLD: register_code16(KC_F14); break;
        case DOUBLE_HOLD: register_code16(KC_F15); break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_HOLD: unregister_code16(KC_F14); break;
        case DOUBLE_HOLD: unregister_code16(KC_F15); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: register_code16(KC_DELETE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[2].step = 0;
}
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_4))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_3))); break;
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_4))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_3))); break;
    }
    dance_state[3].step = 0;
}
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_HOLD: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_HOLD: register_code16(KC_AUDIO_VOL_UP); break;
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_HOLD: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_HOLD: unregister_code16(KC_AUDIO_VOL_UP); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
    }
    if(state->count > 3) {
        tap_code16(KC_BSPC);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_BSPC); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: tap_code16(KC_BSPC); register_code16(KC_BSPC); break;
        case DOUBLE_HOLD: register_code16(KC_BSPC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPC); register_code16(KC_BSPC);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_BSPC); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: unregister_code16(KC_BSPC); break;
        case DOUBLE_HOLD: unregister_code16(KC_BSPC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPC); break;
    }
    dance_state[5].step = 0;
}
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case DOUBLE_HOLD: layer_move(_FUNCTIONS); break;
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state[6].step = 0;
}
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case DOUBLE_HOLD: layer_move(_NUMPAD); break;
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state[7].step = 0;
}
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case DOUBLE_HOLD: layer_move(_MOUSE); break;
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state[8].step = 0;
}
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case DOUBLE_HOLD: layer_move(_COLEMAK_DH); break;
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state[9].step = 0;
}
/*void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case DOUBLE_HOLD: layer_move(_QWERTY); break;
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state[10].step = 0;
}*/
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case DOUBLE_HOLD: layer_move(_SYMBOLS); break;
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state[11].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_9_finished, dance_9_reset),
        // [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_11_finished, dance_11_reset),
};
