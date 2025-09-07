/* Copyright 2023 Yiancar-Designs
 *
 * NEO 2.0 Keyboard Layout Implementation for RD75
 * Based on official NEO specification from neo-layout.org
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
// Hardware-level NEO implementation - no language-specific headers needed
// All characters are sent directly, compatible with US keyboard layout on any OS

// Custom keycodes for NEO layer switching and dead keys
enum custom_keycodes {
    NEO_MOD3 = SAFE_RANGE,  // Mod3 key (Caps Lock position)
    NEO_MOD4,               // Mod4 key (Right Alt position)
    NEO_FN,                 // Function key for Layer 6 access
    
    // NEO Dead Keys - Phase 1 (Essential diacritics)
    NEO_DEAD_CIRCUMFLEX,    // T1 Layer 1: ˆ (â ê î ô û)
    NEO_DEAD_GRAVE,         // T2 Layer 1: ` (à è ì ò ù)
    NEO_DEAD_ACUTE,         // T3 Layer 1: ´ (á é í ó ú)
    NEO_DEAD_DIAERESIS,     // T2 Layer 4: ¨ (ä ë ï ö ü ÿ)
    NEO_DEAD_TILDE,         // T3 Layer 2: ˜ (ã ñ õ)
    
    // NEO Dead Keys - Phase 2 (Extended diacritics)
    NEO_DEAD_CARON,         // T1 Layer 2: ˇ (č š ž ň ř)
    NEO_DEAD_CEDILLA,       // T2 Layer 2: ¸ (ç ş ţ)
    NEO_DEAD_MACRON,        // T2 Layer 6: ¯ (ā ē ī ō ū)
    NEO_DEAD_BREVE,         // T3 Layer 6: ˘ (ă ĕ ğ ĭ ŏ ŭ)
    
    // Polish Language Enhancement - Phase 3
    NEO_DEAD_OGONEK,        // T1 Layer 3: ˛ (ą ę)
    NEO_DEAD_RING_ABOVE,    // T2 Layer 3: ˚ (å ů)
    NEO_DEAD_STROKE         // T3 Layer 3: / (ł đ ħ ŧ)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // NEO Ebene 1 (Base layer) - Layer 0 - HARDWARE LEVEL IMPLEMENTATION
    // Sends actual characters directly - works on any OS with US keyboard layout
    // Official layout: ˆ 1 2 3 4 5 6 7 8 9 0 - `
    //                  x v l c w k h g f q ß ´
    //                  u i a e o s n r t d y
    //                  ü ö ä p z b m , . j
    [0] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_MUTE,
        NEO_DEAD_CIRCUMFLEX, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, NEO_DEAD_GRAVE, KC_GRV, KC_BSPC, KC_END,
        KC_TAB,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,     KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,     UC(0x00DF), NEO_DEAD_ACUTE, KC_BSLS, KC_PGUP,
        NEO_MOD3, KC_U,   KC_I,    KC_A,    KC_E,    KC_O,     KC_S,    KC_N,    KC_R,    KC_T,    KC_D,     KC_Y,     NEO_MOD3, KC_ENT,  KC_PGDN,
        KC_LSFT,          UC(0x00FC), UC(0x00F6), UC(0x00E4), KC_P, KC_Z, KC_B, KC_M, KC_COMM, KC_DOT, KC_J, KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                              NEO_FN,   NEO_MOD4,           KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    // NEO Ebene 2 (Shift layer) - Layer 1 - HARDWARE LEVEL IMPLEMENTATION
    // Official layout: ˇ ° § ℓ » « $ € „ " " — ¸
    //                  X V L C W K H G F Q ẞ ˜
    //                  U I A E O S N R T D Y
    //                  Ü Ö Ä P Z B M – • J
    [1] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_MUTE,
        NEO_DEAD_CARON, UC(0x00B0), UC(0x00A7), UC(0x2113), UC(0x00BB), UC(0x00AB), KC_DLR, UC(0x20AC), UC(0x201E), UC(0x201C), UC(0x201D), NEO_DEAD_CEDILLA, UC(0x00B8), KC_BSPC, KC_END,
        S(KC_TAB), S(KC_X), S(KC_V), S(KC_L), S(KC_C), S(KC_W), S(KC_K), S(KC_H), S(KC_G), S(KC_F), S(KC_Q), UC(0x1E9E), NEO_DEAD_TILDE, KC_BSLS, KC_PGUP,
        KC_TRNS, S(KC_U), S(KC_I), S(KC_A), S(KC_E), S(KC_O), S(KC_S), S(KC_N), S(KC_R), S(KC_T), S(KC_D), S(KC_Y), KC_TRNS, KC_ENT, KC_PGDN,
        KC_LSFT,          UC(0x00DC), UC(0x00D6), UC(0x00C4), S(KC_P), S(KC_Z), S(KC_B), S(KC_M), UC(0x2013), UC(0x2022), S(KC_J), KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                              KC_TRNS, KC_RCTL,           KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    // NEO Ebene 3 (Mod3 symbols) - Layer 2 - HYBRID APPROACH + POLISH ENHANCEMENT ✅ COMPLETE
    // Unicode for decorative symbols (¹²³›‹¢¥‚''♫ſ), ASCII for functional symbols (<>!@#$%^&*()etc)
    // Polish Enhancement: ˛ ¹ ² ³ › ‹ ¢ ¥ ‚ ' ' (space) ˚ /  →  Ogonek + Ring Above + Stroke dead keys ✅
    // Row 1: ˛ ¹ ² ³ › ‹ ¢ ¥ ‚ ' ' (space) ˚ /  →  Polish dead keys + Unicode decorative + ASCII functional ✅
    // Row 2: ♫ … _ [ ] ^ ! < > = & ſ /           →  Unicode compose/ellipsis/long-s + ASCII symbols ✅
    // Row 3: \ / { } * ? ( ) - : @             →  All ASCII (functional symbols) ✅
    // Row 4: # $ | ~ ` + % " ' ;               →  All ASCII (functional symbols) ✅
    [2] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_MUTE,
        NEO_DEAD_OGONEK, UC(0x00B9), UC(0x00B2), UC(0x00B3), UC(0x203A), UC(0x2039), UC(0x00A2), UC(0x00A5), UC(0x201A), UC(0x2018), UC(0x2019), KC_SPC, NEO_DEAD_RING_ABOVE, KC_BSPC, KC_END,
        UC(0x266B), UC(0x2026), KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, KC_EXLM, KC_LABK, KC_RABK, KC_EQL, KC_AMPR, UC(0x017F), NEO_DEAD_STROKE, KC_BSLS, KC_PGUP,
        KC_TRNS, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR, KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN, KC_AT, KC_TRNS, KC_ENT, KC_PGDN,
        KC_LSFT,          KC_HASH, KC_DLR, KC_PIPE, KC_TILD, KC_GRV, KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN, KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                              KC_TRNS, KC_RCTL,            KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    // NEO Ebene 4 (Mod4 navigation/numbers) - Layer 3 - HYBRID APPROACH ✅ COMPLETE
    // Unicode for decorative symbols, ASCII for functional navigation/numbers
    // Row 1: ˙ ª º № (space) · £ ¤ ⇥ / * - ¨  →  Unicode decorative + ASCII math/tab ✅
    // Row 2: ⇞ ⌫ ⇡ ⌦ ⇟ ¡ 7 8 9 + − ˝        →  Navigation functions + Unicode symbols ✅
    // Row 3: ⇱ ⇠ ⇣ ⇢ ⇲ ¿ 4 5 6 , .          →  Navigation functions + Unicode ¿ ✅
    // Row 4: ⌧ ⇥ ⎀ ⏎ ↶ : 1 2 3 ;            →  Navigation functions + ASCII numbers ✅
    [3] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_MUTE,
        KC_TRNS, UC(0x02D9), UC(0x00AA), UC(0x00BA), KC_SPC, UC(0x00B7), UC(0x00A3), UC(0x00A4), KC_TAB, KC_SLSH, KC_ASTR, KC_MINS, NEO_DEAD_DIAERESIS, KC_BSPC, KC_END,
        KC_TRNS, KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN, UC(0x00A1), KC_7, KC_8, KC_9, KC_PLUS, UC(0x2212), UC(0x02DD), KC_BSLS, KC_PGUP,
        KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, UC(0x00BF), KC_4, KC_5, KC_6, KC_COMM, KC_DOT, KC_TRNS, KC_ENT, KC_PGDN,
        KC_LSFT,          KC_ESC, KC_TAB, KC_INS, KC_ENT, KC_UNDO, KC_COLN, KC_1, KC_2, KC_3, KC_SCLN, KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_0,                                KC_TRNS, KC_RCTL,            KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    // NEO Ebene 5 (Mod3+Shift Greek letters) - Layer 4 - HYBRID APPROACH
    // Unicode for Greek letters/math symbols, ASCII for functional symbols
    // Row 1: ˞ ₁ ₂ ₃ ♀ ♂ ⚥ ϰ ⟨ ⟩ ₀ ‑ ῾  →  Unicode decorative + ASCII angle brackets
    // Row 2: ξ (space) λ χ ω κ ψ γ φ ϕ ς ᾿  →  Unicode Greek letters
    // Row 3: (space) ι α ε ο σ ν ρ τ δ υ    →  Unicode Greek letters
    // Row 4: (space) ϵ η π ζ β μ ϱ ϑ θ      →  Unicode Greek letters
    [4] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_MUTE,
        KC_TRNS, UC(0x2081), UC(0x2082), UC(0x2083), UC(0x2640), UC(0x2642), UC(0x26A5), UC(0x03F0), KC_LABK, KC_RABK, UC(0x2080), UC(0x2011), UC(0x1FFE), KC_BSPC, KC_END,
        KC_TRNS, UC(0x03BE), KC_SPC, UC(0x03BB), UC(0x03C7), UC(0x03C9), UC(0x03BA), UC(0x03C8), UC(0x03B3), UC(0x03C6), UC(0x03D5), UC(0x03C2), UC(0x1FBF), KC_BSLS, KC_PGUP,
        KC_TRNS, KC_SPC, UC(0x03B9), UC(0x03B1), UC(0x03B5), UC(0x03BF), UC(0x03C3), UC(0x03BD), UC(0x03C1), UC(0x03C4), UC(0x03B4), UC(0x03C5), KC_TRNS, KC_ENT, KC_PGDN,
        KC_LSFT,          KC_SPC, UC(0x03F5), UC(0x03B7), UC(0x03C0), UC(0x03B6), UC(0x03B2), UC(0x03BC), UC(0x03F1), UC(0x03D1), UC(0x03B8), KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                              KC_TRNS, KC_RCTL,            KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    // NEO Ebene 6 (Mod3+Mod4 math symbols) - Layer 5 - HYBRID APPROACH
    // Unicode for mathematical symbols, ASCII for basic punctuation
    // Row 1: . ¬ ∨ ∧ ⊥ ∡ ∥ → ∞ ∝ ∅ ╌ ¯  →  ASCII dot + Unicode math symbols
    // Row 2: Ξ √ Λ ℂ Ω × Ψ Γ Φ ℚ ∘ ˘    →  Unicode Greek capitals + math symbols
    // Row 3: ⊂ ∫ ∀ ∃ ∈ Σ ℕ ℝ ∂ Δ ∇    →  Unicode mathematical symbols
    // Row 4: ∪ ∩ ℵ Π ℤ ⇐ ⇔ ⇒ ↦ Θ      →  Unicode set theory + logic symbols
    [5] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_MUTE,
        KC_DOT,  UC(0x00AC), UC(0x2228), UC(0x2227), UC(0x22A5), UC(0x2221), UC(0x2225), UC(0x2192), UC(0x221E), UC(0x221D), UC(0x2205), UC(0x254C), NEO_DEAD_MACRON, KC_BSPC, KC_END,
        KC_TRNS, UC(0x039E), UC(0x221A), UC(0x039B), UC(0x2102), UC(0x03A9), UC(0x00D7), UC(0x03A8), UC(0x0393), UC(0x03A6), UC(0x211A), UC(0x2218), NEO_DEAD_BREVE, KC_BSLS, KC_PGUP,
        KC_TRNS, UC(0x2282), UC(0x222B), UC(0x2200), UC(0x2203), UC(0x2208), UC(0x03A3), UC(0x2115), UC(0x211D), UC(0x2202), UC(0x0394), UC(0x2207), KC_TRNS, KC_ENT, KC_PGDN,
        KC_LSFT,          UC(0x222A), UC(0x2229), UC(0x2135), UC(0x03A0), UC(0x2124), UC(0x21D0), UC(0x21D4), UC(0x21D2), UC(0x21A6), UC(0x0398), KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                              KC_TRNS, KC_RCTL,            KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    // NEO Function Layer (Complete RD75 Features + Unicode Control) - Layer 6
    // HYBRID DESIGN: All original RD75 functionality + Unicode mode switching
    // F-Row: Complete multimedia keys (Web Home, Mail, Calculator, Media Select)
    // Numbers: Full wireless switching (BLE1, BLE2, BLE3, 2.4G, USB)
    // QWERTY: Unicode mode switching (Q=Windows, W=Mac, E=Linux)
    // ASDF: Layer switching + RGB controls
    // All RGB, Logo, Battery, and system controls preserved
    [6] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_BRID, KC_BRIU, KC_WHOM, KC_MAIL, KC_CALC,  KC_MSEL, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_TOG, KC_HOME, KC_MUTE,
        KC_GRV,  MD_BLE1, MD_BLE2, MD_BLE3, MD_24G,  MD_USB,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     LOGO_VAD, LOGO_VAI, QK_BAT,  EE_CLR,
        KC_TAB,  UC_WIN,  UC_MAC,  UC_LINX, KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     LOGO_SPD, LOGO_SPI, RGB_MOD, RGB_SAI,
        KC_CAPS, TO(0),   TO(1),   RGB_VAD, RGB_VAI, KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    LOGO_SAD, LOGO_SAI, RGB_MOD,  RGB_HUI, RGB_SAD,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    SIX_N,   KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  LOGO_HUI, RGB_VAI,
        TEST_CL, QK_WLO,  KC_LALT,                   LOGO_MOD,                            KC_TRNS, KC_TRNS,            RGB_SPD,  RGB_VAD, RGB_SPI
    )
};

// Enhanced dead key state management - fixes race conditions and lifecycle issues
typedef struct {
    uint16_t keycode;           // Which dead key is active (0 = none)
    bool shift_state;           // Shift state when dead key was pressed
    uint8_t layer_when_pressed; // Layer when dead key was pressed
} dead_key_state_t;

static dead_key_state_t dead_key_state = {0, false, 0};

// Clear dead key state - centralized cleanup
void clear_dead_key_state(void) {
    dead_key_state.keycode = 0;
    dead_key_state.shift_state = false;
    dead_key_state.layer_when_pressed = 0;
}

// Activate dead key - capture complete context
void activate_dead_key(uint16_t keycode) {
    dead_key_state.keycode = keycode;
    dead_key_state.shift_state = get_mods() & MOD_MASK_SHIFT;
    dead_key_state.layer_when_pressed = get_highest_layer(layer_state);
}

// Check if dead key is active
bool is_dead_key_active(void) {
    return dead_key_state.keycode != 0;
}

// Dead key processing - Complete implementation with race condition protection
void send_dead_key_combination(uint16_t dead_key, uint16_t base_key) {
    // Use cached shift state from when dead key was pressed - prevents race conditions
    bool is_uppercase = dead_key_state.shift_state;
    
    switch (dead_key) {
        case NEO_DEAD_CIRCUMFLEX:
            switch (base_key) {
                case KC_A: send_unicode_string(is_uppercase ? "Â" : "â"); break;
                case KC_E: send_unicode_string(is_uppercase ? "Ê" : "ê"); break;
                case KC_I: send_unicode_string(is_uppercase ? "Î" : "î"); break;
                case KC_O: send_unicode_string(is_uppercase ? "Ô" : "ô"); break;
                case KC_U: send_unicode_string(is_uppercase ? "Û" : "û"); break;
                case KC_SPC: send_unicode_string("ˆ"); break; // Show dead key itself
                default:
                    send_unicode_string("ˆ");
                    tap_code(base_key);
                    break;
            }
            break;
            
        case NEO_DEAD_ACUTE:
            switch (base_key) {
                case KC_A: send_unicode_string(is_uppercase ? "Á" : "á"); break;
                case KC_E: send_unicode_string(is_uppercase ? "É" : "é"); break;
                case KC_I: send_unicode_string(is_uppercase ? "Í" : "í"); break;
                case KC_O: send_unicode_string(is_uppercase ? "Ó" : "ó"); break;
                case KC_U: send_unicode_string(is_uppercase ? "Ú" : "ú"); break;
                case KC_Y: send_unicode_string(is_uppercase ? "Ý" : "ý"); break;
                case KC_C: send_unicode_string(is_uppercase ? "Ć" : "ć"); break;
                case KC_N: send_unicode_string(is_uppercase ? "Ń" : "ń"); break;
                case KC_S: send_unicode_string(is_uppercase ? "Ś" : "ś"); break;
                case KC_Z: send_unicode_string(is_uppercase ? "Ź" : "ź"); break;
                case KC_SPC: send_unicode_string("´"); break;
                default:
                    send_unicode_string("´");
                    tap_code(base_key);
                    break;
            }
            break;
            
        case NEO_DEAD_GRAVE:
            switch (base_key) {
                case KC_A: send_unicode_string(is_uppercase ? "À" : "à"); break;
                case KC_E: send_unicode_string(is_uppercase ? "È" : "è"); break;
                case KC_I: send_unicode_string(is_uppercase ? "Ì" : "ì"); break;
                case KC_O: send_unicode_string(is_uppercase ? "Ò" : "ò"); break;
                case KC_U: send_unicode_string(is_uppercase ? "Ù" : "ù"); break;
                case KC_SPC: send_unicode_string("`"); break;
                default:
                    send_unicode_string("`");
                    tap_code(base_key);
                    break;
            }
            break;
            
        case NEO_DEAD_DIAERESIS:
            switch (base_key) {
                case KC_A: send_unicode_string(is_uppercase ? "Ä" : "ä"); break;
                case KC_E: send_unicode_string(is_uppercase ? "Ë" : "ë"); break;
                case KC_I: send_unicode_string(is_uppercase ? "Ï" : "ï"); break;
                case KC_O: send_unicode_string(is_uppercase ? "Ö" : "ö"); break;
                case KC_U: send_unicode_string(is_uppercase ? "Ü" : "ü"); break;
                case KC_Y: send_unicode_string(is_uppercase ? "Ÿ" : "ÿ"); break;
                case KC_SPC: send_unicode_string("¨"); break;
                default:
                    send_unicode_string("¨");
                    tap_code(base_key);
                    break;
            }
            break;
            
        case NEO_DEAD_TILDE:
            switch (base_key) {
                case KC_A: send_unicode_string(is_uppercase ? "Ã" : "ã"); break;
                case KC_N: send_unicode_string(is_uppercase ? "Ñ" : "ñ"); break;
                case KC_O: send_unicode_string(is_uppercase ? "Õ" : "õ"); break;
                case KC_SPC: send_unicode_string("˜"); break;
                default:
                    send_unicode_string("˜");
                    tap_code(base_key);
                    break;
            }
            break;
            
        case NEO_DEAD_CARON:
            switch (base_key) {
                case KC_C: send_unicode_string(is_uppercase ? "Č" : "č"); break;
                case KC_S: send_unicode_string(is_uppercase ? "Š" : "š"); break;
                case KC_Z: send_unicode_string(is_uppercase ? "Ž" : "ž"); break;
                case KC_N: send_unicode_string(is_uppercase ? "Ň" : "ň"); break;
                case KC_R: send_unicode_string(is_uppercase ? "Ř" : "ř"); break;
                case KC_D: send_unicode_string(is_uppercase ? "Ď" : "ď"); break;
                case KC_T: send_unicode_string(is_uppercase ? "Ť" : "ť"); break;
                case KC_L: send_unicode_string(is_uppercase ? "Ľ" : "ľ"); break;
                case KC_E: send_unicode_string(is_uppercase ? "Ě" : "ě"); break;
                case KC_SPC: send_unicode_string("ˇ"); break;
                default:
                    send_unicode_string("ˇ");
                    tap_code(base_key);
                    break;
            }
            break;
            
        case NEO_DEAD_CEDILLA:
            switch (base_key) {
                case KC_C: send_unicode_string(is_uppercase ? "Ç" : "ç"); break;
                case KC_S: send_unicode_string(is_uppercase ? "Ş" : "ş"); break;
                case KC_T: send_unicode_string(is_uppercase ? "Ţ" : "ţ"); break;
                case KC_G: send_unicode_string(is_uppercase ? "Ģ" : "ģ"); break;
                case KC_K: send_unicode_string(is_uppercase ? "Ķ" : "ķ"); break;
                case KC_L: send_unicode_string(is_uppercase ? "Ļ" : "ļ"); break;
                case KC_N: send_unicode_string(is_uppercase ? "Ņ" : "ņ"); break;
                case KC_R: send_unicode_string(is_uppercase ? "Ŗ" : "ŗ"); break;
                case KC_SPC: send_unicode_string("¸"); break;
                default:
                    send_unicode_string("¸");
                    tap_code(base_key);
                    break;
            }
            break;
            
        case NEO_DEAD_MACRON:
            switch (base_key) {
                case KC_A: send_unicode_string(is_uppercase ? "Ā" : "ā"); break;
                case KC_E: send_unicode_string(is_uppercase ? "Ē" : "ē"); break;
                case KC_I: send_unicode_string(is_uppercase ? "Ī" : "ī"); break;
                case KC_O: send_unicode_string(is_uppercase ? "Ō" : "ō"); break;
                case KC_U: send_unicode_string(is_uppercase ? "Ū" : "ū"); break;
                case KC_Y: send_unicode_string(is_uppercase ? "Ȳ" : "ȳ"); break;
                case KC_SPC: send_unicode_string("¯"); break;
                default:
                    send_unicode_string("¯");
                    tap_code(base_key);
                    break;
            }
            break;
            
        case NEO_DEAD_BREVE:
            switch (base_key) {
                case KC_A: send_unicode_string(is_uppercase ? "Ă" : "ă"); break;
                case KC_E: send_unicode_string(is_uppercase ? "Ĕ" : "ĕ"); break;
                case KC_G: send_unicode_string(is_uppercase ? "Ğ" : "ğ"); break;
                case KC_I: send_unicode_string(is_uppercase ? "Ĭ" : "ĭ"); break;
                case KC_O: send_unicode_string(is_uppercase ? "Ŏ" : "ŏ"); break;
                case KC_U: send_unicode_string(is_uppercase ? "Ŭ" : "ŭ"); break;
                case KC_SPC: send_unicode_string("˘"); break;
                default:
                    send_unicode_string("˘");
                    tap_code(base_key);
                    break;
            }
            break;
            
        case NEO_DEAD_OGONEK:
            switch (base_key) {
                case KC_A: send_unicode_string(is_uppercase ? "Ą" : "ą"); break;
                case KC_E: send_unicode_string(is_uppercase ? "Ę" : "ę"); break;
                case KC_I: send_unicode_string(is_uppercase ? "Į" : "į"); break;
                case KC_O: send_unicode_string(is_uppercase ? "Ǫ" : "ǫ"); break;
                case KC_U: send_unicode_string(is_uppercase ? "Ų" : "ų"); break;
                case KC_SPC: send_unicode_string("˛"); break;
                default:
                    send_unicode_string("˛");
                    tap_code(base_key);
                    break;
            }
            break;
            
        case NEO_DEAD_RING_ABOVE:
            switch (base_key) {
                case KC_A: send_unicode_string(is_uppercase ? "Å" : "å"); break;
                case KC_U: send_unicode_string(is_uppercase ? "Ů" : "ů"); break;
                case KC_W: send_unicode_string(is_uppercase ? "W̊" : "ẘ"); break;
                case KC_Y: send_unicode_string(is_uppercase ? "Y̊" : "ẙ"); break;
                case KC_SPC: send_unicode_string("˚"); break;
                default:
                    send_unicode_string("˚");
                    tap_code(base_key);
                    break;
            }
            break;
            
        case NEO_DEAD_STROKE:
            switch (base_key) {
                case KC_L: send_unicode_string(is_uppercase ? "Ł" : "ł"); break;
                case KC_D: send_unicode_string(is_uppercase ? "Đ" : "đ"); break;
                case KC_H: send_unicode_string(is_uppercase ? "Ħ" : "ħ"); break;
                case KC_T: send_unicode_string(is_uppercase ? "Ŧ" : "ŧ"); break;
                case KC_O: send_unicode_string(is_uppercase ? "Ø" : "ø"); break;
                case KC_B: send_unicode_string(is_uppercase ? "Ƀ" : "ƀ"); break;
                case KC_G: send_unicode_string(is_uppercase ? "Ǥ" : "ǥ"); break;
                case KC_I: send_unicode_string(is_uppercase ? "Ɨ" : "ɨ"); break;
                case KC_J: send_unicode_string(is_uppercase ? "Ɉ" : "ɉ"); break;
                case KC_P: send_unicode_string(is_uppercase ? "Ᵽ" : "ᵽ"); break;
                case KC_R: send_unicode_string(is_uppercase ? "Ɍ" : "ɍ"); break;
                case KC_Y: send_unicode_string(is_uppercase ? "Ɏ" : "ɏ"); break;
                case KC_Z: send_unicode_string(is_uppercase ? "Ƶ" : "ƶ"); break;
                case KC_SPC: send_unicode_string("/"); break;
                default:
                    send_unicode_string("/");
                    tap_code(base_key);
                    break;
            }
            break;
    }
}

// NEO modifier state tracking
static bool neo_mod3_pressed = false;
static bool neo_mod4_pressed = false;

// Update NEO layers based on current modifier state
void update_neo_layers(void) {
    // Clear dead key state when changing layers - prevents state persistence across layers
    if (is_dead_key_active()) {
        clear_dead_key_state();
    }
    
    // Turn off all NEO layers first
    layer_off(2); // Ebene 3
    layer_off(3); // Ebene 4
    layer_off(4); // Ebene 5
    layer_off(5); // Ebene 6
    
    // Determine which layer to activate based on modifier combination
    if (neo_mod3_pressed && neo_mod4_pressed) {
        // Mod3 + Mod4 = Ebene 6 (Math symbols)
        layer_on(5);
    } else if (neo_mod3_pressed && (get_mods() & MOD_MASK_SHIFT)) {
        // Mod3 + Shift = Ebene 5 (Greek letters)
        layer_on(4);
    } else if (neo_mod3_pressed) {
        // Mod3 only = Ebene 3 (Symbols)
        layer_on(2);
    } else if (neo_mod4_pressed) {
        // Mod4 only = Ebene 4 (Navigation/Numbers)
        layer_on(3);
    }
    // If no modifiers pressed, stay on base layer (Ebene 1/2 handled by shift)
}

// Layer switching logic for NEO
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NEO_MOD3:
            neo_mod3_pressed = record->event.pressed;
            update_neo_layers();
            return false;
            
        case NEO_MOD4:
            neo_mod4_pressed = record->event.pressed;
            update_neo_layers();
            return false;
            
        case NEO_FN:
            if (record->event.pressed) {
                layer_on(6); // Activate Layer 6 (Function layer)
            } else {
                layer_off(6);
            }
            return false;
            
        // Dead key handling - Phase 1, 2 & 3 (Polish Enhancement) with enhanced state management
        case NEO_DEAD_CIRCUMFLEX:
        case NEO_DEAD_ACUTE:
        case NEO_DEAD_GRAVE:
        case NEO_DEAD_DIAERESIS:
        case NEO_DEAD_TILDE:
        case NEO_DEAD_CARON:
        case NEO_DEAD_CEDILLA:
        case NEO_DEAD_MACRON:
        case NEO_DEAD_BREVE:
        case NEO_DEAD_OGONEK:
        case NEO_DEAD_RING_ABOVE:
        case NEO_DEAD_STROKE:
            if (record->event.pressed) {
                activate_dead_key(keycode);
            }
            return false;
            
        // Handle shift key to update Greek letter layer
        case KC_LSFT:
        case KC_RSFT:
            // Let the shift key process normally, then update layers
            if (!record->event.pressed) {
                // Small delay to ensure shift state is updated
                wait_ms(1);
            }
            update_neo_layers();
            return true; // Let shift key process normally
            
        // Handle regular keys when dead key is active
        default:
            if (is_dead_key_active() && record->event.pressed) {
                // Check if this is a letter key that can be combined with dead key
                if ((keycode >= KC_A && keycode <= KC_Z) || keycode == KC_SPC) {
                    send_dead_key_combination(dead_key_state.keycode, keycode);
                    clear_dead_key_state(); // Clean state reset
                    return false;
                }
                // For non-combinable keys, clear dead key and let key process normally
                clear_dead_key_state();
            }
            break;
    }
    return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [1] = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [2] = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [3] = { ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [4] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [5] = { ENCODER_CCW_CW(RGB_SPD, RGB_SPI) },
    [6] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif
