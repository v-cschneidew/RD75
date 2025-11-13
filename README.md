# RD75 QMK Firmware - NEO 2 Layout Support

This is a fork of the official RD75 QMK firmware with **NEO 2.0 keyboard layout** support (Erste 3 Ebenen).

## 🎯 Features

- ✅ **NEO 2.0 Layout** - Erste 3 Ebenen (Layers 1-3) fully implemented
- ✅ **Plug & Play** - No drivers required, uses native German keyboard layout
- ✅ **Fixed Debounce** - Resolved manufacturer's double keystroke bug (2ms → 5ms)
- ✅ **Dead Keys** - Full support for accented characters (^`´¨~)
- ✅ **VIA Compatible** - Layer switching and customization via VIA

## 🚀 Quick Start

### 1. Build Firmware
```bash
# Clone repository
git clone https://github.com/v-cschneidew/RD75.git
cd RD75

# Compile neo-de keymap
qmk compile -kb wob/rd75 -km neo-de
```

### 2. Flash Firmware

**Easy Method (macOS/Windows/Linux):**
1. Turn off Bluetooth using the small switch under the CapsLock key
2. Hold down ESC key
3. Connect keyboard via USB cable
4. After 3 seconds, release ESC key
5. A "No Name" device will mount
6. Copy `wob_rd75_neo-de.bin` to the mounted device
7. Keyboard will flash automatically

**Alternative (Command Line):**
```bash
# Enter bootloader mode first (steps above), then:
dfu-util -d 36b0:3003 -a 0 -D wob_rd75_neo-de.bin
```

### 3. Set OS Keyboard Layout
Set your operating system keyboard layout to:
- **Windows**: Deutsch (Deutschland)
- **macOS**: German - Standard
- **Linux**: German (de)

### 4. Start Typing!
Your keyboard now uses the NEO 2.0 layout.


## 📚 NEO Layout Overview

The NEO layout improves typing ergonomics for German and programming:

| Layer | Activation | Description |
|-------|-----------|-------------|
| Ebene 1 | Default | Base layer (xvlcw...) |
| Ebene 2 | Shift | Uppercase + special chars |
| Ebene 3 | Mod3 (Caps Lock) | Symbols: []{}()<>!?@#$%&*/+=\| |
| Function | Fn (right of space) | RGB, Media, Wireless |

For detailed layout information, see [keyboards/wob/rd75/keymaps/neo-de/README.md](keyboards/wob/rd75/keymaps/neo-de/README.md)

## 🐛 Bug Fixes

This firmware fixes a critical bug in the manufacturer's original firmware:

**Double Keystroke Issue**: The original firmware had `DEBOUNCE 2` which was too aggressive, causing switch bouncing to register as multiple keystrokes. This has been corrected to `DEBOUNCE 5` (QMK standard).

## 👤 Credits

- **NEO Layout Implementation**: Christian Schneidewind
- **Original RD75 Firmware**: Finalkey / LiWenLiu
- **QMK Framework**: QMK Contributors

## 📄 License

GPL-2.0 (QMK License)

---

## 🔗 Links

- **NEO Layout Official**: https://neo-layout.org/
- **QMK Firmware**: https://qmk.fm/
- **Original Manufacturer Firmware**: https://github.com/Finalkey/RD75

---

## ⚙️ Original QMK Documentation

For general QMK documentation, see [docs.qmk.fm](https://docs.qmk.fm)
