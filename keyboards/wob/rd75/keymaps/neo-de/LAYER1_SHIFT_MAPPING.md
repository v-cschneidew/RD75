# Layer 1 (Ebene 2) Mapping Strategy

## How It Works

When user presses **Shift + Key**:
1. Firmware detects shift → Activates Layer 1
2. Firmware sends: **BASE_KEY** (from Layer 1) + **Shift modifier**
3. OS (German layout) receives: Shift + BASE_KEY
4. OS produces: **Result character**

## Number Row Mapping

| Pos | NEO Ebene 2 | German: Shift+? = Result | Layer 1 Code | Works? |
|-----|-------------|--------------------------|--------------|--------|
| 1 | ˇ (caron) | N/A | `KC_NO` | ❌ Not in German |
| 2 | ° (degree) | Shift + ^ = ° | `DE_CIRC` | ✅ Yes! |
| 3 | § (section) | Shift + 3 = § | `KC_3` | ✅ Yes! |
| 4 | ℓ (script L) | N/A | `KC_NO` | ❌ Not in German |
| 5 | » | N/A | `KC_NO` | ❌ Not in German |
| 6 | « | N/A | `KC_NO` | ❌ Not in German |
| 7 | $ (dollar) | Shift + 4 = $ | `KC_4` | ✅ Yes! |
| 8 | € (euro) | N/A direct | `KC_NO` | ❌ Not shift-accessible |
| 9 | „ (German open quote) | N/A | `KC_NO` | ❌ Not in German |
| 10 | " (left quote) | N/A | `KC_NO` | ❌ Not in German |
| 11 | " (right quote) | N/A | `KC_NO` | ❌ Not in German |
| 12 | — (em dash) | N/A | `KC_NO` | ❌ Not in German |
| 13 | ¸ (cedilla) | N/A | `KC_NO` | ❌ Not in German |

## Layer 1 Number Row Solution

**Current (wrong)**:
```c
KC_NO, DE_DEG, DE_SECT, KC_NO, KC_NO, KC_NO, DE_DLR, DE_EURO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
```

**Correct (base keys that work with shift)**:
```c
KC_NO, DE_CIRC, KC_3, KC_NO, KC_NO, KC_NO, KC_4, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
```

**Result when user presses Shift+1 through Shift+0,-,`**:
- Shift+1: Nothing (caron not available)
- Shift+2: ° (degree) ✅
- Shift+3: § (section) ✅
- Shift+4: Nothing (script L not available)
- Shift+5: Nothing (guillemet not available)
- Shift+6: Nothing (guillemet not available)
- Shift+7: $ (dollar) ✅
- Shift+8: Nothing (€ not shift-accessible in German)
- Shift+9 through Shift+`: Nothing (characters not available)

## Letters Row - Similar Logic

For each letter position, find which German base key + Shift produces the desired uppercase letter.

Example for "X" position (first letter key):
- NEO Ebene 2: X (uppercase X)
- German: Shift + x = X
- Layer 1: `KC_X`

This is straightforward for letters since German and NEO both use A-Z.

## Summary

Out of 13 number row positions in NEO Ebene 2:
- ✅ **3 work**: °, §, $
- ❌ **10 don't work**: Characters not available via Shift in German layout

**This is the fundamental limitation** of implementing NEO with German OS layout.
