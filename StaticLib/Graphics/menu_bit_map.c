#include "graphical_primitives.h"

const uint8_t menu_bit_map[] = 
{
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    ,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x60,0x63,0xf1,0x81,0x8f,0xc7,0xe3,0x03,0x1f,0x8f,0xc7,0xc3,0xf1,0xf0,0x04
    ,0x40,0x79,0xe3,0xf1,0xc1,0x8f,0xc7,0xe3,0x33,0x1f,0x8f,0xc7,0xe3,0xf1,0xf8,0x04
    ,0x40,0x79,0xe0,0xc1,0xe1,0x8c,0x06,0x03,0x33,0x18,0x0c,0x06,0x63,0x01,0x98,0x04
    ,0x40,0x66,0x60,0xc1,0xf1,0x8c,0x06,0x03,0x33,0x18,0x0c,0x06,0x63,0x01,0x98,0x04
    ,0x40,0x66,0x60,0xc1,0xb9,0x8f,0xc7,0xe3,0x33,0x1f,0x8f,0xc7,0xe3,0xf1,0xf8,0x04
    ,0x40,0x60,0x60,0xc1,0x9d,0x8f,0xc7,0xe3,0x33,0x1f,0x8f,0xc7,0xc3,0xf1,0xf0,0x04
    ,0x40,0x60,0x60,0xc1,0x8f,0x8c,0x00,0x63,0x7b,0x18,0x0c,0x06,0x03,0x01,0xb0,0x04
    ,0x40,0x60,0x60,0xc1,0x87,0x8c,0x00,0x63,0xff,0x18,0x0c,0x06,0x03,0x01,0xb8,0x04
    ,0x40,0x60,0x63,0xf1,0x83,0x8f,0xc7,0xe3,0xcf,0x1f,0x8f,0xc6,0x03,0xf1,0x98,0x04
    ,0x40,0x60,0x63,0xf1,0x81,0x8f,0xc7,0xe1,0x86,0x1f,0x8f,0xc6,0x03,0xf1,0x98,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x1c,0x40,0xc4,0x80,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x12,0x41,0x24,0x80,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x12,0x41,0x24,0x80,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x1c,0x41,0xe7,0x80,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x10,0x41,0x20,0x80,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x10,0x79,0x27,0x80,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x1c,0x73,0xcf,0x38,0xe4,0x90,0x72,0x40,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x12,0x22,0x08,0x11,0x04,0x90,0x22,0x40,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x12,0x22,0x08,0x11,0x04,0x90,0x22,0x40,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x12,0x23,0x8e,0x11,0x04,0x90,0x23,0xc0,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x12,0x22,0x08,0x11,0x04,0x90,0x20,0x40,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x1c,0x72,0x08,0x38,0xe3,0x1e,0x23,0xc0,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04
    ,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc
    ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

};