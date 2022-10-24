#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>

// Address constants 
const uint16_t ADDR_MEM_BASE = 0x0000;
const uint16_t ADDR_MEM_MAX = 0x07FF;

const uint16_t ADDR_PPU_REGISTERS_BASE = 0x2000;
const uint16_t ADDR_PPU_REGISTERS_MAX = 0x2007;

const uint16_t ADDR_APU_IO_REGISTERS_BASE = 0x4000;
const uint16_t ADDR_APU_IO_REGISTERS_MAX = 0x4017;

const uint16_t ADDR_APU_IO_FUNC_BASE = 0x4018;
const uint16_t ADDR_APU_IO_FUNC_MAX = 0x401F;

const uint16_t ADDR_CARTIRDGE_REGISTERS_BASE = 0x4020;
const uint16_t ADDR_CARTIRDGE_REGISTERS_MAX = 0xFFFF;

const uint16_t ADDR_CARTRIDGE_BATTERY_BASE = 0x6000;
const uint16_t ADDR_CARTRIDGE_BATTERY_MAX = 0x7FFF;

const uint16_t ADDR_CARTRIDGE_ROM_BASE = 0x8000;
const uint16_t ADDR_CARTRIDGE_ROM_MAX = 0xFFFF;


// Mirror address constants 
const uint16_t ADDR_MEM_MIRROR1_BASE = 0x0800;
const uint16_t ADDR_MEM_MIRROR1_MAX = 0x0FFF;

const uint16_t ADDR_MEM_MIRROR2_BASE = 0x1000;
const uint16_t ADDR_MEM_MIRROR2_MAX = 0x17FF;

const uint16_t ADDR_MEM_MIRROR3_BASE = 0x1800;
const uint16_t ADDR_MEM_MIRROR3_MAX = 0x1FFF;

const uint16_t ADDR_PPU_MIRROR_BASE = 0x2008;
const uint16_t ADDR_PPU_MIRROR_MAX = 0x3FFF;

#endif