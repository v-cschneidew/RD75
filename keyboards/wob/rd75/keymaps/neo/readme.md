# NEO 2.0 Layout for RD75

Complete NEO 2.0 keyboard layout implementation for the RD75 with hardware-level Unicode support. Works immediately on Windows, Mac, and Linux without software installation.

## Quick Start

1. **Flash firmware**: `qmk compile -kb wob/rd75 -km neo`
2. **Start typing**: NEO layout is active immediately
3. **Access layers**: Use Mod3 (Caps Lock) and Mod4 (Right Alt)
4. **System functions**: Use Fn (Right Ctrl) for RD75 features

## Features

- **100% NEO specification compliance** - All 6 layers with exact character positioning
- **Plug-and-play compatibility** - No OS configuration required
- **Complete multilingual support** - 9 dead keys for European languages
- **Full RD75 integration** - Wireless, RGB, media controls preserved
- **Hardware Unicode** - All special characters sent directly by keyboard

## Layer Overview

| Layer | Access | Description |
|-------|--------|-------------|
| 0 | Default | NEO base layer (lowercase) |
| 1 | Shift | NEO shift layer (uppercase) |
| 2 | Mod3 | Symbols and punctuation |
| 3 | Mod4 | Navigation and numbers |
| 4 | Mod3+Shift | Greek letters |
| 5 | Mod3+Mod4 | Mathematical symbols |
| 6 | Fn | RD75 system functions |

## Dead Keys

### Essential (Phase 1)
- **Circumflex (ˆ)**: `â ê î ô û` → `Â Ê Î Ô Û`
- **Acute (´)**: `á é í ó ú ý ć ń ś ź` → `Á É Í Ó Ú Ý Ć Ń Ś Ź`
- **Grave (`)**: `à è ì ò ù` → `À È Ì Ò Ù`
- **Diaeresis (¨)**: `ä ë ï ö ü ÿ` → `Ä Ë Ï Ö Ü Ÿ`
- **Tilde (~)**: `ã ñ õ` → `Ã Ñ Õ`

### Extended (Phase 2)
- **Caron (ˇ)**: `č š ž ň ř ď ť ľ ě` → `Č Š Ž Ň Ř Ď Ť Ľ Ě`
- **Cedilla (¸)**: `ç ş ţ ģ ķ ļ ņ ŗ` → `Ç Ş Ţ Ģ Ķ Ļ Ņ Ŗ`
- **Macron (¯)**: `ā ē ī ō ū ȳ` → `Ā Ē Ī Ō Ū Ȳ`
- **Breve (˘)**: `ă ĕ ğ ĭ ŏ ŭ` → `Ă Ĕ Ğ Ĭ Ŏ Ŭ`

### Usage
1. Press dead key (e.g., `´` for acute)
2. Press letter (e.g., `e` or `Shift+E`)
3. Get accented character (`é` or `É`)
4. Press Space after dead key to get the symbol itself

## Language Support

| Language | Characters | Example |
|----------|------------|---------|
| German | `ä ö ü ß Ä Ö Ü` | Müller, Zürich |
| French | `é è à ê â ç É È À Ê Â Ç` | École, Français |
| Spanish | `ñ á í ó ú Ñ Á Í Ó Ú` | España, José |
| Czech | `č š ž ň ř ď ť ľ ě` | Čeština, Škoda |
| Polish | `ć ń ś ź Ć Ń Ś Ź` | Kraków, Gdańsk |
| Turkish | `ç ş ğ Ç Ş Ğ` | Türkçe, İstanbul |

## RD75 Functions (Fn Layer)

### Wireless
- **Fn + 1/2/3**: Bluetooth devices 1-3
- **Fn + 4**: 2.4GHz wireless
- **Fn + 5**: USB wired mode
- **Fn + 0**: Battery status

### Media & System
- **Fn + F1-F12**: Brightness, media controls, volume
- **Fn + Q/W/E**: Unicode mode (Windows/Mac/Linux)
- **Fn + Del**: RGB toggle
- **Fn + End**: EEPROM clear

### RGB Controls
- **Fn + Arrow Keys**: Brightness/speed adjustment
- **Fn + PgUp/PgDn**: Mode/hue cycling
- **Fn + -/=**: Logo brightness
- **Fn + [/]**: Logo speed

## Technical Details

### Architecture
- **Hybrid approach**: ASCII for functional symbols, Unicode for decorative
- **Hardware Unicode**: Direct character transmission for OS compatibility
- **State management**: Robust dead key handling with race condition protection
- **Memory efficient**: Optimized for QMK firmware constraints

### Compatibility
- **Operating Systems**: Windows, macOS, Linux
- **Keyboard Layout**: US layout required on host OS
- **Unicode Modes**: Automatic detection and switching
- **VIA Support**: Full customization available

### Files
- [`keymap.c`](keymap.c) - Main implementation
- [`config.h`](config.h) - Configuration settings
- [`rules.mk`](rules.mk) - Build configuration
- [`neo.txt`](neo.txt) - Official NEO specification

## Development

### Building
```bash
qmk compile -kb wob/rd75 -km neo
```

### Customization
- Modify [`keymap.c`](keymap.c) for layout changes
- Adjust [`config.h`](config.h) for Unicode settings
- Use VIA for runtime customization

### Key Features
- **7 layers**: 6 NEO + 1 Function layer
- **Custom keycodes**: NEO modifiers and dead keys
- **Unicode support**: Multi-OS compatibility
- **State tracking**: Layer and modifier management

## Troubleshooting

### Common Issues
- **No accented characters**: Check Unicode mode (Fn+Q/W/E)
- **Wrong characters**: Ensure US layout on host OS
- **Dead keys not working**: Try different Unicode mode
- **Layer switching issues**: Check modifier key assignments

### Unicode Modes
- **Windows**: Fn+Q (default for most systems)
- **macOS**: Fn+W (for Mac systems)
- **Linux**: Fn+E (for Linux systems)

## Credits

Based on the official NEO 2.0 specification from [neo-layout.org](https://neo-layout.org). Implemented for QMK firmware with full RD75 hardware integration.

## License

GPL v2 - See source files for full license text.