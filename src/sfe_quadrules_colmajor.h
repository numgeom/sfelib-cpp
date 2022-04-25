// Copyright 2022 The NumGeom Group, Stony Brook University
//
// sfe_quadrules_colmajor.h
//
// Code generation for function 'sfe_quadrules_colmajor'
//

#ifndef SFE_QUADRULES_COLMAJOR_H
#define SFE_QUADRULES_COLMAJOR_H

// Include files
#include "m2c_lib.h"
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace sfe_qrules {
static inline int bar_deg11_qrule();

static inline void bar_deg11_qrule(double cs[6], double ws[6]);

static inline int bar_deg13_qrule();

static inline void bar_deg13_qrule(double cs[7], double ws[7]);

static inline int bar_deg15_qrule();

static inline void bar_deg15_qrule(double cs[8], double ws[8]);

static inline int bar_deg1_qrule();

static inline void bar_deg1_qrule(double *cs, double *ws);

static inline int bar_deg3_qrule();

static inline void bar_deg3_qrule(double cs[2], double ws[2]);

static inline int bar_deg5_qrule();

static inline void bar_deg5_qrule(double cs[3], double ws[3]);

static inline int bar_deg7_qrule();

static inline void bar_deg7_qrule(double cs[4], double ws[4]);

static inline int bar_deg9_qrule();

static inline void bar_deg9_qrule(double cs[5], double ws[5]);

static inline int hexa_deg11_qrule();

static inline void hexa_deg11_qrule(double cs[648], double ws[216]);

static inline int hexa_deg13_qrule();

static inline void hexa_deg13_qrule(double cs[1029], double ws[343]);

static inline int hexa_deg1_qrule();

static inline void hexa_deg1_qrule(double cs[3], double *ws);

static inline int hexa_deg3_qrule();

static inline void hexa_deg3_qrule(double cs[24], double ws[8]);

static inline int hexa_deg5_qrule();

static inline void hexa_deg5_qrule(double cs[81], double ws[27]);

static inline int hexa_deg7_qrule();

static inline void hexa_deg7_qrule(double cs[192], double ws[64]);

static inline int hexa_deg9_qrule();

static inline void hexa_deg9_qrule(double cs[375], double ws[125]);

static inline int prism_deg11_qrule();

static inline void prism_deg11_qrule(double cs[504], double ws[168]);

static inline int prism_deg13_qrule();

static inline void prism_deg13_qrule(double cs[777], double ws[259]);

static inline int prism_deg1_qrule();

static inline void prism_deg1_qrule(double cs[3], double *ws);

static inline int prism_deg2_qrule();

static inline void prism_deg2_qrule(double cs[18], double ws[6]);

static inline int prism_deg3_qrule();

static inline void prism_deg3_qrule(double cs[36], double ws[12]);

static inline int prism_deg5_qrule();

static inline void prism_deg5_qrule(double cs[63], double ws[21]);

static inline int prism_deg7_qrule();

static inline void prism_deg7_qrule(double cs[144], double ws[48]);

static inline int prism_deg9_qrule();

static inline void prism_deg9_qrule(double cs[285], double ws[95]);

static inline int pyra_deg11_qrule();

static inline void pyra_deg11_qrule(double cs[648], double ws[216]);

static inline int pyra_deg13_qrule();

static inline void pyra_deg13_qrule(double cs[1029], double ws[343]);

static inline int pyra_deg1_qrule();

static inline void pyra_deg1_qrule(double cs[3], double *ws);

static inline int pyra_deg2_qrule();

static inline void pyra_deg2_qrule(double cs[15], double ws[5]);

static inline int pyra_deg3_qrule();

static inline void pyra_deg3_qrule(double cs[24], double ws[8]);

static inline int pyra_deg5_qrule();

static inline void pyra_deg5_qrule(double cs[81], double ws[27]);

static inline int pyra_deg6_qrule();

static inline void pyra_deg6_qrule(double cs[144], double ws[48]);

static inline int pyra_deg7_qrule();

static inline void pyra_deg7_qrule(double cs[192], double ws[64]);

static inline int pyra_deg9_qrule();

static inline void pyra_deg9_qrule(double cs[375], double ws[125]);

static inline int quad_deg11_qrule();

static inline void quad_deg11_qrule(double cs[72], double ws[36]);

static inline int quad_deg13_qrule();

static inline void quad_deg13_qrule(double cs[98], double ws[49]);

static inline int quad_deg1_qrule();

static inline void quad_deg1_qrule(double cs[2], double *ws);

static inline int quad_deg3_qrule();

static inline void quad_deg3_qrule(double cs[8], double ws[4]);

static inline int quad_deg5_qrule();

static inline void quad_deg5_qrule(double cs[18], double ws[9]);

static inline int quad_deg7_qrule();

static inline void quad_deg7_qrule(double cs[32], double ws[16]);

static inline int quad_deg9_qrule();

static inline void quad_deg9_qrule(double cs[50], double ws[25]);

static inline int tet_deg11_qrule();

static inline void tet_deg11_qrule(double cs[588], double ws[196]);

static inline int tet_deg13_qrule();

static inline void tet_deg13_qrule(double cs[888], double ws[296]);

static inline int tet_deg1_qrule();

static inline void tet_deg1_qrule(double cs[3], double *ws);

static inline int tet_deg2_qrule();

static inline void tet_deg2_qrule(double cs[12], double ws[4]);

static inline int tet_deg3_qrule();

static inline void tet_deg3_qrule(double cs[24], double ws[8]);

static inline int tet_deg5_qrule();

static inline void tet_deg5_qrule(double cs[42], double ws[14]);

static inline int tet_deg6_qrule();

static inline void tet_deg6_qrule(double cs[72], double ws[24]);

static inline int tet_deg7_qrule();

static inline void tet_deg7_qrule(double cs[93], double ws[31]);

static inline int tet_deg8_qrule();

static inline void tet_deg8_qrule(double cs[135], double ws[45]);

static inline int tet_deg9_qrule();

static inline void tet_deg9_qrule(double cs[342], double ws[114]);

static inline int tri_deg11_qrule();

static inline void tri_deg11_qrule(double cs[56], double ws[28]);

static inline int tri_deg13_qrule();

static inline void tri_deg13_qrule(double cs[74], double ws[37]);

static inline int tri_deg1_qrule();

static inline void tri_deg1_qrule(double cs[2], double *ws);

static inline int tri_deg2_qrule();

static inline void tri_deg2_qrule(double cs[6], double ws[3]);

static inline int tri_deg4_qrule();

static inline void tri_deg4_qrule(double cs[12], double ws[6]);

static inline int tri_deg5_qrule();

static inline void tri_deg5_qrule(double cs[14], double ws[7]);

static inline int tri_deg7_qrule();

static inline void tri_deg7_qrule(double cs[24], double ws[12]);

static inline int tri_deg8_qrule();

static inline void tri_deg8_qrule(double cs[32], double ws[16]);

static inline int tri_deg9_qrule();

static inline void tri_deg9_qrule(double cs[38], double ws[19]);

} // namespace sfe_qrules

#include "sfe_quadrules_colmajor.cpp"
#endif
// End of code generation (sfe_quadrules_colmajor.h)
