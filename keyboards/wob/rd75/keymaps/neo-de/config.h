/* Copyright 2023 Yiancar-Designs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// EEPROM configuration - MATCH DEFAULT to avoid initialization issues
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR  1151
#define EEPROM_SIZE 1152

#define FEE_PAGE_SIZE (0x200)
#define FEE_PAGE_COUNT (8)

#define FEE_PAGE_BASE_ADDRESS (0x1F000)
#define FEE_MCU_FLASH_SIZE (0x1000)

#define EECONFIG_USER_DATA_SIZE 4
#define EECONFIG_KB_DATA_SIZE 1
#define TRANSIENT_EEPROM_SIZE 4096

// NO Unicode - using native German keyboard layout only for plug-and-play

// Use 4 layers - HARDWARE MAXIMUM (VIA + 1152 byte EEPROM)
// Layer 0: Base, Layer 1: Shift, Layer 2: Mod3, Layer 3: Function (RGB/wireless)
// Mod4 navigation removed due to EEPROM limit - use Function layer instead
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// Enable tap dance for dead keys
#define TAPPING_TERM 200