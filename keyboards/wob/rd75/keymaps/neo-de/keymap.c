/* Copyright 2023 Yiancar-Designs
 *
 * NEO 2.0 Keyboard Layout Implementation for RD75 - TEST VERSION
 * Simplified version with 4 layers only (0-3) for debugging
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
#include "../../../lib/rdr_lib/rdr_common.h"
#include "keymap_german.h"

// Custom keycodes for NEO layer switching only - no Unicode/dead keys
enum custom_keycodes {
    NEO_MOD3 = SAFE_RANGE,  // Mod3 key (Caps Lock position) - activates Layer 2
    NEO_FN                  // Fn key (right of spacebar) - activates Layer 3 (Function)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // NEO Ebene 1 (Base layer) - Layer 0 - Native German keycodes only
    [0] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_MUTE,
        DE_CIRC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DE_MINS, DE_GRV, KC_BSPC, KC_END,
        KC_TAB,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,     KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,     DE_SS, DE_ACUT, KC_BSLS, KC_PGUP,
        NEO_MOD3, KC_U,   KC_I,    KC_A,    KC_E,    KC_O,     KC_S,    KC_N,    KC_R,    KC_T,    KC_D,     DE_Y,     NEO_MOD3, KC_ENT,  KC_PGDN,
        KC_LSFT,          DE_UDIA, DE_ODIA, DE_ADIA, KC_P, DE_Z, KC_B, KC_M, KC_COMM, KC_DOT, KC_J, KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                              NEO_FN,   KC_RCTL,           KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    // NEO Ebene 2 (Shift layer) - Layer 1 - Native German keycodes only
    [1] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_MUTE,
        KC_NO, S(DE_CIRC), S(KC_3), KC_NO, KC_NO, KC_NO, S(KC_4), DE_EURO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_END,
        S(KC_TAB), S(KC_X), S(KC_V), S(KC_L), S(KC_C), S(KC_W), S(KC_K), S(KC_H), S(KC_G), S(KC_F), S(KC_Q), S(DE_SS), DE_TILD, KC_BSLS, KC_PGUP,
        KC_TRNS, S(KC_U), S(KC_I), S(KC_A), S(KC_E), S(KC_O), S(KC_S), S(KC_N), S(KC_R), S(KC_T), S(KC_D), S(DE_Y), KC_TRNS, KC_ENT, KC_PGDN,
        KC_LSFT,          S(DE_UDIA), S(DE_ODIA), S(DE_ADIA), S(KC_P), S(DE_Z), S(KC_B), S(KC_M), DE_MINS, KC_DOT, S(KC_J), KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                              NEO_FN,   KC_RCTL,           KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    // NEO Ebene 3 (Mod3 symbols) - Layer 2 - Native German keycodes only
    [2] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_MUTE,
        KC_NO, KC_NO, DE_SUP2, DE_SUP3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_END,
        KC_NO, KC_NO, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, DE_EXLM, DE_LABK, DE_RABK, DE_EQL, DE_AMPR, KC_NO, DE_SLSH, DE_BSLS, KC_PGUP,
        KC_TRNS, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT, KC_TRNS, KC_ENT, KC_PGDN,
        KC_LSFT,          DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_GRV, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                              NEO_FN,   KC_RCTL,            KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    // Layer 3: Function Layer (RGB, Wireless) - No Unicode modes needed
    // NEO_FN key activates this layer for RGB and wireless control
    [3] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_BRID, KC_BRIU, KC_WHOM, KC_MAIL, KC_CALC,  KC_MSEL, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_TOG, KC_HOME, KC_MUTE,
        KC_GRV,  MD_BLE1, MD_BLE2, MD_BLE3, MD_24G,  MD_USB,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     LOGO_VAD, LOGO_VAI, QK_BAT,  EE_CLR,
        KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     LOGO_SPD, LOGO_SPI, RGB_MOD, RGB_SAI,
        KC_CAPS, KC_NO,   KC_NO,   RGB_VAD, RGB_VAI, KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    LOGO_SAD, LOGO_SAI, RGB_MOD,  RGB_HUI, RGB_SAD,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    SIX_N,   KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  LOGO_HUI, RGB_VAI,
        TEST_CL, QK_WLO,  KC_LALT,                   LOGO_MOD,                            KC_TRNS, KC_RCTL,            RGB_SPD,  RGB_VAD, RGB_SPI
    )
};

// No Unicode map needed - using native German keyboard layout only

// No dead keys or Unicode - plug-and-play with native German keyboard layout only

// NEO modifier state tracking
static bool neo_mod3_pressed = false;
static bool neo_fn_pressed = false;
static bool neo_shift_pressed = false;

// Update NEO layers - 4 layer version (Mod3=symbols, Fn=function, Shift=layer1)
void update_neo_layers(void) {
    // Turn off all NEO layers first
    layer_off(1); // Layer 1 (Shift)
    layer_off(2); // Layer 2 (Mod3)
    layer_off(3); // Layer 3 (Function)
    
    // Activate appropriate layer (priority order: Mod3, Fn, Shift)
    if (neo_mod3_pressed) {
        layer_on(2); // Mod3 = Layer 2 (Symbols)
    } else if (neo_fn_pressed) {
        layer_on(3); // Fn = Layer 3 (Function/RGB)
    } else if (neo_shift_pressed) {
        layer_on(1); // Shift = Layer 1 (NEO Ebene 2)
    }
}

// Layer switching logic for NEO - simplified (no dead keys)
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NEO_MOD3:
            neo_mod3_pressed = record->event.pressed;
            update_neo_layers();
            return false;
            
        case NEO_FN:
            neo_fn_pressed = record->event.pressed;
            update_neo_layers();
            return false;
            
        case KC_LSFT:
        case KC_RSFT:
            neo_shift_pressed = record->event.pressed;
            update_neo_layers();
            return false; // DON'T let OS see shift - Layer 1 handles it
    }
    return true;
}