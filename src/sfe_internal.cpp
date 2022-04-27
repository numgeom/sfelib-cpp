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
#include "omp.h"
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

} // namespace sfe

// Function Declarations
namespace sfe {
static inline void bar_quadrules(coder::SizeType degree,
                                 ::coder::array<double, 2U> &cs,
                                 ::coder::array<double, 1U> &ws);

static inline void hexa_125(double xi, double eta, double zeta,
                            double sfvals[125], double sdvals[375]);

static inline void hexa_216(double xi, double eta, double zeta,
                            double sfvals[216], double sdvals[648]);

static inline void hexa_64(double xi, double eta, double zeta,
                           double sfvals[64], double sdvals[192]);

static inline void hexa_gl_125(double xi, double eta, double zeta,
                               double sfvals[125], double sdvals[375]);

static inline void hexa_gl_216(double xi, double eta, double zeta,
                               double sfvals[216], double sdvals[648]);

static inline void hexa_gl_64(double xi, double eta, double zeta,
                              double sfvals[64], double sdvals[192]);

static inline void obtain_facets(coder::SizeType etype, signed char facetid,
                                 unsigned char *ret, short lids_data[],
                                 coder::SizeType *lids_size);

static inline unsigned char obtain_facets(coder::SizeType etype);

static inline unsigned char obtain_facets(coder::SizeType etype,
                                          signed char facetid);

static inline void prism_126(double xi, double eta, double zeta,
                             double sfvals[126], double sdvals[378]);

static inline void prism_40(double xi, double eta, double zeta,
                            double sfvals[40], double sdvals[120]);

static inline void prism_75(double xi, double eta, double zeta,
                            double sfvals[75], double sdvals[225]);

static inline void prism_gl_126(double xi, double eta, double zeta,
                                double sfvals[126], double sdvals[378]);

static inline void prism_gl_40(double xi, double eta, double zeta,
                               double sfvals[40], double sdvals[120]);

static inline void prism_gl_75(double xi, double eta, double zeta,
                               double sfvals[75], double sdvals[225]);

static inline void pyra_30(double xi, double eta, double zeta,
                           double sfvals[30], double sdvals[90]);

static inline void pyra_55(double xi, double eta, double zeta,
                           double sfvals[55], double sdvals[165]);

static inline void pyra_gl_30(double xi, double eta, double zeta,
                              double sfvals[30], double sdvals[90]);

static inline void pyra_gl_55(double xi, double eta, double zeta,
                              double sfvals[55], double sdvals[165]);

static inline void pyra_quadrules(coder::SizeType degree,
                                  ::coder::array<double, 2U> &cs,
                                  ::coder::array<double, 1U> &ws);

static inline void quad_25(double xi, double eta, double sfvals[25],
                           double sdvals[50]);

static inline void quad_36(double xi, double eta, double sfvals[36],
                           double sdvals[72]);

static inline void quad_49(double xi, double eta, double sfvals[49],
                           double sdvals[98]);

static inline void quad_gl_25(double xi, double eta, double sfvals[25],
                              double sdvals[50]);

static inline void quad_gl_36(double xi, double eta, double sfvals[36],
                              double sdvals[72]);

static inline void quad_gl_49(double xi, double eta, double sfvals[49],
                              double sdvals[98]);

static inline void sfe1_tabulate_shapefuncs(
    coder::SizeType etype, const ::coder::array<double, 2U> &cs,
    ::coder::array<double, 2U> &sfvals, ::coder::array<double, 3U> &sdvals);

static inline void sfe2_tabulate_equi_quad(coder::SizeType etype,
                                           const ::coder::array<double, 2U> &cs,
                                           ::coder::array<double, 2U> &sfvals,
                                           ::coder::array<double, 3U> &sdvals);

static inline void sfe2_tabulate_equi_tri(coder::SizeType etype,
                                          const ::coder::array<double, 2U> &cs,
                                          ::coder::array<double, 2U> &sfvals,
                                          ::coder::array<double, 3U> &sdvals);

static inline void sfe2_tabulate_fek_tri(coder::SizeType etype,
                                         const ::coder::array<double, 2U> &cs,
                                         ::coder::array<double, 2U> &sfvals,
                                         ::coder::array<double, 3U> &sdvals);

static inline void sfe2_tabulate_gl_quad(coder::SizeType etype,
                                         const ::coder::array<double, 2U> &cs,
                                         ::coder::array<double, 2U> &sfvals,
                                         ::coder::array<double, 3U> &sdvals);

static inline void sfe2_tabulate_gl_tri(coder::SizeType etype,
                                        const ::coder::array<double, 2U> &cs,
                                        ::coder::array<double, 2U> &sfvals,
                                        ::coder::array<double, 3U> &sdvals);

static inline void sfe2_tabulate_shapefuncs(
    coder::SizeType etype, const ::coder::array<double, 2U> &cs,
    ::coder::array<double, 2U> &sfvals, ::coder::array<double, 3U> &sdvals);

static inline void sfe3_tabulate_equi_hexa(coder::SizeType etype,
                                           const ::coder::array<double, 2U> &cs,
                                           ::coder::array<double, 2U> &sfvals,
                                           ::coder::array<double, 3U> &sdvals);

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

static inline void sfe3_tabulate_gl_hexa(coder::SizeType etype,
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

static inline void sfe3_tabulate_gl_tet(coder::SizeType etype,
                                        const ::coder::array<double, 2U> &cs,
                                        ::coder::array<double, 2U> &sfvals,
                                        ::coder::array<double, 3U> &sdvals);

static inline void sfe3_tabulate_shapefuncs(
    coder::SizeType etype, const ::coder::array<double, 2U> &cs,
    ::coder::array<double, 2U> &sfvals, ::coder::array<double, 3U> &sdvals);

static inline void sfe_init(SfeObject *b_sfe, const int etypes_data[],
                            coder::SizeType etypes_size,
                            const ::coder::array<double, 2U> &xs,
                            const ::coder::array<double, 2U> &qd_or_natcoords);

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

static inline void tet_20(double xi, double eta, double zeta, double sfvals[20],
                          double sdvals[60]);

static inline void tet_35(double xi, double eta, double zeta, double sfvals[35],
                          double sdvals[105]);

static inline void tet_56(double xi, double eta, double zeta, double sfvals[56],
                          double sdvals[168]);

static inline void tet_gl_20(double xi, double eta, double zeta,
                             double sfvals[20], double sdvals[60]);

static inline void tet_gl_35(double xi, double eta, double zeta,
                             double sfvals[35], double sdvals[105]);

static inline void tri_21(double xi, double eta, double sfvals[21],
                          double sdvals[42]);

static inline void tri_28(double xi, double eta, double sfvals[28],
                          double sdvals[56]);

static inline void tri_fek_15(double xi, double eta, double sfvals[15],
                              double sdvals[30]);

static inline void tri_fek_21(double xi, double eta, double sfvals[21],
                              double sdvals[42]);

static inline void tri_fek_28(double xi, double eta, double sfvals[28],
                              double sdvals[56]);

static inline void tri_gl_21(double xi, double eta, double sfvals[21],
                             double sdvals[42]);

static inline void tri_quadrules(coder::SizeType degree,
                                 ::coder::array<double, 2U> &cs,
                                 ::coder::array<double, 1U> &ws);

} // namespace sfe

// Function Definitions
namespace sfe {
//  bar_quadrules - Obtain quadrature points and weights of a bar element.
static void bar_quadrules(coder::SizeType degree,
                          ::coder::array<double, 2U> &cs,
                          ::coder::array<double, 1U> &ws)
{
  if (degree <= 1) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::bar_deg1_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg1_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 3) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::bar_deg3_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg3_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 5) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::bar_deg5_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg5_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 7) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::bar_deg7_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg7_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 9) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::bar_deg9_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg9_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 11) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::bar_deg11_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg11_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 13) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::bar_deg13_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg13_qrule(&cs[0], &(ws.data())[0]);
  } else {
    coder::SizeType nqp;
    if (degree > 15) {
      m2cWarnMsgIdAndTxt("bar_quadrules:UnsupportedDegree",
                         "Only support up to degree 15");
    }
    nqp = ::sfe_qrules::bar_deg15_qrule();
    cs.set_size(nqp, 1);
    ws.set_size(nqp);
    ::sfe_qrules::bar_deg15_qrule(&cs[0], &(ws.data())[0]);
  }
}

// hexa_125 - Triquartic hexahedral element with equidistant points
static inline void hexa_125(double xi, double eta, double zeta,
                            double sfvals[125], double sdvals[375])
{
  ::sfe_sfuncs::hexa_125_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// hexa_216 - Triquintic hexahedral element with equidistant points
static inline void hexa_216(double xi, double eta, double zeta,
                            double sfvals[216], double sdvals[648])
{
  ::sfe_sfuncs::hexa_216_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// hexa_64 - Tricubic hexahedral element with equidistant nodes
static inline void hexa_64(double xi, double eta, double zeta,
                           double sfvals[64], double sdvals[192])
{
  ::sfe_sfuncs::hexa_64_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// hexa_gl_125 - Triquartic hexahedral element with Gauss-Lobatto points
static inline void hexa_gl_125(double xi, double eta, double zeta,
                               double sfvals[125], double sdvals[375])
{
  ::sfe_sfuncs::hexa_gl_125_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// hexa_gl_216 - Triquintic hexahedral element with equidistant points
static inline void hexa_gl_216(double xi, double eta, double zeta,
                               double sfvals[216], double sdvals[648])
{
  ::sfe_sfuncs::hexa_gl_216_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// hexa_gl_64 - Tricubic hexahedral element with Gauss-Lobatto nodes
static inline void hexa_gl_64(double xi, double eta, double zeta,
                              double sfvals[64], double sdvals[192])
{
  ::sfe_sfuncs::hexa_gl_64_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
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

// prism_126 - Quintic prismatic element with equidistant nodes
static inline void prism_126(double xi, double eta, double zeta,
                             double sfvals[126], double sdvals[378])
{
  ::sfe_sfuncs::prism_126_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// prism_40 - Cubic prismatic element
static inline void prism_40(double xi, double eta, double zeta,
                            double sfvals[40], double sdvals[120])
{
  ::sfe_sfuncs::prism_40_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// prism_75 - Quartic prismatic element with equidistant nodes
static inline void prism_75(double xi, double eta, double zeta,
                            double sfvals[75], double sdvals[225])
{
  ::sfe_sfuncs::prism_75_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// prism_gl_126 - Quintic prismatic element with equidistant nodes
static inline void prism_gl_126(double xi, double eta, double zeta,
                                double sfvals[126], double sdvals[378])
{
  ::sfe_sfuncs::prism_gl_126_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// prism_gl_40 - Quadratic prismatic element with Gauss-Lobatto nodes
static inline void prism_gl_40(double xi, double eta, double zeta,
                               double sfvals[40], double sdvals[120])
{
  ::sfe_sfuncs::prism_gl_40_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// prism_gl_75 - Quartic prismatic element with Gauss-Lobatto nodes
static inline void prism_gl_75(double xi, double eta, double zeta,
                               double sfvals[75], double sdvals[225])
{
  ::sfe_sfuncs::prism_gl_75_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// pyra_30 - Compute shape functions and their derivatives of pyra_30
static inline void pyra_30(double xi, double eta, double zeta,
                           double sfvals[30], double sdvals[90])
{
  ::sfe_sfuncs::pyra_30_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// pyra_55 - Compute shape functions and their derivatives of pyra_55
static inline void pyra_55(double xi, double eta, double zeta,
                           double sfvals[55], double sdvals[165])
{
  ::sfe_sfuncs::pyra_55_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// pyra_gl_30 - Compute shape functions and their derivatives of pyra_gl_30
static inline void pyra_gl_30(double xi, double eta, double zeta,
                              double sfvals[30], double sdvals[90])
{
  ::sfe_sfuncs::pyra_gl_30_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// pyra_gl_55 - Compute shape functions and their derivatives of pyra_gl_55
static inline void pyra_gl_55(double xi, double eta, double zeta,
                              double sfvals[55], double sdvals[165])
{
  ::sfe_sfuncs::pyra_gl_55_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

//  pyra_quadrules - Obtain quadrature points and weights of a pyramidal
static void pyra_quadrules(coder::SizeType degree,
                           ::coder::array<double, 2U> &cs,
                           ::coder::array<double, 1U> &ws)
{
  if (degree <= 1) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::pyra_deg1_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg1_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 2) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::pyra_deg2_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg2_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 3) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::pyra_deg3_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg3_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 5) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::pyra_deg5_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg5_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 6) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::pyra_deg6_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg6_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 7) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::pyra_deg7_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg7_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 9) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::pyra_deg9_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg9_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 11) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::pyra_deg11_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg11_qrule(&cs[0], &(ws.data())[0]);
  } else {
    coder::SizeType nqp;
    if (degree > 13) {
      m2cWarnMsgIdAndTxt("pyra_quadrules:UnsupportedDegree",
                         "Only support up to degree 13");
    }
    nqp = ::sfe_qrules::pyra_deg13_qrule();
    cs.set_size(nqp, 3);
    ws.set_size(nqp);
    ::sfe_qrules::pyra_deg13_qrule(&cs[0], &(ws.data())[0]);
  }
}

// quad_25 - Biquartic quadrilateral element with equidistant points
static inline void quad_25(double xi, double eta, double sfvals[25],
                           double sdvals[50])
{
  ::sfe_sfuncs::quad_25_sfunc(xi, eta, &sfvals[0], &sdvals[0]);
}

// quad_36   Biquintic quadrilateral element with equidistant points
static inline void quad_36(double xi, double eta, double sfvals[36],
                           double sdvals[72])
{
  ::sfe_sfuncs::quad_36_sfunc(xi, eta, &sfvals[0], &sdvals[0]);
}

// quad_49 - Bisextic quadrilateral element with equidistant points
static inline void quad_49(double xi, double eta, double sfvals[49],
                           double sdvals[98])
{
  ::sfe_sfuncs::quad_49_sfunc(xi, eta, &sfvals[0], &sdvals[0]);
}

// quad_gl_25 - Biquartic quadrilateral element with Gauss-Lobatto points
static inline void quad_gl_25(double xi, double eta, double sfvals[25],
                              double sdvals[50])
{
  ::sfe_sfuncs::quad_gl_25_sfunc(xi, eta, &sfvals[0], &sdvals[0]);
}

// quad_gl_36 - Biquintic quadrilateral element with equidistant points
static inline void quad_gl_36(double xi, double eta, double sfvals[36],
                              double sdvals[72])
{
  ::sfe_sfuncs::quad_gl_36_sfunc(xi, eta, &sfvals[0], &sdvals[0]);
}

// quad_gl_49 - Bisextic quadrilateral element with equidistant points
static inline void quad_gl_49(double xi, double eta, double sfvals[49],
                              double sdvals[98])
{
  ::sfe_sfuncs::quad_gl_49_sfunc(xi, eta, &sfvals[0], &sdvals[0]);
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

static void sfe2_tabulate_equi_quad(coder::SizeType etype,
                                    const ::coder::array<double, 2U> &cs,
                                    ::coder::array<double, 2U> &sfvals,
                                    ::coder::array<double, 3U> &sdvals)
{
  double b_tmp_data[1029];
  double tmp_data[1029];
  double dv10[98];
  double dv7[72];
  double dv6[50];
  double dv11[49];
  double dv9[36];
  double dv8[25];
  coder::SizeType b_tmp_size_idx_1;
  coder::SizeType b_tmp_size_idx_2;
  coder::SizeType i;
  coder::SizeType i4;
  coder::SizeType i5;
  coder::SizeType i6;
  coder::SizeType i7;
  coder::SizeType loop_ub;
  coder::SizeType nqp;
  short b_unnamed_idx_1;
  short b_unnamed_idx_2;
  //  triangular
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  switch (etype) {
  case 100: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv3[8];
      double dv[4];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::quad_4_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 &dv[0], &dv3[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i3{0}; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv3[i2 + (ub_loop << 1)];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 3) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 104: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv4[18];
      double dv1[9];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::quad_9_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 &dv1[0], &dv4[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv1[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i3{0}; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv4[i2 + (ub_loop << 1)];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 8) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 108: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv5[32];
      double dv2[16];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::quad_16_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                  &dv2[0], &dv5[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv2[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i3{0}; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv5[i2 + (ub_loop << 1)];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 15) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 112: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      quad_25(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1], dv8, dv6);
      loop_ub = sfvals.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sfvals[i4 + sfvals.size(1) * b_q] = dv8[i4];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i4 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i4] = dv6[i6 + (loop_ub << 1)];
        loop_ub++;
        i4++;
        if (i4 > b_tmp_size_idx_1 - 1) {
          i4 = 0;
          i5++;
        }
        if (loop_ub > 24) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i4 = 0; i4 < b_tmp_size_idx_1; i4++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i4) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i4];
        }
      }
    }
  } break;
  case 116: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      quad_36(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1], dv9, dv7);
      loop_ub = sfvals.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sfvals[i4 + sfvals.size(1) * b_q] = dv9[i4];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i4 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i4] = dv7[i6 + (loop_ub << 1)];
        loop_ub++;
        i4++;
        if (i4 > b_tmp_size_idx_1 - 1) {
          i4 = 0;
          i5++;
        }
        if (loop_ub > 35) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i4 = 0; i4 < b_tmp_size_idx_1; i4++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i4) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i4];
        }
      }
    }
  } break;
  default: {
    coder::SizeType ub_loop;
    m2cAssert(etype == 120, "Only supports up to sextic.");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      quad_49(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1], dv11, dv10);
      loop_ub = sfvals.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sfvals[i4 + sfvals.size(1) * b_q] = dv11[i4];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i4 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i4] = dv10[i6 + (loop_ub << 1)];
        loop_ub++;
        i4++;
        if (i4 > b_tmp_size_idx_1 - 1) {
          i4 = 0;
          i5++;
        }
        if (loop_ub > 48) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i4 = 0; i4 < b_tmp_size_idx_1; i4++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i4) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i4];
        }
      }
    }
  } break;
  }
}

static void sfe2_tabulate_equi_tri(coder::SizeType etype,
                                   const ::coder::array<double, 2U> &cs,
                                   ::coder::array<double, 2U> &sfvals,
                                   ::coder::array<double, 3U> &sdvals)
{
  double b_tmp_data[1029];
  double tmp_data[1029];
  double dv9[56];
  double dv7[42];
  double dv10[28];
  double dv8[21];
  coder::SizeType b_tmp_size_idx_1;
  coder::SizeType b_tmp_size_idx_2;
  coder::SizeType i;
  coder::SizeType i3;
  coder::SizeType i5;
  coder::SizeType i6;
  coder::SizeType i7;
  coder::SizeType loop_ub;
  coder::SizeType nqp;
  short b_unnamed_idx_1;
  short b_unnamed_idx_2;
  //  triangular
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  switch (etype) {
  case 68: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv1[6];
      double dv[3];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::tri_3_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                &dv[0], &dv1[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i4{0}; i4 < unnamed_idx_1 * unnamed_idx_2; i4++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv1[i2 + (ub_loop << 1)];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 2) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 72: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv4[12];
      double dv1[6];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::tri_6_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                &dv1[0], &dv4[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv1[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i4{0}; i4 < unnamed_idx_1 * unnamed_idx_2; i4++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv4[i2 + (ub_loop << 1)];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 5) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 76: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv5[20];
      double dv2[10];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::tri_10_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 &dv2[0], &dv5[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv2[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i4{0}; i4 < unnamed_idx_1 * unnamed_idx_2; i4++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv5[i2 + (ub_loop << 1)];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 9) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 80: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv6[30];
      double dv3[15];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::tri_15_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 &dv3[0], &dv6[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv3[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i4{0}; i4 < unnamed_idx_1 * unnamed_idx_2; i4++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv6[i2 + (ub_loop << 1)];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 14) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 84: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      tri_21(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1], dv8, dv7);
      loop_ub = sfvals.size(1);
      for (i3 = 0; i3 < loop_ub; i3++) {
        sfvals[i3 + sfvals.size(1) * b_q] = dv8[i3];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i3 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i3] = dv7[i6 + (loop_ub << 1)];
        loop_ub++;
        i3++;
        if (i3 > b_tmp_size_idx_1 - 1) {
          i3 = 0;
          i5++;
        }
        if (loop_ub > 20) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i3 = 0; i3 < b_tmp_size_idx_1; i3++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i3) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i3];
        }
      }
    }
  } break;
  default: {
    coder::SizeType ub_loop;
    m2cAssert(etype == 88, "Only support up to sextic.");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      tri_28(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1], dv10, dv9);
      loop_ub = sfvals.size(1);
      for (i3 = 0; i3 < loop_ub; i3++) {
        sfvals[i3 + sfvals.size(1) * b_q] = dv10[i3];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i3 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i3] = dv9[i6 + (loop_ub << 1)];
        loop_ub++;
        i3++;
        if (i3 > b_tmp_size_idx_1 - 1) {
          i3 = 0;
          i5++;
        }
        if (loop_ub > 27) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i3 = 0; i3 < b_tmp_size_idx_1; i3++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i3) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i3];
        }
      }
    }
  } break;
  }
}

static void sfe2_tabulate_fek_tri(coder::SizeType etype,
                                  const ::coder::array<double, 2U> &cs,
                                  ::coder::array<double, 2U> &sfvals,
                                  ::coder::array<double, 3U> &sdvals)
{
  double tmp_data[1029];
  double dv4[56];
  double dv1[42];
  double dv[30];
  double dv5[28];
  double dv3[21];
  double dv2[15];
  coder::SizeType i;
  coder::SizeType i1;
  coder::SizeType i2;
  coder::SizeType i3;
  coder::SizeType loop_ub;
  coder::SizeType tmp_size_idx_1;
  coder::SizeType tmp_size_idx_2;
  coder::SizeType ub_loop;
  short unnamed_idx_1;
  short unnamed_idx_2;
  //  triangular
  ub_loop = iv[etype - 1];
  sfvals.set_size(cs.size(0), ub_loop);
  sdvals.set_size(cs.size(0), ub_loop, cs.size(1));
  switch (etype) {
  case 82:
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      tri_fek_15(cs[cs.size(1) * q], cs[cs.size(1) * q + 1], dv2, dv);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv2[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv[i2 + (loop_ub << 1)];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 14) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
    break;
  case 86:
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      tri_fek_21(cs[cs.size(1) * q], cs[cs.size(1) * q + 1], dv3, dv1);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv3[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv1[i2 + (loop_ub << 1)];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 20) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
    break;
  default:
    m2cAssert(etype == 90, "Only supports up to sextic.");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      tri_fek_28(cs[cs.size(1) * q], cs[cs.size(1) * q + 1], dv5, dv4);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv5[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv4[i2 + (loop_ub << 1)];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 27) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
    break;
  }
}

static void sfe2_tabulate_gl_quad(coder::SizeType etype,
                                  const ::coder::array<double, 2U> &cs,
                                  ::coder::array<double, 2U> &sfvals,
                                  ::coder::array<double, 3U> &sdvals)
{
  double b_tmp_data[1029];
  double tmp_data[1029];
  double dv6[98];
  double dv3[72];
  double dv2[50];
  double dv7[49];
  double dv5[36];
  double dv4[25];
  coder::SizeType b_tmp_size_idx_1;
  coder::SizeType b_tmp_size_idx_2;
  coder::SizeType i;
  coder::SizeType i4;
  coder::SizeType i5;
  coder::SizeType i6;
  coder::SizeType i7;
  coder::SizeType loop_ub;
  coder::SizeType nqp;
  short b_unnamed_idx_1;
  short b_unnamed_idx_2;
  //  quad
  nqp = cs.size(0);
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  switch (etype) {
  case 109: {
    for (coder::SizeType q{0}; q < nqp; q++) {
      double dv1[32];
      double dv[16];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::quad_gl_16_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                     &dv[0], &dv1[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i3{0}; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv1[i2 + (ub_loop << 1)];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 15) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 113: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      quad_gl_25(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1], dv4, dv2);
      loop_ub = sfvals.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sfvals[i4 + sfvals.size(1) * b_q] = dv4[i4];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i4 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i4] = dv2[i6 + (loop_ub << 1)];
        loop_ub++;
        i4++;
        if (i4 > b_tmp_size_idx_1 - 1) {
          i4 = 0;
          i5++;
        }
        if (loop_ub > 24) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i4 = 0; i4 < b_tmp_size_idx_1; i4++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i4) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i4];
        }
      }
    }
  } break;
  case 117: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      quad_gl_36(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1], dv5, dv3);
      loop_ub = sfvals.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sfvals[i4 + sfvals.size(1) * b_q] = dv5[i4];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i4 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i4] = dv3[i6 + (loop_ub << 1)];
        loop_ub++;
        i4++;
        if (i4 > b_tmp_size_idx_1 - 1) {
          i4 = 0;
          i5++;
        }
        if (loop_ub > 35) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i4 = 0; i4 < b_tmp_size_idx_1; i4++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i4) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i4];
        }
      }
    }
  } break;
  default: {
    coder::SizeType ub_loop;
    m2cAssert(etype == 121, "Only supports up to sextic.");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      quad_gl_49(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1], dv7, dv6);
      loop_ub = sfvals.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sfvals[i4 + sfvals.size(1) * b_q] = dv7[i4];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i4 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i4] = dv6[i6 + (loop_ub << 1)];
        loop_ub++;
        i4++;
        if (i4 > b_tmp_size_idx_1 - 1) {
          i4 = 0;
          i5++;
        }
        if (loop_ub > 48) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i4 = 0; i4 < b_tmp_size_idx_1; i4++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i4) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i4];
        }
      }
    }
  } break;
  }
}

static void sfe2_tabulate_gl_tri(coder::SizeType etype,
                                 const ::coder::array<double, 2U> &cs,
                                 ::coder::array<double, 2U> &sfvals,
                                 ::coder::array<double, 3U> &sdvals)
{
  double b_tmp_data[1029];
  double tmp_data[1029];
  double dv6[56];
  double dv4[42];
  double dv7[28];
  double dv5[21];
  coder::SizeType b_tmp_size_idx_1;
  coder::SizeType b_tmp_size_idx_2;
  coder::SizeType i;
  coder::SizeType i3;
  coder::SizeType i5;
  coder::SizeType i6;
  coder::SizeType i7;
  coder::SizeType loop_ub;
  coder::SizeType nqp;
  short b_unnamed_idx_1;
  short b_unnamed_idx_2;
  //  triangular
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  switch (etype) {
  case 77: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv2[20];
      double dv[10];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::tri_gl_10_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                    &dv[0], &dv2[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i4{0}; i4 < unnamed_idx_1 * unnamed_idx_2; i4++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv2[i2 + (ub_loop << 1)];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 9) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 81: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv3[30];
      double dv1[15];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::tri_gl_15_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                    &dv1[0], &dv3[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv1[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i4{0}; i4 < unnamed_idx_1 * unnamed_idx_2; i4++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv3[i2 + (ub_loop << 1)];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 14) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 85: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      tri_gl_21(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1], dv5, dv4);
      loop_ub = sfvals.size(1);
      for (i3 = 0; i3 < loop_ub; i3++) {
        sfvals[i3 + sfvals.size(1) * b_q] = dv5[i3];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i3 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i3] = dv4[i6 + (loop_ub << 1)];
        loop_ub++;
        i3++;
        if (i3 > b_tmp_size_idx_1 - 1) {
          i3 = 0;
          i5++;
        }
        if (loop_ub > 20) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i3 = 0; i3 < b_tmp_size_idx_1; i3++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i3) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i3];
        }
      }
    }
  } break;
  default: {
    coder::SizeType ub_loop;
    m2cAssert(etype == 85, "Only support up to sextic");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      tri_fek_28(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1], dv7, dv6);
      loop_ub = sfvals.size(1);
      for (i3 = 0; i3 < loop_ub; i3++) {
        sfvals[i3 + sfvals.size(1) * b_q] = dv7[i3];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i3 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i3] = dv6[i6 + (loop_ub << 1)];
        loop_ub++;
        i3++;
        if (i3 > b_tmp_size_idx_1 - 1) {
          i3 = 0;
          i5++;
        }
        if (loop_ub > 27) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i3 = 0; i3 < b_tmp_size_idx_1; i3++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i3) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i3];
        }
      }
    }
  } break;
  }
}

// sfe2_tabulate_shapefuncs - Tabulate shape functions and sdvals at given
static inline void sfe2_tabulate_shapefuncs(
    coder::SizeType etype, const ::coder::array<double, 2U> &cs,
    ::coder::array<double, 2U> &sfvals, ::coder::array<double, 3U> &sdvals)
{
  switch (etype & 3) {
  case 0:
    //  equi kernel
    if ((etype >> 5 & 7) == 2) {
      sfe2_tabulate_equi_tri(etype, cs, sfvals, sdvals);
    } else {
      sfe2_tabulate_equi_quad(etype, cs, sfvals, sdvals);
    }
    break;
  case 1:
    //  GL kernel
    if ((etype >> 5 & 7) == 2) {
      sfe2_tabulate_gl_tri(etype, cs, sfvals, sdvals);
    } else {
      sfe2_tabulate_gl_quad(etype, cs, sfvals, sdvals);
    }
    break;
  default:
    //  FEK kernel
    sfe2_tabulate_fek_tri(etype, cs, sfvals, sdvals);
    break;
  }
}

static void sfe3_tabulate_equi_hexa(coder::SizeType etype,
                                    const ::coder::array<double, 2U> &cs,
                                    ::coder::array<double, 2U> &sfvals,
                                    ::coder::array<double, 3U> &sdvals)
{
  double b_tmp_data[1029];
  double tmp_data[1029];
  double dv8[648];
  double dv5[375];
  double dv9[216];
  double dv4[192];
  double dv7[125];
  double dv6[64];
  coder::SizeType b_tmp_size_idx_1;
  coder::SizeType b_tmp_size_idx_2;
  coder::SizeType i;
  coder::SizeType i4;
  coder::SizeType i5;
  coder::SizeType i6;
  coder::SizeType i7;
  coder::SizeType loop_ub;
  coder::SizeType nqp;
  short b_unnamed_idx_1;
  short b_unnamed_idx_2;
  //  hex
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  switch (etype) {
  case 228: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv2[24];
      double dv[8];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::hexa_8_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 cs[cs.size(1) * q + 2], &dv[0], &dv2[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i3{0}; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv2[i2 + 3 * ub_loop];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 7) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 232: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv3[81];
      double dv1[27];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::hexa_27_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                  cs[cs.size(1) * q + 2], &dv1[0], &dv3[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv1[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i3{0}; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv3[i2 + 3 * ub_loop];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 26) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 236: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      hexa_64(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1],
              cs[cs.size(1) * b_q + 2], dv6, dv4);
      loop_ub = sfvals.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sfvals[i4 + sfvals.size(1) * b_q] = dv6[i4];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i4 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i4] = dv4[i6 + 3 * loop_ub];
        loop_ub++;
        i4++;
        if (i4 > b_tmp_size_idx_1 - 1) {
          i4 = 0;
          i5++;
        }
        if (loop_ub > 63) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i4 = 0; i4 < b_tmp_size_idx_1; i4++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i4) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i4];
        }
      }
    }
  } break;
  case 240: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      hexa_125(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1],
               cs[cs.size(1) * b_q + 2], dv7, dv5);
      loop_ub = sfvals.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sfvals[i4 + sfvals.size(1) * b_q] = dv7[i4];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i4 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i4] = dv5[i6 + 3 * loop_ub];
        loop_ub++;
        i4++;
        if (i4 > b_tmp_size_idx_1 - 1) {
          i4 = 0;
          i5++;
        }
        if (loop_ub > 124) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i4 = 0; i4 < b_tmp_size_idx_1; i4++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i4) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i4];
        }
      }
    }
  } break;
  default: {
    coder::SizeType ub_loop;
    m2cAssert(etype == 244, "Hex elements supports up to quintic.");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      hexa_216(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1],
               cs[cs.size(1) * b_q + 2], dv9, dv8);
      loop_ub = sfvals.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sfvals[i4 + sfvals.size(1) * b_q] = dv9[i4];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i4 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i4] = dv8[i6 + 3 * loop_ub];
        loop_ub++;
        i4++;
        if (i4 > b_tmp_size_idx_1 - 1) {
          i4 = 0;
          i5++;
        }
        if (loop_ub > 215) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i4 = 0; i4 < b_tmp_size_idx_1; i4++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i4) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i4];
        }
      }
    }
  } break;
  }
}

static void sfe3_tabulate_equi_prism(coder::SizeType etype,
                                     const ::coder::array<double, 2U> &cs,
                                     ::coder::array<double, 2U> &sfvals,
                                     ::coder::array<double, 3U> &sdvals)
{
  double b_tmp_data[1029];
  double tmp_data[1029];
  double dv7[378];
  double dv4[225];
  double dv8[126];
  double dv3[120];
  double dv6[75];
  double dv5[40];
  coder::SizeType b_tmp_size_idx_1;
  coder::SizeType b_tmp_size_idx_2;
  coder::SizeType i;
  coder::SizeType i4;
  coder::SizeType i5;
  coder::SizeType i6;
  coder::SizeType i7;
  coder::SizeType loop_ub;
  coder::SizeType nqp;
  short b_unnamed_idx_1;
  short b_unnamed_idx_2;
  //  prisms
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  switch (etype) {
  case 196: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv1[18];
      double dv[6];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::prism_6_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                  cs[cs.size(1) * q + 2], &dv[0], &dv1[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i3{0}; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv1[i2 + 3 * ub_loop];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 5) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 200: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv2[54];
      double dv1[18];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::prism_18_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                   cs[cs.size(1) * q + 2], &dv1[0], &dv2[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv1[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i3{0}; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv2[i2 + 3 * ub_loop];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 17) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 204: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      prism_40(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1],
               cs[cs.size(1) * b_q + 2], dv5, dv3);
      loop_ub = sfvals.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sfvals[i4 + sfvals.size(1) * b_q] = dv5[i4];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i4 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i4] = dv3[i6 + 3 * loop_ub];
        loop_ub++;
        i4++;
        if (i4 > b_tmp_size_idx_1 - 1) {
          i4 = 0;
          i5++;
        }
        if (loop_ub > 39) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i4 = 0; i4 < b_tmp_size_idx_1; i4++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i4) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i4];
        }
      }
    }
  } break;
  case 208: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      prism_75(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1],
               cs[cs.size(1) * b_q + 2], dv6, dv4);
      loop_ub = sfvals.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sfvals[i4 + sfvals.size(1) * b_q] = dv6[i4];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i4 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i4] = dv4[i6 + 3 * loop_ub];
        loop_ub++;
        i4++;
        if (i4 > b_tmp_size_idx_1 - 1) {
          i4 = 0;
          i5++;
        }
        if (loop_ub > 74) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i4 = 0; i4 < b_tmp_size_idx_1; i4++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i4) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i4];
        }
      }
    }
  } break;
  default: {
    coder::SizeType ub_loop;
    m2cAssert(etype == 212, "prismatic elements supports up to quintic.");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      prism_126(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1],
                cs[cs.size(1) * b_q + 2], dv8, dv7);
      loop_ub = sfvals.size(1);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sfvals[i4 + sfvals.size(1) * b_q] = dv8[i4];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i4 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i4] = dv7[i6 + 3 * loop_ub];
        loop_ub++;
        i4++;
        if (i4 > b_tmp_size_idx_1 - 1) {
          i4 = 0;
          i5++;
        }
        if (loop_ub > 125) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i4 = 0; i4 < b_tmp_size_idx_1; i4++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i4) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i4];
        }
      }
    }
  } break;
  }
}

static void sfe3_tabulate_equi_pyra(coder::SizeType etype,
                                    const ::coder::array<double, 2U> &cs,
                                    ::coder::array<double, 2U> &sfvals,
                                    ::coder::array<double, 3U> &sdvals)
{
  double b_tmp_data[1029];
  double tmp_data[1029];
  double dv6[165];
  double dv4[90];
  double dv7[55];
  double dv5[30];
  coder::SizeType b_tmp_size_idx_1;
  coder::SizeType b_tmp_size_idx_2;
  coder::SizeType i;
  coder::SizeType i2;
  coder::SizeType i5;
  coder::SizeType i6;
  coder::SizeType i7;
  coder::SizeType loop_ub;
  coder::SizeType nqp;
  short b_unnamed_idx_1;
  short b_unnamed_idx_2;
  //  pyra
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  switch (etype) {
  case 164: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv2[15];
      double dv[5];
      coder::SizeType i1;
      coder::SizeType i3;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::pyra_5_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 cs[cs.size(1) * q + 2], &dv[0], &dv2[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i3 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i4{0}; i4 < unnamed_idx_1 * unnamed_idx_2; i4++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv2[i3 + 3 * ub_loop];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 4) {
          ub_loop = 0;
          i3++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 168: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv3[42];
      double dv1[14];
      coder::SizeType i1;
      coder::SizeType i3;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::pyra_14_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                  cs[cs.size(1) * q + 2], &dv1[0], &dv3[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv1[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i3 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i4{0}; i4 < unnamed_idx_1 * unnamed_idx_2; i4++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv3[i3 + 3 * ub_loop];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 13) {
          ub_loop = 0;
          i3++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 172: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      pyra_30(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1],
              cs[cs.size(1) * b_q + 2], dv5, dv4);
      loop_ub = sfvals.size(1);
      for (i2 = 0; i2 < loop_ub; i2++) {
        sfvals[i2 + sfvals.size(1) * b_q] = dv5[i2];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i2 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i2] = dv4[i6 + 3 * loop_ub];
        loop_ub++;
        i2++;
        if (i2 > b_tmp_size_idx_1 - 1) {
          i2 = 0;
          i5++;
        }
        if (loop_ub > 29) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i2 = 0; i2 < b_tmp_size_idx_1; i2++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i2) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i2];
        }
      }
    }
  } break;
  default: {
    coder::SizeType ub_loop;
    m2cAssert(etype == 176, "Pyramid only support up to quartic");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      pyra_55(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1],
              cs[cs.size(1) * b_q + 2], dv7, dv6);
      loop_ub = sfvals.size(1);
      for (i2 = 0; i2 < loop_ub; i2++) {
        sfvals[i2 + sfvals.size(1) * b_q] = dv7[i2];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i2 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i2] = dv6[i6 + 3 * loop_ub];
        loop_ub++;
        i2++;
        if (i2 > b_tmp_size_idx_1 - 1) {
          i2 = 0;
          i5++;
        }
        if (loop_ub > 54) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i2 = 0; i2 < b_tmp_size_idx_1; i2++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i2) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i2];
        }
      }
    }
  } break;
  }
}

static void sfe3_tabulate_equi_tet(coder::SizeType etype,
                                   const ::coder::array<double, 2U> &cs,
                                   ::coder::array<double, 2U> &sfvals,
                                   ::coder::array<double, 3U> &sdvals)
{
  double b_tmp_data[1029];
  double tmp_data[1029];
  double dv8[168];
  double dv5[105];
  double dv4[60];
  double dv9[56];
  double dv7[35];
  double dv6[20];
  coder::SizeType b_tmp_size_idx_1;
  coder::SizeType b_tmp_size_idx_2;
  coder::SizeType i;
  coder::SizeType i3;
  coder::SizeType i5;
  coder::SizeType i6;
  coder::SizeType i7;
  coder::SizeType loop_ub;
  coder::SizeType nqp;
  short b_unnamed_idx_1;
  short b_unnamed_idx_2;
  //  tet
  nqp = cs.size(0) - 1;
  i = iv[etype - 1];
  sfvals.set_size(cs.size(0), i);
  sdvals.set_size(cs.size(0), i, cs.size(1));
  switch (etype) {
  case 132: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv2[12];
      double dv[4];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::tet_4_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                cs[cs.size(1) * q + 2], &dv[0], &dv2[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i4{0}; i4 < unnamed_idx_1 * unnamed_idx_2; i4++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv2[i2 + 3 * ub_loop];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 3) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 136: {
    for (coder::SizeType q{0}; q <= nqp; q++) {
      double dv3[30];
      double dv1[10];
      coder::SizeType i1;
      coder::SizeType i2;
      coder::SizeType tmp_size_idx_1;
      coder::SizeType tmp_size_idx_2;
      coder::SizeType ub_loop;
      short unnamed_idx_1;
      short unnamed_idx_2;
      ::sfe_sfuncs::tet_10_sfunc(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                                 cs[cs.size(1) * q + 2], &dv1[0], &dv3[0]);
      ub_loop = sfvals.size(1);
      for (i = 0; i < ub_loop; i++) {
        sfvals[i + sfvals.size(1) * q] = dv1[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      ub_loop = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (coder::SizeType i4{0}; i4 < unnamed_idx_1 * unnamed_idx_2; i4++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv3[i2 + 3 * ub_loop];
        ub_loop++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (ub_loop > 9) {
          ub_loop = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } break;
  case 140: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      tet_20(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1],
             cs[cs.size(1) * b_q + 2], dv6, dv4);
      loop_ub = sfvals.size(1);
      for (i3 = 0; i3 < loop_ub; i3++) {
        sfvals[i3 + sfvals.size(1) * b_q] = dv6[i3];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i3 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i3] = dv4[i6 + 3 * loop_ub];
        loop_ub++;
        i3++;
        if (i3 > b_tmp_size_idx_1 - 1) {
          i3 = 0;
          i5++;
        }
        if (loop_ub > 19) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i3 = 0; i3 < b_tmp_size_idx_1; i3++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i3) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i3];
        }
      }
    }
  } break;
  case 144: {
    coder::SizeType ub_loop;
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      tet_35(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1],
             cs[cs.size(1) * b_q + 2], dv7, dv5);
      loop_ub = sfvals.size(1);
      for (i3 = 0; i3 < loop_ub; i3++) {
        sfvals[i3 + sfvals.size(1) * b_q] = dv7[i3];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i3 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i3] = dv5[i6 + 3 * loop_ub];
        loop_ub++;
        i3++;
        if (i3 > b_tmp_size_idx_1 - 1) {
          i3 = 0;
          i5++;
        }
        if (loop_ub > 34) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i3 = 0; i3 < b_tmp_size_idx_1; i3++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i3) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i3];
        }
      }
    }
  } break;
  default: {
    coder::SizeType ub_loop;
    m2cAssert(
        etype == 148,
        "Gauss-Lobatto tetrahedral elements are supported only up to quintic");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType b_q = 0; b_q <= ub_loop; b_q++) {
      tet_56(cs[cs.size(1) * b_q], cs[cs.size(1) * b_q + 1],
             cs[cs.size(1) * b_q + 2], dv9, dv8);
      loop_ub = sfvals.size(1);
      for (i3 = 0; i3 < loop_ub; i3++) {
        sfvals[i3 + sfvals.size(1) * b_q] = dv9[i3];
      }
      b_unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      b_unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i3 = 0;
      i5 = 0;
      loop_ub = 0;
      i6 = 0;
      b_tmp_size_idx_2 = sdvals.size(2);
      b_tmp_size_idx_1 = sdvals.size(1);
      for (i7 = 0; i7 < b_unnamed_idx_1 * b_unnamed_idx_2; i7++) {
        b_tmp_data[i5 + b_tmp_size_idx_2 * i3] = dv8[i6 + 3 * loop_ub];
        loop_ub++;
        i3++;
        if (i3 > b_tmp_size_idx_1 - 1) {
          i3 = 0;
          i5++;
        }
        if (loop_ub > 55) {
          loop_ub = 0;
          i6++;
        }
      }
      for (i3 = 0; i3 < b_tmp_size_idx_1; i3++) {
        for (i5 = 0; i5 < b_tmp_size_idx_2; i5++) {
          sdvals[(i5 + sdvals.size(2) * i3) +
                 sdvals.size(2) * sdvals.size(1) * b_q] =
              b_tmp_data[i5 + b_tmp_size_idx_2 * i3];
        }
      }
    }
  } break;
  }
}

static void sfe3_tabulate_gl_hexa(coder::SizeType etype,
                                  const ::coder::array<double, 2U> &cs,
                                  ::coder::array<double, 2U> &sfvals,
                                  ::coder::array<double, 3U> &sdvals)
{
  double tmp_data[1029];
  double dv4[648];
  double dv1[375];
  double dv5[216];
  double dv[192];
  double dv3[125];
  double dv2[64];
  coder::SizeType i;
  coder::SizeType i1;
  coder::SizeType i2;
  coder::SizeType i3;
  coder::SizeType loop_ub;
  coder::SizeType tmp_size_idx_1;
  coder::SizeType tmp_size_idx_2;
  coder::SizeType ub_loop;
  short unnamed_idx_1;
  short unnamed_idx_2;
  //  hex
  ub_loop = iv[etype - 1];
  sfvals.set_size(cs.size(0), ub_loop);
  sdvals.set_size(cs.size(0), ub_loop, cs.size(1));
  switch (etype) {
  case 237:
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      hexa_gl_64(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                 cs[cs.size(1) * q + 2], dv2, dv);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv2[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv[i2 + 3 * loop_ub];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 63) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
    break;
  case 241:
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      hexa_gl_125(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                  cs[cs.size(1) * q + 2], dv3, dv1);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv3[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv1[i2 + 3 * loop_ub];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 124) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
    break;
  default:
    m2cAssert(etype == 245, "Gauss-Lobatto only supports up to quintic.");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      hexa_gl_216(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                  cs[cs.size(1) * q + 2], dv5, dv4);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv5[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv4[i2 + 3 * loop_ub];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 215) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
    break;
  }
}

static void sfe3_tabulate_gl_prism(coder::SizeType etype,
                                   const ::coder::array<double, 2U> &cs,
                                   ::coder::array<double, 2U> &sfvals,
                                   ::coder::array<double, 3U> &sdvals)
{
  double tmp_data[1029];
  double dv4[378];
  double dv1[225];
  double dv5[126];
  double dv[120];
  double dv3[75];
  double dv2[40];
  coder::SizeType i;
  coder::SizeType i1;
  coder::SizeType i2;
  coder::SizeType i3;
  coder::SizeType loop_ub;
  coder::SizeType tmp_size_idx_1;
  coder::SizeType tmp_size_idx_2;
  coder::SizeType ub_loop;
  short unnamed_idx_1;
  short unnamed_idx_2;
  //  prisms
  ub_loop = iv[etype - 1];
  sfvals.set_size(cs.size(0), ub_loop);
  sdvals.set_size(cs.size(0), ub_loop, cs.size(1));
  switch (etype) {
  case 205:
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      prism_gl_40(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                  cs[cs.size(1) * q + 2], dv2, dv);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv2[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv[i2 + 3 * loop_ub];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 39) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
    break;
  case 209:
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      prism_gl_75(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                  cs[cs.size(1) * q + 2], dv3, dv1);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv3[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv1[i2 + 3 * loop_ub];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 74) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
    break;
  default:
    m2cAssert(etype == 213, "Gauss-Lobatto only supports up to quintic.");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      prism_gl_126(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                   cs[cs.size(1) * q + 2], dv5, dv4);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv5[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv4[i2 + 3 * loop_ub];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 125) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
    break;
  }
}

static void sfe3_tabulate_gl_pyra(coder::SizeType etype,
                                  const ::coder::array<double, 2U> &cs,
                                  ::coder::array<double, 2U> &sfvals,
                                  ::coder::array<double, 3U> &sdvals)
{
  double tmp_data[1029];
  double dv2[165];
  double dv[90];
  double dv3[55];
  double dv1[30];
  coder::SizeType i;
  coder::SizeType i1;
  coder::SizeType i2;
  coder::SizeType i3;
  coder::SizeType loop_ub;
  coder::SizeType tmp_size_idx_1;
  coder::SizeType tmp_size_idx_2;
  coder::SizeType ub_loop;
  short unnamed_idx_1;
  short unnamed_idx_2;
  //  pyra
  ub_loop = iv[etype - 1];
  sfvals.set_size(cs.size(0), ub_loop);
  sdvals.set_size(cs.size(0), ub_loop, cs.size(1));
  if (etype == 173) {
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      pyra_gl_30(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                 cs[cs.size(1) * q + 2], dv1, dv);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv1[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv[i2 + 3 * loop_ub];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 29) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } else {
    m2cAssert(etype == 177, "Pyramid only support up to quartic");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      pyra_gl_55(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                 cs[cs.size(1) * q + 2], dv3, dv2);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv3[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv2[i2 + 3 * loop_ub];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 54) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  }
}

static void sfe3_tabulate_gl_tet(coder::SizeType etype,
                                 const ::coder::array<double, 2U> &cs,
                                 ::coder::array<double, 2U> &sfvals,
                                 ::coder::array<double, 3U> &sdvals)
{
  double tmp_data[1029];
  double dv2[105];
  double dv[60];
  double dv3[35];
  double dv1[20];
  coder::SizeType i;
  coder::SizeType i1;
  coder::SizeType i2;
  coder::SizeType i3;
  coder::SizeType loop_ub;
  coder::SizeType tmp_size_idx_1;
  coder::SizeType tmp_size_idx_2;
  coder::SizeType ub_loop;
  short unnamed_idx_1;
  short unnamed_idx_2;
  //  tet
  ub_loop = iv[etype - 1];
  sfvals.set_size(cs.size(0), ub_loop);
  sdvals.set_size(cs.size(0), ub_loop, cs.size(1));
  if (etype == 141) {
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      tet_gl_20(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                cs[cs.size(1) * q + 2], dv1, dv);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv1[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv[i2 + 3 * loop_ub];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 19) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
    }
  } else {
    m2cAssert(
        etype == 145,
        "Gauss-Lobatto tetrahedral elements are supported only up to quartic");
    //  Serial mode
    ub_loop = cs.size(0) - 1;
    for (coder::SizeType q = 0; q <= ub_loop; q++) {
      tet_gl_35(cs[cs.size(1) * q], cs[cs.size(1) * q + 1],
                cs[cs.size(1) * q + 2], dv3, dv2);
      loop_ub = sfvals.size(1);
      for (i = 0; i < loop_ub; i++) {
        sfvals[i + sfvals.size(1) * q] = dv3[i];
      }
      unnamed_idx_1 = static_cast<short>(sdvals.size(1));
      unnamed_idx_2 = static_cast<short>(sdvals.size(2));
      i = 0;
      i1 = 0;
      loop_ub = 0;
      i2 = 0;
      tmp_size_idx_2 = sdvals.size(2);
      tmp_size_idx_1 = sdvals.size(1);
      for (i3 = 0; i3 < unnamed_idx_1 * unnamed_idx_2; i3++) {
        tmp_data[i1 + tmp_size_idx_2 * i] = dv2[i2 + 3 * loop_ub];
        loop_ub++;
        i++;
        if (i > tmp_size_idx_1 - 1) {
          i = 0;
          i1++;
        }
        if (loop_ub > 34) {
          loop_ub = 0;
          i2++;
        }
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        for (i1 = 0; i1 < tmp_size_idx_2; i1++) {
          sdvals[(i1 + sdvals.size(2) * i) +
                 sdvals.size(2) * sdvals.size(1) * q] =
              tmp_data[i1 + tmp_size_idx_2 * i];
        }
      }
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
      sfe3_tabulate_equi_hexa(etype, cs, sfvals, sdvals);
    }
  } else {
    coder::SizeType i;
    m2cAssert(postype == 1,
              "Only supports Equidistant and Gauss-Lobatto points in 3D");
    i = etype >> 5 & 7;
    if (i == 4) {
      sfe3_tabulate_gl_tet(etype, cs, sfvals, sdvals);
    } else if (i == 5) {
      sfe3_tabulate_gl_pyra(etype, cs, sfvals, sdvals);
    } else if (i == 6) {
      sfe3_tabulate_gl_prism(etype, cs, sfvals, sdvals);
    } else {
      sfe3_tabulate_gl_hexa(etype, cs, sfvals, sdvals);
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
  coder::SizeType shape;
  shape = etype >> 5 & 7;
  switch (shape) {
  case 1:
    bar_quadrules(qd, cs, ws);
    break;
  case 2:
    tri_quadrules(qd, cs, ws);
    break;
  case 3: {
    if (qd <= 1) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::quad_deg1_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::quad_deg1_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 3) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::quad_deg3_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::quad_deg3_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 5) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::quad_deg5_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::quad_deg5_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 7) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::quad_deg7_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::quad_deg7_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 9) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::quad_deg9_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::quad_deg9_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 11) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::quad_deg11_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::quad_deg11_qrule(&cs[0], &(ws.data())[0]);
    } else {
      coder::SizeType nqp;
      if (qd > 13) {
        m2cWarnMsgIdAndTxt("bar_quadrules:UnsupportedDegree",
                           "Only support up to degree 13");
      }
      nqp = ::sfe_qrules::quad_deg13_qrule();
      cs.set_size(nqp, 2);
      ws.set_size(nqp);
      ::sfe_qrules::quad_deg13_qrule(&cs[0], &(ws.data())[0]);
    }
  } break;
  case 4: {
    if (qd <= 1) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::tet_deg1_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg1_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 2) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::tet_deg2_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg2_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 3) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::tet_deg3_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg3_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 5) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::tet_deg5_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg5_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 6) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::tet_deg6_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg6_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 7) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::tet_deg7_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg7_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 9) {
      coder::SizeType nqp;
      //  The degree-8 quadrature rule KEAST9 has negative weights, so we do
      nqp = ::sfe_qrules::tet_deg9_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg9_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 11) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::tet_deg11_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg11_qrule(&cs[0], &(ws.data())[0]);
    } else {
      coder::SizeType nqp;
      if (qd > 13) {
        m2cWarnMsgIdAndTxt("tet_quadrules:UnsupportedDegree",
                           "Only support up to degree 13");
      }
      nqp = ::sfe_qrules::tet_deg13_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::tet_deg13_qrule(&cs[0], &(ws.data())[0]);
    }
  } break;
  case 7: {
    if (qd <= 1) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::hexa_deg1_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::hexa_deg1_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 3) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::hexa_deg3_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::hexa_deg3_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 5) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::hexa_deg5_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::hexa_deg5_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 7) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::hexa_deg7_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::hexa_deg7_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 9) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::hexa_deg9_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::hexa_deg9_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 11) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::hexa_deg11_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::hexa_deg11_qrule(&cs[0], &(ws.data())[0]);
    } else {
      coder::SizeType nqp;
      if (qd > 13) {
        m2cWarnMsgIdAndTxt("hexa_quadrules:UnsupportedDegree",
                           "Only support up to degree 13");
      }
      nqp = ::sfe_qrules::hexa_deg13_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::hexa_deg13_qrule(&cs[0], &(ws.data())[0]);
    }
  } break;
  case 6: {
    if (qd <= 1) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::prism_deg1_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::prism_deg1_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 2) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::prism_deg2_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::prism_deg2_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 3) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::prism_deg3_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::prism_deg3_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 5) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::prism_deg5_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::prism_deg5_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 7) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::prism_deg7_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::prism_deg7_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 9) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::prism_deg9_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::prism_deg9_qrule(&cs[0], &(ws.data())[0]);
    } else if (qd <= 11) {
      coder::SizeType nqp;
      nqp = ::sfe_qrules::prism_deg11_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::prism_deg11_qrule(&cs[0], &(ws.data())[0]);
    } else {
      coder::SizeType nqp;
      if (qd > 13) {
        m2cWarnMsgIdAndTxt("prism_quadrules:UnsupportedDegree",
                           "Only support up to degree 13");
      }
      nqp = ::sfe_qrules::prism_deg13_qrule();
      cs.set_size(nqp, 3);
      ws.set_size(nqp);
      ::sfe_qrules::prism_deg13_qrule(&cs[0], &(ws.data())[0]);
    }
  } break;
  default:
    m2cAssert(shape == 5, "Unsupported element type");
    pyra_quadrules(qd, cs, ws);
    break;
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

// tet_20 - Compute shape functions and their derivatives of tet_20
static inline void tet_20(double xi, double eta, double zeta, double sfvals[20],
                          double sdvals[60])
{
  ::sfe_sfuncs::tet_20_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// tet_35 - Compute shape functions and their derivatives of tet_35
static inline void tet_35(double xi, double eta, double zeta, double sfvals[35],
                          double sdvals[105])
{
  ::sfe_sfuncs::tet_35_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// tet_56 - Compute shape functions and their derivatives of tet_56
static inline void tet_56(double xi, double eta, double zeta, double sfvals[56],
                          double sdvals[168])
{
  ::sfe_sfuncs::tet_56_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// tet_gl_20 - Compute shape functions and their derivatives of tet_gl_20
static inline void tet_gl_20(double xi, double eta, double zeta,
                             double sfvals[20], double sdvals[60])
{
  ::sfe_sfuncs::tet_gl_20_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// tet_gl_35 - Compute shape functions and their derivatives of tet_gl_35
static inline void tet_gl_35(double xi, double eta, double zeta,
                             double sfvals[35], double sdvals[105])
{
  ::sfe_sfuncs::tet_gl_35_sfunc(xi, eta, zeta, &sfvals[0], &sdvals[0]);
}

// tri_21 - Compute shape functions and their derivatives of tri_21
static inline void tri_21(double xi, double eta, double sfvals[21],
                          double sdvals[42])
{
  ::sfe_sfuncs::tri_21_sfunc(xi, eta, &sfvals[0], &sdvals[0]);
}

// tri_28 - Compute shape functions and their derivatives of tri_28
static inline void tri_28(double xi, double eta, double sfvals[28],
                          double sdvals[56])
{
  ::sfe_sfuncs::tri_28_sfunc(xi, eta, &sfvals[0], &sdvals[0]);
}

// tri_fek_15 - Compute shape functions and their derivatives of tri_fek_15
static inline void tri_fek_15(double xi, double eta, double sfvals[15],
                              double sdvals[30])
{
  ::sfe_sfuncs::tri_fek_15_sfunc(xi, eta, &sfvals[0], &sdvals[0]);
}

// tri_fek_21 - Compute shape functions and their derivatives of tri_fek_21
static inline void tri_fek_21(double xi, double eta, double sfvals[21],
                              double sdvals[42])
{
  ::sfe_sfuncs::tri_fek_21_sfunc(xi, eta, &sfvals[0], &sdvals[0]);
}

// tri_fek_28 - Compute shape functions and their derivatives of tri_fek_28
static inline void tri_fek_28(double xi, double eta, double sfvals[28],
                              double sdvals[56])
{
  ::sfe_sfuncs::tri_fek_28_sfunc(xi, eta, &sfvals[0], &sdvals[0]);
}

// tri_gl_21 - Compute shape functions and their derivatives of tri_gl_21
static inline void tri_gl_21(double xi, double eta, double sfvals[21],
                             double sdvals[42])
{
  ::sfe_sfuncs::tri_gl_21_sfunc(xi, eta, &sfvals[0], &sdvals[0]);
}

//  tri_quadrules - Obtain quadrature points and weights of a triangular
static void tri_quadrules(coder::SizeType degree,
                          ::coder::array<double, 2U> &cs,
                          ::coder::array<double, 1U> &ws)
{
  if (degree <= 1) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::tri_deg1_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg1_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 2) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::tri_deg2_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg2_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 4) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::tri_deg4_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg4_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 5) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::tri_deg5_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg5_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 7) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::tri_deg7_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg7_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 8) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::tri_deg8_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg8_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 9) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::tri_deg9_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg9_qrule(&cs[0], &(ws.data())[0]);
  } else if (degree <= 11) {
    coder::SizeType nqp;
    nqp = ::sfe_qrules::tri_deg11_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg11_qrule(&cs[0], &(ws.data())[0]);
  } else {
    coder::SizeType nqp;
    if (degree > 13) {
      m2cWarnMsgIdAndTxt("tri_quadrules:UnsupportedDegree",
                         "Only support up to degree 13");
    }
    nqp = ::sfe_qrules::tri_deg13_qrule();
    cs.set_size(nqp, 2);
    ws.set_size(nqp);
    ::sfe_qrules::tri_deg13_qrule(&cs[0], &(ws.data())[0]);
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
