// This file is part of the sfelib-cpp project
//
//	Copyright (C) 2022 NumGeom Group at Stony Brook University
//
// This file was generated from update_etypeenum4cpp on 21-Apr-2022

#ifndef SFE_ELEMENTTYPES_HPP
#define SFE_ELEMENTTYPES_HPP

namespace sfe {

enum ElementTypes {
  NODE_1       = 1,    // 0b00000001
  SHAPE_NODE   = 0,    // 0b00000000
  BAR_2        = 36,   // 0b00100100
  BAR_3        = 40,   // 0b00101000
  BAR_4        = 44,   // 0b00101100
  BAR_5        = 48,   // 0b00110000
  BAR_6        = 52,   // 0b00110100
  BAR_7        = 56,   // 0b00111000
  BAR_FEK_2    = 36,   // 0b00100100
  BAR_FEK_3    = 40,   // 0b00101000
  BAR_FEK_4    = 45,   // 0b00101101
  BAR_FEK_5    = 49,   // 0b00110001
  BAR_FEK_6    = 53,   // 0b00110101
  BAR_FEK_7    = 57,   // 0b00111001
  BAR_GL_2     = 36,   // 0b00100100
  BAR_GL_3     = 40,   // 0b00101000
  BAR_GL_4     = 45,   // 0b00101101
  BAR_GL_5     = 49,   // 0b00110001
  BAR_GL_6     = 53,   // 0b00110101
  BAR_GL_7     = 57,   // 0b00111001
  SHAPE_BAR    = 1,    // 0b00000001
  QUAD_16      = 108,  // 0b01101100
  QUAD_25      = 112,  // 0b01110000
  QUAD_36      = 116,  // 0b01110100
  QUAD_4       = 100,  // 0b01100100
  QUAD_49      = 120,  // 0b01111000
  QUAD_9       = 104,  // 0b01101000
  QUAD_FEK_16  = 109,  // 0b01101101
  QUAD_FEK_25  = 113,  // 0b01110001
  QUAD_FEK_36  = 117,  // 0b01110101
  QUAD_FEK_4   = 100,  // 0b01100100
  QUAD_FEK_49  = 121,  // 0b01111001
  QUAD_FEK_9   = 104,  // 0b01101000
  QUAD_GL_16   = 109,  // 0b01101101
  QUAD_GL_25   = 113,  // 0b01110001
  QUAD_GL_36   = 117,  // 0b01110101
  QUAD_GL_4    = 100,  // 0b01100100
  QUAD_GL_49   = 121,  // 0b01111001
  QUAD_GL_9    = 104,  // 0b01101000
  SHAPE_QUAD   = 3,    // 0b00000011
  SHAPE_TRI    = 2,    // 0b00000010
  TRI_10       = 76,   // 0b01001100
  TRI_15       = 80,   // 0b01010000
  TRI_21       = 84,   // 0b01010100
  TRI_28       = 88,   // 0b01011000
  TRI_3        = 68,   // 0b01000100
  TRI_6        = 72,   // 0b01001000
  TRI_FEK_10   = 77,   // 0b01001101
  TRI_FEK_15   = 82,   // 0b01010010
  TRI_FEK_21   = 86,   // 0b01010110
  TRI_FEK_28   = 90,   // 0b01011010
  TRI_FEK_3    = 68,   // 0b01000100
  TRI_FEK_6    = 72,   // 0b01001000
  TRI_GL_10    = 77,   // 0b01001101
  TRI_GL_15    = 81,   // 0b01010001
  TRI_GL_21    = 85,   // 0b01010101
  TRI_GL_28    = 89,   // 0b01011001
  TRI_GL_3     = 68,   // 0b01000100
  TRI_GL_6     = 72,   // 0b01001000
  HEXA_125     = 240,  // 0b11110000
  HEXA_216     = 244,  // 0b11110100
  HEXA_27      = 232,  // 0b11101000
  HEXA_343     = 248,  // 0b11111000
  HEXA_64      = 236,  // 0b11101100
  HEXA_8       = 228,  // 0b11100100
  HEXA_FEK_125 = 241,  // 0b11110001
  HEXA_FEK_216 = 245,  // 0b11110101
  HEXA_FEK_27  = 232,  // 0b11101000
  HEXA_FEK_343 = 249,  // 0b11111001
  HEXA_FEK_64  = 237,  // 0b11101101
  HEXA_FEK_8   = 228,  // 0b11100100
  HEXA_GL_125  = 241,  // 0b11110001
  HEXA_GL_216  = 245,  // 0b11110101
  HEXA_GL_27   = 232,  // 0b11101000
  HEXA_GL_343  = 249,  // 0b11111001
  HEXA_GL_64   = 237,  // 0b11101101
  HEXA_GL_8    = 228,  // 0b11100100
  PRISM_18     = 200,  // 0b11001000
  PRISM_40     = 204,  // 0b11001100
  PRISM_6      = 196,  // 0b11000100
  PRISM_75     = 208,  // 0b11010000
  PRISM_FEK_18 = 200,  // 0b11001000
  PRISM_FEK_40 = 205,  // 0b11001101
  PRISM_FEK_6  = 196,  // 0b11000100
  PRISM_FEK_75 = 210,  // 0b11010010
  PRISM_GL_18  = 200,  // 0b11001000
  PRISM_GL_40  = 205,  // 0b11001101
  PRISM_GL_6   = 196,  // 0b11000100
  PRISM_GL_75  = 209,  // 0b11010001
  PYRA_14      = 168,  // 0b10101000
  PYRA_30      = 172,  // 0b10101100
  PYRA_5       = 164,  // 0b10100100
  PYRA_55      = 176,  // 0b10110000
  PYRA_91      = 180,  // 0b10110100
  PYRA_FEK_14  = 168,  // 0b10101000
  PYRA_FEK_30  = 173,  // 0b10101101
  PYRA_FEK_5   = 164,  // 0b10100100
  PYRA_FEK_55  = 178,  // 0b10110010
  PYRA_GL_14   = 168,  // 0b10101000
  PYRA_GL_30   = 173,  // 0b10101101
  PYRA_GL_5    = 164,  // 0b10100100
  PYRA_GL_55   = 177,  // 0b10110001
  SHAPE_HEXA   = 7,    // 0b00000111
  SHAPE_PRISM  = 6,    // 0b00000110
  SHAPE_PYRA   = 5,    // 0b00000101
  SHAPE_TET    = 4,    // 0b00000100
  TET_10       = 136,  // 0b10001000
  TET_20       = 140,  // 0b10001100
  TET_35       = 144,  // 0b10010000
  TET_4        = 132,  // 0b10000100
  TET_56       = 148,  // 0b10010100
  TET_84       = 152,  // 0b10011000
  TET_FEK_10   = 136,  // 0b10001000
  TET_FEK_20   = 141,  // 0b10001101
  TET_FEK_35   = 146,  // 0b10010010
  TET_FEK_4    = 132,  // 0b10000100
  TET_FEK_56   = 150,  // 0b10010110
  TET_FEK_84   = 154,  // 0b10011010
  TET_GL_10    = 136,  // 0b10001000
  TET_GL_20    = 141,  // 0b10001101
  TET_GL_35    = 145,  // 0b10010001
  TET_GL_4     = 132,  // 0b10000100
  TET_GL_56    = 149,  // 0b10010101
  TET_GL_84    = 153,  // 0b10011001
};

}  // end namespace sfe

#endif
