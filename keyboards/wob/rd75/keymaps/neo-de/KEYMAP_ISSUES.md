# NEO neotest2 Keymap Issues Analysis

## Problem Report
The number row and some other keys are incorrectly mapped compared to the official NEO 2.0 specification.

## Reference Documents
- **NEO Specification**: [`neo.txt`](../neo/neo.txt) lines 221-276
- **Current Keymap**: [`keymap.c`](keymap.c) lines 31-58
- **Available Keycodes**: 
  - German: [`keymap_german.h`](../../../../../quantum/keymap_extras/keymap_german.h)
  - NEO2: [`keymap_neo2.h`](../../../../../quantum/keymap_extras/keymap_neo2.h)

---

## Critical Issues Found

### Layer 0 (Ebene 1 - Base Layer)

#### Number Row - Positions After 0

**Current (WRONG)**:
```c
DE_CIRC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DE_GRV, DE_ACUT
```

**Expected per neo.txt line 224**:
```
ˆ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ `
```

**Issue**: Positions 12 and 13 are swapped!
- Position 12: Currently `DE_GRV` (grave `) but should be `DE_MINS` (minus -)
- Position 13: Currently `DE_ACUT` (acute ´) but should be `DE_GRV` (grave `)

**Fix**:
```c
DE_CIRC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DE_MINS, DE_GRV
```

---

### Layer 1 (Ebene 2 - Shift Layer)

#### Number Row Issues

**Current (line 43)**:
```c
S(DE_CIRC), S(KC_3), KC_NO, RALT(KC_Y), RALT(KC_X), KC_NO, KC_DLR, RALT(KC_E), DE_DQUO, DE_DQUO, DE_DQUO, S(DE_GRV), S(DE_ACUT)
```

**Expected per neo.txt line 254**:
```
ˇ │ ° │ § │ ℓ │ » │ « │ $ │ € │ „ │ " │ " │ — │ ¸
```

**Issues**:
1. Position 1: `S(DE_CIRC)` gives `°` ✓ CORRECT
2. Position 2: `S(KC_3)` gives `§` ✓ CORRECT  
3. Position 3: `KC_NO` should be **ℓ** (script lowercase L) ❌ MISSING - needs Unicode
4. Position 4: `RALT(KC_Y)` gives `»` ✓ CORRECT
5. Position 5: `RALT(KC_X)` gives `«` ✓ CORRECT
6. Position 6: `KC_NO` should be Empty/Nothing ❌ - This seems intentionally empty in your keymap
7. Position 7: `KC_DLR` gives `$` ✓ CORRECT
8. Position 8: `RALT(KC_E)` gives `€` ✓ CORRECT
9. Position 9: `DE_DQUO` is wrong - should be **„** (German opening quote U+201E) ❌ needs Unicode
10. Position 10: `DE_DQUO` is wrong - should be **"** (left double quote U+201C) ❌ needs Unicode  
11. Position 11: `DE_DQUO` is wrong - should be **"** (right double quote U+201D) ❌ needs Unicode
12. Position 12: `S(DE_GRV)` gives `` ` `` but should be **—** (em dash U+2014) ❌ needs Unicode
13. Position 13: `S(DE_ACUT)` gives `` ` `` but should be **¸** (cedilla U+00B8) ❌ needs Unicode

**Constraint**: We cannot use Unicode characters directly - must use German keycodes only.

**Partial Fix** (positions that can be fixed with German keycodes):
- Positions 12-13 need to swap like Layer 0: After fixing Layer 0, shifting those keys gives the base layer shifted equivalents

**Note**: Positions 3, 9, 10, 11, 12 require Unicode which we cannot use. These will remain approximations.

---

### Layer 2 (Ebene 3 - Mod3 Layer)

#### Number Row Issues

**Current (line 53)**:
```c
KC_TRNS, KC_NO, RALT(KC_2), RALT(KC_3), RALT(KC_Y), RALT(KC_X), KC_NO, KC_NO, DE_COMM, DE_QUOT, DE_QUOT, KC_SPC, KC_TRNS
```

**Expected per neo.txt line 267**:
```
↻ │ ¹ │ ² │ ³ │ › │ ‹ │ ¢ │ ¥ │ ‚ │ ' │ ' │   │ ˚
```

**Issues**:
1. Position 1: `KC_TRNS` should be **↻** (rotate) ❌ cannot implement without Unicode/custom
2. Position 2: `KC_NO` should be **¹** (superscript 1) - `RALT(KC_1)` might work? Need to test
3. Position 3: `RALT(KC_2)` gives `²` ✓ CORRECT
4. Position 4: `RALT(KC_3)` gives `³` ✓ CORRECT
5. Position 5: `RALT(KC_Y)` gives `»` but should be **›** (single right guillemet U+203A) ❌ wrong character!
6. Position 6: `RALT(KC_X)` gives `«` but should be **‹** (single left guillemet U+2039) ❌ wrong character!
7. Position 7: `KC_NO` should be **¢** (cent) - may be available as `RALTG(KC_C)` or similar
8. Position 8: `KC_NO` should be **¥** (yen) - may be available
9. Position 9: `DE_COMM` gives `,` but should be **‚** (single low quote U+201A) ❌ needs Unicode
10. Position 10: `DE_QUOT` gives `'` - this might be close enough ✓ APPROXIMATE
11. Position 11: `DE_QUOT` gives `'` - might be close ✓ APPROXIMATE
12. Position 12: `KC_SPC` gives space but should be empty/nothing ❌ 
13. Position 13: `KC_TRNS` should be **˚** (ring above dead key) ❌ cannot implement

---

## Summary of Fixable Issues

### Immediate Fixes (Can be done with German keycodes):

1. **Layer 0 - Swap positions 12 & 13**:
   - Change `DE_GRV, DE_ACUT` → `DE_MINS, DE_GRV`

2. **Layer 3 - Position 2**:
   - Test if `RALT(KC_1)` produces `¹` (superscript 1)

3. **Layer 3 - Positions 7-8**:
   - Research if cent (¢) and yen (¥) are available via RALT combinations

4. **Layer 3 - Position 12**:
   - Change `KC_SPC` to `KC_NO` (should be empty)

### Cannot Fix (Require Unicode):
- Layer 1: ℓ, „, ", ", —, ¸
- Layer 2: ↻, ›, ‹, ‚, ˚

---

## Recommendations

### Option 1: Minimal Fix (German Keycodes Only)
Fix only what can be fixed with native German keycodes:
- Swap Layer 0 positions 12-13
- Remove Layer 3 position 12 (change Space to KC_NO)
-Accept approximations for characters that need Unicode

### Option 2: Hybrid Approach  
- Use German keycodes where possible
- Accept that some special characters cannot be represented perfectly
- Document which keys produce approximations vs exact NEO spec

### Option 3: Use keymap_neo2.h
- Switch from `keymap_german.h` to `keymap_neo2.h`
- This provides proper NEO layer definitions
- But may require more extensive keymap rewrite

---

## Next Steps

1. Apply minimal fixes to Layer 0 (swap DE_GRV/DE_ACUT positions)
2. Test current behavior of problematic keys
3. Research RALT combinations for additional symbols
4. Document final character mapping vs NEO spec
5. Update user documentation with known limitations
