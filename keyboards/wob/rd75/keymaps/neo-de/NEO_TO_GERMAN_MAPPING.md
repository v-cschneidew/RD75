# NEO to German Keycode Mapping

## Goal
Create NEO layout by mapping NEO characters to available German keycodes.
- If character exists in German layout: use correct German keycode
- If character does NOT exist: use `KC_NO` (output nothing)

## Available German Keycodes Reference
From `keymap_german.h`:

### Basic Keys
```c
DE_CIRC  // ^ (dead)
DE_1 through DE_0  // 1-0
DE_SS    // ß  
DE_ACUT  // ´ (dead)
DE_MINS  // -
DE_PLUS  // +
DE_HASH  // #
DE_LABK  // <
DE_RABK  // > (shift+<)
```

### Shifted Keys  
```c
DE_DEG   // ° (S(DE_CIRC))
DE_EXLM  // ! (S(DE_1))
DE_DQUO  // " (S(DE_2))
DE_SECT  // § (S(DE_3))
DE_DLR   // $ (S(DE_4))
DE_PERC  // % (S(DE_5))
DE_AMPR  // & (S(DE_6))
DE_SLSH  // / (S(DE_7))
DE_LPRN  // ( (S(DE_8))
DE_RPRN  // ) (S(DE_9))
DE_EQL   // = (S(DE_0))
DE_QUES  // ? (S(DE_SS))
DE_GRV   // ` (dead) (S(DE_ACUT))
DE_ASTR  // * (S(DE_PLUS))
DE_QUOT  // ' (S(DE_HASH))
DE_SCLN  // ; (S(DE_COMM))
DE_COLN  // : (S(DE_DOT))
DE_UNDS  // _ (S(DE_MINS))
```

### AltGr Keys
```c
DE_SUP2  // ² (ALGR(DE_2))
DE_SUP3  // ³ (ALGR(DE_3))
DE_LCBR  // { (ALGR(DE_7))
DE_LBRC  // [ (ALGR(DE_8))
DE_RBRC  // ] (ALGR(DE_9))
DE_RCBR  // } (ALGR(DE_0))
DE_BSLS  // \ (ALGR(DE_SS))
DE_AT    // @ (ALGR(DE_Q))
DE_EURO  // € (ALGR(DE_E))
DE_TILD  // ~ (ALGR(DE_PLUS))
DE_PIPE  // | (ALGR(DE_LABK))
```

---

## Layer 0 (Ebene 1) - Number Row Mapping

NEO spec from neo.txt line 224:
```
ˆ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ `
```

| Position | NEO Char | German Keycode | Notes |
|----------|----------|----------------|-------|
| 1 | ˆ (dead circumflex) | `DE_CIRC` | ✓ Available |
| 2 | 1 | `KC_1` | ✓ Available |
| 3 | 2 | `KC_2` | ✓ Available |
| 4 | 3 | `KC_3` | ✓ Available |
| 5 | 4 | `KC_4` | ✓ Available |
| 6 | 5 | `KC_5` | ✓ Available |
| 7 | 6 | `KC_6` | ✓ Available |
| 8 | 7 | `KC_7` | ✓ Available |
| 9 | 8 | `KC_8` | ✓ Available |
| 10 | 9 | `KC_9` | ✓ Available |
| 11 | 0 | `KC_0` | ✓ Available |
| 12 | - | `DE_MINS` | ✓ Available **FIX: was DE_GRV** |
| 13 | ` (dead grave) | `DE_GRV` | ✓ Available **FIX: was DE_ACUT** |

**Current (WRONG)**: `DE_CIRC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DE_GRV, DE_ACUT`

**Correct**: `DE_CIRC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DE_MINS, DE_GRV`

---

## Layer 1 (Ebene 2 - Shift) - Number Row Mapping

NEO spec from neo.txt line 254:
```
ˇ │ ° │ § │ ℓ │ » │ « │ $ │ € │ „ │ " │ " │ — │ ¸
```

| Position | NEO Char | German Keycode | Notes |
|----------|----------|----------------|-------|
| 1 | ˇ (caron) | `KC_NO` | ❌ Not available |
| 2 | ° (degree) | `DE_DEG` or `S(DE_CIRC)` | ✓ Available **FIX: was S(KC_3)** |
| 3 | § (section) | `DE_SECT` or `S(DE_3)` | ✓ Available |
| 4 | ℓ (script L) | `KC_NO` | ❌ Not available |
| 5 | » | `KC_NO` | ❌ Not in German layout |
| 6 | « | `KC_NO` | ❌ Not in German layout |
| 7 | $ | `DE_DLR` or `S(DE_4)` | ✓ Available |
| 8 | € | `DE_EURO` or `ALGR(DE_E)` | ✓ Available **FIX: was RALT(KC_E)** |
| 9 | „ (German open quote) | `KC_NO` | ❌ Not available |
| 10 | " (left quote) | `KC_NO` | ❌ Not available |
| 11 | " (right quote) | `KC_NO` | ❌ Not available |
| 12 | — (em dash) | `KC_NO` | ❌ Not available |
| 13 | ¸ (cedilla) | `KC_NO` | ❌ Not available |

**Current (WRONG)**: `S(DE_CIRC), S(KC_3), KC_NO, RALT(KC_Y), RALT(KC_X), KC_NO, KC_DLR, RALT(KC_E), DE_DQUO, DE_DQUO, DE_DQUO, S(DE_GRV), S(DE_ACUT)`

**Correct**: `KC_NO, DE_DEG, DE_SECT, KC_NO, KC_NO, KC_NO, DE_DLR, DE_EURO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO`

---

## Layer 2 (Ebene 3 - Mod3) - Number Row Mapping

NEO spec from neo.txt line 267:
```
↻ │ ¹ │ ² │ ³ │ › │ ‹ │ ¢ │ ¥ │ ‚ │ ' │ ' │   │ ˚
```

| Position | NEO Char | German Keycode | Notes |
|----------|----------|----------------|-------|
| 1 | ↻ (rotate) | `KC_NO` | ❌ Not available |
| 2 | ¹ (superscript 1) | `KC_NO` | ❌ Not in German layout |
| 3 | ² (superscript 2) | `DE_SUP2` or `ALGR(DE_2)` | ✓ Available **FIX: was RALT(KC_2)** |
| 4 | ³ (superscript 3) | `DE_SUP3` or `ALGR(DE_3)` | ✓ Available **FIX: was RALT(KC_3)** |
| 5 | › (single right guillemet) | `KC_NO` | ❌ Not available |
| 6 | ‹ (single left guillemet) | `KC_NO` | ❌ Not available |
| 7 | ¢ (cent) | `KC_NO` | ❌ Not available |
| 8 | ¥ (yen) | `KC_NO` | ❌ Not available |
| 9 | ‚ (single low quote) | `KC_NO` | ❌ Not available |
| 10 | ' (right single quote) | `KC_NO` | ❌ Not available (DE_QUOT is different) |
| 11 | ' (right single quote) | `KC_NO` | ❌ Not available |
| 12 | (empty) | `KC_NO` | ✓ Correct |
| 13 | ˚ (ring above) | `KC_NO` | ❌ Not available |

**Current (WRONG)**: `KC_TRNS, KC_NO, RALT(KC_2), RALT(KC_3), RALT(KC_Y), RALT(KC_X), KC_NO, KC_NO, DE_COMM, DE_QUOT, DE_QUOT, KC_SPC, KC_TRNS`

**Correct**: `KC_NO, KC_NO, DE_SUP2, DE_SUP3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO`

---

## Summary of Fixes Needed

### Layer 0 - CRITICAL FIX
Swap positions 12-13:
- Position 12: `DE_GRV` → `DE_MINS`
- Position 13: `DE_ACUT` → `DE_GRV`

### Layer 1 - COMPLETE REWRITE
Replace with mostly KC_NO since most characters don't exist in German layout:
- Position 2: `S(KC_3)` → `DE_DEG`
- Position 3: Keep `S(DE_3)` or use `DE_SECT`
- Position 7: Keep `DE_DLR` or ` S(DE_4)`
- Position 8: `RALT(KC_E)` → `DE_EURO`
- All other positions with special quotes/symbols → `KC_NO`

### Layer 2 - CLEAN UP
Replace incorrect RALT combinations:
- Position 3: `RALT(KC_2)` → `DE_SUP2`  
- Position 4: `RALT(KC_3)` → `DE_SUP3`
- Position 5-11: Wrong characters → `KC_NO`
- Position 12: `KC_SPC` → `KC_NO`
