/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H

enum layers {
    _HOME = 0,
    _SYMBOLS,
    _FUNCTION,
};


// Aliases for readability
#define HOME    DF(_HOME)
#define SYMBOLS DF(_SYMBOLS)
#define FKEYS   MO(_FUNCTION)

#define TILDE     LSFT(KC_GRV)

// Tap for esc, hold for Win key
#define WIN_ESC  MT(MOD_LGUI, KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: HOME
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  MUTE  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | Enter  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ` ~  | LAlt |  ESC | BkSp | LCtrl|  | Sym  | Space| DEL  | \ |  | PRNT |
 *                        |      |      | /WIN |      |      |  |      |      |      |      | SCRN |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_HOME] = LAYOUT(
     KC_TAB , KC_Q,  KC_W, KC_E ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_MUTE,
     KC_LSFT, KC_A,  KC_S, KC_D ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,  KC_ENT,
     KC_LCTL, KC_Z,  KC_X, KC_C ,   KC_V ,   KC_B ,  KC_NO,   KC_NO,        KC_NO, KC_NO,  KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                          KC_GRV, KC_LALT, WIN_ESC,KC_BSPC, KC_LCTL,        MO(1),KC_SPC,KC_DEL, KC_BSLS, KC_PSCR
    ),

/*
 * Base Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    ~   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |  MUTE  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LShift |   !  |   @  |   #  |   $  |   %  |                              |   ^  |   &  |   *  |   :  |   '  |   "    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCtrl  |  [   |   ]  |  (   |   )  |   +  |      |      |  |      |      |   =  |   {  |   }  |   <  |   >  |  ` ~   |
 * `----------------------+------+------+------+      +      |  |      +      +------+------+------+----------------------'
 *                        |FKEYS | LAlt | PRNT |  -   |  _   |  | Pass |   ←  |  ↓   |   ↑  |   →  |
 *                        |      |      | SCRN |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOLS] = LAYOUT(
     TILDE   ,   KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                                             KC_6,   KC_7,     KC_8,   KC_9,   KC_0,KC_MUTE,
     KC_LSFT ,KC_EXLM,  KC_AT,KC_HASH,  KC_DLR, KC_PERC,                                          KC_CIRC,KC_AMPR,  KC_ASTR,KC_COLN,KC_QUOT,KC_DQUO,
     KC_LCTL ,KC_LBRC,KC_RBRC,KC_LPRN, KC_RPRN, KC_PLUS,   KC_NO,   KC_NO,         KC_NO, KC_NO  , KC_EQL,KC_LCBR,  KC_RCBR,KC_LABK,KC_RABK, KC_GRV,
                                FKEYS, KC_LALT, KC_PSCR, KC_MINS, KC_UNDS,       KC_TRNS, KC_LEFT,KC_DOWN,  KC_UP, KC_RIGHT
    ),

/*
 * Function Layer: FKeys and LED Control
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   F1  |  F2  |  F3  |  F4  | F5  |                              |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |UGSPD+|UG nxt|HUE + |SAT + | BRI +|  F11   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |UGSPD-|UG prv|HUE - |SAT + | BRI -|  F12   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  | Light|  Und |      |      |      |
 *                        |      |      |      |      |      |  | TOGG |  Glo |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                    KC_F6 ,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                   UG_SPDU, UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, KC_F11,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,  KC_NO,UG_SPDD, UG_PREV, UG_HUED, UG_SATD, UG_VALD, KC_F12,
                         KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,     BL_TOGG,UG_TOGG,  KC_NO,   KC_NO,   KC_NO
    ),

};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

/* KEYBOARD PET START */

#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 40
#define LUNA_SIZE 96 // 96-byte arrays
#define LUNA_FRAMES 2
#define LUNA_FRAME_DURATION 200 // Number of ms per frame

uint32_t luna_anim_timer = 0;
uint32_t luna_anim_sleep = 0;
uint8_t luna_current_frame = 0;
static long int luna_oled_timeout = 50000;

static void render_luna_sit(void) {
    static const char PROGMEM sit[LUNA_FRAMES][3][LUNA_SIZE/3] = {
        {
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x1c,
            0x02,0x05,0x02,0x24,0x04,0x04,0x02,0xa9,0x1e,0xe0,0x00,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x10,0x08,0x68,0x10,0x08,0x04,0x03,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x02,0x06,0x82,0x7c,0x03,0x00,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x04,0x0c,0x10,0x10,0x20,0x20,0x20,0x28,
            0x3e,0x1c,0x20,0x20,0x3e,0x0f,0x11,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        },
        {
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x1c,
            0x02,0x05,0x02,0x24,0x04,0x04,0x02,0xa9,0x1e,0xe0,0x00,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0xe0,0x90,0x08,0x18,0x60,0x10,0x08,0x04,0x03,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x02,0x0e,0x82,0x7c,0x03,0x00,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x04,0x0c,0x10,0x10,0x20,0x20,0x20,0x28,
            0x3e,0x1c,0x20,0x20,0x3e,0x0f,0x11,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        }
    };
    oled_set_cursor(7,5);
    luna_current_frame = (luna_current_frame + 1) % LUNA_FRAMES;
    oled_write_raw_P(sit[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(7,6);
    oled_write_raw_P(sit[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(7,7);
    oled_write_raw_P(sit[abs(1 - luna_current_frame)][2], LUNA_SIZE/3);
}

static void render_luna_walk(void) {
    static const char PROGMEM walk[LUNA_FRAMES][3][LUNA_SIZE/3] = {
        {
            {0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x20,0x10,0x90,0x90,0x90,0xa0,0xc0,0x80,0x80,
            0x80,0x70,0x08,0x14,0x08,0x90,0x10,0x10,0x08,0xa4,0x78,0x80,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x07,0x08,0xfc,0x01,0x00,0x00,0x00,0x00,0x80,0x00,0x00,
            0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x18,0xea,0x10,0x0f,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1c,0x20,0x20,0x3c,0x0f,0x11,0x1f,0x03,
            0x06,0x18,0x20,0x20,0x3c,0x0c,0x12,0x1e,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        },
        {
            {0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x20,0x20,0x20,0x40,0x80,0x00,0x00,0x00,
            0x00,0xe0,0x10,0x28,0x10,0x20,0x20,0x20,0x10,0x48,0xf0,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x1f,0x20,0xf8,0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
            0x03,0x00,0x00,0x00,0x00,0x01,0x00,0x10,0x30,0xd5,0x20,0x1f,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x20,0x30,0x0c,0x02,0x05,0x09,0x12,0x1e,
            0x02,0x1c,0x14,0x08,0x10,0x20,0x2c,0x32,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        }
    };
    oled_set_cursor(7,5);
    luna_current_frame = (luna_current_frame + 1) % LUNA_FRAMES;
    oled_write_raw_P(walk[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(7,6);
    oled_write_raw_P(walk[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(7,7);
    oled_write_raw_P(walk[abs(1 - luna_current_frame)][2], LUNA_SIZE/3);
}

static void render_luna_run(void) {
    static const char PROGMEM run[LUNA_FRAMES][3][LUNA_SIZE/3] = {
        {
            {0x00,0x00,0x00,0x00,0xe0,0x10,0x08,0x08,0xc8,0xb0,0x80,0x80,0x80,0x80,0x80,0x80,
            0x80,0x40,0x40,0x3c,0x14,0x04,0x08,0x90,0x18,0x04,0x08,0xb0,0x40,0x80,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x01,0x02,0xc4,0xa4,0xfc,0x00,0x00,0x00,0x00,0x80,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc8,0x58,0x28,0x2a,0x10,0x0f,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x0e,0x09,0x04,0x04,0x04,0x04,0x02,0x03,0x02,0x01,0x01,
            0x02,0x02,0x04,0x08,0x10,0x26,0x2b,0x32,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x00}
        },
        {
            {0x00,0x00,0x00,0xe0,0x10,0x10,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
            0x80,0x80,0x78,0x28,0x08,0x10,0x20,0x30,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x03,0x04,0x08,0x10,0x11,0xf9,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x10,0xb0,0x50,0x55,0x20,0x1f,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x0c,0x10,0x20,0x28,0x37,
            0x02,0x1e,0x20,0x20,0x18,0x0c,0x14,0x1e,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        }
    };
    luna_current_frame = (luna_current_frame + 1) % LUNA_FRAMES;
    oled_set_cursor(7,5);
    oled_write_raw_P(run[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(7,6);
    oled_write_raw_P(run[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(7,7);
    oled_write_raw_P(run[abs(1 - luna_current_frame)][2], LUNA_SIZE/3);
}

static void render_luna_bark(void) {
    static const char PROGMEM bark[LUNA_FRAMES][3][LUNA_SIZE/3] = {
        {
            {0x00,0xc0,0x20,0x10,0xd0,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x40,
            0x3c,0x14,0x04,0x08,0x90,0x18,0x04,0x08,0xb0,0x40,0x80,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x03,0x04,0x08,0x10,0x11,0xf9,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x80,0xc8,0x48,0x28,0x2a,0x10,0x0f,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x0c,0x10,0x20,0x28,0x37,0x02,0x02,
            0x04,0x08,0x10,0x26,0x2b,0x32,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        },
        {
            {0x00,0xe0,0x10,0x10,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x40,
            0x40,0x2c,0x14,0x04,0x08,0x90,0x18,0x04,0x08,0xb0,0x40,0x80,0x00,0x00,0x00,0x00},
            {0x00,0x03,0x04,0x08,0x10,0x11,0xf9,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0x48,0x28,0x2a,0x10,0x0f,0x20,0x4a,0x09,0x10},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x0c,0x10,0x20,0x28,0x37,0x02,0x02,
            0x04,0x08,0x10,0x26,0x2b,0x32,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        }
    };
    luna_current_frame = (luna_current_frame + 1) % LUNA_FRAMES;
    oled_set_cursor(7,5);
    oled_write_raw_P(bark[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(7,6);
    oled_write_raw_P(bark[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(7,7);
    oled_write_raw_P(bark[abs(1 - luna_current_frame)][2], LUNA_SIZE/3);
}

/* status variables */
int   current_wpm = 0;
// led_t led_usb_state;

    /* animation */
void animate_luna(void) {

    void animation_phase(void) {
        if (get_mods() & (MOD_MASK_SHIFT)) { render_luna_bark(); }
        else if (get_current_wpm() <= MIN_WALK_SPEED) { render_luna_sit(); }
        else if (get_current_wpm() <= MIN_RUN_SPEED) { render_luna_walk(); }
        else { render_luna_run(); }
    }

    // Animate on WPM, turn off OLED on idle
    if (get_current_wpm() != 000 || host_keyboard_led_state().caps_lock || get_mods() & (MOD_MASK_CSAG)) {
        oled_on();
        if (timer_elapsed32(luna_anim_timer) >LUNA_FRAME_DURATION) {
            luna_anim_timer = timer_read32();
            animation_phase();
        }
        luna_anim_sleep = timer_read32();
    } else {
        if (timer_elapsed32(luna_anim_sleep) > luna_oled_timeout) {
            oled_off();
        } else {
            if (timer_elapsed32(luna_anim_timer) >LUNA_FRAME_DURATION) {
                luna_anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

bool oled_task_user(void) {
    current_wpm   = get_current_wpm();

    if (is_keyboard_master()) {
        // QMK Logo
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

        // clang-format on
        oled_write_P(qmk_logo, false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _HOME:
                oled_write_P(PSTR("Home\n"), false);
                break;
            case _SYMBOLS:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case _MAC:
                oled_write_P(PSTR("Mac\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            default:
                oled_write_P(PSTR("Uhhh\nSomething\nis wrong"), false);
        }

        // Keyboard LED Status to OLEDs keeping this here in case I want to display it later
        // led_t led_usb_state = host_keyboard_led_state();
        // oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        // oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        // oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
        animate_luna();
    } else {
        // clang-format off
        // The beast from over the garden wall
        static const char PROGMEM kyria_logo[] = {
      72, 77,  0,  0, 77,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 77, 76,  0, 64, 77,
       0,  0,  0,  0,  0,  0,  0,  0,  0, 77,128,128, 77, 76, 60,  3,  3,124,124, 62, 49, 49,
     207,207, 49, 79, 79,  0,  0, 77,  0,  0, 77, 76,  0, 72, 77,  0,  0, 77,  0,  0, 77, 72,
       0, 72, 77,  0,  0, 77,  0,  0, 77, 76,  0, 72, 77, 14, 14,113,238,206, 61, 61, 50,124,
     124,  3,  3, 61, 64, 64,192,192,  0, 64, 77,  0,  0, 77, 64,  0, 76, 76,  0,  0, 77,  0,
       0, 76, 72,  0,  0,  0,  0,  0,  0,  0,  0, 77, 72,  0, 72, 77,  0,  0, 54, 54,  0,  0,
      54,  8,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 54, 54,  8,  8,  6,  0,  0,  0,  0,
       0,  0,  0,  0,  0, 54, 15, 15, 56, 56,192,  0,  0, 48, 48,248,  6,  6, 55, 55,  8, 54,
      54,200,200,  6,248,248, 54, 34,  0, 34, 54,  8,  8, 54,  0,  0, 54, 54,  8, 38, 54,  0,
       0, 54,  8,  8,254,254,  6,206,206, 56, 56, 54,  1,  1, 54, 54,200, 48, 48,  0,  0,192,
      56, 56, 55, 39,  0, 32, 54,  8,  8, 54, 32,  0, 38, 54,  8,  8, 54,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0, 54, 34,  0, 34, 54,  8,  8,153,217, 96, 96,217,  6,  4,  0,
       0,  0,  0,  0,  0,  0,  0, 32, 32,153,153,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0, 32,
      32,153,  6,  6,153,137,  0,153,153,  6,  6,153, 97, 97,129,193,134,  1,  1,  1,  1,120,
     199,135,153,217, 96,153,217, 38,102,121, 96, 96,121,121, 38,123,121,224,224,217,198,134,
     159,159,120,  1,  1,  1,  3,135,131,129,225,225, 25, 30, 30,  3,  1,  0,  0,  0,  0,  0, 
      32,145,153,  6,  6,153,129,  0,153,153,  6,  6,153,  0,  0,  0,  0,  0,  0,  0,  0,  0,  
       0,  0,  0,153,153, 96,153,153,  6,  4,100,108, 16, 16,108,131,131,  0,  0,  0,  0,  0,  
       0,  0,  0, 16, 16,108,100,131, 64, 96,  0,  0,  0,  0,  0,  0,  0, 16, 24,108,131,131,
     108, 36, 16,108,100,131,131,108, 16, 16,108,100,131,103,111, 28, 28,112,240,240,  0,  0,  
       3,128,128,128,128,  0,  0,  0,  0,  0,  0,128,128,128,128,  3,  0,  0,240,240, 16,108,
     108,131,131,108, 16, 16,108,100,131,  0,  0,  0,  0,108,128,128,  0,  0,  0,  4, 12,131,
     131,108, 12, 16,108,100,131,131,108,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,108,
     100, 16,100,108,131,131,178,178, 12, 12,178, 65, 65,128,  0,  0,  0,  0,  0,  0,  0,  0, 
      12,178,178, 65, 32, 50,  0,  0,  0,  0,  0,  0,  0, 12, 12,178, 65, 65,178,178, 76,178,
     178, 65, 65,178, 12, 12,178,178, 65,178,178, 76, 76,178, 79, 79,240,240,128,  3,  3,  3,  
       3,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,128,112,112,191,191, 76,178,178, 65, 65,178, 
      12, 12,178,178, 65,179,178,  0,  0,  2,  1,  1,128,128,  0,  0,  0,  1,  1,178,146, 76,
     178,178, 65, 65,178,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,178, 18, 12, 18,178, 
      65, 65, 73,201, 54, 54,201, 48, 48,201,201,  0,  0,  0,  0,  0,  0,  0, 54,201,201, 48,  
       0,  0,  0,  0,  0,  0,  0,200,200, 54, 54,201, 48, 48,201,201, 54,201,201, 48, 48,201, 
      54, 54,201, 73, 48, 73,201, 54, 54,201, 48, 48,201,201, 55,248,248,  0,  0,  0,  0,  0,  
       0,  0,  0,  0,  0,248,248,207, 48, 48,201,201, 54,201,201, 48, 48,201, 54, 54,201,201, 
      48, 72,201,  0,  0,  0,  0,  0,201,201, 48,192,192,  0,  0,  1,  0,  6,  9,  9, 48, 48,
     201,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,201,201, 54,201,201, 48, 48, 36, 38,
     217,217, 38,216,216, 38, 36,  0,  0,  0,  0,  0,  0,137,217, 38, 36,216,  0,  0,  0,  0,  
       0,  0,  0, 38, 38,217,217, 38,216,216, 38,102,217, 38, 38,216,152, 38,217,217, 38, 36,
     216, 36, 38, 25, 25,  6,  6,  6,  6,  6,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  
       0,  0,  0,  1,  6,  6,  6,  6,  7, 14, 30, 56,120,230,217,217, 38, 36,216, 36, 38,  0,  
       0,  0,  0,  0, 38, 38,217,102, 38,216,152,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  
       0,  0,  0,  0,  0,  0,  0,  0,  0, 38, 38,217, 38, 38,216,216,155,155,100,100,155,228,
     228,155,147,  0,  0,  0,  0,  0,  0,  4,100,155,155,228, 64,  0,  0,  0,  0,  0,  0,147,
     155,100,100,155,228,228,155,155,100,155,155,100,100,155,236,236, 31, 31,  0,  0,  0,  0,  
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 31, 31,251,251,228,217,155,  0,  0,  0,  0,  0,
     147,155,100,155,155,228,228,155,176, 96,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  
       0,  0,  0,  0,  0,155,147,100,155,155,228,228
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLD);
    } else {
        tap_code(KC_VOLU);
    }
  return false;
}
#endif
