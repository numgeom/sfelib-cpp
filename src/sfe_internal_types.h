// Copyright 2022 The NumGeom Group, Stony Brook University
//
// sfe_internal_types.h
//
// Code generation for function 'obtain_elemdegree'
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
typedef int SizeType;
#endif // M2C_SIZETYPE64
} // namespace coder
#endif // CODER_ARRAY_SIZE_TYPE_DEFINED

#include "coder_array.h"

// Type Definitions
namespace sfe {
struct SfeObject {
  int etypes[2];
  int nnodes[2];
  int geom_dim;
  int topo_dim;
  signed char facetid;
  int nqp;
  ::coder::array<double, 1U> ws;
  ::coder::array<double, 2U> cs;
  ::coder::array<double, 2U> shapes_sol;
  ::coder::array<double, 2U> shapes_geom;
  ::coder::array<double, 3U> derivs_sol;
  ::coder::array<double, 3U> derivs_geom;
  ::coder::array<double, 2U> cs_phy;
  ::coder::array<double, 2U> grads_sol;
  ::coder::array<double, 2U> grads_geom;
  ::coder::array<double, 2U> jacTs;
  ::coder::array<double, 1U> wdetJ;
  ::coder::array<double, 2U> dwork1;
  ::coder::array<double, 2U> dwork2;
  ::coder::array<double, 2U> xswork;
  ::coder::array<int, 2U> iwork;
};

} // namespace sfe

#endif
// End of code generation (sfe_internal_types.h)
