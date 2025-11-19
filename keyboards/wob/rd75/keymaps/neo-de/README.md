# NEO-DE Keymap

Plug-and-play NEO 2.0 layout for WOB RD75. **No drivers or software required.**

## Quick Start

1. **Set OS keyboard layout**: German - Standard
2. **Flash firmware**: `qmk flash -kb wob/rd75 -km neo-de`  
3. **Start typing**: NEO layout ready!

## Requirements

**OS Keyboard Layout**: German - Standard (Deutschland)
- ✅ Windows: Deutsch (Deutschland)
- ✅ macOS: German - Standard
- ✅ Linux: German (de)

## Layers

| Key | Layer | Description |
|-----|-------|-------------|
| (none) | 0 | NEO base (xvlcw...) |
| Shift | 1 | Uppercase + °§$€ (Note: ẞ→ß due to layout limitation) |
| Mod3 (Caps or backslash key) | 2 | Symbols: []{}()<>!?@#$%&*/+=-\|~²³ |
| Fn (right of space) | 3 | RGB, Media, Wireless |

**Hardware Adaptation**: The backslash key (right of ´) has been remapped to a second Mod3 key for easier access to Layer 2 symbols.

## Keyboard Layout Reference

### Layer 0: NEO Base Layer (Ebene 1)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────────┬─────┐
│ Esc │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │   Del   │Home │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────────┼─────┤
│  ^  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  `  │ ⌫ Bkspc │ End │
│dead │     │     │     │     │     │     │     │     │     │     │     │dead │         │     │
├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──────┼─────┤
│  Tab⇥  │  x  │  v  │  l  │  c  │  w  │  k  │  h  │  g  │  f  │  q  │  ß  │  ´  │ Mod3 │PgUp │
│        │     │     │     │     │     │     │     │     │     │     │     │dead │      │     │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴──────┼─────┤
│  Mod3   │  u  │  i  │  a  │  e  │  o  │  s  │  n  │  r  │  t  │  d  │  y  │   Enter   │PgDn │
│         │     │     │     │     │     │     │     │     │     │     │     │     ⏎     │     │
├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴────┴─────┼─────┤
│   Shift    │  ü  │  ö  │  ä  │  p  │  z  │  b  │  m  │  ,  │  .  │  j  │   Shift     │  ↑  │
│            │     │     │     │     │     │     │     │     │     │     │             │     │
├──────┬─────┴─┬───┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┼─────┴─┬───┴──┬──────────┼─────┼─────┼─────┐
│ Ctrl │  Win  │ Alt  │           Space                       │  Fn   │ Ctrl │          │  ←  │  ↓  │  →  │
│      │       │      │                                       │       │      │          │     │     │     │
└──────┴───────┴──────┴───────────────────────────────────────┴───────┴──────┴──────────┴─────┴─────┴─────┘
```

### Layer 1: Shift Layer (Ebene 2)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────────┬─────┐
│ Esc │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │   Del   │Home │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────────┼─────┤
│     │  !  │  "  │  §  │     │     │  $  │  €  │     │     │     │     │     │ ⌫ Bkspc │ End │
├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──────┼─────┤
│ Tab⇤   │  X  │  V  │  L  │  C  │  W  │  K  │  H  │  G  │  F  │  Q  │  ß  │  ~  │ Mod3 │PgUp │
│        │     │     │     │     │     │     │     │     │     │     │ (1) │     │      │     │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴──────┼─────┤
│  Mod3   │  U  │  I  │  A  │  E  │  O  │  S  │  N  │  R  │  T  │  D  │  Y  │   Enter   │PgDn │
│         │     │     │     │     │     │     │     │     │     │     │     │     ⏎     │     │
├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴────┴─────┼─────┤
│   Shift    │  Ü  │  Ö  │  Ä  │  P  │  Z  │  B  │  M  │  –  │  •  │  J  │   Shift     │  ↑  │
├──────┬─────┴─┬───┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┼─────┴─┬───┴──┬──────────┼─────┼─────┼─────┐
│ Ctrl │  Win  │ Alt  │           Space                       │  Fn   │ Ctrl │          │  ←  │  ↓  │  →  │
└──────┴───────┴──────┴───────────────────────────────────────┴───────┴──────┴──────────┴─────┴─────┴─────┘

(1) Capital ẞ not available in German layout - outputs lowercase ß instead
```

### Layer 2: Mod3 Symbols (Ebene 3)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────────┬─────┐
│ Esc │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │   Del   │Home │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────────┼─────┤
│     │     │  ²  │  ³  │     │     │     │     │     │     │     │     │     │ ⌫ Bkspc │ End │
├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──────┼─────┤
│        │     │  _  │  [  │  ]  │  ^  │  !  │  <  │  >  │  =  │  &  │     │  /  │ Mod3 │PgUp │
│        │     │     │     │     │ (2) │     │     │     │     │     │     │     │      │     │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴──────┼─────┤
│  Mod3   │  \  │  /  │  {  │  }  │  *  │  ?  │  (  │  )  │  -  │  :  │  @  │   Enter   │PgDn │
│         │     │     │     │     │     │     │     │     │     │     │     │     ⏎     │     │
├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴────┴─────┼─────┤
│   Shift    │  #  │  $  │  |  │  ~  │  `  │  +  │  %  │  "  │  '  │  ;  │   Shift     │  ↑  │
│            │     │     │     │     │ (2) │     │     │     │     │     │             │     │
├──────┬─────┴─┬───┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┼─────┴─┬───┴──┬──────────┼─────┼─────┼─────┐
│ Ctrl │  Win  │ Alt  │           Space                       │  Fn   │ Ctrl │          │  ←  │  ↓  │  →  │
└──────┴───────┴──────┴───────────────────────────────────────┴───────┴──────┴──────────┴─────┴─────┴─────┘

(2) Outputs literal character immediately (not dead key) - see Dead Keys section
```

### Layer 3: Function Layer (Fn)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────────┬─────┐
│     │Bri- │Bri+ │Mail │Calc │Calc │Media│Prev │Play │Next │Mute │Vol- │Vol+ │RGB Togl │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────────┼─────┤
│     │BLE1 │BLE2 │BLE3 │2.4G │ USB │     │     │     │     │     │Logo-│Logo+│Battery  │Clear│
│     │     │     │     │     │     │     │     │     │     │     │ Val │ Val │  Info   │EPRM │
├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──────┼─────┤
│        │     │     │     │     │     │     │     │     │     │     │Logo │Logo │ RGB  │RGB  │
│        │     │     │     │     │     │     │     │     │     │     │Spd- │Spd+ │ Mode │Sat+ │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴──────┼─────┤
│         │     │     │RGB- │RGB+ │     │     │     │     │     │Logo │Logo │ RGB Hue+  │RGB  │
│         │     │     │ Val │ Val │     │     │     │     │     │Sat- │Sat+ │           │Sat- │
├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴────┴─────┼─────┤
│            │     │     │     │     │     │6xN  │     │     │     │     │Logo Hue+    │RGB+ │
│            │     │     │     │     │     │     │     │     │     │     │             │ Val │
├──────┬─────┴─┬───┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┼─────┴─┬───┴──┬──────────┼─────┼─────┼─────┐
│Test  │WL Off │      │        Logo Mode                      │  Fn   │      │          │RGB  │RGB- │RGB  │
│Color │       │      │                                       │       │      │          │Spd- │ Val │Spd+ │
└──────┴───────┴──────┴───────────────────────────────────────┴───────┴──────┴──────────┴─────┴─────┴─────┘

Wireless Modes: BLE1/BLE2/BLE3 = Bluetooth devices 1-3, 2.4G = 2.4GHz wireless, USB = wired mode
RGB Controls: Brightness, Saturation, Hue, Speed, Mode cycling
Logo Controls: Separate RGB controls for keyboard logo LED
6xN: Toggle NKRO (N-Key Rollover) - switches between 6-key mode (compatible) and full NKRO (unlimited keys)
```

**Legend:**
- `dead` = Dead key (combine with letter for accents: ^+e=ê, `+e=è, ´+e=é)
- `Mod3` = Layer 2 modifier (Caps Lock position or backslash key)
- `Fn` = Layer 3 modifier (right of spacebar)
- `⌫` = Backspace
- `⏎` = Enter
- `⇥` = Tab forward
- `⇤` = Tab backward

## Dead Keys

**IMPORTANT**: German keyboard layout only supports 3 dead keys on Layer 0:
- `^` (Circumflex) + a → â, e → ê
- `` ` `` (Grave) + e → è, a → à  
- `´` (Acute) + e → é, a → á

**Limitations**: 
1. NEO 2.0 specifies additional dead keys on Layer 1 (Shift) and Layer 2 (Mod3) that are **not available** in the German keyboard layout:
   - Layer 1: ˇ (Caron), ¸ (Cedilla), ¨ (Trema) - **not functional**
   - Layer 2: ˚ (Ring), ¯ (Macron), ˘ (Breve) - **not functional**
   - These positions are set to `KC_NO` to avoid confusion.

2. **Capital ẞ not available**: The German keyboard layout does not support the capital ẞ (U+1E9E). On Layer 1 (Shift), the ß key outputs lowercase `ß` instead of uppercase `ẞ`. This is a limitation of the standard German keyboard layout.

If you need these dead keys or capital ẞ, you would need to use a full NEO driver installation instead of this plug-and-play firmware.

## Features

✅ 3 NEO layers (Ebenen 1-3) implemented  
✅ 3 dead keys (^, `, ´) for accented characters on Layer 0  
⚠️ Additional NEO dead keys not available (German layout limitation)  
⚠️ Capital ẞ not available (outputs lowercase ß instead)  
✅ Second Mod3 key on backslash position for easier access  
✅ Superscripts ²³ (Layer 2)  
✅ All brackets and symbols  
✅ Function layer for keyboard controls  
✅ No software installation needed  
✅ Works on locked-down systems (AVD/Citrix)

## Installation

### Build
```bash
qmk compile -kb wob/rd75 -km neo-de
```

### Flash
```bash
# 1. Enter bootloader: Hold ESC while plugging USB
# 2. Flash:
dfu-util -d 36b0:3003 -a 0 -D wob_rd75_neo-de.bin
```

## Troubleshooting

**Wrong characters appearing?**
→ Verify OS layout is **German - Standard** (not Swiss/Austrian variant)

**Double keystrokes appearing?**
→ This firmware includes a fix for the manufacturer's debounce bug. If you experience double keystrokes with the original firmware, this NEO-DE keymap includes the corrected `DEBOUNCE 5` setting (manufacturer default was too aggressive at 2ms).

**Using in AVD/Citrix/RDP environments?**
→ This firmware includes timing fixes for virtual desktop environments. All AltGr symbols (@ € [ ] { } | ~ \ ² ³) work reliably in Azure Virtual Desktop, Windows RDP, and Citrix by adding 20ms delays around modifier keys to compensate for RDP protocol timing issues.

## Technical Details

- **Firmware Size**: 71,000 bytes
- **VIA**: Enabled
- **Layers**: 4 (0-3)
- **Dead Keys**: 3 dead keys (^, `, ´) on Layer 0 only
- **Limitations**: 
  - German layout does not support all NEO dead keys
  - Capital ẞ not available (outputs lowercase ß)
  - Backslash key remapped to second Mod3

## License

GPL-2.0 (QMK)