// Copyright 2022 The NumGeom Group, Stony Brook University
//
// sfe_shapefuncs_rowmajor.h
//
// Code generation for function 'sfe_shapefuncs_rowmajor'
//

#ifndef SFE_SHAPEFUNCS_ROWMAJOR_H
#define SFE_SHAPEFUNCS_ROWMAJOR_H

// Include files
#include "m2c_lib.h"
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace sfe_sfuncs {
static inline void bar_2_ncoords(double natcoords[2]);

static inline void bar_2_sfunc(double xi, double sfvals[2]);

static inline void bar_2_sfunc(double xi, double sfvals[2], double sdvals[2]);

static inline void bar_3_ncoords(double natcoords[3]);

static inline void bar_3_sfunc(double xi, double sfvals[3]);

static inline void bar_3_sfunc(double xi, double sfvals[3], double sdvals[3]);

static inline void bar_4_ncoords(double natcoords[4]);

static inline void bar_4_sfunc(double xi, double sfvals[4]);

static inline void bar_4_sfunc(double xi, double sfvals[4], double sdvals[4]);

static inline void bar_5_ncoords(double natcoords[5]);

static inline void bar_5_sfunc(double xi, double sfvals[5]);

static inline void bar_5_sfunc(double xi, double sfvals[5], double sdvals[5]);

static inline void bar_6_ncoords(double natcoords[6]);

static inline void bar_6_sfunc(double xi, double sfvals[6]);

static inline void bar_6_sfunc(double xi, double sfvals[6], double sdvals[6]);

static inline void bar_7_ncoords(double natcoords[7]);

static inline void bar_7_sfunc(double xi, double sfvals[7]);

static inline void bar_7_sfunc(double xi, double sfvals[7], double sdvals[7]);

static inline void bar_gl_4_ncoords(double natcoords[4]);

static inline void bar_gl_4_sfunc(double xi, double sfvals[4]);

static inline void bar_gl_4_sfunc(double xi, double sfvals[4],
                                  double sdvals[4]);

static inline void bar_gl_5_ncoords(double natcoords[5]);

static inline void bar_gl_5_sfunc(double xi, double sfvals[5]);

static inline void bar_gl_5_sfunc(double xi, double sfvals[5],
                                  double sdvals[5]);

static inline void bar_gl_6_ncoords(double natcoords[6]);

static inline void bar_gl_6_sfunc(double xi, double sfvals[6]);

static inline void bar_gl_6_sfunc(double xi, double sfvals[6],
                                  double sdvals[6]);

static inline void bar_gl_7_ncoords(double natcoords[7]);

static inline void bar_gl_7_sfunc(double xi, double sfvals[7]);

static inline void bar_gl_7_sfunc(double xi, double sfvals[7],
                                  double sdvals[7]);

static inline void hexa_125_ncoords(double natcoords[375]);

static inline void hexa_125_sfunc(double xi, double eta, double zeta,
                                  double sfvals[125]);

static inline void hexa_125_sfunc(double xi, double eta, double zeta,
                                  double sfvals[125], double sdvals[375]);

static inline void hexa_216_ncoords(double natcoords[648]);

static inline void hexa_216_sfunc(double xi, double eta, double zeta,
                                  double sfvals[216]);

static inline void hexa_216_sfunc(double xi, double eta, double zeta,
                                  double sfvals[216], double sdvals[648]);

static inline void hexa_27_ncoords(double natcoords[81]);

static inline void hexa_27_sfunc(double xi, double eta, double zeta,
                                 double sfvals[27]);

static inline void hexa_27_sfunc(double xi, double eta, double zeta,
                                 double sfvals[27], double sdvals[81]);

static inline void hexa_64_ncoords(double natcoords[192]);

static inline void hexa_64_sfunc(double xi, double eta, double zeta,
                                 double sfvals[64]);

static inline void hexa_64_sfunc(double xi, double eta, double zeta,
                                 double sfvals[64], double sdvals[192]);

static inline void hexa_8_ncoords(double natcoords[24]);

static inline void hexa_8_sfunc(double xi, double eta, double zeta,
                                double sfvals[8]);

static inline void hexa_8_sfunc(double xi, double eta, double zeta,
                                double sfvals[8], double sdvals[24]);

static inline void hexa_gl_125_ncoords(double natcoords[375]);

static inline void hexa_gl_125_sfunc(double xi, double eta, double zeta,
                                     double sfvals[125]);

static inline void hexa_gl_125_sfunc(double xi, double eta, double zeta,
                                     double sfvals[125], double sdvals[375]);

static inline void hexa_gl_216_ncoords(double natcoords[648]);

static inline void hexa_gl_216_sfunc(double xi, double eta, double zeta,
                                     double sfvals[216]);

static inline void hexa_gl_216_sfunc(double xi, double eta, double zeta,
                                     double sfvals[216], double sdvals[648]);

static inline void hexa_gl_64_ncoords(double natcoords[192]);

static inline void hexa_gl_64_sfunc(double xi, double eta, double zeta,
                                    double sfvals[64]);

static inline void hexa_gl_64_sfunc(double xi, double eta, double zeta,
                                    double sfvals[64], double sdvals[192]);

static inline void prism_126_ncoords(double natcoords[378]);

static inline void prism_126_sfunc(double xi, double eta, double zeta,
                                   double sfvals[126]);

static inline void prism_126_sfunc(double xi, double eta, double zeta,
                                   double sfvals[126], double sdvals[378]);

static inline void prism_18_ncoords(double natcoords[54]);

static inline void prism_18_sfunc(double xi, double eta, double zeta,
                                  double sfvals[18]);

static inline void prism_18_sfunc(double xi, double eta, double zeta,
                                  double sfvals[18], double sdvals[54]);

static inline void prism_40_ncoords(double natcoords[120]);

static inline void prism_40_sfunc(double xi, double eta, double zeta,
                                  double sfvals[40]);

static inline void prism_40_sfunc(double xi, double eta, double zeta,
                                  double sfvals[40], double sdvals[120]);

static inline void prism_6_ncoords(double natcoords[18]);

static inline void prism_6_sfunc(double xi, double eta, double zeta,
                                 double sfvals[6]);

static inline void prism_6_sfunc(double xi, double eta, double zeta,
                                 double sfvals[6], double sdvals[18]);

static inline void prism_75_ncoords(double natcoords[225]);

static inline void prism_75_sfunc(double xi, double eta, double zeta,
                                  double sfvals[75]);

static inline void prism_75_sfunc(double xi, double eta, double zeta,
                                  double sfvals[75], double sdvals[225]);

static inline void prism_fek_75_ncoords(double natcoords[225]);

static inline void prism_fek_75_sfunc(double xi, double eta, double zeta,
                                      double sfvals[75]);

static inline void prism_fek_75_sfunc(double xi, double eta, double zeta,
                                      double sfvals[75], double sdvals[225]);

static inline void prism_gl_126_ncoords(double natcoords[378]);

static inline void prism_gl_126_sfunc(double xi, double eta, double zeta,
                                      double sfvals[126]);

static inline void prism_gl_126_sfunc(double xi, double eta, double zeta,
                                      double sfvals[126], double sdvals[378]);

static inline void prism_gl_40_ncoords(double natcoords[120]);

static inline void prism_gl_40_sfunc(double xi, double eta, double zeta,
                                     double sfvals[40]);

static inline void prism_gl_40_sfunc(double xi, double eta, double zeta,
                                     double sfvals[40], double sdvals[120]);

static inline void prism_gl_75_ncoords(double natcoords[225]);

static inline void prism_gl_75_sfunc(double xi, double eta, double zeta,
                                     double sfvals[75]);

static inline void prism_gl_75_sfunc(double xi, double eta, double zeta,
                                     double sfvals[75], double sdvals[225]);

static inline void pyra_14_ncoords(double natcoords[42]);

static inline void pyra_14_sfunc(double xi, double eta, double zeta,
                                 double sfvals[14]);

static inline void pyra_14_sfunc(double xi, double eta, double zeta,
                                 double sfvals[14], double sdvals[42]);

static inline void pyra_30_ncoords(double natcoords[90]);

static inline void pyra_30_sfunc(double xi, double eta, double zeta,
                                 double sfvals[30]);

static inline void pyra_30_sfunc(double xi, double eta, double zeta,
                                 double sfvals[30], double sdvals[90]);

static inline void pyra_55_ncoords(double natcoords[165]);

static inline void pyra_55_sfunc(double xi, double eta, double zeta,
                                 double sfvals[55]);

static inline void pyra_55_sfunc(double xi, double eta, double zeta,
                                 double sfvals[55], double sdvals[165]);

static inline void pyra_5_ncoords(double natcoords[15]);

static inline void pyra_5_sfunc(double xi, double eta, double zeta,
                                double sfvals[5]);

static inline void pyra_5_sfunc(double xi, double eta, double zeta,
                                double sfvals[5], double sdvals[15]);

static inline void pyra_91_ncoords(double natcoords[273]);

static inline void pyra_91_sfunc(double xi, double eta, double zeta,
                                 double sfvals[91]);

static inline void pyra_91_sfunc(double xi, double eta, double zeta,
                                 double sfvals[91], double sdvals[273]);

static inline void pyra_fek_55_ncoords(double natcoords[165]);

static inline void pyra_fek_55_sfunc(double xi, double eta, double zeta,
                                     double sfvals[55]);

static inline void pyra_fek_55_sfunc(double xi, double eta, double zeta,
                                     double sfvals[55], double sdvals[165]);

static inline void pyra_gl_30_ncoords(double natcoords[90]);

static inline void pyra_gl_30_sfunc(double xi, double eta, double zeta,
                                    double sfvals[30]);

static inline void pyra_gl_30_sfunc(double xi, double eta, double zeta,
                                    double sfvals[30], double sdvals[90]);

static inline void pyra_gl_55_ncoords(double natcoords[165]);

static inline void pyra_gl_55_sfunc(double xi, double eta, double zeta,
                                    double sfvals[55]);

static inline void pyra_gl_55_sfunc(double xi, double eta, double zeta,
                                    double sfvals[55], double sdvals[165]);

static inline void quad_16_ncoords(double natcoords[32]);

static inline void quad_16_sfunc(double xi, double eta, double sfvals[16]);

static inline void quad_16_sfunc(double xi, double eta, double sfvals[16],
                                 double sdvals[32]);

static inline void quad_25_ncoords(double natcoords[50]);

static inline void quad_25_sfunc(double xi, double eta, double sfvals[25]);

static inline void quad_25_sfunc(double xi, double eta, double sfvals[25],
                                 double sdvals[50]);

static inline void quad_36_ncoords(double natcoords[72]);

static inline void quad_36_sfunc(double xi, double eta, double sfvals[36]);

static inline void quad_36_sfunc(double xi, double eta, double sfvals[36],
                                 double sdvals[72]);

static inline void quad_49_ncoords(double natcoords[98]);

static inline void quad_49_sfunc(double xi, double eta, double sfvals[49]);

static inline void quad_49_sfunc(double xi, double eta, double sfvals[49],
                                 double sdvals[98]);

static inline void quad_4_ncoords(double natcoords[8]);

static inline void quad_4_sfunc(double xi, double eta, double sfvals[4]);

static inline void quad_4_sfunc(double xi, double eta, double sfvals[4],
                                double sdvals[8]);

static inline void quad_9_ncoords(double natcoords[18]);

static inline void quad_9_sfunc(double xi, double eta, double sfvals[9]);

static inline void quad_9_sfunc(double xi, double eta, double sfvals[9],
                                double sdvals[18]);

static inline void quad_gl_16_ncoords(double natcoords[32]);

static inline void quad_gl_16_sfunc(double xi, double eta, double sfvals[16]);

static inline void quad_gl_16_sfunc(double xi, double eta, double sfvals[16],
                                    double sdvals[32]);

static inline void quad_gl_25_ncoords(double natcoords[50]);

static inline void quad_gl_25_sfunc(double xi, double eta, double sfvals[25]);

static inline void quad_gl_25_sfunc(double xi, double eta, double sfvals[25],
                                    double sdvals[50]);

static inline void quad_gl_36_ncoords(double natcoords[72]);

static inline void quad_gl_36_sfunc(double xi, double eta, double sfvals[36]);

static inline void quad_gl_36_sfunc(double xi, double eta, double sfvals[36],
                                    double sdvals[72]);

static inline void quad_gl_49_ncoords(double natcoords[98]);

static inline void quad_gl_49_sfunc(double xi, double eta, double sfvals[49]);

static inline void quad_gl_49_sfunc(double xi, double eta, double sfvals[49],
                                    double sdvals[98]);

static inline void tet_10_ncoords(double natcoords[30]);

static inline void tet_10_sfunc(double xi, double eta, double zeta,
                                double sfvals[10]);

static inline void tet_10_sfunc(double xi, double eta, double zeta,
                                double sfvals[10], double sdvals[30]);

static inline void tet_20_ncoords(double natcoords[60]);

static inline void tet_20_sfunc(double xi, double eta, double zeta,
                                double sfvals[20]);

static inline void tet_20_sfunc(double xi, double eta, double zeta,
                                double sfvals[20], double sdvals[60]);

static inline void tet_35_ncoords(double natcoords[105]);

static inline void tet_35_sfunc(double xi, double eta, double zeta,
                                double sfvals[35]);

static inline void tet_35_sfunc(double xi, double eta, double zeta,
                                double sfvals[35], double sdvals[105]);

static inline void tet_4_ncoords(double natcoords[12]);

static inline void tet_4_sfunc(double xi, double eta, double zeta,
                               double sfvals[4]);

static inline void tet_4_sfunc(double xi, double eta, double zeta,
                               double sfvals[4], double sdvals[12]);

static inline void tet_56_ncoords(double natcoords[168]);

static inline void tet_56_sfunc(double xi, double eta, double zeta,
                                double sfvals[56]);

static inline void tet_56_sfunc(double xi, double eta, double zeta,
                                double sfvals[56], double sdvals[168]);

static inline void tet_fek_35_ncoords(double natcoords[105]);

static inline void tet_fek_35_sfunc(double xi, double eta, double zeta,
                                    double sfvals[35]);

static inline void tet_fek_35_sfunc(double xi, double eta, double zeta,
                                    double sfvals[35], double sdvals[105]);

static inline void tet_gl_20_ncoords(double natcoords[60]);

static inline void tet_gl_20_sfunc(double xi, double eta, double zeta,
                                   double sfvals[20]);

static inline void tet_gl_20_sfunc(double xi, double eta, double zeta,
                                   double sfvals[20], double sdvals[60]);

static inline void tet_gl_35_ncoords(double natcoords[105]);

static inline void tet_gl_35_sfunc(double xi, double eta, double zeta,
                                   double sfvals[35]);

static inline void tet_gl_35_sfunc(double xi, double eta, double zeta,
                                   double sfvals[35], double sdvals[105]);

static inline void tri_10_ncoords(double natcoords[20]);

static inline void tri_10_sfunc(double xi, double eta, double sfvals[10]);

static inline void tri_10_sfunc(double xi, double eta, double sfvals[10],
                                double sdvals[20]);

static inline void tri_15_ncoords(double natcoords[30]);

static inline void tri_15_sfunc(double xi, double eta, double sfvals[15]);

static inline void tri_15_sfunc(double xi, double eta, double sfvals[15],
                                double sdvals[30]);

static inline void tri_21_ncoords(double natcoords[42]);

static inline void tri_21_sfunc(double xi, double eta, double sfvals[21]);

static inline void tri_21_sfunc(double xi, double eta, double sfvals[21],
                                double sdvals[42]);

static inline void tri_28_ncoords(double natcoords[56]);

static inline void tri_28_sfunc(double xi, double eta, double sfvals[28]);

static inline void tri_28_sfunc(double xi, double eta, double sfvals[28],
                                double sdvals[56]);

static inline void tri_3_ncoords(double natcoords[6]);

static inline void tri_3_sfunc(double xi, double eta, double sfvals[3]);

static inline void tri_3_sfunc(double xi, double eta, double sfvals[3],
                               double sdvals[6]);

static inline void tri_6_ncoords(double natcoords[12]);

static inline void tri_6_sfunc(double xi, double eta, double sfvals[6]);

static inline void tri_6_sfunc(double xi, double eta, double sfvals[6],
                               double sdvals[12]);

static inline void tri_fek_15_ncoords(double natcoords[30]);

static inline void tri_fek_15_sfunc(double xi, double eta, double sfvals[15]);

static inline void tri_fek_15_sfunc(double xi, double eta, double sfvals[15],
                                    double sdvals[30]);

static inline void tri_fek_21_ncoords(double natcoords[42]);

static inline void tri_fek_21_sfunc(double xi, double eta, double sfvals[21]);

static inline void tri_fek_21_sfunc(double xi, double eta, double sfvals[21],
                                    double sdvals[42]);

static inline void tri_fek_28_ncoords(double natcoords[56]);

static inline void tri_fek_28_sfunc(double xi, double eta, double sfvals[28]);

static inline void tri_fek_28_sfunc(double xi, double eta, double sfvals[28],
                                    double sdvals[56]);

static inline void tri_gl_10_ncoords(double natcoords[20]);

static inline void tri_gl_10_sfunc(double xi, double eta, double sfvals[10]);

static inline void tri_gl_10_sfunc(double xi, double eta, double sfvals[10],
                                   double sdvals[20]);

static inline void tri_gl_15_ncoords(double natcoords[30]);

static inline void tri_gl_15_sfunc(double xi, double eta, double sfvals[15]);

static inline void tri_gl_15_sfunc(double xi, double eta, double sfvals[15],
                                   double sdvals[30]);

static inline void tri_gl_21_ncoords(double natcoords[42]);

static inline void tri_gl_21_sfunc(double xi, double eta, double sfvals[21]);

static inline void tri_gl_21_sfunc(double xi, double eta, double sfvals[21],
                                   double sdvals[42]);

static inline void tri_leb_15_ncoords(double natcoords[30]);

static inline void tri_leb_15_sfunc(double xi, double eta, double sfvals[15]);

static inline void tri_leb_15_sfunc(double xi, double eta, double sfvals[15],
                                    double sdvals[30]);

static inline void tri_leb_21_ncoords(double natcoords[42]);

static inline void tri_leb_21_sfunc(double xi, double eta, double sfvals[21]);

static inline void tri_leb_21_sfunc(double xi, double eta, double sfvals[21],
                                    double sdvals[42]);

static inline void tri_leb_28_ncoords(double natcoords[56]);

static inline void tri_leb_28_sfunc(double xi, double eta, double sfvals[28]);

static inline void tri_leb_28_sfunc(double xi, double eta, double sfvals[28],
                                    double sdvals[56]);

} // namespace sfe_sfuncs

#include "sfe_shapefuncs_rowmajor.cpp"
#endif
// End of code generation (sfe_shapefuncs_rowmajor.h)
