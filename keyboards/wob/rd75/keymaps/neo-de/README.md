# NEO 2.0 Layout für Wormier RD75

**Plug-and-play NEO 2.0 Firmware** – keine Treiber, keine Software-Installation erforderlich.

> **English Summary**: This is a plug-and-play NEO 2.0 keyboard layout firmware for the Wormier RD75. It implements NEO layers 1-3 (Ebenen 1-3) using the native German keyboard layout. No drivers or software installation required – just flash the firmware and set your OS keyboard layout to German. Includes fixes for Azure Virtual Desktop/RDP compatibility.

---

## Schnellstart

1. **Firmware kompilieren**: `qmk compile -kb wob/rd75 -km neo-de`
2. **Firmware flashen**: Siehe [Installation](#installation) für Details
3. **OS-Tastaturlayout einstellen**: Deutsch (Deutschland)
4. **Fertig!** NEO 2.0 ist einsatzbereit

---

## Was ist implementiert

### ✅ NEO Ebenen 1-3 (Layer 0-2)
- **Ebene 1** (Base): Komplettes NEO-Basislayout (xvlcw...)
- **Ebene 2** (Shift): Großbuchstaben und Sonderzeichen
- **Ebene 3** (Mod3): Alle Symbole und Klammern

### ✅ Dead Keys
- **Funktionieren**: `^` (Zirkumflex), `` ` `` (Gravis), `´` (Akut)
- Beispiele: `^` + e = ê, `` ` `` + e = è, `´` + e = é

### ✅ Mod3-Tasten
- **Caps Lock Position**: Primärer Mod3
- **Backslash-Position** (rechts von `´`): Zweiter Mod3 für einfacheren Zugriff

### ✅ Fn-Layer (Layer 3)
- Media-Steuerung (Play, Pause, Volume)
- RGB-Beleuchtung (Helligkeit, Farbe, Effekte)
- Wireless-Modi (Bluetooth 1-3, 2.4GHz, USB)
- Logo-LED-Steuerung

### ✅ AVD/RDP-Kompatibilität
- Alle AltGr-Symbole funktionieren zuverlässig in Azure Virtual Desktop, Windows RDP und Citrix
- Spezielle Timing-Fixes für virtuelle Desktop-Umgebungen

---

## Bekannte Einschränkungen

### ⚠️ Dead Keys
Das deutsche Tastaturlayout unterstützt nur 3 Dead Keys. NEO 2.0 spezifiziert mehr Dead Keys auf Ebene 2 und 3, die **nicht verfügbar** sind:
- **Ebene 2**: ˇ (Hatschek), ¸ (Cedille), ¨ (Trema)
- **Ebene 3**: ˚ (Ring), ¯ (Makron), ˘ (Breve)

Diese Positionen sind auf `KC_NO` gesetzt.

### ⚠️ Großes ẞ
Das deutsche Tastaturlayout unterstützt kein großes ẞ (U+1E9E). Auf Ebene 2 gibt die ß-Taste das kleine `ß` aus.

### ⚠️ NEO Ebenen 4-6
Nur Ebenen 1-3 sind implementiert. Ebenen 4-6 (Navigation, Griechisch, Mathematik) sind nicht verfügbar.

---

## Tastatur-Layouts

### Ebene 1: NEO Basis
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
├──────┬─────┴─┬───┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┼─────┴─┬───┴──┬──────────┼─────┼─────┼─────┐
│ Ctrl │  Win  │ Alt  │           Space                       │  Fn   │ Ctrl │          │  ←  │  ↓  │  →  │
│      │       │      │                                       │       │      │          │     │     │     │
└──────┴───────┴──────┴───────────────────────────────────────┴───────┴──────┴──────────┴─────┴─────┴─────┘
```

### Ebene 2: Shift (Großbuchstaben)
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
│      │       │      │                                       │       │      │          │     │     │     │
└──────┴───────┴──────┴───────────────────────────────────────┴───────┴──────┴──────────┴─────┴─────┴─────┘

(1) Großes ẞ nicht verfügbar – gibt kleines ß aus
```

### Ebene 3: Mod3 (Symbole)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────────┬─────┐
│ Esc │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │   Del   │Home │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────────┼─────┤
│     │     │  ²  │  ³  │     │     │     │     │     │     │     │     │     │ ⌫ Bkspc │ End │
├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──────┼─────┤
│        │     │  _  │  [  │  ]  │  ^  │  !  │  <  │  >  │  =  │  &  │     │  /  │ Mod3 │PgUp │
│        │     │     │     │     │     │     │     │     │     │     │     │     │      │     │
├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴──────┼─────┤
│  Mod3   │  \  │  /  │  {  │  }  │  *  │  ?  │  (  │  )  │  -  │  :  │  @  │   Enter   │PgDn │
│         │     │     │     │     │     │     │     │     │     │     │     │     ⏎     │     │
├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴────┴─────┼─────┤
│   Shift    │  #  │  $  │  |  │  ~  │  `  │  +  │  %  │  "  │  '  │  ;  │   Shift     │  ↑  │
│            │     │     │     │     │     │     │     │     │     │     │             │     │
├──────┬─────┴─┬───┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┼─────┴─┬───┴──┬──────────┼─────┼─────┼─────┐
│ Ctrl │  Win  │ Alt  │           Space                       │  Fn   │ Ctrl │          │  ←  │  ↓  │  →  │
│      │       │      │                                       │       │      │          │     │     │     │
└──────┴───────┴──────┴───────────────────────────────────────┴───────┴──────┴──────────┴─────┴─────┴─────┘

```

### Layer 3: Fn (Funktionen)
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
│            │     │     │     │     │     │NKRO │     │     │     │     │Logo Hue+    │RGB+ │
│            │     │     │     │     │     │Togl │     │     │     │     │             │ Val │
├──────┬─────┴─┬───┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┼─────┴─┬───┴──┬──────────┼─────┼─────┼─────┐
│Test  │WL Off │      │        Logo Mode                      │  Fn   │      │          │RGB  │RGB- │RGB  │
│Color │       │      │                                       │       │      │          │Spd- │ Val │Spd+ │
└──────┴───────┴──────┴───────────────────────────────────────┴───────┴──────┴──────────┴─────┴─────┴─────┘

Wireless: BLE1/2/3 = Bluetooth 1-3, 2.4G = 2.4GHz, USB = Kabel
RGB: Helligkeit, Sättigung, Farbton, Geschwindigkeit, Modus
Logo: Separate RGB-Steuerung für Logo-LED
NKRO: Umschalten zwischen 6-Key (kompatibel) und Full NKRO (unbegrenzt)
```

**Legende:**
- `dead` = Dead Key (kombiniert mit Buchstaben: ^+e=ê, `+e=è, ´+e=é)
- `Mod3` = Ebene 3 Modifier (Caps Lock oder Backslash-Taste)
- `Fn` = Layer 3 Modifier (rechts von Leertaste)
- `⌫` = Backspace, `⏎` = Enter, `⇥` = Tab vorwärts, `⇤` = Tab rückwärts

---

## Installation

### Voraussetzungen
- **OS-Tastaturlayout**: Deutsch (Deutschland)
  - Windows: Deutsch (Deutschland)
  - macOS: German - Standard
  - Linux: German (de)

### Firmware kompilieren
```bash
qmk compile -kb wob/rd75 -km neo-de
```

Die kompilierte Firmware befindet sich in: `wob_rd75_neo-de.bin`

### Firmware flashen

**Einfache Methode (macOS/Windows/Linux):**
1. Bluetooth ausschalten (kleiner Schalter unter CapsLock)
2. ESC-Taste gedrückt halten
3. USB-Kabel einstecken
4. Nach 3 Sekunden ESC loslassen
5. "No Name" Gerät wird gemountet
6. `wob_rd75_neo-de.bin` auf das gemountete Gerät kopieren
7. Tastatur flasht automatisch

**Alternative (Kommandozeile):**
```bash
# Erst Bootloader-Modus aktivieren (Schritte oben), dann:
dfu-util -d 36b0:3003 -a 0 -D wob_rd75_neo-de.bin
```

### Troubleshooting

**Falsche Zeichen?**
→ OS-Layout auf **Deutsch (Deutschland)** prüfen (nicht Schweiz/Österreich)

**Doppelte Tastenanschläge?**
→ Diese Firmware behebt den Debounce-Bug des Herstellers (DEBOUNCE 5 statt 2)

**AVD/Citrix/RDP?**
→ Alle AltGr-Symbole (@ € [ ] { } | ~ \ ² ³) funktionieren zuverlässig durch spezielle Timing-Fixes

---

## Technische Details

- **Firmware-Größe**: 71.476 Bytes
- **Layers**: 4 (Ebenen 1-3 + Fn-Layer)
- **Dead Keys**: 3 (^, `, ´) auf Ebene 1
- **Mod3-Tasten**: 2 (Caps Lock + Backslash)
- **Debounce**: 5ms (Herstellerfehler korrigiert)
- **AVD/RDP**: Timing-Fixes für virtuelle Desktops

---

## Lizenz

GPL-2.0 (QMK)

---

## Entwicklung

Dieses Projekt ist ein Fork von [womierkeyboard/RD75](https://github.com/womierkeyboard/RD75), speziell angepasst für NEO 2.0.

**Besonderheiten dieser Implementation:**
- Nutzt natives deutsches Tastaturlayout (keine Treiber erforderlich)
- AVD/RDP-kompatibel durch spezielle Timing-Delays
- Zweiter Mod3-Key für bessere Ergonomie
- Debounce-Fix für zuverlässige Tastenanschläge

**Credits:**
- Original RD75 Firmware: [womierkeyboard/RD75](https://github.com/womierkeyboard/RD75)
- NEO Layout Implementation: Christian Schneidewind
- QMK Framework: QMK Contributors