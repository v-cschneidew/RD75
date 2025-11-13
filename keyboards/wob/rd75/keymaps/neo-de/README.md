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
| Shift | 1 | Uppercase + °§$€ |
| Mod3 (Caps) | 2 | Symbols: []{}()<>!?@#$%&*/+=-\|~²³ |
| Fn (right of space) | 3 | RGB, Media, Wireless |

## Dead Keys

Combine with letters for accents:
- `^` + a → â, e → ê
- `` ` `` + e → è, a → à  
- `´` + e → é, a → á
- `~` + n → ñ, a → ã

## Features

✅ 3 NEO layers (Ebenen 1-3) fully working  
✅ Dead keys for accented characters  
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

## Technical Details

- **Firmware Size**: 71,000 bytes
- **VIA**: Enabled
- **Layers**: 4 (0-3)
- **Dead Keys**: Native German layout support

## License

GPL-2.0 (QMK)