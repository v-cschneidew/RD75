# NEO Test Keymap Rules - Minimal configuration (NO UNICODE - Plug and Play)

# Copy VIA keymap configuration that works
VIA_ENABLE = yes
EEPROM_DRIVER = custom

# NO Unicode - using native German keyboard layout only
UNICODEMAP_ENABLE = no
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