# NEO Test Keymap Implementation Plan

## Overview
This is a simplified version of the NEO keymap with only 4 layers (0-3) to debug firmware flashing issues. The goal is to match the EEPROM configuration of the working default firmware while keeping the core NEO functionality.

## Analysis Summary

### Working Default Keymap
- **Layers:** 4 (0-3)
- **EEPROM_SIZE:** 1152 bytes
- **DYNAMIC_KEYMAP_EEPROM_MAX_ADDR:** 1151
- **Firmware size:** ~30 KB (estimated)
- **Features:** VIA only, no Unicode

### Original NEO Keymap (Not Working)
- **Layers:** 7 (0-6)
- **EEPROM_SIZE:** 2688 bytes
- **DYNAMIC_KEYMAP_EEPROM_MAX_ADDR:** 2687
- **Firmware size:** 73,992 bytes
- **Features:** VIA, Unicode, extensive dead keys

### NEO Test Strategy
- **Layers:** 4 (Layers 0-3 from NEO: Base, Shift, Mod3 symbols, Mod4 navigation)
- **EEPROM_SIZE:** 1152 bytes (match default)
- **Dead keys:** Only Phase 1 (5 essential dead keys)
- **Unicode:** Minimal set (only characters used in layers 0-3)

## Files to Create

### 1. config.h
**Path:** `keyboards/wob/rd75/keymaps/neotest/config.h`

```c
/* Copyright 2023 Yiancar-Designs
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

#pragma once

// EEPROM configuration - MATCH DEFAULT to avoid initialization issues
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR  1151
#define EEPROM_SIZE 1152

#define FEE_PAGE_SIZE (0x200)
#define FEE_PAGE_COUNT (8)

#define FEE_PAGE_BASE_ADDRESS (0x1F000)
#define FEE_MCU_FLASH_SIZE (0x1000)

#define EECONFIG_USER_DATA_SIZE 4
#define EECONFIG_KB_DATA_SIZE 1
#define TRANSIENT_EEPROM_SIZE 4096

// Enable Unicode support for NEO special characters
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_MACOS, UNICODE_MODE_LINUX

// Use 4 layers for NEO test (0-3)
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// Enable tap dance for dead keys
#define TAPPING_TERM 200
```

**Key Changes from NEO:**
- EEPROM_SIZE: 2688 → 1152 (matches default)
- DYNAMIC_KEYMAP_LAYER_COUNT: 7 → 4 (layers 0-3 only)

---

### 2. rules.mk
**Path:** `keyboards/wob/rd75/keymaps/neotest/rules.mk`

```makefile
# NEO Test Keymap Rules - Minimal configuration

# Copy VIA keymap configuration that works
VIA_ENABLE = yes
EEPROM_DRIVER = custom

# Enable Unicode support for special NEO characters
UNICODEMAP_ENABLE = yes
UNICODE_ENABLE = no

# Disable features to save space
COMBO_ENABLE = no
ENCODER_MAP_ENABLE = no
TAP_DANCE_ENABLE = no
MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no

# Keep minimal features
EXTRAKEY_ENABLE = yes
RGB_MATRIX_ENABLE = yes
ENCODER_ENABLE = yes
```

**Key Points:**
- Same as NEO but explicitly minimal
- All unnecessary features disabled

---

### 3. keymap.c
**Path:** `keyboards/wob/rd75/keymaps/neotest/keymap.c`

**Structure:**
```c
/* Copyright header */
#include QMK_KEYBOARD_H
#include "../../../lib/rdr_lib/rdr_common.h"
#include "keymap_german.h"

// Custom keycodes for NEO - SIMPLIFIED
enum custom_keycodes {
    NEO_MOD3 = SAFE_RANGE,
    NEO_MOD4,
    
    // Phase 1 dead keys only (5 essential)
    NEO_DEAD_CIRCUMFLEX,
    NEO_DEAD_GRAVE,
    NEO_DEAD_ACUTE,
    NEO_DEAD_DIAERESIS,
    NEO_DEAD_TILDE
};

// LAYER DEFINITIONS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0: NEO Base (from original keymap lines 58-65)
    // Layer 1: NEO Shift (from original keymap lines 72-79)
    // Layer 2: NEO Mod3 symbols (from original keymap lines 88-95)
    // Layer 3: NEO Mod4 navigation (from original keymap lines 103-110)
};

// UNICODE MAP - Only characters used in layers 0-3
const uint32_t PROGMEM unicode_map[] = {
    // Extract from original unicode_map (lines 161-467)
    // Include indices 0-42 which cover layers 0-3
    // Total ~43 characters instead of 467
};

// DEAD KEY TABLE - Only Phase 1 (5 dead keys)
typedef struct {
    uint16_t dead_key;
    uint16_t base_key;
    uint16_t lowercase_index;
    uint16_t uppercase_index;
} dead_key_mapping_t;

const dead_key_mapping_t PROGMEM dead_key_table[] = {
    // Only include dead key combinations for:
    // - NEO_DEAD_CIRCUMFLEX
    // - NEO_DEAD_GRAVE
    // - NEO_DEAD_ACUTE
    // - NEO_DEAD_DIAERESIS
    // - NEO_DEAD_TILDE
    // From lines 479-522 (skip Polish/extended dead keys)
};

// Dead key state management (simplified)
static struct {
    uint16_t keycode;
    bool shift_state;
} dead_key_state = {0, false};

// NEO modifier tracking
static bool neo_mod3_pressed = false;
static bool neo_mod4_pressed = false;

// Update NEO layers (simplified - only 0-3)
void update_neo_layers(void) {
    layer_off(2); // Mod3
    layer_off(3); // Mod4
    
    if (neo_mod3_pressed) {
        layer_on(2);
    } else if (neo_mod4_pressed) {
        layer_on(3);
    }
}

// Process record (simplified)
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
            
        case NEO_DEAD_CIRCUMFLEX:
        case NEO_DEAD_GRAVE:
        case NEO_DEAD_ACUTE:
        case NEO_DEAD_DIAERESIS:
        case NEO_DEAD_TILDE:
            if (record->event.pressed) {
                dead_key_state.keycode = keycode;
                dead_key_state.shift_state = get_mods() & MOD_MASK_SHIFT;
            }
            return false;
            
        default:
            if (dead_key_state.keycode && record->event.pressed) {
                // Process dead key combination
                send_dead_key_combo(dead_key_state.keycode, keycode);
                dead_key_state.keycode = 0;
                return false;
            }
            break;
    }
    return true;
}
```

---

## Unicode Characters Required for Layers 0-3

### Layer 0 (Base)
- German: ä, ö, ü, ß (indices 0-3)

### Layer 1 (Shift)
- Degree: ° (index 4)
- Section: § (index 5)
- Script l: ℓ (index 6)
- Quotes: », « (indices 7-8)
- Euro: € (index 9)
- German quotes: „, ", " (indices 10-12)
- Cedilla: ¸ (index 13)
- German caps: Ä, Ö, Ü, ẞ (indices 14-17)
- En dash: – (index 18)
- Bullet: • (index 19)

### Layer 2 (Mod3)
- Superscripts: ¹, ², ³ (indices 20-22)
- Angle quotes: ›, ‹ (indices 23-24)
- Currency: ¢, ¥ (indices 25-26)
- Quotes: ‚, ', ' (indices 27-29)
- Music: ♫ (index 30)
- Ellipsis: … (index 31)
- Long s: ſ (index 32)

### Layer 3 (Mod4)
- Dot above: ˙ (index 33)
- Ordinals: ª, º (indices 34-35)
- Middle dot: · (index 36)
- Currency: £, ¤ (indices 37-38)
- Inverted !: ¡ (index 39)
- Minus: − (index 40)
- Double acute: ˝ (index 41)
- Inverted ?: ¿ (index 42)

**Total Unicode characters: 43** (vs 467 in full NEO)

### Dead Key Characters (Phase 1)
From original indices 126-182:
- Circumflex combinations: â, ê, î, ô, û, Â, Ê, Î, Ô, Û, ˆ
- Grave combinations: à, è, ì, ò, ù, À, È, Ì, Ò, Ù, `
- Acute combinations: á, é, í, ó, ú, ý, ć, ń, ś, ź, Á, É, Í, Ó, Ú, Ý, Ć, Ń, Ś, Ź, ´
- Diaeresis combinations: ä, ë, ï, ö, ü, ÿ, Ä, Ë, Ï, Ö, Ü, Ÿ, ¨
- Tilde combinations: ã, ñ, õ, Ã, Ñ, Õ, ˜

**Total additional for dead keys: ~57 characters**

---

## Implementation Steps

### Step 1: Create Directory
```bash
mkdir -p keyboards/wob/rd75/keymaps/neotest
```

### Step 2: Create Files
1. Create `config.h` with content above
2. Create `rules.mk` with content above  
3. Create `keymap.c` with:
   - Copy layers 0-3 from NEO keymap
   - Create minimal unicode_map (indices 0-42 + dead key chars)
   - Include Phase 1 dead key table only
   - Simplified process_record_keymap

### Step 3: Compile
```bash
cd /Users/chris/Code/RD75
qmk compile -kb wob/rd75 -km neotest
```

Expected result: Firmware size should be ~40-50 KB (vs 74 KB for full NEO)

### Step 4: Flash
```bash
# Enter bootloader mode (ESC + plug USB)
dfu-util -d 36b0:3003 -a 0 -D wob_rd75_neotest.bin
```

### Step 5: Test
- Verify keyboard responds
- Test Layer 0 (base NEO layout)
- Test Layer 1 (shift)
- Test Layer 2 (Mod3 - symbols)
- Test Layer 3 (Mod4 - navigation/numbers)
- Test dead keys (circumflex, grave, acute, diaeresis, tilde)

---

## Expected Outcomes

### If NEO Test Works:
✅ Problem is with layers 4-6 or extended features
- Can gradually add features back to find breaking point
- Likely culprits: Greek letters (layer 4), math symbols (layer 5), function layer (6)

### If NEO Test Fails:
❌ Problem is in core NEO implementation
- Try even simpler version with no Unicode
- Try with only 2 layers (base + shift)
- Issue may be in dead key processing or layer switching

---

## Troubleshooting

### If Still Doesn't Work

**Option A: Ultra-Minimal Test**
- Remove all Unicode (UNICODEMAP_ENABLE = no)
- Remove all dead keys
- Just test NEO letter layout with ASCII
- 2 layers only (base + mod3)

**Option B: Incremental Building**
1. Start with default keymap
2. Add NEO letter positions (no Unicode)
3. Add Unicode gradually
4. Add dead keys
5. Find exact breaking point

**Option C: Debug Output**
Enable console output in rules.mk:
```makefile
CONSOLE_ENABLE = yes
```

Add debug prints in keymap.c to track initialization.

---

## Key Differences from Full NEO

| Feature | Full NEO | NEO Test |
|---------|----------|----------|
| Layers | 7 | 4 |
| EEPROM Size | 2688 | 1152 |
| Unicode Characters | 467 | ~100 |
| Dead Keys | 12 types | 5 types |
| Firmware Size | 74 KB | ~45 KB |
| Greek Letters | Yes | No |
| Math Symbols | Yes | No |
| Polish Enhancement | Yes | No |
| Function Layer | Yes | No |

---

## Success Criteria

1. ✅ Firmware compiles without errors
2. ✅ Firmware size < 60 KB
3. ✅ Keyboard responds after flashing
4. ✅ NEO base layout works (xvlcw...)
5. ✅ Mod3 activates symbol layer
6. ✅ Mod4 activates navigation layer
7. ✅ Dead keys produce accented characters
8. ✅ Unicode characters display correctly

---

## Next Steps After Success

1. Add Layer 4 (Greek letters) gradually
2. Add Layer 5 (Math symbols) gradually
3. Add Layer 6 (Function layer)
4. Add remaining dead keys (Polish enhancement)
5. Compare firmware sizes at each step
6. Identify exact size/complexity threshold

---

## Notes for Implementation

- Keep dead key processing simple (no binary search needed for 5 types)
- Use direct table lookup instead
- Minimize PROGMEM usage
- Consider removing encoder map if size is still too large
- VIA must stay enabled (EEPROM driver requirement)