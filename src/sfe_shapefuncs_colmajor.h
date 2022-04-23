// Copyright 2022 The NumGeom Group, Stony Brook University
//
// sfe_shapefuncs_colmajor.h
//
// Code generation for function 'sfe_shapefuncs_colmajor'
//

#ifndef SFE_SHAPEFUNCS_COLMAJOR_H
#define SFE_SHAPEFUNCS_COLMAJOR_H

// Include files
#include "m2c_lib.h"
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace sfe {
static inline void bar_2_sfunc(double xi, double sfvals[2]);

static inline void bar_2_sfunc(double xi, double sfvals[2], double sdvals[2]);

static inline void bar_3_sfunc(double xi, double sfvals[3]);

static inline void bar_3_sfunc(double xi, double sfvals[3], double sdvals[3]);

static inline void bar_4_sfunc(double xi, double sfvals[4]);

static inline void bar_4_sfunc(double xi, double sfvals[4], double sdvals[4]);

static inline void bar_5_sfunc(double xi, double sfvals[5]);

static inline void bar_5_sfunc(double xi, double sfvals[5], double sdvals[5]);

static inline void bar_6_sfunc(double xi, double sfvals[6]);

static inline void bar_6_sfunc(double xi, double sfvals[6], double sdvals[6]);

static inline void bar_7_sfunc(double xi, double sfvals[7]);

static inline void bar_7_sfunc(double xi, double sfvals[7], double sdvals[7]);

static inline void bar_gl_4_sfunc(double xi, double sfvals[4]);

static inline void bar_gl_4_sfunc(double xi, double sfvals[4],
                                  double sdvals[4]);

static inline void bar_gl_5_sfunc(double xi, double sfvals[5]);

static inline void bar_gl_5_sfunc(double xi, double sfvals[5],
                                  double sdvals[5]);

static inline void bar_gl_6_sfunc(double xi, double sfvals[6]);

static inline void bar_gl_6_sfunc(double xi, double sfvals[6],
                                  double sdvals[6]);

static inline void bar_gl_7_sfunc(double xi, double sfvals[7]);

static inline void bar_gl_7_sfunc(double xi, double sfvals[7],
                                  double sdvals[7]);

static inline void pyra_14_sfunc(double xi, double eta, double zeta,
                                 double sfvals[14]);

static inline void pyra_14_sfunc(double xi, double eta, double zeta,
                                 double sfvals[14], double sdvals[42]);

static inline void pyra_30_sfunc(double xi, double eta, double zeta,
                                 double sfvals[30]);

static inline void pyra_30_sfunc(double xi, double eta, double zeta,
                                 double sfvals[30], double sdvals[90]);

static inline void pyra_55_sfunc(double xi, double eta, double zeta,
                                 double sfvals[55]);

static inline void pyra_55_sfunc(double xi, double eta, double zeta,
                                 double sfvals[55], double sdvals[165]);

static inline void pyra_5_sfunc(double xi, double eta, double zeta,
                                double sfvals[5]);

static inline void pyra_5_sfunc(double xi, double eta, double zeta,
                                double sfvals[5], double sdvals[15]);

static inline void pyra_fek_55_sfunc(double xi, double eta, double zeta,
                                     double sfvals[55]);

static inline void pyra_fek_55_sfunc(double xi, double eta, double zeta,
                                     double sfvals[55], double sdvals[165]);

static inline void pyra_gl_30_sfunc(double xi, double eta, double zeta,
                                    double sfvals[30]);

static inline void pyra_gl_30_sfunc(double xi, double eta, double zeta,
                                    double sfvals[30], double sdvals[90]);

static inline void pyra_gl_55_sfunc(double xi, double eta, double zeta,
                                    double sfvals[55]);

static inline void pyra_gl_55_sfunc(double xi, double eta, double zeta,
                                    double sfvals[55], double sdvals[165]);

static inline void tet_10_sfunc(double xi, double eta, double zeta,
                                double sfvals[10]);

static inline void tet_10_sfunc(double xi, double eta, double zeta,
                                double sfvals[10], double sdvals[30]);

static inline void tet_20_sfunc(double xi, double eta, double zeta,
                                double sfvals[20]);

static inline void tet_20_sfunc(double xi, double eta, double zeta,
                                double sfvals[20], double sdvals[60]);

static inline void tet_35_sfunc(double xi, double eta, double zeta,
                                double sfvals[35]);

static inline void tet_35_sfunc(double xi, double eta, double zeta,
                                double sfvals[35], double sdvals[105]);

static inline void tet_4_sfunc(double xi, double eta, double zeta,
                               double sfvals[4]);

static inline void tet_4_sfunc(double xi, double eta, double zeta,
                               double sfvals[4], double sdvals[12]);

static inline void tet_56_sfunc(double xi, double eta, double zeta,
                                double sfvals[56]);

static inline void tet_56_sfunc(double xi, double eta, double zeta,
                                double sfvals[56], double sdvals[168]);

static inline void tet_fek_35_sfunc(double xi, double eta, double zeta,
                                    double sfvals[35]);

static inline void tet_fek_35_sfunc(double xi, double eta, double zeta,
                                    double sfvals[35], double sdvals[105]);

static inline void tet_gl_20_sfunc(double xi, double eta, double zeta,
                                   double sfvals[20]);

static inline void tet_gl_20_sfunc(double xi, double eta, double zeta,
                                   double sfvals[20], double sdvals[60]);

static inline void tet_gl_35_sfunc(double xi, double eta, double zeta,
                                   double sfvals[35]);

static inline void tet_gl_35_sfunc(double xi, double eta, double zeta,
                                   double sfvals[35], double sdvals[105]);

static inline void tri_10_sfunc(double xi, double eta, double sfvals[10]);

static inline void tri_10_sfunc(double xi, double eta, double sfvals[10],
                                double sdvals[20]);

static inline void tri_15_sfunc(double xi, double eta, double sfvals[15]);

static inline void tri_15_sfunc(double xi, double eta, double sfvals[15],
                                double sdvals[30]);

static inline void tri_21_sfunc(double xi, double eta, double sfvals[21]);

static inline void tri_21_sfunc(double xi, double eta, double sfvals[21],
                                double sdvals[42]);

static inline void tri_28_sfunc(double xi, double eta, double sfvals[28]);

static inline void tri_28_sfunc(double xi, double eta, double sfvals[28],
                                double sdvals[56]);

static inline void tri_3_sfunc(double xi, double eta, double sfvals[3]);

static inline void tri_3_sfunc(double xi, double eta, double sfvals[3],
                               double sdvals[6]);

static inline void tri_6_sfunc(double xi, double eta, double sfvals[6]);

static inline void tri_6_sfunc(double xi, double eta, double sfvals[6],
                               double sdvals[12]);

static inline void tri_fek_15_sfunc(double xi, double eta, double sfvals[15]);

static inline void tri_fek_15_sfunc(double xi, double eta, double sfvals[15],
                                    double sdvals[30]);

static inline void tri_fek_21_sfunc(double xi, double eta, double sfvals[21]);

static inline void tri_fek_21_sfunc(double xi, double eta, double sfvals[21],
                                    double sdvals[42]);

static inline void tri_fek_28_sfunc(double xi, double eta, double sfvals[28]);

static inline void tri_fek_28_sfunc(double xi, double eta, double sfvals[28],
                                    double sdvals[56]);

static inline void tri_gl_10_sfunc(double xi, double eta, double sfvals[10]);

static inline void tri_gl_10_sfunc(double xi, double eta, double sfvals[10],
                                   double sdvals[20]);

static inline void tri_gl_15_sfunc(double xi, double eta, double sfvals[15]);

static inline void tri_gl_15_sfunc(double xi, double eta, double sfvals[15],
                                   double sdvals[30]);

static inline void tri_gl_21_sfunc(double xi, double eta, double sfvals[21]);

static inline void tri_gl_21_sfunc(double xi, double eta, double sfvals[21],
                                   double sdvals[42]);

static inline void tri_leb_15_sfunc(double xi, double eta, double sfvals[15]);

static inline void tri_leb_15_sfunc(double xi, double eta, double sfvals[15],
                                    double sdvals[30]);

static inline void tri_leb_21_sfunc(double xi, double eta, double sfvals[21]);

static inline void tri_leb_21_sfunc(double xi, double eta, double sfvals[21],
                                    double sdvals[42]);

static inline void tri_leb_28_sfunc(double xi, double eta, double sfvals[28]);

static inline void tri_leb_28_sfunc(double xi, double eta, double sfvals[28],
                                    double sdvals[56]);

} // namespace sfe

#include "sfe_shapefuncs_colmajor.cpp"
#endif
// End of code generation (sfe_shapefuncs_colmajor.h)
