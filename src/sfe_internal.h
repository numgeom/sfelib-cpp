// Copyright 2022 The NumGeom Group, Stony Brook University
//
// sfe_internal.h
//
// Code generation for function 'sfe_internal'
//

#ifndef SFE_INTERNAL_H
#define SFE_INTERNAL_H

// Include files
#include "coder_array.h"
#include "m2c_lib.h"
#include "rtwtypes.h"
#include "sfe_internal_types.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace sfe {
struct SfeObject;

}

// Function Declarations
namespace sfe {
static inline coder::SizeType obtain_elemdegree(coder::SizeType etype);

extern unsigned char obtain_facets(coder::SizeType etype);

static inline void obtain_facets(coder::SizeType etype, signed char facetid,
                                 unsigned char *ret, short lids_data[],
                                 coder::SizeType lids_size[1]);

static inline void obtain_natcoords(coder::SizeType etype,
                                    ::coder::array<double, 2U> &natcoords);

static inline void sfe_bnd_init(SfeObject *b_sfe, const int etypes_data[],
                                const coder::SizeType etypes_size[1],
                                signed char facetid,
                                const ::coder::array<double, 2U> &xs,
                                coder::SizeType qd_or_natcoords,
                                const ::coder::array<double, 2U> &userquad);

static inline void sfe_bnd_init(SfeObject *b_sfe, const int etypes_data[],
                                const coder::SizeType etypes_size[1],
                                signed char facetid,
                                const ::coder::array<double, 2U> &xs,
                                coder::SizeType qd_or_natcoords);

static inline void sfe_bnd_init(SfeObject *b_sfe, const int etypes_data[],
                                const coder::SizeType etypes_size[1],
                                signed char facetid,
                                const ::coder::array<double, 2U> &xs);

static inline void
sfe_bnd_init(SfeObject *b_sfe, const int etypes_data[],
             const coder::SizeType etypes_size[1], signed char facetid,
             const ::coder::array<double, 2U> &xs,
             const ::coder::array<double, 2U> &qd_or_natcoords);

static inline void sfe_elem_dbc(::coder::array<double, 2U> &elemmat,
                                ::coder::array<double, 1U> &load,
                                const ::coder::array<boolean_T, 1U> &dtags);

static inline void sfe_elem_dbc(::coder::array<double, 2U> &elemmat,
                                ::coder::array<double, 1U> &load,
                                const ::coder::array<boolean_T, 1U> &dtags,
                                const ::coder::array<double, 1U> &dvals);

static inline void sfe_elem_dbc(::coder::array<double, 2U> &elemmat,
                                ::coder::array<double, 1U> &load,
                                const ::coder::array<boolean_T, 1U> &dtags,
                                const ::coder::array<double, 1U> &dvals,
                                const ::coder::array<int, 1U> &gdofs);

static inline void sfe_elem_le2d(SfeObject *b_sfe, double mu, double lambda,
                                 ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_le3d(SfeObject *b_sfe, double mu, double lambda,
                                 ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_load(const SfeObject *b_sfe,
                                 const ::coder::array<double, 2U> &fs,
                                 boolean_T compwise,
                                 ::coder::array<double, 1U> &load);

static inline void sfe_elem_load(const SfeObject *b_sfe,
                                 const ::coder::array<double, 2U> &fs,
                                 ::coder::array<double, 1U> &load);

static inline void sfe_elem_mass(const SfeObject *b_sfe,
                                 ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_mass(const SfeObject *b_sfe, double rho,
                                 ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_mass(const SfeObject *b_sfe,
                                 const ::coder::array<double, 1U> &rho,
                                 ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_nbc(const SfeObject *b_sfe,
                                const ::coder::array<double, 2U> &g,
                                ::coder::array<double, 1U> &load);

static inline void sfe_elem_nbc(const SfeObject *b_sfe,
                                const ::coder::array<double, 2U> &g,
                                boolean_T compwise,
                                ::coder::array<double, 1U> &load);

static inline void sfe_elem_stiff(SfeObject *b_sfe, double nu,
                                  ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_stiff(SfeObject *b_sfe, double nu,
                                  const double vel_data[],
                                  const coder::SizeType vel_size[2],
                                  ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_stiff(SfeObject *b_sfe,
                                  const ::coder::array<double, 1U> &nu,
                                  ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_stiff(SfeObject *b_sfe, double nu,
                                  const ::coder::array<double, 2U> &vel,
                                  ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_stiff(SfeObject *b_sfe,
                                  const ::coder::array<double, 1U> &nu,
                                  const ::coder::array<double, 2U> &vel,
                                  coder::SizeType coefftag,
                                  ::coder::array<double, 2U> &elemmat);

static inline double sfe_eval_div(const SfeObject *b_sfe,
                                  const ::coder::array<double, 2U> &fs);

static inline void sfe_eval_funcs(const SfeObject *b_sfe, coder::SizeType q,
                                  const ::coder::array<double, 2U> &fs,
                                  ::coder::array<double, 2U> &vals);

static inline void sfe_eval_grads(const SfeObject *b_sfe,
                                  const ::coder::array<double, 2U> &fs,
                                  ::coder::array<double, 2U> &grads);

static inline void sfe_init(SfeObject *b_sfe, const int etypes_data[],
                            const coder::SizeType etypes_size[1],
                            const ::coder::array<double, 2U> &xs,
                            coder::SizeType qd_or_natcoords,
                            const ::coder::array<double, 2U> &userquad);

static inline void sfe_init(SfeObject *b_sfe, const int etypes_data[],
                            const coder::SizeType etypes_size[1],
                            const ::coder::array<double, 2U> &xs,
                            coder::SizeType qd_or_natcoords);

static inline void sfe_init(SfeObject *b_sfe, const int etypes_data[],
                            const coder::SizeType etypes_size[1],
                            const ::coder::array<double, 2U> &xs);

static inline void sfe_init(SfeObject *b_sfe, const int etypes_data[],
                            const coder::SizeType etypes_size[1],
                            const ::coder::array<double, 2U> &xs,
                            const ::coder::array<double, 2U> &qd_or_natcoords);

static inline void sfe_init_grad1(SfeObject *b_sfe, coder::SizeType q);

} // namespace sfe

#include "sfe_internal.cpp"
#endif
// End of code generation (sfe_internal.h)
