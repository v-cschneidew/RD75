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
        KC_TAB,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,     KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,     UM(0), NEO_DEAD_ACUTE, KC_BSLS, KC_PGUP,
        NEO_MOD3, KC_U,   KC_I,    KC_A,    KC_E,    KC_O,     KC_S,    KC_N,    KC_R,    KC_T,    KC_D,     KC_Y,     NEO_MOD3, KC_ENT,  KC_PGDN,
        KC_LSFT,          UM(1), UM(2), UM(3), KC_P, KC_Z, KC_B, KC_M, KC_COMM, KC_DOT, KC_J, KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                              NEO_FN,   NEO_MOD4,           KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    // NEO Ebene 2 (Shift layer) - Layer 1 - HARDWARE LEVEL IMPLEMENTATION
    // Official layout: ˇ ° § ℓ » « $ € „ " " — ¸
    //                  X V L C W K H G F Q ẞ ˜
    //                  U I A E O S N R T D Y
    //                  Ü Ö Ä P Z B M – • J
    [1] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_MUTE,
        NEO_DEAD_CARON, UM(4), UM(5), UM(6), UM(7), UM(8), KC_DLR, UM(9), UM(10), UM(11), UM(12), NEO_DEAD_CEDILLA, UM(13), KC_BSPC, KC_END,
        S(KC_TAB), S(KC_X), S(KC_V), S(KC_L), S(KC_C), S(KC_W), S(KC_K), S(KC_H), S(KC_G), S(KC_F), S(KC_Q), UM(14), NEO_DEAD_TILDE, KC_BSLS, KC_PGUP,
        KC_TRNS, S(KC_U), S(KC_I), S(KC_A), S(KC_E), S(KC_O), S(KC_S), S(KC_N), S(KC_R), S(KC_T), S(KC_D), S(KC_Y), KC_TRNS, KC_ENT, KC_PGDN,
        KC_LSFT,          UM(15), UM(16), UM(17), S(KC_P), S(KC_Z), S(KC_B), S(KC_M), UM(18), UM(19), S(KC_J), KC_RSFT, KC_UP,
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
        NEO_DEAD_OGONEK, UM(20), UM(21), UM(22), UM(23), UM(24), UM(25), UM(26), UM(27), UM(28), UM(29), KC_SPC, NEO_DEAD_RING_ABOVE, KC_BSPC, KC_END,
        UM(30), UM(31), KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, KC_EXLM, KC_LABK, KC_RABK, KC_EQL, KC_AMPR, UM(32), NEO_DEAD_STROKE, KC_BSLS, KC_PGUP,
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
        KC_TRNS, UM(33), UM(34), UM(35), KC_SPC, UM(36), UM(37), UM(38), KC_TAB, KC_SLSH, KC_ASTR, KC_MINS, NEO_DEAD_DIAERESIS, KC_BSPC, KC_END,
        KC_TRNS, KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN, UM(39), KC_7, KC_8, KC_9, KC_PLUS, UM(40), UM(41), KC_BSLS, KC_PGUP,
        KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, UM(42), KC_4, KC_5, KC_6, KC_COMM, KC_DOT, KC_TRNS, KC_ENT, KC_PGDN,
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
        KC_TRNS, UM(43), UM(44), UM(45), UM(46), UM(47), UM(48), UM(49), KC_LABK, KC_RABK, UM(50), UM(51), UM(52), KC_BSPC, KC_END,
        KC_TRNS, UM(53), KC_SPC, UM(54), UM(55), UM(56), UM(57), UM(58), UM(59), UM(60), UM(61), UM(62), UM(63), KC_BSLS, KC_PGUP,
        KC_TRNS, KC_SPC, UM(64), UM(65), UM(66), UM(67), UM(68), UM(69), UM(70), UM(71), UM(72), UM(73), KC_TRNS, KC_ENT, KC_PGDN,
        KC_LSFT,          KC_SPC, UM(74), UM(75), UM(76), UM(77), UM(78), UM(79), UM(80), UM(81), UM(82), KC_RSFT, KC_UP,
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
        KC_DOT,  UM(83), UM(84), UM(85), UM(86), UM(87), UM(88), UM(89), UM(90), UM(91), UM(92), UM(93), NEO_DEAD_MACRON, KC_BSPC, KC_END,
        KC_TRNS, UM(94), UM(95), UM(96), UM(97), UM(98), UM(99), UM(100), UM(101), UM(102), UM(103), UM(104), NEO_DEAD_BREVE, KC_BSLS, KC_PGUP,
        KC_TRNS, UM(105), UM(106), UM(107), UM(108), UM(109), UM(110), UM(111), UM(112), UM(113), UM(114), UM(115), KC_TRNS, KC_ENT, KC_PGDN,
        KC_LSFT,          UM(116), UM(117), UM(118), UM(119), UM(120), UM(121), UM(122), UM(123), UM(124), UM(125), KC_RSFT, KC_UP,
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

// UNICODEMAP for optimized Unicode input across Windows, Mac, and Linux
// Complete systematic extraction of ALL Unicode characters used in the keymap
const uint32_t PROGMEM unicode_map[] = {
    // Layer 0 (Base) - UC() calls
    [0] = 0x00DF,   // ß (UC(0x00DF))
    [1] = 0x00FC,   // ü (UC(0x00FC))
    [2] = 0x00F6,   // ö (UC(0x00F6))
    [3] = 0x00E4,   // ä (UC(0x00E4))
    
    // Layer 1 (Shift) - UC() calls
    [4] = 0x00B0,   // ° (UC(0x00B0))
    [5] = 0x00A7,   // § (UC(0x00A7))
    [6] = 0x2113,   // ℓ (UC(0x2113))
    [7] = 0x00BB,   // » (UC(0x00BB))
    [8] = 0x00AB,   // « (UC(0x00AB))
    [9] = 0x20AC,   // € (UC(0x20AC))
    [10] = 0x201E,  // „ (UC(0x201E))
    [11] = 0x201C,  // " (UC(0x201C))
    [12] = 0x201D,  // " (UC(0x201D))
    [13] = 0x00B8,  // ¸ (UC(0x00B8))
    [14] = 0x1E9E,  // ẞ (UC(0x1E9E))
    [15] = 0x00DC,  // Ü (UC(0x00DC))
    [16] = 0x00D6,  // Ö (UC(0x00D6))
    [17] = 0x00C4,  // Ä (UC(0x00C4))
    [18] = 0x2013,  // – (UC(0x2013))
    [19] = 0x2022,  // • (UC(0x2022))
    
    // Layer 2 (Mod3) - UC() calls
    [20] = 0x00B9,  // ¹ (UC(0x00B9))
    [21] = 0x00B2,  // ² (UC(0x00B2))
    [22] = 0x00B3,  // ³ (UC(0x00B3))
    [23] = 0x203A,  // › (UC(0x203A))
    [24] = 0x2039,  // ‹ (UC(0x2039))
    [25] = 0x00A2,  // ¢ (UC(0x00A2))
    [26] = 0x00A5,  // ¥ (UC(0x00A5))
    [27] = 0x201A,  // ‚ (UC(0x201A))
    [28] = 0x2018,  // ' (UC(0x2018))
    [29] = 0x2019,  // ' (UC(0x2019))
    [30] = 0x266B,  // ♫ (UC(0x266B))
    [31] = 0x2026,  // … (UC(0x2026))
    [32] = 0x017F,  // ſ (UC(0x017F))
    
    // Layer 3 (Mod4) - UC() calls
    [33] = 0x02D9,  // ˙ (UC(0x02D9))
    [34] = 0x00AA,  // ª (UC(0x00AA))
    [35] = 0x00BA,  // º (UC(0x00BA))
    [36] = 0x00B7,  // · (UC(0x00B7))
    [37] = 0x00A3,  // £ (UC(0x00A3))
    [38] = 0x00A4,  // ¤ (UC(0x00A4))
    [39] = 0x00A1,  // ¡ (UC(0x00A1))
    [40] = 0x2212,  // − (UC(0x2212))
    [41] = 0x02DD,  // ˝ (UC(0x02DD))
    [42] = 0x00BF,  // ¿ (UC(0x00BF))
    
    // Layer 4 (Greek) - UC() calls
    [43] = 0x2081,  // ₁ (UC(0x2081))
    [44] = 0x2082,  // ₂ (UC(0x2082))
    [45] = 0x2083,  // ₃ (UC(0x2083))
    [46] = 0x2640,  // ♀ (UC(0x2640))
    [47] = 0x2642,  // ♂ (UC(0x2642))
    [48] = 0x26A5,  // ⚥ (UC(0x26A5))
    [49] = 0x03F0,  // ϰ (UC(0x03F0))
    [50] = 0x2080,  // ₀ (UC(0x2080))
    [51] = 0x2011,  // ‑ (UC(0x2011))
    [52] = 0x1FFE,  // ῾ (UC(0x1FFE))
    [53] = 0x03BE,  // ξ (UC(0x03BE))
    [54] = 0x03BB,  // λ (UC(0x03BB))
    [55] = 0x03C7,  // χ (UC(0x03C7))
    [56] = 0x03C9,  // ω (UC(0x03C9))
    [57] = 0x03BA,  // κ (UC(0x03BA))
    [58] = 0x03C8,  // ψ (UC(0x03C8))
    [59] = 0x03B3,  // γ (UC(0x03B3))
    [60] = 0x03C6,  // φ (UC(0x03C6))
    [61] = 0x03D5,  // ϕ (UC(0x03D5))
    [62] = 0x03C2,  // ς (UC(0x03C2))
    [63] = 0x1FBF,  // ᾿ (UC(0x1FBF))
    [64] = 0x03B9,  // ι (UC(0x03B9))
    [65] = 0x03B1,  // α (UC(0x03B1))
    [66] = 0x03B5,  // ε (UC(0x03B5))
    [67] = 0x03BF,  // ο (UC(0x03BF))
    [68] = 0x03C3,  // σ (UC(0x03C3))
    [69] = 0x03BD,  // ν (UC(0x03BD))
    [70] = 0x03C1,  // ρ (UC(0x03C1))
    [71] = 0x03C4,  // τ (UC(0x03C4))
    [72] = 0x03B4,  // δ (UC(0x03B4))
    [73] = 0x03C5,  // υ (UC(0x03C5))
    [74] = 0x03F5,  // ϵ (UC(0x03F5))
    [75] = 0x03B7,  // η (UC(0x03B7))
    [76] = 0x03C0,  // π (UC(0x03C0))
    [77] = 0x03B6,  // ζ (UC(0x03B6))
    [78] = 0x03B2,  // β (UC(0x03B2))
    [79] = 0x03BC,  // μ (UC(0x03BC))
    [80] = 0x03F1,  // ϱ (UC(0x03F1))
    [81] = 0x03D1,  // ϑ (UC(0x03D1))
    [82] = 0x03B8,  // θ (UC(0x03B8))
    
    // Layer 5 (Math) - UC() calls
    [83] = 0x00AC,  // ¬ (UC(0x00AC))
    [84] = 0x2228,  // ∨ (UC(0x2228))
    [85] = 0x2227,  // ∧ (UC(0x2227))
    [86] = 0x22A5,  // ⊥ (UC(0x22A5))
    [87] = 0x2221,  // ∡ (UC(0x2221))
    [88] = 0x2225,  // ∥ (UC(0x2225))
    [89] = 0x2192,  // → (UC(0x2192))
    [90] = 0x221E,  // ∞ (UC(0x221E))
    [91] = 0x221D,  // ∝ (UC(0x221D))
    [92] = 0x2205,  // ∅ (UC(0x2205))
    [93] = 0x254C,  // ╌ (UC(0x254C))
    [94] = 0x039E,  // Ξ (UC(0x039E))
    [95] = 0x221A,  // √ (UC(0x221A))
    [96] = 0x039B,  // Λ (UC(0x039B))
    [97] = 0x2102,  // ℂ (UC(0x2102))
    [98] = 0x03A9,  // Ω (UC(0x03A9))
    [99] = 0x00D7,  // × (UC(0x00D7))
    [100] = 0x03A8, // Ψ (UC(0x03A8))
    [101] = 0x0393, // Γ (UC(0x0393))
    [102] = 0x03A6, // Φ (UC(0x03A6))
    [103] = 0x211A, // ℚ (UC(0x211A))
    [104] = 0x2218, // ∘ (UC(0x2218))
    [105] = 0x2282, // ⊂ (UC(0x2282))
    [106] = 0x222B, // ∫ (UC(0x222B))
    [107] = 0x2200, // ∀ (UC(0x2200))
    [108] = 0x2203, // ∃ (UC(0x2203))
    [109] = 0x2208, // ∈ (UC(0x2208))
    [110] = 0x03A3, // Σ (UC(0x03A3))
    [111] = 0x2115, // ℕ (UC(0x2115))
    [112] = 0x211D, // ℝ (UC(0x211D))
    [113] = 0x2202, // ∂ (UC(0x2202))
    [114] = 0x0394, // Δ (UC(0x0394))
    [115] = 0x2207, // ∇ (UC(0x2207))
    [116] = 0x222A, // ∪ (UC(0x222A))
    [117] = 0x2229, // ∩ (UC(0x2229))
    [118] = 0x2135, // ℵ (UC(0x2135))
    [119] = 0x03A0, // Π (UC(0x03A0))
    [120] = 0x2124, // ℤ (UC(0x2124))
    [121] = 0x21D0, // ⇐ (UC(0x21D0))
    [122] = 0x21D4, // ⇔ (UC(0x21D4))
    [123] = 0x21D2, // ⇒ (UC(0x21D2))
    [124] = 0x21A6, // ↦ (UC(0x21A6))
    [125] = 0x0398, // Θ (UC(0x0398))
    
    // Dead key characters - all accented characters from send_unicode_string calls
    [126] = 0x00E2, // â
    [127] = 0x00EA, // ê
    [128] = 0x00EE, // î
    [129] = 0x00F4, // ô
    [130] = 0x00FB, // û
    [131] = 0x00C2, // Â
    [132] = 0x00CA, // Ê
    [133] = 0x00CE, // Î
    [134] = 0x00D4, // Ô
    [135] = 0x00DB, // Û
    [136] = 0x02C6, // ˆ
    [137] = 0x00E1, // á
    [138] = 0x00E9, // é
    [139] = 0x00ED, // í
    [140] = 0x00F3, // ó
    [141] = 0x00FA, // ú
    [142] = 0x00FD, // ý
    [143] = 0x0107, // ć
    [144] = 0x0144, // ń
    [145] = 0x015B, // ś
    [146] = 0x017A, // ź
    [147] = 0x00C1, // Á
    [148] = 0x00C9, // É
    [149] = 0x00CD, // Í
    [150] = 0x00D3, // Ó
    [151] = 0x00DA, // Ú
    [152] = 0x00DD, // Ý
    [153] = 0x0106, // Ć
    [154] = 0x0143, // Ń
    [155] = 0x015A, // Ś
    [156] = 0x0179, // Ź
    [157] = 0x00B4, // ´
    [158] = 0x00E0, // à
    [159] = 0x00E8, // è
    [160] = 0x00EC, // ì
    [161] = 0x00F2, // ò
    [162] = 0x00F9, // ù
    [163] = 0x00C0, // À
    [164] = 0x00C8, // È
    [165] = 0x00CC, // Ì
    [166] = 0x00D2, // Ò
    [167] = 0x00D9, // Ù
    [168] = 0x0060, // `
    [169] = 0x00EB, // ë
    [170] = 0x00EF, // ï
    [171] = 0x00FF, // ÿ
    [172] = 0x00CB, // Ë
    [173] = 0x00CF, // Ï
    [174] = 0x0178, // Ÿ
    [175] = 0x00A8, // ¨
    [176] = 0x00E3, // ã
    [177] = 0x00F1, // ñ
    [178] = 0x00F5, // õ
    [179] = 0x00C3, // Ã
    [180] = 0x00D1, // Ñ
    [181] = 0x00D5, // Õ
    [182] = 0x02DC, // ˜
    [183] = 0x010D, // č
    [184] = 0x0161, // š
    [185] = 0x017E, // ž
    [186] = 0x0148, // ň
    [187] = 0x0159, // ř
    [188] = 0x010F, // ď
    [189] = 0x0165, // ť
    [190] = 0x013E, // ľ
    [191] = 0x011B, // ě
    [192] = 0x010C, // Č
    [193] = 0x0160, // Š
    [194] = 0x017D, // Ž
    [195] = 0x0147, // Ň
    [196] = 0x0158, // Ř
    [197] = 0x010E, // Ď
    [198] = 0x0164, // Ť
    [199] = 0x013D, // Ľ
    [200] = 0x011A, // Ě
    [201] = 0x02C7, // ˇ
    [202] = 0x00E7, // ç
    [203] = 0x015F, // ş
    [204] = 0x0163, // ţ
    [205] = 0x0123, // ģ
    [206] = 0x0137, // ķ
    [207] = 0x013C, // ļ
    [208] = 0x0146, // ņ
    [209] = 0x0157, // ŗ
    [210] = 0x00C7, // Ç
    [211] = 0x015E, // Ş
    [212] = 0x0162, // Ţ
    [213] = 0x0122, // Ģ
    [214] = 0x0136, // Ķ
    [215] = 0x013B, // Ļ
    [216] = 0x0145, // Ņ
    [217] = 0x0156, // Ŗ
    [218] = 0x0101, // ā
    [219] = 0x0113, // ē
    [220] = 0x012B, // ī
    [221] = 0x014D, // ō
    [222] = 0x016B, // ū
    [223] = 0x0233, // ȳ
    [224] = 0x0100, // Ā
    [225] = 0x0112, // Ē
    [226] = 0x012A, // Ī
    [227] = 0x014C, // Ō
    [228] = 0x016A, // Ū
    [229] = 0x0232, // Ȳ
    [230] = 0x00AF, // ¯
    [231] = 0x0103, // ă
    [232] = 0x0115, // ĕ
    [233] = 0x011F, // ğ
    [234] = 0x012D, // ĭ
    [235] = 0x014F, // ŏ
    [236] = 0x016D, // ŭ
    [237] = 0x0102, // Ă
    [238] = 0x0114, // Ĕ
    [239] = 0x011E, // Ğ
    [240] = 0x012C, // Ĭ
    [241] = 0x014E, // Ŏ
    [242] = 0x016C, // Ŭ
    [243] = 0x02D8, // ˘
    [244] = 0x0105, // ą
    [245] = 0x0119, // ę
    [246] = 0x012F, // į
    [247] = 0x01EB, // ǫ
    [248] = 0x0173, // ų
    [249] = 0x0104, // Ą
    [250] = 0x0118, // Ę
    [251] = 0x012E, // Į
    [252] = 0x01EA, // Ǫ
    [253] = 0x0172, // Ų
    [254] = 0x02DB, // ˛
    [255] = 0x00E5, // å
    [256] = 0x016F, // ů
    [257] = 0x1E98, // ẘ
    [258] = 0x1E99, // ẙ
    [259] = 0x00C5, // Å
    [260] = 0x016E, // Ů
    [261] = 0x02DA, // ˚
    [262] = 0x0142, // ł
    [263] = 0x0111, // đ
    [264] = 0x0127, // ħ
    [265] = 0x0167, // ŧ
    [266] = 0x00F8, // ø
    [267] = 0x0180, // ƀ
    [268] = 0x01E5, // ǥ
    [269] = 0x0268, // ɨ
    [270] = 0x0249, // ɉ
    [271] = 0x2C63, // ᵽ
    [272] = 0x024D, // ɍ
    [273] = 0x024F, // ɏ
    [274] = 0x01B6, // ƶ
    [275] = 0x0141, // Ł
    [276] = 0x0110, // Đ
    [277] = 0x0126, // Ħ
    [278] = 0x0166, // Ŧ
    [279] = 0x00D8, // Ø
    [280] = 0x0243, // Ƀ
    [281] = 0x01E4, // Ǥ
    [282] = 0x0197, // Ɨ
    [283] = 0x0248, // Ɉ
    [284] = 0x2C62, // Ᵽ
    [285] = 0x024C, // Ɍ
    [286] = 0x024E, // Ɏ
    [287] = 0x01B5, // Ƶ
    [288] = 0x002F  // /
};

// Table-driven dead key mapping structure
typedef struct {
    uint16_t dead_key;          // Dead key code (NEO_DEAD_CIRCUMFLEX, etc.)
    uint16_t base_key;          // Base key code (KC_A, KC_E, etc.)
    uint16_t lowercase_index;   // Unicode map index for lowercase result
    uint16_t uppercase_index;   // Unicode map index for uppercase result
} dead_key_mapping_t;

// Dead key lookup table - replaces massive switch statements
const dead_key_mapping_t PROGMEM dead_key_table[] = {
    // NEO_DEAD_CIRCUMFLEX combinations
    {NEO_DEAD_CIRCUMFLEX, KC_A, 126, 131},  // â : Â
    {NEO_DEAD_CIRCUMFLEX, KC_E, 127, 132},  // ê : Ê
    {NEO_DEAD_CIRCUMFLEX, KC_I, 128, 133},  // î : Î
    {NEO_DEAD_CIRCUMFLEX, KC_O, 129, 134},  // ô : Ô
    {NEO_DEAD_CIRCUMFLEX, KC_U, 130, 135},  // û : Û
    {NEO_DEAD_CIRCUMFLEX, KC_SPC, 136, 136}, // ˆ : ˆ (same for both cases)
    
    // NEO_DEAD_ACUTE combinations
    {NEO_DEAD_ACUTE, KC_A, 137, 147},       // á : Á
    {NEO_DEAD_ACUTE, KC_E, 138, 148},       // é : É
    {NEO_DEAD_ACUTE, KC_I, 139, 149},       // í : Í
    {NEO_DEAD_ACUTE, KC_O, 140, 150},       // ó : Ó
    {NEO_DEAD_ACUTE, KC_U, 141, 151},       // ú : Ú
    {NEO_DEAD_ACUTE, KC_Y, 142, 152},       // ý : Ý
    {NEO_DEAD_ACUTE, KC_C, 143, 153},       // ć : Ć
    {NEO_DEAD_ACUTE, KC_N, 144, 154},       // ń : Ń
    {NEO_DEAD_ACUTE, KC_S, 145, 155},       // ś : Ś
    {NEO_DEAD_ACUTE, KC_Z, 146, 156},       // ź : Ź
    {NEO_DEAD_ACUTE, KC_SPC, 157, 157},     // ´ : ´
    
    // NEO_DEAD_GRAVE combinations
    {NEO_DEAD_GRAVE, KC_A, 158, 163},       // à : À
    {NEO_DEAD_GRAVE, KC_E, 159, 164},       // è : È
    {NEO_DEAD_GRAVE, KC_I, 160, 165},       // ì : Ì
    {NEO_DEAD_GRAVE, KC_O, 161, 166},       // ò : Ò
    {NEO_DEAD_GRAVE, KC_U, 162, 167},       // ù : Ù
    {NEO_DEAD_GRAVE, KC_SPC, 168, 168},     // ` : `
    
    // NEO_DEAD_DIAERESIS combinations
    {NEO_DEAD_DIAERESIS, KC_A, 3, 17},      // ä : Ä (reuse from layer 0/1)
    {NEO_DEAD_DIAERESIS, KC_E, 169, 172},   // ë : Ë
    {NEO_DEAD_DIAERESIS, KC_I, 170, 173},   // ï : Ï
    {NEO_DEAD_DIAERESIS, KC_O, 2, 16},      // ö : Ö (reuse from layer 0/1)
    {NEO_DEAD_DIAERESIS, KC_U, 1, 15},      // ü : Ü (reuse from layer 0/1)
    {NEO_DEAD_DIAERESIS, KC_Y, 171, 174},   // ÿ : Ÿ
    {NEO_DEAD_DIAERESIS, KC_SPC, 175, 175}, // ¨ : ¨
    
    // NEO_DEAD_TILDE combinations
    {NEO_DEAD_TILDE, KC_A, 176, 179},       // ã : Ã
    {NEO_DEAD_TILDE, KC_N, 177, 180},       // ñ : Ñ
    {NEO_DEAD_TILDE, KC_O, 178, 181},       // õ : Õ
    {NEO_DEAD_TILDE, KC_SPC, 182, 182},     // ˜ : ˜
    
    // NEO_DEAD_CARON combinations
    {NEO_DEAD_CARON, KC_C, 183, 192},       // č : Č
    {NEO_DEAD_CARON, KC_S, 184, 193},       // š : Š
    {NEO_DEAD_CARON, KC_Z, 185, 194},       // ž : Ž
    {NEO_DEAD_CARON, KC_N, 186, 195},       // ň : Ň
    {NEO_DEAD_CARON, KC_R, 187, 196},       // ř : Ř
    {NEO_DEAD_CARON, KC_D, 188, 197},       // ď : Ď
    {NEO_DEAD_CARON, KC_T, 189, 198},       // ť : Ť
    {NEO_DEAD_CARON, KC_L, 190, 199},       // ľ : Ľ
    {NEO_DEAD_CARON, KC_E, 191, 200},       // ě : Ě
    {NEO_DEAD_CARON, KC_SPC, 201, 201},     // ˇ : ˇ
    
    // NEO_DEAD_CEDILLA combinations
    {NEO_DEAD_CEDILLA, KC_C, 202, 210},     // ç : Ç
    {NEO_DEAD_CEDILLA, KC_S, 203, 211},     // ş : Ş
    {NEO_DEAD_CEDILLA, KC_T, 204, 212},     // ţ : Ţ
    {NEO_DEAD_CEDILLA, KC_G, 205, 213},     // ģ : Ģ
    {NEO_DEAD_CEDILLA, KC_K, 206, 214},     // ķ : Ķ
    {NEO_DEAD_CEDILLA, KC_L, 207, 215},     // ļ : Ļ
    {NEO_DEAD_CEDILLA, KC_N, 208, 216},     // ņ : Ņ
    {NEO_DEAD_CEDILLA, KC_R, 209, 217},     // ŗ : Ŗ
    {NEO_DEAD_CEDILLA, KC_SPC, 13, 13},     // ¸ : ¸ (reuse from layer 1)
    
    // NEO_DEAD_MACRON combinations
    {NEO_DEAD_MACRON, KC_A, 218, 224},      // ā : Ā
    {NEO_DEAD_MACRON, KC_E, 219, 225},      // ē : Ē
    {NEO_DEAD_MACRON, KC_I, 220, 226},      // ī : Ī
    {NEO_DEAD_MACRON, KC_O, 221, 227},      // ō : Ō
    {NEO_DEAD_MACRON, KC_U, 222, 228},      // ū : Ū
    {NEO_DEAD_MACRON, KC_Y, 223, 229},      // ȳ : Ȳ
    {NEO_DEAD_MACRON, KC_SPC, 230, 230},    // ¯ : ¯
    
    // NEO_DEAD_BREVE combinations
    {NEO_DEAD_BREVE, KC_A, 231, 237},       // ă : Ă
    {NEO_DEAD_BREVE, KC_E, 232, 238},       // ĕ : Ĕ
    {NEO_DEAD_BREVE, KC_G, 233, 239},       // ğ : Ğ
    {NEO_DEAD_BREVE, KC_I, 234, 240},       // ĭ : Ĭ
    {NEO_DEAD_BREVE, KC_O, 235, 241},       // ŏ : Ŏ
    {NEO_DEAD_BREVE, KC_U, 236, 242},       // ŭ : Ŭ
    {NEO_DEAD_BREVE, KC_SPC, 243, 243},     // ˘ : ˘
    
    // NEO_DEAD_OGONEK combinations
    {NEO_DEAD_OGONEK, KC_A, 244, 249},      // ą : Ą
    {NEO_DEAD_OGONEK, KC_E, 245, 250},      // ę : Ę
    {NEO_DEAD_OGONEK, KC_I, 246, 251},      // į : Į
    {NEO_DEAD_OGONEK, KC_O, 247, 252},      // ǫ : Ǫ
    {NEO_DEAD_OGONEK, KC_U, 248, 253},      // ų : Ų
    {NEO_DEAD_OGONEK, KC_SPC, 254, 254},    // ˛ : ˛
    
    // NEO_DEAD_RING_ABOVE combinations
    {NEO_DEAD_RING_ABOVE, KC_A, 255, 259},  // å : Å
    {NEO_DEAD_RING_ABOVE, KC_U, 256, 260},  // ů : Ů
    {NEO_DEAD_RING_ABOVE, KC_W, 257, 261},  // ẘ : W̊
    {NEO_DEAD_RING_ABOVE, KC_Y, 258, 261},  // ẙ : Y̊
    {NEO_DEAD_RING_ABOVE, KC_SPC, 261, 261}, // ˚ : ˚
    
    // NEO_DEAD_STROKE combinations
    {NEO_DEAD_STROKE, KC_L, 262, 275},      // ł : Ł
    {NEO_DEAD_STROKE, KC_D, 263, 276},      // đ : Đ
    {NEO_DEAD_STROKE, KC_H, 264, 277},      // ħ : Ħ
    {NEO_DEAD_STROKE, KC_T, 265, 278},      // ŧ : Ŧ
    {NEO_DEAD_STROKE, KC_O, 266, 279},      // ø : Ø
    {NEO_DEAD_STROKE, KC_B, 267, 280},      // ƀ : Ƀ
    {NEO_DEAD_STROKE, KC_G, 268, 281},      // ǥ : Ǥ
    {NEO_DEAD_STROKE, KC_I, 269, 282},      // ɨ : Ɨ
    {NEO_DEAD_STROKE, KC_J, 270, 283},      // ɉ : Ɉ
    {NEO_DEAD_STROKE, KC_P, 271, 284},      // ᵽ : Ᵽ
    {NEO_DEAD_STROKE, KC_R, 272, 285},      // ɍ : Ɍ
    {NEO_DEAD_STROKE, KC_Y, 273, 286},      // ɏ : Ɏ
    {NEO_DEAD_STROKE, KC_Z, 274, 287},      // ƶ : Ƶ
    {NEO_DEAD_STROKE, KC_SPC, 288, 288},    // / : /
};

#define DEAD_KEY_TABLE_SIZE (sizeof(dead_key_table) / sizeof(dead_key_mapping_t))

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

// Table-driven dead key lookup function
uint16_t find_dead_key_unicode_index(uint16_t dead_key, uint16_t base_key, bool is_uppercase) {
    // Linear search through the dead key table
    // For better performance, this could be replaced with binary search or hash table
    for (uint16_t i = 0; i < DEAD_KEY_TABLE_SIZE; i++) {
        const dead_key_mapping_t *mapping = &dead_key_table[i];
        if (pgm_read_word(&mapping->dead_key) == dead_key &&
            pgm_read_word(&mapping->base_key) == base_key) {
            // Found matching combination
            if (is_uppercase) {
                return pgm_read_word(&mapping->uppercase_index);
            } else {
                return pgm_read_word(&mapping->lowercase_index);
            }
        }
    }
    
    // No matching combination found - return fallback dead key character
    // This handles cases where user types unsupported base key after dead key
    for (uint16_t i = 0; i < DEAD_KEY_TABLE_SIZE; i++) {
        const dead_key_mapping_t *mapping = &dead_key_table[i];
        if (pgm_read_word(&mapping->dead_key) == dead_key &&
            pgm_read_word(&mapping->base_key) == KC_SPC) {
            // Return the dead key character itself (space combination)
            return pgm_read_word(&mapping->lowercase_index);
        }
    }
    
    // Ultimate fallback - should never happen with proper table
    return 0;
}

// Dead key processing - Table-driven implementation with race condition protection
void send_dead_key_combination(uint16_t dead_key, uint16_t base_key) {
    // Use cached shift state from when dead key was pressed - prevents race conditions
    bool is_uppercase = dead_key_state.shift_state;
    
    // Look up the Unicode index using the table
    uint16_t unicode_index = find_dead_key_unicode_index(dead_key, base_key, is_uppercase);
    
    if (unicode_index != 0) {
        // Found valid combination - send the Unicode character
        register_unicode(unicode_index);
    } else {
        // No valid combination found - send dead key character + base key
        uint16_t fallback_index = find_dead_key_unicode_index(dead_key, KC_SPC, false);
        if (fallback_index != 0) {
            register_unicode(fallback_index);
        }
        // Also send the base key that was pressed
        tap_code(base_key);
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
