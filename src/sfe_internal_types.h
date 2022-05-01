// Copyright 2022 The NumGeom Group, Stony Brook University
//
// sfe_internal_types.h
//
// Code generation for function 'sfe_bnd_init'
//

#ifndef SFE_INTERNAL_TYPES_H
#define SFE_INTERNAL_TYPES_H

// Include files
#include "rtwtypes.h"
#ifndef CODER_ARRAY_SIZE_TYPE_DEFINED
#define CODER_ARRAY_SIZE_TYPE_DEFINED
namespace coder {
#ifdef M2C_SIZETYPE64
typedef int64_T SizeType;
#else
typedef int32_T SizeType;
#endif // M2C_SIZETYPE64
} // namespace coder
#endif // CODER_ARRAY_SIZE_TYPE_DEFINED

#include "coder_array.h"
#define MAX_THREADS omp_get_max_threads()

// Type Definitions
namespace sfe {
struct SfeObject {
  int32_T etypes[2];
  int32_T nnodes[2];
  int32_T geom_dim;
  int32_T topo_dim;
  int8_T facetid;
  int32_T nqp;
  ::coder::array<real_T, 1U> ws;
  ::coder::array<real_T, 2U> cs;
  ::coder::array<real_T, 2U> shapes_sol;
  ::coder::array<real_T, 2U> shapes_geom;
  ::coder::array<real_T, 3U> derivs_sol;
  ::coder::array<real_T, 3U> derivs_geom;
  ::coder::array<real_T, 2U> cs_phy;
  ::coder::array<real_T, 2U> grads_sol;
  ::coder::array<real_T, 2U> grads_geom;
  ::coder::array<real_T, 2U> jacTs;
  ::coder::array<real_T, 1U> wdetJ;
  ::coder::array<real_T, 2U> dwork1;
  ::coder::array<real_T, 2U> dwork2;
  ::coder::array<real_T, 2U> xswork;
  ::coder::array<int32_T, 2U> iwork;
};

} // namespace sfe

#endif
// End of code generation (sfe_internal_types.h)
