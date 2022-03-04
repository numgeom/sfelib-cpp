//
// sfe_internal.h
//
// Code generation for function 'sfe_internal'
//

#ifndef SFE_INTERNAL_H
#define SFE_INTERNAL_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace sfe {
struct SfeObject;

}

// Function Declarations
namespace sfe {
static inline void sfe_apply_dbc1(::coder::array<double, 2U> &elemmat,
                           ::coder::array<double, 1U> &load,
                           const ::coder::array<boolean_T, 1U> &dtags,
                           const ::coder::array<double, 1U> &dvals,
                           const ::coder::array<int, 1U> &gdofs);

static inline void sfe_apply_dbc2(::coder::array<double, 2U> &elemmat,
                           ::coder::array<double, 1U> &load,
                           const ::coder::array<boolean_T, 1U> &dtags,
                           const ::coder::array<double, 1U> &dvals);

static inline void sfe_elem_le3d1(SfeObject *b_sfe, double nu, double lambda,
                           ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_mass1(const SfeObject *b_sfe,
                           ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_mass2(const SfeObject *b_sfe, double rho,
                           ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_mass3(const SfeObject *b_sfe,
                           const ::coder::array<double, 1U> &rho,
                           ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_stiff1(SfeObject *b_sfe, double nu,
                            ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_stiff2(SfeObject *b_sfe, double nu,
                            const double vel_data[], const int vel_size[2],
                            ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_stiff3(SfeObject *b_sfe,
                            const ::coder::array<double, 1U> &nu,
                            ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_stiff4(SfeObject *b_sfe, double nu,
                            const ::coder::array<double, 2U> &vel,
                            ::coder::array<double, 2U> &elemmat);

static inline void sfe_elem_stiff5(SfeObject *b_sfe,
                            const ::coder::array<double, 1U> &nu,
                            const ::coder::array<double, 2U> &vel, int coefftag,
                            ::coder::array<double, 2U> &elemmat);

static inline double sfe_eval_div1(const SfeObject *b_sfe,
                            const ::coder::array<double, 2U> &fs);

static inline void sfe_eval_funcs1(const SfeObject *b_sfe, int q,
                            const ::coder::array<double, 2U> &fs,
                            ::coder::array<double, 2U> &vals);

static inline void sfe_eval_grads1(const SfeObject *b_sfe,
                            const ::coder::array<double, 2U> &fs,
                            ::coder::array<double, 2U> &grads);

static inline void sfe_init1(SfeObject *b_sfe, const int etypes_data[],
                      const int etypes_size[1],
                      const ::coder::array<double, 2U> &xs,
                      const ::coder::array<double, 2U> &userquad);

static inline void sfe_init2(SfeObject *b_sfe, const int etypes_data[],
                      const int etypes_size[1],
                      const ::coder::array<double, 2U> &xs, int qd);

static inline void sfe_init3(SfeObject *b_sfe, const int etypes_data[],
                      const int etypes_size[1],
                      const ::coder::array<double, 2U> &xs);

static inline void sfe_init_grad1(SfeObject *b_sfe, int q);

static inline void sfe_init_grad2(SfeObject *b_sfe, int q);

static inline void sfe_init_grad3(SfeObject *b_sfe, int q);

static inline void sfe_init_grad4(SfeObject *b_sfe, int q);

static inline void sfe_loadvec1(const SfeObject *b_sfe,
                         const ::coder::array<double, 2U> &fs,
                         ::coder::array<double, 1U> &load);

static inline void sfe_loadvec2(const SfeObject *b_sfe,
                         const ::coder::array<double, 2U> &fs,
                         boolean_T compwise, ::coder::array<double, 1U> &load);

static inline void sfe_loadvec3(const SfeObject *b_sfe,
                         const ::coder::array<double, 2U> &fs,
                         ::coder::array<double, 1U> &load);

} // namespace sfe

#include "sfe_internal.cpp"
#endif
// End of code generation (sfe_internal.h)
