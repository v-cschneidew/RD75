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
// EEPROM configuration for custom driver (7 layers: 6 NEO + 1 function)
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR  2687
#define EEPROM_SIZE 2688

#define FEE_PAGE_SIZE (0x200)
#define FEE_PAGE_COUNT (8)

#define FEE_PAGE_BASE_ADDRESS (0x1F000)
#define FEE_MCU_FLASH_SIZE (0x1000)

#define EECONFIG_USER_DATA_SIZE 4
#define EECONFIG_KB_DATA_SIZE 1
#define TRANSIENT_EEPROM_SIZE 4096

// Enable Unicode support for NEO special characters - ALL OPERATING SYSTEMS
// Uses WinCompose on Windows for better reliability, Mac and Linux native support
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_MACOS, UNICODE_MODE_LINUX

// Use 7 layers for complete NEO 2.0 functionality + RD75 function layer
#define DYNAMIC_KEYMAP_LAYER_COUNT 7

// Enable tap dance for dead keys if needed
#define TAPPING_TERM 200
