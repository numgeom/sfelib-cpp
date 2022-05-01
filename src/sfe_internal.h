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

static inline coder::SizeType obtain_elemdim(coder::SizeType etype);

static inline coder::SizeType obtain_elemnodepos(coder::SizeType etype);

static inline coder::SizeType obtain_elemshape(coder::SizeType etype);

static inline uint8_T obtain_facets(coder::SizeType etype);

static inline void obtain_facets(coder::SizeType etype, int8_T facetid,
                                 uint8_T *ret, int16_T lids_data[],
                                 coder::SizeType lids_size[1]);

static inline void obtain_natcoords(coder::SizeType etype,
                                    ::coder::array<real_T, 2U> &natcoords);

static inline void obtain_natcoords1d(coder::SizeType etype,
                                      real_T natcoords_data[],
                                      coder::SizeType natcoords_size[1]);

static inline void obtain_natcoords2d(coder::SizeType etype,
                                      ::coder::array<real_T, 2U> &natcoords);

static inline void obtain_natcoords3d(coder::SizeType etype,
                                      ::coder::array<real_T, 2U> &natcoords);

static inline void sfe_bnd_init(SfeObject *b_sfe, coder::SizeType etypes,
                                int8_T facetid,
                                const ::coder::array<real_T, 2U> &xs,
                                coder::SizeType qd_or_natcoords,
                                const ::coder::array<real_T, 2U> &userquad);

static inline void sfe_bnd_init(SfeObject *b_sfe, int8_T facetid,
                                const ::coder::array<real_T, 2U> &xs,
                                int32_T qd_or_natcoords);

static inline void sfe_bnd_init(SfeObject *b_sfe, int8_T facetid,
                                const ::coder::array<real_T, 2U> &xs);

static inline void
sfe_bnd_init(SfeObject *b_sfe, int8_T facetid,
             const ::coder::array<real_T, 2U> &xs,
             const ::coder::array<real_T, 2U> &qd_or_natcoords);

static inline void sfe_bnd_init(SfeObject *b_sfe, coder::SizeType etypes,
                                int8_T facetid,
                                const ::coder::array<real_T, 2U> &xs,
                                coder::SizeType qd_or_natcoords);

static inline void sfe_bnd_init(SfeObject *b_sfe, coder::SizeType etypes,
                                int8_T facetid,
                                const ::coder::array<real_T, 2U> &xs);

static inline void
sfe_bnd_init(SfeObject *b_sfe, coder::SizeType etypes, int8_T facetid,
             const ::coder::array<real_T, 2U> &xs,
             const ::coder::array<real_T, 2U> &qd_or_natcoords);

static inline void sfe_bnd_init(SfeObject *b_sfe, const int32_T etypes[2],
                                int8_T facetid,
                                const ::coder::array<real_T, 2U> &xs,
                                coder::SizeType qd_or_natcoords,
                                const ::coder::array<real_T, 2U> &userquad);

static inline void sfe_bnd_init(SfeObject *b_sfe, const int32_T etypes[2],
                                int8_T facetid,
                                const ::coder::array<real_T, 2U> &xs,
                                coder::SizeType qd_or_natcoords);

static inline void sfe_bnd_init(SfeObject *b_sfe, const int32_T etypes[2],
                                int8_T facetid,
                                const ::coder::array<real_T, 2U> &xs);

static inline void
sfe_bnd_init(SfeObject *b_sfe, const int32_T etypes[2], int8_T facetid,
             const ::coder::array<real_T, 2U> &xs,
             const ::coder::array<real_T, 2U> &qd_or_natcoords);

static inline void sfe_bnd_init(SfeObject *b_sfe, int8_T facetid,
                                const ::coder::array<real_T, 2U> &xs,
                                int32_T qd_or_natcoords,
                                const ::coder::array<real_T, 2U> &userquad);

static inline void sfe_elem_dbc(::coder::array<real_T, 2U> &elemmat,
                                ::coder::array<real_T, 1U> &load,
                                const ::coder::array<boolean_T, 1U> &dtags);

static inline void sfe_elem_dbc(::coder::array<real_T, 2U> &elemmat,
                                ::coder::array<real_T, 1U> &load,
                                const ::coder::array<boolean_T, 1U> &dtags,
                                const ::coder::array<real_T, 1U> &dvals);

static inline void sfe_elem_dbc(::coder::array<real_T, 2U> &elemmat,
                                ::coder::array<real_T, 1U> &load,
                                const ::coder::array<boolean_T, 1U> &dtags,
                                const ::coder::array<real_T, 1U> &dvals,
                                const ::coder::array<int32_T, 1U> &gdofs);

static inline void sfe_elem_le2d(SfeObject *b_sfe, real_T mu, real_T lambda,
                                 ::coder::array<real_T, 2U> &elemmat);

static inline void sfe_elem_le3d(SfeObject *b_sfe, real_T mu, real_T lambda,
                                 ::coder::array<real_T, 2U> &elemmat);

static inline void sfe_elem_load(const SfeObject *b_sfe,
                                 const ::coder::array<real_T, 2U> &fs,
                                 boolean_T compwise,
                                 ::coder::array<real_T, 1U> &load);

static inline void sfe_elem_load(const SfeObject *b_sfe,
                                 const ::coder::array<real_T, 2U> &fs,
                                 ::coder::array<real_T, 1U> &load);

static inline void sfe_elem_mass(const SfeObject *b_sfe,
                                 ::coder::array<real_T, 2U> &elemmat);

static inline void sfe_elem_mass(const SfeObject *b_sfe, real_T rho,
                                 ::coder::array<real_T, 2U> &elemmat);

static inline void sfe_elem_mass(const SfeObject *b_sfe,
                                 const ::coder::array<real_T, 1U> &rho,
                                 ::coder::array<real_T, 2U> &elemmat);

static inline void sfe_elem_nbc(const SfeObject *b_sfe,
                                const ::coder::array<real_T, 2U> &g,
                                ::coder::array<real_T, 1U> &load);

static inline void sfe_elem_nbc(const SfeObject *b_sfe,
                                const ::coder::array<real_T, 2U> &g,
                                boolean_T compwise,
                                ::coder::array<real_T, 1U> &load);

static inline void sfe_elem_stiff(SfeObject *b_sfe, real_T nu,
                                  ::coder::array<real_T, 2U> &elemmat);

static inline void sfe_elem_stiff(SfeObject *b_sfe, real_T nu,
                                  const real_T vel_data[],
                                  const coder::SizeType vel_size[2],
                                  ::coder::array<real_T, 2U> &elemmat);

static inline void sfe_elem_stiff(SfeObject *b_sfe,
                                  const ::coder::array<real_T, 1U> &nu,
                                  ::coder::array<real_T, 2U> &elemmat);

static inline void sfe_elem_stiff(SfeObject *b_sfe, real_T nu,
                                  const ::coder::array<real_T, 2U> &vel,
                                  ::coder::array<real_T, 2U> &elemmat);

static inline void sfe_elem_stiff(SfeObject *b_sfe,
                                  const ::coder::array<real_T, 1U> &nu,
                                  const ::coder::array<real_T, 2U> &vel,
                                  coder::SizeType coefftag,
                                  ::coder::array<real_T, 2U> &elemmat);

static inline real_T sfe_eval_div(const SfeObject *b_sfe,
                                  const ::coder::array<real_T, 2U> &fs);

static inline void sfe_eval_funcs(const SfeObject *b_sfe, coder::SizeType q,
                                  const ::coder::array<real_T, 2U> &fs,
                                  ::coder::array<real_T, 2U> &vals);

static inline void sfe_eval_grads(const SfeObject *b_sfe,
                                  const ::coder::array<real_T, 2U> &fs,
                                  ::coder::array<real_T, 2U> &grads);

static inline void sfe_init(SfeObject *b_sfe, coder::SizeType etypes,
                            const ::coder::array<real_T, 2U> &xs,
                            coder::SizeType qd_or_natcoords,
                            const ::coder::array<real_T, 2U> &userquad);

static inline void sfe_init(SfeObject *b_sfe,
                            const ::coder::array<real_T, 2U> &xs,
                            int32_T qd_or_natcoords);

static inline void sfe_init11(SfeObject *b_sfe,
                              const ::coder::array<real_T, 2U> &xs);

static inline void sfe_init(SfeObject *b_sfe,
                            const ::coder::array<real_T, 2U> &xs,
                            const ::coder::array<real_T, 2U> &qd_or_natcoords);

static inline void sfe_init(SfeObject *b_sfe, coder::SizeType etypes,
                            const ::coder::array<real_T, 2U> &xs,
                            coder::SizeType qd_or_natcoords);

static inline void sfe_init(SfeObject *b_sfe, coder::SizeType etypes,
                            const ::coder::array<real_T, 2U> &xs);

static inline void sfe_init(SfeObject *b_sfe, coder::SizeType etypes,
                            const ::coder::array<real_T, 2U> &xs,
                            const ::coder::array<real_T, 2U> &qd_or_natcoords);

static inline void sfe_init(SfeObject *b_sfe, const int32_T etypes[2],
                            const ::coder::array<real_T, 2U> &xs,
                            coder::SizeType qd_or_natcoords,
                            const ::coder::array<real_T, 2U> &userquad);

static inline void sfe_init(SfeObject *b_sfe, const int32_T etypes[2],
                            const ::coder::array<real_T, 2U> &xs,
                            coder::SizeType qd_or_natcoords);

static inline void sfe_init(SfeObject *b_sfe, const int32_T etypes[2],
                            const ::coder::array<real_T, 2U> &xs);

static inline void sfe_init(SfeObject *b_sfe, const int32_T etypes[2],
                            const ::coder::array<real_T, 2U> &xs,
                            const ::coder::array<real_T, 2U> &qd_or_natcoords);

static inline void sfe_init(SfeObject *b_sfe,
                            const ::coder::array<real_T, 2U> &xs,
                            int32_T qd_or_natcoords,
                            const ::coder::array<real_T, 2U> &userquad);

static inline void sfe_init_grad(SfeObject *b_sfe, coder::SizeType q);

static inline void tabulate_quadratures(coder::SizeType etype,
                                        coder::SizeType qd,
                                        ::coder::array<real_T, 2U> &cs,
                                        ::coder::array<real_T, 1U> &ws);

static inline void tabulate_shapefuncs(coder::SizeType etype,
                                       const ::coder::array<real_T, 2U> &cs,
                                       ::coder::array<real_T, 2U> &sfvals,
                                       ::coder::array<real_T, 3U> &sdvals);

static inline void tabulate_shapefuncs(coder::SizeType etype,
                                       const ::coder::array<real_T, 2U> &cs,
                                       coder::SizeType varargin_2,
                                       ::coder::array<real_T, 2U> &sfvals,
                                       ::coder::array<real_T, 3U> &sdvals);

static inline void tabulate_shapefuncs3(coder::SizeType etype,
                                        const ::coder::array<real_T, 2U> &cs,
                                        ::coder::array<real_T, 2U> &sfvals,
                                        ::coder::array<real_T, 3U> &sdvals);

} // namespace sfe

#include "sfe_internal.cpp"
#endif
// End of code generation (sfe_internal.h)
