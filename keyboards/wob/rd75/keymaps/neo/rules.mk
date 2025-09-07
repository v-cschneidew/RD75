# NEO 2.0 Keymap Rules

# Copy VIA keymap configuration that works
VIA_ENABLE = yes
EEPROM_DRIVER = custom

# Enable Unicode support for special NEO characters
UNICODE_ENABLE = yes

# Disable problematic features for now
COMBO_ENABLE = no
ENCODER_MAP_ENABLE = no

# Enable tap dance if needed for complex key behaviors
TAP_DANCE_ENABLE = no

# Enable extra keys for German layout
EXTRAKEY_ENABLE = yes

# Disable features we don't need to save space
MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no

# Keep RGB and encoder support from base keyboard
RGB_MATRIX_ENABLE = yes
ENCODER_ENABLE = yes