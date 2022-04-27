// Copyright 2022 The NumGeom Group, Stony Brook University
// Main developers:
//     sfelib: Qiao Chen, Xiangmin Jiao, Jacob Jones
//     momp2cpp: Xiangmin Jiao, Qiao Chen
//
// sfe_internal.cpp
//
// Code generation for function 'sfe_internal'
//

// Include files
#include "sfe_internal.h"
#include "coder_array.h"
#include "m2c_lib.h"
#include "sfe_internal_types.h"
#include "sfe_quadrules_rowmajor.h"
#include "sfe_shapefuncs_rowmajor.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <vector>

// Variable Definitions
namespace sfe {
static const short iv[250]{
    1,  0,   0,   0,  0,  0,   0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,
    0,  0,   0,   0,  0,  0,   0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,
    0,  2,   0,   0,  0,  3,   0,   0,   0,   4,   4,   0,  0,  5,  5,  0,  0,
    6,  6,   0,   0,  7,  7,   0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  3,
    0,  0,   0,   6,  0,  0,   0,   10,  10,  0,   0,   15, 15, 15, 0,  21, 21,
    21, 0,   28,  28, 28, 0,   0,   0,   0,   0,   0,   0,  0,  0,  4,  0,  0,
    0,  9,   0,   0,  0,  16,  16,  0,   0,   25,  25,  0,  0,  36, 36, 0,  0,
    49, 49,  0,   0,  0,  0,   0,   0,   0,   0,   0,   0,  4,  0,  0,  0,  10,
    0,  0,   0,   20, 20, 0,   0,   35,  35,  35,  0,   56, 56, 56, 0,  84, 84,
    84, 0,   0,   0,  0,  0,   0,   0,   0,   0,   5,   0,  0,  0,  14, 0,  0,
    0,  30,  30,  0,  0,  55,  55,  55,  0,   91,  0,   0,  0,  0,  0,  0,  0,
    0,  0,   0,   0,  0,  0,   0,   0,   6,   0,   0,   0,  18, 0,  0,  0,  40,
    40, 0,   0,   75, 75, 75,  0,   126, 126, 0,   0,   0,  0,  0,  0,  0,  0,
    0,  0,   0,   0,  0,  0,   8,   0,   0,   0,   27,  0,  0,  0,  64, 64, 0,
    0,  125, 125, 0,  0,  216, 216, 0,   0,   343, 343, -1};

}

// Function Declarations
namespace sfe {
static inline void bar_quadrules(coder::SizeType degree,
                                 ::coder::array<double, 2U> &cs,
                                 ::coder::array<double, 1U> &ws);

static inline unsigned char obtain_facets(coder::SizeType etype);

static inline void obtain_facets(coder::SizeType etype, signed char facetid,
                                 unsigned char *ret, short lids_data[],
                                 coder::SizeType *lids_size);

static inline unsigned char obtain_facets(coder::SizeType etype,
                                          signed char facetid);

static inline void pyra_quadrules(coder::SizeType degree,
                                  ::coder::array<double, 2U> &cs,
                                  ::coder::array<double, 1U> &ws);

static inline void sfe1_tabulate_shapefuncs(
    coder::SizeType etype, const ::coder::array<double, 2U> &cs,
    ::coder::array<double, 2U> &sfvals, ::coder::array<double, 3U> &sdvals);

static inline void sfe2_tabulate_equi_tri(coder::SizeType etype,
                                          const ::coder::array<double, 2U> &cs,
                                          ::coder::array<double, 2U> &sfvals,
                                          ::coder::array<double, 3U> &sdvals);

static inline void sfe2_tabulate_gl(coder::SizeType etype,
                                    const ::coder::array<double, 2U> &cs,
                                    ::coder::array<double, 2U> &sfvals,
                                    ::coder::array<double, 3U> &sdvals);

static inline void sfe2_tabulate_shapefuncs(
    coder::SizeType etype, const ::coder::array<double, 2U> &cs,
    ::coder::array<double, 2U> &sfvals, ::coder::array<double, 3U> &sdvals);

static inline void sfe3_tabulate_equi_prism(
    coder::SizeType etype, const ::coder::array<double, 2U> &cs,
    ::coder::array<double, 2U> &sfvals, ::coder::array<double, 3U> &sdvals);

static inline void sfe3_tabulate_equi_pyra(coder::SizeType etype,
                                           const ::coder::array<double, 2U> &cs,
                                           ::coder::array<double, 2U> &sfvals,
                                           ::coder::array<double, 3U> &sdvals);

static inline void sfe3_tabulate_equi_tet(coder::SizeType etype,
                                          const ::coder::array<double, 2U> &cs,
                                          ::coder::array<double, 2U> &sfvals,
                                          ::coder::array<double, 3U> &sdvals);

static inline void sfe3_tabulate_gl_prism(coder::SizeType etype,
                                          const ::coder::array<double, 2U> &cs,
                                          ::coder::array<double, 2U> &sfvals,
                                          ::coder::array<double, 3U> &sdvals);

static inline void sfe3_tabulate_gl_pyra(coder::SizeType etype,
                                         const ::coder::array<double, 2U> &cs,
                                         ::coder::array<double, 2U> &sfvals,
                                         ::coder::array<double, 3U> &sdvals);

static inline void sfe3_tabulate_shapefuncs(
    coder::SizeType etype, const ::coder::array<double, 2U> &cs,
    ::coder::array<double, 2U> &sfvals, ::coder::array<double, 3U> &sdvals);

static inline void sfe_init(SfeObject *b_sfe, const unsigned char etypes[2],
                            const ::coder::array<double, 2U> &xs,
                            coder::SizeType qd_or_natcoords,
                            const ::coder::array<double, 2U> &userquad);

static inline void sfe_init(SfeObject *b_sfe, const int etypes_data[],
                            coder::SizeType etypes_size,
                            const ::coder::array<double, 2U> &xs,
                            coder::SizeType qd_or_natcoords,
                            const ::coder::array<double, 2U> &userquad);

static inline void sfe_init(SfeObject *b_sfe, const unsigned char etypes[2],
                            const ::coder::array<double, 2U> &xs);

static inline void sfe_init(SfeObject *b_sfe, const int etypes_data[],
                            coder::SizeType etypes_size,
                            const ::coder::array<double, 2U> &xs);

static inline void sfe_init(SfeObject *b_sfe, const unsigned char etypes[2],
                            const ::coder::array<double, 2U> &xs,
                            const ::coder::array<double, 2U> &qd_or_natcoords);

static inline void sfe_init(SfeObject *b_sfe, const int etypes_data[],
                            coder::SizeType etypes_size,
                            const ::coder::array<double, 2U> &xs,
                            const ::coder::array<double, 2U> &qd_or_natcoords);

static inline void sfe_init_grad(SfeObject *b_sfe, coder::SizeType q);

static inline boolean_T solve_sq(double J[9], coder::SizeType n,
                                 ::coder::array<double, 2U> &b1);

static inline void tabulate_quadratures(coder::SizeType etype,
                                        coder::SizeType qd,
                                        ::coder::array<double, 2U> &cs,
                                        ::coder::array<double, 1U> &ws);

static inline void tabulate_shapefuncs(coder::SizeType etype,
                                       const ::coder::array<double, 2U> &cs,
                                       ::coder::array<double, 2U> &sfvals,
                                       ::coder::array<double, 3U> &sdvals);

} // namespace sfe

// Function Definitions
namespace sfe {
//  bar_quadrules - Obtain quadrature points and weights of a bar element.
static void bar_quadrules(coder::SizeType degree,
                          ::coder::array<double, 2U> &cs,
                          ::coder::array<double, 1U> &ws)
{
  coder::SizeType nqp;
  boolean_T guard1{false};
  boolean_T guard2{false};
  boolean_T guard3{false};
  boolean_T guard4{false};
  boolean_T guard5{false};
  boolean_T guard6{false};
  boolean_T guard7{false};
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  guard5 = false;
  guard6 = false;
  guard7 = false;
  switch (degree) {
  case 0:
    guard1 = true;
    break;
  case 1:
    guard1 = true;
    break;
  case 2:
    guard2 = true;
    break;
  case 3:
    guard2 = true;
    break;
  case 4:
    guard3 = true;
    break;
  case 5:
    guard3 = true;
    break;
  case 6:
    guard4 = true;
    break;
  case 7:
    guard4 = true;
    break;
  case 8:
    guard5 = true;
    break;
  case 9:
    guard5 = true;
    break;
  case 10:
    guard6 = true;
    break;
  case 11:
    guard6 = true;
    break;
  case 12:
    guard7 = true;
    break;
  case 13:
    guard7 = true;
    break;
  default:
    if (degree > 15) {
      m2cWarnMsgIdAndTxt("bar_quadrules:UnsupportedDegree",
                         "Only support up to degree 15");
    }
    nqp = ::sfe_qrules::bar_deg15_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg15_qrule(&cs[0], &(ws.data())[0]);
    break;
  }
  if (guard7) {
    nqp = ::sfe_qrules::bar_deg13_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg13_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard6) {
    nqp = ::sfe_qrules::bar_deg11_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg11_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard5) {
    nqp = ::sfe_qrules::bar_deg9_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg9_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard4) {
    nqp = ::sfe_qrules::bar_deg7_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg7_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard3) {
    nqp = ::sfe_qrules::bar_deg5_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg5_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard2) {
    nqp = ::sfe_qrules::bar_deg3_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg3_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard1) {
    nqp = ::sfe_qrules::bar_deg1_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg1_qrule(&cs[0], &(ws.data())[0]);
  }
}

// obtain_facets - Query facet information
static void obtain_facets(coder::SizeType etype, signed char facetid,
                          unsigned char *ret, short lids_data[],
                          coder::SizeType *lids_size)
{
  coder::SizeType n;
  const static std::vector<std::vector<uint8_T>> FACETS{
      {1, 1},                         // SFE_BAR_2
      {},                             // 37
      {},                             // 38
      {},                             // 39
      {1, 1},                         // SFE_BAR_3
      {},                             // 41
      {},                             // 42
      {},                             // 43
      {1, 1},                         // SFE_BAR_4
      {1, 1},                         // SFE_BAR_FEK_4
      {},                             // 46
      {},                             // 47
      {1, 1},                         // SFE_BAR_5
      {1, 1},                         // SFE_BAR_FEK_5
      {},                             // 50
      {},                             // 51
      {1, 1},                         // SFE_BAR_6
      {1, 1},                         // SFE_BAR_FEK_6
      {},                             // 54
      {},                             // 55
      {1, 1},                         // SFE_BAR_7
      {1, 1},                         // SFE_BAR_FEK_7
      {},                             // 58
      {},                             // 59
      {},                             // 60
      {},                             // 61
      {},                             // 62
      {},                             // 63
      {},                             // 64
      {},                             // 65
      {},                             // 66
      {},                             // 67
      {36, 36, 36},                   // SFE_TRI_3
      {},                             // 69
      {},                             // 70
      {},                             // 71
      {40, 40, 40},                   // SFE_TRI_6
      {},                             // 73
      {},                             // 74
      {},                             // 75
      {44, 44, 44},                   // SFE_TRI_10
      {45, 45, 45},                   // SFE_TRI_FEK_10
      {},                             // 78
      {},                             // 79
      {48, 48, 48},                   // SFE_TRI_15
      {49, 49, 49},                   // SFE_TRI_GL_15
      {48, 48, 48},                   // SFE_TRI_FEK_15
      {},                             // 83
      {52, 52, 52},                   // SFE_TRI_21
      {53, 53, 53},                   // SFE_TRI_GL_21
      {52, 52, 52},                   // SFE_TRI_FEK_21
      {},                             // 87
      {56, 56, 56},                   // SFE_TRI_28
      {57, 57, 57},                   // SFE_TRI_GL_28
      {56, 56, 56},                   // SFE_TRI_FEK_28
      {},                             // 91
      {},                             // 92
      {},                             // 93
      {},                             // 94
      {},                             // 95
      {},                             // 96
      {},                             // 97
      {},                             // 98
      {},                             // 99
      {36, 36, 36, 36},               // SFE_QUAD_4
      {},                             // 101
      {},                             // 102
      {},                             // 103
      {40, 40, 40, 40},               // SFE_QUAD_9
      {},                             // 105
      {},                             // 106
      {},                             // 107
      {44, 44, 44, 44},               // SFE_QUAD_16
      {45, 45, 45, 45},               // SFE_QUAD_FEK_16
      {},                             // 110
      {},                             // 111
      {48, 48, 48, 48},               // SFE_QUAD_25
      {49, 49, 49, 49},               // SFE_QUAD_FEK_25
      {},                             // 114
      {},                             // 115
      {52, 52, 52, 52},               // SFE_QUAD_36
      {53, 53, 53, 53},               // SFE_QUAD_FEK_36
      {},                             // 118
      {},                             // 119
      {56, 56, 56, 56},               // SFE_QUAD_49
      {57, 57, 57, 57},               // SFE_QUAD_FEK_49
      {},                             // 122
      {},                             // 123
      {},                             // 124
      {},                             // 125
      {},                             // 126
      {},                             // 127
      {},                             // 128
      {},                             // 129
      {},                             // 130
      {},                             // 131
      {68, 68, 68, 68},               // SFE_TET_4
      {},                             // 133
      {},                             // 134
      {},                             // 135
      {72, 72, 72, 72},               // SFE_TET_10
      {},                             // 137
      {},                             // 138
      {},                             // 139
      {76, 76, 76, 76},               // SFE_TET_20
      {77, 77, 77, 77},               // SFE_TET_FEK_20
      {},                             // 142
      {},                             // 143
      {80, 80, 80, 80},               // SFE_TET_35
      {81, 81, 81, 81},               // SFE_TET_GL_35
      {82, 82, 82, 82},               // SFE_TET_FEK_35
      {},                             // 147
      {84, 84, 84, 84},               // SFE_TET_56
      {85, 85, 85, 85},               // SFE_TET_GL_56
      {86, 86, 86, 86},               // SFE_TET_FEK_56
      {},                             // 151
      {88, 88, 88, 88},               // SFE_TET_84
      {89, 89, 89, 89},               // SFE_TET_GL_84
      {90, 90, 90, 90},               // SFE_TET_FEK_84
      {},                             // 155
      {},                             // 156
      {},                             // 157
      {},                             // 158
      {},                             // 159
      {},                             // 160
      {},                             // 161
      {},                             // 162
      {},                             // 163
      {100, 68, 68, 68, 68},          // SFE_PYRA_5
      {},                             // 165
      {},                             // 166
      {},                             // 167
      {104, 72, 72, 72, 72},          // SFE_PYRA_14
      {},                             // 169
      {},                             // 170
      {},                             // 171
      {108, 76, 76, 76, 76},          // SFE_PYRA_30
      {109, 77, 77, 77, 77},          // SFE_PYRA_FEK_30
      {},                             // 174
      {},                             // 175
      {112, 80, 80, 80, 80},          // SFE_PYRA_55
      {113, 81, 81, 81, 81},          // SFE_PYRA_GL_55
      {112, 82, 82, 82, 82},          // SFE_PYRA_FEK_55
      {},                             // 179
      {116, 84, 84, 84, 84},          // SFE_PYRA_91
      {},                             // 181
      {},                             // 182
      {},                             // 183
      {},                             // 184
      {},                             // 185
      {},                             // 186
      {},                             // 187
      {},                             // 188
      {},                             // 189
      {},                             // 190
      {},                             // 191
      {},                             // 192
      {},                             // 193
      {},                             // 194
      {},                             // 195
      {100, 100, 100, 68, 68},        // SFE_PRISM_6
      {},                             // 197
      {},                             // 198
      {},                             // 199
      {104, 104, 104, 72, 72},        // SFE_PRISM_18
      {},                             // 201
      {},                             // 202
      {},                             // 203
      {108, 108, 108, 76, 76},        // SFE_PRISM_40
      {109, 109, 109, 77, 77},        // SFE_PRISM_FEK_40
      {},                             // 206
      {},                             // 207
      {112, 112, 112, 80, 80},        // SFE_PRISM_75
      {113, 113, 113, 81, 81},        // SFE_PRISM_GL_75
      {112, 112, 112, 82, 82},        // SFE_PRISM_FEK_75
      {},                             // 211
      {116, 116, 116, 84, 84},        // SFE_PRISM_126
      {117, 117, 117, 85, 85},        // SFE_PRISM_GL_126
      {},                             // 214
      {},                             // 215
      {},                             // 216
      {},                             // 217
      {},                             // 218
      {},                             // 219
      {},                             // 220
      {},                             // 221
      {},                             // 222
      {},                             // 223
      {},                             // 224
      {},                             // 225
      {},                             // 226
      {},                             // 227
      {100, 100, 100, 100, 100, 100}, // SFE_HEXA_8
      {},                             // 229
      {},                             // 230
      {},                             // 231
      {104, 104, 104, 104, 104, 104}, // SFE_HEXA_27
      {},                             // 233
      {},                             // 234
      {},                             // 235
      {108, 108, 108, 108, 108, 108}, // SFE_HEXA_64
      {109, 109, 109, 109, 109, 109}, // SFE_HEXA_FEK_64
      {},                             // 238
      {},                             // 239
      {112, 112, 112, 112, 112, 112}, // SFE_HEXA_125
      {113, 113, 113, 113, 113, 113}, // SFE_HEXA_FEK_125
      {},                             // 242
      {},                             // 243
      {116, 116, 116, 116, 116, 116}, // SFE_HEXA_216
      {117, 117, 117, 117, 117, 117}, // SFE_HEXA_FEK_216
      {},                             // 246
      {},                             // 247
      {120, 120, 120, 120, 120, 120}, // SFE_HEXA_343
      {121, 121, 121, 121, 121, 121}, // SFE_HEXA_FEK_343
  };
  const static std::vector<std::vector<std::vector<int16_T>>> LIDS{
      {{1}, {2}},                                             // SFE_BAR_2
      {{}},                                                   // 37
      {{}},                                                   // 38
      {{}},                                                   // 39
      {{1}, {2}},                                             // SFE_BAR_3
      {{}},                                                   // 41
      {{}},                                                   // 42
      {{}},                                                   // 43
      {{1}, {2}},                                             // SFE_BAR_4
      {{1}, {2}},                                             // SFE_BAR_FEK_4
      {{}},                                                   // 46
      {{}},                                                   // 47
      {{1}, {2}},                                             // SFE_BAR_5
      {{1}, {2}},                                             // SFE_BAR_FEK_5
      {{}},                                                   // 50
      {{}},                                                   // 51
      {{1}, {2}},                                             // SFE_BAR_6
      {{1}, {2}},                                             // SFE_BAR_FEK_6
      {{}},                                                   // 54
      {{}},                                                   // 55
      {{1}, {2}},                                             // SFE_BAR_7
      {{1}, {2}},                                             // SFE_BAR_FEK_7
      {{}},                                                   // 58
      {{}},                                                   // 59
      {{}},                                                   // 60
      {{}},                                                   // 61
      {{}},                                                   // 62
      {{}},                                                   // 63
      {{}},                                                   // 64
      {{}},                                                   // 65
      {{}},                                                   // 66
      {{}},                                                   // 67
      {{1, 2}, {2, 3}, {3, 1}},                               // SFE_TRI_3
      {{}},                                                   // 69
      {{}},                                                   // 70
      {{}},                                                   // 71
      {{1, 2, 4}, {2, 3, 5}, {3, 1, 6}},                      // SFE_TRI_6
      {{}},                                                   // 73
      {{}},                                                   // 74
      {{}},                                                   // 75
      {{1, 2, 4, 5}, {2, 3, 6, 7}, {3, 1, 8, 9}},             // SFE_TRI_10
      {{1, 2, 4, 5}, {2, 3, 6, 7}, {3, 1, 8, 9}},             // SFE_TRI_FEK_10
      {{}},                                                   // 78
      {{}},                                                   // 79
      {{1, 2, 4, 5, 6}, {2, 3, 7, 8, 9}, {3, 1, 10, 11, 12}}, // SFE_TRI_15
      {{1, 2, 4, 5, 6}, {2, 3, 7, 8, 9}, {3, 1, 10, 11, 12}}, // SFE_TRI_GL_15
      {{1, 2, 4, 5, 6}, {2, 3, 7, 8, 9}, {3, 1, 10, 11, 12}}, // SFE_TRI_FEK_15
      {{}},                                                   // 83
      {{1, 2, 4, 5, 6, 7},
       {2, 3, 8, 9, 10, 11},
       {3, 1, 12, 13, 14, 15}}, // SFE_TRI_21
      {{1, 2, 4, 5, 6, 7},
       {2, 3, 8, 9, 10, 11},
       {3, 1, 12, 13, 14, 15}}, // SFE_TRI_GL_21
      {{1, 2, 4, 5, 6, 7},
       {2, 3, 8, 9, 10, 11},
       {3, 1, 12, 13, 14, 15}}, // SFE_TRI_FEK_21
      {{}},                     // 87
      {{1, 2, 4, 5, 6, 7, 8},
       {2, 3, 9, 10, 11, 12, 13},
       {3, 1, 14, 15, 16, 17, 18}}, // SFE_TRI_28
      {{1, 2, 4, 5, 6, 7, 8},
       {2, 3, 9, 10, 11, 12, 13},
       {3, 1, 14, 15, 16, 17, 18}}, // SFE_TRI_GL_28
      {{1, 2, 4, 5, 6, 7, 8},
       {2, 3, 9, 10, 11, 12, 13},
       {3, 1, 14, 15, 16, 17, 18}},                 // SFE_TRI_FEK_28
      {{}},                                         // 91
      {{}},                                         // 92
      {{}},                                         // 93
      {{}},                                         // 94
      {{}},                                         // 95
      {{}},                                         // 96
      {{}},                                         // 97
      {{}},                                         // 98
      {{}},                                         // 99
      {{1, 2}, {2, 3}, {3, 4}, {4, 1}},             // SFE_QUAD_4
      {{}},                                         // 101
      {{}},                                         // 102
      {{}},                                         // 103
      {{1, 2, 5}, {2, 3, 6}, {3, 4, 7}, {4, 1, 8}}, // SFE_QUAD_9
      {{}},                                         // 105
      {{}},                                         // 106
      {{}},                                         // 107
      {{1, 2, 5, 6},
       {2, 3, 7, 8},
       {3, 4, 9, 10},
       {4, 1, 11, 12}}, // SFE_QUAD_16
      {{1, 2, 5, 6},
       {2, 3, 7, 8},
       {3, 4, 9, 10},
       {4, 1, 11, 12}}, // SFE_QUAD_FEK_16
      {{}},             // 110
      {{}},             // 111
      {{1, 2, 5, 6, 7},
       {2, 3, 8, 9, 10},
       {3, 4, 11, 12, 13},
       {4, 1, 14, 15, 16}}, // SFE_QUAD_25
      {{1, 2, 5, 6, 7},
       {2, 3, 8, 9, 10},
       {3, 4, 11, 12, 13},
       {4, 1, 14, 15, 16}}, // SFE_QUAD_FEK_25
      {{}},                 // 114
      {{}},                 // 115
      {{1, 2, 5, 6, 7, 8},
       {2, 3, 9, 10, 11, 12},
       {3, 4, 13, 14, 15, 16},
       {4, 1, 17, 18, 19, 20}}, // SFE_QUAD_36
      {{1, 2, 5, 6, 7, 8},
       {2, 3, 9, 10, 11, 12},
       {3, 4, 13, 14, 15, 16},
       {4, 1, 17, 18, 19, 20}}, // SFE_QUAD_FEK_36
      {{}},                     // 118
      {{}},                     // 119
      {{1, 2, 5, 6, 7, 8, 9},
       {2, 3, 10, 11, 12, 13, 14},
       {3, 4, 15, 16, 17, 18, 19},
       {4, 1, 20, 21, 22, 23, 24}}, // SFE_QUAD_49
      {{1, 2, 5, 6, 7, 8, 9},
       {2, 3, 10, 11, 12, 13, 14},
       {3, 4, 15, 16, 17, 18, 19},
       {4, 1, 20, 21, 22, 23, 24}},                 // SFE_QUAD_FEK_49
      {{}},                                         // 122
      {{}},                                         // 123
      {{}},                                         // 124
      {{}},                                         // 125
      {{}},                                         // 126
      {{}},                                         // 127
      {{}},                                         // 128
      {{}},                                         // 129
      {{}},                                         // 130
      {{}},                                         // 131
      {{1, 3, 2}, {1, 2, 4}, {2, 3, 4}, {3, 1, 4}}, // SFE_TET_4
      {{}},                                         // 133
      {{}},                                         // 134
      {{}},                                         // 135
      {{1, 3, 2, 7, 6, 5},
       {1, 2, 4, 5, 9, 8},
       {2, 3, 4, 6, 10, 9},
       {3, 1, 4, 7, 8, 10}}, // SFE_TET_10
      {{}},                  // 137
      {{}},                  // 138
      {{}},                  // 139
      {{1, 3, 2, 10, 9, 8, 7, 6, 5, 17},
       {1, 2, 4, 5, 6, 13, 14, 12, 11, 18},
       {2, 3, 4, 7, 8, 15, 16, 14, 13, 19},
       {3, 1, 4, 9, 10, 11, 12, 16, 15, 20}}, // SFE_TET_20
      {{1, 3, 2, 10, 9, 8, 7, 6, 5, 17},
       {1, 2, 4, 5, 6, 13, 14, 12, 11, 18},
       {2, 3, 4, 7, 8, 15, 16, 14, 13, 19},
       {3, 1, 4, 9, 10, 11, 12, 16, 15, 20}}, // SFE_TET_FEK_20
      {{}},                                   // 142
      {{}},                                   // 143
      {{1, 3, 2, 13, 12, 11, 10, 9, 8, 7, 6, 5, 23, 25, 24},
       {1, 2, 4, 5, 6, 7, 17, 18, 19, 16, 15, 14, 26, 27, 28},
       {2, 3, 4, 8, 9, 10, 20, 21, 22, 19, 18, 17, 29, 30, 31},
       {3, 1, 4, 11, 12, 13, 14, 15, 16, 22, 21, 20, 32, 33, 34}}, // SFE_TET_35
      {{1, 3, 2, 13, 12, 11, 10, 9, 8, 7, 6, 5, 23, 25, 24},
       {1, 2, 4, 5, 6, 7, 17, 18, 19, 16, 15, 14, 26, 27, 28},
       {2, 3, 4, 8, 9, 10, 20, 21, 22, 19, 18, 17, 29, 30, 31},
       {3, 1, 4, 11, 12, 13, 14, 15, 16, 22, 21, 20, 32, 33,
        34}}, // SFE_TET_GL_35
      {{1, 3, 2, 13, 12, 11, 10, 9, 8, 7, 6, 5, 23, 25, 24},
       {1, 2, 4, 5, 6, 7, 17, 18, 19, 16, 15, 14, 26, 27, 28},
       {2, 3, 4, 8, 9, 10, 20, 21, 22, 19, 18, 17, 29, 30, 31},
       {3, 1, 4, 11, 12, 13, 14, 15, 16, 22, 21, 20, 32, 33,
        34}}, // SFE_TET_FEK_35
      {{}},   // 147
      {{1, 3, 2, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 5,  29, 34, 33, 32, 31, 30},
       {1,  2,  4,  5,  6,  7,  8,  21, 22, 23, 24,
        20, 19, 18, 17, 35, 36, 37, 38, 39, 40},
       {2,  3,  4,  9,  10, 11, 12, 25, 26, 27, 28,
        24, 23, 22, 21, 41, 42, 43, 44, 45, 46},
       {3,  1,  4,  13, 14, 15, 16, 17, 18, 19, 20,
        28, 27, 26, 25, 47, 48, 49, 50, 51, 52}}, // SFE_TET_56
      {{1, 3, 2, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 5,  29, 34, 33, 32, 31, 30},
       {1,  2,  4,  5,  6,  7,  8,  21, 22, 23, 24,
        20, 19, 18, 17, 35, 36, 37, 38, 39, 40},
       {2,  3,  4,  9,  10, 11, 12, 25, 26, 27, 28,
        24, 23, 22, 21, 41, 42, 43, 44, 45, 46},
       {3,  1,  4,  13, 14, 15, 16, 17, 18, 19, 20,
        28, 27, 26, 25, 47, 48, 49, 50, 51, 52}}, // SFE_TET_GL_56
      {{1, 3, 2, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 5,  29, 34, 33, 32, 31, 30},
       {1,  2,  4,  5,  6,  7,  8,  21, 22, 23, 24,
        20, 19, 18, 17, 35, 36, 37, 38, 39, 40},
       {2,  3,  4,  9,  10, 11, 12, 25, 26, 27, 28,
        24, 23, 22, 21, 41, 42, 43, 44, 45, 46},
       {3,  1,  4,  13, 14, 15, 16, 17, 18, 19, 20,
        28, 27, 26, 25, 47, 48, 49, 50, 51, 52}}, // SFE_TET_FEK_56
      {{}},                                       // 151
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // SFE_TET_84
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // SFE_TET_GL_84
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // SFE_TET_FEK_84
      {{}},                                         // 155
      {{}},                                         // 156
      {{}},                                         // 157
      {{}},                                         // 158
      {{}},                                         // 159
      {{}},                                         // 160
      {{}},                                         // 161
      {{}},                                         // 162
      {{}},                                         // 163
      {{1, 4, 3, 2},
       {1, 2, 5, 0},
       {2, 3, 5, 0},
       {3, 4, 5, 0},
       {4, 1, 5, 0}}, // SFE_PYRA_5
      {{}},           // 165
      {{}},           // 166
      {{}},           // 167
      {{1, 4, 3, 2, 9, 8, 7, 6, 14},
       {1, 2, 5, 6, 11, 10, 0, 0, 0},
       {2, 3, 5, 7, 12, 11, 0, 0, 0},
       {3, 4, 5, 8, 13, 12, 0, 0, 0},
       {4, 1, 5, 9, 10, 13, 0, 0, 0}}, // SFE_PYRA_14
      {{}},                            // 169
      {{}},                            // 170
      {{}},                            // 171
      {{1, 4, 3, 2, 13, 12, 11, 10, 9, 8, 7, 6, 22, 25, 24, 23},
       {1, 2, 5, 6, 7, 16, 17, 15, 14, 26, 0, 0, 0, 0, 0, 0},
       {2, 3, 5, 8, 9, 18, 19, 17, 16, 27, 0, 0, 0, 0, 0, 0},
       {3, 4, 5, 10, 11, 20, 21, 19, 18, 28, 0, 0, 0, 0, 0, 0},
       {4, 1, 5, 12, 13, 14, 15, 21, 20, 29, 0, 0, 0, 0, 0, 0}}, // SFE_PYRA_30
      {{1, 4, 3, 2, 13, 12, 11, 10, 9, 8, 7, 6, 22, 25, 24, 23},
       {1, 2, 5, 6, 7, 16, 17, 15, 14, 26, 0, 0, 0, 0, 0, 0},
       {2, 3, 5, 8, 9, 18, 19, 17, 16, 27, 0, 0, 0, 0, 0, 0},
       {3, 4, 5, 10, 11, 20, 21, 19, 18, 28, 0, 0, 0, 0, 0, 0},
       {4, 1, 5, 12, 13, 14, 15, 21, 20, 29, 0, 0, 0, 0, 0,
        0}}, // SFE_PYRA_FEK_30
      {{}},  // 174
      {{}},  // 175
      {{1, 4, 3, 2,  17, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 30, 37, 36, 35, 34, 33, 32, 31, 38},
       {1,  2,  5, 6, 7, 8, 21, 22, 23, 20, 19, 18, 39,
        40, 41, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0},
       {2,  3,  5, 9, 10, 11, 24, 25, 26, 23, 22, 21, 42,
        43, 44, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0},
       {3,  4,  5, 12, 13, 14, 27, 28, 29, 26, 25, 24, 45,
        46, 47, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0},
       {4,  1,  5, 15, 16, 17, 18, 19, 20, 29, 28, 27, 48,
        49, 50, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PYRA_55
      {{1, 4, 3, 2,  17, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 30, 37, 36, 35, 34, 33, 32, 31, 38},
       {1,  2,  5, 6, 7, 8, 21, 22, 23, 20, 19, 18, 39,
        40, 41, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0},
       {2,  3,  5, 9, 10, 11, 24, 25, 26, 23, 22, 21, 42,
        43, 44, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0},
       {3,  4,  5, 12, 13, 14, 27, 28, 29, 26, 25, 24, 45,
        46, 47, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0},
       {4,  1,  5, 15, 16, 17, 18, 19, 20, 29, 28, 27, 48,
        49, 50, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PYRA_GL_55
      {{1, 4, 3, 2,  17, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 30, 37, 36, 35, 34, 33, 32, 31, 38},
       {1,  2,  5, 6, 7, 8, 21, 22, 23, 20, 19, 18, 39,
        40, 41, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0},
       {2,  3,  5, 9, 10, 11, 24, 25, 26, 23, 22, 21, 42,
        43, 44, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0},
       {3,  4,  5, 12, 13, 14, 27, 28, 29, 26, 25, 24, 45,
        46, 47, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0},
       {4,  1,  5, 15, 16, 17, 18, 19, 20, 29, 28, 27, 48,
        49, 50, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PYRA_FEK_55
      {{}},                                             // 179
      {{1, 4, 3,  2,  21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9,  8,
        7, 6, 38, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 50, 53, 52, 51},
       {1,  2,  5,  6, 7, 8, 9, 26, 27, 28, 29, 25, 24, 23, 22, 54, 55, 56,
        57, 58, 59, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
       {2,  3,  5,  10, 11, 12, 13, 30, 31, 32, 33, 29, 28, 27, 26, 60, 61, 62,
        63, 64, 65, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
       {3,  4,  5,  14, 15, 16, 17, 34, 35, 36, 37, 33, 32, 31, 30, 66, 67, 68,
        69, 70, 71, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
       {4,  1,  5,  18, 19, 20, 21, 22, 23, 24, 25, 37,
        36, 35, 34, 72, 73, 74, 75, 76, 77, 0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PYRA_91
      {{}},                                              // 181
      {{}},                                              // 182
      {{}},                                              // 183
      {{}},                                              // 184
      {{}},                                              // 185
      {{}},                                              // 186
      {{}},                                              // 187
      {{}},                                              // 188
      {{}},                                              // 189
      {{}},                                              // 190
      {{}},                                              // 191
      {{}},                                              // 192
      {{}},                                              // 193
      {{}},                                              // 194
      {{}},                                              // 195
      {{1, 2, 5, 4},
       {2, 3, 6, 5},
       {3, 1, 4, 6},
       {1, 3, 2, 0},
       {4, 5, 6, 0}}, // SFE_PRISM_6
      {{}},           // 197
      {{}},           // 198
      {{}},           // 199
      {{1, 2, 5, 4, 7, 11, 13, 10, 16},
       {2, 3, 6, 5, 8, 12, 14, 11, 17},
       {3, 1, 4, 6, 9, 10, 15, 12, 18},
       {1, 3, 2, 9, 8, 7, 0, 0, 0},
       {4, 5, 6, 13, 14, 15, 0, 0, 0}}, // SFE_PRISM_18
      {{}},                             // 201
      {{}},                             // 202
      {{}},                             // 203
      {{1, 2, 5, 4, 7, 8, 15, 16, 20, 19, 14, 13, 26, 27, 28, 29},
       {2, 3, 6, 5, 9, 10, 17, 18, 22, 21, 16, 15, 30, 31, 32, 33},
       {3, 1, 4, 6, 11, 12, 13, 14, 24, 23, 18, 17, 34, 35, 36, 37},
       {1, 3, 2, 12, 11, 10, 9, 8, 7, 25, 0, 0, 0, 0, 0, 0},
       {4, 5, 6, 19, 20, 21, 22, 23, 24, 38, 0, 0, 0, 0, 0, 0}}, // SFE_PRISM_40
      {{1, 2, 5, 4, 7, 8, 15, 16, 20, 19, 14, 13, 26, 27, 28, 29},
       {2, 3, 6, 5, 9, 10, 17, 18, 22, 21, 16, 15, 30, 31, 32, 33},
       {3, 1, 4, 6, 11, 12, 13, 14, 24, 23, 18, 17, 34, 35, 36, 37},
       {1, 3, 2, 12, 11, 10, 9, 8, 7, 25, 0, 0, 0, 0, 0, 0},
       {4, 5, 6, 19, 20, 21, 22, 23, 24, 38, 0, 0, 0, 0, 0,
        0}}, // SFE_PRISM_FEK_40
      {{}},  // 206
      {{}},  // 207
      {{1,  2,  5,  4,  7,  8,  9,  19, 20, 21, 27, 26, 25,
        18, 17, 16, 37, 38, 39, 40, 41, 42, 43, 44, 45},
       {2,  3,  6,  5,  10, 11, 12, 22, 23, 24, 30, 29, 28,
        21, 20, 19, 46, 47, 48, 49, 50, 51, 52, 53, 54},
       {3,  1,  4,  6,  13, 14, 15, 16, 17, 18, 33, 32, 31,
        24, 23, 22, 55, 56, 57, 58, 59, 60, 61, 62, 63},
       {1,  3,  2, 15, 14, 13, 12, 11, 10, 9, 8, 7, 34,
        36, 35, 0, 0,  0,  0,  0,  0,  0,  0, 0, 0},
       {4,  5,  6, 25, 26, 27, 28, 29, 30, 31, 32, 33, 64,
        65, 66, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PRISM_75
      {{1,  2,  5,  4,  7,  8,  9,  19, 20, 21, 27, 26, 25,
        18, 17, 16, 37, 38, 39, 40, 41, 42, 43, 44, 45},
       {2,  3,  6,  5,  10, 11, 12, 22, 23, 24, 30, 29, 28,
        21, 20, 19, 46, 47, 48, 49, 50, 51, 52, 53, 54},
       {3,  1,  4,  6,  13, 14, 15, 16, 17, 18, 33, 32, 31,
        24, 23, 22, 55, 56, 57, 58, 59, 60, 61, 62, 63},
       {1,  3,  2, 15, 14, 13, 12, 11, 10, 9, 8, 7, 34,
        36, 35, 0, 0,  0,  0,  0,  0,  0,  0, 0, 0},
       {4,  5,  6, 25, 26, 27, 28, 29, 30, 31, 32, 33, 64,
        65, 66, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PRISM_GL_75
      {{1,  2,  5,  4,  7,  8,  9,  19, 20, 21, 27, 26, 25,
        18, 17, 16, 37, 38, 39, 40, 41, 42, 43, 44, 45},
       {2,  3,  6,  5,  10, 11, 12, 22, 23, 24, 30, 29, 28,
        21, 20, 19, 46, 47, 48, 49, 50, 51, 52, 53, 54},
       {3,  1,  4,  6,  13, 14, 15, 16, 17, 18, 33, 32, 31,
        24, 23, 22, 55, 56, 57, 58, 59, 60, 61, 62, 63},
       {1,  3,  2, 15, 14, 13, 12, 11, 10, 9, 8, 7, 34,
        36, 35, 0, 0,  0,  0,  0,  0,  0,  0, 0, 0},
       {4,  5,  6, 25, 26, 27, 28, 29, 30, 31, 32, 33, 64,
        65, 66, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PRISM_FEK_75
      {{}},                                             // 211
      {{1,  2,  5,  4,  7,  8,  9,  10, 23, 24, 25, 26, 34, 33, 32, 31, 24, 23,
        22, 21, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58},
       {2,  3,  6,  5,  11, 12, 13, 14, 27, 28, 29, 30, 38, 37, 36, 35, 26, 25,
        24, 23, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74},
       {3,  1,  4,  6,  15, 16, 17, 18, 19, 20, 21, 22, 42, 41, 40, 39, 30, 29,
        28, 27, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
       {1,  3,  2,  18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 91, 96, 95,
        94, 93, 92, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0,  0},
       {4,  5,  6,  31, 32, 33, 34,  35,  36,  37, 38, 39,
        40, 41, 42, 97, 98, 99, 100, 101, 102, 0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,   0,   0,   0,  0,  0}}, // SFE_PRISM_126
      {{1,  2,  5,  4,  7,  8,  9,  10, 23, 24, 25, 26, 34, 33, 32, 31, 24, 23,
        22, 21, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58},
       {2,  3,  6,  5,  11, 12, 13, 14, 27, 28, 29, 30, 38, 37, 36, 35, 26, 25,
        24, 23, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74},
       {3,  1,  4,  6,  15, 16, 17, 18, 19, 20, 21, 22, 42, 41, 40, 39, 30, 29,
        28, 27, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
       {1,  3,  2,  18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 91, 96, 95,
        94, 93, 92, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0,  0},
       {4,  5,  6,  31, 32, 33, 34,  35,  36,  37, 38, 39,
        40, 41, 42, 97, 98, 99, 100, 101, 102, 0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,   0,   0,   0,  0,  0}}, // SFE_PRISM_GL_126
      {{}},                                                 // 214
      {{}},                                                 // 215
      {{}},                                                 // 216
      {{}},                                                 // 217
      {{}},                                                 // 218
      {{}},                                                 // 219
      {{}},                                                 // 220
      {{}},                                                 // 221
      {{}},                                                 // 222
      {{}},                                                 // 223
      {{}},                                                 // 224
      {{}},                                                 // 225
      {{}},                                                 // 226
      {{}},                                                 // 227
      {{1, 4, 3, 2},
       {1, 2, 6, 5},
       {2, 3, 7, 6},
       {3, 4, 8, 7},
       {1, 5, 8, 4},
       {5, 6, 7, 8}}, // SFE_HEXA_8
      {{}},           // 229
      {{}},           // 230
      {{}},           // 231
      {{1, 4, 3, 2, 12, 11, 10, 9, 21},
       {1, 2, 6, 5, 9, 14, 17, 13, 22},
       {2, 3, 7, 6, 10, 15, 18, 14, 23},
       {3, 4, 8, 7, 11, 16, 19, 15, 24},
       {1, 5, 8, 4, 13, 20, 16, 12, 25},
       {5, 6, 7, 8, 17, 18, 19, 20, 26}}, // SFE_HEXA_27
      {{}},                               // 233
      {{}},                               // 234
      {{}},                               // 235
      {{1, 4, 3, 2, 16, 15, 14, 13, 12, 11, 10, 9, 33, 36, 35, 34},
       {1, 2, 6, 5, 9, 10, 19, 20, 26, 25, 18, 17, 37, 38, 39, 40},
       {2, 3, 7, 6, 11, 12, 21, 22, 28, 27, 20, 19, 41, 42, 43, 44},
       {3, 4, 8, 7, 13, 14, 23, 24, 30, 29, 22, 21, 45, 46, 47, 48},
       {1, 5, 8, 4, 17, 18, 32, 31, 24, 23, 15, 16, 50, 51, 52, 49},
       {5, 6, 7, 8, 25, 26, 27, 28, 29, 30, 31, 32, 53, 54, 55,
        56}}, // SFE_HEXA_64
      {{1, 4, 3, 2, 16, 15, 14, 13, 12, 11, 10, 9, 33, 36, 35, 34},
       {1, 2, 6, 5, 9, 10, 19, 20, 26, 25, 18, 17, 37, 38, 39, 40},
       {2, 3, 7, 6, 11, 12, 21, 22, 28, 27, 20, 19, 41, 42, 43, 44},
       {3, 4, 8, 7, 13, 14, 23, 24, 30, 29, 22, 21, 45, 46, 47, 48},
       {1, 5, 8, 4, 17, 18, 32, 31, 24, 23, 15, 16, 50, 51, 52, 49},
       {5, 6, 7, 8, 25, 26, 27, 28, 29, 30, 31, 32, 53, 54, 55,
        56}}, // SFE_HEXA_FEK_64
      {{}},   // 238
      {{}},   // 239
      {{1,  4,  3, 2,  20, 19, 18, 17, 16, 15, 14, 13, 12,
        11, 10, 9, 45, 52, 51, 50, 49, 48, 47, 46, 53},
       {1,  2,  6,  5,  9,  10, 11, 24, 25, 26, 35, 34, 33,
        23, 22, 21, 54, 55, 56, 57, 58, 59, 60, 61, 62},
       {2,  3,  7,  6,  12, 13, 14, 27, 28, 29, 38, 37, 36,
        26, 25, 24, 63, 64, 65, 66, 67, 68, 69, 70, 71},
       {3,  4,  8,  7,  15, 16, 17, 30, 31, 32, 40, 40, 39,
        29, 28, 27, 72, 73, 74, 75, 76, 77, 78, 79, 80},
       {1,  5,  8,  4,  21, 22, 23, 44, 43, 42, 32, 31, 30,
        18, 19, 20, 83, 84, 85, 86, 87, 88, 81, 82, 89},
       {5,  6,  7,  8,  33, 34, 35, 36, 37, 38, 39, 40, 41,
        42, 43, 44, 90, 91, 92, 93, 94, 95, 96, 97, 98}}, // SFE_HEXA_125
      {{1,  4,  3, 2,  20, 19, 18, 17, 16, 15, 14, 13, 12,
        11, 10, 9, 45, 52, 51, 50, 49, 48, 47, 46, 53},
       {1,  2,  6,  5,  9,  10, 11, 24, 25, 26, 35, 34, 33,
        23, 22, 21, 54, 55, 56, 57, 58, 59, 60, 61, 62},
       {2,  3,  7,  6,  12, 13, 14, 27, 28, 29, 38, 37, 36,
        26, 25, 24, 63, 64, 65, 66, 67, 68, 69, 70, 71},
       {3,  4,  8,  7,  15, 16, 17, 30, 31, 32, 40, 40, 39,
        29, 28, 27, 72, 73, 74, 75, 76, 77, 78, 79, 80},
       {1,  5,  8,  4,  21, 22, 23, 44, 43, 42, 32, 31, 30,
        18, 19, 20, 83, 84, 85, 86, 87, 88, 81, 82, 89},
       {5,  6,  7,  8,  33, 34, 35, 36, 37, 38, 39, 40, 41,
        42, 43, 44, 90, 91, 92, 93, 94, 95, 96, 97, 98}}, // SFE_HEXA_FEK_125
      {{}},                                               // 242
      {{}},                                               // 243
      {{1,  4, 3,  2,  24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
        10, 9, 57, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 69, 72, 71, 70},
       {1,  2,  6,  5,  9,  10, 11, 12, 29, 30, 31, 32, 44, 43, 42, 41, 28, 27,
        26, 25, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88},
       {2,  3,  7,  6,  13, 14, 15, 16,  33,  34,  35,  36,
        48, 47, 46, 45, 32, 31, 30, 29,  89,  90,  91,  92,
        93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104},
       {3,   4,   8,   7,   17,  18,  19,  20,  37,  38,  39,  40,
        52,  51,  50,  49,  36,  35,  34,  33,  105, 106, 107, 108,
        109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
       {1,   5,   8,   4,   25,  26,  27,  28,  56,  55,  54,  53,
        40,  39,  38,  37,  21,  22,  23,  24,  124, 125, 126, 127,
        128, 129, 130, 131, 132, 121, 122, 123, 134, 135, 136, 133},
       {5,   6,   7,   8,   41,  42,  43,  44,  45,  46,  47,  48,  49,
        50,  51,  52,  53,  54,  55,  56,  137, 138, 139, 140, 141, 142,
        143, 144, 145, 146, 147, 148, 149, 150, 151, 152}}, // SFE_HEXA_216
      {{1,  4, 3,  2,  24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
        10, 9, 57, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 69, 72, 71, 70},
       {1,  2,  6,  5,  9,  10, 11, 12, 29, 30, 31, 32, 44, 43, 42, 41, 28, 27,
        26, 25, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88},
       {2,  3,  7,  6,  13, 14, 15, 16,  33,  34,  35,  36,
        48, 47, 46, 45, 32, 31, 30, 29,  89,  90,  91,  92,
        93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104},
       {3,   4,   8,   7,   17,  18,  19,  20,  37,  38,  39,  40,
        52,  51,  50,  49,  36,  35,  34,  33,  105, 106, 107, 108,
        109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
       {1,   5,   8,   4,   25,  26,  27,  28,  56,  55,  54,  53,
        40,  39,  38,  37,  21,  22,  23,  24,  124, 125, 126, 127,
        128, 129, 130, 131, 132, 121, 122, 123, 134, 135, 136, 133},
       {5,   6,   7,   8,   41,  42,  43,  44,  45,  46,  47,  48,  49,
        50,  51,  52,  53,  54,  55,  56,  137, 138, 139, 140, 141, 142,
        143, 144, 145, 146, 147, 148, 149, 150, 151, 152}}, // SFE_HEXA_FEK_216
      {{}},                                                 // 246
      {{}},                                                 // 247
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // SFE_HEXA_343
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // SFE_HEXA_FEK_343
  };
  *ret = [&](int et, uint8_T fid) {
    return FACETS[et - 36][fid];
  }(etype, static_cast<signed char>(facetid - 1));
  n = [&](int et, uint8_T fid) {
    return LIDS[et - 36][fid].size();
  }(etype, static_cast<signed char>(facetid - 1));
  *lids_size = n;
  [&](int et, uint8_T fid, int n, std::int16_t *v) {
    std::copy_n(LIDS[et - 36][fid].cbegin(), n, v);
  }(etype, static_cast<signed char>(facetid - 1), n, &lids_data[0]);
}

// obtain_facets - Query facet information
static unsigned char obtain_facets(coder::SizeType etype, signed char facetid)
{
  const static std::vector<std::vector<uint8_T>> FACETS{
      {1, 1},                         // SFE_BAR_2
      {},                             // 37
      {},                             // 38
      {},                             // 39
      {1, 1},                         // SFE_BAR_3
      {},                             // 41
      {},                             // 42
      {},                             // 43
      {1, 1},                         // SFE_BAR_4
      {1, 1},                         // SFE_BAR_FEK_4
      {},                             // 46
      {},                             // 47
      {1, 1},                         // SFE_BAR_5
      {1, 1},                         // SFE_BAR_FEK_5
      {},                             // 50
      {},                             // 51
      {1, 1},                         // SFE_BAR_6
      {1, 1},                         // SFE_BAR_FEK_6
      {},                             // 54
      {},                             // 55
      {1, 1},                         // SFE_BAR_7
      {1, 1},                         // SFE_BAR_FEK_7
      {},                             // 58
      {},                             // 59
      {},                             // 60
      {},                             // 61
      {},                             // 62
      {},                             // 63
      {},                             // 64
      {},                             // 65
      {},                             // 66
      {},                             // 67
      {36, 36, 36},                   // SFE_TRI_3
      {},                             // 69
      {},                             // 70
      {},                             // 71
      {40, 40, 40},                   // SFE_TRI_6
      {},                             // 73
      {},                             // 74
      {},                             // 75
      {44, 44, 44},                   // SFE_TRI_10
      {45, 45, 45},                   // SFE_TRI_FEK_10
      {},                             // 78
      {},                             // 79
      {48, 48, 48},                   // SFE_TRI_15
      {49, 49, 49},                   // SFE_TRI_GL_15
      {48, 48, 48},                   // SFE_TRI_FEK_15
      {},                             // 83
      {52, 52, 52},                   // SFE_TRI_21
      {53, 53, 53},                   // SFE_TRI_GL_21
      {52, 52, 52},                   // SFE_TRI_FEK_21
      {},                             // 87
      {56, 56, 56},                   // SFE_TRI_28
      {57, 57, 57},                   // SFE_TRI_GL_28
      {56, 56, 56},                   // SFE_TRI_FEK_28
      {},                             // 91
      {},                             // 92
      {},                             // 93
      {},                             // 94
      {},                             // 95
      {},                             // 96
      {},                             // 97
      {},                             // 98
      {},                             // 99
      {36, 36, 36, 36},               // SFE_QUAD_4
      {},                             // 101
      {},                             // 102
      {},                             // 103
      {40, 40, 40, 40},               // SFE_QUAD_9
      {},                             // 105
      {},                             // 106
      {},                             // 107
      {44, 44, 44, 44},               // SFE_QUAD_16
      {45, 45, 45, 45},               // SFE_QUAD_FEK_16
      {},                             // 110
      {},                             // 111
      {48, 48, 48, 48},               // SFE_QUAD_25
      {49, 49, 49, 49},               // SFE_QUAD_FEK_25
      {},                             // 114
      {},                             // 115
      {52, 52, 52, 52},               // SFE_QUAD_36
      {53, 53, 53, 53},               // SFE_QUAD_FEK_36
      {},                             // 118
      {},                             // 119
      {56, 56, 56, 56},               // SFE_QUAD_49
      {57, 57, 57, 57},               // SFE_QUAD_FEK_49
      {},                             // 122
      {},                             // 123
      {},                             // 124
      {},                             // 125
      {},                             // 126
      {},                             // 127
      {},                             // 128
      {},                             // 129
      {},                             // 130
      {},                             // 131
      {68, 68, 68, 68},               // SFE_TET_4
      {},                             // 133
      {},                             // 134
      {},                             // 135
      {72, 72, 72, 72},               // SFE_TET_10
      {},                             // 137
      {},                             // 138
      {},                             // 139
      {76, 76, 76, 76},               // SFE_TET_20
      {77, 77, 77, 77},               // SFE_TET_FEK_20
      {},                             // 142
      {},                             // 143
      {80, 80, 80, 80},               // SFE_TET_35
      {81, 81, 81, 81},               // SFE_TET_GL_35
      {82, 82, 82, 82},               // SFE_TET_FEK_35
      {},                             // 147
      {84, 84, 84, 84},               // SFE_TET_56
      {85, 85, 85, 85},               // SFE_TET_GL_56
      {86, 86, 86, 86},               // SFE_TET_FEK_56
      {},                             // 151
      {88, 88, 88, 88},               // SFE_TET_84
      {89, 89, 89, 89},               // SFE_TET_GL_84
      {90, 90, 90, 90},               // SFE_TET_FEK_84
      {},                             // 155
      {},                             // 156
      {},                             // 157
      {},                             // 158
      {},                             // 159
      {},                             // 160
      {},                             // 161
      {},                             // 162
      {},                             // 163
      {100, 68, 68, 68, 68},          // SFE_PYRA_5
      {},                             // 165
      {},                             // 166
      {},                             // 167
      {104, 72, 72, 72, 72},          // SFE_PYRA_14
      {},                             // 169
      {},                             // 170
      {},                             // 171
      {108, 76, 76, 76, 76},          // SFE_PYRA_30
      {109, 77, 77, 77, 77},          // SFE_PYRA_FEK_30
      {},                             // 174
      {},                             // 175
      {112, 80, 80, 80, 80},          // SFE_PYRA_55
      {113, 81, 81, 81, 81},          // SFE_PYRA_GL_55
      {112, 82, 82, 82, 82},          // SFE_PYRA_FEK_55
      {},                             // 179
      {116, 84, 84, 84, 84},          // SFE_PYRA_91
      {},                             // 181
      {},                             // 182
      {},                             // 183
      {},                             // 184
      {},                             // 185
      {},                             // 186
      {},                             // 187
      {},                             // 188
      {},                             // 189
      {},                             // 190
      {},                             // 191
      {},                             // 192
      {},                             // 193
      {},                             // 194
      {},                             // 195
      {100, 100, 100, 68, 68},        // SFE_PRISM_6
      {},                             // 197
      {},                             // 198
      {},                             // 199
      {104, 104, 104, 72, 72},        // SFE_PRISM_18
      {},                             // 201
      {},                             // 202
      {},                             // 203
      {108, 108, 108, 76, 76},        // SFE_PRISM_40
      {109, 109, 109, 77, 77},        // SFE_PRISM_FEK_40
      {},                             // 206
      {},                             // 207
      {112, 112, 112, 80, 80},        // SFE_PRISM_75
      {113, 113, 113, 81, 81},        // SFE_PRISM_GL_75
      {112, 112, 112, 82, 82},        // SFE_PRISM_FEK_75
      {},                             // 211
      {116, 116, 116, 84, 84},        // SFE_PRISM_126
      {117, 117, 117, 85, 85},        // SFE_PRISM_GL_126
      {},                             // 214
      {},                             // 215
      {},                             // 216
      {},                             // 217
      {},                             // 218
      {},                             // 219
      {},                             // 220
      {},                             // 221
      {},                             // 222
      {},                             // 223
      {},                             // 224
      {},                             // 225
      {},                             // 226
      {},                             // 227
      {100, 100, 100, 100, 100, 100}, // SFE_HEXA_8
      {},                             // 229
      {},                             // 230
      {},                             // 231
      {104, 104, 104, 104, 104, 104}, // SFE_HEXA_27
      {},                             // 233
      {},                             // 234
      {},                             // 235
      {108, 108, 108, 108, 108, 108}, // SFE_HEXA_64
      {109, 109, 109, 109, 109, 109}, // SFE_HEXA_FEK_64
      {},                             // 238
      {},                             // 239
      {112, 112, 112, 112, 112, 112}, // SFE_HEXA_125
      {113, 113, 113, 113, 113, 113}, // SFE_HEXA_FEK_125
      {},                             // 242
      {},                             // 243
      {116, 116, 116, 116, 116, 116}, // SFE_HEXA_216
      {117, 117, 117, 117, 117, 117}, // SFE_HEXA_FEK_216
      {},                             // 246
      {},                             // 247
      {120, 120, 120, 120, 120, 120}, // SFE_HEXA_343
      {121, 121, 121, 121, 121, 121}, // SFE_HEXA_FEK_343
  };
  const static std::vector<std::vector<std::vector<int16_T>>> LIDS{
      {{1}, {2}},                                             // SFE_BAR_2
      {{}},                                                   // 37
      {{}},                                                   // 38
      {{}},                                                   // 39
      {{1}, {2}},                                             // SFE_BAR_3
      {{}},                                                   // 41
      {{}},                                                   // 42
      {{}},                                                   // 43
      {{1}, {2}},                                             // SFE_BAR_4
      {{1}, {2}},                                             // SFE_BAR_FEK_4
      {{}},                                                   // 46
      {{}},                                                   // 47
      {{1}, {2}},                                             // SFE_BAR_5
      {{1}, {2}},                                             // SFE_BAR_FEK_5
      {{}},                                                   // 50
      {{}},                                                   // 51
      {{1}, {2}},                                             // SFE_BAR_6
      {{1}, {2}},                                             // SFE_BAR_FEK_6
      {{}},                                                   // 54
      {{}},                                                   // 55
      {{1}, {2}},                                             // SFE_BAR_7
      {{1}, {2}},                                             // SFE_BAR_FEK_7
      {{}},                                                   // 58
      {{}},                                                   // 59
      {{}},                                                   // 60
      {{}},                                                   // 61
      {{}},                                                   // 62
      {{}},                                                   // 63
      {{}},                                                   // 64
      {{}},                                                   // 65
      {{}},                                                   // 66
      {{}},                                                   // 67
      {{1, 2}, {2, 3}, {3, 1}},                               // SFE_TRI_3
      {{}},                                                   // 69
      {{}},                                                   // 70
      {{}},                                                   // 71
      {{1, 2, 4}, {2, 3, 5}, {3, 1, 6}},                      // SFE_TRI_6
      {{}},                                                   // 73
      {{}},                                                   // 74
      {{}},                                                   // 75
      {{1, 2, 4, 5}, {2, 3, 6, 7}, {3, 1, 8, 9}},             // SFE_TRI_10
      {{1, 2, 4, 5}, {2, 3, 6, 7}, {3, 1, 8, 9}},             // SFE_TRI_FEK_10
      {{}},                                                   // 78
      {{}},                                                   // 79
      {{1, 2, 4, 5, 6}, {2, 3, 7, 8, 9}, {3, 1, 10, 11, 12}}, // SFE_TRI_15
      {{1, 2, 4, 5, 6}, {2, 3, 7, 8, 9}, {3, 1, 10, 11, 12}}, // SFE_TRI_GL_15
      {{1, 2, 4, 5, 6}, {2, 3, 7, 8, 9}, {3, 1, 10, 11, 12}}, // SFE_TRI_FEK_15
      {{}},                                                   // 83
      {{1, 2, 4, 5, 6, 7},
       {2, 3, 8, 9, 10, 11},
       {3, 1, 12, 13, 14, 15}}, // SFE_TRI_21
      {{1, 2, 4, 5, 6, 7},
       {2, 3, 8, 9, 10, 11},
       {3, 1, 12, 13, 14, 15}}, // SFE_TRI_GL_21
      {{1, 2, 4, 5, 6, 7},
       {2, 3, 8, 9, 10, 11},
       {3, 1, 12, 13, 14, 15}}, // SFE_TRI_FEK_21
      {{}},                     // 87
      {{1, 2, 4, 5, 6, 7, 8},
       {2, 3, 9, 10, 11, 12, 13},
       {3, 1, 14, 15, 16, 17, 18}}, // SFE_TRI_28
      {{1, 2, 4, 5, 6, 7, 8},
       {2, 3, 9, 10, 11, 12, 13},
       {3, 1, 14, 15, 16, 17, 18}}, // SFE_TRI_GL_28
      {{1, 2, 4, 5, 6, 7, 8},
       {2, 3, 9, 10, 11, 12, 13},
       {3, 1, 14, 15, 16, 17, 18}},                 // SFE_TRI_FEK_28
      {{}},                                         // 91
      {{}},                                         // 92
      {{}},                                         // 93
      {{}},                                         // 94
      {{}},                                         // 95
      {{}},                                         // 96
      {{}},                                         // 97
      {{}},                                         // 98
      {{}},                                         // 99
      {{1, 2}, {2, 3}, {3, 4}, {4, 1}},             // SFE_QUAD_4
      {{}},                                         // 101
      {{}},                                         // 102
      {{}},                                         // 103
      {{1, 2, 5}, {2, 3, 6}, {3, 4, 7}, {4, 1, 8}}, // SFE_QUAD_9
      {{}},                                         // 105
      {{}},                                         // 106
      {{}},                                         // 107
      {{1, 2, 5, 6},
       {2, 3, 7, 8},
       {3, 4, 9, 10},
       {4, 1, 11, 12}}, // SFE_QUAD_16
      {{1, 2, 5, 6},
       {2, 3, 7, 8},
       {3, 4, 9, 10},
       {4, 1, 11, 12}}, // SFE_QUAD_FEK_16
      {{}},             // 110
      {{}},             // 111
      {{1, 2, 5, 6, 7},
       {2, 3, 8, 9, 10},
       {3, 4, 11, 12, 13},
       {4, 1, 14, 15, 16}}, // SFE_QUAD_25
      {{1, 2, 5, 6, 7},
       {2, 3, 8, 9, 10},
       {3, 4, 11, 12, 13},
       {4, 1, 14, 15, 16}}, // SFE_QUAD_FEK_25
      {{}},                 // 114
      {{}},                 // 115
      {{1, 2, 5, 6, 7, 8},
       {2, 3, 9, 10, 11, 12},
       {3, 4, 13, 14, 15, 16},
       {4, 1, 17, 18, 19, 20}}, // SFE_QUAD_36
      {{1, 2, 5, 6, 7, 8},
       {2, 3, 9, 10, 11, 12},
       {3, 4, 13, 14, 15, 16},
       {4, 1, 17, 18, 19, 20}}, // SFE_QUAD_FEK_36
      {{}},                     // 118
      {{}},                     // 119
      {{1, 2, 5, 6, 7, 8, 9},
       {2, 3, 10, 11, 12, 13, 14},
       {3, 4, 15, 16, 17, 18, 19},
       {4, 1, 20, 21, 22, 23, 24}}, // SFE_QUAD_49
      {{1, 2, 5, 6, 7, 8, 9},
       {2, 3, 10, 11, 12, 13, 14},
       {3, 4, 15, 16, 17, 18, 19},
       {4, 1, 20, 21, 22, 23, 24}},                 // SFE_QUAD_FEK_49
      {{}},                                         // 122
      {{}},                                         // 123
      {{}},                                         // 124
      {{}},                                         // 125
      {{}},                                         // 126
      {{}},                                         // 127
      {{}},                                         // 128
      {{}},                                         // 129
      {{}},                                         // 130
      {{}},                                         // 131
      {{1, 3, 2}, {1, 2, 4}, {2, 3, 4}, {3, 1, 4}}, // SFE_TET_4
      {{}},                                         // 133
      {{}},                                         // 134
      {{}},                                         // 135
      {{1, 3, 2, 7, 6, 5},
       {1, 2, 4, 5, 9, 8},
       {2, 3, 4, 6, 10, 9},
       {3, 1, 4, 7, 8, 10}}, // SFE_TET_10
      {{}},                  // 137
      {{}},                  // 138
      {{}},                  // 139
      {{1, 3, 2, 10, 9, 8, 7, 6, 5, 17},
       {1, 2, 4, 5, 6, 13, 14, 12, 11, 18},
       {2, 3, 4, 7, 8, 15, 16, 14, 13, 19},
       {3, 1, 4, 9, 10, 11, 12, 16, 15, 20}}, // SFE_TET_20
      {{1, 3, 2, 10, 9, 8, 7, 6, 5, 17},
       {1, 2, 4, 5, 6, 13, 14, 12, 11, 18},
       {2, 3, 4, 7, 8, 15, 16, 14, 13, 19},
       {3, 1, 4, 9, 10, 11, 12, 16, 15, 20}}, // SFE_TET_FEK_20
      {{}},                                   // 142
      {{}},                                   // 143
      {{1, 3, 2, 13, 12, 11, 10, 9, 8, 7, 6, 5, 23, 25, 24},
       {1, 2, 4, 5, 6, 7, 17, 18, 19, 16, 15, 14, 26, 27, 28},
       {2, 3, 4, 8, 9, 10, 20, 21, 22, 19, 18, 17, 29, 30, 31},
       {3, 1, 4, 11, 12, 13, 14, 15, 16, 22, 21, 20, 32, 33, 34}}, // SFE_TET_35
      {{1, 3, 2, 13, 12, 11, 10, 9, 8, 7, 6, 5, 23, 25, 24},
       {1, 2, 4, 5, 6, 7, 17, 18, 19, 16, 15, 14, 26, 27, 28},
       {2, 3, 4, 8, 9, 10, 20, 21, 22, 19, 18, 17, 29, 30, 31},
       {3, 1, 4, 11, 12, 13, 14, 15, 16, 22, 21, 20, 32, 33,
        34}}, // SFE_TET_GL_35
      {{1, 3, 2, 13, 12, 11, 10, 9, 8, 7, 6, 5, 23, 25, 24},
       {1, 2, 4, 5, 6, 7, 17, 18, 19, 16, 15, 14, 26, 27, 28},
       {2, 3, 4, 8, 9, 10, 20, 21, 22, 19, 18, 17, 29, 30, 31},
       {3, 1, 4, 11, 12, 13, 14, 15, 16, 22, 21, 20, 32, 33,
        34}}, // SFE_TET_FEK_35
      {{}},   // 147
      {{1, 3, 2, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 5,  29, 34, 33, 32, 31, 30},
       {1,  2,  4,  5,  6,  7,  8,  21, 22, 23, 24,
        20, 19, 18, 17, 35, 36, 37, 38, 39, 40},
       {2,  3,  4,  9,  10, 11, 12, 25, 26, 27, 28,
        24, 23, 22, 21, 41, 42, 43, 44, 45, 46},
       {3,  1,  4,  13, 14, 15, 16, 17, 18, 19, 20,
        28, 27, 26, 25, 47, 48, 49, 50, 51, 52}}, // SFE_TET_56
      {{1, 3, 2, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 5,  29, 34, 33, 32, 31, 30},
       {1,  2,  4,  5,  6,  7,  8,  21, 22, 23, 24,
        20, 19, 18, 17, 35, 36, 37, 38, 39, 40},
       {2,  3,  4,  9,  10, 11, 12, 25, 26, 27, 28,
        24, 23, 22, 21, 41, 42, 43, 44, 45, 46},
       {3,  1,  4,  13, 14, 15, 16, 17, 18, 19, 20,
        28, 27, 26, 25, 47, 48, 49, 50, 51, 52}}, // SFE_TET_GL_56
      {{1, 3, 2, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 5,  29, 34, 33, 32, 31, 30},
       {1,  2,  4,  5,  6,  7,  8,  21, 22, 23, 24,
        20, 19, 18, 17, 35, 36, 37, 38, 39, 40},
       {2,  3,  4,  9,  10, 11, 12, 25, 26, 27, 28,
        24, 23, 22, 21, 41, 42, 43, 44, 45, 46},
       {3,  1,  4,  13, 14, 15, 16, 17, 18, 19, 20,
        28, 27, 26, 25, 47, 48, 49, 50, 51, 52}}, // SFE_TET_FEK_56
      {{}},                                       // 151
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // SFE_TET_84
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // SFE_TET_GL_84
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // SFE_TET_FEK_84
      {{}},                                         // 155
      {{}},                                         // 156
      {{}},                                         // 157
      {{}},                                         // 158
      {{}},                                         // 159
      {{}},                                         // 160
      {{}},                                         // 161
      {{}},                                         // 162
      {{}},                                         // 163
      {{1, 4, 3, 2},
       {1, 2, 5, 0},
       {2, 3, 5, 0},
       {3, 4, 5, 0},
       {4, 1, 5, 0}}, // SFE_PYRA_5
      {{}},           // 165
      {{}},           // 166
      {{}},           // 167
      {{1, 4, 3, 2, 9, 8, 7, 6, 14},
       {1, 2, 5, 6, 11, 10, 0, 0, 0},
       {2, 3, 5, 7, 12, 11, 0, 0, 0},
       {3, 4, 5, 8, 13, 12, 0, 0, 0},
       {4, 1, 5, 9, 10, 13, 0, 0, 0}}, // SFE_PYRA_14
      {{}},                            // 169
      {{}},                            // 170
      {{}},                            // 171
      {{1, 4, 3, 2, 13, 12, 11, 10, 9, 8, 7, 6, 22, 25, 24, 23},
       {1, 2, 5, 6, 7, 16, 17, 15, 14, 26, 0, 0, 0, 0, 0, 0},
       {2, 3, 5, 8, 9, 18, 19, 17, 16, 27, 0, 0, 0, 0, 0, 0},
       {3, 4, 5, 10, 11, 20, 21, 19, 18, 28, 0, 0, 0, 0, 0, 0},
       {4, 1, 5, 12, 13, 14, 15, 21, 20, 29, 0, 0, 0, 0, 0, 0}}, // SFE_PYRA_30
      {{1, 4, 3, 2, 13, 12, 11, 10, 9, 8, 7, 6, 22, 25, 24, 23},
       {1, 2, 5, 6, 7, 16, 17, 15, 14, 26, 0, 0, 0, 0, 0, 0},
       {2, 3, 5, 8, 9, 18, 19, 17, 16, 27, 0, 0, 0, 0, 0, 0},
       {3, 4, 5, 10, 11, 20, 21, 19, 18, 28, 0, 0, 0, 0, 0, 0},
       {4, 1, 5, 12, 13, 14, 15, 21, 20, 29, 0, 0, 0, 0, 0,
        0}}, // SFE_PYRA_FEK_30
      {{}},  // 174
      {{}},  // 175
      {{1, 4, 3, 2,  17, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 30, 37, 36, 35, 34, 33, 32, 31, 38},
       {1,  2,  5, 6, 7, 8, 21, 22, 23, 20, 19, 18, 39,
        40, 41, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0},
       {2,  3,  5, 9, 10, 11, 24, 25, 26, 23, 22, 21, 42,
        43, 44, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0},
       {3,  4,  5, 12, 13, 14, 27, 28, 29, 26, 25, 24, 45,
        46, 47, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0},
       {4,  1,  5, 15, 16, 17, 18, 19, 20, 29, 28, 27, 48,
        49, 50, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PYRA_55
      {{1, 4, 3, 2,  17, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 30, 37, 36, 35, 34, 33, 32, 31, 38},
       {1,  2,  5, 6, 7, 8, 21, 22, 23, 20, 19, 18, 39,
        40, 41, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0},
       {2,  3,  5, 9, 10, 11, 24, 25, 26, 23, 22, 21, 42,
        43, 44, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0},
       {3,  4,  5, 12, 13, 14, 27, 28, 29, 26, 25, 24, 45,
        46, 47, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0},
       {4,  1,  5, 15, 16, 17, 18, 19, 20, 29, 28, 27, 48,
        49, 50, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PYRA_GL_55
      {{1, 4, 3, 2,  17, 16, 15, 14, 13, 12, 11, 10, 9,
        8, 7, 6, 30, 37, 36, 35, 34, 33, 32, 31, 38},
       {1,  2,  5, 6, 7, 8, 21, 22, 23, 20, 19, 18, 39,
        40, 41, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0},
       {2,  3,  5, 9, 10, 11, 24, 25, 26, 23, 22, 21, 42,
        43, 44, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0},
       {3,  4,  5, 12, 13, 14, 27, 28, 29, 26, 25, 24, 45,
        46, 47, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0},
       {4,  1,  5, 15, 16, 17, 18, 19, 20, 29, 28, 27, 48,
        49, 50, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PYRA_FEK_55
      {{}},                                             // 179
      {{1, 4, 3,  2,  21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9,  8,
        7, 6, 38, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 50, 53, 52, 51},
       {1,  2,  5,  6, 7, 8, 9, 26, 27, 28, 29, 25, 24, 23, 22, 54, 55, 56,
        57, 58, 59, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
       {2,  3,  5,  10, 11, 12, 13, 30, 31, 32, 33, 29, 28, 27, 26, 60, 61, 62,
        63, 64, 65, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
       {3,  4,  5,  14, 15, 16, 17, 34, 35, 36, 37, 33, 32, 31, 30, 66, 67, 68,
        69, 70, 71, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
       {4,  1,  5,  18, 19, 20, 21, 22, 23, 24, 25, 37,
        36, 35, 34, 72, 73, 74, 75, 76, 77, 0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PYRA_91
      {{}},                                              // 181
      {{}},                                              // 182
      {{}},                                              // 183
      {{}},                                              // 184
      {{}},                                              // 185
      {{}},                                              // 186
      {{}},                                              // 187
      {{}},                                              // 188
      {{}},                                              // 189
      {{}},                                              // 190
      {{}},                                              // 191
      {{}},                                              // 192
      {{}},                                              // 193
      {{}},                                              // 194
      {{}},                                              // 195
      {{1, 2, 5, 4},
       {2, 3, 6, 5},
       {3, 1, 4, 6},
       {1, 3, 2, 0},
       {4, 5, 6, 0}}, // SFE_PRISM_6
      {{}},           // 197
      {{}},           // 198
      {{}},           // 199
      {{1, 2, 5, 4, 7, 11, 13, 10, 16},
       {2, 3, 6, 5, 8, 12, 14, 11, 17},
       {3, 1, 4, 6, 9, 10, 15, 12, 18},
       {1, 3, 2, 9, 8, 7, 0, 0, 0},
       {4, 5, 6, 13, 14, 15, 0, 0, 0}}, // SFE_PRISM_18
      {{}},                             // 201
      {{}},                             // 202
      {{}},                             // 203
      {{1, 2, 5, 4, 7, 8, 15, 16, 20, 19, 14, 13, 26, 27, 28, 29},
       {2, 3, 6, 5, 9, 10, 17, 18, 22, 21, 16, 15, 30, 31, 32, 33},
       {3, 1, 4, 6, 11, 12, 13, 14, 24, 23, 18, 17, 34, 35, 36, 37},
       {1, 3, 2, 12, 11, 10, 9, 8, 7, 25, 0, 0, 0, 0, 0, 0},
       {4, 5, 6, 19, 20, 21, 22, 23, 24, 38, 0, 0, 0, 0, 0, 0}}, // SFE_PRISM_40
      {{1, 2, 5, 4, 7, 8, 15, 16, 20, 19, 14, 13, 26, 27, 28, 29},
       {2, 3, 6, 5, 9, 10, 17, 18, 22, 21, 16, 15, 30, 31, 32, 33},
       {3, 1, 4, 6, 11, 12, 13, 14, 24, 23, 18, 17, 34, 35, 36, 37},
       {1, 3, 2, 12, 11, 10, 9, 8, 7, 25, 0, 0, 0, 0, 0, 0},
       {4, 5, 6, 19, 20, 21, 22, 23, 24, 38, 0, 0, 0, 0, 0,
        0}}, // SFE_PRISM_FEK_40
      {{}},  // 206
      {{}},  // 207
      {{1,  2,  5,  4,  7,  8,  9,  19, 20, 21, 27, 26, 25,
        18, 17, 16, 37, 38, 39, 40, 41, 42, 43, 44, 45},
       {2,  3,  6,  5,  10, 11, 12, 22, 23, 24, 30, 29, 28,
        21, 20, 19, 46, 47, 48, 49, 50, 51, 52, 53, 54},
       {3,  1,  4,  6,  13, 14, 15, 16, 17, 18, 33, 32, 31,
        24, 23, 22, 55, 56, 57, 58, 59, 60, 61, 62, 63},
       {1,  3,  2, 15, 14, 13, 12, 11, 10, 9, 8, 7, 34,
        36, 35, 0, 0,  0,  0,  0,  0,  0,  0, 0, 0},
       {4,  5,  6, 25, 26, 27, 28, 29, 30, 31, 32, 33, 64,
        65, 66, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PRISM_75
      {{1,  2,  5,  4,  7,  8,  9,  19, 20, 21, 27, 26, 25,
        18, 17, 16, 37, 38, 39, 40, 41, 42, 43, 44, 45},
       {2,  3,  6,  5,  10, 11, 12, 22, 23, 24, 30, 29, 28,
        21, 20, 19, 46, 47, 48, 49, 50, 51, 52, 53, 54},
       {3,  1,  4,  6,  13, 14, 15, 16, 17, 18, 33, 32, 31,
        24, 23, 22, 55, 56, 57, 58, 59, 60, 61, 62, 63},
       {1,  3,  2, 15, 14, 13, 12, 11, 10, 9, 8, 7, 34,
        36, 35, 0, 0,  0,  0,  0,  0,  0,  0, 0, 0},
       {4,  5,  6, 25, 26, 27, 28, 29, 30, 31, 32, 33, 64,
        65, 66, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PRISM_GL_75
      {{1,  2,  5,  4,  7,  8,  9,  19, 20, 21, 27, 26, 25,
        18, 17, 16, 37, 38, 39, 40, 41, 42, 43, 44, 45},
       {2,  3,  6,  5,  10, 11, 12, 22, 23, 24, 30, 29, 28,
        21, 20, 19, 46, 47, 48, 49, 50, 51, 52, 53, 54},
       {3,  1,  4,  6,  13, 14, 15, 16, 17, 18, 33, 32, 31,
        24, 23, 22, 55, 56, 57, 58, 59, 60, 61, 62, 63},
       {1,  3,  2, 15, 14, 13, 12, 11, 10, 9, 8, 7, 34,
        36, 35, 0, 0,  0,  0,  0,  0,  0,  0, 0, 0},
       {4,  5,  6, 25, 26, 27, 28, 29, 30, 31, 32, 33, 64,
        65, 66, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0}}, // SFE_PRISM_FEK_75
      {{}},                                             // 211
      {{1,  2,  5,  4,  7,  8,  9,  10, 23, 24, 25, 26, 34, 33, 32, 31, 24, 23,
        22, 21, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58},
       {2,  3,  6,  5,  11, 12, 13, 14, 27, 28, 29, 30, 38, 37, 36, 35, 26, 25,
        24, 23, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74},
       {3,  1,  4,  6,  15, 16, 17, 18, 19, 20, 21, 22, 42, 41, 40, 39, 30, 29,
        28, 27, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
       {1,  3,  2,  18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 91, 96, 95,
        94, 93, 92, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0,  0},
       {4,  5,  6,  31, 32, 33, 34,  35,  36,  37, 38, 39,
        40, 41, 42, 97, 98, 99, 100, 101, 102, 0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,   0,   0,   0,  0,  0}}, // SFE_PRISM_126
      {{1,  2,  5,  4,  7,  8,  9,  10, 23, 24, 25, 26, 34, 33, 32, 31, 24, 23,
        22, 21, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58},
       {2,  3,  6,  5,  11, 12, 13, 14, 27, 28, 29, 30, 38, 37, 36, 35, 26, 25,
        24, 23, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74},
       {3,  1,  4,  6,  15, 16, 17, 18, 19, 20, 21, 22, 42, 41, 40, 39, 30, 29,
        28, 27, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
       {1,  3,  2,  18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 91, 96, 95,
        94, 93, 92, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0,  0},
       {4,  5,  6,  31, 32, 33, 34,  35,  36,  37, 38, 39,
        40, 41, 42, 97, 98, 99, 100, 101, 102, 0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,   0,   0,   0,  0,  0}}, // SFE_PRISM_GL_126
      {{}},                                                 // 214
      {{}},                                                 // 215
      {{}},                                                 // 216
      {{}},                                                 // 217
      {{}},                                                 // 218
      {{}},                                                 // 219
      {{}},                                                 // 220
      {{}},                                                 // 221
      {{}},                                                 // 222
      {{}},                                                 // 223
      {{}},                                                 // 224
      {{}},                                                 // 225
      {{}},                                                 // 226
      {{}},                                                 // 227
      {{1, 4, 3, 2},
       {1, 2, 6, 5},
       {2, 3, 7, 6},
       {3, 4, 8, 7},
       {1, 5, 8, 4},
       {5, 6, 7, 8}}, // SFE_HEXA_8
      {{}},           // 229
      {{}},           // 230
      {{}},           // 231
      {{1, 4, 3, 2, 12, 11, 10, 9, 21},
       {1, 2, 6, 5, 9, 14, 17, 13, 22},
       {2, 3, 7, 6, 10, 15, 18, 14, 23},
       {3, 4, 8, 7, 11, 16, 19, 15, 24},
       {1, 5, 8, 4, 13, 20, 16, 12, 25},
       {5, 6, 7, 8, 17, 18, 19, 20, 26}}, // SFE_HEXA_27
      {{}},                               // 233
      {{}},                               // 234
      {{}},                               // 235
      {{1, 4, 3, 2, 16, 15, 14, 13, 12, 11, 10, 9, 33, 36, 35, 34},
       {1, 2, 6, 5, 9, 10, 19, 20, 26, 25, 18, 17, 37, 38, 39, 40},
       {2, 3, 7, 6, 11, 12, 21, 22, 28, 27, 20, 19, 41, 42, 43, 44},
       {3, 4, 8, 7, 13, 14, 23, 24, 30, 29, 22, 21, 45, 46, 47, 48},
       {1, 5, 8, 4, 17, 18, 32, 31, 24, 23, 15, 16, 50, 51, 52, 49},
       {5, 6, 7, 8, 25, 26, 27, 28, 29, 30, 31, 32, 53, 54, 55,
        56}}, // SFE_HEXA_64
      {{1, 4, 3, 2, 16, 15, 14, 13, 12, 11, 10, 9, 33, 36, 35, 34},
       {1, 2, 6, 5, 9, 10, 19, 20, 26, 25, 18, 17, 37, 38, 39, 40},
       {2, 3, 7, 6, 11, 12, 21, 22, 28, 27, 20, 19, 41, 42, 43, 44},
       {3, 4, 8, 7, 13, 14, 23, 24, 30, 29, 22, 21, 45, 46, 47, 48},
       {1, 5, 8, 4, 17, 18, 32, 31, 24, 23, 15, 16, 50, 51, 52, 49},
       {5, 6, 7, 8, 25, 26, 27, 28, 29, 30, 31, 32, 53, 54, 55,
        56}}, // SFE_HEXA_FEK_64
      {{}},   // 238
      {{}},   // 239
      {{1,  4,  3, 2,  20, 19, 18, 17, 16, 15, 14, 13, 12,
        11, 10, 9, 45, 52, 51, 50, 49, 48, 47, 46, 53},
       {1,  2,  6,  5,  9,  10, 11, 24, 25, 26, 35, 34, 33,
        23, 22, 21, 54, 55, 56, 57, 58, 59, 60, 61, 62},
       {2,  3,  7,  6,  12, 13, 14, 27, 28, 29, 38, 37, 36,
        26, 25, 24, 63, 64, 65, 66, 67, 68, 69, 70, 71},
       {3,  4,  8,  7,  15, 16, 17, 30, 31, 32, 40, 40, 39,
        29, 28, 27, 72, 73, 74, 75, 76, 77, 78, 79, 80},
       {1,  5,  8,  4,  21, 22, 23, 44, 43, 42, 32, 31, 30,
        18, 19, 20, 83, 84, 85, 86, 87, 88, 81, 82, 89},
       {5,  6,  7,  8,  33, 34, 35, 36, 37, 38, 39, 40, 41,
        42, 43, 44, 90, 91, 92, 93, 94, 95, 96, 97, 98}}, // SFE_HEXA_125
      {{1,  4,  3, 2,  20, 19, 18, 17, 16, 15, 14, 13, 12,
        11, 10, 9, 45, 52, 51, 50, 49, 48, 47, 46, 53},
       {1,  2,  6,  5,  9,  10, 11, 24, 25, 26, 35, 34, 33,
        23, 22, 21, 54, 55, 56, 57, 58, 59, 60, 61, 62},
       {2,  3,  7,  6,  12, 13, 14, 27, 28, 29, 38, 37, 36,
        26, 25, 24, 63, 64, 65, 66, 67, 68, 69, 70, 71},
       {3,  4,  8,  7,  15, 16, 17, 30, 31, 32, 40, 40, 39,
        29, 28, 27, 72, 73, 74, 75, 76, 77, 78, 79, 80},
       {1,  5,  8,  4,  21, 22, 23, 44, 43, 42, 32, 31, 30,
        18, 19, 20, 83, 84, 85, 86, 87, 88, 81, 82, 89},
       {5,  6,  7,  8,  33, 34, 35, 36, 37, 38, 39, 40, 41,
        42, 43, 44, 90, 91, 92, 93, 94, 95, 96, 97, 98}}, // SFE_HEXA_FEK_125
      {{}},                                               // 242
      {{}},                                               // 243
      {{1,  4, 3,  2,  24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
        10, 9, 57, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 69, 72, 71, 70},
       {1,  2,  6,  5,  9,  10, 11, 12, 29, 30, 31, 32, 44, 43, 42, 41, 28, 27,
        26, 25, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88},
       {2,  3,  7,  6,  13, 14, 15, 16,  33,  34,  35,  36,
        48, 47, 46, 45, 32, 31, 30, 29,  89,  90,  91,  92,
        93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104},
       {3,   4,   8,   7,   17,  18,  19,  20,  37,  38,  39,  40,
        52,  51,  50,  49,  36,  35,  34,  33,  105, 106, 107, 108,
        109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
       {1,   5,   8,   4,   25,  26,  27,  28,  56,  55,  54,  53,
        40,  39,  38,  37,  21,  22,  23,  24,  124, 125, 126, 127,
        128, 129, 130, 131, 132, 121, 122, 123, 134, 135, 136, 133},
       {5,   6,   7,   8,   41,  42,  43,  44,  45,  46,  47,  48,  49,
        50,  51,  52,  53,  54,  55,  56,  137, 138, 139, 140, 141, 142,
        143, 144, 145, 146, 147, 148, 149, 150, 151, 152}}, // SFE_HEXA_216
      {{1,  4, 3,  2,  24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
        10, 9, 57, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 69, 72, 71, 70},
       {1,  2,  6,  5,  9,  10, 11, 12, 29, 30, 31, 32, 44, 43, 42, 41, 28, 27,
        26, 25, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88},
       {2,  3,  7,  6,  13, 14, 15, 16,  33,  34,  35,  36,
        48, 47, 46, 45, 32, 31, 30, 29,  89,  90,  91,  92,
        93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104},
       {3,   4,   8,   7,   17,  18,  19,  20,  37,  38,  39,  40,
        52,  51,  50,  49,  36,  35,  34,  33,  105, 106, 107, 108,
        109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
       {1,   5,   8,   4,   25,  26,  27,  28,  56,  55,  54,  53,
        40,  39,  38,  37,  21,  22,  23,  24,  124, 125, 126, 127,
        128, 129, 130, 131, 132, 121, 122, 123, 134, 135, 136, 133},
       {5,   6,   7,   8,   41,  42,  43,  44,  45,  46,  47,  48,  49,
        50,  51,  52,  53,  54,  55,  56,  137, 138, 139, 140, 141, 142,
        143, 144, 145, 146, 147, 148, 149, 150, 151, 152}}, // SFE_HEXA_FEK_216
      {{}},                                                 // 246
      {{}},                                                 // 247
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // SFE_HEXA_343
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // SFE_HEXA_FEK_343
  };
  return [&](int et, uint8_T fid) {
    return FACETS[et - 36][fid];
  }(etype, static_cast<signed char>(facetid - 1));
}

// obtain_facets - Query facet information
static unsigned char obtain_facets(coder::SizeType etype)
{
  const static std::vector<std::vector<uint8_T>> FACETS{
      {1, 1},                         // SFE_BAR_2
      {},                             // 37
      {},                             // 38
      {},                             // 39
      {1, 1},                         // SFE_BAR_3
      {},                             // 41
      {},                             // 42
      {},                             // 43
      {1, 1},                         // SFE_BAR_4
      {1, 1},                         // SFE_BAR_FEK_4
      {},                             // 46
      {},                             // 47
      {1, 1},                         // SFE_BAR_5
      {1, 1},                         // SFE_BAR_FEK_5
      {},                             // 50
      {},                             // 51
      {1, 1},                         // SFE_BAR_6
      {1, 1},                         // SFE_BAR_FEK_6
      {},                             // 54
      {},                             // 55
      {1, 1},                         // SFE_BAR_7
      {1, 1},                         // SFE_BAR_FEK_7
      {},                             // 58
      {},                             // 59
      {},                             // 60
      {},                             // 61
      {},                             // 62
      {},                             // 63
      {},                             // 64
      {},                             // 65
      {},                             // 66
      {},                             // 67
      {36, 36, 36},                   // SFE_TRI_3
      {},                             // 69
      {},                             // 70
      {},                             // 71
      {40, 40, 40},                   // SFE_TRI_6
      {},                             // 73
      {},                             // 74
      {},                             // 75
      {44, 44, 44},                   // SFE_TRI_10
      {45, 45, 45},                   // SFE_TRI_FEK_10
      {},                             // 78
      {},                             // 79
      {48, 48, 48},                   // SFE_TRI_15
      {49, 49, 49},                   // SFE_TRI_GL_15
      {48, 48, 48},                   // SFE_TRI_FEK_15
      {},                             // 83
      {52, 52, 52},                   // SFE_TRI_21
      {53, 53, 53},                   // SFE_TRI_GL_21
      {52, 52, 52},                   // SFE_TRI_FEK_21
      {},                             // 87
      {56, 56, 56},                   // SFE_TRI_28
      {57, 57, 57},                   // SFE_TRI_GL_28
      {56, 56, 56},                   // SFE_TRI_FEK_28
      {},                             // 91
      {},                             // 92
      {},                             // 93
      {},                             // 94
      {},                             // 95
      {},                             // 96
      {},                             // 97
      {},                             // 98
      {},                             // 99
      {36, 36, 36, 36},               // SFE_QUAD_4
      {},                             // 101
      {},                             // 102
      {},                             // 103
      {40, 40, 40, 40},               // SFE_QUAD_9
      {},                             // 105
      {},                             // 106
      {},                             // 107
      {44, 44, 44, 44},               // SFE_QUAD_16
      {45, 45, 45, 45},               // SFE_QUAD_FEK_16
      {},                             // 110
      {},                             // 111
      {48, 48, 48, 48},               // SFE_QUAD_25
      {49, 49, 49, 49},               // SFE_QUAD_FEK_25
      {},                             // 114
      {},                             // 115
      {52, 52, 52, 52},               // SFE_QUAD_36
      {53, 53, 53, 53},               // SFE_QUAD_FEK_36
      {},                             // 118
      {},                             // 119
      {56, 56, 56, 56},               // SFE_QUAD_49
      {57, 57, 57, 57},               // SFE_QUAD_FEK_49
      {},                             // 122
      {},                             // 123
      {},                             // 124
      {},                             // 125
      {},                             // 126
      {},                             // 127
      {},                             // 128
      {},                             // 129
      {},                             // 130
      {},                             // 131
      {68, 68, 68, 68},               // SFE_TET_4
      {},                             // 133
      {},                             // 134
      {},                             // 135
      {72, 72, 72, 72},               // SFE_TET_10
      {},                             // 137
      {},                             // 138
      {},                             // 139
      {76, 76, 76, 76},               // SFE_TET_20
      {77, 77, 77, 77},               // SFE_TET_FEK_20
      {},                             // 142
      {},                             // 143
      {80, 80, 80, 80},               // SFE_TET_35
      {81, 81, 81, 81},               // SFE_TET_GL_35
      {82, 82, 82, 82},               // SFE_TET_FEK_35
      {},                             // 147
      {84, 84, 84, 84},               // SFE_TET_56
      {85, 85, 85, 85},               // SFE_TET_GL_56
      {86, 86, 86, 86},               // SFE_TET_FEK_56
      {},                             // 151
      {88, 88, 88, 88},               // SFE_TET_84
      {89, 89, 89, 89},               // SFE_TET_GL_84
      {90, 90, 90, 90},               // SFE_TET_FEK_84
      {},                             // 155
      {},                             // 156
      {},                             // 157
      {},                             // 158
      {},                             // 159
      {},                             // 160
      {},                             // 161
      {},                             // 162
      {},                             // 163
      {100, 68, 68, 68, 68},          // SFE_PYRA_5
      {},                             // 165
      {},                             // 166
      {},                             // 167
      {104, 72, 72, 72, 72},          // SFE_PYRA_14
      {},                             // 169
      {},                             // 170
      {},                             // 171
      {108, 76, 76, 76, 76},          // SFE_PYRA_30
      {109, 77, 77, 77, 77},          // SFE_PYRA_FEK_30
      {},                             // 174
      {},                             // 175
      {112, 80, 80, 80, 80},          // SFE_PYRA_55
      {113, 81, 81, 81, 81},          // SFE_PYRA_GL_55
      {112, 82, 82, 82, 82},          // SFE_PYRA_FEK_55
      {},                             // 179
      {116, 84, 84, 84, 84},          // SFE_PYRA_91
      {},                             // 181
      {},                             // 182
      {},                             // 183
      {},                             // 184
      {},                             // 185
      {},                             // 186
      {},                             // 187
      {},                             // 188
      {},                             // 189
      {},                             // 190
      {},                             // 191
      {},                             // 192
      {},                             // 193
      {},                             // 194
      {},                             // 195
      {100, 100, 100, 68, 68},        // SFE_PRISM_6
      {},                             // 197
      {},                             // 198
      {},                             // 199
      {104, 104, 104, 72, 72},        // SFE_PRISM_18
      {},                             // 201
      {},                             // 202
      {},                             // 203
      {108, 108, 108, 76, 76},        // SFE_PRISM_40
      {109, 109, 109, 77, 77},        // SFE_PRISM_FEK_40
      {},                             // 206
      {},                             // 207
      {112, 112, 112, 80, 80},        // SFE_PRISM_75
      {113, 113, 113, 81, 81},        // SFE_PRISM_GL_75
      {112, 112, 112, 82, 82},        // SFE_PRISM_FEK_75
      {},                             // 211
      {116, 116, 116, 84, 84},        // SFE_PRISM_126
      {117, 117, 117, 85, 85},        // SFE_PRISM_GL_126
      {},                             // 214
      {},                             // 215
      {},                             // 216
      {},                             // 217
      {},                             // 218
      {},                             // 219
      {},                             // 220
      {},                             // 221
      {},                             // 222
      {},                             // 223
      {},                             // 224
      {},                             // 225
      {},                             // 226
      {},                             // 227
      {100, 100, 100, 100, 100, 100}, // SFE_HEXA_8
      {},                             // 229
      {},                             // 230
      {},                             // 231
      {104, 104, 104, 104, 104, 104}, // SFE_HEXA_27
      {},                             // 233
      {},                             // 234
      {},                             // 235
      {108, 108, 108, 108, 108, 108}, // SFE_HEXA_64
      {109, 109, 109, 109, 109, 109}, // SFE_HEXA_FEK_64
      {},                             // 238
      {},                             // 239
      {112, 112, 112, 112, 112, 112}, // SFE_HEXA_125
      {113, 113, 113, 113, 113, 113}, // SFE_HEXA_FEK_125
      {},                             // 242
      {},                             // 243
      {116, 116, 116, 116, 116, 116}, // SFE_HEXA_216
      {117, 117, 117, 117, 117, 117}, // SFE_HEXA_FEK_216
      {},                             // 246
      {},                             // 247
      {120, 120, 120, 120, 120, 120}, // SFE_HEXA_343
      {121, 121, 121, 121, 121, 121}, // SFE_HEXA_FEK_343
  };
  //  get the number of facets
  return [&](uint8_T et) { return FACETS[et - 36].size(); }(etype);
}

//  pyra_quadrules - Obtain quadrature points and weights of a pyramidal
static void pyra_quadrules(coder::SizeType degree,
                           ::coder::array<double, 2U> &cs,
                           ::coder::array<double, 1U> &ws)
{
  coder::SizeType nqp;
  boolean_T guard1{false};
  boolean_T guard2{false};
  boolean_T guard3{false};
  boolean_T guard4{false};
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  switch (degree) {
  case 0:
    guard1 = true;
    break;
  case 1:
    guard1 = true;
    break;
  case 2:
    nqp = ::sfe_qrules::pyra_deg2_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg2_qrule(&cs[0], &(ws.data())[0]);
    break;
  case 3:
    nqp = ::sfe_qrules::pyra_deg3_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg3_qrule(&cs[0], &(ws.data())[0]);
    break;
  case 4:
    guard2 = true;
    break;
  case 5:
    guard2 = true;
    break;
  case 6:
    nqp = ::sfe_qrules::pyra_deg6_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg6_qrule(&cs[0], &(ws.data())[0]);
    break;
  case 7:
    nqp = ::sfe_qrules::pyra_deg7_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg7_qrule(&cs[0], &(ws.data())[0]);
    break;
  case 8:
    guard3 = true;
    break;
  case 9:
    guard3 = true;
    break;
  case 10:
    guard4 = true;
    break;
  case 11:
    guard4 = true;
    break;
  default:
    if (degree > 13) {
      m2cWarnMsgIdAndTxt("pyra_quadrules:UnsupportedDegree",
                         "Only support up to degree 13");
    }
    nqp = ::sfe_qrules::pyra_deg13_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg13_qrule(&cs[0], &(ws.data())[0]);
    break;
  }
  if (guard4) {
    nqp = ::sfe_qrules::pyra_deg11_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg11_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard3) {
    m2cAssert(degree <= 9, "Only support up to degree 9");
    nqp = ::sfe_qrules::pyra_deg9_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg9_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard2) {
    m2cAssert(degree <= 5, "Only support up to degree 5");
    nqp = ::sfe_qrules::pyra_deg5_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg5_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard1) {
    nqp = ::sfe_qrules::pyra_deg1_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg1_qrule(&cs[0], &(ws.data())[0]);
  }
}

static void sfe1_tabulate_shapefuncs(coder::SizeType etype,
                                     const ::coder::array<double, 2U> &cs,
                                     ::coder::array<double, 2U> &sfvals,
                                     ::coder::array<double, 3U> &sdvals)
{
  coder::SizeType i;
  coder::SizeType nqp;
  //  Tabulate shape functions and derivative at given points.
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  if ((etype & 3) == 0) {
    switch (etype) {
    case 36: {
      coder::SizeType i1;
      boolean_T b;
      boolean_T b1;
      b = true;
      b1 = ((cs.size(1) <= 0) || (cs.size(0) <= 0));
      i = cs.size(1) * cs.size(0);
      i1 = 0;
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double N[2];
        double deriv[2];
        if (b1 || (q >= i)) {
          i1 = 0;
          b = true;
        } else if (b) {
          b = false;
          i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
        } else {
          coder::SizeType i2;
          i2 = cs.size(1) * cs.size(0) - 1;
          if (i1 > MAX_int32_T - cs.size(1)) {
            i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
          } else {
            i1 += cs.size(1);
            if (i1 > i2) {
              i1 -= i2;
            }
          }
        }
        ::sfe_sfuncs::bar_2_sfunc(cs[i1], &N[0], &deriv[0]);
        sfvals[sfvals.size(1) * q] = N[0];
        sdvals[sdvals.size(2) * sdvals.size(1) * q] = deriv[0];
        sfvals[sfvals.size(1) * q + 1] = N[1];
        sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = deriv[1];
      }
    } break;
    case 40: {
      coder::SizeType i1;
      boolean_T b;
      boolean_T b1;
      b = true;
      b1 = ((cs.size(1) <= 0) || (cs.size(0) <= 0));
      i = cs.size(1) * cs.size(0);
      i1 = 0;
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double b_N[3];
        double b_deriv[3];
        if (b1 || (q >= i)) {
          i1 = 0;
          b = true;
        } else if (b) {
          b = false;
          i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
        } else {
          coder::SizeType i2;
          i2 = cs.size(1) * cs.size(0) - 1;
          if (i1 > MAX_int32_T - cs.size(1)) {
            i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
          } else {
            i1 += cs.size(1);
            if (i1 > i2) {
              i1 -= i2;
            }
          }
        }
        ::sfe_sfuncs::bar_3_sfunc(cs[i1], &b_N[0], &b_deriv[0]);
        sfvals[sfvals.size(1) * q] = b_N[0];
        sdvals[sdvals.size(2) * sdvals.size(1) * q] = b_deriv[0];
        sfvals[sfvals.size(1) * q + 1] = b_N[1];
        sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] =
            b_deriv[1];
        sfvals[sfvals.size(1) * q + 2] = b_N[2];
        sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
            b_deriv[2];
      }
    } break;
    case 44: {
      coder::SizeType i1;
      boolean_T b;
      boolean_T b1;
      b = true;
      b1 = ((cs.size(1) <= 0) || (cs.size(0) <= 0));
      i = cs.size(1) * cs.size(0);
      i1 = 0;
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double c_N[4];
        double c_deriv[4];
        if (b1 || (q >= i)) {
          i1 = 0;
          b = true;
        } else if (b) {
          b = false;
          i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
        } else {
          coder::SizeType i2;
          i2 = cs.size(1) * cs.size(0) - 1;
          if (i1 > MAX_int32_T - cs.size(1)) {
            i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
          } else {
            i1 += cs.size(1);
            if (i1 > i2) {
              i1 -= i2;
            }
          }
        }
        ::sfe_sfuncs::bar_4_sfunc(cs[i1], &c_N[0], &c_deriv[0]);
        sfvals[sfvals.size(1) * q] = c_N[0];
        sdvals[sdvals.size(2) * sdvals.size(1) * q] = c_deriv[0];
        sfvals[sfvals.size(1) * q + 1] = c_N[1];
        sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] =
            c_deriv[1];
        sfvals[sfvals.size(1) * q + 2] = c_N[2];
        sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
            c_deriv[2];
        sfvals[sfvals.size(1) * q + 3] = c_N[3];
        sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
            c_deriv[3];
      }
    } break;
    case 48: {
      coder::SizeType i1;
      boolean_T b;
      boolean_T b1;
      b = true;
      b1 = ((cs.size(1) <= 0) || (cs.size(0) <= 0));
      i = cs.size(1) * cs.size(0);
      i1 = 0;
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double d_N[5];
        double d_deriv[5];
        if (b1 || (q >= i)) {
          i1 = 0;
          b = true;
        } else if (b) {
          b = false;
          i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
        } else {
          coder::SizeType i2;
          i2 = cs.size(1) * cs.size(0) - 1;
          if (i1 > MAX_int32_T - cs.size(1)) {
            i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
          } else {
            i1 += cs.size(1);
            if (i1 > i2) {
              i1 -= i2;
            }
          }
        }
        ::sfe_sfuncs::bar_5_sfunc(cs[i1], &d_N[0], &d_deriv[0]);
        sfvals[sfvals.size(1) * q] = d_N[0];
        sdvals[sdvals.size(2) * sdvals.size(1) * q] = d_deriv[0];
        sfvals[sfvals.size(1) * q + 1] = d_N[1];
        sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[1];
        sfvals[sfvals.size(1) * q + 2] = d_N[2];
        sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[2];
        sfvals[sfvals.size(1) * q + 3] = d_N[3];
        sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[3];
        sfvals[sfvals.size(1) * q + 4] = d_N[4];
        sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[4];
      }
    } break;
    case 52: {
      coder::SizeType i1;
      boolean_T b;
      boolean_T b1;
      b = true;
      b1 = ((cs.size(1) <= 0) || (cs.size(0) <= 0));
      i = cs.size(1) * cs.size(0);
      i1 = 0;
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double e_N[6];
        double e_deriv[6];
        if (b1 || (q >= i)) {
          i1 = 0;
          b = true;
        } else if (b) {
          b = false;
          i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
        } else {
          coder::SizeType i2;
          i2 = cs.size(1) * cs.size(0) - 1;
          if (i1 > MAX_int32_T - cs.size(1)) {
            i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
          } else {
            i1 += cs.size(1);
            if (i1 > i2) {
              i1 -= i2;
            }
          }
        }
        ::sfe_sfuncs::bar_6_sfunc(cs[i1], &e_N[0], &e_deriv[0]);
        sfvals[sfvals.size(1) * q] = e_N[0];
        sdvals[sdvals.size(2) * sdvals.size(1) * q] = e_deriv[0];
        sfvals[sfvals.size(1) * q + 1] = e_N[1];
        sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] =
            e_deriv[1];
        sfvals[sfvals.size(1) * q + 2] = e_N[2];
        sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
            e_deriv[2];
        sfvals[sfvals.size(1) * q + 3] = e_N[3];
        sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
            e_deriv[3];
        sfvals[sfvals.size(1) * q + 4] = e_N[4];
        sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
            e_deriv[4];
        sfvals[sfvals.size(1) * q + 5] = e_N[5];
        sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
            e_deriv[5];
      }
    } break;
    default: {
      coder::SizeType i1;
      boolean_T b;
      boolean_T b1;
      m2cAssert(etype == 56, "Only support up to sextic.");
      b = true;
      b1 = ((cs.size(1) <= 0) || (cs.size(0) <= 0));
      i = cs.size(1) * cs.size(0);
      i1 = 0;
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double f_N[7];
        double f_deriv[7];
        if (b1 || (q >= i)) {
          i1 = 0;
          b = true;
        } else if (b) {
          b = false;
          i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
        } else {
          coder::SizeType i2;
          i2 = cs.size(1) * cs.size(0) - 1;
          if (i1 > MAX_int32_T - cs.size(1)) {
            i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
          } else {
            i1 += cs.size(1);
            if (i1 > i2) {
              i1 -= i2;
            }
          }
        }
        ::sfe_sfuncs::bar_7_sfunc(cs[i1], &f_N[0], &f_deriv[0]);
        sfvals[sfvals.size(1) * q] = f_N[0];
        sdvals[sdvals.size(2) * sdvals.size(1) * q] = f_deriv[0];
        sfvals[sfvals.size(1) * q + 1] = f_N[1];
        sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[1];
        sfvals[sfvals.size(1) * q + 2] = f_N[2];
        sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[2];
        sfvals[sfvals.size(1) * q + 3] = f_N[3];
        sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[3];
        sfvals[sfvals.size(1) * q + 4] = f_N[4];
        sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[4];
        sfvals[sfvals.size(1) * q + 5] = f_N[5];
        sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[5];
        sfvals[sfvals.size(1) * q + 6] = f_N[6];
        sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[6];
      }
    } break;
    }
  } else {
    //  GL
    switch (etype) {
    case 45: {
      coder::SizeType i1;
      boolean_T b;
      boolean_T b1;
      b = true;
      b1 = ((cs.size(1) <= 0) || (cs.size(0) <= 0));
      i = cs.size(1) * cs.size(0);
      i1 = 0;
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double c_N[4];
        double c_deriv[4];
        if (b1 || (q >= i)) {
          i1 = 0;
          b = true;
        } else if (b) {
          b = false;
          i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
        } else {
          coder::SizeType i2;
          i2 = cs.size(1) * cs.size(0) - 1;
          if (i1 > MAX_int32_T - cs.size(1)) {
            i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
          } else {
            i1 += cs.size(1);
            if (i1 > i2) {
              i1 -= i2;
            }
          }
        }
        ::sfe_sfuncs::bar_gl_4_sfunc(cs[i1], &c_N[0], &c_deriv[0]);
        sfvals[sfvals.size(1) * q] = c_N[0];
        sdvals[sdvals.size(2) * sdvals.size(1) * q] = c_deriv[0];
        sfvals[sfvals.size(1) * q + 1] = c_N[1];
        sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] =
            c_deriv[1];
        sfvals[sfvals.size(1) * q + 2] = c_N[2];
        sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
            c_deriv[2];
        sfvals[sfvals.size(1) * q + 3] = c_N[3];
        sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
            c_deriv[3];
      }
    } break;
    case 49: {
      coder::SizeType i1;
      boolean_T b;
      boolean_T b1;
      b = true;
      b1 = ((cs.size(1) <= 0) || (cs.size(0) <= 0));
      i = cs.size(1) * cs.size(0);
      i1 = 0;
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double d_N[5];
        double d_deriv[5];
        if (b1 || (q >= i)) {
          i1 = 0;
          b = true;
        } else if (b) {
          b = false;
          i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
        } else {
          coder::SizeType i2;
          i2 = cs.size(1) * cs.size(0) - 1;
          if (i1 > MAX_int32_T - cs.size(1)) {
            i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
          } else {
            i1 += cs.size(1);
            if (i1 > i2) {
              i1 -= i2;
            }
          }
        }
        ::sfe_sfuncs::bar_gl_5_sfunc(cs[i1], &d_N[0], &d_deriv[0]);
        sfvals[sfvals.size(1) * q] = d_N[0];
        sdvals[sdvals.size(2) * sdvals.size(1) * q] = d_deriv[0];
        sfvals[sfvals.size(1) * q + 1] = d_N[1];
        sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[1];
        sfvals[sfvals.size(1) * q + 2] = d_N[2];
        sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[2];
        sfvals[sfvals.size(1) * q + 3] = d_N[3];
        sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[3];
        sfvals[sfvals.size(1) * q + 4] = d_N[4];
        sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[4];
      }
    } break;
    case 53: {
      coder::SizeType i1;
      boolean_T b;
      boolean_T b1;
      b = true;
      b1 = ((cs.size(1) <= 0) || (cs.size(0) <= 0));
      i = cs.size(1) * cs.size(0);
      i1 = 0;
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double e_N[6];
        double e_deriv[6];
        if (b1 || (q >= i)) {
          i1 = 0;
          b = true;
        } else if (b) {
          b = false;
          i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
        } else {
          coder::SizeType i2;
          i2 = cs.size(1) * cs.size(0) - 1;
          if (i1 > MAX_int32_T - cs.size(1)) {
            i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
          } else {
            i1 += cs.size(1);
            if (i1 > i2) {
              i1 -= i2;
            }
          }
        }
        ::sfe_sfuncs::bar_gl_6_sfunc(cs[i1], &e_N[0], &e_deriv[0]);
        sfvals[sfvals.size(1) * q] = e_N[0];
        sdvals[sdvals.size(2) * sdvals.size(1) * q] = e_deriv[0];
        sfvals[sfvals.size(1) * q + 1] = e_N[1];
        sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] =
            e_deriv[1];
        sfvals[sfvals.size(1) * q + 2] = e_N[2];
        sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
            e_deriv[2];
        sfvals[sfvals.size(1) * q + 3] = e_N[3];
        sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
            e_deriv[3];
        sfvals[sfvals.size(1) * q + 4] = e_N[4];
        sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
            e_deriv[4];
        sfvals[sfvals.size(1) * q + 5] = e_N[5];
        sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
            e_deriv[5];
      }
    } break;
    default: {
      coder::SizeType i1;
      boolean_T b;
      boolean_T b1;
      m2cAssert(etype == 57, "Only support up to sextic.");
      b = true;
      b1 = ((cs.size(1) <= 0) || (cs.size(0) <= 0));
      i = cs.size(1) * cs.size(0);
      i1 = 0;
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double f_N[7];
        double f_deriv[7];
        if (b1 || (q >= i)) {
          i1 = 0;
          b = true;
        } else if (b) {
          b = false;
          i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
        } else {
          coder::SizeType i2;
          i2 = cs.size(1) * cs.size(0) - 1;
          if (i1 > MAX_int32_T - cs.size(1)) {
            i1 = q % cs.size(0) * cs.size(1) + q / cs.size(0);
          } else {
            i1 += cs.size(1);
            if (i1 > i2) {
              i1 -= i2;
            }
          }
        }
        ::sfe_sfuncs::bar_gl_7_sfunc(cs[i1], &f_N[0], &f_deriv[0]);
        sfvals[sfvals.size(1) * q] = f_N[0];
        sdvals[sdvals.size(2) * sdvals.size(1) * q] = f_deriv[0];
        sfvals[sfvals.size(1) * q + 1] = f_N[1];
        sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[1];
        sfvals[sfvals.size(1) * q + 2] = f_N[2];
        sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[2];
        sfvals[sfvals.size(1) * q + 3] = f_N[3];
        sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[3];
        sfvals[sfvals.size(1) * q + 4] = f_N[4];
        sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[4];
        sfvals[sfvals.size(1) * q + 5] = f_N[5];
        sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[5];
        sfvals[sfvals.size(1) * q + 6] = f_N[6];
        sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[6];
      }
    } break;
    }
  }
}

static void sfe2_tabulate_equi_tri(coder::SizeType etype,
                                   const ::coder::array<double, 2U> &cs,
                                   ::coder::array<double, 2U> &sfvals,
                                   ::coder::array<double, 3U> &sdvals)
{
  coder::SizeType nqp;
  coder::SizeType sdvals_tmp;
  //  triangular
  nqp = cs.size(0) - 1;
  sdvals_tmp = iv[etype - 1];
  sfvals.set_size(cs.size(0), sdvals_tmp);
  sdvals.set_size(cs.size(0), sdvals_tmp, cs.size(1));
  switch (etype) {
  case 68: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double deriv[6];
      double N[3];
      ::sfe_sfuncs::tri_3_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                &N[0], &deriv[0]);
      sfvals[sfvals.size(1) * q] = N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = deriv[1];
      sfvals[sfvals.size(1) * q + 1] = N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = deriv[2];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[3];
      sfvals[sfvals.size(1) * q + 2] = N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[4];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[5];
    }
  } break;
  case 72: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double b_deriv[12];
      double b_N[6];
      ::sfe_sfuncs::tri_6_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                &b_N[0], &b_deriv[0]);
      sfvals[sfvals.size(1) * q] = b_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = b_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = b_deriv[1];
      sfvals[sfvals.size(1) * q + 1] = b_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = b_deriv[2];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[3];
      sfvals[sfvals.size(1) * q + 2] = b_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[4];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[5];
      sfvals[sfvals.size(1) * q + 3] = b_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[6];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[7];
      sfvals[sfvals.size(1) * q + 4] = b_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[8];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[9];
      sfvals[sfvals.size(1) * q + 5] = b_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[10];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[11];
    }
  } break;
  case 76: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double c_deriv[20];
      double c_N[10];
      ::sfe_sfuncs::tri_10_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 &c_N[0], &c_deriv[0]);
      sfvals[sfvals.size(1) * q] = c_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = c_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = c_deriv[1];
      sfvals[sfvals.size(1) * q + 1] = c_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = c_deriv[2];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[3];
      sfvals[sfvals.size(1) * q + 2] = c_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[4];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[5];
      sfvals[sfvals.size(1) * q + 3] = c_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[6];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[7];
      sfvals[sfvals.size(1) * q + 4] = c_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[8];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[9];
      sfvals[sfvals.size(1) * q + 5] = c_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[10];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[11];
      sfvals[sfvals.size(1) * q + 6] = c_N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[12];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[13];
      sfvals[sfvals.size(1) * q + 7] = c_N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[14];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[15];
      sfvals[sfvals.size(1) * q + 8] = c_N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[16];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[17];
      sfvals[sfvals.size(1) * q + 9] = c_N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[18];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[19];
    }
  } break;
  case 80: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double d_deriv[30];
      double d_N[15];
      ::sfe_sfuncs::tri_15_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 &d_N[0], &d_deriv[0]);
      for (coder::SizeType i{0}; i < 15; i++) {
        sfvals[i + sfvals.size(1) * q] = d_N[i];
        sdvals_tmp = i << 1;
        sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[sdvals_tmp];
        sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) + 1] =
            d_deriv[sdvals_tmp + 1];
      }
    }
  } break;
  case 84: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double e_deriv[42];
      double e_N[21];
      ::sfe_sfuncs::tri_21_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 &e_N[0], &e_deriv[0]);
      for (coder::SizeType i{0}; i < 21; i++) {
        sfvals[i + sfvals.size(1) * q] = e_N[i];
        sdvals_tmp = i << 1;
        sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
            e_deriv[sdvals_tmp];
        sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) + 1] =
            e_deriv[sdvals_tmp + 1];
      }
    }
  } break;
  default: {
    m2cAssert(etype == 88, "Only support up to sextic.");
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double f_deriv[56];
      double f_N[28];
      ::sfe_sfuncs::tri_28_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 &f_N[0], &f_deriv[0]);
      for (coder::SizeType i{0}; i < 28; i++) {
        sfvals[i + sfvals.size(1) * q] = f_N[i];
        sdvals_tmp = i << 1;
        sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
            f_deriv[sdvals_tmp];
        sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) + 1] =
            f_deriv[sdvals_tmp + 1];
      }
    }
  } break;
  }
}

static void sfe2_tabulate_gl(coder::SizeType etype,
                             const ::coder::array<double, 2U> &cs,
                             ::coder::array<double, 2U> &sfvals,
                             ::coder::array<double, 3U> &sdvals)
{
  //  GL kernel
  if ((etype >> 5 & 7) == 2) {
    coder::SizeType nqp;
    coder::SizeType sdvals_tmp;
    //  triangular
    nqp = cs.size(0) - 1;
    sdvals_tmp = iv[etype - 1];
    sfvals.set_size(cs.size(0), sdvals_tmp);
    sdvals.set_size(cs.size(0), sdvals_tmp, cs.size(1));
    switch (etype) {
    case 77: {
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double d_deriv[20];
        double d_N[10];
        ::sfe_sfuncs::tri_gl_10_sfunc(
            cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &d_N[0], &d_deriv[0]);
        sfvals[sfvals.size(1) * q] = d_N[0];
        sdvals[sdvals.size(2) * sdvals.size(1) * q] = d_deriv[0];
        sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = d_deriv[1];
        sfvals[sfvals.size(1) * q + 1] = d_N[1];
        sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[2];
        sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
            d_deriv[3];
        sfvals[sfvals.size(1) * q + 2] = d_N[2];
        sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[4];
        sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
            d_deriv[5];
        sfvals[sfvals.size(1) * q + 3] = d_N[3];
        sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[6];
        sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
            d_deriv[7];
        sfvals[sfvals.size(1) * q + 4] = d_N[4];
        sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[8];
        sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
            d_deriv[9];
        sfvals[sfvals.size(1) * q + 5] = d_N[5];
        sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[10];
        sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
            d_deriv[11];
        sfvals[sfvals.size(1) * q + 6] = d_N[6];
        sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[12];
        sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
            d_deriv[13];
        sfvals[sfvals.size(1) * q + 7] = d_N[7];
        sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[14];
        sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
            d_deriv[15];
        sfvals[sfvals.size(1) * q + 8] = d_N[8];
        sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[16];
        sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
            d_deriv[17];
        sfvals[sfvals.size(1) * q + 9] = d_N[9];
        sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[18];
        sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
            d_deriv[19];
      }
    } break;
    case 81: {
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double e_deriv[30];
        double e_N[15];
        ::sfe_sfuncs::tri_gl_15_sfunc(
            cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &e_N[0], &e_deriv[0]);
        for (coder::SizeType i{0}; i < 15; i++) {
          sfvals[i + sfvals.size(1) * q] = e_N[i];
          sdvals_tmp = i << 1;
          sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
              e_deriv[sdvals_tmp];
          sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = e_deriv[sdvals_tmp + 1];
        }
      }
    } break;
    case 85: {
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double f_deriv[42];
        double f_N[21];
        ::sfe_sfuncs::tri_gl_21_sfunc(
            cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &f_N[0], &f_deriv[0]);
        for (coder::SizeType i{0}; i < 21; i++) {
          sfvals[i + sfvals.size(1) * q] = f_N[i];
          sdvals_tmp = i << 1;
          sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
              f_deriv[sdvals_tmp];
          sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = f_deriv[sdvals_tmp + 1];
        }
      }
    } break;
    default: {
      m2cAssert(etype == 85, "Only support up to sextic");
      //  Sextic GL points do not exist. Use Fekete points instead.
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double h_deriv[56];
        double h_N[28];
        ::sfe_sfuncs::tri_fek_28_sfunc(
            cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &h_N[0], &h_deriv[0]);
        for (coder::SizeType i{0}; i < 28; i++) {
          sfvals[i + sfvals.size(1) * q] = h_N[i];
          sdvals_tmp = i << 1;
          sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
              h_deriv[sdvals_tmp];
          sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = h_deriv[sdvals_tmp + 1];
        }
      }
    } break;
    }
  } else {
    coder::SizeType nqp;
    coder::SizeType sdvals_tmp;
    //  quad
    nqp = cs.size(0) - 1;
    sdvals_tmp = iv[etype - 1];
    sfvals.set_size(cs.size(0), sdvals_tmp);
    sdvals.set_size(cs.size(0), sdvals_tmp, cs.size(1));
    switch (etype) {
    case 109: {
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double deriv[32];
        double N[16];
        ::sfe_sfuncs::quad_gl_16_sfunc(
            cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &N[0], &deriv[0]);
        for (coder::SizeType i{0}; i < 16; i++) {
          sfvals[i + sfvals.size(1) * q] = N[i];
          sdvals_tmp = i << 1;
          sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
              deriv[sdvals_tmp];
          sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = deriv[sdvals_tmp + 1];
        }
      }
    } break;
    case 113: {
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double b_deriv[50];
        double b_N[25];
        ::sfe_sfuncs::quad_gl_25_sfunc(
            cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &b_N[0], &b_deriv[0]);
        for (coder::SizeType i{0}; i < 25; i++) {
          sfvals[i + sfvals.size(1) * q] = b_N[i];
          sdvals_tmp = i << 1;
          sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
              b_deriv[sdvals_tmp];
          sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = b_deriv[sdvals_tmp + 1];
        }
      }
    } break;
    case 117: {
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double c_deriv[72];
        double c_N[36];
        ::sfe_sfuncs::quad_gl_36_sfunc(
            cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &c_N[0], &c_deriv[0]);
        for (coder::SizeType i{0}; i < 36; i++) {
          sfvals[i + sfvals.size(1) * q] = c_N[i];
          sdvals_tmp = i << 1;
          sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
              c_deriv[sdvals_tmp];
          sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = c_deriv[sdvals_tmp + 1];
        }
      }
    } break;
    default: {
      m2cAssert(etype == 121, "Only supports up to sextic.");
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double g_deriv[98];
        double g_N[49];
        ::sfe_sfuncs::quad_gl_49_sfunc(
            cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &g_N[0], &g_deriv[0]);
        for (coder::SizeType i{0}; i < 49; i++) {
          sfvals[i + sfvals.size(1) * q] = g_N[i];
          sdvals_tmp = i << 1;
          sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
              g_deriv[sdvals_tmp];
          sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = g_deriv[sdvals_tmp + 1];
        }
      }
    } break;
    }
  }
}

// sfe2_tabulate_shapefuncs - Tabulate shape functions and sdvals at given
static inline void sfe2_tabulate_shapefuncs(
    coder::SizeType etype, const ::coder::array<double, 2U> &cs,
    ::coder::array<double, 2U> &sfvals, ::coder::array<double, 3U> &sdvals)
{
  switch (etype & 3) {
  case 0: {
    //  equi kernel
    if ((etype >> 5 & 7) == 2) {
      sfe2_tabulate_equi_tri(etype, cs, sfvals, sdvals);
    } else {
      coder::SizeType nqp;
      coder::SizeType sdvals_tmp;
      //  triangular
      nqp = cs.size(0) - 1;
      sdvals_tmp = iv[etype - 1];
      sfvals.set_size(cs.size(0), sdvals_tmp);
      sdvals.set_size(cs.size(0), sdvals_tmp, cs.size(1));
      switch (etype) {
      case 100: {
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double c_deriv[8];
          double c_N[4];
          ::sfe_sfuncs::quad_4_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                     &c_N[0], &c_deriv[0]);
          sfvals[sfvals.size(1) * q] = c_N[0];
          sdvals[sdvals.size(2) * sdvals.size(1) * q] = c_deriv[0];
          sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = c_deriv[1];
          sfvals[sfvals.size(1) * q + 1] = c_N[1];
          sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] =
              c_deriv[2];
          sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
              c_deriv[3];
          sfvals[sfvals.size(1) * q + 2] = c_N[2];
          sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
              c_deriv[4];
          sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = c_deriv[5];
          sfvals[sfvals.size(1) * q + 3] = c_N[3];
          sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
              c_deriv[6];
          sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = c_deriv[7];
        }
      } break;
      case 104: {
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double d_deriv[18];
          double d_N[9];
          ::sfe_sfuncs::quad_9_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                     &d_N[0], &d_deriv[0]);
          sfvals[sfvals.size(1) * q] = d_N[0];
          sdvals[sdvals.size(2) * sdvals.size(1) * q] = d_deriv[0];
          sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = d_deriv[1];
          sfvals[sfvals.size(1) * q + 1] = d_N[1];
          sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] =
              d_deriv[2];
          sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
              d_deriv[3];
          sfvals[sfvals.size(1) * q + 2] = d_N[2];
          sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
              d_deriv[4];
          sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = d_deriv[5];
          sfvals[sfvals.size(1) * q + 3] = d_N[3];
          sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
              d_deriv[6];
          sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = d_deriv[7];
          sfvals[sfvals.size(1) * q + 4] = d_N[4];
          sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
              d_deriv[8];
          sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = d_deriv[9];
          sfvals[sfvals.size(1) * q + 5] = d_N[5];
          sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
              d_deriv[10];
          sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = d_deriv[11];
          sfvals[sfvals.size(1) * q + 6] = d_N[6];
          sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
              d_deriv[12];
          sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = d_deriv[13];
          sfvals[sfvals.size(1) * q + 7] = d_N[7];
          sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
              d_deriv[14];
          sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = d_deriv[15];
          sfvals[sfvals.size(1) * q + 8] = d_N[8];
          sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
              d_deriv[16];
          sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = d_deriv[17];
        }
      } break;
      case 108: {
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double e_deriv[32];
          double e_N[16];
          ::sfe_sfuncs::quad_16_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &e_N[0], &e_deriv[0]);
          for (coder::SizeType i{0}; i < 16; i++) {
            sfvals[i + sfvals.size(1) * q] = e_N[i];
            sdvals_tmp = i << 1;
            sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
                e_deriv[sdvals_tmp];
            sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                   1] = e_deriv[sdvals_tmp + 1];
          }
        }
      } break;
      case 112: {
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double f_deriv[50];
          double f_N[25];
          ::sfe_sfuncs::quad_25_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &f_N[0], &f_deriv[0]);
          for (coder::SizeType i{0}; i < 25; i++) {
            sfvals[i + sfvals.size(1) * q] = f_N[i];
            sdvals_tmp = i << 1;
            sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
                f_deriv[sdvals_tmp];
            sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                   1] = f_deriv[sdvals_tmp + 1];
          }
        }
      } break;
      case 116: {
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double g_deriv[72];
          double g_N[36];
          ::sfe_sfuncs::quad_36_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &g_N[0], &g_deriv[0]);
          for (coder::SizeType i{0}; i < 36; i++) {
            sfvals[i + sfvals.size(1) * q] = g_N[i];
            sdvals_tmp = i << 1;
            sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
                g_deriv[sdvals_tmp];
            sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                   1] = g_deriv[sdvals_tmp + 1];
          }
        }
      } break;
      default: {
        m2cAssert(etype == 120, "Only supports up to sextic.");
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double i_deriv[98];
          double i_N[49];
          ::sfe_sfuncs::quad_49_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &i_N[0], &i_deriv[0]);
          for (coder::SizeType i{0}; i < 49; i++) {
            sfvals[i + sfvals.size(1) * q] = i_N[i];
            sdvals_tmp = i << 1;
            sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
                i_deriv[sdvals_tmp];
            sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                   1] = i_deriv[sdvals_tmp + 1];
          }
        }
      } break;
      }
    }
  } break;
  case 1:
    sfe2_tabulate_gl(etype, cs, sfvals, sdvals);
    break;
  default: {
    coder::SizeType nqp;
    coder::SizeType sdvals_tmp;
    //  FEK kernel
    nqp = cs.size(0) - 1;
    sdvals_tmp = iv[etype - 1];
    sfvals.set_size(cs.size(0), sdvals_tmp);
    sdvals.set_size(cs.size(0), sdvals_tmp, cs.size(1));
    switch (etype) {
    case 82: {
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double deriv[30];
        double N[15];
        ::sfe_sfuncs::tri_fek_15_sfunc(
            cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &N[0], &deriv[0]);
        for (coder::SizeType i{0}; i < 15; i++) {
          sfvals[i + sfvals.size(1) * q] = N[i];
          sdvals_tmp = i << 1;
          sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
              deriv[sdvals_tmp];
          sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = deriv[sdvals_tmp + 1];
        }
      }
    } break;
    case 86: {
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double b_deriv[42];
        double b_N[21];
        ::sfe_sfuncs::tri_fek_21_sfunc(
            cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &b_N[0], &b_deriv[0]);
        for (coder::SizeType i{0}; i < 21; i++) {
          sfvals[i + sfvals.size(1) * q] = b_N[i];
          sdvals_tmp = i << 1;
          sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
              b_deriv[sdvals_tmp];
          sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = b_deriv[sdvals_tmp + 1];
        }
      }
    } break;
    default: {
      m2cAssert(etype == 90, "Only supports up to sextic.");
      for (coder::SizeType q{0}; q <= nqp; q++) {
        double h_deriv[56];
        double h_N[28];
        ::sfe_sfuncs::tri_fek_28_sfunc(
            cs[cs.size(1) * q], cs[cs.size(1) * q + 1], &h_N[0], &h_deriv[0]);
        for (coder::SizeType i{0}; i < 28; i++) {
          sfvals[i + sfvals.size(1) * q] = h_N[i];
          sdvals_tmp = i << 1;
          sdvals[sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q] =
              h_deriv[sdvals_tmp];
          sdvals[(sdvals.size(2) * i + sdvals.size(2) * sdvals.size(1) * q) +
                 1] = h_deriv[sdvals_tmp + 1];
        }
      }
    } break;
    }
  } break;
  }
}

static void sfe3_tabulate_equi_prism(coder::SizeType etype,
                                     const ::coder::array<double, 2U> &cs,
                                     ::coder::array<double, 2U> &sfvals,
                                     ::coder::array<double, 3U> &sdvals)
{
  coder::SizeType i;
  coder::SizeType nqp;
  //  prisms
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  switch (etype) {
  case 196: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double deriv[18];
      double N[6];
      ::sfe_sfuncs::prism_6_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                  cs[cs.size(1) * q + 2], &N[0], &deriv[0]);
      sfvals[sfvals.size(1) * q] = N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = deriv[2];
      sfvals[sfvals.size(1) * q + 1] = N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[5];
      sfvals[sfvals.size(1) * q + 2] = N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[8];
      sfvals[sfvals.size(1) * q + 3] = N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[11];
      sfvals[sfvals.size(1) * q + 4] = N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[14];
      sfvals[sfvals.size(1) * q + 5] = N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[17];
    }
  } break;
  case 200: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double b_deriv[54];
      double b_N[18];
      ::sfe_sfuncs::prism_18_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                   cs[cs.size(1) * q + 2], &b_N[0],
                                   &b_deriv[0]);
      sfvals[sfvals.size(1) * q] = b_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = b_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = b_deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = b_deriv[2];
      sfvals[sfvals.size(1) * q + 1] = b_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = b_deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[5];
      sfvals[sfvals.size(1) * q + 2] = b_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[8];
      sfvals[sfvals.size(1) * q + 3] = b_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[11];
      sfvals[sfvals.size(1) * q + 4] = b_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[14];
      sfvals[sfvals.size(1) * q + 5] = b_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[17];
      sfvals[sfvals.size(1) * q + 6] = b_N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[20];
      sfvals[sfvals.size(1) * q + 7] = b_N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[23];
      sfvals[sfvals.size(1) * q + 8] = b_N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[26];
      sfvals[sfvals.size(1) * q + 9] = b_N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[29];
      sfvals[sfvals.size(1) * q + 10] = b_N[10];
      sdvals[sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[30];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[31];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[32];
      sfvals[sfvals.size(1) * q + 11] = b_N[11];
      sdvals[sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[33];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[34];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[35];
      sfvals[sfvals.size(1) * q + 12] = b_N[12];
      sdvals[sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[36];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[37];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[38];
      sfvals[sfvals.size(1) * q + 13] = b_N[13];
      sdvals[sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[39];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[40];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[41];
      sfvals[sfvals.size(1) * q + 14] = b_N[14];
      sdvals[sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[42];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[43];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[44];
      sfvals[sfvals.size(1) * q + 15] = b_N[15];
      sdvals[sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[45];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[46];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[47];
      sfvals[sfvals.size(1) * q + 16] = b_N[16];
      sdvals[sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[48];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[49];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[50];
      sfvals[sfvals.size(1) * q + 17] = b_N[17];
      sdvals[sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[51];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[52];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[53];
    }
  } break;
  case 204: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double c_deriv[120];
      double c_N[40];
      ::sfe_sfuncs::prism_40_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                   cs[cs.size(1) * q + 2], &c_N[0],
                                   &c_deriv[0]);
      sfvals[sfvals.size(1) * q] = c_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = c_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = c_deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = c_deriv[2];
      sfvals[sfvals.size(1) * q + 1] = c_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = c_deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[5];
      sfvals[sfvals.size(1) * q + 2] = c_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[8];
      sfvals[sfvals.size(1) * q + 3] = c_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[11];
      sfvals[sfvals.size(1) * q + 4] = c_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[14];
      sfvals[sfvals.size(1) * q + 5] = c_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[17];
      sfvals[sfvals.size(1) * q + 6] = c_N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[20];
      sfvals[sfvals.size(1) * q + 7] = c_N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[23];
      sfvals[sfvals.size(1) * q + 8] = c_N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[26];
      sfvals[sfvals.size(1) * q + 9] = c_N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[29];
      sfvals[sfvals.size(1) * q + 10] = c_N[10];
      sdvals[sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[30];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[31];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[32];
      sfvals[sfvals.size(1) * q + 11] = c_N[11];
      sdvals[sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[33];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[34];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[35];
      sfvals[sfvals.size(1) * q + 12] = c_N[12];
      sdvals[sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[36];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[37];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[38];
      sfvals[sfvals.size(1) * q + 13] = c_N[13];
      sdvals[sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[39];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[40];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[41];
      sfvals[sfvals.size(1) * q + 14] = c_N[14];
      sdvals[sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[42];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[43];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[44];
      sfvals[sfvals.size(1) * q + 15] = c_N[15];
      sdvals[sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[45];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[46];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[47];
      sfvals[sfvals.size(1) * q + 16] = c_N[16];
      sdvals[sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[48];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[49];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[50];
      sfvals[sfvals.size(1) * q + 17] = c_N[17];
      sdvals[sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[51];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[52];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[53];
      sfvals[sfvals.size(1) * q + 18] = c_N[18];
      sdvals[sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[54];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[55];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[56];
      sfvals[sfvals.size(1) * q + 19] = c_N[19];
      sdvals[sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[57];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[58];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[59];
      sfvals[sfvals.size(1) * q + 20] = c_N[20];
      sdvals[sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[60];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[61];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[62];
      sfvals[sfvals.size(1) * q + 21] = c_N[21];
      sdvals[sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[63];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[64];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[65];
      sfvals[sfvals.size(1) * q + 22] = c_N[22];
      sdvals[sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[66];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[67];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[68];
      sfvals[sfvals.size(1) * q + 23] = c_N[23];
      sdvals[sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[69];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[70];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[71];
      sfvals[sfvals.size(1) * q + 24] = c_N[24];
      sdvals[sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[72];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[73];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[74];
      sfvals[sfvals.size(1) * q + 25] = c_N[25];
      sdvals[sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[75];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[76];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[77];
      sfvals[sfvals.size(1) * q + 26] = c_N[26];
      sdvals[sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[78];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[79];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[80];
      sfvals[sfvals.size(1) * q + 27] = c_N[27];
      sdvals[sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[81];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[82];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[83];
      sfvals[sfvals.size(1) * q + 28] = c_N[28];
      sdvals[sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[84];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[85];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[86];
      sfvals[sfvals.size(1) * q + 29] = c_N[29];
      sdvals[sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[87];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[88];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[89];
      sfvals[sfvals.size(1) * q + 30] = c_N[30];
      sdvals[sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[90];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[91];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[92];
      sfvals[sfvals.size(1) * q + 31] = c_N[31];
      sdvals[sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[93];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[94];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[95];
      sfvals[sfvals.size(1) * q + 32] = c_N[32];
      sdvals[sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[96];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[97];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[98];
      sfvals[sfvals.size(1) * q + 33] = c_N[33];
      sdvals[sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[99];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[100];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[101];
      sfvals[sfvals.size(1) * q + 34] = c_N[34];
      sdvals[sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[102];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[103];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[104];
      sfvals[sfvals.size(1) * q + 35] = c_N[35];
      sdvals[sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[105];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[106];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[107];
      sfvals[sfvals.size(1) * q + 36] = c_N[36];
      sdvals[sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[108];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[109];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[110];
      sfvals[sfvals.size(1) * q + 37] = c_N[37];
      sdvals[sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[111];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[112];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[113];
      sfvals[sfvals.size(1) * q + 38] = c_N[38];
      sdvals[sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[114];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[115];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[116];
      sfvals[sfvals.size(1) * q + 39] = c_N[39];
      sdvals[sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[117];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[118];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[119];
    }
  } break;
  case 208: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double d_deriv[225];
      double d_N[75];
      ::sfe_sfuncs::prism_75_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                   cs[cs.size(1) * q + 2], &d_N[0],
                                   &d_deriv[0]);
      sfvals[sfvals.size(1) * q] = d_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = d_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = d_deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = d_deriv[2];
      sfvals[sfvals.size(1) * q + 1] = d_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = d_deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[5];
      sfvals[sfvals.size(1) * q + 2] = d_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[8];
      sfvals[sfvals.size(1) * q + 3] = d_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[11];
      sfvals[sfvals.size(1) * q + 4] = d_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[14];
      sfvals[sfvals.size(1) * q + 5] = d_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[17];
      sfvals[sfvals.size(1) * q + 6] = d_N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[20];
      sfvals[sfvals.size(1) * q + 7] = d_N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[23];
      sfvals[sfvals.size(1) * q + 8] = d_N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[26];
      sfvals[sfvals.size(1) * q + 9] = d_N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[29];
      sfvals[sfvals.size(1) * q + 10] = d_N[10];
      sdvals[sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[30];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[31];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[32];
      sfvals[sfvals.size(1) * q + 11] = d_N[11];
      sdvals[sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[33];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[34];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[35];
      sfvals[sfvals.size(1) * q + 12] = d_N[12];
      sdvals[sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[36];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[37];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[38];
      sfvals[sfvals.size(1) * q + 13] = d_N[13];
      sdvals[sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[39];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[40];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[41];
      sfvals[sfvals.size(1) * q + 14] = d_N[14];
      sdvals[sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[42];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[43];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[44];
      sfvals[sfvals.size(1) * q + 15] = d_N[15];
      sdvals[sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[45];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[46];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[47];
      sfvals[sfvals.size(1) * q + 16] = d_N[16];
      sdvals[sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[48];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[49];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[50];
      sfvals[sfvals.size(1) * q + 17] = d_N[17];
      sdvals[sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[51];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[52];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[53];
      sfvals[sfvals.size(1) * q + 18] = d_N[18];
      sdvals[sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[54];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[55];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[56];
      sfvals[sfvals.size(1) * q + 19] = d_N[19];
      sdvals[sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[57];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[58];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[59];
      sfvals[sfvals.size(1) * q + 20] = d_N[20];
      sdvals[sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[60];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[61];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[62];
      sfvals[sfvals.size(1) * q + 21] = d_N[21];
      sdvals[sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[63];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[64];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[65];
      sfvals[sfvals.size(1) * q + 22] = d_N[22];
      sdvals[sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[66];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[67];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[68];
      sfvals[sfvals.size(1) * q + 23] = d_N[23];
      sdvals[sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[69];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[70];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[71];
      sfvals[sfvals.size(1) * q + 24] = d_N[24];
      sdvals[sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[72];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[73];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[74];
      sfvals[sfvals.size(1) * q + 25] = d_N[25];
      sdvals[sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[75];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[76];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[77];
      sfvals[sfvals.size(1) * q + 26] = d_N[26];
      sdvals[sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[78];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[79];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[80];
      sfvals[sfvals.size(1) * q + 27] = d_N[27];
      sdvals[sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[81];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[82];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[83];
      sfvals[sfvals.size(1) * q + 28] = d_N[28];
      sdvals[sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[84];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[85];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[86];
      sfvals[sfvals.size(1) * q + 29] = d_N[29];
      sdvals[sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[87];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[88];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[89];
      sfvals[sfvals.size(1) * q + 30] = d_N[30];
      sdvals[sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[90];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[91];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[92];
      sfvals[sfvals.size(1) * q + 31] = d_N[31];
      sdvals[sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[93];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[94];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[95];
      sfvals[sfvals.size(1) * q + 32] = d_N[32];
      sdvals[sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[96];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[97];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[98];
      sfvals[sfvals.size(1) * q + 33] = d_N[33];
      sdvals[sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[99];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[100];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[101];
      sfvals[sfvals.size(1) * q + 34] = d_N[34];
      sdvals[sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[102];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[103];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[104];
      sfvals[sfvals.size(1) * q + 35] = d_N[35];
      sdvals[sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[105];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[106];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[107];
      sfvals[sfvals.size(1) * q + 36] = d_N[36];
      sdvals[sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[108];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[109];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[110];
      sfvals[sfvals.size(1) * q + 37] = d_N[37];
      sdvals[sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[111];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[112];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[113];
      sfvals[sfvals.size(1) * q + 38] = d_N[38];
      sdvals[sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[114];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[115];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[116];
      sfvals[sfvals.size(1) * q + 39] = d_N[39];
      sdvals[sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[117];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[118];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[119];
      sfvals[sfvals.size(1) * q + 40] = d_N[40];
      sdvals[sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[120];
      sdvals[(sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[121];
      sdvals[(sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[122];
      sfvals[sfvals.size(1) * q + 41] = d_N[41];
      sdvals[sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[123];
      sdvals[(sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[124];
      sdvals[(sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[125];
      sfvals[sfvals.size(1) * q + 42] = d_N[42];
      sdvals[sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[126];
      sdvals[(sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[127];
      sdvals[(sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[128];
      sfvals[sfvals.size(1) * q + 43] = d_N[43];
      sdvals[sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[129];
      sdvals[(sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[130];
      sdvals[(sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[131];
      sfvals[sfvals.size(1) * q + 44] = d_N[44];
      sdvals[sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[132];
      sdvals[(sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[133];
      sdvals[(sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[134];
      sfvals[sfvals.size(1) * q + 45] = d_N[45];
      sdvals[sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[135];
      sdvals[(sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[136];
      sdvals[(sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[137];
      sfvals[sfvals.size(1) * q + 46] = d_N[46];
      sdvals[sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[138];
      sdvals[(sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[139];
      sdvals[(sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[140];
      sfvals[sfvals.size(1) * q + 47] = d_N[47];
      sdvals[sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[141];
      sdvals[(sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[142];
      sdvals[(sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[143];
      sfvals[sfvals.size(1) * q + 48] = d_N[48];
      sdvals[sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[144];
      sdvals[(sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[145];
      sdvals[(sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[146];
      sfvals[sfvals.size(1) * q + 49] = d_N[49];
      sdvals[sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[147];
      sdvals[(sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[148];
      sdvals[(sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[149];
      sfvals[sfvals.size(1) * q + 50] = d_N[50];
      sdvals[sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[150];
      sdvals[(sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[151];
      sdvals[(sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[152];
      sfvals[sfvals.size(1) * q + 51] = d_N[51];
      sdvals[sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[153];
      sdvals[(sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[154];
      sdvals[(sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[155];
      sfvals[sfvals.size(1) * q + 52] = d_N[52];
      sdvals[sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[156];
      sdvals[(sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[157];
      sdvals[(sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[158];
      sfvals[sfvals.size(1) * q + 53] = d_N[53];
      sdvals[sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[159];
      sdvals[(sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[160];
      sdvals[(sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[161];
      sfvals[sfvals.size(1) * q + 54] = d_N[54];
      sdvals[sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[162];
      sdvals[(sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[163];
      sdvals[(sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[164];
      sfvals[sfvals.size(1) * q + 55] = d_N[55];
      sdvals[sdvals.size(2) * 55 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[165];
      sdvals[(sdvals.size(2) * 55 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[166];
      sdvals[(sdvals.size(2) * 55 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[167];
      sfvals[sfvals.size(1) * q + 56] = d_N[56];
      sdvals[sdvals.size(2) * 56 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[168];
      sdvals[(sdvals.size(2) * 56 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[169];
      sdvals[(sdvals.size(2) * 56 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[170];
      sfvals[sfvals.size(1) * q + 57] = d_N[57];
      sdvals[sdvals.size(2) * 57 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[171];
      sdvals[(sdvals.size(2) * 57 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[172];
      sdvals[(sdvals.size(2) * 57 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[173];
      sfvals[sfvals.size(1) * q + 58] = d_N[58];
      sdvals[sdvals.size(2) * 58 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[174];
      sdvals[(sdvals.size(2) * 58 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[175];
      sdvals[(sdvals.size(2) * 58 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[176];
      sfvals[sfvals.size(1) * q + 59] = d_N[59];
      sdvals[sdvals.size(2) * 59 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[177];
      sdvals[(sdvals.size(2) * 59 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[178];
      sdvals[(sdvals.size(2) * 59 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[179];
      sfvals[sfvals.size(1) * q + 60] = d_N[60];
      sdvals[sdvals.size(2) * 60 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[180];
      sdvals[(sdvals.size(2) * 60 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[181];
      sdvals[(sdvals.size(2) * 60 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[182];
      sfvals[sfvals.size(1) * q + 61] = d_N[61];
      sdvals[sdvals.size(2) * 61 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[183];
      sdvals[(sdvals.size(2) * 61 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[184];
      sdvals[(sdvals.size(2) * 61 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[185];
      sfvals[sfvals.size(1) * q + 62] = d_N[62];
      sdvals[sdvals.size(2) * 62 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[186];
      sdvals[(sdvals.size(2) * 62 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[187];
      sdvals[(sdvals.size(2) * 62 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[188];
      sfvals[sfvals.size(1) * q + 63] = d_N[63];
      sdvals[sdvals.size(2) * 63 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[189];
      sdvals[(sdvals.size(2) * 63 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[190];
      sdvals[(sdvals.size(2) * 63 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[191];
      sfvals[sfvals.size(1) * q + 64] = d_N[64];
      sdvals[sdvals.size(2) * 64 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[192];
      sdvals[(sdvals.size(2) * 64 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[193];
      sdvals[(sdvals.size(2) * 64 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[194];
      sfvals[sfvals.size(1) * q + 65] = d_N[65];
      sdvals[sdvals.size(2) * 65 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[195];
      sdvals[(sdvals.size(2) * 65 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[196];
      sdvals[(sdvals.size(2) * 65 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[197];
      sfvals[sfvals.size(1) * q + 66] = d_N[66];
      sdvals[sdvals.size(2) * 66 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[198];
      sdvals[(sdvals.size(2) * 66 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[199];
      sdvals[(sdvals.size(2) * 66 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[200];
      sfvals[sfvals.size(1) * q + 67] = d_N[67];
      sdvals[sdvals.size(2) * 67 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[201];
      sdvals[(sdvals.size(2) * 67 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[202];
      sdvals[(sdvals.size(2) * 67 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[203];
      sfvals[sfvals.size(1) * q + 68] = d_N[68];
      sdvals[sdvals.size(2) * 68 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[204];
      sdvals[(sdvals.size(2) * 68 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[205];
      sdvals[(sdvals.size(2) * 68 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[206];
      sfvals[sfvals.size(1) * q + 69] = d_N[69];
      sdvals[sdvals.size(2) * 69 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[207];
      sdvals[(sdvals.size(2) * 69 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[208];
      sdvals[(sdvals.size(2) * 69 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[209];
      sfvals[sfvals.size(1) * q + 70] = d_N[70];
      sdvals[sdvals.size(2) * 70 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[210];
      sdvals[(sdvals.size(2) * 70 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[211];
      sdvals[(sdvals.size(2) * 70 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[212];
      sfvals[sfvals.size(1) * q + 71] = d_N[71];
      sdvals[sdvals.size(2) * 71 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[213];
      sdvals[(sdvals.size(2) * 71 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[214];
      sdvals[(sdvals.size(2) * 71 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[215];
      sfvals[sfvals.size(1) * q + 72] = d_N[72];
      sdvals[sdvals.size(2) * 72 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[216];
      sdvals[(sdvals.size(2) * 72 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[217];
      sdvals[(sdvals.size(2) * 72 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[218];
      sfvals[sfvals.size(1) * q + 73] = d_N[73];
      sdvals[sdvals.size(2) * 73 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[219];
      sdvals[(sdvals.size(2) * 73 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[220];
      sdvals[(sdvals.size(2) * 73 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[221];
      sfvals[sfvals.size(1) * q + 74] = d_N[74];
      sdvals[sdvals.size(2) * 74 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[222];
      sdvals[(sdvals.size(2) * 74 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[223];
      sdvals[(sdvals.size(2) * 74 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[224];
    }
  } break;
  default: {
    m2cAssert(etype == 212, "prismatic elements supports up to quintic.");
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double e_deriv[378];
      double e_N[126];
      ::sfe_sfuncs::prism_126_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                    cs[cs.size(1) * q + 2], &e_N[0],
                                    &e_deriv[0]);
      sfvals[sfvals.size(1) * q] = e_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = e_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = e_deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = e_deriv[2];
      sfvals[sfvals.size(1) * q + 1] = e_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = e_deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[5];
      sfvals[sfvals.size(1) * q + 2] = e_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[8];
      sfvals[sfvals.size(1) * q + 3] = e_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[11];
      sfvals[sfvals.size(1) * q + 4] = e_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[14];
      sfvals[sfvals.size(1) * q + 5] = e_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[17];
      sfvals[sfvals.size(1) * q + 6] = e_N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[20];
      sfvals[sfvals.size(1) * q + 7] = e_N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[23];
      sfvals[sfvals.size(1) * q + 8] = e_N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[26];
      sfvals[sfvals.size(1) * q + 9] = e_N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[29];
      sfvals[sfvals.size(1) * q + 10] = e_N[10];
      sdvals[sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[30];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[31];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[32];
      sfvals[sfvals.size(1) * q + 11] = e_N[11];
      sdvals[sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[33];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[34];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[35];
      sfvals[sfvals.size(1) * q + 12] = e_N[12];
      sdvals[sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[36];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[37];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[38];
      sfvals[sfvals.size(1) * q + 13] = e_N[13];
      sdvals[sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[39];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[40];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[41];
      sfvals[sfvals.size(1) * q + 14] = e_N[14];
      sdvals[sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[42];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[43];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[44];
      sfvals[sfvals.size(1) * q + 15] = e_N[15];
      sdvals[sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[45];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[46];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[47];
      sfvals[sfvals.size(1) * q + 16] = e_N[16];
      sdvals[sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[48];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[49];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[50];
      sfvals[sfvals.size(1) * q + 17] = e_N[17];
      sdvals[sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[51];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[52];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[53];
      sfvals[sfvals.size(1) * q + 18] = e_N[18];
      sdvals[sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[54];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[55];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[56];
      sfvals[sfvals.size(1) * q + 19] = e_N[19];
      sdvals[sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[57];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[58];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[59];
      sfvals[sfvals.size(1) * q + 20] = e_N[20];
      sdvals[sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[60];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[61];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[62];
      sfvals[sfvals.size(1) * q + 21] = e_N[21];
      sdvals[sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[63];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[64];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[65];
      sfvals[sfvals.size(1) * q + 22] = e_N[22];
      sdvals[sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[66];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[67];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[68];
      sfvals[sfvals.size(1) * q + 23] = e_N[23];
      sdvals[sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[69];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[70];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[71];
      sfvals[sfvals.size(1) * q + 24] = e_N[24];
      sdvals[sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[72];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[73];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[74];
      sfvals[sfvals.size(1) * q + 25] = e_N[25];
      sdvals[sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[75];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[76];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[77];
      sfvals[sfvals.size(1) * q + 26] = e_N[26];
      sdvals[sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[78];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[79];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[80];
      sfvals[sfvals.size(1) * q + 27] = e_N[27];
      sdvals[sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[81];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[82];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[83];
      sfvals[sfvals.size(1) * q + 28] = e_N[28];
      sdvals[sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[84];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[85];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[86];
      sfvals[sfvals.size(1) * q + 29] = e_N[29];
      sdvals[sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[87];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[88];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[89];
      sfvals[sfvals.size(1) * q + 30] = e_N[30];
      sdvals[sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[90];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[91];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[92];
      sfvals[sfvals.size(1) * q + 31] = e_N[31];
      sdvals[sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[93];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[94];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[95];
      sfvals[sfvals.size(1) * q + 32] = e_N[32];
      sdvals[sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[96];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[97];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[98];
      sfvals[sfvals.size(1) * q + 33] = e_N[33];
      sdvals[sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[99];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[100];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[101];
      sfvals[sfvals.size(1) * q + 34] = e_N[34];
      sdvals[sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[102];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[103];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[104];
      sfvals[sfvals.size(1) * q + 35] = e_N[35];
      sdvals[sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[105];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[106];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[107];
      sfvals[sfvals.size(1) * q + 36] = e_N[36];
      sdvals[sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[108];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[109];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[110];
      sfvals[sfvals.size(1) * q + 37] = e_N[37];
      sdvals[sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[111];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[112];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[113];
      sfvals[sfvals.size(1) * q + 38] = e_N[38];
      sdvals[sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[114];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[115];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[116];
      sfvals[sfvals.size(1) * q + 39] = e_N[39];
      sdvals[sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[117];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[118];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[119];
      sfvals[sfvals.size(1) * q + 40] = e_N[40];
      sdvals[sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[120];
      sdvals[(sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[121];
      sdvals[(sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[122];
      sfvals[sfvals.size(1) * q + 41] = e_N[41];
      sdvals[sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[123];
      sdvals[(sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[124];
      sdvals[(sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[125];
      sfvals[sfvals.size(1) * q + 42] = e_N[42];
      sdvals[sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[126];
      sdvals[(sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[127];
      sdvals[(sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[128];
      sfvals[sfvals.size(1) * q + 43] = e_N[43];
      sdvals[sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[129];
      sdvals[(sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[130];
      sdvals[(sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[131];
      sfvals[sfvals.size(1) * q + 44] = e_N[44];
      sdvals[sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[132];
      sdvals[(sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[133];
      sdvals[(sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[134];
      sfvals[sfvals.size(1) * q + 45] = e_N[45];
      sdvals[sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[135];
      sdvals[(sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[136];
      sdvals[(sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[137];
      sfvals[sfvals.size(1) * q + 46] = e_N[46];
      sdvals[sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[138];
      sdvals[(sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[139];
      sdvals[(sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[140];
      sfvals[sfvals.size(1) * q + 47] = e_N[47];
      sdvals[sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[141];
      sdvals[(sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[142];
      sdvals[(sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[143];
      sfvals[sfvals.size(1) * q + 48] = e_N[48];
      sdvals[sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[144];
      sdvals[(sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[145];
      sdvals[(sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[146];
      sfvals[sfvals.size(1) * q + 49] = e_N[49];
      sdvals[sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[147];
      sdvals[(sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[148];
      sdvals[(sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[149];
      sfvals[sfvals.size(1) * q + 50] = e_N[50];
      sdvals[sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[150];
      sdvals[(sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[151];
      sdvals[(sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[152];
      sfvals[sfvals.size(1) * q + 51] = e_N[51];
      sdvals[sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[153];
      sdvals[(sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[154];
      sdvals[(sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[155];
      sfvals[sfvals.size(1) * q + 52] = e_N[52];
      sdvals[sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[156];
      sdvals[(sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[157];
      sdvals[(sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[158];
      sfvals[sfvals.size(1) * q + 53] = e_N[53];
      sdvals[sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[159];
      sdvals[(sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[160];
      sdvals[(sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[161];
      sfvals[sfvals.size(1) * q + 54] = e_N[54];
      sdvals[sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[162];
      sdvals[(sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[163];
      sdvals[(sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[164];
      sfvals[sfvals.size(1) * q + 55] = e_N[55];
      sdvals[sdvals.size(2) * 55 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[165];
      sdvals[(sdvals.size(2) * 55 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[166];
      sdvals[(sdvals.size(2) * 55 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[167];
      sfvals[sfvals.size(1) * q + 56] = e_N[56];
      sdvals[sdvals.size(2) * 56 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[168];
      sdvals[(sdvals.size(2) * 56 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[169];
      sdvals[(sdvals.size(2) * 56 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[170];
      sfvals[sfvals.size(1) * q + 57] = e_N[57];
      sdvals[sdvals.size(2) * 57 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[171];
      sdvals[(sdvals.size(2) * 57 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[172];
      sdvals[(sdvals.size(2) * 57 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[173];
      sfvals[sfvals.size(1) * q + 58] = e_N[58];
      sdvals[sdvals.size(2) * 58 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[174];
      sdvals[(sdvals.size(2) * 58 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[175];
      sdvals[(sdvals.size(2) * 58 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[176];
      sfvals[sfvals.size(1) * q + 59] = e_N[59];
      sdvals[sdvals.size(2) * 59 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[177];
      sdvals[(sdvals.size(2) * 59 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[178];
      sdvals[(sdvals.size(2) * 59 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[179];
      sfvals[sfvals.size(1) * q + 60] = e_N[60];
      sdvals[sdvals.size(2) * 60 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[180];
      sdvals[(sdvals.size(2) * 60 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[181];
      sdvals[(sdvals.size(2) * 60 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[182];
      sfvals[sfvals.size(1) * q + 61] = e_N[61];
      sdvals[sdvals.size(2) * 61 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[183];
      sdvals[(sdvals.size(2) * 61 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[184];
      sdvals[(sdvals.size(2) * 61 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[185];
      sfvals[sfvals.size(1) * q + 62] = e_N[62];
      sdvals[sdvals.size(2) * 62 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[186];
      sdvals[(sdvals.size(2) * 62 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[187];
      sdvals[(sdvals.size(2) * 62 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[188];
      sfvals[sfvals.size(1) * q + 63] = e_N[63];
      sdvals[sdvals.size(2) * 63 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[189];
      sdvals[(sdvals.size(2) * 63 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[190];
      sdvals[(sdvals.size(2) * 63 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[191];
      sfvals[sfvals.size(1) * q + 64] = e_N[64];
      sdvals[sdvals.size(2) * 64 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[192];
      sdvals[(sdvals.size(2) * 64 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[193];
      sdvals[(sdvals.size(2) * 64 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[194];
      sfvals[sfvals.size(1) * q + 65] = e_N[65];
      sdvals[sdvals.size(2) * 65 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[195];
      sdvals[(sdvals.size(2) * 65 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[196];
      sdvals[(sdvals.size(2) * 65 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[197];
      sfvals[sfvals.size(1) * q + 66] = e_N[66];
      sdvals[sdvals.size(2) * 66 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[198];
      sdvals[(sdvals.size(2) * 66 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[199];
      sdvals[(sdvals.size(2) * 66 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[200];
      sfvals[sfvals.size(1) * q + 67] = e_N[67];
      sdvals[sdvals.size(2) * 67 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[201];
      sdvals[(sdvals.size(2) * 67 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[202];
      sdvals[(sdvals.size(2) * 67 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[203];
      sfvals[sfvals.size(1) * q + 68] = e_N[68];
      sdvals[sdvals.size(2) * 68 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[204];
      sdvals[(sdvals.size(2) * 68 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[205];
      sdvals[(sdvals.size(2) * 68 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[206];
      sfvals[sfvals.size(1) * q + 69] = e_N[69];
      sdvals[sdvals.size(2) * 69 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[207];
      sdvals[(sdvals.size(2) * 69 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[208];
      sdvals[(sdvals.size(2) * 69 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[209];
      sfvals[sfvals.size(1) * q + 70] = e_N[70];
      sdvals[sdvals.size(2) * 70 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[210];
      sdvals[(sdvals.size(2) * 70 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[211];
      sdvals[(sdvals.size(2) * 70 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[212];
      sfvals[sfvals.size(1) * q + 71] = e_N[71];
      sdvals[sdvals.size(2) * 71 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[213];
      sdvals[(sdvals.size(2) * 71 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[214];
      sdvals[(sdvals.size(2) * 71 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[215];
      sfvals[sfvals.size(1) * q + 72] = e_N[72];
      sdvals[sdvals.size(2) * 72 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[216];
      sdvals[(sdvals.size(2) * 72 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[217];
      sdvals[(sdvals.size(2) * 72 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[218];
      sfvals[sfvals.size(1) * q + 73] = e_N[73];
      sdvals[sdvals.size(2) * 73 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[219];
      sdvals[(sdvals.size(2) * 73 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[220];
      sdvals[(sdvals.size(2) * 73 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[221];
      sfvals[sfvals.size(1) * q + 74] = e_N[74];
      sdvals[sdvals.size(2) * 74 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[222];
      sdvals[(sdvals.size(2) * 74 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[223];
      sdvals[(sdvals.size(2) * 74 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[224];
      sfvals[sfvals.size(1) * q + 75] = e_N[75];
      sdvals[sdvals.size(2) * 75 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[225];
      sdvals[(sdvals.size(2) * 75 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[226];
      sdvals[(sdvals.size(2) * 75 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[227];
      sfvals[sfvals.size(1) * q + 76] = e_N[76];
      sdvals[sdvals.size(2) * 76 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[228];
      sdvals[(sdvals.size(2) * 76 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[229];
      sdvals[(sdvals.size(2) * 76 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[230];
      sfvals[sfvals.size(1) * q + 77] = e_N[77];
      sdvals[sdvals.size(2) * 77 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[231];
      sdvals[(sdvals.size(2) * 77 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[232];
      sdvals[(sdvals.size(2) * 77 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[233];
      sfvals[sfvals.size(1) * q + 78] = e_N[78];
      sdvals[sdvals.size(2) * 78 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[234];
      sdvals[(sdvals.size(2) * 78 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[235];
      sdvals[(sdvals.size(2) * 78 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[236];
      sfvals[sfvals.size(1) * q + 79] = e_N[79];
      sdvals[sdvals.size(2) * 79 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[237];
      sdvals[(sdvals.size(2) * 79 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[238];
      sdvals[(sdvals.size(2) * 79 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[239];
      sfvals[sfvals.size(1) * q + 80] = e_N[80];
      sdvals[sdvals.size(2) * 80 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[240];
      sdvals[(sdvals.size(2) * 80 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[241];
      sdvals[(sdvals.size(2) * 80 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[242];
      sfvals[sfvals.size(1) * q + 81] = e_N[81];
      sdvals[sdvals.size(2) * 81 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[243];
      sdvals[(sdvals.size(2) * 81 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[244];
      sdvals[(sdvals.size(2) * 81 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[245];
      sfvals[sfvals.size(1) * q + 82] = e_N[82];
      sdvals[sdvals.size(2) * 82 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[246];
      sdvals[(sdvals.size(2) * 82 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[247];
      sdvals[(sdvals.size(2) * 82 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[248];
      sfvals[sfvals.size(1) * q + 83] = e_N[83];
      sdvals[sdvals.size(2) * 83 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[249];
      sdvals[(sdvals.size(2) * 83 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[250];
      sdvals[(sdvals.size(2) * 83 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[251];
      sfvals[sfvals.size(1) * q + 84] = e_N[84];
      sdvals[sdvals.size(2) * 84 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[252];
      sdvals[(sdvals.size(2) * 84 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[253];
      sdvals[(sdvals.size(2) * 84 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[254];
      sfvals[sfvals.size(1) * q + 85] = e_N[85];
      sdvals[sdvals.size(2) * 85 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[255];
      sdvals[(sdvals.size(2) * 85 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[256];
      sdvals[(sdvals.size(2) * 85 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[257];
      sfvals[sfvals.size(1) * q + 86] = e_N[86];
      sdvals[sdvals.size(2) * 86 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[258];
      sdvals[(sdvals.size(2) * 86 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[259];
      sdvals[(sdvals.size(2) * 86 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[260];
      sfvals[sfvals.size(1) * q + 87] = e_N[87];
      sdvals[sdvals.size(2) * 87 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[261];
      sdvals[(sdvals.size(2) * 87 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[262];
      sdvals[(sdvals.size(2) * 87 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[263];
      sfvals[sfvals.size(1) * q + 88] = e_N[88];
      sdvals[sdvals.size(2) * 88 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[264];
      sdvals[(sdvals.size(2) * 88 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[265];
      sdvals[(sdvals.size(2) * 88 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[266];
      sfvals[sfvals.size(1) * q + 89] = e_N[89];
      sdvals[sdvals.size(2) * 89 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[267];
      sdvals[(sdvals.size(2) * 89 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[268];
      sdvals[(sdvals.size(2) * 89 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[269];
      sfvals[sfvals.size(1) * q + 90] = e_N[90];
      sdvals[sdvals.size(2) * 90 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[270];
      sdvals[(sdvals.size(2) * 90 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[271];
      sdvals[(sdvals.size(2) * 90 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[272];
      sfvals[sfvals.size(1) * q + 91] = e_N[91];
      sdvals[sdvals.size(2) * 91 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[273];
      sdvals[(sdvals.size(2) * 91 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[274];
      sdvals[(sdvals.size(2) * 91 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[275];
      sfvals[sfvals.size(1) * q + 92] = e_N[92];
      sdvals[sdvals.size(2) * 92 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[276];
      sdvals[(sdvals.size(2) * 92 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[277];
      sdvals[(sdvals.size(2) * 92 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[278];
      sfvals[sfvals.size(1) * q + 93] = e_N[93];
      sdvals[sdvals.size(2) * 93 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[279];
      sdvals[(sdvals.size(2) * 93 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[280];
      sdvals[(sdvals.size(2) * 93 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[281];
      sfvals[sfvals.size(1) * q + 94] = e_N[94];
      sdvals[sdvals.size(2) * 94 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[282];
      sdvals[(sdvals.size(2) * 94 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[283];
      sdvals[(sdvals.size(2) * 94 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[284];
      sfvals[sfvals.size(1) * q + 95] = e_N[95];
      sdvals[sdvals.size(2) * 95 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[285];
      sdvals[(sdvals.size(2) * 95 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[286];
      sdvals[(sdvals.size(2) * 95 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[287];
      sfvals[sfvals.size(1) * q + 96] = e_N[96];
      sdvals[sdvals.size(2) * 96 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[288];
      sdvals[(sdvals.size(2) * 96 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[289];
      sdvals[(sdvals.size(2) * 96 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[290];
      sfvals[sfvals.size(1) * q + 97] = e_N[97];
      sdvals[sdvals.size(2) * 97 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[291];
      sdvals[(sdvals.size(2) * 97 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[292];
      sdvals[(sdvals.size(2) * 97 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[293];
      sfvals[sfvals.size(1) * q + 98] = e_N[98];
      sdvals[sdvals.size(2) * 98 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[294];
      sdvals[(sdvals.size(2) * 98 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[295];
      sdvals[(sdvals.size(2) * 98 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[296];
      sfvals[sfvals.size(1) * q + 99] = e_N[99];
      sdvals[sdvals.size(2) * 99 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[297];
      sdvals[(sdvals.size(2) * 99 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[298];
      sdvals[(sdvals.size(2) * 99 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[299];
      sfvals[sfvals.size(1) * q + 100] = e_N[100];
      sdvals[sdvals.size(2) * 100 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[300];
      sdvals[(sdvals.size(2) * 100 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[301];
      sdvals[(sdvals.size(2) * 100 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[302];
      sfvals[sfvals.size(1) * q + 101] = e_N[101];
      sdvals[sdvals.size(2) * 101 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[303];
      sdvals[(sdvals.size(2) * 101 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[304];
      sdvals[(sdvals.size(2) * 101 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[305];
      sfvals[sfvals.size(1) * q + 102] = e_N[102];
      sdvals[sdvals.size(2) * 102 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[306];
      sdvals[(sdvals.size(2) * 102 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[307];
      sdvals[(sdvals.size(2) * 102 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[308];
      sfvals[sfvals.size(1) * q + 103] = e_N[103];
      sdvals[sdvals.size(2) * 103 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[309];
      sdvals[(sdvals.size(2) * 103 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[310];
      sdvals[(sdvals.size(2) * 103 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[311];
      sfvals[sfvals.size(1) * q + 104] = e_N[104];
      sdvals[sdvals.size(2) * 104 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[312];
      sdvals[(sdvals.size(2) * 104 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[313];
      sdvals[(sdvals.size(2) * 104 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[314];
      sfvals[sfvals.size(1) * q + 105] = e_N[105];
      sdvals[sdvals.size(2) * 105 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[315];
      sdvals[(sdvals.size(2) * 105 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[316];
      sdvals[(sdvals.size(2) * 105 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[317];
      sfvals[sfvals.size(1) * q + 106] = e_N[106];
      sdvals[sdvals.size(2) * 106 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[318];
      sdvals[(sdvals.size(2) * 106 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[319];
      sdvals[(sdvals.size(2) * 106 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[320];
      sfvals[sfvals.size(1) * q + 107] = e_N[107];
      sdvals[sdvals.size(2) * 107 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[321];
      sdvals[(sdvals.size(2) * 107 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[322];
      sdvals[(sdvals.size(2) * 107 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[323];
      sfvals[sfvals.size(1) * q + 108] = e_N[108];
      sdvals[sdvals.size(2) * 108 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[324];
      sdvals[(sdvals.size(2) * 108 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[325];
      sdvals[(sdvals.size(2) * 108 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[326];
      sfvals[sfvals.size(1) * q + 109] = e_N[109];
      sdvals[sdvals.size(2) * 109 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[327];
      sdvals[(sdvals.size(2) * 109 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[328];
      sdvals[(sdvals.size(2) * 109 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[329];
      sfvals[sfvals.size(1) * q + 110] = e_N[110];
      sdvals[sdvals.size(2) * 110 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[330];
      sdvals[(sdvals.size(2) * 110 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[331];
      sdvals[(sdvals.size(2) * 110 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[332];
      sfvals[sfvals.size(1) * q + 111] = e_N[111];
      sdvals[sdvals.size(2) * 111 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[333];
      sdvals[(sdvals.size(2) * 111 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[334];
      sdvals[(sdvals.size(2) * 111 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[335];
      sfvals[sfvals.size(1) * q + 112] = e_N[112];
      sdvals[sdvals.size(2) * 112 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[336];
      sdvals[(sdvals.size(2) * 112 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[337];
      sdvals[(sdvals.size(2) * 112 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[338];
      sfvals[sfvals.size(1) * q + 113] = e_N[113];
      sdvals[sdvals.size(2) * 113 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[339];
      sdvals[(sdvals.size(2) * 113 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[340];
      sdvals[(sdvals.size(2) * 113 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[341];
      sfvals[sfvals.size(1) * q + 114] = e_N[114];
      sdvals[sdvals.size(2) * 114 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[342];
      sdvals[(sdvals.size(2) * 114 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[343];
      sdvals[(sdvals.size(2) * 114 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[344];
      sfvals[sfvals.size(1) * q + 115] = e_N[115];
      sdvals[sdvals.size(2) * 115 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[345];
      sdvals[(sdvals.size(2) * 115 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[346];
      sdvals[(sdvals.size(2) * 115 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[347];
      sfvals[sfvals.size(1) * q + 116] = e_N[116];
      sdvals[sdvals.size(2) * 116 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[348];
      sdvals[(sdvals.size(2) * 116 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[349];
      sdvals[(sdvals.size(2) * 116 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[350];
      sfvals[sfvals.size(1) * q + 117] = e_N[117];
      sdvals[sdvals.size(2) * 117 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[351];
      sdvals[(sdvals.size(2) * 117 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[352];
      sdvals[(sdvals.size(2) * 117 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[353];
      sfvals[sfvals.size(1) * q + 118] = e_N[118];
      sdvals[sdvals.size(2) * 118 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[354];
      sdvals[(sdvals.size(2) * 118 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[355];
      sdvals[(sdvals.size(2) * 118 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[356];
      sfvals[sfvals.size(1) * q + 119] = e_N[119];
      sdvals[sdvals.size(2) * 119 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[357];
      sdvals[(sdvals.size(2) * 119 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[358];
      sdvals[(sdvals.size(2) * 119 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[359];
      sfvals[sfvals.size(1) * q + 120] = e_N[120];
      sdvals[sdvals.size(2) * 120 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[360];
      sdvals[(sdvals.size(2) * 120 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[361];
      sdvals[(sdvals.size(2) * 120 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[362];
      sfvals[sfvals.size(1) * q + 121] = e_N[121];
      sdvals[sdvals.size(2) * 121 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[363];
      sdvals[(sdvals.size(2) * 121 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[364];
      sdvals[(sdvals.size(2) * 121 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[365];
      sfvals[sfvals.size(1) * q + 122] = e_N[122];
      sdvals[sdvals.size(2) * 122 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[366];
      sdvals[(sdvals.size(2) * 122 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[367];
      sdvals[(sdvals.size(2) * 122 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[368];
      sfvals[sfvals.size(1) * q + 123] = e_N[123];
      sdvals[sdvals.size(2) * 123 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[369];
      sdvals[(sdvals.size(2) * 123 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[370];
      sdvals[(sdvals.size(2) * 123 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[371];
      sfvals[sfvals.size(1) * q + 124] = e_N[124];
      sdvals[sdvals.size(2) * 124 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[372];
      sdvals[(sdvals.size(2) * 124 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[373];
      sdvals[(sdvals.size(2) * 124 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[374];
      sfvals[sfvals.size(1) * q + 125] = e_N[125];
      sdvals[sdvals.size(2) * 125 + sdvals.size(2) * sdvals.size(1) * q] =
          e_deriv[375];
      sdvals[(sdvals.size(2) * 125 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          e_deriv[376];
      sdvals[(sdvals.size(2) * 125 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          e_deriv[377];
    }
  } break;
  }
}

static void sfe3_tabulate_equi_pyra(coder::SizeType etype,
                                    const ::coder::array<double, 2U> &cs,
                                    ::coder::array<double, 2U> &sfvals,
                                    ::coder::array<double, 3U> &sdvals)
{
  coder::SizeType i;
  coder::SizeType nqp;
  //  pyra
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  switch (etype) {
  case 164: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double deriv[15];
      double N[5];
      ::sfe_sfuncs::pyra_5_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 cs[cs.size(1) * q + 2], &N[0], &deriv[0]);
      sfvals[sfvals.size(1) * q] = N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = deriv[2];
      sfvals[sfvals.size(1) * q + 1] = N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[5];
      sfvals[sfvals.size(1) * q + 2] = N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[8];
      sfvals[sfvals.size(1) * q + 3] = N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[11];
      sfvals[sfvals.size(1) * q + 4] = N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[14];
    }
  } break;
  case 168: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double b_deriv[42];
      double b_N[14];
      ::sfe_sfuncs::pyra_14_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                  cs[cs.size(1) * q + 2], &b_N[0], &b_deriv[0]);
      sfvals[sfvals.size(1) * q] = b_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = b_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = b_deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = b_deriv[2];
      sfvals[sfvals.size(1) * q + 1] = b_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = b_deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[5];
      sfvals[sfvals.size(1) * q + 2] = b_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[8];
      sfvals[sfvals.size(1) * q + 3] = b_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[11];
      sfvals[sfvals.size(1) * q + 4] = b_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[14];
      sfvals[sfvals.size(1) * q + 5] = b_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[17];
      sfvals[sfvals.size(1) * q + 6] = b_N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[20];
      sfvals[sfvals.size(1) * q + 7] = b_N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[23];
      sfvals[sfvals.size(1) * q + 8] = b_N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[26];
      sfvals[sfvals.size(1) * q + 9] = b_N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[29];
      sfvals[sfvals.size(1) * q + 10] = b_N[10];
      sdvals[sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[30];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[31];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[32];
      sfvals[sfvals.size(1) * q + 11] = b_N[11];
      sdvals[sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[33];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[34];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[35];
      sfvals[sfvals.size(1) * q + 12] = b_N[12];
      sdvals[sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[36];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[37];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[38];
      sfvals[sfvals.size(1) * q + 13] = b_N[13];
      sdvals[sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[39];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[40];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[41];
    }
  } break;
  case 172: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double c_deriv[90];
      double c_N[30];
      ::sfe_sfuncs::pyra_30_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                  cs[cs.size(1) * q + 2], &c_N[0], &c_deriv[0]);
      sfvals[sfvals.size(1) * q] = c_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = c_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = c_deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = c_deriv[2];
      sfvals[sfvals.size(1) * q + 1] = c_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = c_deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[5];
      sfvals[sfvals.size(1) * q + 2] = c_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[8];
      sfvals[sfvals.size(1) * q + 3] = c_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[11];
      sfvals[sfvals.size(1) * q + 4] = c_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[14];
      sfvals[sfvals.size(1) * q + 5] = c_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[17];
      sfvals[sfvals.size(1) * q + 6] = c_N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[20];
      sfvals[sfvals.size(1) * q + 7] = c_N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[23];
      sfvals[sfvals.size(1) * q + 8] = c_N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[26];
      sfvals[sfvals.size(1) * q + 9] = c_N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[29];
      sfvals[sfvals.size(1) * q + 10] = c_N[10];
      sdvals[sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[30];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[31];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[32];
      sfvals[sfvals.size(1) * q + 11] = c_N[11];
      sdvals[sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[33];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[34];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[35];
      sfvals[sfvals.size(1) * q + 12] = c_N[12];
      sdvals[sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[36];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[37];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[38];
      sfvals[sfvals.size(1) * q + 13] = c_N[13];
      sdvals[sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[39];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[40];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[41];
      sfvals[sfvals.size(1) * q + 14] = c_N[14];
      sdvals[sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[42];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[43];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[44];
      sfvals[sfvals.size(1) * q + 15] = c_N[15];
      sdvals[sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[45];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[46];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[47];
      sfvals[sfvals.size(1) * q + 16] = c_N[16];
      sdvals[sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[48];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[49];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[50];
      sfvals[sfvals.size(1) * q + 17] = c_N[17];
      sdvals[sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[51];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[52];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[53];
      sfvals[sfvals.size(1) * q + 18] = c_N[18];
      sdvals[sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[54];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[55];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[56];
      sfvals[sfvals.size(1) * q + 19] = c_N[19];
      sdvals[sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[57];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[58];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[59];
      sfvals[sfvals.size(1) * q + 20] = c_N[20];
      sdvals[sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[60];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[61];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[62];
      sfvals[sfvals.size(1) * q + 21] = c_N[21];
      sdvals[sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[63];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[64];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[65];
      sfvals[sfvals.size(1) * q + 22] = c_N[22];
      sdvals[sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[66];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[67];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[68];
      sfvals[sfvals.size(1) * q + 23] = c_N[23];
      sdvals[sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[69];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[70];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[71];
      sfvals[sfvals.size(1) * q + 24] = c_N[24];
      sdvals[sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[72];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[73];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[74];
      sfvals[sfvals.size(1) * q + 25] = c_N[25];
      sdvals[sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[75];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[76];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[77];
      sfvals[sfvals.size(1) * q + 26] = c_N[26];
      sdvals[sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[78];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[79];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[80];
      sfvals[sfvals.size(1) * q + 27] = c_N[27];
      sdvals[sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[81];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[82];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[83];
      sfvals[sfvals.size(1) * q + 28] = c_N[28];
      sdvals[sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[84];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[85];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[86];
      sfvals[sfvals.size(1) * q + 29] = c_N[29];
      sdvals[sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[87];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[88];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[89];
    }
  } break;
  default: {
    m2cAssert(etype == 176, "Pyramid only support up to quartic");
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double d_deriv[165];
      double d_N[55];
      ::sfe_sfuncs::pyra_55_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                  cs[cs.size(1) * q + 2], &d_N[0], &d_deriv[0]);
      sfvals[sfvals.size(1) * q] = d_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = d_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = d_deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = d_deriv[2];
      sfvals[sfvals.size(1) * q + 1] = d_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = d_deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[5];
      sfvals[sfvals.size(1) * q + 2] = d_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[8];
      sfvals[sfvals.size(1) * q + 3] = d_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[11];
      sfvals[sfvals.size(1) * q + 4] = d_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[14];
      sfvals[sfvals.size(1) * q + 5] = d_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[17];
      sfvals[sfvals.size(1) * q + 6] = d_N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[20];
      sfvals[sfvals.size(1) * q + 7] = d_N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[23];
      sfvals[sfvals.size(1) * q + 8] = d_N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[26];
      sfvals[sfvals.size(1) * q + 9] = d_N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[29];
      sfvals[sfvals.size(1) * q + 10] = d_N[10];
      sdvals[sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[30];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[31];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[32];
      sfvals[sfvals.size(1) * q + 11] = d_N[11];
      sdvals[sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[33];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[34];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[35];
      sfvals[sfvals.size(1) * q + 12] = d_N[12];
      sdvals[sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[36];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[37];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[38];
      sfvals[sfvals.size(1) * q + 13] = d_N[13];
      sdvals[sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[39];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[40];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[41];
      sfvals[sfvals.size(1) * q + 14] = d_N[14];
      sdvals[sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[42];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[43];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[44];
      sfvals[sfvals.size(1) * q + 15] = d_N[15];
      sdvals[sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[45];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[46];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[47];
      sfvals[sfvals.size(1) * q + 16] = d_N[16];
      sdvals[sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[48];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[49];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[50];
      sfvals[sfvals.size(1) * q + 17] = d_N[17];
      sdvals[sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[51];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[52];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[53];
      sfvals[sfvals.size(1) * q + 18] = d_N[18];
      sdvals[sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[54];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[55];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[56];
      sfvals[sfvals.size(1) * q + 19] = d_N[19];
      sdvals[sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[57];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[58];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[59];
      sfvals[sfvals.size(1) * q + 20] = d_N[20];
      sdvals[sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[60];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[61];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[62];
      sfvals[sfvals.size(1) * q + 21] = d_N[21];
      sdvals[sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[63];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[64];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[65];
      sfvals[sfvals.size(1) * q + 22] = d_N[22];
      sdvals[sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[66];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[67];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[68];
      sfvals[sfvals.size(1) * q + 23] = d_N[23];
      sdvals[sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[69];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[70];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[71];
      sfvals[sfvals.size(1) * q + 24] = d_N[24];
      sdvals[sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[72];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[73];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[74];
      sfvals[sfvals.size(1) * q + 25] = d_N[25];
      sdvals[sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[75];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[76];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[77];
      sfvals[sfvals.size(1) * q + 26] = d_N[26];
      sdvals[sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[78];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[79];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[80];
      sfvals[sfvals.size(1) * q + 27] = d_N[27];
      sdvals[sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[81];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[82];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[83];
      sfvals[sfvals.size(1) * q + 28] = d_N[28];
      sdvals[sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[84];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[85];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[86];
      sfvals[sfvals.size(1) * q + 29] = d_N[29];
      sdvals[sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[87];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[88];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[89];
      sfvals[sfvals.size(1) * q + 30] = d_N[30];
      sdvals[sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[90];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[91];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[92];
      sfvals[sfvals.size(1) * q + 31] = d_N[31];
      sdvals[sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[93];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[94];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[95];
      sfvals[sfvals.size(1) * q + 32] = d_N[32];
      sdvals[sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[96];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[97];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[98];
      sfvals[sfvals.size(1) * q + 33] = d_N[33];
      sdvals[sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[99];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[100];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[101];
      sfvals[sfvals.size(1) * q + 34] = d_N[34];
      sdvals[sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[102];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[103];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[104];
      sfvals[sfvals.size(1) * q + 35] = d_N[35];
      sdvals[sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[105];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[106];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[107];
      sfvals[sfvals.size(1) * q + 36] = d_N[36];
      sdvals[sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[108];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[109];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[110];
      sfvals[sfvals.size(1) * q + 37] = d_N[37];
      sdvals[sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[111];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[112];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[113];
      sfvals[sfvals.size(1) * q + 38] = d_N[38];
      sdvals[sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[114];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[115];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[116];
      sfvals[sfvals.size(1) * q + 39] = d_N[39];
      sdvals[sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[117];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[118];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[119];
      sfvals[sfvals.size(1) * q + 40] = d_N[40];
      sdvals[sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[120];
      sdvals[(sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[121];
      sdvals[(sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[122];
      sfvals[sfvals.size(1) * q + 41] = d_N[41];
      sdvals[sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[123];
      sdvals[(sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[124];
      sdvals[(sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[125];
      sfvals[sfvals.size(1) * q + 42] = d_N[42];
      sdvals[sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[126];
      sdvals[(sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[127];
      sdvals[(sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[128];
      sfvals[sfvals.size(1) * q + 43] = d_N[43];
      sdvals[sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[129];
      sdvals[(sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[130];
      sdvals[(sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[131];
      sfvals[sfvals.size(1) * q + 44] = d_N[44];
      sdvals[sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[132];
      sdvals[(sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[133];
      sdvals[(sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[134];
      sfvals[sfvals.size(1) * q + 45] = d_N[45];
      sdvals[sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[135];
      sdvals[(sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[136];
      sdvals[(sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[137];
      sfvals[sfvals.size(1) * q + 46] = d_N[46];
      sdvals[sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[138];
      sdvals[(sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[139];
      sdvals[(sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[140];
      sfvals[sfvals.size(1) * q + 47] = d_N[47];
      sdvals[sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[141];
      sdvals[(sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[142];
      sdvals[(sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[143];
      sfvals[sfvals.size(1) * q + 48] = d_N[48];
      sdvals[sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[144];
      sdvals[(sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[145];
      sdvals[(sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[146];
      sfvals[sfvals.size(1) * q + 49] = d_N[49];
      sdvals[sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[147];
      sdvals[(sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[148];
      sdvals[(sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[149];
      sfvals[sfvals.size(1) * q + 50] = d_N[50];
      sdvals[sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[150];
      sdvals[(sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[151];
      sdvals[(sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[152];
      sfvals[sfvals.size(1) * q + 51] = d_N[51];
      sdvals[sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[153];
      sdvals[(sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[154];
      sdvals[(sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[155];
      sfvals[sfvals.size(1) * q + 52] = d_N[52];
      sdvals[sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[156];
      sdvals[(sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[157];
      sdvals[(sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[158];
      sfvals[sfvals.size(1) * q + 53] = d_N[53];
      sdvals[sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[159];
      sdvals[(sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[160];
      sdvals[(sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[161];
      sfvals[sfvals.size(1) * q + 54] = d_N[54];
      sdvals[sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q] =
          d_deriv[162];
      sdvals[(sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          d_deriv[163];
      sdvals[(sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          d_deriv[164];
    }
  } break;
  }
}

static void sfe3_tabulate_equi_tet(coder::SizeType etype,
                                   const ::coder::array<double, 2U> &cs,
                                   ::coder::array<double, 2U> &sfvals,
                                   ::coder::array<double, 3U> &sdvals)
{
  coder::SizeType i;
  coder::SizeType nqp;
  //  tet
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  switch (etype) {
  case 132: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double deriv[12];
      double N[4];
      ::sfe_sfuncs::tet_4_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                cs[cs.size(1) * q + 2], &N[0], &deriv[0]);
      sfvals[sfvals.size(1) * q] = N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = deriv[2];
      sfvals[sfvals.size(1) * q + 1] = N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[5];
      sfvals[sfvals.size(1) * q + 2] = N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[8];
      sfvals[sfvals.size(1) * q + 3] = N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[11];
    }
  } break;
  case 136: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double b_deriv[30];
      double b_N[10];
      ::sfe_sfuncs::tet_10_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 cs[cs.size(1) * q + 2], &b_N[0], &b_deriv[0]);
      sfvals[sfvals.size(1) * q] = b_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = b_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = b_deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = b_deriv[2];
      sfvals[sfvals.size(1) * q + 1] = b_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = b_deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[5];
      sfvals[sfvals.size(1) * q + 2] = b_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[8];
      sfvals[sfvals.size(1) * q + 3] = b_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[11];
      sfvals[sfvals.size(1) * q + 4] = b_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[14];
      sfvals[sfvals.size(1) * q + 5] = b_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[17];
      sfvals[sfvals.size(1) * q + 6] = b_N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[20];
      sfvals[sfvals.size(1) * q + 7] = b_N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[23];
      sfvals[sfvals.size(1) * q + 8] = b_N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[26];
      sfvals[sfvals.size(1) * q + 9] = b_N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[29];
    }
  } break;
  case 140: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double c_deriv[60];
      double c_N[20];
      ::sfe_sfuncs::tet_20_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 cs[cs.size(1) * q + 2], &c_N[0], &c_deriv[0]);
      for (coder::SizeType b_i{0}; b_i < 20; b_i++) {
        sfvals[b_i + sfvals.size(1) * q] = c_N[b_i];
        sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
            c_deriv[3 * b_i];
        sdvals[(sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q) +
               1] = c_deriv[3 * b_i + 1];
        sdvals[(sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q) +
               2] = c_deriv[3 * b_i + 2];
      }
    }
  } break;
  case 144: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double d_deriv[105];
      double d_N[35];
      ::sfe_sfuncs::tet_35_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 cs[cs.size(1) * q + 2], &d_N[0], &d_deriv[0]);
      for (coder::SizeType b_i{0}; b_i < 35; b_i++) {
        sfvals[b_i + sfvals.size(1) * q] = d_N[b_i];
        sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
            d_deriv[3 * b_i];
        sdvals[(sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q) +
               1] = d_deriv[3 * b_i + 1];
        sdvals[(sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q) +
               2] = d_deriv[3 * b_i + 2];
      }
    }
  } break;
  default: {
    m2cAssert(
        etype == 148,
        "Gauss-Lobatto tetrahedral elements are supported only up to quintic");
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double e_deriv[168];
      double e_N[56];
      ::sfe_sfuncs::tet_56_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 cs[cs.size(1) * q + 2], &e_N[0], &e_deriv[0]);
      for (coder::SizeType b_i{0}; b_i < 56; b_i++) {
        sfvals[b_i + sfvals.size(1) * q] = e_N[b_i];
        sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
            e_deriv[3 * b_i];
        sdvals[(sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q) +
               1] = e_deriv[3 * b_i + 1];
        sdvals[(sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q) +
               2] = e_deriv[3 * b_i + 2];
      }
    }
  } break;
  }
}

static void sfe3_tabulate_gl_prism(coder::SizeType etype,
                                   const ::coder::array<double, 2U> &cs,
                                   ::coder::array<double, 2U> &sfvals,
                                   ::coder::array<double, 3U> &sdvals)
{
  coder::SizeType i;
  coder::SizeType nqp;
  //  prisms
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  switch (etype) {
  case 205: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double deriv[120];
      double N[40];
      ::sfe_sfuncs::prism_gl_40_sfunc(cs[cs.size(1) * q],
                                      cs[cs.size(1) * q + 1],
                                      cs[cs.size(1) * q + 2], &N[0], &deriv[0]);
      sfvals[sfvals.size(1) * q] = N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = deriv[2];
      sfvals[sfvals.size(1) * q + 1] = N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[5];
      sfvals[sfvals.size(1) * q + 2] = N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[8];
      sfvals[sfvals.size(1) * q + 3] = N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[11];
      sfvals[sfvals.size(1) * q + 4] = N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[14];
      sfvals[sfvals.size(1) * q + 5] = N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[17];
      sfvals[sfvals.size(1) * q + 6] = N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[20];
      sfvals[sfvals.size(1) * q + 7] = N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[23];
      sfvals[sfvals.size(1) * q + 8] = N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[26];
      sfvals[sfvals.size(1) * q + 9] = N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[29];
      sfvals[sfvals.size(1) * q + 10] = N[10];
      sdvals[sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[30];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[31];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[32];
      sfvals[sfvals.size(1) * q + 11] = N[11];
      sdvals[sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[33];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[34];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[35];
      sfvals[sfvals.size(1) * q + 12] = N[12];
      sdvals[sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[36];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[37];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[38];
      sfvals[sfvals.size(1) * q + 13] = N[13];
      sdvals[sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[39];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[40];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[41];
      sfvals[sfvals.size(1) * q + 14] = N[14];
      sdvals[sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[42];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[43];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[44];
      sfvals[sfvals.size(1) * q + 15] = N[15];
      sdvals[sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[45];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[46];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[47];
      sfvals[sfvals.size(1) * q + 16] = N[16];
      sdvals[sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[48];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[49];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[50];
      sfvals[sfvals.size(1) * q + 17] = N[17];
      sdvals[sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[51];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[52];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[53];
      sfvals[sfvals.size(1) * q + 18] = N[18];
      sdvals[sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[54];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[55];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[56];
      sfvals[sfvals.size(1) * q + 19] = N[19];
      sdvals[sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[57];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[58];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[59];
      sfvals[sfvals.size(1) * q + 20] = N[20];
      sdvals[sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[60];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[61];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[62];
      sfvals[sfvals.size(1) * q + 21] = N[21];
      sdvals[sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[63];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[64];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[65];
      sfvals[sfvals.size(1) * q + 22] = N[22];
      sdvals[sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[66];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[67];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[68];
      sfvals[sfvals.size(1) * q + 23] = N[23];
      sdvals[sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[69];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[70];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[71];
      sfvals[sfvals.size(1) * q + 24] = N[24];
      sdvals[sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[72];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[73];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[74];
      sfvals[sfvals.size(1) * q + 25] = N[25];
      sdvals[sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[75];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[76];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[77];
      sfvals[sfvals.size(1) * q + 26] = N[26];
      sdvals[sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[78];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[79];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[80];
      sfvals[sfvals.size(1) * q + 27] = N[27];
      sdvals[sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[81];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[82];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[83];
      sfvals[sfvals.size(1) * q + 28] = N[28];
      sdvals[sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[84];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[85];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[86];
      sfvals[sfvals.size(1) * q + 29] = N[29];
      sdvals[sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[87];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[88];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[89];
      sfvals[sfvals.size(1) * q + 30] = N[30];
      sdvals[sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[90];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[91];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[92];
      sfvals[sfvals.size(1) * q + 31] = N[31];
      sdvals[sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[93];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[94];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[95];
      sfvals[sfvals.size(1) * q + 32] = N[32];
      sdvals[sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[96];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[97];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[98];
      sfvals[sfvals.size(1) * q + 33] = N[33];
      sdvals[sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[99];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[100];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[101];
      sfvals[sfvals.size(1) * q + 34] = N[34];
      sdvals[sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[102];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[103];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[104];
      sfvals[sfvals.size(1) * q + 35] = N[35];
      sdvals[sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[105];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[106];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[107];
      sfvals[sfvals.size(1) * q + 36] = N[36];
      sdvals[sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[108];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[109];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[110];
      sfvals[sfvals.size(1) * q + 37] = N[37];
      sdvals[sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[111];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[112];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[113];
      sfvals[sfvals.size(1) * q + 38] = N[38];
      sdvals[sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[114];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[115];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[116];
      sfvals[sfvals.size(1) * q + 39] = N[39];
      sdvals[sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[117];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[118];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[119];
    }
  } break;
  case 209: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double b_deriv[225];
      double b_N[75];
      ::sfe_sfuncs::prism_gl_75_sfunc(
          cs[cs.size(1) * q], cs[cs.size(1) * q + 1], cs[cs.size(1) * q + 2],
          &b_N[0], &b_deriv[0]);
      sfvals[sfvals.size(1) * q] = b_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = b_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = b_deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = b_deriv[2];
      sfvals[sfvals.size(1) * q + 1] = b_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = b_deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[5];
      sfvals[sfvals.size(1) * q + 2] = b_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[8];
      sfvals[sfvals.size(1) * q + 3] = b_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[11];
      sfvals[sfvals.size(1) * q + 4] = b_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[14];
      sfvals[sfvals.size(1) * q + 5] = b_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[17];
      sfvals[sfvals.size(1) * q + 6] = b_N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[20];
      sfvals[sfvals.size(1) * q + 7] = b_N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[23];
      sfvals[sfvals.size(1) * q + 8] = b_N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[26];
      sfvals[sfvals.size(1) * q + 9] = b_N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[29];
      sfvals[sfvals.size(1) * q + 10] = b_N[10];
      sdvals[sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[30];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[31];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[32];
      sfvals[sfvals.size(1) * q + 11] = b_N[11];
      sdvals[sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[33];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[34];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[35];
      sfvals[sfvals.size(1) * q + 12] = b_N[12];
      sdvals[sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[36];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[37];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[38];
      sfvals[sfvals.size(1) * q + 13] = b_N[13];
      sdvals[sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[39];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[40];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[41];
      sfvals[sfvals.size(1) * q + 14] = b_N[14];
      sdvals[sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[42];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[43];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[44];
      sfvals[sfvals.size(1) * q + 15] = b_N[15];
      sdvals[sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[45];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[46];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[47];
      sfvals[sfvals.size(1) * q + 16] = b_N[16];
      sdvals[sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[48];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[49];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[50];
      sfvals[sfvals.size(1) * q + 17] = b_N[17];
      sdvals[sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[51];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[52];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[53];
      sfvals[sfvals.size(1) * q + 18] = b_N[18];
      sdvals[sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[54];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[55];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[56];
      sfvals[sfvals.size(1) * q + 19] = b_N[19];
      sdvals[sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[57];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[58];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[59];
      sfvals[sfvals.size(1) * q + 20] = b_N[20];
      sdvals[sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[60];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[61];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[62];
      sfvals[sfvals.size(1) * q + 21] = b_N[21];
      sdvals[sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[63];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[64];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[65];
      sfvals[sfvals.size(1) * q + 22] = b_N[22];
      sdvals[sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[66];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[67];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[68];
      sfvals[sfvals.size(1) * q + 23] = b_N[23];
      sdvals[sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[69];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[70];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[71];
      sfvals[sfvals.size(1) * q + 24] = b_N[24];
      sdvals[sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[72];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[73];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[74];
      sfvals[sfvals.size(1) * q + 25] = b_N[25];
      sdvals[sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[75];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[76];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[77];
      sfvals[sfvals.size(1) * q + 26] = b_N[26];
      sdvals[sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[78];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[79];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[80];
      sfvals[sfvals.size(1) * q + 27] = b_N[27];
      sdvals[sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[81];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[82];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[83];
      sfvals[sfvals.size(1) * q + 28] = b_N[28];
      sdvals[sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[84];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[85];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[86];
      sfvals[sfvals.size(1) * q + 29] = b_N[29];
      sdvals[sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[87];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[88];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[89];
      sfvals[sfvals.size(1) * q + 30] = b_N[30];
      sdvals[sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[90];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[91];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[92];
      sfvals[sfvals.size(1) * q + 31] = b_N[31];
      sdvals[sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[93];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[94];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[95];
      sfvals[sfvals.size(1) * q + 32] = b_N[32];
      sdvals[sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[96];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[97];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[98];
      sfvals[sfvals.size(1) * q + 33] = b_N[33];
      sdvals[sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[99];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[100];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[101];
      sfvals[sfvals.size(1) * q + 34] = b_N[34];
      sdvals[sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[102];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[103];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[104];
      sfvals[sfvals.size(1) * q + 35] = b_N[35];
      sdvals[sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[105];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[106];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[107];
      sfvals[sfvals.size(1) * q + 36] = b_N[36];
      sdvals[sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[108];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[109];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[110];
      sfvals[sfvals.size(1) * q + 37] = b_N[37];
      sdvals[sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[111];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[112];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[113];
      sfvals[sfvals.size(1) * q + 38] = b_N[38];
      sdvals[sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[114];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[115];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[116];
      sfvals[sfvals.size(1) * q + 39] = b_N[39];
      sdvals[sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[117];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[118];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[119];
      sfvals[sfvals.size(1) * q + 40] = b_N[40];
      sdvals[sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[120];
      sdvals[(sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[121];
      sdvals[(sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[122];
      sfvals[sfvals.size(1) * q + 41] = b_N[41];
      sdvals[sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[123];
      sdvals[(sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[124];
      sdvals[(sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[125];
      sfvals[sfvals.size(1) * q + 42] = b_N[42];
      sdvals[sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[126];
      sdvals[(sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[127];
      sdvals[(sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[128];
      sfvals[sfvals.size(1) * q + 43] = b_N[43];
      sdvals[sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[129];
      sdvals[(sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[130];
      sdvals[(sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[131];
      sfvals[sfvals.size(1) * q + 44] = b_N[44];
      sdvals[sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[132];
      sdvals[(sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[133];
      sdvals[(sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[134];
      sfvals[sfvals.size(1) * q + 45] = b_N[45];
      sdvals[sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[135];
      sdvals[(sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[136];
      sdvals[(sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[137];
      sfvals[sfvals.size(1) * q + 46] = b_N[46];
      sdvals[sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[138];
      sdvals[(sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[139];
      sdvals[(sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[140];
      sfvals[sfvals.size(1) * q + 47] = b_N[47];
      sdvals[sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[141];
      sdvals[(sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[142];
      sdvals[(sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[143];
      sfvals[sfvals.size(1) * q + 48] = b_N[48];
      sdvals[sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[144];
      sdvals[(sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[145];
      sdvals[(sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[146];
      sfvals[sfvals.size(1) * q + 49] = b_N[49];
      sdvals[sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[147];
      sdvals[(sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[148];
      sdvals[(sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[149];
      sfvals[sfvals.size(1) * q + 50] = b_N[50];
      sdvals[sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[150];
      sdvals[(sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[151];
      sdvals[(sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[152];
      sfvals[sfvals.size(1) * q + 51] = b_N[51];
      sdvals[sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[153];
      sdvals[(sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[154];
      sdvals[(sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[155];
      sfvals[sfvals.size(1) * q + 52] = b_N[52];
      sdvals[sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[156];
      sdvals[(sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[157];
      sdvals[(sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[158];
      sfvals[sfvals.size(1) * q + 53] = b_N[53];
      sdvals[sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[159];
      sdvals[(sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[160];
      sdvals[(sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[161];
      sfvals[sfvals.size(1) * q + 54] = b_N[54];
      sdvals[sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[162];
      sdvals[(sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[163];
      sdvals[(sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[164];
      sfvals[sfvals.size(1) * q + 55] = b_N[55];
      sdvals[sdvals.size(2) * 55 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[165];
      sdvals[(sdvals.size(2) * 55 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[166];
      sdvals[(sdvals.size(2) * 55 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[167];
      sfvals[sfvals.size(1) * q + 56] = b_N[56];
      sdvals[sdvals.size(2) * 56 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[168];
      sdvals[(sdvals.size(2) * 56 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[169];
      sdvals[(sdvals.size(2) * 56 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[170];
      sfvals[sfvals.size(1) * q + 57] = b_N[57];
      sdvals[sdvals.size(2) * 57 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[171];
      sdvals[(sdvals.size(2) * 57 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[172];
      sdvals[(sdvals.size(2) * 57 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[173];
      sfvals[sfvals.size(1) * q + 58] = b_N[58];
      sdvals[sdvals.size(2) * 58 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[174];
      sdvals[(sdvals.size(2) * 58 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[175];
      sdvals[(sdvals.size(2) * 58 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[176];
      sfvals[sfvals.size(1) * q + 59] = b_N[59];
      sdvals[sdvals.size(2) * 59 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[177];
      sdvals[(sdvals.size(2) * 59 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[178];
      sdvals[(sdvals.size(2) * 59 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[179];
      sfvals[sfvals.size(1) * q + 60] = b_N[60];
      sdvals[sdvals.size(2) * 60 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[180];
      sdvals[(sdvals.size(2) * 60 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[181];
      sdvals[(sdvals.size(2) * 60 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[182];
      sfvals[sfvals.size(1) * q + 61] = b_N[61];
      sdvals[sdvals.size(2) * 61 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[183];
      sdvals[(sdvals.size(2) * 61 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[184];
      sdvals[(sdvals.size(2) * 61 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[185];
      sfvals[sfvals.size(1) * q + 62] = b_N[62];
      sdvals[sdvals.size(2) * 62 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[186];
      sdvals[(sdvals.size(2) * 62 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[187];
      sdvals[(sdvals.size(2) * 62 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[188];
      sfvals[sfvals.size(1) * q + 63] = b_N[63];
      sdvals[sdvals.size(2) * 63 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[189];
      sdvals[(sdvals.size(2) * 63 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[190];
      sdvals[(sdvals.size(2) * 63 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[191];
      sfvals[sfvals.size(1) * q + 64] = b_N[64];
      sdvals[sdvals.size(2) * 64 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[192];
      sdvals[(sdvals.size(2) * 64 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[193];
      sdvals[(sdvals.size(2) * 64 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[194];
      sfvals[sfvals.size(1) * q + 65] = b_N[65];
      sdvals[sdvals.size(2) * 65 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[195];
      sdvals[(sdvals.size(2) * 65 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[196];
      sdvals[(sdvals.size(2) * 65 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[197];
      sfvals[sfvals.size(1) * q + 66] = b_N[66];
      sdvals[sdvals.size(2) * 66 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[198];
      sdvals[(sdvals.size(2) * 66 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[199];
      sdvals[(sdvals.size(2) * 66 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[200];
      sfvals[sfvals.size(1) * q + 67] = b_N[67];
      sdvals[sdvals.size(2) * 67 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[201];
      sdvals[(sdvals.size(2) * 67 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[202];
      sdvals[(sdvals.size(2) * 67 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[203];
      sfvals[sfvals.size(1) * q + 68] = b_N[68];
      sdvals[sdvals.size(2) * 68 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[204];
      sdvals[(sdvals.size(2) * 68 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[205];
      sdvals[(sdvals.size(2) * 68 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[206];
      sfvals[sfvals.size(1) * q + 69] = b_N[69];
      sdvals[sdvals.size(2) * 69 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[207];
      sdvals[(sdvals.size(2) * 69 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[208];
      sdvals[(sdvals.size(2) * 69 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[209];
      sfvals[sfvals.size(1) * q + 70] = b_N[70];
      sdvals[sdvals.size(2) * 70 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[210];
      sdvals[(sdvals.size(2) * 70 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[211];
      sdvals[(sdvals.size(2) * 70 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[212];
      sfvals[sfvals.size(1) * q + 71] = b_N[71];
      sdvals[sdvals.size(2) * 71 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[213];
      sdvals[(sdvals.size(2) * 71 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[214];
      sdvals[(sdvals.size(2) * 71 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[215];
      sfvals[sfvals.size(1) * q + 72] = b_N[72];
      sdvals[sdvals.size(2) * 72 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[216];
      sdvals[(sdvals.size(2) * 72 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[217];
      sdvals[(sdvals.size(2) * 72 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[218];
      sfvals[sfvals.size(1) * q + 73] = b_N[73];
      sdvals[sdvals.size(2) * 73 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[219];
      sdvals[(sdvals.size(2) * 73 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[220];
      sdvals[(sdvals.size(2) * 73 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[221];
      sfvals[sfvals.size(1) * q + 74] = b_N[74];
      sdvals[sdvals.size(2) * 74 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[222];
      sdvals[(sdvals.size(2) * 74 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[223];
      sdvals[(sdvals.size(2) * 74 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[224];
    }
  } break;
  default: {
    m2cAssert(etype == 213, "Gauss-Lobatoo only supports up to quintic.");
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double c_deriv[378];
      double c_N[126];
      ::sfe_sfuncs::prism_gl_126_sfunc(
          cs[cs.size(1) * q], cs[cs.size(1) * q + 1], cs[cs.size(1) * q + 2],
          &c_N[0], &c_deriv[0]);
      sfvals[sfvals.size(1) * q] = c_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = c_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = c_deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = c_deriv[2];
      sfvals[sfvals.size(1) * q + 1] = c_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = c_deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[5];
      sfvals[sfvals.size(1) * q + 2] = c_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[8];
      sfvals[sfvals.size(1) * q + 3] = c_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[11];
      sfvals[sfvals.size(1) * q + 4] = c_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[14];
      sfvals[sfvals.size(1) * q + 5] = c_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[17];
      sfvals[sfvals.size(1) * q + 6] = c_N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[20];
      sfvals[sfvals.size(1) * q + 7] = c_N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[23];
      sfvals[sfvals.size(1) * q + 8] = c_N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[26];
      sfvals[sfvals.size(1) * q + 9] = c_N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[29];
      sfvals[sfvals.size(1) * q + 10] = c_N[10];
      sdvals[sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[30];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[31];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[32];
      sfvals[sfvals.size(1) * q + 11] = c_N[11];
      sdvals[sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[33];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[34];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[35];
      sfvals[sfvals.size(1) * q + 12] = c_N[12];
      sdvals[sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[36];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[37];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[38];
      sfvals[sfvals.size(1) * q + 13] = c_N[13];
      sdvals[sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[39];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[40];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[41];
      sfvals[sfvals.size(1) * q + 14] = c_N[14];
      sdvals[sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[42];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[43];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[44];
      sfvals[sfvals.size(1) * q + 15] = c_N[15];
      sdvals[sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[45];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[46];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[47];
      sfvals[sfvals.size(1) * q + 16] = c_N[16];
      sdvals[sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[48];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[49];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[50];
      sfvals[sfvals.size(1) * q + 17] = c_N[17];
      sdvals[sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[51];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[52];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[53];
      sfvals[sfvals.size(1) * q + 18] = c_N[18];
      sdvals[sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[54];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[55];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[56];
      sfvals[sfvals.size(1) * q + 19] = c_N[19];
      sdvals[sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[57];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[58];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[59];
      sfvals[sfvals.size(1) * q + 20] = c_N[20];
      sdvals[sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[60];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[61];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[62];
      sfvals[sfvals.size(1) * q + 21] = c_N[21];
      sdvals[sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[63];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[64];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[65];
      sfvals[sfvals.size(1) * q + 22] = c_N[22];
      sdvals[sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[66];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[67];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[68];
      sfvals[sfvals.size(1) * q + 23] = c_N[23];
      sdvals[sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[69];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[70];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[71];
      sfvals[sfvals.size(1) * q + 24] = c_N[24];
      sdvals[sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[72];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[73];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[74];
      sfvals[sfvals.size(1) * q + 25] = c_N[25];
      sdvals[sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[75];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[76];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[77];
      sfvals[sfvals.size(1) * q + 26] = c_N[26];
      sdvals[sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[78];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[79];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[80];
      sfvals[sfvals.size(1) * q + 27] = c_N[27];
      sdvals[sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[81];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[82];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[83];
      sfvals[sfvals.size(1) * q + 28] = c_N[28];
      sdvals[sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[84];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[85];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[86];
      sfvals[sfvals.size(1) * q + 29] = c_N[29];
      sdvals[sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[87];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[88];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[89];
      sfvals[sfvals.size(1) * q + 30] = c_N[30];
      sdvals[sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[90];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[91];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[92];
      sfvals[sfvals.size(1) * q + 31] = c_N[31];
      sdvals[sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[93];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[94];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[95];
      sfvals[sfvals.size(1) * q + 32] = c_N[32];
      sdvals[sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[96];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[97];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[98];
      sfvals[sfvals.size(1) * q + 33] = c_N[33];
      sdvals[sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[99];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[100];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[101];
      sfvals[sfvals.size(1) * q + 34] = c_N[34];
      sdvals[sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[102];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[103];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[104];
      sfvals[sfvals.size(1) * q + 35] = c_N[35];
      sdvals[sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[105];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[106];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[107];
      sfvals[sfvals.size(1) * q + 36] = c_N[36];
      sdvals[sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[108];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[109];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[110];
      sfvals[sfvals.size(1) * q + 37] = c_N[37];
      sdvals[sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[111];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[112];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[113];
      sfvals[sfvals.size(1) * q + 38] = c_N[38];
      sdvals[sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[114];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[115];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[116];
      sfvals[sfvals.size(1) * q + 39] = c_N[39];
      sdvals[sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[117];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[118];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[119];
      sfvals[sfvals.size(1) * q + 40] = c_N[40];
      sdvals[sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[120];
      sdvals[(sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[121];
      sdvals[(sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[122];
      sfvals[sfvals.size(1) * q + 41] = c_N[41];
      sdvals[sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[123];
      sdvals[(sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[124];
      sdvals[(sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[125];
      sfvals[sfvals.size(1) * q + 42] = c_N[42];
      sdvals[sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[126];
      sdvals[(sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[127];
      sdvals[(sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[128];
      sfvals[sfvals.size(1) * q + 43] = c_N[43];
      sdvals[sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[129];
      sdvals[(sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[130];
      sdvals[(sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[131];
      sfvals[sfvals.size(1) * q + 44] = c_N[44];
      sdvals[sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[132];
      sdvals[(sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[133];
      sdvals[(sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[134];
      sfvals[sfvals.size(1) * q + 45] = c_N[45];
      sdvals[sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[135];
      sdvals[(sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[136];
      sdvals[(sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[137];
      sfvals[sfvals.size(1) * q + 46] = c_N[46];
      sdvals[sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[138];
      sdvals[(sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[139];
      sdvals[(sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[140];
      sfvals[sfvals.size(1) * q + 47] = c_N[47];
      sdvals[sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[141];
      sdvals[(sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[142];
      sdvals[(sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[143];
      sfvals[sfvals.size(1) * q + 48] = c_N[48];
      sdvals[sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[144];
      sdvals[(sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[145];
      sdvals[(sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[146];
      sfvals[sfvals.size(1) * q + 49] = c_N[49];
      sdvals[sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[147];
      sdvals[(sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[148];
      sdvals[(sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[149];
      sfvals[sfvals.size(1) * q + 50] = c_N[50];
      sdvals[sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[150];
      sdvals[(sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[151];
      sdvals[(sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[152];
      sfvals[sfvals.size(1) * q + 51] = c_N[51];
      sdvals[sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[153];
      sdvals[(sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[154];
      sdvals[(sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[155];
      sfvals[sfvals.size(1) * q + 52] = c_N[52];
      sdvals[sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[156];
      sdvals[(sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[157];
      sdvals[(sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[158];
      sfvals[sfvals.size(1) * q + 53] = c_N[53];
      sdvals[sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[159];
      sdvals[(sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[160];
      sdvals[(sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[161];
      sfvals[sfvals.size(1) * q + 54] = c_N[54];
      sdvals[sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[162];
      sdvals[(sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[163];
      sdvals[(sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[164];
      sfvals[sfvals.size(1) * q + 55] = c_N[55];
      sdvals[sdvals.size(2) * 55 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[165];
      sdvals[(sdvals.size(2) * 55 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[166];
      sdvals[(sdvals.size(2) * 55 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[167];
      sfvals[sfvals.size(1) * q + 56] = c_N[56];
      sdvals[sdvals.size(2) * 56 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[168];
      sdvals[(sdvals.size(2) * 56 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[169];
      sdvals[(sdvals.size(2) * 56 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[170];
      sfvals[sfvals.size(1) * q + 57] = c_N[57];
      sdvals[sdvals.size(2) * 57 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[171];
      sdvals[(sdvals.size(2) * 57 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[172];
      sdvals[(sdvals.size(2) * 57 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[173];
      sfvals[sfvals.size(1) * q + 58] = c_N[58];
      sdvals[sdvals.size(2) * 58 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[174];
      sdvals[(sdvals.size(2) * 58 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[175];
      sdvals[(sdvals.size(2) * 58 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[176];
      sfvals[sfvals.size(1) * q + 59] = c_N[59];
      sdvals[sdvals.size(2) * 59 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[177];
      sdvals[(sdvals.size(2) * 59 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[178];
      sdvals[(sdvals.size(2) * 59 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[179];
      sfvals[sfvals.size(1) * q + 60] = c_N[60];
      sdvals[sdvals.size(2) * 60 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[180];
      sdvals[(sdvals.size(2) * 60 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[181];
      sdvals[(sdvals.size(2) * 60 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[182];
      sfvals[sfvals.size(1) * q + 61] = c_N[61];
      sdvals[sdvals.size(2) * 61 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[183];
      sdvals[(sdvals.size(2) * 61 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[184];
      sdvals[(sdvals.size(2) * 61 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[185];
      sfvals[sfvals.size(1) * q + 62] = c_N[62];
      sdvals[sdvals.size(2) * 62 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[186];
      sdvals[(sdvals.size(2) * 62 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[187];
      sdvals[(sdvals.size(2) * 62 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[188];
      sfvals[sfvals.size(1) * q + 63] = c_N[63];
      sdvals[sdvals.size(2) * 63 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[189];
      sdvals[(sdvals.size(2) * 63 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[190];
      sdvals[(sdvals.size(2) * 63 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[191];
      sfvals[sfvals.size(1) * q + 64] = c_N[64];
      sdvals[sdvals.size(2) * 64 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[192];
      sdvals[(sdvals.size(2) * 64 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[193];
      sdvals[(sdvals.size(2) * 64 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[194];
      sfvals[sfvals.size(1) * q + 65] = c_N[65];
      sdvals[sdvals.size(2) * 65 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[195];
      sdvals[(sdvals.size(2) * 65 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[196];
      sdvals[(sdvals.size(2) * 65 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[197];
      sfvals[sfvals.size(1) * q + 66] = c_N[66];
      sdvals[sdvals.size(2) * 66 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[198];
      sdvals[(sdvals.size(2) * 66 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[199];
      sdvals[(sdvals.size(2) * 66 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[200];
      sfvals[sfvals.size(1) * q + 67] = c_N[67];
      sdvals[sdvals.size(2) * 67 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[201];
      sdvals[(sdvals.size(2) * 67 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[202];
      sdvals[(sdvals.size(2) * 67 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[203];
      sfvals[sfvals.size(1) * q + 68] = c_N[68];
      sdvals[sdvals.size(2) * 68 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[204];
      sdvals[(sdvals.size(2) * 68 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[205];
      sdvals[(sdvals.size(2) * 68 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[206];
      sfvals[sfvals.size(1) * q + 69] = c_N[69];
      sdvals[sdvals.size(2) * 69 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[207];
      sdvals[(sdvals.size(2) * 69 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[208];
      sdvals[(sdvals.size(2) * 69 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[209];
      sfvals[sfvals.size(1) * q + 70] = c_N[70];
      sdvals[sdvals.size(2) * 70 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[210];
      sdvals[(sdvals.size(2) * 70 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[211];
      sdvals[(sdvals.size(2) * 70 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[212];
      sfvals[sfvals.size(1) * q + 71] = c_N[71];
      sdvals[sdvals.size(2) * 71 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[213];
      sdvals[(sdvals.size(2) * 71 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[214];
      sdvals[(sdvals.size(2) * 71 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[215];
      sfvals[sfvals.size(1) * q + 72] = c_N[72];
      sdvals[sdvals.size(2) * 72 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[216];
      sdvals[(sdvals.size(2) * 72 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[217];
      sdvals[(sdvals.size(2) * 72 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[218];
      sfvals[sfvals.size(1) * q + 73] = c_N[73];
      sdvals[sdvals.size(2) * 73 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[219];
      sdvals[(sdvals.size(2) * 73 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[220];
      sdvals[(sdvals.size(2) * 73 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[221];
      sfvals[sfvals.size(1) * q + 74] = c_N[74];
      sdvals[sdvals.size(2) * 74 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[222];
      sdvals[(sdvals.size(2) * 74 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[223];
      sdvals[(sdvals.size(2) * 74 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[224];
      sfvals[sfvals.size(1) * q + 75] = c_N[75];
      sdvals[sdvals.size(2) * 75 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[225];
      sdvals[(sdvals.size(2) * 75 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[226];
      sdvals[(sdvals.size(2) * 75 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[227];
      sfvals[sfvals.size(1) * q + 76] = c_N[76];
      sdvals[sdvals.size(2) * 76 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[228];
      sdvals[(sdvals.size(2) * 76 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[229];
      sdvals[(sdvals.size(2) * 76 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[230];
      sfvals[sfvals.size(1) * q + 77] = c_N[77];
      sdvals[sdvals.size(2) * 77 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[231];
      sdvals[(sdvals.size(2) * 77 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[232];
      sdvals[(sdvals.size(2) * 77 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[233];
      sfvals[sfvals.size(1) * q + 78] = c_N[78];
      sdvals[sdvals.size(2) * 78 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[234];
      sdvals[(sdvals.size(2) * 78 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[235];
      sdvals[(sdvals.size(2) * 78 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[236];
      sfvals[sfvals.size(1) * q + 79] = c_N[79];
      sdvals[sdvals.size(2) * 79 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[237];
      sdvals[(sdvals.size(2) * 79 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[238];
      sdvals[(sdvals.size(2) * 79 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[239];
      sfvals[sfvals.size(1) * q + 80] = c_N[80];
      sdvals[sdvals.size(2) * 80 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[240];
      sdvals[(sdvals.size(2) * 80 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[241];
      sdvals[(sdvals.size(2) * 80 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[242];
      sfvals[sfvals.size(1) * q + 81] = c_N[81];
      sdvals[sdvals.size(2) * 81 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[243];
      sdvals[(sdvals.size(2) * 81 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[244];
      sdvals[(sdvals.size(2) * 81 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[245];
      sfvals[sfvals.size(1) * q + 82] = c_N[82];
      sdvals[sdvals.size(2) * 82 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[246];
      sdvals[(sdvals.size(2) * 82 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[247];
      sdvals[(sdvals.size(2) * 82 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[248];
      sfvals[sfvals.size(1) * q + 83] = c_N[83];
      sdvals[sdvals.size(2) * 83 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[249];
      sdvals[(sdvals.size(2) * 83 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[250];
      sdvals[(sdvals.size(2) * 83 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[251];
      sfvals[sfvals.size(1) * q + 84] = c_N[84];
      sdvals[sdvals.size(2) * 84 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[252];
      sdvals[(sdvals.size(2) * 84 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[253];
      sdvals[(sdvals.size(2) * 84 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[254];
      sfvals[sfvals.size(1) * q + 85] = c_N[85];
      sdvals[sdvals.size(2) * 85 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[255];
      sdvals[(sdvals.size(2) * 85 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[256];
      sdvals[(sdvals.size(2) * 85 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[257];
      sfvals[sfvals.size(1) * q + 86] = c_N[86];
      sdvals[sdvals.size(2) * 86 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[258];
      sdvals[(sdvals.size(2) * 86 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[259];
      sdvals[(sdvals.size(2) * 86 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[260];
      sfvals[sfvals.size(1) * q + 87] = c_N[87];
      sdvals[sdvals.size(2) * 87 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[261];
      sdvals[(sdvals.size(2) * 87 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[262];
      sdvals[(sdvals.size(2) * 87 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[263];
      sfvals[sfvals.size(1) * q + 88] = c_N[88];
      sdvals[sdvals.size(2) * 88 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[264];
      sdvals[(sdvals.size(2) * 88 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[265];
      sdvals[(sdvals.size(2) * 88 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[266];
      sfvals[sfvals.size(1) * q + 89] = c_N[89];
      sdvals[sdvals.size(2) * 89 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[267];
      sdvals[(sdvals.size(2) * 89 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[268];
      sdvals[(sdvals.size(2) * 89 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[269];
      sfvals[sfvals.size(1) * q + 90] = c_N[90];
      sdvals[sdvals.size(2) * 90 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[270];
      sdvals[(sdvals.size(2) * 90 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[271];
      sdvals[(sdvals.size(2) * 90 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[272];
      sfvals[sfvals.size(1) * q + 91] = c_N[91];
      sdvals[sdvals.size(2) * 91 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[273];
      sdvals[(sdvals.size(2) * 91 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[274];
      sdvals[(sdvals.size(2) * 91 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[275];
      sfvals[sfvals.size(1) * q + 92] = c_N[92];
      sdvals[sdvals.size(2) * 92 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[276];
      sdvals[(sdvals.size(2) * 92 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[277];
      sdvals[(sdvals.size(2) * 92 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[278];
      sfvals[sfvals.size(1) * q + 93] = c_N[93];
      sdvals[sdvals.size(2) * 93 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[279];
      sdvals[(sdvals.size(2) * 93 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[280];
      sdvals[(sdvals.size(2) * 93 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[281];
      sfvals[sfvals.size(1) * q + 94] = c_N[94];
      sdvals[sdvals.size(2) * 94 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[282];
      sdvals[(sdvals.size(2) * 94 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[283];
      sdvals[(sdvals.size(2) * 94 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[284];
      sfvals[sfvals.size(1) * q + 95] = c_N[95];
      sdvals[sdvals.size(2) * 95 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[285];
      sdvals[(sdvals.size(2) * 95 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[286];
      sdvals[(sdvals.size(2) * 95 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[287];
      sfvals[sfvals.size(1) * q + 96] = c_N[96];
      sdvals[sdvals.size(2) * 96 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[288];
      sdvals[(sdvals.size(2) * 96 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[289];
      sdvals[(sdvals.size(2) * 96 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[290];
      sfvals[sfvals.size(1) * q + 97] = c_N[97];
      sdvals[sdvals.size(2) * 97 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[291];
      sdvals[(sdvals.size(2) * 97 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[292];
      sdvals[(sdvals.size(2) * 97 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[293];
      sfvals[sfvals.size(1) * q + 98] = c_N[98];
      sdvals[sdvals.size(2) * 98 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[294];
      sdvals[(sdvals.size(2) * 98 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[295];
      sdvals[(sdvals.size(2) * 98 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[296];
      sfvals[sfvals.size(1) * q + 99] = c_N[99];
      sdvals[sdvals.size(2) * 99 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[297];
      sdvals[(sdvals.size(2) * 99 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[298];
      sdvals[(sdvals.size(2) * 99 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[299];
      sfvals[sfvals.size(1) * q + 100] = c_N[100];
      sdvals[sdvals.size(2) * 100 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[300];
      sdvals[(sdvals.size(2) * 100 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[301];
      sdvals[(sdvals.size(2) * 100 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[302];
      sfvals[sfvals.size(1) * q + 101] = c_N[101];
      sdvals[sdvals.size(2) * 101 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[303];
      sdvals[(sdvals.size(2) * 101 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[304];
      sdvals[(sdvals.size(2) * 101 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[305];
      sfvals[sfvals.size(1) * q + 102] = c_N[102];
      sdvals[sdvals.size(2) * 102 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[306];
      sdvals[(sdvals.size(2) * 102 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[307];
      sdvals[(sdvals.size(2) * 102 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[308];
      sfvals[sfvals.size(1) * q + 103] = c_N[103];
      sdvals[sdvals.size(2) * 103 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[309];
      sdvals[(sdvals.size(2) * 103 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[310];
      sdvals[(sdvals.size(2) * 103 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[311];
      sfvals[sfvals.size(1) * q + 104] = c_N[104];
      sdvals[sdvals.size(2) * 104 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[312];
      sdvals[(sdvals.size(2) * 104 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[313];
      sdvals[(sdvals.size(2) * 104 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[314];
      sfvals[sfvals.size(1) * q + 105] = c_N[105];
      sdvals[sdvals.size(2) * 105 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[315];
      sdvals[(sdvals.size(2) * 105 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[316];
      sdvals[(sdvals.size(2) * 105 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[317];
      sfvals[sfvals.size(1) * q + 106] = c_N[106];
      sdvals[sdvals.size(2) * 106 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[318];
      sdvals[(sdvals.size(2) * 106 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[319];
      sdvals[(sdvals.size(2) * 106 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[320];
      sfvals[sfvals.size(1) * q + 107] = c_N[107];
      sdvals[sdvals.size(2) * 107 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[321];
      sdvals[(sdvals.size(2) * 107 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[322];
      sdvals[(sdvals.size(2) * 107 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[323];
      sfvals[sfvals.size(1) * q + 108] = c_N[108];
      sdvals[sdvals.size(2) * 108 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[324];
      sdvals[(sdvals.size(2) * 108 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[325];
      sdvals[(sdvals.size(2) * 108 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[326];
      sfvals[sfvals.size(1) * q + 109] = c_N[109];
      sdvals[sdvals.size(2) * 109 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[327];
      sdvals[(sdvals.size(2) * 109 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[328];
      sdvals[(sdvals.size(2) * 109 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[329];
      sfvals[sfvals.size(1) * q + 110] = c_N[110];
      sdvals[sdvals.size(2) * 110 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[330];
      sdvals[(sdvals.size(2) * 110 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[331];
      sdvals[(sdvals.size(2) * 110 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[332];
      sfvals[sfvals.size(1) * q + 111] = c_N[111];
      sdvals[sdvals.size(2) * 111 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[333];
      sdvals[(sdvals.size(2) * 111 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[334];
      sdvals[(sdvals.size(2) * 111 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[335];
      sfvals[sfvals.size(1) * q + 112] = c_N[112];
      sdvals[sdvals.size(2) * 112 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[336];
      sdvals[(sdvals.size(2) * 112 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[337];
      sdvals[(sdvals.size(2) * 112 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[338];
      sfvals[sfvals.size(1) * q + 113] = c_N[113];
      sdvals[sdvals.size(2) * 113 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[339];
      sdvals[(sdvals.size(2) * 113 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[340];
      sdvals[(sdvals.size(2) * 113 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[341];
      sfvals[sfvals.size(1) * q + 114] = c_N[114];
      sdvals[sdvals.size(2) * 114 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[342];
      sdvals[(sdvals.size(2) * 114 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[343];
      sdvals[(sdvals.size(2) * 114 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[344];
      sfvals[sfvals.size(1) * q + 115] = c_N[115];
      sdvals[sdvals.size(2) * 115 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[345];
      sdvals[(sdvals.size(2) * 115 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[346];
      sdvals[(sdvals.size(2) * 115 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[347];
      sfvals[sfvals.size(1) * q + 116] = c_N[116];
      sdvals[sdvals.size(2) * 116 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[348];
      sdvals[(sdvals.size(2) * 116 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[349];
      sdvals[(sdvals.size(2) * 116 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[350];
      sfvals[sfvals.size(1) * q + 117] = c_N[117];
      sdvals[sdvals.size(2) * 117 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[351];
      sdvals[(sdvals.size(2) * 117 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[352];
      sdvals[(sdvals.size(2) * 117 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[353];
      sfvals[sfvals.size(1) * q + 118] = c_N[118];
      sdvals[sdvals.size(2) * 118 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[354];
      sdvals[(sdvals.size(2) * 118 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[355];
      sdvals[(sdvals.size(2) * 118 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[356];
      sfvals[sfvals.size(1) * q + 119] = c_N[119];
      sdvals[sdvals.size(2) * 119 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[357];
      sdvals[(sdvals.size(2) * 119 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[358];
      sdvals[(sdvals.size(2) * 119 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[359];
      sfvals[sfvals.size(1) * q + 120] = c_N[120];
      sdvals[sdvals.size(2) * 120 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[360];
      sdvals[(sdvals.size(2) * 120 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[361];
      sdvals[(sdvals.size(2) * 120 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[362];
      sfvals[sfvals.size(1) * q + 121] = c_N[121];
      sdvals[sdvals.size(2) * 121 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[363];
      sdvals[(sdvals.size(2) * 121 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[364];
      sdvals[(sdvals.size(2) * 121 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[365];
      sfvals[sfvals.size(1) * q + 122] = c_N[122];
      sdvals[sdvals.size(2) * 122 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[366];
      sdvals[(sdvals.size(2) * 122 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[367];
      sdvals[(sdvals.size(2) * 122 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[368];
      sfvals[sfvals.size(1) * q + 123] = c_N[123];
      sdvals[sdvals.size(2) * 123 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[369];
      sdvals[(sdvals.size(2) * 123 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[370];
      sdvals[(sdvals.size(2) * 123 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[371];
      sfvals[sfvals.size(1) * q + 124] = c_N[124];
      sdvals[sdvals.size(2) * 124 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[372];
      sdvals[(sdvals.size(2) * 124 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[373];
      sdvals[(sdvals.size(2) * 124 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[374];
      sfvals[sfvals.size(1) * q + 125] = c_N[125];
      sdvals[sdvals.size(2) * 125 + sdvals.size(2) * sdvals.size(1) * q] =
          c_deriv[375];
      sdvals[(sdvals.size(2) * 125 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          c_deriv[376];
      sdvals[(sdvals.size(2) * 125 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          c_deriv[377];
    }
  } break;
  }
}

static void sfe3_tabulate_gl_pyra(coder::SizeType etype,
                                  const ::coder::array<double, 2U> &cs,
                                  ::coder::array<double, 2U> &sfvals,
                                  ::coder::array<double, 3U> &sdvals)
{
  coder::SizeType i;
  coder::SizeType nqp;
  //  pyra
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  if (etype == 173) {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double deriv[90];
      double N[30];
      ::sfe_sfuncs::pyra_gl_30_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                     cs[cs.size(1) * q + 2], &N[0], &deriv[0]);
      sfvals[sfvals.size(1) * q] = N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = deriv[2];
      sfvals[sfvals.size(1) * q + 1] = N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[5];
      sfvals[sfvals.size(1) * q + 2] = N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[8];
      sfvals[sfvals.size(1) * q + 3] = N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[11];
      sfvals[sfvals.size(1) * q + 4] = N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[14];
      sfvals[sfvals.size(1) * q + 5] = N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[17];
      sfvals[sfvals.size(1) * q + 6] = N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[20];
      sfvals[sfvals.size(1) * q + 7] = N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[23];
      sfvals[sfvals.size(1) * q + 8] = N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[26];
      sfvals[sfvals.size(1) * q + 9] = N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[29];
      sfvals[sfvals.size(1) * q + 10] = N[10];
      sdvals[sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[30];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[31];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[32];
      sfvals[sfvals.size(1) * q + 11] = N[11];
      sdvals[sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[33];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[34];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[35];
      sfvals[sfvals.size(1) * q + 12] = N[12];
      sdvals[sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[36];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[37];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[38];
      sfvals[sfvals.size(1) * q + 13] = N[13];
      sdvals[sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[39];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[40];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[41];
      sfvals[sfvals.size(1) * q + 14] = N[14];
      sdvals[sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[42];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[43];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[44];
      sfvals[sfvals.size(1) * q + 15] = N[15];
      sdvals[sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[45];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[46];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[47];
      sfvals[sfvals.size(1) * q + 16] = N[16];
      sdvals[sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[48];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[49];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[50];
      sfvals[sfvals.size(1) * q + 17] = N[17];
      sdvals[sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[51];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[52];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[53];
      sfvals[sfvals.size(1) * q + 18] = N[18];
      sdvals[sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[54];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[55];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[56];
      sfvals[sfvals.size(1) * q + 19] = N[19];
      sdvals[sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[57];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[58];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[59];
      sfvals[sfvals.size(1) * q + 20] = N[20];
      sdvals[sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[60];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[61];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[62];
      sfvals[sfvals.size(1) * q + 21] = N[21];
      sdvals[sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[63];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[64];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[65];
      sfvals[sfvals.size(1) * q + 22] = N[22];
      sdvals[sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[66];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[67];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[68];
      sfvals[sfvals.size(1) * q + 23] = N[23];
      sdvals[sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[69];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[70];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[71];
      sfvals[sfvals.size(1) * q + 24] = N[24];
      sdvals[sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[72];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[73];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[74];
      sfvals[sfvals.size(1) * q + 25] = N[25];
      sdvals[sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[75];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[76];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[77];
      sfvals[sfvals.size(1) * q + 26] = N[26];
      sdvals[sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[78];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[79];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[80];
      sfvals[sfvals.size(1) * q + 27] = N[27];
      sdvals[sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[81];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[82];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[83];
      sfvals[sfvals.size(1) * q + 28] = N[28];
      sdvals[sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[84];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[85];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[86];
      sfvals[sfvals.size(1) * q + 29] = N[29];
      sdvals[sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q] =
          deriv[87];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          deriv[88];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          deriv[89];
    }
  } else {
    m2cAssert(etype == 177, "Pyramid only support up to quartic");
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double b_deriv[165];
      double b_N[55];
      ::sfe_sfuncs::pyra_gl_55_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                     cs[cs.size(1) * q + 2], &b_N[0],
                                     &b_deriv[0]);
      sfvals[sfvals.size(1) * q] = b_N[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q] = b_deriv[0];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 1] = b_deriv[1];
      sdvals[sdvals.size(2) * sdvals.size(1) * q + 2] = b_deriv[2];
      sfvals[sfvals.size(1) * q + 1] = b_N[1];
      sdvals[sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q] = b_deriv[3];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[4];
      sdvals[(sdvals.size(2) + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[5];
      sfvals[sfvals.size(1) * q + 2] = b_N[2];
      sdvals[sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[6];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[7];
      sdvals[(sdvals.size(2) * 2 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[8];
      sfvals[sfvals.size(1) * q + 3] = b_N[3];
      sdvals[sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[9];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[10];
      sdvals[(sdvals.size(2) * 3 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[11];
      sfvals[sfvals.size(1) * q + 4] = b_N[4];
      sdvals[sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[12];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[13];
      sdvals[(sdvals.size(2) * 4 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[14];
      sfvals[sfvals.size(1) * q + 5] = b_N[5];
      sdvals[sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[15];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[16];
      sdvals[(sdvals.size(2) * 5 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[17];
      sfvals[sfvals.size(1) * q + 6] = b_N[6];
      sdvals[sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[18];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[19];
      sdvals[(sdvals.size(2) * 6 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[20];
      sfvals[sfvals.size(1) * q + 7] = b_N[7];
      sdvals[sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[21];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[22];
      sdvals[(sdvals.size(2) * 7 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[23];
      sfvals[sfvals.size(1) * q + 8] = b_N[8];
      sdvals[sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[24];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[25];
      sdvals[(sdvals.size(2) * 8 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[26];
      sfvals[sfvals.size(1) * q + 9] = b_N[9];
      sdvals[sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[27];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[28];
      sdvals[(sdvals.size(2) * 9 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[29];
      sfvals[sfvals.size(1) * q + 10] = b_N[10];
      sdvals[sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[30];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[31];
      sdvals[(sdvals.size(2) * 10 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[32];
      sfvals[sfvals.size(1) * q + 11] = b_N[11];
      sdvals[sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[33];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[34];
      sdvals[(sdvals.size(2) * 11 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[35];
      sfvals[sfvals.size(1) * q + 12] = b_N[12];
      sdvals[sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[36];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[37];
      sdvals[(sdvals.size(2) * 12 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[38];
      sfvals[sfvals.size(1) * q + 13] = b_N[13];
      sdvals[sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[39];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[40];
      sdvals[(sdvals.size(2) * 13 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[41];
      sfvals[sfvals.size(1) * q + 14] = b_N[14];
      sdvals[sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[42];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[43];
      sdvals[(sdvals.size(2) * 14 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[44];
      sfvals[sfvals.size(1) * q + 15] = b_N[15];
      sdvals[sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[45];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[46];
      sdvals[(sdvals.size(2) * 15 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[47];
      sfvals[sfvals.size(1) * q + 16] = b_N[16];
      sdvals[sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[48];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[49];
      sdvals[(sdvals.size(2) * 16 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[50];
      sfvals[sfvals.size(1) * q + 17] = b_N[17];
      sdvals[sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[51];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[52];
      sdvals[(sdvals.size(2) * 17 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[53];
      sfvals[sfvals.size(1) * q + 18] = b_N[18];
      sdvals[sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[54];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[55];
      sdvals[(sdvals.size(2) * 18 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[56];
      sfvals[sfvals.size(1) * q + 19] = b_N[19];
      sdvals[sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[57];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[58];
      sdvals[(sdvals.size(2) * 19 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[59];
      sfvals[sfvals.size(1) * q + 20] = b_N[20];
      sdvals[sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[60];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[61];
      sdvals[(sdvals.size(2) * 20 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[62];
      sfvals[sfvals.size(1) * q + 21] = b_N[21];
      sdvals[sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[63];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[64];
      sdvals[(sdvals.size(2) * 21 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[65];
      sfvals[sfvals.size(1) * q + 22] = b_N[22];
      sdvals[sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[66];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[67];
      sdvals[(sdvals.size(2) * 22 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[68];
      sfvals[sfvals.size(1) * q + 23] = b_N[23];
      sdvals[sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[69];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[70];
      sdvals[(sdvals.size(2) * 23 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[71];
      sfvals[sfvals.size(1) * q + 24] = b_N[24];
      sdvals[sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[72];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[73];
      sdvals[(sdvals.size(2) * 24 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[74];
      sfvals[sfvals.size(1) * q + 25] = b_N[25];
      sdvals[sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[75];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[76];
      sdvals[(sdvals.size(2) * 25 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[77];
      sfvals[sfvals.size(1) * q + 26] = b_N[26];
      sdvals[sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[78];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[79];
      sdvals[(sdvals.size(2) * 26 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[80];
      sfvals[sfvals.size(1) * q + 27] = b_N[27];
      sdvals[sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[81];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[82];
      sdvals[(sdvals.size(2) * 27 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[83];
      sfvals[sfvals.size(1) * q + 28] = b_N[28];
      sdvals[sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[84];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[85];
      sdvals[(sdvals.size(2) * 28 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[86];
      sfvals[sfvals.size(1) * q + 29] = b_N[29];
      sdvals[sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[87];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[88];
      sdvals[(sdvals.size(2) * 29 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[89];
      sfvals[sfvals.size(1) * q + 30] = b_N[30];
      sdvals[sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[90];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[91];
      sdvals[(sdvals.size(2) * 30 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[92];
      sfvals[sfvals.size(1) * q + 31] = b_N[31];
      sdvals[sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[93];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[94];
      sdvals[(sdvals.size(2) * 31 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[95];
      sfvals[sfvals.size(1) * q + 32] = b_N[32];
      sdvals[sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[96];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[97];
      sdvals[(sdvals.size(2) * 32 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[98];
      sfvals[sfvals.size(1) * q + 33] = b_N[33];
      sdvals[sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[99];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[100];
      sdvals[(sdvals.size(2) * 33 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[101];
      sfvals[sfvals.size(1) * q + 34] = b_N[34];
      sdvals[sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[102];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[103];
      sdvals[(sdvals.size(2) * 34 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[104];
      sfvals[sfvals.size(1) * q + 35] = b_N[35];
      sdvals[sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[105];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[106];
      sdvals[(sdvals.size(2) * 35 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[107];
      sfvals[sfvals.size(1) * q + 36] = b_N[36];
      sdvals[sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[108];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[109];
      sdvals[(sdvals.size(2) * 36 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[110];
      sfvals[sfvals.size(1) * q + 37] = b_N[37];
      sdvals[sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[111];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[112];
      sdvals[(sdvals.size(2) * 37 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[113];
      sfvals[sfvals.size(1) * q + 38] = b_N[38];
      sdvals[sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[114];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[115];
      sdvals[(sdvals.size(2) * 38 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[116];
      sfvals[sfvals.size(1) * q + 39] = b_N[39];
      sdvals[sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[117];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[118];
      sdvals[(sdvals.size(2) * 39 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[119];
      sfvals[sfvals.size(1) * q + 40] = b_N[40];
      sdvals[sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[120];
      sdvals[(sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[121];
      sdvals[(sdvals.size(2) * 40 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[122];
      sfvals[sfvals.size(1) * q + 41] = b_N[41];
      sdvals[sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[123];
      sdvals[(sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[124];
      sdvals[(sdvals.size(2) * 41 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[125];
      sfvals[sfvals.size(1) * q + 42] = b_N[42];
      sdvals[sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[126];
      sdvals[(sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[127];
      sdvals[(sdvals.size(2) * 42 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[128];
      sfvals[sfvals.size(1) * q + 43] = b_N[43];
      sdvals[sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[129];
      sdvals[(sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[130];
      sdvals[(sdvals.size(2) * 43 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[131];
      sfvals[sfvals.size(1) * q + 44] = b_N[44];
      sdvals[sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[132];
      sdvals[(sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[133];
      sdvals[(sdvals.size(2) * 44 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[134];
      sfvals[sfvals.size(1) * q + 45] = b_N[45];
      sdvals[sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[135];
      sdvals[(sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[136];
      sdvals[(sdvals.size(2) * 45 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[137];
      sfvals[sfvals.size(1) * q + 46] = b_N[46];
      sdvals[sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[138];
      sdvals[(sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[139];
      sdvals[(sdvals.size(2) * 46 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[140];
      sfvals[sfvals.size(1) * q + 47] = b_N[47];
      sdvals[sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[141];
      sdvals[(sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[142];
      sdvals[(sdvals.size(2) * 47 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[143];
      sfvals[sfvals.size(1) * q + 48] = b_N[48];
      sdvals[sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[144];
      sdvals[(sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[145];
      sdvals[(sdvals.size(2) * 48 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[146];
      sfvals[sfvals.size(1) * q + 49] = b_N[49];
      sdvals[sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[147];
      sdvals[(sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[148];
      sdvals[(sdvals.size(2) * 49 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[149];
      sfvals[sfvals.size(1) * q + 50] = b_N[50];
      sdvals[sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[150];
      sdvals[(sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[151];
      sdvals[(sdvals.size(2) * 50 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[152];
      sfvals[sfvals.size(1) * q + 51] = b_N[51];
      sdvals[sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[153];
      sdvals[(sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[154];
      sdvals[(sdvals.size(2) * 51 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[155];
      sfvals[sfvals.size(1) * q + 52] = b_N[52];
      sdvals[sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[156];
      sdvals[(sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[157];
      sdvals[(sdvals.size(2) * 52 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[158];
      sfvals[sfvals.size(1) * q + 53] = b_N[53];
      sdvals[sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[159];
      sdvals[(sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[160];
      sdvals[(sdvals.size(2) * 53 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[161];
      sfvals[sfvals.size(1) * q + 54] = b_N[54];
      sdvals[sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q] =
          b_deriv[162];
      sdvals[(sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q) + 1] =
          b_deriv[163];
      sdvals[(sdvals.size(2) * 54 + sdvals.size(2) * sdvals.size(1) * q) + 2] =
          b_deriv[164];
    }
  }
}

// sfe3_tabulate_shapefuncs - Tabulate shape functions and sdvals at qpoints
static void sfe3_tabulate_shapefuncs(coder::SizeType etype,
                                     const ::coder::array<double, 2U> &cs,
                                     ::coder::array<double, 2U> &sfvals,
                                     ::coder::array<double, 3U> &sdvals)
{
  coder::SizeType postype;
  postype = etype & 3;
  if (postype == 0) {
    coder::SizeType i;
    i = etype >> 5 & 7;
    if (i == 4) {
      sfe3_tabulate_equi_tet(etype, cs, sfvals, sdvals);
    } else if (i == 5) {
      sfe3_tabulate_equi_pyra(etype, cs, sfvals, sdvals);
    } else if (i == 6) {
      sfe3_tabulate_equi_prism(etype, cs, sfvals, sdvals);
    } else {
      coder::SizeType nqp;
      //  hex
      nqp = cs.size(0) - 1;
      i = iv[etype - 1];
      sfvals.set_size(cs.size(0), i);
      sdvals.set_size(cs.size(0), i, cs.size(1));
      switch (etype) {
      case 228: {
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double deriv[24];
          double N[8];
          ::sfe_sfuncs::hexa_8_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                     cs[cs.size(1) * q + 2], &N[0], &deriv[0]);
          for (coder::SizeType b_i{0}; b_i < 8; b_i++) {
            sfvals[b_i + sfvals.size(1) * q] = N[b_i];
            sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
                deriv[3 * b_i];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   1] = deriv[3 * b_i + 1];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   2] = deriv[3 * b_i + 2];
          }
        }
      } break;
      case 232: {
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double b_deriv[81];
          double b_N[27];
          ::sfe_sfuncs::hexa_27_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
              cs[cs.size(1) * q + 2], &b_N[0], &b_deriv[0]);
          for (coder::SizeType b_i{0}; b_i < 27; b_i++) {
            sfvals[b_i + sfvals.size(1) * q] = b_N[b_i];
            sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
                b_deriv[3 * b_i];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   1] = b_deriv[3 * b_i + 1];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   2] = b_deriv[3 * b_i + 2];
          }
        }
      } break;
      case 236: {
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double c_deriv[192];
          double c_N[64];
          ::sfe_sfuncs::hexa_64_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
              cs[cs.size(1) * q + 2], &c_N[0], &c_deriv[0]);
          for (coder::SizeType b_i{0}; b_i < 64; b_i++) {
            sfvals[b_i + sfvals.size(1) * q] = c_N[b_i];
            sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
                c_deriv[3 * b_i];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   1] = c_deriv[3 * b_i + 1];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   2] = c_deriv[3 * b_i + 2];
          }
        }
      } break;
      case 240: {
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double d_deriv[375];
          double d_N[125];
          ::sfe_sfuncs::hexa_125_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
              cs[cs.size(1) * q + 2], &d_N[0], &d_deriv[0]);
          for (coder::SizeType b_i{0}; b_i < 125; b_i++) {
            sfvals[b_i + sfvals.size(1) * q] = d_N[b_i];
            sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
                d_deriv[3 * b_i];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   1] = d_deriv[3 * b_i + 1];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   2] = d_deriv[3 * b_i + 2];
          }
        }
      } break;
      default: {
        m2cAssert(etype == 244, "Hex elements supports up to quinitic.");
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double e_deriv[648];
          double e_N[216];
          ::sfe_sfuncs::hexa_216_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
              cs[cs.size(1) * q + 2], &e_N[0], &e_deriv[0]);
          for (coder::SizeType b_i{0}; b_i < 216; b_i++) {
            sfvals[b_i + sfvals.size(1) * q] = e_N[b_i];
            sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
                e_deriv[3 * b_i];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   1] = e_deriv[3 * b_i + 1];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   2] = e_deriv[3 * b_i + 2];
          }
        }
      } break;
      }
    }
  } else {
    coder::SizeType i;
    m2cAssert(postype == 1,
              "Only supports Equidistant and Gauss-Lobatto points in 3D");
    i = etype >> 5 & 7;
    if (i == 4) {
      coder::SizeType nqp;
      //  tet
      nqp = cs.size(0) - 1;
      i = iv[etype - 1];
      sfvals.set_size(cs.size(0), i);
      sdvals.set_size(cs.size(0), i, cs.size(1));
      if (etype == 141) {
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double f_deriv[60];
          double f_N[20];
          ::sfe_sfuncs::tet_gl_20_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
              cs[cs.size(1) * q + 2], &f_N[0], &f_deriv[0]);
          for (coder::SizeType b_i{0}; b_i < 20; b_i++) {
            sfvals[b_i + sfvals.size(1) * q] = f_N[b_i];
            sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
                f_deriv[3 * b_i];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   1] = f_deriv[3 * b_i + 1];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   2] = f_deriv[3 * b_i + 2];
          }
        }
      } else {
        m2cAssert(etype == 145, "Gauss-Lobatto tetrahedral elements are "
                                "supported only up to quartic");
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double g_deriv[105];
          double g_N[35];
          ::sfe_sfuncs::tet_gl_35_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
              cs[cs.size(1) * q + 2], &g_N[0], &g_deriv[0]);
          for (coder::SizeType b_i{0}; b_i < 35; b_i++) {
            sfvals[b_i + sfvals.size(1) * q] = g_N[b_i];
            sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
                g_deriv[3 * b_i];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   1] = g_deriv[3 * b_i + 1];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   2] = g_deriv[3 * b_i + 2];
          }
        }
      }
    } else if (i == 5) {
      sfe3_tabulate_gl_pyra(etype, cs, sfvals, sdvals);
    } else if (i == 6) {
      sfe3_tabulate_gl_prism(etype, cs, sfvals, sdvals);
    } else {
      coder::SizeType nqp;
      //  hex
      nqp = cs.size(0) - 1;
      i = iv[etype - 1];
      sfvals.set_size(cs.size(0), i);
      sdvals.set_size(cs.size(0), i, cs.size(1));
      switch (etype) {
      case 237: {
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double c_deriv[192];
          double c_N[64];
          ::sfe_sfuncs::hexa_gl_64_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
              cs[cs.size(1) * q + 2], &c_N[0], &c_deriv[0]);
          for (coder::SizeType b_i{0}; b_i < 64; b_i++) {
            sfvals[b_i + sfvals.size(1) * q] = c_N[b_i];
            sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
                c_deriv[3 * b_i];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   1] = c_deriv[3 * b_i + 1];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   2] = c_deriv[3 * b_i + 2];
          }
        }
      } break;
      case 241: {
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double d_deriv[375];
          double d_N[125];
          ::sfe_sfuncs::hexa_gl_125_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
              cs[cs.size(1) * q + 2], &d_N[0], &d_deriv[0]);
          for (coder::SizeType b_i{0}; b_i < 125; b_i++) {
            sfvals[b_i + sfvals.size(1) * q] = d_N[b_i];
            sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
                d_deriv[3 * b_i];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   1] = d_deriv[3 * b_i + 1];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   2] = d_deriv[3 * b_i + 2];
          }
        }
      } break;
      default: {
        m2cAssert(etype == 245, "Gauss-Lobatoo only supports up to quintic.");
        for (coder::SizeType q{0}; q <= nqp; q++) {
          double e_deriv[648];
          double e_N[216];
          ::sfe_sfuncs::hexa_gl_216_sfunc(
              cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
              cs[cs.size(1) * q + 2], &e_N[0], &e_deriv[0]);
          for (coder::SizeType b_i{0}; b_i < 216; b_i++) {
            sfvals[b_i + sfvals.size(1) * q] = e_N[b_i];
            sdvals[sdvals.size(2) * b_i + sdvals.size(2) * sdvals.size(1) * q] =
                e_deriv[3 * b_i];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   1] = e_deriv[3 * b_i + 1];
            sdvals[(sdvals.size(2) * b_i +
                    sdvals.size(2) * sdvals.size(1) * q) +
                   2] = e_deriv[3 * b_i + 2];
          }
        }
      } break;
      }
    }
  }
}

// sfe_init - Initialize/reinitialize an sfe object for non-boundary element
static void sfe_init(SfeObject *b_sfe, const int etypes_data[],
                     coder::SizeType etypes_size,
                     const ::coder::array<double, 2U> &xs,
                     coder::SizeType qd_or_natcoords,
                     const ::coder::array<double, 2U> &userquad)
{
  double dv[9];
  double v;
  coder::SizeType a;
  coder::SizeType geom_etype;
  coder::SizeType i;
  coder::SizeType sfe_idx_0_tmp_tmp;
  coder::SizeType topo_dim;
  boolean_T flag;
  if ((etypes_size < 2) || (etypes_data[1] == 0)) {
    geom_etype = etypes_data[0];
  } else {
    geom_etype = etypes_data[1];
  }
  flag = etypes_data[0] == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (etypes_data[0] >> 5 & 7) == (geom_etype >> 5 & 7);
  }
  m2cAssert(flag, "invalid element combinations");
  if (etypes_data[0] != -1) {
    coder::SizeType shape;
    shape = etypes_data[0] >> 5 & 7;
    topo_dim = ((shape > 0) + (shape > 1)) + (shape > 3);
    //  Geometric dimension
    if (xs.size(1) < topo_dim) {
      m2cErrMsgIdAndTxt("sfe_init:badDim",
                        "geometric dim cannot be smaller than topo dim");
    }
    b_sfe->geom_dim = xs.size(1);
    //  assign geom dimension
    b_sfe->topo_dim = topo_dim;
    //  assign topo dimension
    m2cAssert(iv[geom_etype - 1] == xs.size(0), "nnodes do not match");
    b_sfe->etypes[0] = etypes_data[0];
    b_sfe->etypes[1] = geom_etype;
    //  Get number of nodes per element
    b_sfe->nnodes[0] = iv[etypes_data[0] - 1];
    b_sfe->nnodes[1] = iv[geom_etype - 1];
    //  Set up quadrature
    if (qd_or_natcoords != -1) {
      if (qd_or_natcoords == 0) {
        //  trial+test+nonlinear_geom?1:0
        a = obtain_elemdegree(etypes_data[0]);
        qd_or_natcoords = ((a << 1) + (obtain_elemdegree(geom_etype) > 1)) +
                          (xs.size(1) > topo_dim);
      }
      tabulate_quadratures(etypes_data[0], qd_or_natcoords, b_sfe->cs,
                           b_sfe->ws);
      b_sfe->nqp = b_sfe->ws.size(0);
    } else {
      if ((userquad.size(0) == 0) || (userquad.size(1) == 0)) {
        m2cErrMsgIdAndTxt("sfe_init:missUserQuad",
                          "missing user quadrature data");
      }
      if (userquad.size(1) != topo_dim + 1) {
        m2cErrMsgIdAndTxt("sfe_init:badUserQuadDim",
                          "bad user quadrature data size");
      }
      b_sfe->nqp = userquad.size(0);
      b_sfe->ws.set_size(b_sfe->nqp);
      b_sfe->cs.set_size(b_sfe->nqp, topo_dim);
      i = b_sfe->nqp;
      for (coder::SizeType q{0}; q < i; q++) {
        b_sfe->ws[q] = userquad[userquad.size(1) * q];
        for (coder::SizeType k{0}; k < topo_dim; k++) {
          b_sfe->cs[k + b_sfe->cs.size(1) * q] =
              userquad[(k + userquad.size(1) * q) + 1];
        }
      }
    }
    //  Solution space shape functions & derivs
    tabulate_shapefuncs(etypes_data[0], b_sfe->cs, b_sfe->shapes_geom,
                        b_sfe->derivs_geom);
    a = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
    b_sfe->shapes_sol.set_size(b_sfe->shapes_geom.size(0),
                               b_sfe->shapes_geom.size(1));
    for (i = 0; i < a; i++) {
      b_sfe->shapes_sol[i] = b_sfe->shapes_geom[i];
    }
    a = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
        b_sfe->derivs_geom.size(0);
    b_sfe->derivs_sol.set_size(b_sfe->derivs_geom.size(0),
                               b_sfe->derivs_geom.size(1),
                               b_sfe->derivs_geom.size(2));
    for (i = 0; i < a; i++) {
      b_sfe->derivs_sol[i] = b_sfe->derivs_geom[i];
    }
    //  Geometry space shape functions & derivs
    if (etypes_data[0] != geom_etype) {
      tabulate_shapefuncs(geom_etype, b_sfe->cs, b_sfe->shapes_geom,
                          b_sfe->derivs_geom);
    }
  } else {
    if ((b_sfe->etypes[0] > 0) && (iv[b_sfe->etypes[0] - 1] != 0)) {
      flag = true;
    } else {
      flag = false;
    }
    m2cAssert(flag, "");
  }
  //  potentially skip re-tabulating
  sfe_idx_0_tmp_tmp = b_sfe->nqp;
  b_sfe->cs_phy.set_size(sfe_idx_0_tmp_tmp, xs.size(1));
  for (coder::SizeType q{0}; q < sfe_idx_0_tmp_tmp; q++) {
    i = xs.size(1);
    for (coder::SizeType k{0}; k < i; k++) {
      coder::SizeType m;
      m = b_sfe->shapes_geom.size(1);
      v = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[k];
      for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
        v += b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1] *
             xs[k + xs.size(1) * (b_i - 1)];
      }
      b_sfe->cs_phy[k + b_sfe->cs_phy.size(1) * q] = v;
    }
  }
  //  Compute Jacobian
  b_sfe->wdetJ.set_size(b_sfe->nqp);
  if ((geom_etype == 68) || (geom_etype == 132) || (geom_etype == 36)) {
    double d;
    coder::SizeType geom_dim;
    coder::SizeType n;
    //  A single Jacobian matrix (transpose) is needed for simplex elements
    geom_dim = xs.size(1);
    topo_dim = b_sfe->derivs_geom.size(2);
    std::memset(&dv[0], 0, 9U * sizeof(double));
    n = xs.size(0);
    for (coder::SizeType k{0}; k < n; k++) {
      for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
        for (coder::SizeType j{0}; j < geom_dim; j++) {
          i = j + 3 * b_i;
          dv[i] += xs[j + xs.size(1) * k] *
                   b_sfe->derivs_geom[b_i + b_sfe->derivs_geom.size(2) * k];
        }
      }
    }
    if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
      if (xs.size(1) == 1) {
        d = dv[0];
      } else if (xs.size(1) == 2) {
        d = dv[0] * dv[4] - dv[1] * dv[3];
      } else {
        d = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
             dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
            dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
      }
    } else if (b_sfe->derivs_geom.size(2) == 1) {
      d = dv[0] * dv[0] + dv[1] * dv[1];
      if (xs.size(1) == 3) {
        d += dv[2] * dv[2];
      }
      d = std::sqrt(d);
    } else {
      //  must be 2x3
      dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
      dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
      dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
      d = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
    }
    b_sfe->jacTs.set_size(3, 3);
    for (i = 0; i < 9; i++) {
      b_sfe->jacTs[i] = dv[i];
    }
    for (coder::SizeType q{0}; q < sfe_idx_0_tmp_tmp; q++) {
      b_sfe->wdetJ[q] = d * b_sfe->ws[q];
    }
  } else {
    //  Super-parametric
    a = b_sfe->nqp * 3;
    b_sfe->jacTs.set_size(a, 3);
    for (coder::SizeType q{0}; q < sfe_idx_0_tmp_tmp; q++) {
      coder::SizeType geom_dim;
      coder::SizeType n;
      coder::SizeType y;
      y = q * 3;
      geom_dim = xs.size(1);
      topo_dim = b_sfe->derivs_geom.size(2);
      std::memset(&dv[0], 0, 9U * sizeof(double));
      n = xs.size(0);
      for (coder::SizeType k{0}; k < n; k++) {
        for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
          for (coder::SizeType j{0}; j < geom_dim; j++) {
            i = j + 3 * b_i;
            dv[i] += xs[j + xs.size(1) * k] *
                     b_sfe->derivs_geom[(b_i + b_sfe->derivs_geom.size(2) * k) +
                                        b_sfe->derivs_geom.size(2) *
                                            b_sfe->derivs_geom.size(1) * q];
          }
        }
      }
      if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
        if (xs.size(1) == 1) {
          v = dv[0];
        } else if (xs.size(1) == 2) {
          v = dv[0] * dv[4] - dv[1] * dv[3];
        } else {
          v = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
               dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
              dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
        }
      } else if (b_sfe->derivs_geom.size(2) == 1) {
        v = dv[0] * dv[0] + dv[1] * dv[1];
        if (xs.size(1) == 3) {
          v += dv[2] * dv[2];
        }
        v = std::sqrt(v);
      } else {
        //  must be 2x3
        dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
        dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
        dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
        v = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
      }
      for (i = 0; i < 3; i++) {
        a = i + y;
        b_sfe->jacTs[3 * a] = dv[3 * i];
        b_sfe->jacTs[3 * a + 1] = dv[3 * i + 1];
        b_sfe->jacTs[3 * a + 2] = dv[3 * i + 2];
      }
      b_sfe->wdetJ[q] = v;
      b_sfe->wdetJ[q] = b_sfe->wdetJ[q] * b_sfe->ws[q];
    }
  }
}

// sfe_init - Initialize/reinitialize an sfe object for non-boundary element
static void sfe_init(SfeObject *b_sfe, const int etypes_data[],
                     coder::SizeType etypes_size,
                     const ::coder::array<double, 2U> &xs,
                     const ::coder::array<double, 2U> &qd_or_natcoords)
{
  coder::SizeType geom_etype;
  coder::SizeType i;
  coder::SizeType sfe_idx_0;
  boolean_T flag;
  if ((etypes_size < 2) || (etypes_data[1] == 0)) {
    geom_etype = etypes_data[0];
  } else {
    geom_etype = etypes_data[1];
  }
  flag = etypes_data[0] == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (etypes_data[0] >> 5 & 7) == (geom_etype >> 5 & 7);
  }
  m2cAssert(flag, "invalid element combinations");
  if (etypes_data[0] != -1) {
    coder::SizeType shape;
    coder::SizeType topo_dim;
    shape = etypes_data[0] >> 5 & 7;
    topo_dim = ((shape > 0) + (shape > 1)) + (shape > 3);
    //  Geometric dimension
    if (xs.size(1) < topo_dim) {
      m2cErrMsgIdAndTxt("sfe_init:badDim",
                        "geometric dim cannot be smaller than topo dim");
    }
    b_sfe->geom_dim = xs.size(1);
    //  assign geom dimension
    b_sfe->topo_dim = topo_dim;
    //  assign topo dimension
    m2cAssert(iv[geom_etype - 1] == xs.size(0), "nnodes do not match");
    b_sfe->etypes[0] = etypes_data[0];
    b_sfe->etypes[1] = geom_etype;
    //  Get number of nodes per element
    b_sfe->nnodes[0] = iv[etypes_data[0] - 1];
    b_sfe->nnodes[1] = iv[geom_etype - 1];
    //  User-input natural coordinates
    b_sfe->nqp = qd_or_natcoords.size(0);
    sfe_idx_0 = b_sfe->nqp;
    b_sfe->ws.set_size(sfe_idx_0);
    for (i = 0; i < sfe_idx_0; i++) {
      b_sfe->ws[i] = 1.0;
    }
    //  user ones for dummy quad weights
    b_sfe->cs.set_size(b_sfe->nqp, topo_dim);
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      for (coder::SizeType k{0}; k < topo_dim; k++) {
        b_sfe->cs[k + b_sfe->cs.size(1) * q] =
            qd_or_natcoords[k + qd_or_natcoords.size(1) * q];
      }
    }
    //  Solution space shape functions & derivs
    tabulate_shapefuncs(etypes_data[0], b_sfe->cs, b_sfe->shapes_geom,
                        b_sfe->derivs_geom);
    sfe_idx_0 = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
    b_sfe->shapes_sol.set_size(b_sfe->shapes_geom.size(0),
                               b_sfe->shapes_geom.size(1));
    for (i = 0; i < sfe_idx_0; i++) {
      b_sfe->shapes_sol[i] = b_sfe->shapes_geom[i];
    }
    sfe_idx_0 = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
                b_sfe->derivs_geom.size(0);
    b_sfe->derivs_sol.set_size(b_sfe->derivs_geom.size(0),
                               b_sfe->derivs_geom.size(1),
                               b_sfe->derivs_geom.size(2));
    for (i = 0; i < sfe_idx_0; i++) {
      b_sfe->derivs_sol[i] = b_sfe->derivs_geom[i];
    }
    //  Geometry space shape functions & derivs
    if (etypes_data[0] != geom_etype) {
      tabulate_shapefuncs(geom_etype, b_sfe->cs, b_sfe->shapes_geom,
                          b_sfe->derivs_geom);
    }
  } else {
    if ((b_sfe->etypes[0] > 0) && (iv[b_sfe->etypes[0] - 1] != 0)) {
      flag = true;
    } else {
      flag = false;
    }
    m2cAssert(flag, "");
  }
  //  potentially skip re-tabulating
  sfe_idx_0 = b_sfe->nqp;
  b_sfe->cs_phy.set_size(sfe_idx_0, xs.size(1));
  for (coder::SizeType q{0}; q < sfe_idx_0; q++) {
    i = xs.size(1);
    for (coder::SizeType k{0}; k < i; k++) {
      double v;
      coder::SizeType m;
      m = b_sfe->shapes_geom.size(1);
      v = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[k];
      for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
        v += b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1] *
             xs[k + xs.size(1) * (b_i - 1)];
      }
      b_sfe->cs_phy[k + b_sfe->cs_phy.size(1) * q] = v;
    }
  }
  //  Compute Jacobian
}

// sfe_init - Initialize/reinitialize an sfe object for non-boundary element
static void sfe_init(SfeObject *b_sfe, const unsigned char etypes[2],
                     const ::coder::array<double, 2U> &xs)
{
  double dv[9];
  double v;
  coder::SizeType a;
  coder::SizeType i;
  coder::SizeType qd_or_natcoords;
  coder::SizeType sfe_idx_0_tmp_tmp;
  coder::SizeType topo_dim;
  unsigned char c;
  unsigned char geom_etype;
  boolean_T flag;
  if (etypes[1] == 0) {
    geom_etype = etypes[0];
  } else {
    geom_etype = etypes[1];
  }
  flag = etypes[0] == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (static_cast<coder::SizeType>(static_cast<unsigned int>(etypes[0]) >>
                                         5) ==
            static_cast<coder::SizeType>(
                static_cast<unsigned int>(geom_etype) >> 5));
  }
  m2cAssert(flag, "invalid element combinations");
  c = static_cast<unsigned char>((etypes[0]) >> 5);
  topo_dim = ((c > 0) + (c > 1)) + (c > 3);
  //  Geometric dimension
  if (xs.size(1) < topo_dim) {
    m2cErrMsgIdAndTxt("sfe_init:badDim",
                      "geometric dim cannot be smaller than topo dim");
  }
  b_sfe->geom_dim = xs.size(1);
  //  assign geom dimension
  b_sfe->topo_dim = topo_dim;
  //  assign topo dimension
  m2cAssert(iv[geom_etype - 1] == xs.size(0), "nnodes do not match");
  b_sfe->etypes[0] = etypes[0];
  b_sfe->etypes[1] = geom_etype;
  //  Get number of nodes per element
  b_sfe->nnodes[0] = iv[etypes[0] - 1];
  b_sfe->nnodes[1] = iv[geom_etype - 1];
  //  Set up quadrature
  a = obtain_elemdegree((etypes[0]));
  qd_or_natcoords = ((a << 1) + (obtain_elemdegree(geom_etype) > 1)) +
                    (xs.size(1) > topo_dim);
  tabulate_quadratures((etypes[0]), qd_or_natcoords, b_sfe->cs, b_sfe->ws);
  b_sfe->nqp = b_sfe->ws.size(0);
  //  Solution space shape functions & derivs
  tabulate_shapefuncs((etypes[0]), b_sfe->cs, b_sfe->shapes_geom,
                      b_sfe->derivs_geom);
  a = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
  b_sfe->shapes_sol.set_size(b_sfe->shapes_geom.size(0),
                             b_sfe->shapes_geom.size(1));
  for (i = 0; i < a; i++) {
    b_sfe->shapes_sol[i] = b_sfe->shapes_geom[i];
  }
  a = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
      b_sfe->derivs_geom.size(0);
  b_sfe->derivs_sol.set_size(b_sfe->derivs_geom.size(0),
                             b_sfe->derivs_geom.size(1),
                             b_sfe->derivs_geom.size(2));
  for (i = 0; i < a; i++) {
    b_sfe->derivs_sol[i] = b_sfe->derivs_geom[i];
  }
  //  Geometry space shape functions & derivs
  if (etypes[0] != geom_etype) {
    tabulate_shapefuncs(geom_etype, b_sfe->cs, b_sfe->shapes_geom,
                        b_sfe->derivs_geom);
  }
  //  potentially skip re-tabulating
  sfe_idx_0_tmp_tmp = b_sfe->nqp;
  b_sfe->cs_phy.set_size(sfe_idx_0_tmp_tmp, xs.size(1));
  for (coder::SizeType q{0}; q < sfe_idx_0_tmp_tmp; q++) {
    i = xs.size(1);
    for (coder::SizeType k{0}; k < i; k++) {
      coder::SizeType m;
      m = b_sfe->shapes_geom.size(1);
      v = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[k];
      for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
        v += b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1] *
             xs[k + xs.size(1) * (b_i - 1)];
      }
      b_sfe->cs_phy[k + b_sfe->cs_phy.size(1) * q] = v;
    }
  }
  //  Compute Jacobian
  b_sfe->wdetJ.set_size(b_sfe->nqp);
  if ((geom_etype == 68) || (geom_etype == 132) || (geom_etype == 36)) {
    double d;
    coder::SizeType geom_dim;
    coder::SizeType n;
    //  A single Jacobian matrix (transpose) is needed for simplex elements
    geom_dim = xs.size(1);
    topo_dim = b_sfe->derivs_geom.size(2);
    std::memset(&dv[0], 0, 9U * sizeof(double));
    n = xs.size(0);
    for (coder::SizeType k{0}; k < n; k++) {
      for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
        for (coder::SizeType j{0}; j < geom_dim; j++) {
          i = j + 3 * b_i;
          dv[i] += xs[j + xs.size(1) * k] *
                   b_sfe->derivs_geom[b_i + b_sfe->derivs_geom.size(2) * k];
        }
      }
    }
    if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
      if (xs.size(1) == 1) {
        d = dv[0];
      } else if (xs.size(1) == 2) {
        d = dv[0] * dv[4] - dv[1] * dv[3];
      } else {
        d = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
             dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
            dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
      }
    } else if (b_sfe->derivs_geom.size(2) == 1) {
      d = dv[0] * dv[0] + dv[1] * dv[1];
      if (xs.size(1) == 3) {
        d += dv[2] * dv[2];
      }
      d = std::sqrt(d);
    } else {
      //  must be 2x3
      dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
      dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
      dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
      d = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
    }
    b_sfe->jacTs.set_size(3, 3);
    for (i = 0; i < 9; i++) {
      b_sfe->jacTs[i] = dv[i];
    }
    for (coder::SizeType q{0}; q < sfe_idx_0_tmp_tmp; q++) {
      b_sfe->wdetJ[q] = d * b_sfe->ws[q];
    }
  } else {
    //  Super-parametric
    a = b_sfe->nqp * 3;
    b_sfe->jacTs.set_size(a, 3);
    for (coder::SizeType q{0}; q < sfe_idx_0_tmp_tmp; q++) {
      coder::SizeType geom_dim;
      coder::SizeType n;
      coder::SizeType y;
      y = q * 3;
      geom_dim = xs.size(1);
      topo_dim = b_sfe->derivs_geom.size(2);
      std::memset(&dv[0], 0, 9U * sizeof(double));
      n = xs.size(0);
      for (coder::SizeType k{0}; k < n; k++) {
        for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
          for (coder::SizeType j{0}; j < geom_dim; j++) {
            i = j + 3 * b_i;
            dv[i] += xs[j + xs.size(1) * k] *
                     b_sfe->derivs_geom[(b_i + b_sfe->derivs_geom.size(2) * k) +
                                        b_sfe->derivs_geom.size(2) *
                                            b_sfe->derivs_geom.size(1) * q];
          }
        }
      }
      if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
        if (xs.size(1) == 1) {
          v = dv[0];
        } else if (xs.size(1) == 2) {
          v = dv[0] * dv[4] - dv[1] * dv[3];
        } else {
          v = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
               dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
              dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
        }
      } else if (b_sfe->derivs_geom.size(2) == 1) {
        v = dv[0] * dv[0] + dv[1] * dv[1];
        if (xs.size(1) == 3) {
          v += dv[2] * dv[2];
        }
        v = std::sqrt(v);
      } else {
        //  must be 2x3
        dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
        dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
        dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
        v = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
      }
      for (i = 0; i < 3; i++) {
        a = i + y;
        b_sfe->jacTs[3 * a] = dv[3 * i];
        b_sfe->jacTs[3 * a + 1] = dv[3 * i + 1];
        b_sfe->jacTs[3 * a + 2] = dv[3 * i + 2];
      }
      b_sfe->wdetJ[q] = v;
      b_sfe->wdetJ[q] = b_sfe->wdetJ[q] * b_sfe->ws[q];
    }
  }
}

// sfe_init - Initialize/reinitialize an sfe object for non-boundary element
static void sfe_init(SfeObject *b_sfe, const int etypes_data[],
                     coder::SizeType etypes_size,
                     const ::coder::array<double, 2U> &xs)
{
  double dv[9];
  double v;
  coder::SizeType a;
  coder::SizeType geom_etype;
  coder::SizeType i;
  coder::SizeType sfe_idx_0_tmp_tmp;
  coder::SizeType topo_dim;
  boolean_T flag;
  if ((etypes_size < 2) || (etypes_data[1] == 0)) {
    geom_etype = etypes_data[0];
  } else {
    geom_etype = etypes_data[1];
  }
  flag = etypes_data[0] == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (etypes_data[0] >> 5 & 7) == (geom_etype >> 5 & 7);
  }
  m2cAssert(flag, "invalid element combinations");
  if (etypes_data[0] != -1) {
    coder::SizeType qd_or_natcoords;
    coder::SizeType shape;
    shape = etypes_data[0] >> 5 & 7;
    topo_dim = ((shape > 0) + (shape > 1)) + (shape > 3);
    //  Geometric dimension
    if (xs.size(1) < topo_dim) {
      m2cErrMsgIdAndTxt("sfe_init:badDim",
                        "geometric dim cannot be smaller than topo dim");
    }
    b_sfe->geom_dim = xs.size(1);
    //  assign geom dimension
    b_sfe->topo_dim = topo_dim;
    //  assign topo dimension
    m2cAssert(iv[geom_etype - 1] == xs.size(0), "nnodes do not match");
    b_sfe->etypes[0] = etypes_data[0];
    b_sfe->etypes[1] = geom_etype;
    //  Get number of nodes per element
    b_sfe->nnodes[0] = iv[etypes_data[0] - 1];
    b_sfe->nnodes[1] = iv[geom_etype - 1];
    //  Set up quadrature
    a = obtain_elemdegree(etypes_data[0]);
    qd_or_natcoords = ((a << 1) + (obtain_elemdegree(geom_etype) > 1)) +
                      (xs.size(1) > topo_dim);
    tabulate_quadratures(etypes_data[0], qd_or_natcoords, b_sfe->cs, b_sfe->ws);
    b_sfe->nqp = b_sfe->ws.size(0);
    //  Solution space shape functions & derivs
    tabulate_shapefuncs(etypes_data[0], b_sfe->cs, b_sfe->shapes_geom,
                        b_sfe->derivs_geom);
    a = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
    b_sfe->shapes_sol.set_size(b_sfe->shapes_geom.size(0),
                               b_sfe->shapes_geom.size(1));
    for (i = 0; i < a; i++) {
      b_sfe->shapes_sol[i] = b_sfe->shapes_geom[i];
    }
    a = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
        b_sfe->derivs_geom.size(0);
    b_sfe->derivs_sol.set_size(b_sfe->derivs_geom.size(0),
                               b_sfe->derivs_geom.size(1),
                               b_sfe->derivs_geom.size(2));
    for (i = 0; i < a; i++) {
      b_sfe->derivs_sol[i] = b_sfe->derivs_geom[i];
    }
    //  Geometry space shape functions & derivs
    if (etypes_data[0] != geom_etype) {
      tabulate_shapefuncs(geom_etype, b_sfe->cs, b_sfe->shapes_geom,
                          b_sfe->derivs_geom);
    }
  } else {
    if ((b_sfe->etypes[0] > 0) && (iv[b_sfe->etypes[0] - 1] != 0)) {
      flag = true;
    } else {
      flag = false;
    }
    m2cAssert(flag, "");
  }
  //  potentially skip re-tabulating
  sfe_idx_0_tmp_tmp = b_sfe->nqp;
  b_sfe->cs_phy.set_size(sfe_idx_0_tmp_tmp, xs.size(1));
  for (coder::SizeType q{0}; q < sfe_idx_0_tmp_tmp; q++) {
    i = xs.size(1);
    for (coder::SizeType k{0}; k < i; k++) {
      coder::SizeType m;
      m = b_sfe->shapes_geom.size(1);
      v = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[k];
      for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
        v += b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1] *
             xs[k + xs.size(1) * (b_i - 1)];
      }
      b_sfe->cs_phy[k + b_sfe->cs_phy.size(1) * q] = v;
    }
  }
  //  Compute Jacobian
  b_sfe->wdetJ.set_size(b_sfe->nqp);
  if ((geom_etype == 68) || (geom_etype == 132) || (geom_etype == 36)) {
    double d;
    coder::SizeType geom_dim;
    coder::SizeType n;
    //  A single Jacobian matrix (transpose) is needed for simplex elements
    geom_dim = xs.size(1);
    topo_dim = b_sfe->derivs_geom.size(2);
    std::memset(&dv[0], 0, 9U * sizeof(double));
    n = xs.size(0);
    for (coder::SizeType k{0}; k < n; k++) {
      for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
        for (coder::SizeType j{0}; j < geom_dim; j++) {
          i = j + 3 * b_i;
          dv[i] += xs[j + xs.size(1) * k] *
                   b_sfe->derivs_geom[b_i + b_sfe->derivs_geom.size(2) * k];
        }
      }
    }
    if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
      if (xs.size(1) == 1) {
        d = dv[0];
      } else if (xs.size(1) == 2) {
        d = dv[0] * dv[4] - dv[1] * dv[3];
      } else {
        d = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
             dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
            dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
      }
    } else if (b_sfe->derivs_geom.size(2) == 1) {
      d = dv[0] * dv[0] + dv[1] * dv[1];
      if (xs.size(1) == 3) {
        d += dv[2] * dv[2];
      }
      d = std::sqrt(d);
    } else {
      //  must be 2x3
      dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
      dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
      dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
      d = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
    }
    b_sfe->jacTs.set_size(3, 3);
    for (i = 0; i < 9; i++) {
      b_sfe->jacTs[i] = dv[i];
    }
    for (coder::SizeType q{0}; q < sfe_idx_0_tmp_tmp; q++) {
      b_sfe->wdetJ[q] = d * b_sfe->ws[q];
    }
  } else {
    //  Super-parametric
    a = b_sfe->nqp * 3;
    b_sfe->jacTs.set_size(a, 3);
    for (coder::SizeType q{0}; q < sfe_idx_0_tmp_tmp; q++) {
      coder::SizeType geom_dim;
      coder::SizeType n;
      coder::SizeType y;
      y = q * 3;
      geom_dim = xs.size(1);
      topo_dim = b_sfe->derivs_geom.size(2);
      std::memset(&dv[0], 0, 9U * sizeof(double));
      n = xs.size(0);
      for (coder::SizeType k{0}; k < n; k++) {
        for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
          for (coder::SizeType j{0}; j < geom_dim; j++) {
            i = j + 3 * b_i;
            dv[i] += xs[j + xs.size(1) * k] *
                     b_sfe->derivs_geom[(b_i + b_sfe->derivs_geom.size(2) * k) +
                                        b_sfe->derivs_geom.size(2) *
                                            b_sfe->derivs_geom.size(1) * q];
          }
        }
      }
      if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
        if (xs.size(1) == 1) {
          v = dv[0];
        } else if (xs.size(1) == 2) {
          v = dv[0] * dv[4] - dv[1] * dv[3];
        } else {
          v = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
               dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
              dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
        }
      } else if (b_sfe->derivs_geom.size(2) == 1) {
        v = dv[0] * dv[0] + dv[1] * dv[1];
        if (xs.size(1) == 3) {
          v += dv[2] * dv[2];
        }
        v = std::sqrt(v);
      } else {
        //  must be 2x3
        dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
        dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
        dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
        v = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
      }
      for (i = 0; i < 3; i++) {
        a = i + y;
        b_sfe->jacTs[3 * a] = dv[3 * i];
        b_sfe->jacTs[3 * a + 1] = dv[3 * i + 1];
        b_sfe->jacTs[3 * a + 2] = dv[3 * i + 2];
      }
      b_sfe->wdetJ[q] = v;
      b_sfe->wdetJ[q] = b_sfe->wdetJ[q] * b_sfe->ws[q];
    }
  }
}

// sfe_init - Initialize/reinitialize an sfe object for non-boundary element
static void sfe_init(SfeObject *b_sfe, const unsigned char etypes[2],
                     const ::coder::array<double, 2U> &xs,
                     coder::SizeType qd_or_natcoords,
                     const ::coder::array<double, 2U> &userquad)
{
  double dv[9];
  double v;
  coder::SizeType a;
  coder::SizeType i;
  coder::SizeType i1;
  coder::SizeType topo_dim;
  unsigned char c;
  unsigned char geom_etype;
  boolean_T flag;
  if (etypes[1] == 0) {
    geom_etype = etypes[0];
  } else {
    geom_etype = etypes[1];
  }
  flag = etypes[0] == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (static_cast<coder::SizeType>(static_cast<unsigned int>(etypes[0]) >>
                                         5) ==
            static_cast<coder::SizeType>(
                static_cast<unsigned int>(geom_etype) >> 5));
  }
  m2cAssert(flag, "invalid element combinations");
  c = static_cast<unsigned char>((etypes[0]) >> 5);
  topo_dim = ((c > 0) + (c > 1)) + (c > 3);
  //  Geometric dimension
  if (xs.size(1) < topo_dim) {
    m2cErrMsgIdAndTxt("sfe_init:badDim",
                      "geometric dim cannot be smaller than topo dim");
  }
  b_sfe->geom_dim = xs.size(1);
  //  assign geom dimension
  b_sfe->topo_dim = topo_dim;
  //  assign topo dimension
  m2cAssert(iv[geom_etype - 1] == xs.size(0), "nnodes do not match");
  b_sfe->etypes[0] = etypes[0];
  b_sfe->etypes[1] = geom_etype;
  //  Get number of nodes per element
  b_sfe->nnodes[0] = iv[etypes[0] - 1];
  b_sfe->nnodes[1] = iv[geom_etype - 1];
  //  Set up quadrature
  if (qd_or_natcoords != -1) {
    if (qd_or_natcoords == 0) {
      //  trial+test+nonlinear_geom?1:0
      a = obtain_elemdegree((etypes[0]));
      qd_or_natcoords = ((a << 1) + (obtain_elemdegree(geom_etype) > 1)) +
                        (xs.size(1) > topo_dim);
    }
    tabulate_quadratures((etypes[0]), qd_or_natcoords, b_sfe->cs, b_sfe->ws);
    b_sfe->nqp = b_sfe->ws.size(0);
  } else {
    if ((userquad.size(0) == 0) || (userquad.size(1) == 0)) {
      m2cErrMsgIdAndTxt("sfe_init:missUserQuad",
                        "missing user quadrature data");
    }
    if (userquad.size(1) != topo_dim + 1) {
      m2cErrMsgIdAndTxt("sfe_init:badUserQuadDim",
                        "bad user quadrature data size");
    }
    b_sfe->nqp = userquad.size(0);
    b_sfe->ws.set_size(b_sfe->nqp);
    b_sfe->cs.set_size(b_sfe->nqp, topo_dim);
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      b_sfe->ws[q] = userquad[userquad.size(1) * q];
      for (coder::SizeType k{0}; k < topo_dim; k++) {
        b_sfe->cs[k + b_sfe->cs.size(1) * q] =
            userquad[(k + userquad.size(1) * q) + 1];
      }
    }
  }
  //  Solution space shape functions & derivs
  tabulate_shapefuncs((etypes[0]), b_sfe->cs, b_sfe->shapes_geom,
                      b_sfe->derivs_geom);
  a = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
  b_sfe->shapes_sol.set_size(b_sfe->shapes_geom.size(0),
                             b_sfe->shapes_geom.size(1));
  for (i = 0; i < a; i++) {
    b_sfe->shapes_sol[i] = b_sfe->shapes_geom[i];
  }
  a = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
      b_sfe->derivs_geom.size(0);
  b_sfe->derivs_sol.set_size(b_sfe->derivs_geom.size(0),
                             b_sfe->derivs_geom.size(1),
                             b_sfe->derivs_geom.size(2));
  for (i = 0; i < a; i++) {
    b_sfe->derivs_sol[i] = b_sfe->derivs_geom[i];
  }
  //  Geometry space shape functions & derivs
  if (etypes[0] != geom_etype) {
    tabulate_shapefuncs(geom_etype, b_sfe->cs, b_sfe->shapes_geom,
                        b_sfe->derivs_geom);
  }
  //  potentially skip re-tabulating
  b_sfe->cs_phy.set_size(b_sfe->nqp, xs.size(1));
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    i1 = xs.size(1);
    for (coder::SizeType k{0}; k < i1; k++) {
      coder::SizeType m;
      m = b_sfe->shapes_geom.size(1);
      v = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[k];
      for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
        v += b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1] *
             xs[k + xs.size(1) * (b_i - 1)];
      }
      b_sfe->cs_phy[k + b_sfe->cs_phy.size(1) * q] = v;
    }
  }
  //  Compute Jacobian
  b_sfe->wdetJ.set_size(b_sfe->nqp);
  if ((geom_etype == 68) || (geom_etype == 132) || (geom_etype == 36)) {
    double d;
    coder::SizeType geom_dim;
    coder::SizeType n;
    //  A single Jacobian matrix (transpose) is needed for simplex elements
    geom_dim = xs.size(1);
    topo_dim = b_sfe->derivs_geom.size(2);
    std::memset(&dv[0], 0, 9U * sizeof(double));
    n = xs.size(0);
    for (coder::SizeType k{0}; k < n; k++) {
      for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
        for (coder::SizeType j{0}; j < geom_dim; j++) {
          i = j + 3 * b_i;
          dv[i] += xs[j + xs.size(1) * k] *
                   b_sfe->derivs_geom[b_i + b_sfe->derivs_geom.size(2) * k];
        }
      }
    }
    if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
      if (xs.size(1) == 1) {
        d = dv[0];
      } else if (xs.size(1) == 2) {
        d = dv[0] * dv[4] - dv[1] * dv[3];
      } else {
        d = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
             dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
            dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
      }
    } else if (b_sfe->derivs_geom.size(2) == 1) {
      d = dv[0] * dv[0] + dv[1] * dv[1];
      if (xs.size(1) == 3) {
        d += dv[2] * dv[2];
      }
      d = std::sqrt(d);
    } else {
      //  must be 2x3
      dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
      dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
      dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
      d = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
    }
    b_sfe->jacTs.set_size(3, 3);
    for (i = 0; i < 9; i++) {
      b_sfe->jacTs[i] = dv[i];
    }
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      b_sfe->wdetJ[q] = d * b_sfe->ws[q];
    }
  } else {
    //  Super-parametric
    a = b_sfe->nqp * 3;
    b_sfe->jacTs.set_size(a, 3);
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      coder::SizeType geom_dim;
      coder::SizeType n;
      coder::SizeType y;
      y = q * 3;
      geom_dim = xs.size(1);
      topo_dim = b_sfe->derivs_geom.size(2);
      std::memset(&dv[0], 0, 9U * sizeof(double));
      n = xs.size(0);
      for (coder::SizeType k{0}; k < n; k++) {
        for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
          for (coder::SizeType j{0}; j < geom_dim; j++) {
            i1 = j + 3 * b_i;
            dv[i1] +=
                xs[j + xs.size(1) * k] *
                b_sfe->derivs_geom[(b_i + b_sfe->derivs_geom.size(2) * k) +
                                   b_sfe->derivs_geom.size(2) *
                                       b_sfe->derivs_geom.size(1) * q];
          }
        }
      }
      if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
        if (xs.size(1) == 1) {
          v = dv[0];
        } else if (xs.size(1) == 2) {
          v = dv[0] * dv[4] - dv[1] * dv[3];
        } else {
          v = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
               dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
              dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
        }
      } else if (b_sfe->derivs_geom.size(2) == 1) {
        v = dv[0] * dv[0] + dv[1] * dv[1];
        if (xs.size(1) == 3) {
          v += dv[2] * dv[2];
        }
        v = std::sqrt(v);
      } else {
        //  must be 2x3
        dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
        dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
        dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
        v = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
      }
      for (i1 = 0; i1 < 3; i1++) {
        a = i1 + y;
        b_sfe->jacTs[3 * a] = dv[3 * i1];
        b_sfe->jacTs[3 * a + 1] = dv[3 * i1 + 1];
        b_sfe->jacTs[3 * a + 2] = dv[3 * i1 + 2];
      }
      b_sfe->wdetJ[q] = v;
      b_sfe->wdetJ[q] = b_sfe->wdetJ[q] * b_sfe->ws[q];
    }
  }
}

// sfe_init - Initialize/reinitialize an sfe object for non-boundary element
static void sfe_init(SfeObject *b_sfe, const unsigned char etypes[2],
                     const ::coder::array<double, 2U> &xs,
                     const ::coder::array<double, 2U> &qd_or_natcoords)
{
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType sfe_idx_0_tmp_tmp;
  coder::SizeType topo_dim;
  unsigned char c;
  unsigned char geom_etype;
  boolean_T flag;
  if (etypes[1] == 0) {
    geom_etype = etypes[0];
  } else {
    geom_etype = etypes[1];
  }
  flag = etypes[0] == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (static_cast<coder::SizeType>(static_cast<unsigned int>(etypes[0]) >>
                                         5) ==
            static_cast<coder::SizeType>(
                static_cast<unsigned int>(geom_etype) >> 5));
  }
  m2cAssert(flag, "invalid element combinations");
  c = static_cast<unsigned char>((etypes[0]) >> 5);
  topo_dim = ((c > 0) + (c > 1)) + (c > 3);
  //  Geometric dimension
  if (xs.size(1) < topo_dim) {
    m2cErrMsgIdAndTxt("sfe_init:badDim",
                      "geometric dim cannot be smaller than topo dim");
  }
  b_sfe->geom_dim = xs.size(1);
  //  assign geom dimension
  b_sfe->topo_dim = topo_dim;
  //  assign topo dimension
  m2cAssert(iv[geom_etype - 1] == xs.size(0), "nnodes do not match");
  b_sfe->etypes[0] = etypes[0];
  b_sfe->etypes[1] = geom_etype;
  //  Get number of nodes per element
  b_sfe->nnodes[0] = iv[etypes[0] - 1];
  b_sfe->nnodes[1] = iv[geom_etype - 1];
  //  User-input natural coordinates
  b_sfe->nqp = qd_or_natcoords.size(0);
  sfe_idx_0_tmp_tmp = b_sfe->nqp;
  b_sfe->ws.set_size(sfe_idx_0_tmp_tmp);
  for (i = 0; i < sfe_idx_0_tmp_tmp; i++) {
    b_sfe->ws[i] = 1.0;
  }
  //  user ones for dummy quad weights
  b_sfe->cs.set_size(sfe_idx_0_tmp_tmp, topo_dim);
  for (coder::SizeType q{0}; q < sfe_idx_0_tmp_tmp; q++) {
    for (coder::SizeType k{0}; k < topo_dim; k++) {
      b_sfe->cs[k + b_sfe->cs.size(1) * q] =
          qd_or_natcoords[k + qd_or_natcoords.size(1) * q];
    }
  }
  //  Solution space shape functions & derivs
  tabulate_shapefuncs((etypes[0]), b_sfe->cs, b_sfe->shapes_geom,
                      b_sfe->derivs_geom);
  loop_ub = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
  b_sfe->shapes_sol.set_size(b_sfe->shapes_geom.size(0),
                             b_sfe->shapes_geom.size(1));
  for (i = 0; i < loop_ub; i++) {
    b_sfe->shapes_sol[i] = b_sfe->shapes_geom[i];
  }
  loop_ub = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
            b_sfe->derivs_geom.size(0);
  b_sfe->derivs_sol.set_size(b_sfe->derivs_geom.size(0),
                             b_sfe->derivs_geom.size(1),
                             b_sfe->derivs_geom.size(2));
  for (i = 0; i < loop_ub; i++) {
    b_sfe->derivs_sol[i] = b_sfe->derivs_geom[i];
  }
  //  Geometry space shape functions & derivs
  if (etypes[0] != geom_etype) {
    tabulate_shapefuncs(geom_etype, b_sfe->cs, b_sfe->shapes_geom,
                        b_sfe->derivs_geom);
  }
  //  potentially skip re-tabulating
  b_sfe->cs_phy.set_size(sfe_idx_0_tmp_tmp, xs.size(1));
  for (coder::SizeType q{0}; q < sfe_idx_0_tmp_tmp; q++) {
    i = xs.size(1);
    for (coder::SizeType k{0}; k < i; k++) {
      double v;
      coder::SizeType m;
      m = b_sfe->shapes_geom.size(1);
      v = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[k];
      for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
        v += b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1] *
             xs[k + xs.size(1) * (b_i - 1)];
      }
      b_sfe->cs_phy[k + b_sfe->cs_phy.size(1) * q] = v;
    }
  }
  //  Compute Jacobian
}

static void sfe_init_grad(SfeObject *b_sfe, coder::SizeType q)
{
  double Jt[9];
  coder::SizeType dim;
  coder::SizeType n;
  m2cAssert(b_sfe->geom_dim == b_sfe->topo_dim, "not implemented");
  //  for now
  if (q > b_sfe->nqp) {
    m2cErrMsgIdAndTxt("sfe_init_grad:badRange",
                      "out of bound of qpoint range %d", (int)q);
  }
  if (b_sfe->jacTs.size(0) == 3) {
    for (coder::SizeType i{0}; i < 3; i++) {
      Jt[3 * i] = b_sfe->jacTs[3 * i];
      Jt[3 * i + 1] = b_sfe->jacTs[3 * i + 1];
      Jt[3 * i + 2] = b_sfe->jacTs[3 * i + 2];
    }
  } else {
    coder::SizeType y;
    y = (q - 1) * 3;
    for (coder::SizeType i{0}; i < 3; i++) {
      coder::SizeType Jt_tmp;
      Jt_tmp = i + y;
      Jt[3 * i] = b_sfe->jacTs[3 * Jt_tmp];
      Jt[3 * i + 1] = b_sfe->jacTs[3 * Jt_tmp + 1];
      Jt[3 * i + 2] = b_sfe->jacTs[3 * Jt_tmp + 2];
    }
  }
  dim = b_sfe->derivs_sol.size(2);
  n = b_sfe->derivs_sol.size(1);
  b_sfe->grads_sol.set_size(b_sfe->derivs_sol.size(1),
                            b_sfe->derivs_sol.size(2));
  for (coder::SizeType b_i{0}; b_i < n; b_i++) {
    for (coder::SizeType d{0}; d < dim; d++) {
      b_sfe->grads_sol[d + b_sfe->grads_sol.size(1) * b_i] =
          b_sfe->derivs_sol[(d + b_sfe->derivs_sol.size(2) * b_i) +
                            b_sfe->derivs_sol.size(2) *
                                b_sfe->derivs_sol.size(1) * (q - 1)];
    }
  }
  if (b_sfe->geom_dim == b_sfe->topo_dim) {
    boolean_T info;
    info = solve_sq(Jt, b_sfe->geom_dim, b_sfe->grads_sol);
    m2cAssert(!info, "singular Jacobian");
  }
}

static boolean_T solve_sq(double J[9], coder::SizeType n,
                          ::coder::array<double, 2U> &b1)
{
  coder::SizeType m1;
  boolean_T info;
  m1 = b1.size(0) - 1;
  info = false;
  if (n == 1) {
    if (J[0] == 0.0) {
      info = true;
    } else {
      double ji;
      ji = 1.0 / J[0];
      for (coder::SizeType i{0}; i <= m1; i++) {
        b1[b1.size(1) * i] = b1[b1.size(1) * i] * ji;
      }
    }
  } else {
    double pivot;
    double t;
    boolean_T guard1{false};
    boolean_T guard2{false};
    boolean_T guard3{false};
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (n == 2) {
      if (std::abs(J[0]) >= std::abs(J[3])) {
        pivot = J[0];
        if (J[0] == 0.0) {
          info = true;
        } else {
          guard2 = true;
        }
      } else {
        pivot = J[3];
        t = J[3];
        J[3] = J[0];
        J[0] = t;
        t = J[4];
        J[4] = J[1];
        J[1] = t;
        for (coder::SizeType i{0}; i <= m1; i++) {
          t = b1[b1.size(1) * i + 1];
          b1[b1.size(1) * i + 1] = b1[b1.size(1) * i];
          b1[b1.size(1) * i] = t;
        }
        guard2 = true;
      }
    } else {
      double d;
      double d1;
      //  3x3
      d = std::abs(J[0]);
      d1 = std::abs(J[3]);
      if ((d >= d1) && (d >= std::abs(J[6]))) {
        pivot = J[0];
        if (J[0] == 0.0) {
          info = true;
        } else {
          guard3 = true;
        }
      } else if (d1 >= std::abs(J[6])) {
        pivot = J[3];
        if (J[3] == 0.0) {
          info = true;
        } else {
          t = J[3];
          J[3] = J[0];
          J[0] = t;
          t = J[4];
          J[4] = J[1];
          J[1] = t;
          t = J[5];
          J[5] = J[2];
          J[2] = t;
          for (coder::SizeType i{0}; i <= m1; i++) {
            t = b1[b1.size(1) * i + 1];
            b1[b1.size(1) * i + 1] = b1[b1.size(1) * i];
            b1[b1.size(1) * i] = t;
          }
          guard3 = true;
        }
      } else {
        pivot = J[6];
        t = J[6];
        J[6] = J[0];
        J[0] = t;
        t = J[7];
        J[7] = J[1];
        J[1] = t;
        t = J[8];
        J[8] = J[2];
        J[2] = t;
        for (coder::SizeType i{0}; i <= m1; i++) {
          t = b1[b1.size(1) * i + 2];
          b1[b1.size(1) * i + 2] = b1[b1.size(1) * i];
          b1[b1.size(1) * i] = t;
        }
        guard3 = true;
      }
    }
    if (guard3) {
      J[3] /= pivot;
      J[4] -= J[1] * J[3];
      J[5] -= J[2] * J[3];
      J[6] /= pivot;
      J[7] -= J[1] * J[6];
      J[8] -= J[2] * J[6];
      for (coder::SizeType i{0}; i <= m1; i++) {
        b1[b1.size(1) * i + 1] =
            b1[b1.size(1) * i + 1] - J[3] * b1[b1.size(1) * i];
        b1[b1.size(1) * i + 2] =
            b1[b1.size(1) * i + 2] - J[6] * b1[b1.size(1) * i];
      }
      if (std::abs(J[4]) >= std::abs(J[7])) {
        pivot = J[4];
        if (J[4] == 0.0) {
          info = true;
        } else {
          guard1 = true;
        }
      } else {
        pivot = J[7];
        t = J[6];
        J[6] = J[3];
        J[3] = t;
        t = J[7];
        J[7] = J[4];
        J[4] = t;
        t = J[8];
        J[8] = J[5];
        J[5] = t;
        for (coder::SizeType i{0}; i <= m1; i++) {
          t = b1[b1.size(1) * i + 2];
          b1[b1.size(1) * i + 2] = b1[b1.size(1) * i + 1];
          b1[b1.size(1) * i + 1] = t;
        }
        guard1 = true;
      }
    }
    if (guard2) {
      J[3] /= pivot;
      J[4] -= J[1] * J[3];
      if (J[4] == 0.0) {
        info = true;
      } else {
        for (coder::SizeType i{0}; i <= m1; i++) {
          b1[b1.size(1) * i + 1] =
              (b1[b1.size(1) * i + 1] - J[3] * b1[b1.size(1) * i]) / J[4];
          b1[b1.size(1) * i] =
              (b1[b1.size(1) * i] - J[1] * b1[b1.size(1) * i + 1]) / J[0];
        }
      }
    }
    if (guard1) {
      J[7] /= pivot;
      J[8] -= J[5] * J[7];
      if (J[8] == 0.0) {
        info = true;
      } else {
        for (coder::SizeType i{0}; i <= m1; i++) {
          b1[b1.size(1) * i + 2] =
              (b1[b1.size(1) * i + 2] - J[7] * b1[b1.size(1) * i + 1]) / J[8];
          b1[b1.size(1) * i + 1] =
              (b1[b1.size(1) * i + 1] - J[5] * b1[b1.size(1) * i + 2]) / J[4];
          b1[b1.size(1) * i] =
              ((b1[b1.size(1) * i] - J[2] * b1[b1.size(1) * i + 2]) -
               J[1] * b1[b1.size(1) * i + 1]) /
              J[0];
        }
      }
    }
  }
  return info;
}

// tabulate_quadratures - Tabulate quadrature rule for given element type
static void tabulate_quadratures(coder::SizeType etype, coder::SizeType qd,
                                 ::coder::array<double, 2U> &cs,
                                 ::coder::array<double, 1U> &ws)
{
  coder::SizeType nqp;
  coder::SizeType shape;
  boolean_T guard1{false};
  boolean_T guard10{false};
  boolean_T guard11{false};
  boolean_T guard12{false};
  boolean_T guard13{false};
  boolean_T guard14{false};
  boolean_T guard15{false};
  boolean_T guard16{false};
  boolean_T guard17{false};
  boolean_T guard18{false};
  boolean_T guard19{false};
  boolean_T guard2{false};
  boolean_T guard20{false};
  boolean_T guard21{false};
  boolean_T guard22{false};
  boolean_T guard23{false};
  boolean_T guard24{false};
  boolean_T guard25{false};
  boolean_T guard3{false};
  boolean_T guard4{false};
  boolean_T guard5{false};
  boolean_T guard6{false};
  boolean_T guard7{false};
  boolean_T guard8{false};
  boolean_T guard9{false};
  shape = etype >> 5 & 7;
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  guard5 = false;
  guard6 = false;
  guard7 = false;
  guard8 = false;
  guard9 = false;
  guard10 = false;
  guard11 = false;
  guard12 = false;
  guard13 = false;
  guard14 = false;
  guard15 = false;
  guard16 = false;
  guard17 = false;
  guard18 = false;
  guard19 = false;
  guard20 = false;
  guard21 = false;
  guard22 = false;
  guard23 = false;
  guard24 = false;
  guard25 = false;
  switch (shape) {
  case 1:
    bar_quadrules(qd, cs, ws);
    break;
  case 2:
    switch (qd) {
    case 0:
      guard1 = true;
      break;
    case 1:
      guard1 = true;
      break;
    case 2:
      nqp = ::sfe_qrules::tri_deg2_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::tri_deg2_qrule(&cs[0], &(ws.data())[0]);
      break;
    case 3:
      guard2 = true;
      break;
    case 4:
      guard2 = true;
      break;
    case 5:
      nqp = ::sfe_qrules::tri_deg5_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::tri_deg5_qrule(&cs[0], &(ws.data())[0]);
      break;
    case 6:
      guard3 = true;
      break;
    case 7:
      guard3 = true;
      break;
    case 8:
      nqp = ::sfe_qrules::tri_deg8_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::tri_deg8_qrule(&cs[0], &(ws.data())[0]);
      break;
    case 9:
      nqp = ::sfe_qrules::tri_deg9_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::tri_deg9_qrule(&cs[0], &(ws.data())[0]);
      break;
    case 10:
      guard4 = true;
      break;
    case 11:
      guard4 = true;
      break;
    default:
      if (qd > 13) {
        m2cWarnMsgIdAndTxt("tri_quadrules:UnsupportedDegree",
                           "Only support up to degree 13");
      }
      nqp = ::sfe_qrules::tri_deg13_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::tri_deg13_qrule(&cs[0], &(ws.data())[0]);
      break;
    }
    break;
  case 3:
    switch (qd) {
    case 0:
      guard5 = true;
      break;
    case 1:
      guard5 = true;
      break;
    case 2:
      guard6 = true;
      break;
    case 3:
      guard6 = true;
      break;
    case 4:
      guard7 = true;
      break;
    case 5:
      guard7 = true;
      break;
    case 6:
      guard8 = true;
      break;
    case 7:
      guard8 = true;
      break;
    case 8:
      guard9 = true;
      break;
    case 9:
      guard9 = true;
      break;
    case 10:
      guard10 = true;
      break;
    case 11:
      guard10 = true;
      break;
    default:
      if (qd > 13) {
        m2cWarnMsgIdAndTxt("bar_quadrules:UnsupportedDegree",
                           "Only support up to degree 13");
      }
      nqp = ::sfe_qrules::quad_deg13_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::quad_deg13_qrule(&cs[0], &(ws.data())[0]);
      break;
    }
    break;
  case 4:
    switch (qd) {
    case 0:
      guard11 = true;
      break;
    case 1:
      guard11 = true;
      break;
    case 2:
      nqp = ::sfe_qrules::tet_deg2_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg2_qrule(&cs[0], &(ws.data())[0]);
      break;
    case 3:
      nqp = ::sfe_qrules::tet_deg3_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg3_qrule(&cs[0], &(ws.data())[0]);
      break;
    case 4:
      guard12 = true;
      break;
    case 5:
      guard12 = true;
      break;
    case 6:
      nqp = ::sfe_qrules::tet_deg6_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg6_qrule(&cs[0], &(ws.data())[0]);
      break;
    case 7:
      nqp = ::sfe_qrules::tet_deg7_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg7_qrule(&cs[0], &(ws.data())[0]);
      break;
    case 8:
      guard13 = true;
      break;
    case 9:
      guard13 = true;
      break;
    case 10:
      guard14 = true;
      break;
    case 11:
      guard14 = true;
      break;
    default:
      if (qd > 13) {
        m2cWarnMsgIdAndTxt("tet_quadrules:UnsupportedDegree",
                           "Only support up to degree 13");
      }
      nqp = ::sfe_qrules::tet_deg13_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg13_qrule(&cs[0], &(ws.data())[0]);
      break;
    }
    break;
  case 7:
    switch (qd) {
    case 0:
      guard15 = true;
      break;
    case 1:
      guard15 = true;
      break;
    case 2:
      guard16 = true;
      break;
    case 3:
      guard16 = true;
      break;
    case 4:
      guard17 = true;
      break;
    case 5:
      guard17 = true;
      break;
    case 6:
      guard18 = true;
      break;
    case 7:
      guard18 = true;
      break;
    case 8:
      guard19 = true;
      break;
    case 9:
      guard19 = true;
      break;
    case 10:
      guard20 = true;
      break;
    case 11:
      guard20 = true;
      break;
    default:
      if (qd > 13) {
        m2cWarnMsgIdAndTxt("hexa_quadrules:UnsupportedDegree",
                           "Only support up to degree 13");
      }
      nqp = ::sfe_qrules::hexa_deg13_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::hexa_deg13_qrule(&cs[0], &(ws.data())[0]);
      break;
    }
    break;
  case 6:
    switch (qd) {
    case 0:
      guard21 = true;
      break;
    case 1:
      guard21 = true;
      break;
    case 2:
      nqp = ::sfe_qrules::prism_deg2_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::prism_deg2_qrule(&cs[0], &(ws.data())[0]);
      break;
    case 3:
      nqp = ::sfe_qrules::prism_deg3_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::prism_deg3_qrule(&cs[0], &(ws.data())[0]);
      break;
    case 4:
      guard22 = true;
      break;
    case 5:
      guard22 = true;
      break;
    case 6:
      guard23 = true;
      break;
    case 7:
      guard23 = true;
      break;
    case 8:
      guard24 = true;
      break;
    case 9:
      guard24 = true;
      break;
    case 10:
      guard25 = true;
      break;
    case 11:
      guard25 = true;
      break;
    default:
      if (qd > 13) {
        m2cWarnMsgIdAndTxt("prism_quadrules:UnsupportedDegree",
                           "Only support up to degree 13");
      }
      nqp = ::sfe_qrules::prism_deg13_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::prism_deg13_qrule(&cs[0], &(ws.data())[0]);
      break;
    }
    break;
  default:
    m2cAssert(shape == 5, "Unsupported element type");
    pyra_quadrules(qd, cs, ws);
    break;
  }
  if (guard25) {
    nqp = ::sfe_qrules::prism_deg11_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::prism_deg11_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard24) {
    nqp = ::sfe_qrules::prism_deg9_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::prism_deg9_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard23) {
    nqp = ::sfe_qrules::prism_deg7_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::prism_deg7_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard22) {
    nqp = ::sfe_qrules::prism_deg5_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::prism_deg5_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard21) {
    nqp = ::sfe_qrules::prism_deg1_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::prism_deg1_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard20) {
    nqp = ::sfe_qrules::hexa_deg11_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::hexa_deg11_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard19) {
    nqp = ::sfe_qrules::hexa_deg9_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::hexa_deg9_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard18) {
    nqp = ::sfe_qrules::hexa_deg7_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::hexa_deg7_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard17) {
    nqp = ::sfe_qrules::hexa_deg5_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::hexa_deg5_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard16) {
    nqp = ::sfe_qrules::hexa_deg3_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::hexa_deg3_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard15) {
    nqp = ::sfe_qrules::hexa_deg1_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::hexa_deg1_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard14) {
    nqp = ::sfe_qrules::tet_deg11_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::tet_deg11_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard13) {
    //  The degree-8 quadrature rule KEAST9 has negative weights, so we do
    nqp = ::sfe_qrules::tet_deg9_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::tet_deg9_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard12) {
    nqp = ::sfe_qrules::tet_deg5_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::tet_deg5_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard11) {
    nqp = ::sfe_qrules::tet_deg1_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::tet_deg1_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard10) {
    nqp = ::sfe_qrules::quad_deg11_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::quad_deg11_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard9) {
    nqp = ::sfe_qrules::quad_deg9_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::quad_deg9_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard8) {
    nqp = ::sfe_qrules::quad_deg7_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::quad_deg7_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard7) {
    nqp = ::sfe_qrules::quad_deg5_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::quad_deg5_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard6) {
    nqp = ::sfe_qrules::quad_deg3_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::quad_deg3_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard5) {
    nqp = ::sfe_qrules::quad_deg1_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::quad_deg1_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard4) {
    nqp = ::sfe_qrules::tri_deg11_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg11_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard3) {
    nqp = ::sfe_qrules::tri_deg7_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg7_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard2) {
    nqp = ::sfe_qrules::tri_deg4_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg4_qrule(&cs[0], &(ws.data())[0]);
  }
  if (guard1) {
    nqp = ::sfe_qrules::tri_deg1_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg1_qrule(&cs[0], &(ws.data())[0]);
  }
}

// tabulate_shapefuncs - kernel for tabulating shape functions
static void tabulate_shapefuncs(coder::SizeType etype,
                                const ::coder::array<double, 2U> &cs,
                                ::coder::array<double, 2U> &sfvals,
                                ::coder::array<double, 3U> &sdvals)
{
  coder::SizeType shape;
  shape = etype >> 5 & 7;
  switch (((shape > 0) + (shape > 1)) + (shape > 3)) {
  case 3:
    sfe3_tabulate_shapefuncs(etype, cs, sfvals, sdvals);
    break;
  case 2:
    sfe2_tabulate_shapefuncs(etype, cs, sfvals, sdvals);
    break;
  default:
    sfe1_tabulate_shapefuncs(etype, cs, sfvals, sdvals);
    break;
  }
}

// obtain_elemdegree - Decode the element degree from etype
coder::SizeType obtain_elemdegree(coder::SizeType etype)
{
  return etype >> 2 & 7;
}

// sfe_bnd_init - Initialize an SfeObject instance for boundary element
void sfe_bnd_init(SfeObject *b_sfe, const int etypes_data[],
                  const coder::SizeType etypes_size[1], signed char facetid,
                  const ::coder::array<double, 2U> &xs,
                  coder::SizeType qd_or_natcoords,
                  const ::coder::array<double, 2U> &userquad)
{
  coder::SizeType geom_etype;
  coder::SizeType lids_size;
  coder::SizeType nfnodes;
  coder::SizeType sol_etype;
  short lids_data[50];
  unsigned char geom_bnd_etype;
  boolean_T flag;
  if (etypes_data[0] == -1) {
    //  pre-initialized
    sol_etype = b_sfe->etypes[0];
    geom_etype = b_sfe->etypes[1];
  } else {
    sol_etype = etypes_data[0];
    if ((etypes_size[0] < 2) || (etypes_data[1] == 0)) {
      geom_etype = etypes_data[0];
    } else {
      geom_etype = etypes_data[1];
    }
  }
  //  check if valid combo
  flag = sol_etype == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (sol_etype >> 5 & 7) == (geom_etype >> 5 & 7);
  }
  m2cAssert(flag, "invalid element combination");
  if ((facetid >= 1) && (facetid <= obtain_facets(sol_etype))) {
    flag = true;
  } else {
    flag = false;
  }
  m2cAssert(flag, "facet ID out of range");
  m2cAssert(xs.size(0) == iv[geom_etype - 1], "unmatched nnodes");
  obtain_facets(geom_etype, facetid, &geom_bnd_etype, lids_data, &lids_size);
  nfnodes = lids_size;
  b_sfe->xswork.set_size(nfnodes, xs.size(1));
  for (coder::SizeType i{0}; i < lids_size; i++) {
    coder::SizeType b_i;
    b_i = xs.size(1);
    for (coder::SizeType d{0}; d < b_i; d++) {
      b_sfe->xswork[d + b_sfe->xswork.size(1) * i] =
          xs[d + xs.size(1) * (lids_data[i] - 1)];
    }
  }
  b_sfe->facetid = facetid;
  if (etypes_data[0] == -1) {
    //  remain already-initialized stage
    sfe_init(b_sfe, etypes_data, etypes_size[0], b_sfe->xswork, qd_or_natcoords,
             userquad);
  } else {
    unsigned char b_trial_bnd_etype[2];
    unsigned char trial_bnd_etype;
    trial_bnd_etype = obtain_facets(sol_etype, facetid);
    b_trial_bnd_etype[0] = trial_bnd_etype;
    b_trial_bnd_etype[1] = geom_bnd_etype;
    sfe_init(b_sfe, b_trial_bnd_etype, b_sfe->xswork, qd_or_natcoords,
             userquad);
    //  reset to volume cell types
    b_sfe->etypes[0] = sol_etype;
    b_sfe->etypes[1] = geom_etype;
    //  NOTE the number of nodes in sfe are based on facet elements
  }
}

// sfe_bnd_init - Initialize an SfeObject instance for boundary element
void sfe_bnd_init(SfeObject *b_sfe, const int etypes_data[],
                  const coder::SizeType etypes_size[1], signed char facetid,
                  const ::coder::array<double, 2U> &xs,
                  coder::SizeType qd_or_natcoords)
{
  ::coder::array<double, 2U> b_userquad_data;
  ::coder::array<double, 2U> userquad_data;
  coder::SizeType geom_etype;
  coder::SizeType lids_size;
  coder::SizeType nfnodes;
  coder::SizeType sol_etype;
  short lids_data[50];
  unsigned char geom_bnd_etype;
  boolean_T flag;
  if (etypes_data[0] == -1) {
    //  pre-initialized
    sol_etype = b_sfe->etypes[0];
    geom_etype = b_sfe->etypes[1];
  } else {
    sol_etype = etypes_data[0];
    if ((etypes_size[0] < 2) || (etypes_data[1] == 0)) {
      geom_etype = etypes_data[0];
    } else {
      geom_etype = etypes_data[1];
    }
  }
  //  check if valid combo
  flag = sol_etype == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (sol_etype >> 5 & 7) == (geom_etype >> 5 & 7);
  }
  m2cAssert(flag, "invalid element combination");
  if ((facetid >= 1) && (facetid <= obtain_facets(sol_etype))) {
    flag = true;
  } else {
    flag = false;
  }
  m2cAssert(flag, "facet ID out of range");
  m2cAssert(xs.size(0) == iv[geom_etype - 1], "unmatched nnodes");
  obtain_facets(geom_etype, facetid, &geom_bnd_etype, lids_data, &lids_size);
  nfnodes = lids_size;
  b_sfe->xswork.set_size(nfnodes, xs.size(1));
  for (coder::SizeType i{0}; i < lids_size; i++) {
    coder::SizeType b_i;
    b_i = xs.size(1);
    for (coder::SizeType d{0}; d < b_i; d++) {
      b_sfe->xswork[d + b_sfe->xswork.size(1) * i] =
          xs[d + xs.size(1) * (lids_data[i] - 1)];
    }
  }
  b_sfe->facetid = facetid;
  if (etypes_data[0] == -1) {
    //  remain already-initialized stage
    userquad_data.set(nullptr, 0, 0);
    sfe_init(b_sfe, etypes_data, etypes_size[0], b_sfe->xswork, qd_or_natcoords,
             userquad_data);
  } else {
    unsigned char b_trial_bnd_etype[2];
    unsigned char trial_bnd_etype;
    trial_bnd_etype = obtain_facets(sol_etype, facetid);
    b_trial_bnd_etype[0] = trial_bnd_etype;
    b_trial_bnd_etype[1] = geom_bnd_etype;
    b_userquad_data.set(nullptr, 0, 0);
    sfe_init(b_sfe, b_trial_bnd_etype, b_sfe->xswork, qd_or_natcoords,
             b_userquad_data);
    //  reset to volume cell types
    b_sfe->etypes[0] = sol_etype;
    b_sfe->etypes[1] = geom_etype;
    //  NOTE the number of nodes in sfe are based on facet elements
  }
}

// sfe_bnd_init - Initialize an SfeObject instance for boundary element
void sfe_bnd_init(SfeObject *b_sfe, const int etypes_data[],
                  const coder::SizeType etypes_size[1], signed char facetid,
                  const ::coder::array<double, 2U> &xs)
{
  coder::SizeType geom_etype;
  coder::SizeType lids_size;
  coder::SizeType nfnodes;
  coder::SizeType sol_etype;
  short lids_data[50];
  unsigned char geom_bnd_etype;
  boolean_T flag;
  if (etypes_data[0] == -1) {
    //  pre-initialized
    sol_etype = b_sfe->etypes[0];
    geom_etype = b_sfe->etypes[1];
  } else {
    sol_etype = etypes_data[0];
    if ((etypes_size[0] < 2) || (etypes_data[1] == 0)) {
      geom_etype = etypes_data[0];
    } else {
      geom_etype = etypes_data[1];
    }
  }
  //  check if valid combo
  flag = sol_etype == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (sol_etype >> 5 & 7) == (geom_etype >> 5 & 7);
  }
  m2cAssert(flag, "invalid element combination");
  if ((facetid >= 1) && (facetid <= obtain_facets(sol_etype))) {
    flag = true;
  } else {
    flag = false;
  }
  m2cAssert(flag, "facet ID out of range");
  m2cAssert(xs.size(0) == iv[geom_etype - 1], "unmatched nnodes");
  obtain_facets(geom_etype, facetid, &geom_bnd_etype, lids_data, &lids_size);
  nfnodes = lids_size;
  b_sfe->xswork.set_size(nfnodes, xs.size(1));
  for (coder::SizeType i{0}; i < lids_size; i++) {
    coder::SizeType b_i;
    b_i = xs.size(1);
    for (coder::SizeType d{0}; d < b_i; d++) {
      b_sfe->xswork[d + b_sfe->xswork.size(1) * i] =
          xs[d + xs.size(1) * (lids_data[i] - 1)];
    }
  }
  b_sfe->facetid = facetid;
  if (etypes_data[0] == -1) {
    //  remain already-initialized stage
    sfe_init(b_sfe, etypes_data, etypes_size[0], b_sfe->xswork);
  } else {
    unsigned char b_trial_bnd_etype[2];
    unsigned char trial_bnd_etype;
    trial_bnd_etype = obtain_facets(sol_etype, facetid);
    b_trial_bnd_etype[0] = trial_bnd_etype;
    b_trial_bnd_etype[1] = geom_bnd_etype;
    sfe_init(b_sfe, b_trial_bnd_etype, b_sfe->xswork);
    //  reset to volume cell types
    b_sfe->etypes[0] = sol_etype;
    b_sfe->etypes[1] = geom_etype;
    //  NOTE the number of nodes in sfe are based on facet elements
  }
}

// sfe_bnd_init - Initialize an SfeObject instance for boundary element
void sfe_bnd_init(SfeObject *b_sfe, const int etypes_data[],
                  const coder::SizeType etypes_size[1], signed char facetid,
                  const ::coder::array<double, 2U> &xs,
                  const ::coder::array<double, 2U> &qd_or_natcoords)
{
  coder::SizeType geom_etype;
  coder::SizeType lids_size;
  coder::SizeType nfnodes;
  coder::SizeType sol_etype;
  short lids_data[50];
  unsigned char geom_bnd_etype;
  boolean_T flag;
  if (etypes_data[0] == -1) {
    //  pre-initialized
    sol_etype = b_sfe->etypes[0];
    geom_etype = b_sfe->etypes[1];
  } else {
    sol_etype = etypes_data[0];
    if ((etypes_size[0] < 2) || (etypes_data[1] == 0)) {
      geom_etype = etypes_data[0];
    } else {
      geom_etype = etypes_data[1];
    }
  }
  //  check if valid combo
  flag = sol_etype == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (sol_etype >> 5 & 7) == (geom_etype >> 5 & 7);
  }
  m2cAssert(flag, "invalid element combination");
  if ((facetid >= 1) && (facetid <= obtain_facets(sol_etype))) {
    flag = true;
  } else {
    flag = false;
  }
  m2cAssert(flag, "facet ID out of range");
  m2cAssert(xs.size(0) == iv[geom_etype - 1], "unmatched nnodes");
  obtain_facets(geom_etype, facetid, &geom_bnd_etype, lids_data, &lids_size);
  nfnodes = lids_size;
  b_sfe->xswork.set_size(nfnodes, xs.size(1));
  for (coder::SizeType i{0}; i < lids_size; i++) {
    coder::SizeType b_i;
    b_i = xs.size(1);
    for (coder::SizeType d{0}; d < b_i; d++) {
      b_sfe->xswork[d + b_sfe->xswork.size(1) * i] =
          xs[d + xs.size(1) * (lids_data[i] - 1)];
    }
  }
  b_sfe->facetid = facetid;
  if (etypes_data[0] == -1) {
    //  remain already-initialized stage
    sfe_init(b_sfe, etypes_data, etypes_size[0], b_sfe->xswork,
             qd_or_natcoords);
  } else {
    unsigned char b_trial_bnd_etype[2];
    unsigned char trial_bnd_etype;
    trial_bnd_etype = obtain_facets(sol_etype, facetid);
    b_trial_bnd_etype[0] = trial_bnd_etype;
    b_trial_bnd_etype[1] = geom_bnd_etype;
    sfe_init(b_sfe, b_trial_bnd_etype, b_sfe->xswork, qd_or_natcoords);
    //  reset to volume cell types
    b_sfe->etypes[0] = sol_etype;
    b_sfe->etypes[1] = geom_etype;
    //  NOTE the number of nodes in sfe are based on facet elements
  }
}

// sfe_elem_dbc - Apply Dirichlet boundary conditions (DBC)
void sfe_elem_dbc(::coder::array<double, 2U> &elemmat,
                  ::coder::array<double, 1U> &load,
                  const ::coder::array<boolean_T, 1U> &dtags)
{
  coder::SizeType n;
  n = elemmat.size(0) - 1;
  m2cAssert(load.size(0) == elemmat.size(0), "");
  for (coder::SizeType i{0}; i <= n; i++) {
    if (dtags[i]) {
      coder::SizeType b_i;
      //  not a dirichlet node
      for (coder::SizeType j{0}; j <= n; j++) {
        elemmat[i + elemmat.size(1) * j] = 0.0;
      }
      b_i = elemmat.size(1);
      for (coder::SizeType j{0}; j < b_i; j++) {
        elemmat[j + elemmat.size(1) * i] = 0.0;
      }
      elemmat[i + elemmat.size(1) * i] = 1.0;
      load[i] = 0.0;
    }
  }
}

// sfe_elem_dbc - Apply Dirichlet boundary conditions (DBC)
void sfe_elem_dbc(::coder::array<double, 2U> &elemmat,
                  ::coder::array<double, 1U> &load,
                  const ::coder::array<boolean_T, 1U> &dtags,
                  const ::coder::array<double, 1U> &dvals)
{
  coder::SizeType n;
  n = elemmat.size(0) - 1;
  m2cAssert(load.size(0) == elemmat.size(0), "");
  for (coder::SizeType i{0}; i <= n; i++) {
    if (dtags[i]) {
      double dv;
      coder::SizeType b_i;
      //  not a dirichlet node
      dv = 0.0;
      if (dvals.size(0) != 0) {
        dv = dvals[i];
      }
      if (dv != 0.0) {
        for (coder::SizeType j{0}; j <= n; j++) {
          load[j] = load[j] - elemmat[i + elemmat.size(1) * j] * dv;
          elemmat[i + elemmat.size(1) * j] = 0.0;
        }
      } else {
        for (coder::SizeType j{0}; j <= n; j++) {
          elemmat[i + elemmat.size(1) * j] = 0.0;
        }
      }
      b_i = elemmat.size(1);
      for (coder::SizeType j{0}; j < b_i; j++) {
        elemmat[j + elemmat.size(1) * i] = 0.0;
      }
      elemmat[i + elemmat.size(1) * i] = 1.0;
      load[i] = dv;
    }
  }
}

// sfe_elem_dbc - Apply Dirichlet boundary conditions (DBC)
void sfe_elem_dbc(::coder::array<double, 2U> &elemmat,
                  ::coder::array<double, 1U> &load,
                  const ::coder::array<boolean_T, 1U> &dtags,
                  const ::coder::array<double, 1U> &dvals,
                  const ::coder::array<int, 1U> &gdofs)
{
  coder::SizeType n;
  n = elemmat.size(0) - 1;
  m2cAssert(load.size(0) == elemmat.size(0), "");
  for (coder::SizeType i{0}; i <= n; i++) {
    if (dtags[gdofs[i] - 1]) {
      double dv;
      coder::SizeType b_i;
      //  not a dirichlet node
      dv = 0.0;
      if (dvals.size(0) != 0) {
        dv = dvals[gdofs[i] - 1];
      }
      if (dv != 0.0) {
        for (coder::SizeType j{0}; j <= n; j++) {
          load[j] = load[j] - elemmat[i + elemmat.size(1) * j] * dv;
          elemmat[i + elemmat.size(1) * j] = 0.0;
        }
      } else {
        for (coder::SizeType j{0}; j <= n; j++) {
          elemmat[i + elemmat.size(1) * j] = 0.0;
        }
      }
      b_i = elemmat.size(1);
      for (coder::SizeType j{0}; j < b_i; j++) {
        elemmat[j + elemmat.size(1) * i] = 0.0;
      }
      elemmat[i + elemmat.size(1) * i] = 1.0;
      load[i] = dv;
    }
  }
}

// sfe_elem_le2d - Computing the stiffness matrix for linear elasticity in 2D
void sfe_elem_le2d(SfeObject *b_sfe, double mu, double lambda,
                   ::coder::array<double, 2U> &elemmat)
{
  double D[9];
  double B[6];
  double Bi[6];
  double b_D[6];
  double c_sfe;
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType n;
  coder::SizeType y_tmp;
  m2cAssert(b_sfe->geom_dim == 2, "");
  n = b_sfe->nnodes[0];
  y_tmp = b_sfe->nnodes[0] << 1;
  elemmat.set_size(y_tmp, y_tmp);
  loop_ub = y_tmp * y_tmp;
  for (i = 0; i < loop_ub; i++) {
    elemmat[i] = 0.0;
  }
  double d;
  d = lambda + 2.0 * mu;
  //  stiffness tensor
  D[0] = d;
  D[1] = lambda;
  D[2] = 0.0;
  D[3] = lambda;
  D[4] = d;
  D[5] = 0.0;
  D[6] = 0.0;
  D[7] = 0.0;
  D[8] = mu;
  //  loop through all quadrature points
  i = b_sfe->nqp;
  if ((i - 1 >= 0) && (n - 1 >= 0)) {
    Bi[1] = 0.0;
    Bi[2] = 0.0;
  }
  for (coder::SizeType q{0}; q < i; q++) {
    //  initialize gradient
    sfe_init_grad(b_sfe, q + 1);
    //  compute stiffness matrix Bi'*D*Bj
    for (coder::SizeType b_i{0}; b_i < n; b_i++) {
      double elemmat_idx_3;
      double ux;
      double uy;
      ux = b_sfe->grads_sol[b_sfe->grads_sol.size(1) * b_i];
      uy = b_sfe->grads_sol[b_sfe->grads_sol.size(1) * b_i + 1];
      Bi[0] = ux;
      Bi[3] = uy;
      Bi[4] = uy;
      Bi[5] = ux;
      loop_ub = b_i << 1;
      if (b_i + 1 <= n) {
        B[1] = 0.0;
        B[2] = 0.0;
        c_sfe = b_sfe->wdetJ[q];
        for (coder::SizeType i1{0}; i1 < 3; i1++) {
          ux = D[i1];
          uy = D[i1 + 3];
          elemmat_idx_3 = D[i1 + 6];
          for (coder::SizeType i2{0}; i2 < 2; i2++) {
            b_D[i1 + 3 * i2] =
                (ux * Bi[i2] + uy * Bi[i2 + 2]) + elemmat_idx_3 * Bi[i2 + 4];
          }
        }
      }
      for (coder::SizeType j{b_i + 1}; j <= n; j++) {
        double b_B[4];
        coder::SizeType y;
        y = (j - 1) << 1;
        ux = b_sfe->grads_sol[b_sfe->grads_sol.size(1) * (j - 1)];
        uy = b_sfe->grads_sol[b_sfe->grads_sol.size(1) * (j - 1) + 1];
        B[0] = ux;
        B[3] = uy;
        B[4] = uy;
        B[5] = ux;
        for (coder::SizeType i1{0}; i1 < 2; i1++) {
          ux = B[i1];
          uy = B[i1 + 2];
          elemmat_idx_3 = B[i1 + 4];
          for (coder::SizeType i2{0}; i2 < 2; i2++) {
            b_B[i1 + (i2 << 1)] = (ux * b_D[3 * i2] + uy * b_D[3 * i2 + 1]) +
                                  elemmat_idx_3 * b_D[3 * i2 + 2];
          }
        }
        ux = elemmat[(y + elemmat.size(1) * loop_ub) + 1] + b_B[1] * c_sfe;
        uy = elemmat[y + elemmat.size(1) * (loop_ub + 1)] + b_B[2] * c_sfe;
        elemmat_idx_3 =
            elemmat[(y + elemmat.size(1) * (loop_ub + 1)) + 1] + b_B[3] * c_sfe;
        elemmat[y + elemmat.size(1) * loop_ub] =
            elemmat[y + elemmat.size(1) * loop_ub] + b_B[0] * c_sfe;
        elemmat[(y + elemmat.size(1) * loop_ub) + 1] = ux;
        elemmat[y + elemmat.size(1) * (loop_ub + 1)] = uy;
        elemmat[(y + elemmat.size(1) * (loop_ub + 1)) + 1] = elemmat_idx_3;
      }
    }
  }
  //  fill in lower part
  for (coder::SizeType b_i{2}; b_i <= y_tmp; b_i++) {
    for (coder::SizeType j{0}; j <= b_i - 2; j++) {
      elemmat[j + elemmat.size(1) * (b_i - 1)] =
          elemmat[(b_i + elemmat.size(1) * j) - 1];
    }
  }
}

// sfe_elem_le3d - Computing the stiffness matrix for linear elasticity in 3D
void sfe_elem_le3d(SfeObject *b_sfe, double mu, double lambda,
                   ::coder::array<double, 2U> &elemmat)
{
  double D[36];
  double B[18];
  double Bi[18];
  double c_sfe;
  int elemmat_tmp[3];
  coder::SizeType i;
  coder::SizeType m;
  coder::SizeType n;
  coder::SizeType y_tmp;
  m2cAssert(b_sfe->geom_dim == 3, "");
  n = b_sfe->nnodes[0];
  y_tmp = b_sfe->nnodes[0] * 3;
  elemmat.set_size(y_tmp, y_tmp);
  y_tmp *= y_tmp;
  for (i = 0; i < y_tmp; i++) {
    elemmat[i] = 0.0;
  }
  double d;
  d = lambda + 2.0 * mu;
  //  stiffness tensor
  D[0] = d;
  D[1] = 2.0 * lambda;
  D[2] = 2.0 * lambda;
  D[3] = 0.0;
  D[4] = 0.0;
  D[5] = 0.0;
  D[6] = 2.0 * lambda;
  D[7] = d;
  D[8] = 2.0 * lambda;
  D[9] = 0.0;
  D[10] = 0.0;
  D[11] = 0.0;
  D[12] = 2.0 * lambda;
  D[13] = 2.0 * lambda;
  D[14] = d;
  D[15] = 0.0;
  D[16] = 0.0;
  D[17] = 0.0;
  D[18] = 0.0;
  D[19] = 0.0;
  D[20] = 0.0;
  D[21] = mu;
  D[22] = 0.0;
  D[23] = 0.0;
  D[24] = 0.0;
  D[25] = 0.0;
  D[26] = 0.0;
  D[27] = 0.0;
  D[28] = mu;
  D[29] = 0.0;
  D[30] = 0.0;
  D[31] = 0.0;
  D[32] = 0.0;
  D[33] = 0.0;
  D[34] = 0.0;
  D[35] = mu;
  //  loop through all quadrature points
  i = b_sfe->nqp;
  if ((i - 1 >= 0) && (n - 1 >= 0)) {
    Bi[1] = 0.0;
    Bi[2] = 0.0;
    Bi[3] = 0.0;
    Bi[5] = 0.0;
    Bi[6] = 0.0;
    Bi[7] = 0.0;
    Bi[11] = 0.0;
    Bi[12] = 0.0;
    Bi[16] = 0.0;
  }
  for (coder::SizeType q{0}; q < i; q++) {
    //  initialize gradient
    sfe_init_grad(b_sfe, q + 1);
    //  compute stiffness matrix Bi'*D*Bj
    for (coder::SizeType b_i{0}; b_i < n; b_i++) {
      double ux;
      double uy;
      double uz;
      coder::SizeType y;
      ux = b_sfe->grads_sol[b_sfe->grads_sol.size(1) * b_i];
      uy = b_sfe->grads_sol[b_sfe->grads_sol.size(1) * b_i + 1];
      uz = b_sfe->grads_sol[b_sfe->grads_sol.size(1) * b_i + 2];
      Bi[0] = ux;
      Bi[4] = uy;
      Bi[8] = uz;
      Bi[9] = uy;
      Bi[10] = ux;
      Bi[13] = uz;
      Bi[14] = uy;
      Bi[15] = uz;
      Bi[17] = ux;
      y = b_i * 3;
      if (b_i + 1 <= n) {
        B[1] = 0.0;
        B[2] = 0.0;
        B[3] = 0.0;
        B[5] = 0.0;
        B[6] = 0.0;
        B[7] = 0.0;
        B[11] = 0.0;
        B[12] = 0.0;
        B[16] = 0.0;
        c_sfe = b_sfe->wdetJ[q];
        elemmat_tmp[0] = y + 1;
        elemmat_tmp[1] = y + 2;
        elemmat_tmp[2] = y + 3;
      }
      for (coder::SizeType j{b_i + 1}; j <= n; j++) {
        double b_D[18];
        double b_B[9];
        double b_elemmat[9];
        coder::SizeType i2;
        y = (j - 1) * 3;
        ux = b_sfe->grads_sol[b_sfe->grads_sol.size(1) * (j - 1)];
        uy = b_sfe->grads_sol[b_sfe->grads_sol.size(1) * (j - 1) + 1];
        uz = b_sfe->grads_sol[b_sfe->grads_sol.size(1) * (j - 1) + 2];
        B[0] = ux;
        B[4] = uy;
        B[8] = uz;
        B[9] = uy;
        B[10] = ux;
        B[13] = uz;
        B[14] = uy;
        B[15] = uz;
        B[17] = ux;
        for (coder::SizeType i1{0}; i1 < 6; i1++) {
          for (i2 = 0; i2 < 3; i2++) {
            ux = 0.0;
            for (y_tmp = 0; y_tmp < 6; y_tmp++) {
              ux += D[i1 + 6 * y_tmp] * Bi[i2 + 3 * y_tmp];
            }
            b_D[i1 + 6 * i2] = ux;
          }
        }
        for (coder::SizeType i1{0}; i1 < 3; i1++) {
          for (i2 = 0; i2 < 3; i2++) {
            ux = 0.0;
            for (y_tmp = 0; y_tmp < 6; y_tmp++) {
              ux += B[i1 + 3 * y_tmp] * b_D[y_tmp + 6 * i2];
            }
            b_B[i1 + 3 * i2] = ux;
          }
        }
        for (coder::SizeType i1{0}; i1 < 3; i1++) {
          i2 = elemmat_tmp[i1];
          b_elemmat[3 * i1] =
              elemmat[y + elemmat.size(1) * (i2 - 1)] + b_B[3 * i1] * c_sfe;
          y_tmp = 3 * i1 + 1;
          b_elemmat[y_tmp] = elemmat[(y + elemmat.size(1) * (i2 - 1)) + 1] +
                             b_B[y_tmp] * c_sfe;
          y_tmp = 3 * i1 + 2;
          b_elemmat[y_tmp] = elemmat[(y + elemmat.size(1) * (i2 - 1)) + 2] +
                             b_B[y_tmp] * c_sfe;
        }
        for (coder::SizeType i1{0}; i1 < 3; i1++) {
          i2 = elemmat_tmp[i1];
          elemmat[y + elemmat.size(1) * (i2 - 1)] = b_elemmat[3 * i1];
          elemmat[(y + elemmat.size(1) * (i2 - 1)) + 1] = b_elemmat[3 * i1 + 1];
          elemmat[(y + elemmat.size(1) * (i2 - 1)) + 2] = b_elemmat[3 * i1 + 2];
        }
      }
    }
  }
  //  fill in lower part
  m = 3 * n;
  for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
    for (coder::SizeType j{0}; j <= b_i - 2; j++) {
      elemmat[j + elemmat.size(1) * (b_i - 1)] =
          elemmat[(b_i + elemmat.size(1) * j) - 1];
    }
  }
}

// sfe_elem_load - Computing load vector for an element
void sfe_elem_load(const SfeObject *b_sfe, const ::coder::array<double, 2U> &fs,
                   boolean_T compwise, ::coder::array<double, 1U> &load)
{
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType n;
  coder::SizeType ncomps;
  n = b_sfe->nnodes[0] - 1;
  m2cAssert(b_sfe->nnodes[0] == fs.size(0), "");
  ncomps = fs.size(1);
  load.set_size(fs.size(1) * b_sfe->nnodes[0]);
  loop_ub = fs.size(1) * b_sfe->nnodes[0];
  for (i = 0; i < loop_ub; i++) {
    load[i] = 0.0;
  }
  //  for each quadrature point
  if (compwise) {
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      coder::SizeType j;
      j = 0;
      for (coder::SizeType k{0}; k < ncomps; k++) {
        double a;
        double v;
        coder::SizeType m;
        m = b_sfe->shapes_sol.size(1);
        v = b_sfe->shapes_sol[b_sfe->shapes_sol.size(1) * q] * fs[k];
        for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
          v += b_sfe->shapes_sol[(b_i + b_sfe->shapes_sol.size(1) * q) - 1] *
               fs[k + fs.size(1) * (b_i - 1)];
        }
        a = v * b_sfe->wdetJ[q];
        for (coder::SizeType b_i{0}; b_i <= n; b_i++) {
          loop_ub = j + b_i;
          load[loop_ub] =
              load[loop_ub] +
              a * b_sfe->shapes_sol[b_i + b_sfe->shapes_sol.size(1) * q];
        }
        j = (j + n) + 1;
      }
    }
  } else {
    //  tensor blocks of DOFs, not component-wise
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      for (coder::SizeType k{0}; k < ncomps; k++) {
        double a;
        double v;
        coder::SizeType m;
        m = b_sfe->shapes_sol.size(1);
        v = b_sfe->shapes_sol[b_sfe->shapes_sol.size(1) * q] * fs[k];
        for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
          v += b_sfe->shapes_sol[(b_i + b_sfe->shapes_sol.size(1) * q) - 1] *
               fs[k + fs.size(1) * (b_i - 1)];
        }
        a = v * b_sfe->wdetJ[q];
        for (coder::SizeType b_i{0}; b_i <= n; b_i++) {
          load[k + b_i * ncomps] =
              load[k + b_i * ncomps] +
              a * b_sfe->shapes_sol[b_i + b_sfe->shapes_sol.size(1) * q];
        }
      }
    }
  }
}

// sfe_elem_load - Computing load vector for an element
void sfe_elem_load(const SfeObject *b_sfe, const ::coder::array<double, 2U> &fs,
                   ::coder::array<double, 1U> &load)
{
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType n;
  coder::SizeType ncomps;
  n = b_sfe->nnodes[0];
  m2cAssert(b_sfe->nnodes[0] == fs.size(0), "");
  ncomps = fs.size(1);
  load.set_size(fs.size(1) * b_sfe->nnodes[0]);
  loop_ub = fs.size(1) * b_sfe->nnodes[0];
  for (i = 0; i < loop_ub; i++) {
    load[i] = 0.0;
  }
  //  for each quadrature point
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    for (coder::SizeType k{0}; k < ncomps; k++) {
      double a;
      double v;
      coder::SizeType m;
      m = b_sfe->shapes_sol.size(1);
      v = b_sfe->shapes_sol[b_sfe->shapes_sol.size(1) * q] * fs[k];
      for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
        v += b_sfe->shapes_sol[(b_i + b_sfe->shapes_sol.size(1) * q) - 1] *
             fs[k + fs.size(1) * (b_i - 1)];
      }
      a = v * b_sfe->wdetJ[q];
      for (coder::SizeType b_i{0}; b_i < n; b_i++) {
        load[k + b_i * ncomps] =
            load[k + b_i * ncomps] +
            a * b_sfe->shapes_sol[b_i + b_sfe->shapes_sol.size(1) * q];
      }
    }
  }
}

// sfe_elem_mass - Computing the local mass matrix for an element
void sfe_elem_mass(const SfeObject *b_sfe, ::coder::array<double, 2U> &elemmat)
{
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType m;
  m = b_sfe->nnodes[0];
  elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[0]);
  loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[0];
  for (i = 0; i < loop_ub; i++) {
    elemmat[i] = 0.0;
  }
  //  for each qpoint
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    //  get weighted volume
    for (coder::SizeType b_i{0}; b_i < m; b_i++) {
      double psi;
      psi = b_sfe->wdetJ[q] *
            b_sfe->shapes_sol[b_i + b_sfe->shapes_sol.size(1) * q];
      for (coder::SizeType j{b_i + 1}; j <= m; j++) {
        elemmat[(j + elemmat.size(1) * b_i) - 1] =
            elemmat[(j + elemmat.size(1) * b_i) - 1] +
            b_sfe->shapes_sol[(j + b_sfe->shapes_sol.size(1) * q) - 1] * psi;
      }
    }
  }
  //  fill in lower part
  for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
    for (coder::SizeType j{0}; j <= b_i - 2; j++) {
      elemmat[j + elemmat.size(1) * (b_i - 1)] =
          elemmat[(b_i + elemmat.size(1) * j) - 1];
    }
  }
}

// sfe_elem_mass - Computing the local mass matrix for an element
void sfe_elem_mass(const SfeObject *b_sfe, double rho,
                   ::coder::array<double, 2U> &elemmat)
{
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType m;
  m = b_sfe->nnodes[0];
  elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[0]);
  loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[0];
  for (i = 0; i < loop_ub; i++) {
    elemmat[i] = 0.0;
  }
  //  for each qpoint
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    double wdetj;
    //  get weighted volume
    wdetj = b_sfe->wdetJ[q] * rho;
    for (coder::SizeType b_i{0}; b_i < m; b_i++) {
      double psi;
      psi = wdetj * b_sfe->shapes_sol[b_i + b_sfe->shapes_sol.size(1) * q];
      for (coder::SizeType j{b_i + 1}; j <= m; j++) {
        elemmat[(j + elemmat.size(1) * b_i) - 1] =
            elemmat[(j + elemmat.size(1) * b_i) - 1] +
            b_sfe->shapes_sol[(j + b_sfe->shapes_sol.size(1) * q) - 1] * psi;
      }
    }
  }
  //  fill in lower part
  for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
    for (coder::SizeType j{0}; j <= b_i - 2; j++) {
      elemmat[j + elemmat.size(1) * (b_i - 1)] =
          elemmat[(b_i + elemmat.size(1) * j) - 1];
    }
  }
}

// sfe_elem_mass - Computing the local mass matrix for an element
void sfe_elem_mass(const SfeObject *b_sfe,
                   const ::coder::array<double, 1U> &rho,
                   ::coder::array<double, 2U> &elemmat)
{
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType m;
  m = b_sfe->nnodes[0];
  elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[0]);
  loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[0];
  for (i = 0; i < loop_ub; i++) {
    elemmat[i] = 0.0;
  }
  //  for each qpoint
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    double wdetj;
    //  get weighted volume
    if (rho.size(0) == 1) {
      wdetj = b_sfe->wdetJ[q] * rho[0];
    } else {
      double v;
      coder::SizeType b_m;
      b_m = b_sfe->shapes_sol.size(1);
      v = b_sfe->shapes_sol[b_sfe->shapes_sol.size(1) * q] * rho[0];
      for (coder::SizeType b_i{2}; b_i <= b_m; b_i++) {
        v += b_sfe->shapes_sol[(b_i + b_sfe->shapes_sol.size(1) * q) - 1] *
             rho[b_i - 1];
      }
      wdetj = b_sfe->wdetJ[q] * v;
    }
    for (coder::SizeType b_i{0}; b_i < m; b_i++) {
      double psi;
      psi = wdetj * b_sfe->shapes_sol[b_i + b_sfe->shapes_sol.size(1) * q];
      for (coder::SizeType j{b_i + 1}; j <= m; j++) {
        elemmat[(j + elemmat.size(1) * b_i) - 1] =
            elemmat[(j + elemmat.size(1) * b_i) - 1] +
            b_sfe->shapes_sol[(j + b_sfe->shapes_sol.size(1) * q) - 1] * psi;
      }
    }
  }
  //  fill in lower part
  for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
    for (coder::SizeType j{0}; j <= b_i - 2; j++) {
      elemmat[j + elemmat.size(1) * (b_i - 1)] =
          elemmat[(b_i + elemmat.size(1) * j) - 1];
    }
  }
}

// sfe_elem_nbc - Compute local Neumann boundary values as load vectors
void sfe_elem_nbc(const SfeObject *b_sfe, const ::coder::array<double, 2U> &g,
                  ::coder::array<double, 1U> &load)
{
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType n;
  coder::SizeType ncomps;
  m2cAssert(b_sfe->facetid != 0, "must be a boundary element");
  n = b_sfe->nnodes[0];
  m2cAssert(b_sfe->nnodes[0] == g.size(0), "");
  ncomps = g.size(1);
  load.set_size(g.size(1) * b_sfe->nnodes[0]);
  loop_ub = g.size(1) * b_sfe->nnodes[0];
  for (i = 0; i < loop_ub; i++) {
    load[i] = 0.0;
  }
  //  for each quadrature point
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    for (coder::SizeType k{0}; k < ncomps; k++) {
      double a;
      double v;
      coder::SizeType m;
      m = b_sfe->shapes_sol.size(1);
      v = b_sfe->shapes_sol[b_sfe->shapes_sol.size(1) * q] * g[k];
      for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
        v += b_sfe->shapes_sol[(b_i + b_sfe->shapes_sol.size(1) * q) - 1] *
             g[k + g.size(1) * (b_i - 1)];
      }
      a = v * b_sfe->wdetJ[q];
      for (coder::SizeType b_i{0}; b_i < n; b_i++) {
        load[k + b_i * ncomps] =
            load[k + b_i * ncomps] +
            a * b_sfe->shapes_sol[b_i + b_sfe->shapes_sol.size(1) * q];
      }
    }
  }
}

// sfe_elem_nbc - Compute local Neumann boundary values as load vectors
void sfe_elem_nbc(const SfeObject *b_sfe, const ::coder::array<double, 2U> &g,
                  boolean_T compwise, ::coder::array<double, 1U> &load)
{
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType n;
  coder::SizeType ncomps;
  m2cAssert(b_sfe->facetid != 0, "must be a boundary element");
  n = b_sfe->nnodes[0] - 1;
  m2cAssert(b_sfe->nnodes[0] == g.size(0), "");
  ncomps = g.size(1);
  load.set_size(g.size(1) * b_sfe->nnodes[0]);
  loop_ub = g.size(1) * b_sfe->nnodes[0];
  for (i = 0; i < loop_ub; i++) {
    load[i] = 0.0;
  }
  //  for each quadrature point
  if (compwise) {
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      coder::SizeType j;
      j = 0;
      for (coder::SizeType k{0}; k < ncomps; k++) {
        double a;
        double v;
        coder::SizeType m;
        m = b_sfe->shapes_sol.size(1);
        v = b_sfe->shapes_sol[b_sfe->shapes_sol.size(1) * q] * g[k];
        for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
          v += b_sfe->shapes_sol[(b_i + b_sfe->shapes_sol.size(1) * q) - 1] *
               g[k + g.size(1) * (b_i - 1)];
        }
        a = v * b_sfe->wdetJ[q];
        for (coder::SizeType b_i{0}; b_i <= n; b_i++) {
          loop_ub = j + b_i;
          load[loop_ub] =
              load[loop_ub] +
              a * b_sfe->shapes_sol[b_i + b_sfe->shapes_sol.size(1) * q];
        }
        j = (j + n) + 1;
      }
    }
  } else {
    //  tensor blocks of DOFs, not component-wise
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      for (coder::SizeType k{0}; k < ncomps; k++) {
        double a;
        double v;
        coder::SizeType m;
        m = b_sfe->shapes_sol.size(1);
        v = b_sfe->shapes_sol[b_sfe->shapes_sol.size(1) * q] * g[k];
        for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
          v += b_sfe->shapes_sol[(b_i + b_sfe->shapes_sol.size(1) * q) - 1] *
               g[k + g.size(1) * (b_i - 1)];
        }
        a = v * b_sfe->wdetJ[q];
        for (coder::SizeType b_i{0}; b_i <= n; b_i++) {
          load[k + b_i * ncomps] =
              load[k + b_i * ncomps] +
              a * b_sfe->shapes_sol[b_i + b_sfe->shapes_sol.size(1) * q];
        }
      }
    }
  }
}

// sfe_elem_stiff - Compute the element-wise stiffness matrix
void sfe_elem_stiff(SfeObject *b_sfe, double nu,
                    ::coder::array<double, 2U> &elemmat)
{
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType m;
  m = b_sfe->nnodes[0] - 1;
  elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[0]);
  loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[0];
  for (i = 0; i < loop_ub; i++) {
    elemmat[i] = 0.0;
  }
  //  for each qpoint
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    double stiff_coeff;
    //  initialize gradients at this qpoint
    sfe_init_grad(b_sfe, q + 1);
    //  get weighted volume
    stiff_coeff = nu * b_sfe->wdetJ[q];
    for (coder::SizeType b_i{0}; b_i <= m; b_i++) {
      for (coder::SizeType j{0}; j <= m; j++) {
        loop_ub = b_sfe->geom_dim;
        for (coder::SizeType k{0}; k < loop_ub; k++) {
          elemmat[j + elemmat.size(1) * b_i] =
              elemmat[j + elemmat.size(1) * b_i] +
              stiff_coeff * b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * j] *
                  b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * b_i];
        }
      }
    }
    //  Convection part
  }
}

// sfe_elem_stiff - Compute the element-wise stiffness matrix
void sfe_elem_stiff(SfeObject *b_sfe, double nu, const double vel_data[],
                    const coder::SizeType vel_size[2],
                    ::coder::array<double, 2U> &elemmat)
{
  double vel_coeff_data[3];
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType m;
  m = b_sfe->nnodes[0] - 1;
  elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[0]);
  loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[0];
  for (i = 0; i < loop_ub; i++) {
    elemmat[i] = 0.0;
  }
  //  for each qpoint
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    double stiff_coeff;
    //  initialize gradients at this qpoint
    sfe_init_grad(b_sfe, q + 1);
    //  get weighted volume
    stiff_coeff = nu * b_sfe->wdetJ[q];
    for (coder::SizeType b_i{0}; b_i <= m; b_i++) {
      for (coder::SizeType j{0}; j <= m; j++) {
        loop_ub = b_sfe->geom_dim;
        for (coder::SizeType k{0}; k < loop_ub; k++) {
          elemmat[j + elemmat.size(1) * b_i] =
              elemmat[j + elemmat.size(1) * b_i] +
              stiff_coeff * b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * j] *
                  b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * b_i];
        }
      }
    }
    //  Convection part
    loop_ub = vel_size[1];
    if (vel_size[1] != 0) {
      std::copy(&vel_data[0], &vel_data[loop_ub], &vel_coeff_data[0]);
      //  scale with weighted volume
      loop_ub = b_sfe->geom_dim;
      for (coder::SizeType k{0}; k < loop_ub; k++) {
        vel_coeff_data[k] *= b_sfe->wdetJ[q];
      }
      for (coder::SizeType b_i{0}; b_i <= m; b_i++) {
        double psi;
        psi = b_sfe->shapes_sol[b_i + b_sfe->shapes_sol.size(1) * q];
        for (coder::SizeType j{0}; j <= m; j++) {
          for (coder::SizeType k{0}; k < loop_ub; k++) {
            elemmat[j + elemmat.size(1) * b_i] =
                elemmat[j + elemmat.size(1) * b_i] +
                vel_coeff_data[k] *
                    b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * j] * psi;
          }
        }
      }
    }
  }
}

// sfe_elem_stiff - Compute the element-wise stiffness matrix
void sfe_elem_stiff(SfeObject *b_sfe, const ::coder::array<double, 1U> &nu,
                    ::coder::array<double, 2U> &elemmat)
{
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType m;
  m = b_sfe->nnodes[0] - 1;
  elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[0]);
  loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[0];
  for (i = 0; i < loop_ub; i++) {
    elemmat[i] = 0.0;
  }
  //  for each qpoint
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    double stiff_coeff;
    //  initialize gradients at this qpoint
    sfe_init_grad(b_sfe, q + 1);
    //  get weighted volume
    if (nu.size(0) == 1) {
      stiff_coeff = nu[0] * b_sfe->wdetJ[q];
    } else {
      double v;
      coder::SizeType b_m;
      b_m = b_sfe->shapes_sol.size(1);
      v = b_sfe->shapes_sol[b_sfe->shapes_sol.size(1) * q] * nu[0];
      for (coder::SizeType b_i{2}; b_i <= b_m; b_i++) {
        v += b_sfe->shapes_sol[(b_i + b_sfe->shapes_sol.size(1) * q) - 1] *
             nu[b_i - 1];
      }
      stiff_coeff = v * b_sfe->wdetJ[q];
    }
    for (coder::SizeType b_i{0}; b_i <= m; b_i++) {
      for (coder::SizeType j{0}; j <= m; j++) {
        loop_ub = b_sfe->geom_dim;
        for (coder::SizeType k{0}; k < loop_ub; k++) {
          elemmat[j + elemmat.size(1) * b_i] =
              elemmat[j + elemmat.size(1) * b_i] +
              stiff_coeff * b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * j] *
                  b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * b_i];
        }
      }
    }
    //  Convection part
  }
}

// sfe_elem_stiff - Compute the element-wise stiffness matrix
void sfe_elem_stiff(SfeObject *b_sfe, double nu,
                    const ::coder::array<double, 2U> &vel,
                    ::coder::array<double, 2U> &elemmat)
{
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType m;
  m = b_sfe->nnodes[0] - 1;
  elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[0]);
  loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[0];
  for (i = 0; i < loop_ub; i++) {
    elemmat[i] = 0.0;
  }
  //  for each qpoint
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    double stiff_coeff;
    coder::SizeType i1;
    //  initialize gradients at this qpoint
    sfe_init_grad(b_sfe, q + 1);
    //  get weighted volume
    stiff_coeff = nu * b_sfe->wdetJ[q];
    for (coder::SizeType b_i{0}; b_i <= m; b_i++) {
      for (coder::SizeType j{0}; j <= m; j++) {
        i1 = b_sfe->geom_dim;
        for (coder::SizeType k{0}; k < i1; k++) {
          elemmat[j + elemmat.size(1) * b_i] =
              elemmat[j + elemmat.size(1) * b_i] +
              stiff_coeff * b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * j] *
                  b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * b_i];
        }
      }
    }
    //  Convection part
    if ((vel.size(0) != 0) && (vel.size(1) != 0)) {
      double vel_coeff_data[3];
      if (vel.size(0) == 1) {
        loop_ub = vel.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          vel_coeff_data[i1] = vel[i1];
        }
      } else {
        i1 = b_sfe->geom_dim;
        for (coder::SizeType k{0}; k < i1; k++) {
          double v;
          coder::SizeType b_m;
          b_m = b_sfe->shapes_sol.size(1);
          v = b_sfe->shapes_sol[b_sfe->shapes_sol.size(1) * q] * vel[k];
          for (coder::SizeType b_i{2}; b_i <= b_m; b_i++) {
            v += b_sfe->shapes_sol[(b_i + b_sfe->shapes_sol.size(1) * q) - 1] *
                 vel[k + vel.size(1) * (b_i - 1)];
          }
          vel_coeff_data[k] = v;
        }
      }
      //  scale with weighted volume
      i1 = b_sfe->geom_dim;
      for (coder::SizeType k{0}; k < i1; k++) {
        vel_coeff_data[k] *= b_sfe->wdetJ[q];
      }
      for (coder::SizeType b_i{0}; b_i <= m; b_i++) {
        double psi;
        psi = b_sfe->shapes_sol[b_i + b_sfe->shapes_sol.size(1) * q];
        for (coder::SizeType j{0}; j <= m; j++) {
          for (coder::SizeType k{0}; k < i1; k++) {
            elemmat[j + elemmat.size(1) * b_i] =
                elemmat[j + elemmat.size(1) * b_i] +
                vel_coeff_data[k] *
                    b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * j] * psi;
          }
        }
      }
    }
  }
}

// sfe_elem_stiff - Compute the element-wise stiffness matrix
void sfe_elem_stiff(SfeObject *b_sfe, const ::coder::array<double, 1U> &nu,
                    const ::coder::array<double, 2U> &vel,
                    coder::SizeType coefftag,
                    ::coder::array<double, 2U> &elemmat)
{
  coder::SizeType i;
  coder::SizeType loop_ub;
  coder::SizeType m;
  m = b_sfe->nnodes[0] - 1;
  elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[0]);
  loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[0];
  for (i = 0; i < loop_ub; i++) {
    elemmat[i] = 0.0;
  }
  //  for each qpoint
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    double stiff_coeff;
    double v;
    coder::SizeType b_m;
    coder::SizeType i1;
    //  initialize gradients at this qpoint
    sfe_init_grad(b_sfe, q + 1);
    //  get weighted volume
    if ((coefftag & 1) == 1) {
      if (nu.size(0) == 1) {
        stiff_coeff = nu[0] * b_sfe->wdetJ[q];
      } else {
        b_m = b_sfe->shapes_sol.size(1);
        v = b_sfe->shapes_sol[b_sfe->shapes_sol.size(1) * q] * nu[0];
        for (coder::SizeType b_i{2}; b_i <= b_m; b_i++) {
          v += b_sfe->shapes_sol[(b_i + b_sfe->shapes_sol.size(1) * q) - 1] *
               nu[b_i - 1];
        }
        stiff_coeff = v * b_sfe->wdetJ[q];
      }
    } else {
      stiff_coeff = nu[0] * b_sfe->wdetJ[q];
    }
    for (coder::SizeType b_i{0}; b_i <= m; b_i++) {
      for (coder::SizeType j{0}; j <= m; j++) {
        i1 = b_sfe->geom_dim;
        for (coder::SizeType k{0}; k < i1; k++) {
          elemmat[j + elemmat.size(1) * b_i] =
              elemmat[j + elemmat.size(1) * b_i] +
              stiff_coeff * b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * j] *
                  b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * b_i];
        }
      }
    }
    //  Convection part
    if ((vel.size(0) != 0) && (vel.size(1) != 0)) {
      double vel_coeff_data[3];
      if ((coefftag >> 1 & 1) == 1) {
        if (vel.size(0) == 1) {
          loop_ub = vel.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            vel_coeff_data[i1] = vel[i1];
          }
        } else {
          i1 = b_sfe->geom_dim;
          for (coder::SizeType k{0}; k < i1; k++) {
            b_m = b_sfe->shapes_sol.size(1);
            v = b_sfe->shapes_sol[b_sfe->shapes_sol.size(1) * q] * vel[k];
            for (coder::SizeType b_i{2}; b_i <= b_m; b_i++) {
              v +=
                  b_sfe->shapes_sol[(b_i + b_sfe->shapes_sol.size(1) * q) - 1] *
                  vel[k + vel.size(1) * (b_i - 1)];
            }
            vel_coeff_data[k] = v;
          }
        }
      } else {
        loop_ub = vel.size(1) * vel.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          vel_coeff_data[i1] = vel[i1];
        }
      }
      //  scale with weighted volume
      i1 = b_sfe->geom_dim;
      for (coder::SizeType k{0}; k < i1; k++) {
        vel_coeff_data[k] *= b_sfe->wdetJ[q];
      }
      for (coder::SizeType b_i{0}; b_i <= m; b_i++) {
        double psi;
        psi = b_sfe->shapes_sol[b_i + b_sfe->shapes_sol.size(1) * q];
        for (coder::SizeType j{0}; j <= m; j++) {
          for (coder::SizeType k{0}; k < i1; k++) {
            elemmat[j + elemmat.size(1) * b_i] =
                elemmat[j + elemmat.size(1) * b_i] +
                vel_coeff_data[k] *
                    b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * j] * psi;
          }
        }
      }
    }
  }
}

double sfe_eval_div(const SfeObject *b_sfe,
                    const ::coder::array<double, 2U> &fs)
{
  double d;
  coder::SizeType i;
  boolean_T cond;
  m2cAssert((b_sfe->grads_sol.size(0) != 0) && (b_sfe->grads_sol.size(1) != 0),
            "miss trial gradient fields");
  if ((b_sfe->nnodes[0] == fs.size(0)) && (fs.size(1) == b_sfe->geom_dim)) {
    cond = true;
  } else {
    cond = false;
  }
  m2cAssert(cond, "");
  d = 0.0;
  i = b_sfe->nnodes[0];
  for (coder::SizeType j{0}; j < i; j++) {
    coder::SizeType i1;
    i1 = b_sfe->geom_dim;
    for (coder::SizeType k{0}; k < i1; k++) {
      d += b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * j] *
           fs[k + fs.size(1) * j];
    }
  }
  return d;
}

// sfe_eval_funcs - Evaluate a set of discrete function values
void sfe_eval_funcs(const SfeObject *b_sfe, coder::SizeType q,
                    const ::coder::array<double, 2U> &fs,
                    ::coder::array<double, 2U> &vals)
{
  coder::SizeType m;
  coder::SizeType nrhs;
  m = b_sfe->shapes_sol.size(1);
  nrhs = fs.size(1) - 1;
  vals.set_size(1, fs.size(1));
  for (coder::SizeType j{0}; j <= nrhs; j++) {
    vals[j] = b_sfe->shapes_sol[b_sfe->shapes_sol.size(1) * (q - 1)] * fs[j];
  }
  for (coder::SizeType i{2}; i <= m; i++) {
    double Ni;
    Ni = b_sfe->shapes_sol[(i + b_sfe->shapes_sol.size(1) * (q - 1)) - 1];
    for (coder::SizeType j{0}; j <= nrhs; j++) {
      vals[j] = vals[j] + Ni * fs[j + fs.size(1) * (i - 1)];
    }
  }
}

// sfe_eval_grads - Evaluate the gradients of a set of function fields
void sfe_eval_grads(const SfeObject *b_sfe,
                    const ::coder::array<double, 2U> &fs,
                    ::coder::array<double, 2U> &grads)
{
  coder::SizeType m;
  m2cAssert((b_sfe->grads_sol.size(0) != 0) && (b_sfe->grads_sol.size(1) != 0),
            "miss trial gradient fields");
  m2cAssert(b_sfe->nnodes[0] == fs.size(0), "");
  m = fs.size(1);
  grads.set_size(b_sfe->geom_dim, fs.size(1));
  for (coder::SizeType i{0}; i < m; i++) {
    coder::SizeType b_i;
    b_i = b_sfe->geom_dim;
    for (coder::SizeType k{0}; k < b_i; k++) {
      double v;
      coder::SizeType i1;
      v = 0.0;
      i1 = b_sfe->nnodes[0];
      for (coder::SizeType j{0}; j < i1; j++) {
        v += b_sfe->grads_sol[k + b_sfe->grads_sol.size(1) * j] *
             fs[i + fs.size(1) * j];
      }
      grads[i + grads.size(1) * k] = v;
    }
  }
}

// sfe_init - Initialize/reinitialize an sfe object for non-boundary element
void sfe_init(SfeObject *b_sfe, const int etypes_data[],
              const coder::SizeType etypes_size[1],
              const ::coder::array<double, 2U> &xs,
              coder::SizeType qd_or_natcoords,
              const ::coder::array<double, 2U> &userquad)
{
  double dv[9];
  double v;
  coder::SizeType a;
  coder::SizeType geom_etype;
  coder::SizeType i;
  coder::SizeType i1;
  coder::SizeType topo_dim;
  boolean_T flag;
  if ((etypes_size[0] < 2) || (etypes_data[1] == 0)) {
    geom_etype = etypes_data[0];
  } else {
    geom_etype = etypes_data[1];
  }
  flag = etypes_data[0] == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (etypes_data[0] >> 5 & 7) == (geom_etype >> 5 & 7);
  }
  m2cAssert(flag, "invalid element combinations");
  if (etypes_data[0] != -1) {
    coder::SizeType shape;
    shape = etypes_data[0] >> 5 & 7;
    topo_dim = ((shape > 0) + (shape > 1)) + (shape > 3);
    //  Geometric dimension
    if (xs.size(1) < topo_dim) {
      m2cErrMsgIdAndTxt("sfe_init:badDim",
                        "geometric dim cannot be smaller than topo dim");
    }
    b_sfe->geom_dim = xs.size(1);
    //  assign geom dimension
    b_sfe->topo_dim = topo_dim;
    //  assign topo dimension
    m2cAssert(iv[geom_etype - 1] == xs.size(0), "nnodes do not match");
    b_sfe->etypes[0] = etypes_data[0];
    b_sfe->etypes[1] = geom_etype;
    //  Get number of nodes per element
    b_sfe->nnodes[0] = iv[etypes_data[0] - 1];
    b_sfe->nnodes[1] = iv[geom_etype - 1];
    //  Set up quadrature
    if (qd_or_natcoords != -1) {
      if (qd_or_natcoords == 0) {
        //  trial+test+nonlinear_geom?1:0
        a = obtain_elemdegree(etypes_data[0]);
        qd_or_natcoords = ((a << 1) + (obtain_elemdegree(geom_etype) > 1)) +
                          (xs.size(1) > topo_dim);
      }
      tabulate_quadratures(etypes_data[0], qd_or_natcoords, b_sfe->cs,
                           b_sfe->ws);
      b_sfe->nqp = b_sfe->ws.size(0);
    } else {
      if ((userquad.size(0) == 0) || (userquad.size(1) == 0)) {
        m2cErrMsgIdAndTxt("sfe_init:missUserQuad",
                          "missing user quadrature data");
      }
      if (userquad.size(1) != topo_dim + 1) {
        m2cErrMsgIdAndTxt("sfe_init:badUserQuadDim",
                          "bad user quadrature data size");
      }
      b_sfe->nqp = userquad.size(0);
      b_sfe->ws.set_size(b_sfe->nqp);
      b_sfe->cs.set_size(b_sfe->nqp, topo_dim);
      i = b_sfe->nqp;
      for (coder::SizeType q{0}; q < i; q++) {
        b_sfe->ws[q] = userquad[userquad.size(1) * q];
        for (coder::SizeType k{0}; k < topo_dim; k++) {
          b_sfe->cs[k + b_sfe->cs.size(1) * q] =
              userquad[(k + userquad.size(1) * q) + 1];
        }
      }
    }
    //  Solution space shape functions & derivs
    tabulate_shapefuncs(etypes_data[0], b_sfe->cs, b_sfe->shapes_geom,
                        b_sfe->derivs_geom);
    a = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
    b_sfe->shapes_sol.set_size(b_sfe->shapes_geom.size(0),
                               b_sfe->shapes_geom.size(1));
    for (i = 0; i < a; i++) {
      b_sfe->shapes_sol[i] = b_sfe->shapes_geom[i];
    }
    a = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
        b_sfe->derivs_geom.size(0);
    b_sfe->derivs_sol.set_size(b_sfe->derivs_geom.size(0),
                               b_sfe->derivs_geom.size(1),
                               b_sfe->derivs_geom.size(2));
    for (i = 0; i < a; i++) {
      b_sfe->derivs_sol[i] = b_sfe->derivs_geom[i];
    }
    //  Geometry space shape functions & derivs
    if (etypes_data[0] != geom_etype) {
      tabulate_shapefuncs(geom_etype, b_sfe->cs, b_sfe->shapes_geom,
                          b_sfe->derivs_geom);
    }
  } else {
    if ((b_sfe->etypes[0] > 0) && (iv[b_sfe->etypes[0] - 1] != 0)) {
      flag = true;
    } else {
      flag = false;
    }
    m2cAssert(flag, "");
  }
  //  potentially skip re-tabulating
  b_sfe->cs_phy.set_size(b_sfe->nqp, xs.size(1));
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    i1 = xs.size(1);
    for (coder::SizeType k{0}; k < i1; k++) {
      coder::SizeType m;
      m = b_sfe->shapes_geom.size(1);
      v = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[k];
      for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
        v += b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1] *
             xs[k + xs.size(1) * (b_i - 1)];
      }
      b_sfe->cs_phy[k + b_sfe->cs_phy.size(1) * q] = v;
    }
  }
  //  Compute Jacobian
  b_sfe->wdetJ.set_size(b_sfe->nqp);
  if ((geom_etype == 68) || (geom_etype == 132) || (geom_etype == 36)) {
    double d;
    coder::SizeType geom_dim;
    coder::SizeType n;
    //  A single Jacobian matrix (transpose) is needed for simplex elements
    geom_dim = xs.size(1);
    topo_dim = b_sfe->derivs_geom.size(2);
    std::memset(&dv[0], 0, 9U * sizeof(double));
    n = xs.size(0);
    for (coder::SizeType k{0}; k < n; k++) {
      for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
        for (coder::SizeType j{0}; j < geom_dim; j++) {
          i = j + 3 * b_i;
          dv[i] += xs[j + xs.size(1) * k] *
                   b_sfe->derivs_geom[b_i + b_sfe->derivs_geom.size(2) * k];
        }
      }
    }
    if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
      if (xs.size(1) == 1) {
        d = dv[0];
      } else if (xs.size(1) == 2) {
        d = dv[0] * dv[4] - dv[1] * dv[3];
      } else {
        d = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
             dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
            dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
      }
    } else if (b_sfe->derivs_geom.size(2) == 1) {
      d = dv[0] * dv[0] + dv[1] * dv[1];
      if (xs.size(1) == 3) {
        d += dv[2] * dv[2];
      }
      d = std::sqrt(d);
    } else {
      //  must be 2x3
      dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
      dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
      dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
      d = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
    }
    b_sfe->jacTs.set_size(3, 3);
    for (i = 0; i < 9; i++) {
      b_sfe->jacTs[i] = dv[i];
    }
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      b_sfe->wdetJ[q] = d * b_sfe->ws[q];
    }
  } else {
    //  Super-parametric
    a = b_sfe->nqp * 3;
    b_sfe->jacTs.set_size(a, 3);
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      coder::SizeType geom_dim;
      coder::SizeType n;
      coder::SizeType y;
      y = q * 3;
      geom_dim = xs.size(1);
      topo_dim = b_sfe->derivs_geom.size(2);
      std::memset(&dv[0], 0, 9U * sizeof(double));
      n = xs.size(0);
      for (coder::SizeType k{0}; k < n; k++) {
        for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
          for (coder::SizeType j{0}; j < geom_dim; j++) {
            i1 = j + 3 * b_i;
            dv[i1] +=
                xs[j + xs.size(1) * k] *
                b_sfe->derivs_geom[(b_i + b_sfe->derivs_geom.size(2) * k) +
                                   b_sfe->derivs_geom.size(2) *
                                       b_sfe->derivs_geom.size(1) * q];
          }
        }
      }
      if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
        if (xs.size(1) == 1) {
          v = dv[0];
        } else if (xs.size(1) == 2) {
          v = dv[0] * dv[4] - dv[1] * dv[3];
        } else {
          v = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
               dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
              dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
        }
      } else if (b_sfe->derivs_geom.size(2) == 1) {
        v = dv[0] * dv[0] + dv[1] * dv[1];
        if (xs.size(1) == 3) {
          v += dv[2] * dv[2];
        }
        v = std::sqrt(v);
      } else {
        //  must be 2x3
        dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
        dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
        dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
        v = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
      }
      for (i1 = 0; i1 < 3; i1++) {
        a = i1 + y;
        b_sfe->jacTs[3 * a] = dv[3 * i1];
        b_sfe->jacTs[3 * a + 1] = dv[3 * i1 + 1];
        b_sfe->jacTs[3 * a + 2] = dv[3 * i1 + 2];
      }
      b_sfe->wdetJ[q] = v;
      b_sfe->wdetJ[q] = b_sfe->wdetJ[q] * b_sfe->ws[q];
    }
  }
}

// sfe_init - Initialize/reinitialize an sfe object for non-boundary element
void sfe_init(SfeObject *b_sfe, const int etypes_data[],
              const coder::SizeType etypes_size[1],
              const ::coder::array<double, 2U> &xs,
              coder::SizeType qd_or_natcoords)
{
  double dv[9];
  double v;
  coder::SizeType a;
  coder::SizeType geom_etype;
  coder::SizeType i;
  coder::SizeType i1;
  coder::SizeType topo_dim;
  boolean_T flag;
  if ((etypes_size[0] < 2) || (etypes_data[1] == 0)) {
    geom_etype = etypes_data[0];
  } else {
    geom_etype = etypes_data[1];
  }
  flag = etypes_data[0] == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (etypes_data[0] >> 5 & 7) == (geom_etype >> 5 & 7);
  }
  m2cAssert(flag, "invalid element combinations");
  if (etypes_data[0] != -1) {
    coder::SizeType shape;
    shape = etypes_data[0] >> 5 & 7;
    topo_dim = ((shape > 0) + (shape > 1)) + (shape > 3);
    //  Geometric dimension
    if (xs.size(1) < topo_dim) {
      m2cErrMsgIdAndTxt("sfe_init:badDim",
                        "geometric dim cannot be smaller than topo dim");
    }
    b_sfe->geom_dim = xs.size(1);
    //  assign geom dimension
    b_sfe->topo_dim = topo_dim;
    //  assign topo dimension
    m2cAssert(iv[geom_etype - 1] == xs.size(0), "nnodes do not match");
    b_sfe->etypes[0] = etypes_data[0];
    b_sfe->etypes[1] = geom_etype;
    //  Get number of nodes per element
    b_sfe->nnodes[0] = iv[etypes_data[0] - 1];
    b_sfe->nnodes[1] = iv[geom_etype - 1];
    //  Set up quadrature
    if (qd_or_natcoords != -1) {
      if (qd_or_natcoords == 0) {
        //  trial+test+nonlinear_geom?1:0
        a = obtain_elemdegree(etypes_data[0]);
        qd_or_natcoords = ((a << 1) + (obtain_elemdegree(geom_etype) > 1)) +
                          (xs.size(1) > topo_dim);
      }
      tabulate_quadratures(etypes_data[0], qd_or_natcoords, b_sfe->cs,
                           b_sfe->ws);
      b_sfe->nqp = b_sfe->ws.size(0);
    } else {
      m2cErrMsgIdAndTxt("sfe_init:missUserQuad",
                        "missing user quadrature data");
      m2cErrMsgIdAndTxt("sfe_init:badUserQuadDim",
                        "bad user quadrature data size");
      b_sfe->nqp = 0;
      b_sfe->ws.set_size(b_sfe->nqp);
      b_sfe->cs.set_size(b_sfe->nqp, topo_dim);
    }
    //  Solution space shape functions & derivs
    tabulate_shapefuncs(etypes_data[0], b_sfe->cs, b_sfe->shapes_geom,
                        b_sfe->derivs_geom);
    a = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
    b_sfe->shapes_sol.set_size(b_sfe->shapes_geom.size(0),
                               b_sfe->shapes_geom.size(1));
    for (i = 0; i < a; i++) {
      b_sfe->shapes_sol[i] = b_sfe->shapes_geom[i];
    }
    a = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
        b_sfe->derivs_geom.size(0);
    b_sfe->derivs_sol.set_size(b_sfe->derivs_geom.size(0),
                               b_sfe->derivs_geom.size(1),
                               b_sfe->derivs_geom.size(2));
    for (i = 0; i < a; i++) {
      b_sfe->derivs_sol[i] = b_sfe->derivs_geom[i];
    }
    //  Geometry space shape functions & derivs
    if (etypes_data[0] != geom_etype) {
      tabulate_shapefuncs(geom_etype, b_sfe->cs, b_sfe->shapes_geom,
                          b_sfe->derivs_geom);
    }
  } else {
    if ((b_sfe->etypes[0] > 0) && (iv[b_sfe->etypes[0] - 1] != 0)) {
      flag = true;
    } else {
      flag = false;
    }
    m2cAssert(flag, "");
  }
  //  potentially skip re-tabulating
  b_sfe->cs_phy.set_size(b_sfe->nqp, xs.size(1));
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    i1 = xs.size(1);
    for (coder::SizeType k{0}; k < i1; k++) {
      coder::SizeType m;
      m = b_sfe->shapes_geom.size(1);
      v = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[k];
      for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
        v += b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1] *
             xs[k + xs.size(1) * (b_i - 1)];
      }
      b_sfe->cs_phy[k + b_sfe->cs_phy.size(1) * q] = v;
    }
  }
  //  Compute Jacobian
  b_sfe->wdetJ.set_size(b_sfe->nqp);
  if ((geom_etype == 68) || (geom_etype == 132) || (geom_etype == 36)) {
    double d;
    coder::SizeType geom_dim;
    coder::SizeType n;
    //  A single Jacobian matrix (transpose) is needed for simplex elements
    geom_dim = xs.size(1);
    topo_dim = b_sfe->derivs_geom.size(2);
    std::memset(&dv[0], 0, 9U * sizeof(double));
    n = xs.size(0);
    for (coder::SizeType k{0}; k < n; k++) {
      for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
        for (coder::SizeType j{0}; j < geom_dim; j++) {
          i = j + 3 * b_i;
          dv[i] += xs[j + xs.size(1) * k] *
                   b_sfe->derivs_geom[b_i + b_sfe->derivs_geom.size(2) * k];
        }
      }
    }
    if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
      if (xs.size(1) == 1) {
        d = dv[0];
      } else if (xs.size(1) == 2) {
        d = dv[0] * dv[4] - dv[1] * dv[3];
      } else {
        d = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
             dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
            dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
      }
    } else if (b_sfe->derivs_geom.size(2) == 1) {
      d = dv[0] * dv[0] + dv[1] * dv[1];
      if (xs.size(1) == 3) {
        d += dv[2] * dv[2];
      }
      d = std::sqrt(d);
    } else {
      //  must be 2x3
      dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
      dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
      dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
      d = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
    }
    b_sfe->jacTs.set_size(3, 3);
    for (i = 0; i < 9; i++) {
      b_sfe->jacTs[i] = dv[i];
    }
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      b_sfe->wdetJ[q] = d * b_sfe->ws[q];
    }
  } else {
    //  Super-parametric
    a = b_sfe->nqp * 3;
    b_sfe->jacTs.set_size(a, 3);
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      coder::SizeType geom_dim;
      coder::SizeType n;
      coder::SizeType y;
      y = q * 3;
      geom_dim = xs.size(1);
      topo_dim = b_sfe->derivs_geom.size(2);
      std::memset(&dv[0], 0, 9U * sizeof(double));
      n = xs.size(0);
      for (coder::SizeType k{0}; k < n; k++) {
        for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
          for (coder::SizeType j{0}; j < geom_dim; j++) {
            i1 = j + 3 * b_i;
            dv[i1] +=
                xs[j + xs.size(1) * k] *
                b_sfe->derivs_geom[(b_i + b_sfe->derivs_geom.size(2) * k) +
                                   b_sfe->derivs_geom.size(2) *
                                       b_sfe->derivs_geom.size(1) * q];
          }
        }
      }
      if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
        if (xs.size(1) == 1) {
          v = dv[0];
        } else if (xs.size(1) == 2) {
          v = dv[0] * dv[4] - dv[1] * dv[3];
        } else {
          v = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
               dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
              dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
        }
      } else if (b_sfe->derivs_geom.size(2) == 1) {
        v = dv[0] * dv[0] + dv[1] * dv[1];
        if (xs.size(1) == 3) {
          v += dv[2] * dv[2];
        }
        v = std::sqrt(v);
      } else {
        //  must be 2x3
        dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
        dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
        dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
        v = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
      }
      for (i1 = 0; i1 < 3; i1++) {
        a = i1 + y;
        b_sfe->jacTs[3 * a] = dv[3 * i1];
        b_sfe->jacTs[3 * a + 1] = dv[3 * i1 + 1];
        b_sfe->jacTs[3 * a + 2] = dv[3 * i1 + 2];
      }
      b_sfe->wdetJ[q] = v;
      b_sfe->wdetJ[q] = b_sfe->wdetJ[q] * b_sfe->ws[q];
    }
  }
}

// sfe_init - Initialize/reinitialize an sfe object for non-boundary element
void sfe_init(SfeObject *b_sfe, const int etypes_data[],
              const coder::SizeType etypes_size[1],
              const ::coder::array<double, 2U> &xs)
{
  double dv[9];
  double v;
  coder::SizeType a;
  coder::SizeType geom_etype;
  coder::SizeType i;
  coder::SizeType i1;
  coder::SizeType topo_dim;
  boolean_T flag;
  if ((etypes_size[0] < 2) || (etypes_data[1] == 0)) {
    geom_etype = etypes_data[0];
  } else {
    geom_etype = etypes_data[1];
  }
  flag = etypes_data[0] == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (etypes_data[0] >> 5 & 7) == (geom_etype >> 5 & 7);
  }
  m2cAssert(flag, "invalid element combinations");
  if (etypes_data[0] != -1) {
    coder::SizeType qd_or_natcoords;
    coder::SizeType shape;
    shape = etypes_data[0] >> 5 & 7;
    topo_dim = ((shape > 0) + (shape > 1)) + (shape > 3);
    //  Geometric dimension
    if (xs.size(1) < topo_dim) {
      m2cErrMsgIdAndTxt("sfe_init:badDim",
                        "geometric dim cannot be smaller than topo dim");
    }
    b_sfe->geom_dim = xs.size(1);
    //  assign geom dimension
    b_sfe->topo_dim = topo_dim;
    //  assign topo dimension
    m2cAssert(iv[geom_etype - 1] == xs.size(0), "nnodes do not match");
    b_sfe->etypes[0] = etypes_data[0];
    b_sfe->etypes[1] = geom_etype;
    //  Get number of nodes per element
    b_sfe->nnodes[0] = iv[etypes_data[0] - 1];
    b_sfe->nnodes[1] = iv[geom_etype - 1];
    //  Set up quadrature
    a = obtain_elemdegree(etypes_data[0]);
    qd_or_natcoords = ((a << 1) + (obtain_elemdegree(geom_etype) > 1)) +
                      (xs.size(1) > topo_dim);
    tabulate_quadratures(etypes_data[0], qd_or_natcoords, b_sfe->cs, b_sfe->ws);
    b_sfe->nqp = b_sfe->ws.size(0);
    //  Solution space shape functions & derivs
    tabulate_shapefuncs(etypes_data[0], b_sfe->cs, b_sfe->shapes_geom,
                        b_sfe->derivs_geom);
    a = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
    b_sfe->shapes_sol.set_size(b_sfe->shapes_geom.size(0),
                               b_sfe->shapes_geom.size(1));
    for (i = 0; i < a; i++) {
      b_sfe->shapes_sol[i] = b_sfe->shapes_geom[i];
    }
    a = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
        b_sfe->derivs_geom.size(0);
    b_sfe->derivs_sol.set_size(b_sfe->derivs_geom.size(0),
                               b_sfe->derivs_geom.size(1),
                               b_sfe->derivs_geom.size(2));
    for (i = 0; i < a; i++) {
      b_sfe->derivs_sol[i] = b_sfe->derivs_geom[i];
    }
    //  Geometry space shape functions & derivs
    if (etypes_data[0] != geom_etype) {
      tabulate_shapefuncs(geom_etype, b_sfe->cs, b_sfe->shapes_geom,
                          b_sfe->derivs_geom);
    }
  } else {
    if ((b_sfe->etypes[0] > 0) && (iv[b_sfe->etypes[0] - 1] != 0)) {
      flag = true;
    } else {
      flag = false;
    }
    m2cAssert(flag, "");
  }
  //  potentially skip re-tabulating
  b_sfe->cs_phy.set_size(b_sfe->nqp, xs.size(1));
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    i1 = xs.size(1);
    for (coder::SizeType k{0}; k < i1; k++) {
      coder::SizeType m;
      m = b_sfe->shapes_geom.size(1);
      v = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[k];
      for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
        v += b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1] *
             xs[k + xs.size(1) * (b_i - 1)];
      }
      b_sfe->cs_phy[k + b_sfe->cs_phy.size(1) * q] = v;
    }
  }
  //  Compute Jacobian
  b_sfe->wdetJ.set_size(b_sfe->nqp);
  if ((geom_etype == 68) || (geom_etype == 132) || (geom_etype == 36)) {
    double d;
    coder::SizeType geom_dim;
    coder::SizeType n;
    //  A single Jacobian matrix (transpose) is needed for simplex elements
    geom_dim = xs.size(1);
    topo_dim = b_sfe->derivs_geom.size(2);
    std::memset(&dv[0], 0, 9U * sizeof(double));
    n = xs.size(0);
    for (coder::SizeType k{0}; k < n; k++) {
      for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
        for (coder::SizeType j{0}; j < geom_dim; j++) {
          i = j + 3 * b_i;
          dv[i] += xs[j + xs.size(1) * k] *
                   b_sfe->derivs_geom[b_i + b_sfe->derivs_geom.size(2) * k];
        }
      }
    }
    if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
      if (xs.size(1) == 1) {
        d = dv[0];
      } else if (xs.size(1) == 2) {
        d = dv[0] * dv[4] - dv[1] * dv[3];
      } else {
        d = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
             dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
            dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
      }
    } else if (b_sfe->derivs_geom.size(2) == 1) {
      d = dv[0] * dv[0] + dv[1] * dv[1];
      if (xs.size(1) == 3) {
        d += dv[2] * dv[2];
      }
      d = std::sqrt(d);
    } else {
      //  must be 2x3
      dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
      dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
      dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
      d = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
    }
    b_sfe->jacTs.set_size(3, 3);
    for (i = 0; i < 9; i++) {
      b_sfe->jacTs[i] = dv[i];
    }
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      b_sfe->wdetJ[q] = d * b_sfe->ws[q];
    }
  } else {
    //  Super-parametric
    a = b_sfe->nqp * 3;
    b_sfe->jacTs.set_size(a, 3);
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      coder::SizeType geom_dim;
      coder::SizeType n;
      coder::SizeType y;
      y = q * 3;
      geom_dim = xs.size(1);
      topo_dim = b_sfe->derivs_geom.size(2);
      std::memset(&dv[0], 0, 9U * sizeof(double));
      n = xs.size(0);
      for (coder::SizeType k{0}; k < n; k++) {
        for (coder::SizeType b_i{0}; b_i < topo_dim; b_i++) {
          for (coder::SizeType j{0}; j < geom_dim; j++) {
            i1 = j + 3 * b_i;
            dv[i1] +=
                xs[j + xs.size(1) * k] *
                b_sfe->derivs_geom[(b_i + b_sfe->derivs_geom.size(2) * k) +
                                   b_sfe->derivs_geom.size(2) *
                                       b_sfe->derivs_geom.size(1) * q];
          }
        }
      }
      if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
        if (xs.size(1) == 1) {
          v = dv[0];
        } else if (xs.size(1) == 2) {
          v = dv[0] * dv[4] - dv[1] * dv[3];
        } else {
          v = (dv[2] * (dv[3] * dv[7] - dv[4] * dv[6]) +
               dv[5] * (dv[1] * dv[6] - dv[0] * dv[7])) +
              dv[8] * (dv[0] * dv[4] - dv[1] * dv[3]);
        }
      } else if (b_sfe->derivs_geom.size(2) == 1) {
        v = dv[0] * dv[0] + dv[1] * dv[1];
        if (xs.size(1) == 3) {
          v += dv[2] * dv[2];
        }
        v = std::sqrt(v);
      } else {
        //  must be 2x3
        dv[6] = dv[1] * dv[5] - dv[2] * dv[4];
        dv[7] = dv[2] * dv[3] - dv[0] * dv[5];
        dv[8] = dv[0] * dv[4] - dv[1] * dv[3];
        v = std::sqrt((dv[6] * dv[6] + dv[7] * dv[7]) + dv[8] * dv[8]);
      }
      for (i1 = 0; i1 < 3; i1++) {
        a = i1 + y;
        b_sfe->jacTs[3 * a] = dv[3 * i1];
        b_sfe->jacTs[3 * a + 1] = dv[3 * i1 + 1];
        b_sfe->jacTs[3 * a + 2] = dv[3 * i1 + 2];
      }
      b_sfe->wdetJ[q] = v;
      b_sfe->wdetJ[q] = b_sfe->wdetJ[q] * b_sfe->ws[q];
    }
  }
}

// sfe_init - Initialize/reinitialize an sfe object for non-boundary element
void sfe_init(SfeObject *b_sfe, const int etypes_data[],
              const coder::SizeType etypes_size[1],
              const ::coder::array<double, 2U> &xs,
              const ::coder::array<double, 2U> &qd_or_natcoords)
{
  coder::SizeType geom_etype;
  coder::SizeType i;
  coder::SizeType sfe_idx_0;
  boolean_T flag;
  if ((etypes_size[0] < 2) || (etypes_data[1] == 0)) {
    geom_etype = etypes_data[0];
  } else {
    geom_etype = etypes_data[1];
  }
  flag = etypes_data[0] == geom_etype;
  if (!flag) {
    //  then the shapes must match
    flag = (etypes_data[0] >> 5 & 7) == (geom_etype >> 5 & 7);
  }
  m2cAssert(flag, "invalid element combinations");
  if (etypes_data[0] != -1) {
    coder::SizeType shape;
    coder::SizeType topo_dim;
    shape = etypes_data[0] >> 5 & 7;
    topo_dim = ((shape > 0) + (shape > 1)) + (shape > 3);
    //  Geometric dimension
    if (xs.size(1) < topo_dim) {
      m2cErrMsgIdAndTxt("sfe_init:badDim",
                        "geometric dim cannot be smaller than topo dim");
    }
    b_sfe->geom_dim = xs.size(1);
    //  assign geom dimension
    b_sfe->topo_dim = topo_dim;
    //  assign topo dimension
    m2cAssert(iv[geom_etype - 1] == xs.size(0), "nnodes do not match");
    b_sfe->etypes[0] = etypes_data[0];
    b_sfe->etypes[1] = geom_etype;
    //  Get number of nodes per element
    b_sfe->nnodes[0] = iv[etypes_data[0] - 1];
    b_sfe->nnodes[1] = iv[geom_etype - 1];
    //  User-input natural coordinates
    b_sfe->nqp = qd_or_natcoords.size(0);
    sfe_idx_0 = b_sfe->nqp;
    b_sfe->ws.set_size(sfe_idx_0);
    for (i = 0; i < sfe_idx_0; i++) {
      b_sfe->ws[i] = 1.0;
    }
    //  user ones for dummy quad weights
    b_sfe->cs.set_size(b_sfe->nqp, topo_dim);
    i = b_sfe->nqp;
    for (coder::SizeType q{0}; q < i; q++) {
      for (coder::SizeType k{0}; k < topo_dim; k++) {
        b_sfe->cs[k + b_sfe->cs.size(1) * q] =
            qd_or_natcoords[k + qd_or_natcoords.size(1) * q];
      }
    }
    //  Solution space shape functions & derivs
    tabulate_shapefuncs(etypes_data[0], b_sfe->cs, b_sfe->shapes_geom,
                        b_sfe->derivs_geom);
    sfe_idx_0 = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
    b_sfe->shapes_sol.set_size(b_sfe->shapes_geom.size(0),
                               b_sfe->shapes_geom.size(1));
    for (i = 0; i < sfe_idx_0; i++) {
      b_sfe->shapes_sol[i] = b_sfe->shapes_geom[i];
    }
    sfe_idx_0 = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
                b_sfe->derivs_geom.size(0);
    b_sfe->derivs_sol.set_size(b_sfe->derivs_geom.size(0),
                               b_sfe->derivs_geom.size(1),
                               b_sfe->derivs_geom.size(2));
    for (i = 0; i < sfe_idx_0; i++) {
      b_sfe->derivs_sol[i] = b_sfe->derivs_geom[i];
    }
    //  Geometry space shape functions & derivs
    if (etypes_data[0] != geom_etype) {
      tabulate_shapefuncs(geom_etype, b_sfe->cs, b_sfe->shapes_geom,
                          b_sfe->derivs_geom);
    }
  } else {
    if ((b_sfe->etypes[0] > 0) && (iv[b_sfe->etypes[0] - 1] != 0)) {
      flag = true;
    } else {
      flag = false;
    }
    m2cAssert(flag, "");
  }
  //  potentially skip re-tabulating
  b_sfe->cs_phy.set_size(b_sfe->nqp, xs.size(1));
  i = b_sfe->nqp;
  for (coder::SizeType q{0}; q < i; q++) {
    sfe_idx_0 = xs.size(1);
    for (coder::SizeType k{0}; k < sfe_idx_0; k++) {
      double v;
      coder::SizeType m;
      m = b_sfe->shapes_geom.size(1);
      v = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[k];
      for (coder::SizeType b_i{2}; b_i <= m; b_i++) {
        v += b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1] *
             xs[k + xs.size(1) * (b_i - 1)];
      }
      b_sfe->cs_phy[k + b_sfe->cs_phy.size(1) * q] = v;
    }
  }
  //  Compute Jacobian
}

void sfe_init_grad1(SfeObject *b_sfe, coder::SizeType q)
{
  double Jt[9];
  coder::SizeType dim;
  coder::SizeType n;
  m2cAssert(b_sfe->geom_dim == b_sfe->topo_dim, "not implemented");
  //  for now
  if ((q <= 0) || (q > b_sfe->nqp)) {
    m2cErrMsgIdAndTxt("sfe_init_grad:badRange",
                      "out of bound of qpoint range %d", (int)q);
  }
  if (b_sfe->jacTs.size(0) == 3) {
    for (coder::SizeType i{0}; i < 3; i++) {
      Jt[3 * i] = b_sfe->jacTs[3 * i];
      Jt[3 * i + 1] = b_sfe->jacTs[3 * i + 1];
      Jt[3 * i + 2] = b_sfe->jacTs[3 * i + 2];
    }
  } else {
    coder::SizeType y;
    y = (q - 1) * 3;
    for (coder::SizeType i{0}; i < 3; i++) {
      coder::SizeType Jt_tmp;
      Jt_tmp = i + y;
      Jt[3 * i] = b_sfe->jacTs[3 * Jt_tmp];
      Jt[3 * i + 1] = b_sfe->jacTs[3 * Jt_tmp + 1];
      Jt[3 * i + 2] = b_sfe->jacTs[3 * Jt_tmp + 2];
    }
  }
  dim = b_sfe->derivs_sol.size(2);
  n = b_sfe->derivs_sol.size(1);
  b_sfe->grads_sol.set_size(b_sfe->derivs_sol.size(1),
                            b_sfe->derivs_sol.size(2));
  for (coder::SizeType b_i{0}; b_i < n; b_i++) {
    for (coder::SizeType d{0}; d < dim; d++) {
      b_sfe->grads_sol[d + b_sfe->grads_sol.size(1) * b_i] =
          b_sfe->derivs_sol[(d + b_sfe->derivs_sol.size(2) * b_i) +
                            b_sfe->derivs_sol.size(2) *
                                b_sfe->derivs_sol.size(1) * (q - 1)];
    }
  }
  if (b_sfe->geom_dim == b_sfe->topo_dim) {
    boolean_T info;
    info = solve_sq(Jt, b_sfe->geom_dim, b_sfe->grads_sol);
    m2cAssert(!info, "singular Jacobian");
  }
}

} // namespace sfe

// End of code generation (sfe_internal.cpp)
