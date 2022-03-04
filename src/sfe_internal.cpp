//
// sfe_internal.cpp
//
// Code generation for function 'sfe_internal'
//

// Include files
#include "sfe_internal.h"
#include "sfe_internal_types.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Variable Definitions
namespace sfe
{
  static const int iv[250]{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 4,
    4, 0, 0, 5, 5, 0, 0, 6, 6, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0,
    0, 6, 0, 0, 0, 10, 10, 0, 0, 15, 15, 15, 0, 21, 21, 21, 0, 28, 28, 28, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 9, 0, 0, 0, 16, 16, 0, 0, 25, 25, 0, 0, 36,
    36, 0, 0, 49, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 10, 0, 0, 0, 20,
    20, 0, 0, 35, 35, 35, 0, 56, 56, 56, 0, 84, 84, 84, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 5, 0, 0, 0, 14, 0, 0, 0, 30, 30, 0, 0, 55, 55, 55, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 18, 0, 0, 0, 40, 40, 0, 0, 75, 75, 75,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 27, 0, 0, 0,
    64, 64, 0, 0, 125, 125, 0, 0, 216, 216, 0, 0, 343, 343, MAX_int32_T };

  static const signed char iv1[36]{ 1, 2, 2, 1, 3, 4, 5, 6, 2, 2, 2, 2, 6, 5, 4,
    3, 1, 1, 1, 1, 3, 4, 5, 6, 6, 6, 6, 5, 4, 3, 3, 3, 4, 5, 5, 4 };

  static const signed char iv2[36]{ 1, 1, 2, 2, 1, 1, 1, 1, 3, 4, 5, 6, 2, 2, 2,
    2, 6, 5, 4, 3, 3, 3, 3, 3, 4, 5, 6, 6, 6, 6, 5, 4, 4, 4, 5, 5 };

  static const signed char iv3[25]{ 1, 2, 2, 1, 3, 4, 5, 2, 2, 2, 5, 4, 3, 1, 1,
    1, 3, 4, 5, 5, 5, 4, 3, 3, 4 };

  static const signed char iv4[25]{ 1, 1, 2, 2, 1, 1, 1, 3, 4, 5, 2, 2, 2, 5, 4,
    3, 3, 3, 3, 4, 5, 5, 5, 4, 4 };

  static const signed char iv5[16]{ 1, 2, 2, 1, 3, 4, 2, 2, 4, 3, 1, 1, 3, 4, 4,
    3 };

  static const signed char iv6[16]{ 1, 1, 2, 2, 1, 1, 3, 4, 2, 2, 4, 3, 3, 3, 4,
    4 };

  static const double dv[6]{ 0.66666666666666663, 0.16666666666666666,
    0.16666666666666666, 0.66666666666666663, 0.16666666666666666,
    0.16666666666666666 };

  static const double dv1[6]{ 0.054975871827661, 0.054975871827661,
    0.054975871827661, 0.1116907948390055, 0.1116907948390055,
    0.1116907948390055 };

  static const double dv2[12]{ 0.816847572980459, 0.091576213509771,
    0.091576213509771, 0.816847572980459, 0.091576213509771, 0.091576213509771,
    0.10810301816807, 0.445948490915965, 0.445948490915965, 0.10810301816807,
    0.445948490915965, 0.445948490915965 };

  static const double dv3[14]{ 0.33333333333333331, 0.33333333333333331,
    0.101286507323456, 0.101286507323456, 0.797426985353087, 0.101286507323456,
    0.101286507323456, 0.797426985353087, 0.470142064105115, 0.470142064105115,
    0.05971587178977, 0.470142064105115, 0.470142064105115, 0.05971587178977 };

  static const double dv4[7]{ 0.1125, 0.062969590272413584, 0.062969590272413584,
    0.062969590272413584, 0.066197076394253, 0.066197076394253,
    0.066197076394253 };

  static const double dv5[24]{ 0.062382265094402, 0.067517867073916,
    0.067517867073916, 0.870099867831682, 0.870099867831682, 0.062382265094402,
    0.055225456656927, 0.321502493851982, 0.321502493851982, 0.623272049491092,
    0.623272049491092, 0.055225456656927, 0.034324302945097, 0.660949196186736,
    0.660949196186736, 0.304726500868167, 0.304726500868167, 0.034324302945097,
    0.515842334353592, 0.277716166976392, 0.277716166976392, 0.206441498670016,
    0.206441498670016, 0.515842334353592 };

  static const double dv6[12]{ 0.026517028157436, 0.026517028157436,
    0.026517028157436, 0.043881408714446, 0.043881408714446, 0.043881408714446,
    0.028775042784982, 0.028775042784982, 0.028775042784982, 0.067493187009803,
    0.067493187009803, 0.067493187009803 };

  static const double dv7[24]{ 0.062382265094402117, 0.067517867073916091,
    0.87009986783168181, 0.062382265094402117, 0.067517867073916091,
    0.87009986783168181, 0.055225456656926609, 0.32150249385198182,
    0.623272049491092, 0.055225456656926609, 0.32150249385198182,
    0.623272049491092, 0.034324302945097147, 0.66094919618673564,
    0.304726500868167, 0.034324302945097147, 0.66094919618673564,
    0.304726500868167, 0.51584233435359172, 0.27771616697639179,
    0.206441498670016, 0.515842334353592, 0.27771616697639179, 0.206441498670016
  };

  static const double dv8[12]{ 0.02651702815743625, 0.02651702815743625,
    0.02651702815743625, 0.043881408714446055, 0.043881408714446055,
    0.043881408714446055, 0.028775042784981584, 0.028775042784981584,
    0.028775042784981584, 0.06749318700980278, 0.06749318700980278,
    0.06749318700980278 };

  static const double dv9[32]{ 0.33333333333333331, 0.33333333333333331,
    0.17056930775176021, 0.17056930775176021, 0.65886138449647957,
    0.17056930775176021, 0.17056930775176021, 0.65886138449647957,
    0.050547228317030977, 0.050547228317030977, 0.89890554336593809,
    0.050547228317030977, 0.050547228317030977, 0.89890554336593809,
    0.45929258829272313, 0.45929258829272313, 0.45929258829272313,
    0.0814148234145537, 0.0814148234145537, 0.45929258829272313,
    0.72849239295540424, 0.26311282963463811, 0.26311282963463811,
    0.72849239295540424, 0.72849239295540424, 0.00839477740995761,
    0.00839477740995761, 0.72849239295540424, 0.26311282963463811,
    0.00839477740995761, 0.00839477740995761, 0.26311282963463811 };

  static const double dv10[16]{ 0.072157803838893586, 0.051608685267359122,
    0.051608685267359122, 0.051608685267359122, 0.01622924881159904,
    0.01622924881159904, 0.01622924881159904, 0.04754581713364231,
    0.04754581713364231, 0.04754581713364231, 0.013615157087217496,
    0.013615157087217496, 0.013615157087217496, 0.013615157087217496,
    0.013615157087217496, 0.013615157087217496 };

  static const double dv11[38]{ 0.33333333333333331, 0.33333333333333331,
    0.48968251919873762, 0.48968251919873762, 0.48968251919873762,
    0.02063496160252476, 0.02063496160252476, 0.48968251919873762,
    0.43708959149293664, 0.43708959149293664, 0.43708959149293664,
    0.125820817014127, 0.125820817014127, 0.43708959149293664,
    0.18820353561903272, 0.18820353561903272, 0.62359292876193451,
    0.18820353561903272, 0.18820353561903272, 0.62359292876193451,
    0.044729513394452712, 0.044729513394452712, 0.91054097321109462,
    0.044729513394452712, 0.044729513394452712, 0.91054097321109462,
    0.741198598784498, 0.036838412054736286, 0.036838412054736286,
    0.741198598784498, 0.741198598784498, 0.22196298916076571,
    0.036838412054736286, 0.22196298916076571, 0.22196298916076571,
    0.036838412054736286, 0.22196298916076571, 0.741198598784498 };

  static const double dv12[19]{ 0.048567898141399418, 0.015667350113569536,
    0.015667350113569536, 0.015667350113569536, 0.038913770502387139,
    0.038913770502387139, 0.038913770502387139, 0.039823869463605124,
    0.039823869463605124, 0.039823869463605124, 0.012788837829349016,
    0.012788837829349016, 0.012788837829349016, 0.021641769688644688,
    0.021641769688644688, 0.021641769688644688, 0.021641769688644688,
    0.021641769688644688, 0.021641769688644688 };

  static const double dv13[5]{ 0.046910077030668, 0.230765344947158, 0.5,
    0.769234655052842, 0.953089922969332 };

  static const double dv14[5]{ 0.118463442528095, 0.239314335249683,
    0.284444444444444, 0.239314335249683, 0.118463442528095 };

  static const double dv15[6]{ 0.38069040695840156, 0.61930959304159849,
    0.16939530676686776, 0.83060469323313224, 0.033765242898423975,
    0.966234757101576 };

  static const double dv16[6]{ 0.23395696728634549, 0.23395696728634549,
    0.18038078652406919, 0.18038078652406919, 0.085662246189585151,
    0.085662246189585151 };

  static const double dv17[7]{ 0.5, 0.29707742431130141, 0.70292257568869854,
    0.12923440720030277, 0.87076559279969723, 0.0254460438286207,
    0.9745539561713793 };

  static const double dv18[7]{ 0.2089795918367347, 0.19091502525255941,
    0.19091502525255941, 0.13985269574463802, 0.13985269574463802,
    0.064742483084434879, 0.064742483084434879 };
}

// Function Declarations
namespace sfe
{
  static inline
  void b_fe1_quadrule(int degree, double ws_data[], int *ws_size, double
    cs_data[], int *cs_size);
  static inline
  void bar_3(double xi, double shape_funcs[3], double deriv[3]);
  static inline
  void bar_4(double xi, double shape_funcs[4], double deriv[4]);
  static inline
  void bar_5(double xi, double shape_funcs[5], double deriv[5]);
  static inline
  void bar_6(double xi, double shape_funcs[6], double deriv[6]);
  static inline
  void bar_7(double xi, double shape_funcs[7], double deriv[7]);
  static inline
  void bar_gl_4(double xi, double shape_funcs[4], double deriv[4]);
  static inline
  void bar_gl_5(double xi, double shape_funcs[5], double deriv[5]);
  static inline
  void bar_gl_6(double xi, double shape_funcs[6], double deriv[6]);
  static inline
  void bar_gl_7(double xi, double shape_funcs[7], double deriv[7]);
  namespace coder
  {
    static inline
    void meshgrid(const double x_data[], int x_size, const double y_data[],
                         int y_size, const double z_data[], int z_size, double
                         xx_data[], int xx_size[3], double yy_data[], int
                         yy_size[3], double zz_data[], int zz_size[3]);
    static inline
    void repmat(const double a_data[], const int a_size[2], const double
                       varargin_1[2], double b_data[], int b_size[2]);
  }

  static inline
  void fe1_quadrule(int degree, double ws_data[], int *ws_size, double
    cs_data[], int *cs_size);
  static inline
  void fe2_quadrule(int degree, double ws_data[], int *ws_size, double
    cs_data[], int cs_size[2]);
  static inline
  void fe3_quadrule(int nv, int degree, double ws_data[], int *ws_size,
    double cs_data[], int cs_size[2], int *nqp);
  static inline
  void quad_9(double xi, double eta, double shape_funcs[9], double deriv
                     [18]);
  static inline
  void sfe1_tabulate_shapefuncs(int etype, const double cs_data[], const
    int cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double,
    3U> &derivs);
  static inline
  void sfe2_tabulate_equi(int etype, const double cs_data[], const int
    cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double, 3U>
    &derivs);
  static inline
  void sfe2_tabulate_equi_tri(int etype, const double cs_data[], const
    int cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double,
    3U> &derivs);
  static inline
  void sfe2_tabulate_gl_tri(int etype, const double cs_data[], const int
    cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double, 3U>
    &derivs);
  static inline
  void sfe2_tabulate_shapefuncs(int etype, const double cs_data[], const
    int cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double,
    3U> &derivs);
  static inline
  void sfe3_tabulate_shapefuncs(int etype, const double cs_data[], const
    int cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double,
    3U> &derivs);
  static inline
  void sfe_init_grad(SfeObject *b_sfe, int q);
  static inline
  boolean_T solve_sq(double J[9], int n, ::coder::array<double, 2U> &b1, ::
    coder::array<double, 2U> &b2);
  static inline
  boolean_T solve_sq(double J[9], int n, ::coder::array<double, 2U> &b1);
  static inline
  void tabulate_quadratures(int etype, int qd, int *nqp, double ws_data[],
    int *ws_size, double cs_data[], int cs_size[2]);
  static inline
  void tabulate_shapefuncs(int etype, const double cs_data[], const int
    cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double, 3U>
    &derivs);
  static inline
  void tet_10(double xi, double eta, double zeta, double shape_funcs[10],
                     double deriv[30]);
  static inline
  void tet_20(double xi, double eta, double zeta, double shape_funcs[20],
                     double deriv[60]);
  static inline
  void tet_35(double xi, double eta, double zeta, double shape_funcs[35],
                     double deriv[105]);
  static inline
  void tri_10(double xi, double eta, double shape_funcs[10], double
                     deriv[20]);
  static inline
  void tri_15(double xi, double eta, double shape_funcs[15], double
                     deriv[30]);
  static inline
  void tri_21(double xi, double eta, double shape_funcs[21], double
                     deriv[42]);
  static inline
  void tri_28(double xi, double eta, double shape_funcs[28], double
                     deriv[56]);
  static inline
  void tri_6(double xi, double eta, double shape_funcs[6], double deriv
                    [12]);
  static inline
  void tri_fek_21(double xi, double eta, double shape_funcs[21], double
    deriv[42]);
  static inline
  void tri_fek_28(double xi, double eta, double shape_funcs[28], double
    deriv[56]);
  static inline
  void tri_gl_15(double xi, double eta, double shape_funcs[15], double
                        deriv[30]);
  static inline
  void tri_gl_21(double xi, double eta, double shape_funcs[21], double
                        deriv[42]);
}

// Function Definitions
namespace sfe
{
  static inline
  void b_fe1_quadrule(int degree, double ws_data[], int *ws_size, double
    cs_data[], int *cs_size)
  {
    //  Obtain quadrature points of a 1-D element.
    if (degree <= 3) {
      *cs_size = 2;
      *ws_size = 2;
      cs_data[0] = 0.211324865405187;
      ws_data[0] = 0.5;
      cs_data[1] = 0.788675134594813;
      ws_data[1] = 0.5;
    } else if (degree <= 5) {
      *cs_size = 3;
      *ws_size = 3;
      cs_data[0] = 0.112701665379258;
      ws_data[0] = 0.27777777777777779;
      cs_data[1] = 0.5;
      ws_data[1] = 0.44444444444444442;
      cs_data[2] = 0.887298334620742;
      ws_data[2] = 0.27777777777777779;
    } else if (degree <= 7) {
      *cs_size = 4;
      *ws_size = 4;
      cs_data[0] = 0.069431844202974;
      ws_data[0] = 0.173927422568727;
      cs_data[1] = 0.330009478207572;
      ws_data[1] = 0.326072577431273;
      cs_data[2] = 0.669990521792428;
      ws_data[2] = 0.326072577431273;
      cs_data[3] = 0.930568155797026;
      ws_data[3] = 0.173927422568727;
    } else if (degree <= 8) {
      *cs_size = 5;
      *ws_size = 5;
      for (int i{0}; i < 5; i++) {
        cs_data[i] = dv13[i];
        ws_data[i] = dv14[i];
      }
    } else if (degree <= 9) {
      *cs_size = 6;
      *ws_size = 6;
      for (int i{0}; i < 6; i++) {
        cs_data[i] = dv15[i];
        ws_data[i] = dv16[i];
      }
    } else {
      *cs_size = 7;
      *ws_size = 7;
      for (int i{0}; i < 7; i++) {
        cs_data[i] = dv17[i];
        ws_data[i] = dv18[i];
      }
    }
  }

  static inline
  void bar_3(double xi, double shape_funcs[3], double deriv[3])
  {
    double t2;
    double t3;
    double t4;

    // BAR_3   Quadratic bar element
    t2 = 4.0 * xi;
    t3 = xi * xi;
    t4 = t3 * 2.0;
    shape_funcs[0] = (t4 + -3.0 * xi) + 1.0;
    shape_funcs[1] = t4 + -xi;
    shape_funcs[2] = t2 - t3 * 4.0;
    deriv[0] = t2 - 3.0;
    deriv[1] = t2 - 1.0;
    deriv[2] = -8.0 * xi + 4.0;
  }

  static inline
  void bar_4(double xi, double shape_funcs[4], double deriv[4])
  {
    double t2;
    double t3;
    double t4;
    double t5;
    double t6;
    double t7;
    double t8;

    // BAR_4  Cubic bar element with equidistant nodes
    t2 = xi * xi;
    t3 = std::pow(xi, 3.0);
    t4 = 9.0 * xi;
    t5 = t3 * 4.5;
    t6 = t2 * 13.5;
    t7 = t3 * 13.5;
    shape_funcs[0] = ((t2 * 9.0 - t5) + -5.5 * xi) + 1.0;
    shape_funcs[1] = (t2 * -4.5 + t5) + xi;
    shape_funcs[2] = (t2 * -22.5 + t4) + t7;
    shape_funcs[3] = (t2 * 18.0 - t7) + -4.5 * xi;
    t8 = t2 * 40.5;
    deriv[0] = (-t6 + 18.0 * xi) - 5.5;
    deriv[1] = (-t4 + t6) + 1.0;
    deriv[2] = (t8 + -45.0 * xi) + 9.0;
    deriv[3] = (-t8 + 36.0 * xi) - 4.5;
  }

  static inline
  void bar_5(double xi, double shape_funcs[5], double deriv[5])
  {
    double t2;
    double t3;
    double t4;
    double t5;
    double t6;
    double t7;
    double t9;

    // BAR_5  Quartic bar element with equidistant nodes
    t2 = xi * xi;
    t3 = std::pow(xi, 3.0);
    t4 = t2 * t2;
    t6 = t3 * 42.666666666666664;
    t9 = t3 * 170.66666666666666;
    t5 = t4 * 10.666666666666666;
    t7 = t4 * 42.666666666666664;
    shape_funcs[0] = (((t2 * 23.333333333333332 - t3 * 26.666666666666668) + t5)
                      + -8.3333333333333339 * xi) + 1.0;
    shape_funcs[1] = ((t2 * 7.333333333333333 - t3 * 16.0) + t5) + -xi;
    shape_funcs[2] = ((t2 * -69.333333333333329 + t3 * 96.0) - t7) + 16.0 * xi;
    shape_funcs[3] = ((t2 * 76.0 - t3 * 128.0) + t4 * 64.0) + -12.0 * xi;
    shape_funcs[4] = ((t2 * -37.333333333333336 + t3 * 74.666666666666671) - t7)
      + 5.333333333333333 * xi;
    deriv[0] = ((t2 * -80.0 + t6) + 46.666666666666664 * xi) -
      8.3333333333333339;
    deriv[1] = ((t2 * -48.0 + t6) + 14.666666666666666 * xi) - 1.0;
    deriv[2] = ((t2 * 288.0 - t9) + -138.66666666666666 * xi) + 16.0;
    deriv[3] = ((t2 * -384.0 + t3 * 256.0) + 152.0 * xi) - 12.0;
    deriv[4] = ((t2 * 224.0 - t9) + -74.666666666666671 * xi) +
      5.333333333333333;
  }

  static inline
  void bar_6(double xi, double shape_funcs[6], double deriv[6])
  {
    double t10;
    double t11;
    double t12;
    double t2;
    double t3;
    double t4;
    double t5;
    double t6;
    double t7;
    double t8;
    double t9;

    // BAR_6   Quintic bar element with equidistant nodes
    t2 = xi * xi;
    t3 = std::pow(xi, 3.0);
    t5 = std::pow(xi, 5.0);
    t6 = 25.0 * xi;
    t4 = t2 * t2;
    t7 = t5 * 26.041666666666668;
    t8 = t5 * 260.41666666666669;
    t10 = t5 * 130.20833333333329;
    shape_funcs[0] = ((((t2 * 46.875 - t3 * 88.541666666666671) + t4 * 78.125) -
                       t7) + -11.416666666666666 * xi) + 1.0;
    shape_funcs[1] = (((t2 * -10.416666666666666 + t3 * 36.458333333333336) - t4
                       * 52.083333333333336) + t7) + xi;
    shape_funcs[2] = (((t2 * -160.41666666666671 + t3 * 369.79166666666669) - t4
                       * 364.58333333333331) + t6) + t10;
    shape_funcs[3] = (((t2 * 222.91666666666671 - t3 * 614.58333333333326) + t4 *
                       677.08333333333326) - t6) - t8;
    shape_funcs[4] = (((t2 * -162.5 + t3 * 510.41666666666669) - t4 * 625.0) +
                      t8) + 16.666666666666668 * xi;
    shape_funcs[5] = (((t2 * 63.541666666666671 - t3 * 213.54166666666671) + t4 *
                       286.45833333333331) - t10) + -6.25 * xi;
    t9 = t4 * 130.20833333333329;
    t11 = t4 * 1302.083333333333;
    t12 = t4 * 651.04166666666674;
    deriv[0] = (((t2 * -265.625 + t3 * 312.5) - t9) + 93.75 * xi) -
      11.416666666666666;
    deriv[1] = (((t2 * 109.375 - t3 * 208.33333333333334) + t9) +
                -20.833333333333332 * xi) + 1.0;
    deriv[2] = (((t2 * 1109.375 - t3 * 1458.333333333333) + t12) +
                -320.83333333333331 * xi) + 25.0;
    deriv[3] = (((t2 * -1843.75 + t3 * 2708.333333333333) - t11) +
                445.83333333333331 * xi) - 25.0;
    deriv[4] = (((t2 * 1531.25 - t3 * 2500.0) + t11) + -325.0 * xi) +
      16.666666666666668;
    deriv[5] = (((t2 * -640.625 + t3 * 1145.833333333333) - t12) +
                127.0833333333333 * xi) - 6.25;
  }

  static inline
  void bar_7(double xi, double shape_funcs[7], double deriv[7])
  {
    double t10;
    double t11;
    double t13;
    double t2;
    double t3;
    double t4;
    double t5;
    double t6;
    double t7;
    double t8;
    double t9;

    // BAR_7   Sextic bar element with equidistant nodes
    t2 = xi * xi;
    t3 = std::pow(xi, 3.0);
    t5 = std::pow(xi, 5.0);
    t4 = t2 * t2;
    t6 = std::pow(t2, 3.0);
    t8 = t5 * 5832.0;
    t10 = t5 * 388.8;
    t13 = t5 * 2332.8;
    t7 = t6 * 972.0;
    t9 = t6 * 64.8;
    t11 = t6 * 388.8;
    shape_funcs[0] = (((((t2 * 81.2 - t3 * 220.5) + t4 * 315.0) - t5 * 226.8) +
                       t9) + -14.7 * xi) + 1.0;
    shape_funcs[1] = ((((t2 * 13.7 - t3 * 67.5) + t4 * 153.0) - t5 * 162.0) + t9)
      + -xi;
    shape_funcs[2] = ((((t2 * -313.2 + t3 * 1044.0) - t4 * 1674.0) + t5 * 1296.0)
                      - t11) + 36.0 * xi;
    shape_funcs[3] = ((((t2 * 526.5 - t3 * 2074.5) + t4 * 3699.0) - t5 * 3078.0)
                      + t7) + -45.0 * xi;
    shape_funcs[4] = ((((t2 * -508.0 + t3 * 2232.0) - t4 * 4356.0) + t5 * 3888.0)
                      - t6 * 1296.0) + 40.0 * xi;
    shape_funcs[5] = ((((t2 * 297.0 - t3 * 1381.5) + t4 * 2889.0) - t5 * 2754.0)
                      + t7) + -22.5 * xi;
    shape_funcs[6] = ((((t2 * -97.2 + t3 * 468.0) - t4 * 1026.0) + t5 * 1036.8)
                      - t11) + 7.2 * xi;
    deriv[0] = ((((t2 * -661.5 + t3 * 1260.0) - t4 * 1134.0) + t10) + 162.4 * xi)
      - 14.7;
    deriv[1] = ((((t2 * -202.5 + t3 * 612.0) - t4 * 810.0) + t10) + 27.4 * xi) -
      1.0;
    deriv[2] = ((((t2 * 3132.0 - t3 * 6696.0) + t4 * 6480.0) - t13) + -626.4 *
                xi) + 36.0;
    deriv[3] = ((((t2 * -6223.5 + t3 * 14796.0) - t4 * 15390.0) + t8) + 1053.0 *
                xi) - 45.0;
    deriv[4] = ((((t2 * 6696.0 - t3 * 17424.0) + t4 * 19440.0) - t5 * 7776.0) +
                -1016.0 * xi) + 40.0;
    deriv[5] = ((((t2 * -4144.5 + t3 * 11556.0) - t4 * 13770.0) + t8) + 594.0 *
                xi) - 22.5;
    deriv[6] = ((((t2 * 1404.0 - t3 * 4104.0) + t4 * 5184.0) - t13) + -194.4 *
                xi) + 7.2;
  }

  static inline
  void bar_gl_4(double xi, double shape_funcs[4], double deriv[4])
  {
    double t2;
    double t3;
    double t4;
    double t6;

    // BAR_GL_4  Cubic bar element with Gauss-Lobatto nodes
    t2 = xi * xi;
    t3 = std::pow(xi, 3.0);
    t4 = t3 * 5.0;
    shape_funcs[0] = ((t2 * 10.0 - t4) + -6.0 * xi) + 1.0;
    shape_funcs[1] = (t2 * -5.0 + t4) + xi;
    shape_funcs[2] = (t2 * -19.270509831248422 + t4 * 2.23606797749979) +
      8.0901699437494745 * xi;
    shape_funcs[3] = (t2 * 14.27050983124842 - t3 * 2.23606797749979 * 5.0) +
      -3.0901699437494741 * xi;
    t6 = t2 * 15.0;
    deriv[0] = (-t6 + 20.0 * xi) - 6.0;
    deriv[1] = (t6 + -10.0 * xi) + 1.0;
    deriv[2] = (2.23606797749979 * t6 + -38.541019662496844 * xi) +
      8.0901699437494745;
    deriv[3] = (28.541019662496851 * xi - t2 * 2.23606797749979 * 15.0) -
      3.0901699437494741;
  }

  static inline
  void bar_gl_5(double xi, double shape_funcs[5], double deriv[5])
  {
    double t2;
    double t3;
    double t4;
    double t5;
    double t6;
    double t7;
    double t8;

    // BAR_GL_5  Quartic bar element with Gauss-Lobatto nodes
    t2 = xi * xi;
    t3 = std::pow(xi, 3.0);
    t4 = t2 * t2;
    t6 = t3 * 56.0;
    t8 = t3 * 130.66666666666666;
    t5 = t4 * 14.0;
    t7 = t4 * 32.666666666666664;
    shape_funcs[0] = (((t2 * 30.0 - t3 * 35.0) + t5) + -10.0 * xi) + 1.0;
    shape_funcs[1] = ((t2 * 9.0 - t3 * 21.0) + t5) + -xi;
    shape_funcs[2] = ((t2 * -56.872348265678767 + t3 * 76.026009954896963) - t7)
      + 13.51300497744848 * xi;
    shape_funcs[3] = ((t2 * 42.666666666666664 - t3 * 74.666666666666671) + t4 *
                      37.333333333333336) + -5.333333333333333 * xi;
    shape_funcs[4] = ((t2 * -24.794318400987891 + t3 * 54.640656711769708) - t7)
      + 2.820328355884854 * xi;
    deriv[0] = ((t2 * -105.0 + t6) + 60.0 * xi) - 10.0;
    deriv[1] = ((t2 * -63.0 + t6) + 18.0 * xi) - 1.0;
    deriv[2] = ((t2 * 228.0780298646909 - t8) + -113.7446965313575 * xi) +
      13.51300497744848;
    deriv[3] = ((t2 * -224.0 + t3 * 149.33333333333334) + 85.333333333333329 *
                xi) - 5.333333333333333;
    deriv[4] = ((t2 * 163.9219701353091 - t8) + -49.588636801975788 * xi) +
      2.820328355884854;
  }

  static inline
  void bar_gl_6(double xi, double shape_funcs[6], double deriv[6])
  {
    double t10;
    double t11;
    double t2;
    double t3;
    double t4;
    double t5;
    double t6;
    double t7;
    double t8;
    double t9;

    // BAR_GL_6   Quintic bar element with Gauss-Lobatto nodes
    t2 = xi * xi;
    t3 = std::pow(xi, 3.0);
    t5 = std::pow(xi, 5.0);
    t4 = t2 * t2;
    t6 = t5 * 42.0;
    t10 = t5 * 100.0722106463179;
    t11 = t5 * 121.1674570846437;
    shape_funcs[0] = ((((t2 * 70.0 - t3 * 140.0) + t4 * 126.0) - t6) + -15.0 *
                      xi) + 1.0;
    shape_funcs[1] = (((t2 * -14.0 + t3 * 56.0) - t4 * 84.0) + t6) + xi;
    shape_funcs[2] = (((t2 * -131.58198446299679 + t3 * 299.68785732601259) - t4
                       * 288.46091538197311) + t10) + 20.282831872639338 * xi;
    shape_funcs[3] = (((t2 * 98.49823568607377 - t3 * 289.45743553860677) + t4 *
                       320.1990314777874) - t11) + -8.0723745406106957 * xi;
    shape_funcs[4] = (((t2 * -60.354452909459013 + t3 * 220.335880473894) - t4 *
                       285.638253945431) + t11) + 4.4893692963523337 * xi;
    shape_funcs[5] = (((t2 * 37.438201686382072 - t3 * 146.5663022612998) + t4 *
                       211.9001378496167) - t10) + -2.699826628380976 * xi;
    t7 = t4 * 210.0;
    t8 = t4 * 605.83728542321842;
    t9 = t4 * 500.36105323158972;
    deriv[0] = (((t2 * -420.0 + t3 * 504.0) - t7) + 140.0 * xi) - 15.0;
    deriv[1] = (((t2 * 168.0 - t3 * 336.0) + t7) + -28.0 * xi) + 1.0;
    deriv[2] = (((t2 * 899.06357197803788 - t3 * 1153.843661527892) + t9) +
                -263.16396892599357 * xi) + 20.282831872639338;
    deriv[3] = (((t2 * -868.37230661582043 + t3 * 1280.79612591115) - t8) +
                196.99647137214751 * xi) - 8.0723745406106957;
    deriv[4] = (((t2 * 661.007641421682 - t3 * 1142.5530157817241) + t8) +
                -120.708905818918 * xi) + 4.4893692963523337;
    deriv[5] = (((t2 * -439.69890678389942 + t3 * 847.60055139846668) - t9) +
                74.87640337276413 * xi) - 2.699826628380976;
  }

  static inline
  void bar_gl_7(double xi, double shape_funcs[7], double deriv[7])
  {
    double t10;
    double t11;
    double t12;
    double t2;
    double t3;
    double t4;
    double t5;
    double t6;
    double t7;
    double t8;
    double t9;

    // BAR_GL_7
    t2 = xi * xi;
    t3 = std::pow(xi, 3.0);
    t5 = std::pow(xi, 5.0);
    t4 = t2 * t2;
    t6 = std::pow(t2, 3.0);
    t8 = t5 * 792.0;
    t9 = t5 * 2384.7819671373918;
    t11 = t5 * 1909.581967137392;
    t7 = t6 * 132.0;
    t10 = t6 * 397.4636611895653;
    t12 = t6 * 318.26366118956531;
    shape_funcs[0] = (((((t2 * 140.0 - t3 * 420.0) + t4 * 630.0) - t5 * 462.0) +
                       t7) + -21.0 * xi) + 1.0;
    shape_funcs[1] = ((((t2 * 20.0 - t3 * 120.0) + t4 * 300.0) - t5 * 330.0) +
                      t7) + -xi;
    shape_funcs[2] = ((((t2 * -261.87079920132538 + t3 * 891.54559526444336) -
                        t4 * 1426.72032006643) + t5 * 1086.9060319870371) - t12)
      + 28.403153205839629 * xi;
    shape_funcs[3] = ((((t2 * 195.405316227204 - t3 * 851.53549091544392) + t4 *
                        1555.570646517052) - t5 * 1285.566162567286) + t10) +
      -11.337970451091021 * xi;
    shape_funcs[4] = ((((t2 * -121.6 + t3 * 652.8) - t4 * 1382.4) + t5 * 1267.2)
                      - t6 * 422.4) + 6.4 * xi;
    shape_funcs[5] = ((((t2 * 80.516014753801173 - t3 * 464.358693271208) + t4 *
                        1089.6947515241011) - t5 * 1099.215804570106) + t10) +
      -4.0999296261534859 * xi;
    shape_funcs[6] = ((((t2 * -52.450531779679778 + t3 * 311.54858892220858) -
                        t4 * 766.145077974723) + t5 * 822.67593515035469) - t12)
      + 2.634746871404869 * xi;
    deriv[0] = ((((t2 * -1260.0 + t3 * 2520.0) - t4 * 2310.0) + t8) + 280.0 * xi)
      - 21.0;
    deriv[1] = ((((t2 * -360.0 + t3 * 1200.0) - t4 * 1650.0) + t8) + 40.0 * xi)
      - 1.0;
    deriv[2] = ((((t2 * 2674.63678579333 - t3 * 5706.8812802657176) + t4 *
                  5434.530159935186) - t11) + -523.74159840265077 * xi) +
      28.403153205839629;
    deriv[3] = ((((t2 * -2554.6064727463322 + t3 * 6222.2825860682078) - t4 *
                  6427.8308128364306) + t9) + 390.810632454408 * xi) -
      11.337970451091021;
    deriv[4] = ((((t2 * 1958.4 - t3 * 5529.6) + t4 * 6336.0) - t5 * 2534.4) +
                -243.2 * xi) + 6.4;
    deriv[5] = ((((t2 * -1393.0760798136239 + t3 * 4358.7790060964026) - t4 *
                  5496.0790228505284) + t9) + 161.03202950760229 * xi) -
      4.0999296261534859;
    deriv[6] = ((((t2 * 934.64576676662568 - t3 * 3064.580311898892) + t4 *
                  4113.379675751773) - t11) + -104.9010635593596 * xi) +
      2.634746871404869;
  }

  namespace coder
  {
    static inline
    void meshgrid(const double x_data[], int x_size, const double y_data[],
                         int y_size, const double z_data[], int z_size, double
                         xx_data[], int xx_size[3], double yy_data[], int
                         yy_size[3], double zz_data[], int zz_size[3])
    {
      xx_size[2] = static_cast<signed char>(z_size);
      xx_size[1] = static_cast<signed char>(x_size);
      xx_size[0] = static_cast<signed char>(y_size);
      yy_size[2] = static_cast<signed char>(z_size);
      yy_size[1] = static_cast<signed char>(x_size);
      yy_size[0] = static_cast<signed char>(y_size);
      zz_size[2] = static_cast<signed char>(z_size);
      zz_size[1] = static_cast<signed char>(x_size);
      zz_size[0] = static_cast<signed char>(y_size);
      for (int i{0}; i < y_size; i++) {
        for (int j{0}; j < x_size; j++) {
          for (int k{0}; k < z_size; k++) {
            xx_data[(k + static_cast<signed char>(z_size) * j) + static_cast<
              signed char>(x_size) * static_cast<signed char>(z_size) * i] =
              x_data[j];
            yy_data[(k + static_cast<signed char>(z_size) * j) + static_cast<
              signed char>(x_size) * static_cast<signed char>(z_size) * i] =
              y_data[i];
            zz_data[(k + static_cast<signed char>(z_size) * j) + static_cast<
              signed char>(x_size) * static_cast<signed char>(z_size) * i] =
              z_data[k];
          }
        }
      }
    }

    static inline
    void repmat(const double a_data[], const int a_size[2], const double
                       varargin_1[2], double b_data[], int b_size[2])
    {
      int i;
      b_size[1] = static_cast<signed char>(a_size[1]);
      b_size[0] = static_cast<signed char>(static_cast<int>(varargin_1[0]));
      i = static_cast<int>(varargin_1[0]) - 1;
      for (int t{0}; t <= i; t++) {
        int na;
        na = a_size[1];
        for (int k{0}; k < na; k++) {
          b_data[k + b_size[1] * t] = a_data[k];
        }
      }
    }
  }

  static inline
  void fe1_quadrule(int degree, double ws_data[], int *ws_size, double
    cs_data[], int *cs_size)
  {
    //  Obtain quadrature points of a 1-D element.
    if (degree <= 5) {
      *cs_size = 3;
      *ws_size = 3;
      cs_data[0] = 0.112701665379258;
      ws_data[0] = 0.27777777777777779;
      cs_data[1] = 0.5;
      ws_data[1] = 0.44444444444444442;
      cs_data[2] = 0.887298334620742;
      ws_data[2] = 0.27777777777777779;
    } else if (degree <= 7) {
      *cs_size = 4;
      *ws_size = 4;
      cs_data[0] = 0.069431844202974;
      ws_data[0] = 0.173927422568727;
      cs_data[1] = 0.330009478207572;
      ws_data[1] = 0.326072577431273;
      cs_data[2] = 0.669990521792428;
      ws_data[2] = 0.326072577431273;
      cs_data[3] = 0.930568155797026;
      ws_data[3] = 0.173927422568727;
    } else if (degree <= 8) {
      *cs_size = 5;
      *ws_size = 5;
      for (int i{0}; i < 5; i++) {
        cs_data[i] = dv13[i];
        ws_data[i] = dv14[i];
      }
    } else if (degree <= 9) {
      *cs_size = 6;
      *ws_size = 6;
      for (int i{0}; i < 6; i++) {
        cs_data[i] = dv15[i];
        ws_data[i] = dv16[i];
      }
    } else {
      *cs_size = 7;
      *ws_size = 7;
      for (int i{0}; i < 7; i++) {
        cs_data[i] = dv17[i];
        ws_data[i] = dv18[i];
      }
    }
  }

  static inline
  void fe2_quadrule(int degree, double ws_data[], int *ws_size, double
    cs_data[], int cs_size[2])
  {
    //  Obtain quadrature points of a 2-D element.
    if (degree <= 1) {
      *ws_size = 1;
      ws_data[0] = 0.5;
      cs_size[1] = 2;
      cs_size[0] = 1;
      cs_data[0] = 0.33333333333333331;
      cs_data[1] = 0.33333333333333331;
    } else if (degree <= 2) {
      *ws_size = 3;
      ws_data[0] = 0.16666666666666666;
      ws_data[1] = 0.16666666666666666;
      ws_data[2] = 0.16666666666666666;
      cs_size[1] = 2;
      cs_size[0] = 3;
      for (int i{0}; i < 6; i++) {
        cs_data[i] = dv[i];
      }
    } else if (degree <= 4) {
      *ws_size = 6;
      for (int i{0}; i < 6; i++) {
        ws_data[i] = dv1[i];
      }

      cs_size[1] = 2;
      cs_size[0] = 6;
      std::copy(&dv2[0], &dv2[12], &cs_data[0]);
    } else if (degree <= 5) {
      cs_size[1] = 2;
      cs_size[0] = 7;
      std::copy(&dv3[0], &dv3[14], &cs_data[0]);
      *ws_size = 7;
      for (int i{0}; i < 7; i++) {
        ws_data[i] = dv4[i];
      }
    } else if (degree <= 6) {
      //  degree 6
      cs_size[1] = 2;
      cs_size[0] = 12;
      std::copy(&dv5[0], &dv5[24], &cs_data[0]);
      *ws_size = 12;
      std::copy(&dv6[0], &dv6[12], &ws_data[0]);
    } else if (degree <= 7) {
      cs_size[1] = 2;
      cs_size[0] = 12;
      std::copy(&dv7[0], &dv7[24], &cs_data[0]);
      *ws_size = 12;
      std::copy(&dv8[0], &dv8[12], &ws_data[0]);
    } else if (degree <= 8) {
      cs_size[1] = 2;
      cs_size[0] = 16;
      std::copy(&dv9[0], &dv9[32], &cs_data[0]);
      *ws_size = 16;
      std::copy(&dv10[0], &dv10[16], &ws_data[0]);
    } else {
      cs_size[1] = 2;
      cs_size[0] = 19;
      std::copy(&dv11[0], &dv11[38], &cs_data[0]);
      *ws_size = 19;
      std::copy(&dv12[0], &dv12[19], &ws_data[0]);
    }
  }

  static inline
  void fe3_quadrule(int nv, int degree, double ws_data[], int *ws_size,
    double cs_data[], int cs_size[2], int *nqp)
  {
    static const double b_dv11[93]{ 0.0, 0.0, 0.5, 0.0, 0.5, 0.0, 0.5, 0.0, 0.0,
      0.5, 0.5, 0.0, 0.5, 0.0, 0.5, 0.0, 0.5, 0.5, 0.25, 0.25, 0.25,
      0.765360423009046, 0.078213192330318, 0.078213192330318, 0.078213192330318,
      0.765360423009046, 0.078213192330318, 0.078213192330318, 0.078213192330318,
      0.765360423009046, 0.078213192330318, 0.078213192330318, 0.078213192330318,
      0.634470350008284, 0.121843216663905, 0.121843216663905, 0.121843216663905,
      0.634470350008284, 0.121843216663905, 0.121843216663905, 0.121843216663905,
      0.634470350008284, 0.121843216663905, 0.121843216663905, 0.121843216663905,
      0.002382506660738, 0.332539164446421, 0.332539164446421, 0.332539164446421,
      0.002382506660738, 0.332539164446421, 0.332539164446421, 0.332539164446421,
      0.002382506660738, 0.332539164446421, 0.332539164446421, 0.332539164446421,
      0.6, 0.2, 0.1, 0.6, 0.1, 0.2, 0.6, 0.1, 0.1, 0.2, 0.6, 0.1, 0.2, 0.1, 0.6,
      0.2, 0.1, 0.1, 0.1, 0.6, 0.2, 0.1, 0.2, 0.6, 0.1, 0.1, 0.6, 0.1, 0.6, 0.1,
      0.1, 0.1, 0.2, 0.1, 0.2, 0.1 };

    static const double b_dv5[81]{ 0.104475117303481, 0.104475117303481,
      0.07299402407315, 0.463502987963425, 0.104475117303481, 0.07299402407315,
      0.82253085862337, 0.104475117303481, 0.07299402407315, 0.104475117303481,
      0.463502987963425, 0.07299402407315, 0.463502987963425, 0.463502987963425,
      0.07299402407315, 0.82253085862337, 0.463502987963425, 0.07299402407315,
      0.104475117303481, 0.82253085862337, 0.07299402407315, 0.463502987963425,
      0.82253085862337, 0.07299402407315, 0.82253085862337, 0.82253085862337,
      0.07299402407315, 0.073593763053862, 0.073593763053862, 0.347003766038352,
      0.326498116980824, 0.073593763053862, 0.347003766038352, 0.579402470907787,
      0.073593763053862, 0.347003766038352, 0.073593763053862, 0.326498116980824,
      0.347003766038352, 0.326498116980824, 0.326498116980824, 0.347003766038352,
      0.579402470907787, 0.326498116980824, 0.347003766038352, 0.073593763053862,
      0.579402470907787, 0.347003766038352, 0.326498116980824, 0.579402470907787,
      0.347003766038352, 0.579402470907787, 0.579402470907787, 0.347003766038352,
      0.033246742228767, 0.033246742228767, 0.705002209888498, 0.147498895055751,
      0.033246742228767, 0.705002209888498, 0.261751047882735, 0.033246742228767,
      0.705002209888498, 0.033246742228767, 0.147498895055751, 0.705002209888498,
      0.147498895055751, 0.147498895055751, 0.705002209888498, 0.261751047882735,
      0.147498895055751, 0.705002209888498, 0.033246742228767, 0.261751047882735,
      0.705002209888498, 0.147498895055751, 0.261751047882735, 0.705002209888498,
      0.261751047882735, 0.261751047882735, 0.705002209888498 };

    static const double b_dv12[72]{ 0.356191386222544, 0.214602871259152,
      0.214602871259152, 0.214602871259152, 0.356191386222544, 0.214602871259152,
      0.214602871259152, 0.214602871259152, 0.356191386222544, 0.214602871259152,
      0.214602871259152, 0.214602871259152, 0.877978124396166, 0.040673958534611,
      0.040673958534611, 0.040673958534611, 0.877978124396166, 0.040673958534611,
      0.040673958534611, 0.040673958534611, 0.877978124396166, 0.040673958534611,
      0.040673958534611, 0.040673958534611, 0.032986329573173, 0.322337890142275,
      0.322337890142275, 0.322337890142275, 0.032986329573173, 0.322337890142275,
      0.322337890142275, 0.322337890142275, 0.032986329573173, 0.322337890142275,
      0.322337890142275, 0.322337890142275, 0.603005664791649, 0.269672331458316,
      0.063661001875018, 0.603005664791649, 0.063661001875018, 0.269672331458316,
      0.603005664791649, 0.063661001875018, 0.063661001875018, 0.269672331458316,
      0.603005664791649, 0.063661001875018, 0.269672331458316, 0.063661001875018,
      0.603005664791649, 0.269672331458316, 0.063661001875018, 0.063661001875018,
      0.063661001875018, 0.603005664791649, 0.269672331458316, 0.063661001875018,
      0.269672331458316, 0.603005664791649, 0.063661001875018, 0.063661001875018,
      0.603005664791649, 0.063661001875018, 0.603005664791649, 0.063661001875018,
      0.063661001875018, 0.063661001875018, 0.269672331458316, 0.063661001875018,
      0.269672331458316, 0.063661001875018 };

    static const double b_dv9[42]{ 0.092735250310891221, 0.092735250310891221,
      0.092735250310891221, 0.72179424906732637, 0.092735250310891221,
      0.092735250310891221, 0.092735250310891221, 0.72179424906732637,
      0.092735250310891221, 0.092735250310891221, 0.092735250310891221,
      0.72179424906732637, 0.31088591926330061, 0.31088591926330061,
      0.31088591926330061, 0.067342242210098213, 0.31088591926330061,
      0.31088591926330061, 0.31088591926330061, 0.067342242210098213,
      0.31088591926330061, 0.31088591926330061, 0.31088591926330061,
      0.067342242210098213, 0.45449629587435036, 0.45449629587435036,
      0.045503704125649649, 0.45449629587435036, 0.045503704125649649,
      0.45449629587435036, 0.045503704125649649, 0.45449629587435036,
      0.45449629587435036, 0.045503704125649649, 0.045503704125649649,
      0.45449629587435036, 0.045503704125649649, 0.45449629587435036,
      0.045503704125649649, 0.45449629587435036, 0.045503704125649649,
      0.045503704125649649 };

    static const double b_dv15[31]{ 0.00097001763668430336,
      0.00097001763668430336, 0.00097001763668430336, 0.00097001763668430336,
      0.00097001763668430336, 0.00097001763668430336, 0.018264223466108821,
      0.010599941524413686, 0.010599941524413686, 0.010599941524413686,
      0.010599941524413686, -0.062517740114331852, -0.062517740114331852,
      -0.062517740114331852, -0.062517740114331852, 0.0048914252630734992,
      0.0048914252630734992, 0.0048914252630734992, 0.0048914252630734992,
      0.027557319223985889, 0.027557319223985889, 0.027557319223985889,
      0.027557319223985889, 0.027557319223985889, 0.027557319223985889,
      0.027557319223985889, 0.027557319223985889, 0.027557319223985889,
      0.027557319223985889, 0.027557319223985889, 0.027557319223985889 };

    static const double b_dv1[27]{ 0.01212471921797, 0.019399550748751,
      0.01212471921797, 0.019399550748751, 0.031039281198002, 0.019399550748751,
      0.01212471921797, 0.019399550748751, 0.01212471921797, 0.011284434356471,
      0.018055094970354, 0.011284434356471, 0.018055094970354, 0.028888151952566,
      0.018055094970354, 0.011284434356471, 0.018055094970354, 0.011284434356471,
      0.002311011034613, 0.00369761765538, 0.002311011034613, 0.00369761765538,
      0.005916188248609, 0.00369761765538, 0.002311011034613, 0.00369761765538,
      0.002311011034613 };

    static const double b_dv16[24]{ 0.0066537917096945818, 0.0066537917096945818,
      0.0066537917096945818, 0.0066537917096945818, 0.0016795351758867739,
      0.0016795351758867739, 0.0016795351758867739, 0.0016795351758867739,
      0.0092261969239424528, 0.0092261969239424528, 0.0092261969239424528,
      0.0092261969239424528, 0.0080357142857142849, 0.0080357142857142849,
      0.0080357142857142849, 0.0080357142857142849, 0.0080357142857142849,
      0.0080357142857142849, 0.0080357142857142849, 0.0080357142857142849,
      0.0080357142857142849, 0.0080357142857142849, 0.0080357142857142849,
      0.0080357142857142849 };

    static const double b_dv3[24]{ 0.096332050209531, 0.096332050209531,
      0.544151844011225, 0.359516105779244, 0.096332050209531, 0.544151844011225,
      0.359516105779244, 0.359516105779244, 0.544151844011225, 0.096332050209531,
      0.359516105779244, 0.544151844011225, 0.185434436997386, 0.185434436997386,
      0.122514822655441, 0.692050740347173, 0.185434436997386, 0.122514822655441,
      0.692050740347173, 0.692050740347173, 0.122514822655441, 0.185434436997386,
      0.692050740347173, 0.122514822655441 };

    static const double b_dv7[24]{ 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
      0.0, 0.0, 1.0, 0.33333333333333331, 0.33333333333333331,
      0.33333333333333331, 0.0, 0.33333333333333331, 0.33333333333333331,
      0.33333333333333331, 0.0, 0.33333333333333331, 0.33333333333333331,
      0.33333333333333331, 0.0 };

    static const double b_dv8[24]{ 0.211324865405187, 0.211324865405187,
      0.211324865405187, 0.211324865405187, 0.788675134594813, 0.211324865405187,
      0.788675134594813, 0.211324865405187, 0.211324865405187, 0.788675134594813,
      0.788675134594813, 0.211324865405187, 0.211324865405187, 0.211324865405187,
      0.788675134594813, 0.211324865405187, 0.788675134594813, 0.788675134594813,
      0.788675134594813, 0.211324865405187, 0.788675134594813, 0.788675134594813,
      0.788675134594813, 0.788675134594813 };

    static const double b_dv6[18]{ 0.666666666666667, 0.166666666666667,
      0.211324865405187, 0.666666666666667, 0.166666666666667, 0.788675134594813,
      0.166666666666667, 0.666666666666667, 0.211324865405187, 0.166666666666667,
      0.666666666666667, 0.788675134594813, 0.166666666666667, 0.166666666666667,
      0.211324865405187, 0.166666666666667, 0.166666666666667, 0.788675134594813
    };

    static const double b_dv4[15]{ 0.173234418886593, 0.173234418886593,
      0.166666666666667, 0.660098914446741, 0.173234418886593, 0.166666666666667,
      0.660098914446741, 0.660098914446741, 0.166666666666667, 0.173234418886593,
      0.660098914446741, 0.166666666666667, 0.15, 0.15, 0.7 };

    static const double b_dv13[14]{ 0.012248840519393659, 0.012248840519393659,
      0.012248840519393659, 0.012248840519393659, 0.018781320953002643,
      0.018781320953002643, 0.018781320953002643, 0.018781320953002643,
      0.0070910034628469112, 0.0070910034628469112, 0.0070910034628469112,
      0.0070910034628469112, 0.0070910034628469112, 0.0070910034628469112 };

    static const double b_dv14[12]{ 0.585410196624969, 0.1381966011250105,
      0.1381966011250105, 0.1381966011250105, 0.585410196624969,
      0.1381966011250105, 0.1381966011250105, 0.1381966011250105,
      0.585410196624969, 0.1381966011250105, 0.1381966011250105,
      0.1381966011250105 };

    static const double b_dv[8]{ 0.025196470519956, 0.025196470519956,
      0.025196470519956, 0.025196470519956, 0.058136862813377, 0.058136862813377,
      0.058136862813377, 0.058136862813377 };

    static const double b_dv10[8]{ 0.0041666666666666666, 0.0041666666666666666,
      0.0041666666666666666, 0.0041666666666666666, 0.0375, 0.0375, 0.0375,
      0.0375 };

    static const double b_dv2[5]{ 0.0703125, 0.0703125, 0.0703125, 0.0703125,
      0.052083333333333 };

    double y_data[931];
    double b_tmp_data[343];
    double c_tmp_data[343];
    double eta_data[343];
    double tmp_data[343];
    double xi_data[343];
    double zeta_data[343];
    double b_eta_data[133];
    double b_xi_data[133];
    double b_zeta_data[133];
    double d_tmp_data[49];
    double ps2_data[38];
    double b_ps2_data[19];
    double ws2_data[19];
    double ps1_data[7];
    double ws1_data[7];
    double ps1[2];
    int eta_size[3];
    int xi_size[3];
    int zeta_size[3];
    int b_eta_size[2];
    int b_ps2_size[2];
    int b_xi_size[2];
    int ps2_size[2];
    int b_tmp_size;
    int i;
    int i1;
    int i2;
    int k;
    int ps1_size;
    int t;
    int tmp_size;
    int ws1_size;
    int ws2_size;
    short xi_idx_0;
    boolean_T guard1{ false };

    boolean_T guard2{ false };

    boolean_T guard3{ false };

    boolean_T guard4{ false };

    //  FE3_QUADRULE Obtain quadrature rule of 3-D element.
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    switch (nv) {
     case 4:
      guard1 = true;
      break;

     case 10:
      guard1 = true;
      break;

     case 20:
      guard1 = true;
      break;

     case 35:
      guard1 = true;
      break;

     case 8:
      guard2 = true;
      break;

     case 21:
      guard2 = true;
      break;

     case 27:
      guard2 = true;
      break;

     case 32:
      guard2 = true;
      break;

     case 64:
      guard2 = true;
      break;

     case 125:
      guard2 = true;
      break;

     case 6:
      guard3 = true;
      break;

     case 15:
      guard3 = true;
      break;

     case 18:
      guard3 = true;
      break;

     case 40:
      guard3 = true;
      break;

     case 75:
      guard3 = true;
      break;

     case 5:
      guard4 = true;
      break;

     case 13:
      guard4 = true;
      break;

     case 14:
      guard4 = true;
      break;

     case 30:
      guard4 = true;
      break;

     case 55:
      guard4 = true;
      break;
    }

    if (guard4) {
      //  PYRAMID
      if ((nv <= 6) && (degree <= 1)) {
        *nqp = 1;
        *ws_size = 1;
        ws_data[0] = 0.33333333333333331;
        cs_size[1] = 3;
        cs_size[0] = 1;
        cs_data[0] = 0.375;
        cs_data[1] = 0.375;
        cs_data[2] = 0.25;
      } else if ((nv <= 14) && (degree <= 2)) {
        *nqp = 5;
        *ws_size = 5;
        for (i = 0; i < 5; i++) {
          ws_data[i] = b_dv2[i];
        }

        cs_size[1] = 3;
        cs_size[0] = 5;
        std::copy(&b_dv4[0], &b_dv4[15], &cs_data[0]);
      } else if (degree <= 3) {
        *nqp = 8;
        *ws_size = 8;
        std::copy(&b_dv[0], &b_dv[8], &ws_data[0]);
        cs_size[1] = 3;
        cs_size[0] = 8;
        std::copy(&b_dv3[0], &b_dv3[24], &cs_data[0]);
      } else {
        //  degree 5
        *nqp = 27;
        *ws_size = 27;
        std::copy(&b_dv1[0], &b_dv1[27], &ws_data[0]);
        cs_size[1] = 3;
        cs_size[0] = 27;
        std::copy(&b_dv5[0], &b_dv5[81], &cs_data[0]);
      }
    }

    if (guard3) {
      //  PRISM
      if ((nv <= 6) && (degree <= 1)) {
        *nqp = 1;
        *ws_size = 1;
        ws_data[0] = 0.5;
        cs_size[1] = 3;
        cs_size[0] = 1;
        cs_data[0] = 0.33333333333333331;
        cs_data[1] = 0.33333333333333331;
        cs_data[2] = 0.5;
      } else if ((nv <= 18) && (degree <= 2)) {
        *nqp = 6;
        *ws_size = 6;
        for (i = 0; i < 6; i++) {
          ws_data[i] = 0.083333333333333329;
        }

        cs_size[1] = 3;
        cs_size[0] = 6;
        std::copy(&b_dv6[0], &b_dv6[18], &cs_data[0]);
      } else {
        int zeta_size_idx_1;

        //  Use tensor product to construct high-degree rules
        b_fe1_quadrule(degree, ws1_data, &ws1_size, ps1_data, &ps1_size);
        fe2_quadrule(degree, ws2_data, &ws2_size, ps2_data, ps2_size);
        b_ps2_size[1] = ps2_size[0];
        b_ps2_size[0] = 1;
        k = ps2_size[0];
        for (i = 0; i < k; i++) {
          b_ps2_data[i] = ps2_data[2 * i];
        }

        ps1[0] = ps1_size;
        ps1[1] = 1.0;
        coder::repmat(b_ps2_data, b_ps2_size, ps1, b_xi_data, b_xi_size);
        b_ps2_size[1] = ps2_size[0];
        b_ps2_size[0] = 1;
        k = ps2_size[0];
        for (i = 0; i < k; i++) {
          b_ps2_data[i] = ps2_data[2 * i + 1];
        }

        ps1[0] = ps1_size;
        ps1[1] = 1.0;
        coder::repmat(b_ps2_data, b_ps2_size, ps1, b_eta_data, b_eta_size);
        zeta_size_idx_1 = static_cast<signed char>(ps2_size[0]);
        for (k = 0; k < ps1_size; k++) {
          i = static_cast<signed char>(ps2_size[0]) - 1;
          for (t = 0; t <= i; t++) {
            b_zeta_data[t + zeta_size_idx_1 * k] = ps1_data[k];
          }
        }

        xi_idx_0 = static_cast<short>(b_xi_size[0] * b_xi_size[1]);
        i = 0;
        i1 = 0;
        tmp_size = xi_idx_0;
        for (i2 = 0; i2 < xi_idx_0; i2++) {
          tmp_data[i2] = b_xi_data[i1 + b_xi_size[1] * i];
          i++;
          if (i > b_xi_size[0] - 1) {
            i = 0;
            i1++;
          }
        }

        xi_idx_0 = static_cast<short>(b_eta_size[0] * b_eta_size[1]);
        i = 0;
        i1 = 0;
        t = xi_idx_0;
        for (i2 = 0; i2 < xi_idx_0; i2++) {
          b_tmp_data[i2] = b_eta_data[i1 + b_eta_size[1] * i];
          i++;
          if (i > b_eta_size[0] - 1) {
            i = 0;
            i1++;
          }
        }

        xi_idx_0 = static_cast<short>(static_cast<signed char>(ps1_size) *
          static_cast<signed char>(ps2_size[0]));
        i = 0;
        i1 = 0;
        b_tmp_size = xi_idx_0;
        for (i2 = 0; i2 < xi_idx_0; i2++) {
          c_tmp_data[i2] = b_zeta_data[i1 + zeta_size_idx_1 * i];
          i++;
          if (i > static_cast<signed char>(ps1_size) - 1) {
            i = 0;
            i1++;
          }
        }

        cs_size[1] = 3;
        cs_size[0] = tmp_size;
        for (i = 0; i < tmp_size; i++) {
          cs_data[3 * i] = tmp_data[i];
        }

        for (i = 0; i < t; i++) {
          cs_data[3 * i + 1] = b_tmp_data[i];
        }

        for (i = 0; i < b_tmp_size; i++) {
          cs_data[3 * i + 2] = c_tmp_data[i];
        }

        for (i = 0; i < ws1_size; i++) {
          for (i1 = 0; i1 < ws2_size; i1++) {
            y_data[i1 + ws2_size * i] = ws2_data[i1] * ws1_data[i];
          }
        }

        xi_idx_0 = static_cast<short>(static_cast<signed char>(ws2_size) *
          static_cast<signed char>(ws1_size));
        i = 0;
        i1 = 0;
        *ws_size = xi_idx_0;
        for (i2 = 0; i2 < xi_idx_0; i2++) {
          ws_data[i2] = y_data[i1 + ws2_size * i];
          i++;
          if (i > ws1_size - 1) {
            i = 0;
            i1++;
          }
        }

        *nqp = xi_idx_0;
      }
    }

    if (guard2) {
      //  HEX
      if ((nv <= 8) && (degree <= 1)) {
        *nqp = 1;
        *ws_size = 1;
        ws_data[0] = 1.0;
        cs_size[1] = 3;
        cs_size[0] = 1;
        cs_data[0] = 0.5;
        cs_data[1] = 0.5;
        cs_data[2] = 0.5;
      } else if ((nv <= 27) && (degree <= 3)) {
        *nqp = 8;
        *ws_size = 8;
        for (i = 0; i < 8; i++) {
          ws_data[i] = 0.125;
        }

        cs_size[1] = 3;
        cs_size[0] = 8;
        std::copy(&b_dv8[0], &b_dv8[24], &cs_data[0]);
      } else {
        //  Use tensor product to construct high-degree rules
        fe1_quadrule(degree, ws1_data, &ws1_size, ps1_data, &ps1_size);
        coder::meshgrid(ps1_data, ps1_size, ps1_data, ps1_size, ps1_data,
                        ps1_size, xi_data, xi_size, eta_data, eta_size,
                        zeta_data, zeta_size);
        xi_idx_0 = static_cast<short>(xi_size[0] * xi_size[1] * xi_size[2]);
        i = 0;
        i1 = 0;
        i2 = 0;
        tmp_size = xi_idx_0;
        for (k = 0; k < xi_idx_0; k++) {
          tmp_data[k] = xi_data[(i2 + xi_size[2] * i1) + xi_size[1] * xi_size[2]
            * i];
          i++;
          if (i > xi_size[0] - 1) {
            i = 0;
            i1++;
            if (i1 > xi_size[1] - 1) {
              i1 = 0;
              i2++;
            }
          }
        }

        xi_idx_0 = static_cast<short>(eta_size[0] * eta_size[1] * eta_size[2]);
        i = 0;
        i1 = 0;
        i2 = 0;
        t = xi_idx_0;
        for (k = 0; k < xi_idx_0; k++) {
          b_tmp_data[k] = eta_data[(i2 + eta_size[2] * i1) + eta_size[1] *
            eta_size[2] * i];
          i++;
          if (i > eta_size[0] - 1) {
            i = 0;
            i1++;
            if (i1 > eta_size[1] - 1) {
              i1 = 0;
              i2++;
            }
          }
        }

        xi_idx_0 = static_cast<short>(zeta_size[0] * zeta_size[1] * zeta_size[2]);
        i = 0;
        i1 = 0;
        i2 = 0;
        b_tmp_size = xi_idx_0;
        for (k = 0; k < xi_idx_0; k++) {
          c_tmp_data[k] = zeta_data[(i2 + zeta_size[2] * i1) + zeta_size[1] *
            zeta_size[2] * i];
          i++;
          if (i > zeta_size[0] - 1) {
            i = 0;
            i1++;
            if (i1 > zeta_size[1] - 1) {
              i1 = 0;
              i2++;
            }
          }
        }

        cs_size[1] = 3;
        cs_size[0] = tmp_size;
        for (i = 0; i < tmp_size; i++) {
          cs_data[3 * i] = tmp_data[i];
        }

        for (i = 0; i < t; i++) {
          cs_data[3 * i + 1] = b_tmp_data[i];
        }

        for (i = 0; i < b_tmp_size; i++) {
          cs_data[3 * i + 2] = c_tmp_data[i];
        }

        for (i = 0; i < ws1_size; i++) {
          for (i1 = 0; i1 < ws1_size; i1++) {
            y_data[i1 + ws1_size * i] = ws1_data[i1] * ws1_data[i];
          }
        }

        xi_idx_0 = static_cast<short>(static_cast<signed char>(ws1_size) *
          static_cast<signed char>(ws1_size));
        i = 0;
        i1 = 0;
        tmp_size = xi_idx_0;
        for (i2 = 0; i2 < xi_idx_0; i2++) {
          d_tmp_data[i2] = y_data[i1 + ws1_size * i];
          i++;
          if (i > ws1_size - 1) {
            i = 0;
            i1++;
          }
        }

        for (i = 0; i < tmp_size; i++) {
          for (i1 = 0; i1 < ws1_size; i1++) {
            y_data[i1 + ws1_size * i] = ws1_data[i1] * d_tmp_data[i];
          }
        }

        xi_idx_0 = static_cast<short>(static_cast<signed char>(ws1_size) *
          static_cast<signed char>(xi_idx_0));
        i = 0;
        i1 = 0;
        *ws_size = xi_idx_0;
        for (i2 = 0; i2 < xi_idx_0; i2++) {
          ws_data[i2] = y_data[i1 + ws1_size * i];
          i++;
          if (i > tmp_size - 1) {
            i = 0;
            i1++;
          }
        }

        *nqp = xi_idx_0;
      }
    }

    if (guard1) {
      //  TET_4, TET_10, or TET_20
      if ((nv <= 4) && (degree <= 1)) {
        *nqp = 1;
        *ws_size = 1;
        ws_data[0] = 0.16666666666666666;
        cs_size[1] = 3;
        cs_size[0] = 1;
        cs_data[0] = 0.25;
        cs_data[1] = 0.25;
        cs_data[2] = 0.25;
      } else if ((nv <= 10) && (degree <= 2)) {
        *nqp = 4;
        *ws_size = 4;
        ws_data[0] = 0.041666666666666664;
        ws_data[1] = 0.041666666666666664;
        ws_data[2] = 0.041666666666666664;
        ws_data[3] = 0.041666666666666664;
        cs_size[1] = 3;
        cs_size[0] = 4;
        std::copy(&b_dv14[0], &b_dv14[12], &cs_data[0]);
      } else if ((nv <= 20) && (degree <= 3)) {
        *nqp = 8;
        cs_size[1] = 3;
        cs_size[0] = 8;
        std::copy(&b_dv7[0], &b_dv7[24], &cs_data[0]);
        *ws_size = 8;
        std::copy(&b_dv10[0], &b_dv10[8], &ws_data[0]);
      } else if ((nv <= 56) && (degree <= 5)) {
        //  degree 5, 14 points
        *nqp = 14;
        cs_size[1] = 3;
        cs_size[0] = 14;
        std::copy(&b_dv9[0], &b_dv9[42], &cs_data[0]);
        *ws_size = 14;
        std::copy(&b_dv13[0], &b_dv13[14], &ws_data[0]);
      } else if ((nv <= 84) && (degree <= 6)) {
        //  degree 6, 24 points
        *nqp = 24;
        cs_size[1] = 3;
        cs_size[0] = 24;
        std::copy(&b_dv12[0], &b_dv12[72], &cs_data[0]);
        *ws_size = 24;
        std::copy(&b_dv16[0], &b_dv16[24], &ws_data[0]);
      } else {
        //  degree 7, 24 points
        *nqp = 31;
        cs_size[1] = 3;
        cs_size[0] = 31;
        std::copy(&b_dv11[0], &b_dv11[93], &cs_data[0]);
        *ws_size = 31;
        std::copy(&b_dv15[0], &b_dv15[31], &ws_data[0]);
      }
    }
  }

  static inline
  void quad_9(double xi, double eta, double shape_funcs[9], double deriv
                     [18])
  {
    static const signed char b_iv[9]{ 1, 2, 2, 1, 3, 2, 3, 1, 3 };

    static const signed char b_iv1[9]{ 1, 1, 2, 2, 1, 3, 2, 3, 3 };

    double N_eta[3];
    double N_xi[3];
    double deriv_eta[3];
    double deriv_xi[3];
    double t2;
    double t3;
    double t4;

    // QUAD_9   Bilinear quadrilateral element
    t2 = 4.0 * xi;
    t3 = xi * xi;
    t4 = t3 * 2.0;
    N_xi[0] = (t4 + -3.0 * xi) + 1.0;
    N_xi[1] = t4 + -xi;
    N_xi[2] = t2 - t3 * 4.0;
    deriv_xi[0] = t2 - 3.0;
    deriv_xi[1] = t2 - 1.0;
    deriv_xi[2] = -8.0 * xi + 4.0;

    // BAR_3   Quadratic bar element
    t2 = 4.0 * eta;
    t3 = eta * eta;
    t4 = t3 * 2.0;
    N_eta[0] = (t4 + -3.0 * eta) + 1.0;
    N_eta[1] = t4 + -eta;
    N_eta[2] = t2 - t3 * 4.0;
    deriv_eta[0] = t2 - 3.0;
    deriv_eta[1] = t2 - 1.0;
    deriv_eta[2] = -8.0 * eta + 4.0;
    for (int k{0}; k < 9; k++) {
      double c_shape_funcs_tmp;
      double d_shape_funcs_tmp;
      int b_shape_funcs_tmp;
      int deriv_tmp;
      int shape_funcs_tmp;
      shape_funcs_tmp = b_iv[k] - 1;
      b_shape_funcs_tmp = b_iv1[k] - 1;
      c_shape_funcs_tmp = N_eta[b_shape_funcs_tmp];
      d_shape_funcs_tmp = N_xi[shape_funcs_tmp];
      shape_funcs[k] = d_shape_funcs_tmp * c_shape_funcs_tmp;
      deriv_tmp = k << 1;
      deriv[deriv_tmp] = deriv_xi[shape_funcs_tmp] * c_shape_funcs_tmp;
      deriv[deriv_tmp + 1] = d_shape_funcs_tmp * deriv_eta[b_shape_funcs_tmp];
    }
  }

  static inline
  void sfe1_tabulate_shapefuncs(int etype, const double cs_data[], const
    int cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double,
    3U> &derivs)
  {
    double e_N[7];
    double e_deriv[7];
    double d_N[6];
    double d_deriv[6];
    double c_N[5];
    double c_deriv[5];
    double b_N[4];
    double b_deriv[4];
    double N[3];
    double deriv[3];
    int i;
    int nqp;

    //  Tabulate shape functions and derivative at given points.
    nqp = cs_size[0] - 1;

    // obtain_nnodes - Obtain number of nodes per element given etype
    i = iv[etype - 1];
    shapes.set_size(cs_size[0], i);
    derivs.set_size(cs_size[0], i, cs_size[1]);

    // obtain_elemnodepos - Decode nodal position types, e.g., equidistance, GL
    if ((etype & 3) == 0) {
      switch (etype) {
       case 36:
        {
          int i1;
          boolean_T b;
          boolean_T b1;
          b = true;
          b1 = ((cs_size[1] <= 0) || (cs_size[0] <= 0));
          i = cs_size[0] * cs_size[1];
          i1 = 0;
          for (int q{0}; q <= nqp; q++) {
            if (b1 || (q >= i)) {
              i1 = 0;
              b = true;
            } else if (b) {
              b = false;
              i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
            } else if (i1 > MAX_int32_T - cs_size[1]) {
              i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
            } else {
              i1 += cs_size[1];
              if (i1 > i - 1) {
                i1 = (i1 - i) + 1;
              }
            }

            // BAR_2   Linear bar element
            shapes[shapes.size(1) * q] = -cs_data[i1] + 1.0;
            derivs[derivs.size(2) * derivs.size(1) * q] = -1.0;
            shapes[shapes.size(1) * q + 1] = cs_data[i1];
            derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] = 1.0;
          }
        }
        break;

       case 40:
        {
          int i1;
          boolean_T b;
          boolean_T b1;
          b = true;
          b1 = ((cs_size[1] <= 0) || (cs_size[0] <= 0));
          i = cs_size[0] * cs_size[1];
          i1 = 0;
          for (int q{0}; q <= nqp; q++) {
            if (b1 || (q >= i)) {
              i1 = 0;
              b = true;
            } else if (b) {
              b = false;
              i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
            } else {
              int i2;
              i2 = cs_size[0] * cs_size[1] - 1;
              if (i1 > MAX_int32_T - cs_size[1]) {
                i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
              } else {
                i1 += cs_size[1];
                if (i1 > i2) {
                  i1 -= i2;
                }
              }
            }

            bar_3(cs_data[i1], N, deriv);
            shapes[shapes.size(1) * q] = N[0];
            derivs[derivs.size(2) * derivs.size(1) * q] = deriv[0];
            shapes[shapes.size(1) * q + 1] = N[1];
            derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] =
              deriv[1];
            shapes[shapes.size(1) * q + 2] = N[2];
            derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
              deriv[2];
          }
        }
        break;

       case 44:
        {
          int i1;
          boolean_T b;
          boolean_T b1;
          b = true;
          b1 = ((cs_size[1] <= 0) || (cs_size[0] <= 0));
          i = cs_size[0] * cs_size[1];
          i1 = 0;
          for (int q{0}; q <= nqp; q++) {
            if (b1 || (q >= i)) {
              i1 = 0;
              b = true;
            } else if (b) {
              b = false;
              i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
            } else {
              int i2;
              i2 = cs_size[0] * cs_size[1] - 1;
              if (i1 > MAX_int32_T - cs_size[1]) {
                i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
              } else {
                i1 += cs_size[1];
                if (i1 > i2) {
                  i1 -= i2;
                }
              }
            }

            bar_4(cs_data[i1], b_N, b_deriv);
            shapes[shapes.size(1) * q] = b_N[0];
            derivs[derivs.size(2) * derivs.size(1) * q] = b_deriv[0];
            shapes[shapes.size(1) * q + 1] = b_N[1];
            derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] =
              b_deriv[1];
            shapes[shapes.size(1) * q + 2] = b_N[2];
            derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
              b_deriv[2];
            shapes[shapes.size(1) * q + 3] = b_N[3];
            derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
              b_deriv[3];
          }
        }
        break;

       case 48:
        {
          int i1;
          boolean_T b;
          boolean_T b1;
          b = true;
          b1 = ((cs_size[1] <= 0) || (cs_size[0] <= 0));
          i = cs_size[0] * cs_size[1];
          i1 = 0;
          for (int q{0}; q <= nqp; q++) {
            if (b1 || (q >= i)) {
              i1 = 0;
              b = true;
            } else if (b) {
              b = false;
              i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
            } else {
              int i2;
              i2 = cs_size[0] * cs_size[1] - 1;
              if (i1 > MAX_int32_T - cs_size[1]) {
                i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
              } else {
                i1 += cs_size[1];
                if (i1 > i2) {
                  i1 -= i2;
                }
              }
            }

            bar_5(cs_data[i1], c_N, c_deriv);
            shapes[shapes.size(1) * q] = c_N[0];
            derivs[derivs.size(2) * derivs.size(1) * q] = c_deriv[0];
            shapes[shapes.size(1) * q + 1] = c_N[1];
            derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] =
              c_deriv[1];
            shapes[shapes.size(1) * q + 2] = c_N[2];
            derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
              c_deriv[2];
            shapes[shapes.size(1) * q + 3] = c_N[3];
            derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
              c_deriv[3];
            shapes[shapes.size(1) * q + 4] = c_N[4];
            derivs[derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q] =
              c_deriv[4];
          }
        }
        break;

       case 52:
        {
          int i1;
          boolean_T b;
          boolean_T b1;
          b = true;
          b1 = ((cs_size[1] <= 0) || (cs_size[0] <= 0));
          i = cs_size[0] * cs_size[1];
          i1 = 0;
          for (int q{0}; q <= nqp; q++) {
            if (b1 || (q >= i)) {
              i1 = 0;
              b = true;
            } else if (b) {
              b = false;
              i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
            } else {
              int i2;
              i2 = cs_size[0] * cs_size[1] - 1;
              if (i1 > MAX_int32_T - cs_size[1]) {
                i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
              } else {
                i1 += cs_size[1];
                if (i1 > i2) {
                  i1 -= i2;
                }
              }
            }

            bar_6(cs_data[i1], d_N, d_deriv);
            shapes[shapes.size(1) * q] = d_N[0];
            derivs[derivs.size(2) * derivs.size(1) * q] = d_deriv[0];
            shapes[shapes.size(1) * q + 1] = d_N[1];
            derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] =
              d_deriv[1];
            shapes[shapes.size(1) * q + 2] = d_N[2];
            derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
              d_deriv[2];
            shapes[shapes.size(1) * q + 3] = d_N[3];
            derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
              d_deriv[3];
            shapes[shapes.size(1) * q + 4] = d_N[4];
            derivs[derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q] =
              d_deriv[4];
            shapes[shapes.size(1) * q + 5] = d_N[5];
            derivs[derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q] =
              d_deriv[5];
          }
        }
        break;

       case 56:
        {
          int i1;
          boolean_T b;
          boolean_T b1;
          b = true;
          b1 = ((cs_size[1] <= 0) || (cs_size[0] <= 0));
          i = cs_size[0] * cs_size[1];
          i1 = 0;
          for (int q{0}; q <= nqp; q++) {
            if (b1 || (q >= i)) {
              i1 = 0;
              b = true;
            } else if (b) {
              b = false;
              i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
            } else {
              int i2;
              i2 = cs_size[0] * cs_size[1] - 1;
              if (i1 > MAX_int32_T - cs_size[1]) {
                i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
              } else {
                i1 += cs_size[1];
                if (i1 > i2) {
                  i1 -= i2;
                }
              }
            }

            bar_7(cs_data[i1], e_N, e_deriv);
            shapes[shapes.size(1) * q] = e_N[0];
            derivs[derivs.size(2) * derivs.size(1) * q] = e_deriv[0];
            shapes[shapes.size(1) * q + 1] = e_N[1];
            derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] =
              e_deriv[1];
            shapes[shapes.size(1) * q + 2] = e_N[2];
            derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
              e_deriv[2];
            shapes[shapes.size(1) * q + 3] = e_N[3];
            derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
              e_deriv[3];
            shapes[shapes.size(1) * q + 4] = e_N[4];
            derivs[derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q] =
              e_deriv[4];
            shapes[shapes.size(1) * q + 5] = e_N[5];
            derivs[derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q] =
              e_deriv[5];
            shapes[shapes.size(1) * q + 6] = e_N[6];
            derivs[derivs.size(2) * 6 + derivs.size(2) * derivs.size(1) * q] =
              e_deriv[6];
          }
        }
        break;
      }
    } else {
      //  GL
      switch (etype) {
       case 45:
        {
          int i1;
          boolean_T b;
          boolean_T b1;
          b = true;
          b1 = ((cs_size[1] <= 0) || (cs_size[0] <= 0));
          i = cs_size[0] * cs_size[1];
          i1 = 0;
          for (int q{0}; q <= nqp; q++) {
            if (b1 || (q >= i)) {
              i1 = 0;
              b = true;
            } else if (b) {
              b = false;
              i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
            } else {
              int i2;
              i2 = cs_size[0] * cs_size[1] - 1;
              if (i1 > MAX_int32_T - cs_size[1]) {
                i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
              } else {
                i1 += cs_size[1];
                if (i1 > i2) {
                  i1 -= i2;
                }
              }
            }

            bar_gl_4(cs_data[i1], b_N, b_deriv);
            shapes[shapes.size(1) * q] = b_N[0];
            derivs[derivs.size(2) * derivs.size(1) * q] = b_deriv[0];
            shapes[shapes.size(1) * q + 1] = b_N[1];
            derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] =
              b_deriv[1];
            shapes[shapes.size(1) * q + 2] = b_N[2];
            derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
              b_deriv[2];
            shapes[shapes.size(1) * q + 3] = b_N[3];
            derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
              b_deriv[3];
          }
        }
        break;

       case 49:
        {
          int i1;
          boolean_T b;
          boolean_T b1;
          b = true;
          b1 = ((cs_size[1] <= 0) || (cs_size[0] <= 0));
          i = cs_size[0] * cs_size[1];
          i1 = 0;
          for (int q{0}; q <= nqp; q++) {
            if (b1 || (q >= i)) {
              i1 = 0;
              b = true;
            } else if (b) {
              b = false;
              i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
            } else {
              int i2;
              i2 = cs_size[0] * cs_size[1] - 1;
              if (i1 > MAX_int32_T - cs_size[1]) {
                i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
              } else {
                i1 += cs_size[1];
                if (i1 > i2) {
                  i1 -= i2;
                }
              }
            }

            bar_gl_5(cs_data[i1], c_N, c_deriv);
            shapes[shapes.size(1) * q] = c_N[0];
            derivs[derivs.size(2) * derivs.size(1) * q] = c_deriv[0];
            shapes[shapes.size(1) * q + 1] = c_N[1];
            derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] =
              c_deriv[1];
            shapes[shapes.size(1) * q + 2] = c_N[2];
            derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
              c_deriv[2];
            shapes[shapes.size(1) * q + 3] = c_N[3];
            derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
              c_deriv[3];
            shapes[shapes.size(1) * q + 4] = c_N[4];
            derivs[derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q] =
              c_deriv[4];
          }
        }
        break;

       case 53:
        {
          int i1;
          boolean_T b;
          boolean_T b1;
          b = true;
          b1 = ((cs_size[1] <= 0) || (cs_size[0] <= 0));
          i = cs_size[0] * cs_size[1];
          i1 = 0;
          for (int q{0}; q <= nqp; q++) {
            if (b1 || (q >= i)) {
              i1 = 0;
              b = true;
            } else if (b) {
              b = false;
              i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
            } else {
              int i2;
              i2 = cs_size[0] * cs_size[1] - 1;
              if (i1 > MAX_int32_T - cs_size[1]) {
                i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
              } else {
                i1 += cs_size[1];
                if (i1 > i2) {
                  i1 -= i2;
                }
              }
            }

            bar_gl_6(cs_data[i1], d_N, d_deriv);
            shapes[shapes.size(1) * q] = d_N[0];
            derivs[derivs.size(2) * derivs.size(1) * q] = d_deriv[0];
            shapes[shapes.size(1) * q + 1] = d_N[1];
            derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] =
              d_deriv[1];
            shapes[shapes.size(1) * q + 2] = d_N[2];
            derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
              d_deriv[2];
            shapes[shapes.size(1) * q + 3] = d_N[3];
            derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
              d_deriv[3];
            shapes[shapes.size(1) * q + 4] = d_N[4];
            derivs[derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q] =
              d_deriv[4];
            shapes[shapes.size(1) * q + 5] = d_N[5];
            derivs[derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q] =
              d_deriv[5];
          }
        }
        break;

       case 57:
        {
          int i1;
          boolean_T b;
          boolean_T b1;
          b = true;
          b1 = ((cs_size[1] <= 0) || (cs_size[0] <= 0));
          i = cs_size[0] * cs_size[1];
          i1 = 0;
          for (int q{0}; q <= nqp; q++) {
            if (b1 || (q >= i)) {
              i1 = 0;
              b = true;
            } else if (b) {
              b = false;
              i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
            } else {
              int i2;
              i2 = cs_size[0] * cs_size[1] - 1;
              if (i1 > MAX_int32_T - cs_size[1]) {
                i1 = q % cs_size[0] * cs_size[1] + q / cs_size[0];
              } else {
                i1 += cs_size[1];
                if (i1 > i2) {
                  i1 -= i2;
                }
              }
            }

            bar_gl_7(cs_data[i1], e_N, e_deriv);
            shapes[shapes.size(1) * q] = e_N[0];
            derivs[derivs.size(2) * derivs.size(1) * q] = e_deriv[0];
            shapes[shapes.size(1) * q + 1] = e_N[1];
            derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] =
              e_deriv[1];
            shapes[shapes.size(1) * q + 2] = e_N[2];
            derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
              e_deriv[2];
            shapes[shapes.size(1) * q + 3] = e_N[3];
            derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
              e_deriv[3];
            shapes[shapes.size(1) * q + 4] = e_N[4];
            derivs[derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q] =
              e_deriv[4];
            shapes[shapes.size(1) * q + 5] = e_N[5];
            derivs[derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q] =
              e_deriv[5];
            shapes[shapes.size(1) * q + 6] = e_N[6];
            derivs[derivs.size(2) * 6 + derivs.size(2) * derivs.size(1) * q] =
              e_deriv[6];
          }
        }
        break;
      }
    }
  }

  static inline
  void sfe2_tabulate_equi(int etype, const double cs_data[], const int
    cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double, 3U>
    &derivs)
  {
    static const signed char b_iv[49]{ 1, 2, 2, 1, 3, 4, 5, 6, 7, 2, 2, 2, 2, 2,
      7, 6, 5, 4, 3, 1, 1, 1, 1, 1, 3, 4, 5, 6, 7, 7, 7, 7, 7, 6, 5, 4, 3, 3, 3,
      3, 4, 5, 6, 6, 6, 5, 4, 4, 5 };

    static const signed char b_iv1[49]{ 1, 1, 2, 2, 1, 1, 1, 1, 1, 3, 4, 5, 6, 7,
      2, 2, 2, 2, 2, 7, 6, 5, 4, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7, 7, 7, 7, 7, 6, 5,
      4, 4, 4, 4, 5, 6, 6, 6, 5, 5 };

    double deriv[18];
    double N[9];
    double d_N_eta[7];
    double d_N_xi[7];
    double d_deriv_eta[7];
    double d_deriv_xi[7];
    double c_N_eta[6];
    double c_N_xi[6];
    double c_deriv_eta[6];
    double c_deriv_xi[6];
    double b_N_eta[5];
    double b_N_xi[5];
    double b_deriv_eta[5];
    double b_deriv_xi[5];
    double N_eta[4];
    double N_xi[4];
    double deriv_eta[4];
    double deriv_xi[4];

    //  equi kernel
    if ((etype >> 5 & 7) == 2) {
      sfe2_tabulate_equi_tri(etype, cs_data, cs_size, shapes, derivs);
    } else {
      int nqp;
      int xi_tmp;

      //  triangular
      nqp = cs_size[0] - 1;

      // obtain_nnodes - Obtain number of nodes per element given etype
      xi_tmp = iv[etype - 1];
      shapes.set_size(cs_size[0], xi_tmp);
      derivs.set_size(cs_size[0], xi_tmp, cs_size[1]);
      switch (etype) {
       case 100:
        {
          for (int q{0}; q <= nqp; q++) {
            double eta;
            double xi;
            xi_tmp = cs_size[1] * q;
            xi = cs_data[xi_tmp];
            eta = cs_data[xi_tmp + 1];

            // QUAD_4   Bilinear quadrilateral element
            shapes[shapes.size(1) * q] = (-xi + 1.0) * (-eta + 1.0);
            derivs[derivs.size(2) * derivs.size(1) * q] = -(-eta + 1.0);
            derivs[derivs.size(2) * derivs.size(1) * q + 1] = -(-xi + 1.0);
            shapes[shapes.size(1) * q + 1] = (-eta + 1.0) * xi;
            derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] = -eta
              + 1.0;
            derivs[(derivs.size(2) + derivs.size(2) * derivs.size(1) * q) + 1] =
              -xi;
            shapes[shapes.size(1) * q + 2] = xi * eta;
            derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
              eta;
            derivs[(derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q) +
              1] = xi;
            shapes[shapes.size(1) * q + 3] = (-xi + 1.0) * eta;
            derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
              -eta;
            derivs[(derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q) +
              1] = -xi + 1.0;
          }
        }
        break;

       case 104:
        for (int q{0}; q <= nqp; q++) {
          quad_9(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1], N, deriv);
          shapes[shapes.size(1) * q] = N[0];
          derivs[derivs.size(2) * derivs.size(1) * q] = deriv[0];
          derivs[derivs.size(2) * derivs.size(1) * q + 1] = deriv[1];
          shapes[shapes.size(1) * q + 1] = N[1];
          derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] = deriv[2];
          derivs[(derivs.size(2) + derivs.size(2) * derivs.size(1) * q) + 1] =
            deriv[3];
          shapes[shapes.size(1) * q + 2] = N[2];
          derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
            deriv[4];
          derivs[(derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q) + 1]
            = deriv[5];
          shapes[shapes.size(1) * q + 3] = N[3];
          derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
            deriv[6];
          derivs[(derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q) + 1]
            = deriv[7];
          shapes[shapes.size(1) * q + 4] = N[4];
          derivs[derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q] =
            deriv[8];
          derivs[(derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q) + 1]
            = deriv[9];
          shapes[shapes.size(1) * q + 5] = N[5];
          derivs[derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q] =
            deriv[10];
          derivs[(derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q) + 1]
            = deriv[11];
          shapes[shapes.size(1) * q + 6] = N[6];
          derivs[derivs.size(2) * 6 + derivs.size(2) * derivs.size(1) * q] =
            deriv[12];
          derivs[(derivs.size(2) * 6 + derivs.size(2) * derivs.size(1) * q) + 1]
            = deriv[13];
          shapes[shapes.size(1) * q + 7] = N[7];
          derivs[derivs.size(2) * 7 + derivs.size(2) * derivs.size(1) * q] =
            deriv[14];
          derivs[(derivs.size(2) * 7 + derivs.size(2) * derivs.size(1) * q) + 1]
            = deriv[15];
          shapes[shapes.size(1) * q + 8] = N[8];
          derivs[derivs.size(2) * 8 + derivs.size(2) * derivs.size(1) * q] =
            deriv[16];
          derivs[(derivs.size(2) * 8 + derivs.size(2) * derivs.size(1) * q) + 1]
            = deriv[17];
        }
        break;

       case 108:
        {
          for (int q{0}; q <= nqp; q++) {
            // QUAD_16   Bicubic quadrilateral element with equidistant points
            bar_4(cs_data[cs_size[1] * q], N_xi, deriv_xi);
            bar_4(cs_data[cs_size[1] * q + 1], N_eta, deriv_eta);
            for (int k{0}; k < 16; k++) {
              double eta;
              double xi;
              int shapes_tmp;
              xi_tmp = iv5[k] - 1;
              shapes_tmp = iv6[k] - 1;
              xi = N_eta[shapes_tmp];
              eta = N_xi[xi_tmp];
              shapes[k + shapes.size(1) * q] = eta * xi;
              derivs[derivs.size(2) * k + derivs.size(2) * derivs.size(1) * q] =
                deriv_xi[xi_tmp] * xi;
              derivs[(derivs.size(2) * k + derivs.size(2) * derivs.size(1) * q)
                + 1] = eta * deriv_eta[shapes_tmp];
            }
          }
        }
        break;

       case 112:
        {
          for (int q{0}; q <= nqp; q++) {
            // QUAD_25   Biquartic quadrilateral element with equidistant points
            bar_5(cs_data[cs_size[1] * q], b_N_xi, b_deriv_xi);
            bar_5(cs_data[cs_size[1] * q + 1], b_N_eta, b_deriv_eta);
            for (int k{0}; k < 25; k++) {
              double eta;
              double xi;
              int shapes_tmp;
              xi_tmp = iv3[k] - 1;
              shapes_tmp = iv4[k] - 1;
              xi = b_N_eta[shapes_tmp];
              eta = b_N_xi[xi_tmp];
              shapes[k + shapes.size(1) * q] = eta * xi;
              derivs[derivs.size(2) * k + derivs.size(2) * derivs.size(1) * q] =
                b_deriv_xi[xi_tmp] * xi;
              derivs[(derivs.size(2) * k + derivs.size(2) * derivs.size(1) * q)
                + 1] = eta * b_deriv_eta[shapes_tmp];
            }
          }
        }
        break;

       case 116:
        {
          for (int q{0}; q <= nqp; q++) {
            // QUAD_36   Biquintic quadrilateral element with equidistant points
            bar_6(cs_data[cs_size[1] * q], c_N_xi, c_deriv_xi);
            bar_6(cs_data[cs_size[1] * q + 1], c_N_eta, c_deriv_eta);
            for (int k{0}; k < 36; k++) {
              double eta;
              double xi;
              int shapes_tmp;
              xi_tmp = iv1[k] - 1;
              shapes_tmp = iv2[k] - 1;
              xi = c_N_eta[shapes_tmp];
              eta = c_N_xi[xi_tmp];
              shapes[k + shapes.size(1) * q] = eta * xi;
              derivs[derivs.size(2) * k + derivs.size(2) * derivs.size(1) * q] =
                c_deriv_xi[xi_tmp] * xi;
              derivs[(derivs.size(2) * k + derivs.size(2) * derivs.size(1) * q)
                + 1] = eta * c_deriv_eta[shapes_tmp];
            }
          }
        }
        break;

       case 120:
        {
          for (int q{0}; q <= nqp; q++) {
            // QUAD_49   Bisextic quadrilateral element with equidistant points
            bar_7(cs_data[cs_size[1] * q], d_N_xi, d_deriv_xi);
            bar_7(cs_data[cs_size[1] * q + 1], d_N_eta, d_deriv_eta);
            for (int k{0}; k < 49; k++) {
              double eta;
              double xi;
              int shapes_tmp;
              xi_tmp = b_iv[k] - 1;
              shapes_tmp = b_iv1[k] - 1;
              xi = d_N_eta[shapes_tmp];
              eta = d_N_xi[xi_tmp];
              shapes[k + shapes.size(1) * q] = eta * xi;
              derivs[derivs.size(2) * k + derivs.size(2) * derivs.size(1) * q] =
                d_deriv_xi[xi_tmp] * xi;
              derivs[(derivs.size(2) * k + derivs.size(2) * derivs.size(1) * q)
                + 1] = eta * d_deriv_eta[shapes_tmp];
            }
          }
        }
        break;
      }
    }
  }

  static inline
  void sfe2_tabulate_equi_tri(int etype, const double cs_data[], const
    int cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double,
    3U> &derivs)
  {
    double e_deriv[56];
    double d_deriv[42];
    double c_deriv[30];
    double e_N[28];
    double d_N[21];
    double b_deriv[20];
    double c_N[15];
    double deriv[12];
    double b_N[10];
    double N[6];
    int nqp;
    int xi_tmp;

    //  triangular
    nqp = cs_size[0] - 1;

    // obtain_nnodes - Obtain number of nodes per element given etype
    xi_tmp = iv[etype - 1];
    shapes.set_size(cs_size[0], xi_tmp);
    derivs.set_size(cs_size[0], xi_tmp, cs_size[1]);
    switch (etype) {
     case 68:
      {
        for (int q{0}; q <= nqp; q++) {
          double eta;
          double xi;
          xi_tmp = cs_size[1] * q;
          xi = cs_data[xi_tmp];
          eta = cs_data[xi_tmp + 1];

          // TRI_3   Linear triangular element
          shapes[shapes.size(1) * q] = -xi + (1.0 - eta);
          derivs[derivs.size(2) * derivs.size(1) * q] = -1.0;
          derivs[derivs.size(2) * derivs.size(1) * q + 1] = -1.0;
          shapes[shapes.size(1) * q + 1] = xi;
          derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] = 1.0;
          derivs[(derivs.size(2) + derivs.size(2) * derivs.size(1) * q) + 1] =
            0.0;
          shapes[shapes.size(1) * q + 2] = eta;
          derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] = 0.0;
          derivs[(derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q) + 1]
            = 1.0;
        }
      }
      break;

     case 72:
      for (int q{0}; q <= nqp; q++) {
        tri_6(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1], N, deriv);
        shapes[shapes.size(1) * q] = N[0];
        derivs[derivs.size(2) * derivs.size(1) * q] = deriv[0];
        derivs[derivs.size(2) * derivs.size(1) * q + 1] = deriv[1];
        shapes[shapes.size(1) * q + 1] = N[1];
        derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] = deriv[2];
        derivs[(derivs.size(2) + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[3];
        shapes[shapes.size(1) * q + 2] = N[2];
        derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
          deriv[4];
        derivs[(derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[5];
        shapes[shapes.size(1) * q + 3] = N[3];
        derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
          deriv[6];
        derivs[(derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[7];
        shapes[shapes.size(1) * q + 4] = N[4];
        derivs[derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q] =
          deriv[8];
        derivs[(derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[9];
        shapes[shapes.size(1) * q + 5] = N[5];
        derivs[derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q] =
          deriv[10];
        derivs[(derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[11];
      }
      break;

     case 76:
      for (int q{0}; q <= nqp; q++) {
        tri_10(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1], b_N,
               b_deriv);
        shapes[shapes.size(1) * q] = b_N[0];
        derivs[derivs.size(2) * derivs.size(1) * q] = b_deriv[0];
        derivs[derivs.size(2) * derivs.size(1) * q + 1] = b_deriv[1];
        shapes[shapes.size(1) * q + 1] = b_N[1];
        derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] = b_deriv[2];
        derivs[(derivs.size(2) + derivs.size(2) * derivs.size(1) * q) + 1] =
          b_deriv[3];
        shapes[shapes.size(1) * q + 2] = b_N[2];
        derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
          b_deriv[4];
        derivs[(derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q) + 1] =
          b_deriv[5];
        shapes[shapes.size(1) * q + 3] = b_N[3];
        derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
          b_deriv[6];
        derivs[(derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q) + 1] =
          b_deriv[7];
        shapes[shapes.size(1) * q + 4] = b_N[4];
        derivs[derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q] =
          b_deriv[8];
        derivs[(derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q) + 1] =
          b_deriv[9];
        shapes[shapes.size(1) * q + 5] = b_N[5];
        derivs[derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q] =
          b_deriv[10];
        derivs[(derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q) + 1] =
          b_deriv[11];
        shapes[shapes.size(1) * q + 6] = b_N[6];
        derivs[derivs.size(2) * 6 + derivs.size(2) * derivs.size(1) * q] =
          b_deriv[12];
        derivs[(derivs.size(2) * 6 + derivs.size(2) * derivs.size(1) * q) + 1] =
          b_deriv[13];
        shapes[shapes.size(1) * q + 7] = b_N[7];
        derivs[derivs.size(2) * 7 + derivs.size(2) * derivs.size(1) * q] =
          b_deriv[14];
        derivs[(derivs.size(2) * 7 + derivs.size(2) * derivs.size(1) * q) + 1] =
          b_deriv[15];
        shapes[shapes.size(1) * q + 8] = b_N[8];
        derivs[derivs.size(2) * 8 + derivs.size(2) * derivs.size(1) * q] =
          b_deriv[16];
        derivs[(derivs.size(2) * 8 + derivs.size(2) * derivs.size(1) * q) + 1] =
          b_deriv[17];
        shapes[shapes.size(1) * q + 9] = b_N[9];
        derivs[derivs.size(2) * 9 + derivs.size(2) * derivs.size(1) * q] =
          b_deriv[18];
        derivs[(derivs.size(2) * 9 + derivs.size(2) * derivs.size(1) * q) + 1] =
          b_deriv[19];
      }
      break;

     case 80:
      for (int q{0}; q <= nqp; q++) {
        tri_15(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1], c_N,
               c_deriv);
        for (int i{0}; i < 15; i++) {
          shapes[i + shapes.size(1) * q] = c_N[i];
          xi_tmp = i << 1;
          derivs[derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q] =
            c_deriv[xi_tmp];
          derivs[(derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q) + 1]
            = c_deriv[xi_tmp + 1];
        }
      }
      break;

     case 84:
      for (int q{0}; q <= nqp; q++) {
        tri_21(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1], d_N,
               d_deriv);
        for (int i{0}; i < 21; i++) {
          shapes[i + shapes.size(1) * q] = d_N[i];
          xi_tmp = i << 1;
          derivs[derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q] =
            d_deriv[xi_tmp];
          derivs[(derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q) + 1]
            = d_deriv[xi_tmp + 1];
        }
      }
      break;

     case 88:
      for (int q{0}; q <= nqp; q++) {
        tri_28(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1], e_N,
               e_deriv);
        for (int i{0}; i < 28; i++) {
          shapes[i + shapes.size(1) * q] = e_N[i];
          xi_tmp = i << 1;
          derivs[derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q] =
            e_deriv[xi_tmp];
          derivs[(derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q) + 1]
            = e_deriv[xi_tmp + 1];
        }
      }
      break;
    }
  }

  static inline
  void sfe2_tabulate_gl_tri(int etype, const double cs_data[], const int
    cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double, 3U>
    &derivs)
  {
    double b_deriv[42];
    double deriv[30];
    double b_N[21];
    double b_dv[20];
    double c_deriv[20];
    double N[15];
    int nqp;
    int xi_tmp;

    //  triangular
    nqp = cs_size[0] - 1;

    // obtain_nnodes - Obtain number of nodes per element given etype
    xi_tmp = iv[etype - 1];
    shapes.set_size(cs_size[0], xi_tmp);
    derivs.set_size(cs_size[0], xi_tmp, cs_size[1]);
    switch (etype) {
     case 77:
      {
        for (int q{0}; q <= nqp; q++) {
          double eta;
          double t11;
          double t13;
          double t14;
          double t15;
          double t17;
          double t2;
          double t23;
          double t24;
          double t27;
          double t3;
          double t32;
          double t33;
          double t37;
          double t39;
          double t4;
          double t40;
          double t41;
          double t42;
          double t47;
          double t48;
          double t5;
          double t50;
          double t51;
          double t52;
          double t54;
          double t55;
          double t56;
          double t58;
          double t59;
          double t6;
          double t62;
          double t63;
          double t64;
          double t65;
          double t7;
          double xi;
          int b_i;
          xi_tmp = cs_size[1] * q;
          xi = cs_data[xi_tmp];
          eta = cs_data[xi_tmp + 1];

          // TRI_GL_10    Cubic triangular element with Gauss-Lobatto points
          t2 = eta * 2.0;
          t3 = eta * 5.0;
          t4 = eta * eta;
          t5 = std::pow(eta, 3.0);
          t6 = xi * xi;
          t7 = std::pow(xi, 3.0);
          t11 = eta * 21.0;
          t13 = eta * 32.0;
          t14 = eta * 54.0;
          t39 = eta * 18.541019662496851;
          t40 = eta * 21.180339887498949;
          t41 = eta * 26.180339887498949;
          t42 = eta * 48.541019662496844;
          t47 = eta * 3.819660112501051;
          t48 = eta * 1.180339887498949;
          t15 = t3 * t4;
          t17 = t7 * 5.0;
          t23 = t4 * 15.0;
          t24 = t4 * 16.0;
          t33 = -xi * (t2 - 1.0);
          t50 = t41 * xi;
          t51 = t4 * 1.9098300562505259;
          t54 = t47 * xi;
          t55 = t4 * 13.090169943749469;
          t27 = t6 * 15.0;
          t32 = eta - t4;
          t52 = t6 * 1.9098300562505259;
          t56 = t6 * 13.090169943749469;
          t58 = t6 * (eta * 13.090169943749469);
          t59 = t6 * (eta * 1.9098300562505259);
          t62 = -t40 + t4 * 24.270509831248422;
          t64 = (-t40 + t55) + 8.0901699437494745;
          t65 = (t48 + t51) - 3.0901699437494741;
          t37 = eta * 27.0 - t4 * 27.0;
          t63 = t48 - t4 * 9.2705098312484235;
          b_dv[0] = (-t27 + ((t11 - t24) - 6.0)) - xi * (t13 - 20.0);
          b_dv[1] = (t27 + (t32 + 1.0)) - xi * (t2 + 10.0);
          b_dv[2] = t32 - t2 * xi;
          b_dv[3] = (t64 + 2.23606797749979 * t27) + xi * (t42 -
            38.541019662496844);
          b_dv[4] = (t65 - t6 * 2.23606797749979 * 15.0) - xi * (t39 -
            28.541019662496851);
          b_dv[5] = t50 + (-t3 + t51);
          b_dv[6] = t54 + (-t3 + t55);
          b_dv[7] = t54 + t63;
          b_dv[8] = t50 + t62;
          b_dv[9] = t37 - t14 * xi;
          b_dv[10] = (((eta * 20.0 - t6 * 16.0) - t23) - xi * (t13 - 21.0)) -
            6.0;
          b_dv[11] = -t6 + t33;
          b_dv[12] = (((eta * -10.0 + t23) - t6) + t33) + 1.0;
          b_dv[13] = t6 * 24.270509831248422 + xi * (t41 - 21.180339887498949);
          b_dv[14] = t6 * -9.2705098312484235 + xi * (t47 + 1.180339887498949);
          b_dv[15] = t56 + xi * (t47 - 5.0);
          b_dv[16] = t52 + xi * (t41 - 5.0);
          b_dv[17] = (((eta * 28.541019662496851 + t52) - t4 * 2.23606797749979 *
                       15.0) - xi * (t39 - 1.180339887498949)) -
            3.0901699437494741;
          b_dv[18] = (((eta * -38.541019662496844 + 2.23606797749979 * t23) +
                       t56) + xi * (t42 - 21.180339887498949)) +
            8.0901699437494745;
          b_dv[19] = t6 * -27.0 - xi * (t14 - 27.0);
          xi_tmp = 0;
          b_i = 0;
          for (int i1{0}; i1 < 20; i1++) {
            c_deriv[b_i + (xi_tmp << 1)] = b_dv[i1];
            xi_tmp++;
            if (xi_tmp > 9) {
              xi_tmp = 0;
              b_i++;
            }
          }

          double shapes_tmp;
          shapes[shapes.size(1) * q] = (((((eta * -6.0 + t4 * 10.0) - t5 * 5.0)
            - t17) - xi * ((-t11 + t24) + 6.0)) + t6 * (10.0 - eta * 16.0)) +
            1.0;
          derivs[derivs.size(2) * derivs.size(1) * q] = c_deriv[0];
          derivs[derivs.size(2) * derivs.size(1) * q + 1] = c_deriv[1];
          shapes[shapes.size(1) * q + 1] = (t17 + (t32 + 1.0) * xi) - t6 * (eta
            + 5.0);
          derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] =
            c_deriv[2];
          derivs[(derivs.size(2) + derivs.size(2) * derivs.size(1) * q) + 1] =
            c_deriv[3];
          shapes_tmp = eta * t6;
          shapes[shapes.size(1) * q + 2] = (((eta - t4 * 5.0) + t15) -
            shapes_tmp) + t32 * xi;
          derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
            c_deriv[4];
          derivs[(derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q) + 1]
            = c_deriv[5];
          shapes[shapes.size(1) * q + 3] = (t6 * (eta * 24.270509831248422 -
            19.270509831248422) + t17 * 2.23606797749979) + t64 * xi;
          derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
            c_deriv[6];
          derivs[(derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q) + 1]
            = c_deriv[7];
          shapes[shapes.size(1) * q + 4] = (t7 * 2.23606797749979 * -5.0 + t65 *
            xi) + t6 * (14.27050983124842 - eta * 9.2705098312484235);
          derivs[derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q] =
            c_deriv[8];
          derivs[(derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q) + 1]
            = c_deriv[9];
          shapes[shapes.size(1) * q + 5] = t58 - xi * (t3 - t51);
          derivs[derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q] =
            c_deriv[10];
          derivs[(derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q) + 1]
            = c_deriv[11];
          shapes[shapes.size(1) * q + 6] = t59 - xi * (t3 - t55);
          derivs[derivs.size(2) * 6 + derivs.size(2) * derivs.size(1) * q] =
            c_deriv[12];
          derivs[(derivs.size(2) * 6 + derivs.size(2) * derivs.size(1) * q) + 1]
            = c_deriv[13];
          shapes[shapes.size(1) * q + 7] = (((eta * -3.0901699437494741 + t4 *
            14.27050983124842) + t59) - t5 * 2.23606797749979 * 5.0) + t63 * xi;
          derivs[derivs.size(2) * 7 + derivs.size(2) * derivs.size(1) * q] =
            c_deriv[14];
          derivs[(derivs.size(2) * 7 + derivs.size(2) * derivs.size(1) * q) + 1]
            = c_deriv[15];
          shapes[shapes.size(1) * q + 8] = (((eta * 8.0901699437494745 - t4 *
            19.270509831248422) + t15 * 2.23606797749979) + t58) + t62 * xi;
          derivs[derivs.size(2) * 8 + derivs.size(2) * derivs.size(1) * q] =
            c_deriv[16];
          derivs[(derivs.size(2) * 8 + derivs.size(2) * derivs.size(1) * q) + 1]
            = c_deriv[17];
          shapes[shapes.size(1) * q + 9] = shapes_tmp * -27.0 + t37 * xi;
          derivs[derivs.size(2) * 9 + derivs.size(2) * derivs.size(1) * q] =
            c_deriv[18];
          derivs[(derivs.size(2) * 9 + derivs.size(2) * derivs.size(1) * q) + 1]
            = c_deriv[19];
        }
      }
      break;

     case 81:
      for (int q{0}; q <= nqp; q++) {
        tri_gl_15(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1], N, deriv);
        for (int i{0}; i < 15; i++) {
          shapes[i + shapes.size(1) * q] = N[i];
          xi_tmp = i << 1;
          derivs[derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q] =
            deriv[xi_tmp];
          derivs[(derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q) + 1]
            = deriv[xi_tmp + 1];
        }
      }
      break;

     case 85:
      for (int q{0}; q <= nqp; q++) {
        tri_gl_21(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1], b_N,
                  b_deriv);
        for (int i{0}; i < 21; i++) {
          shapes[i + shapes.size(1) * q] = b_N[i];
          xi_tmp = i << 1;
          derivs[derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q] =
            b_deriv[xi_tmp];
          derivs[(derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q) + 1]
            = b_deriv[xi_tmp + 1];
        }
      }
      break;

     case 89:
      break;
    }
  }

  static inline
  void sfe2_tabulate_shapefuncs(int etype, const double cs_data[], const
    int cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double,
    3U> &derivs)
  {
    double b_deriv[56];
    double deriv[42];
    double b_dv[30];
    double c_deriv[30];
    double b_N[28];
    double N[21];
    double c_N[15];
    double N_eta[6];
    double N_xi[6];
    double deriv_eta[6];
    double deriv_xi[6];
    double c_N_eta[5];
    double c_N_xi[5];
    double c_deriv_eta[5];
    double c_deriv_xi[5];
    double b_N_eta[4];
    double b_N_xi[4];
    double b_deriv_eta[4];
    double b_deriv_xi[4];

    // sfe2_tabulate_shapefuncs - Tabulate shape functions and derivs at qpoints
    switch (etype & 3) {
     case 0:
      sfe2_tabulate_equi(etype, cs_data, cs_size, shapes, derivs);
      break;

     case 1:
      {
        //  GL kernel
        if ((etype >> 5 & 7) == 2) {
          sfe2_tabulate_gl_tri(etype, cs_data, cs_size, shapes, derivs);
        } else {
          int nqp;
          int xi_tmp;

          //  quad
          nqp = cs_size[0] - 1;

          // obtain_nnodes - Obtain number of nodes per element given etype
          xi_tmp = iv[etype - 1];
          shapes.set_size(cs_size[0], xi_tmp);
          derivs.set_size(cs_size[0], xi_tmp, cs_size[1]);
          switch (etype) {
           case 109:
            {
              for (int q{0}; q <= nqp; q++) {
                double eta;
                double t2;
                double t3;
                double t4;
                double t6;
                double xi;
                xi_tmp = cs_size[1] * q;
                xi = cs_data[xi_tmp];
                eta = cs_data[xi_tmp + 1];

                // QUAD_GL_16   Bicubic quadrilateral element with Gauss-Lobatto points
                t2 = xi * xi;
                t3 = std::pow(xi, 3.0);
                t4 = t3 * 5.0;
                b_N_xi[0] = ((t2 * 10.0 - t4) + -6.0 * xi) + 1.0;
                b_N_xi[1] = (t2 * -5.0 + t4) + xi;
                b_N_xi[2] = (t2 * -19.270509831248422 + t4 * 2.23606797749979) +
                  8.0901699437494745 * xi;
                b_N_xi[3] = (t2 * 14.27050983124842 - t3 * 2.23606797749979 *
                             5.0) + -3.0901699437494741 * xi;
                t6 = t2 * 15.0;
                b_deriv_xi[0] = (-t6 + 20.0 * xi) - 6.0;
                b_deriv_xi[1] = (t6 + -10.0 * xi) + 1.0;
                b_deriv_xi[2] = (2.23606797749979 * t6 + -38.541019662496844 *
                                 xi) + 8.0901699437494745;
                b_deriv_xi[3] = (28.541019662496851 * xi - t2 * 2.23606797749979
                                 * 15.0) - 3.0901699437494741;

                // BAR_GL_4  Cubic bar element with Gauss-Lobatto nodes
                t2 = eta * eta;
                t3 = std::pow(eta, 3.0);
                t4 = t3 * 5.0;
                b_N_eta[0] = ((t2 * 10.0 - t4) + -6.0 * eta) + 1.0;
                b_N_eta[1] = (t2 * -5.0 + t4) + eta;
                b_N_eta[2] = (t2 * -19.270509831248422 + t4 * 2.23606797749979)
                  + 8.0901699437494745 * eta;
                b_N_eta[3] = (t2 * 14.27050983124842 - t3 * 2.23606797749979 *
                              5.0) + -3.0901699437494741 * eta;
                t6 = t2 * 15.0;
                b_deriv_eta[0] = (-t6 + 20.0 * eta) - 6.0;
                b_deriv_eta[1] = (t6 + -10.0 * eta) + 1.0;
                b_deriv_eta[2] = (2.23606797749979 * t6 + -38.541019662496844 *
                                  eta) + 8.0901699437494745;
                b_deriv_eta[3] = (28.541019662496851 * eta - t2 *
                                  2.23606797749979 * 15.0) - 3.0901699437494741;
                for (int k{0}; k < 16; k++) {
                  double N_tmp;
                  int shapes_tmp;
                  xi_tmp = iv5[k] - 1;
                  shapes_tmp = iv6[k] - 1;
                  eta = b_N_eta[shapes_tmp];
                  N_tmp = b_N_xi[xi_tmp];
                  shapes[k + shapes.size(1) * q] = N_tmp * eta;
                  derivs[derivs.size(2) * k + derivs.size(2) * derivs.size(1) *
                    q] = b_deriv_xi[xi_tmp] * eta;
                  derivs[(derivs.size(2) * k + derivs.size(2) * derivs.size(1) *
                          q) + 1] = N_tmp * b_deriv_eta[shapes_tmp];
                }
              }
            }
            break;

           case 113:
            {
              for (int q{0}; q <= nqp; q++) {
                double t2;
                double t3;
                double t4;
                double t5;
                double t6;
                double t7;
                double t8;
                double xi;

                // QUAD_GL_25   Biquartic quadrilateral element with Gauss-Lobatto points
                xi_tmp = cs_size[1] * q;
                xi = cs_data[xi_tmp];

                // BAR_GL_5  Quartic bar element with Gauss-Lobatto nodes
                t2 = xi * xi;
                t3 = std::pow(xi, 3.0);
                t4 = t2 * t2;
                t6 = t3 * 56.0;
                t8 = t3 * 130.66666666666666;
                t5 = t4 * 14.0;
                t7 = t4 * 32.666666666666664;
                c_N_xi[0] = (((t2 * 30.0 - t3 * 35.0) + t5) + -10.0 * xi) + 1.0;
                c_N_xi[1] = ((t2 * 9.0 - t3 * 21.0) + t5) + -xi;
                c_N_xi[2] = ((t2 * -56.872348265678767 + t3 * 76.026009954896963)
                             - t7) + 13.51300497744848 * xi;
                c_N_xi[3] = ((t2 * 42.666666666666664 - t3 * 74.666666666666671)
                             + t4 * 37.333333333333336) + -5.333333333333333 *
                  xi;
                c_N_xi[4] = ((t2 * -24.794318400987891 + t3 * 54.640656711769708)
                             - t7) + 2.820328355884854 * xi;
                c_deriv_xi[0] = ((t2 * -105.0 + t6) + 60.0 * xi) - 10.0;
                c_deriv_xi[1] = ((t2 * -63.0 + t6) + 18.0 * xi) - 1.0;
                c_deriv_xi[2] = ((t2 * 228.0780298646909 - t8) +
                                 -113.7446965313575 * xi) + 13.51300497744848;
                c_deriv_xi[3] = ((t2 * -224.0 + t3 * 149.33333333333334) +
                                 85.333333333333329 * xi) - 5.333333333333333;
                c_deriv_xi[4] = ((t2 * 163.9219701353091 - t8) +
                                 -49.588636801975788 * xi) + 2.820328355884854;
                xi = cs_data[xi_tmp + 1];

                // BAR_GL_5  Quartic bar element with Gauss-Lobatto nodes
                t2 = xi * xi;
                t3 = std::pow(xi, 3.0);
                t4 = t2 * t2;
                t6 = t3 * 56.0;
                t8 = t3 * 130.66666666666666;
                t5 = t4 * 14.0;
                t7 = t4 * 32.666666666666664;
                c_N_eta[0] = (((t2 * 30.0 - t3 * 35.0) + t5) + -10.0 * xi) + 1.0;
                c_N_eta[1] = ((t2 * 9.0 - t3 * 21.0) + t5) + -xi;
                c_N_eta[2] = ((t2 * -56.872348265678767 + t3 *
                               76.026009954896963) - t7) + 13.51300497744848 *
                  xi;
                c_N_eta[3] = ((t2 * 42.666666666666664 - t3 * 74.666666666666671)
                              + t4 * 37.333333333333336) + -5.333333333333333 *
                  xi;
                c_N_eta[4] = ((t2 * -24.794318400987891 + t3 *
                               54.640656711769708) - t7) + 2.820328355884854 *
                  xi;
                c_deriv_eta[0] = ((t2 * -105.0 + t6) + 60.0 * xi) - 10.0;
                c_deriv_eta[1] = ((t2 * -63.0 + t6) + 18.0 * xi) - 1.0;
                c_deriv_eta[2] = ((t2 * 228.0780298646909 - t8) +
                                  -113.7446965313575 * xi) + 13.51300497744848;
                c_deriv_eta[3] = ((t2 * -224.0 + t3 * 149.33333333333334) +
                                  85.333333333333329 * xi) - 5.333333333333333;
                c_deriv_eta[4] = ((t2 * 163.9219701353091 - t8) +
                                  -49.588636801975788 * xi) + 2.820328355884854;
                for (int k{0}; k < 25; k++) {
                  double N_tmp;
                  double eta;
                  int shapes_tmp;
                  xi_tmp = iv3[k] - 1;
                  shapes_tmp = iv4[k] - 1;
                  eta = c_N_eta[shapes_tmp];
                  N_tmp = c_N_xi[xi_tmp];
                  shapes[k + shapes.size(1) * q] = N_tmp * eta;
                  derivs[derivs.size(2) * k + derivs.size(2) * derivs.size(1) *
                    q] = c_deriv_xi[xi_tmp] * eta;
                  derivs[(derivs.size(2) * k + derivs.size(2) * derivs.size(1) *
                          q) + 1] = N_tmp * c_deriv_eta[shapes_tmp];
                }
              }
            }
            break;

           case 117:
            {
              for (int q{0}; q <= nqp; q++) {
                // QUAD_GL_36   Biquintic quadrilateral element with equidistant points
                bar_gl_6(cs_data[cs_size[1] * q], N_xi, deriv_xi);
                bar_gl_6(cs_data[cs_size[1] * q + 1], N_eta, deriv_eta);
                for (int k{0}; k < 36; k++) {
                  double N_tmp;
                  double eta;
                  int shapes_tmp;
                  xi_tmp = iv1[k] - 1;
                  shapes_tmp = iv2[k] - 1;
                  eta = N_eta[shapes_tmp];
                  N_tmp = N_xi[xi_tmp];
                  shapes[k + shapes.size(1) * q] = N_tmp * eta;
                  derivs[derivs.size(2) * k + derivs.size(2) * derivs.size(1) *
                    q] = deriv_xi[xi_tmp] * eta;
                  derivs[(derivs.size(2) * k + derivs.size(2) * derivs.size(1) *
                          q) + 1] = N_tmp * deriv_eta[shapes_tmp];
                }
              }
            }
            break;

           case 121:
            break;
          }
        }
      }
      break;

     default:
      {
        int nqp;
        int xi_tmp;

        //  FEK kernel
        nqp = cs_size[0] - 1;

        // obtain_nnodes - Obtain number of nodes per element given etype
        xi_tmp = iv[etype - 1];
        shapes.set_size(cs_size[0], xi_tmp);
        derivs.set_size(cs_size[0], xi_tmp, cs_size[1]);
        switch (etype) {
         case 82:
          {
            for (int q{0}; q <= nqp; q++) {
              double N_tmp;
              double eta;
              double t12;
              double t16;
              double t2;
              double t20;
              double t21;
              double t24;
              double t3;
              double t32;
              double t37;
              double t38;
              double t4;
              double t40;
              double t43;
              double t5;
              double t51;
              double t53;
              double t6;
              double t63;
              double t7;
              double t77;
              double t78;
              double t8;
              double t80;
              double t81;
              double t85;
              double t86;
              double t87;
              double t88;
              double t89;
              double t90;
              double t91;
              double xi;
              int shapes_tmp;
              xi_tmp = cs_size[1] * q;
              xi = cs_data[xi_tmp];
              eta = cs_data[xi_tmp + 1];

              // TRI_FEK_15
              t2 = eta * eta;
              t3 = std::pow(eta, 3.0);
              t5 = xi * xi;
              t6 = std::pow(xi, 3.0);
              t8 = eta * 35.99475159940539;
              t12 = eta * 382.96436895930782;
              t16 = eta * 67.373436838649965;
              t20 = eta * 23.249222765165111;
              t24 = eta * 2.6691526018761249;
              t32 = eta * 3.3910615596941822;
              t4 = t2 * t2;
              t7 = t5 * t5;
              t21 = t3 * 15.9541893883758;
              t37 = t2 * 130.61492651117149;
              t38 = t3 * 107.3657037460064;
              t40 = t2 * 179.26558738560871;
              t43 = t2 * 10.9953907691365;
              t51 = t3 * 114.71247890272561;
              t53 = t3 * 8.32623825722872;
              t63 = t2 * 0.94987715253559157;
              t86 = (-(eta * 23.249221870808569) + t2 * 23.249219587707358) + t3
                * 2.2831012060986469E-6;
              t91 = ((-(eta * 2.66915259326103) + t2 * 2.6691520084772291) + t3 *
                     5.0655270788988256E-7) - 0.99999992176890706;
              t77 = (-(t2 * 17.9973757997027) + eta * 4.5154339230597351) + t3 *
                8.1486087058664829;
              t78 = (eta * 84.116480733647336 + t3 * 107.3657037460065) - t2 *
                191.48218447965391;
              t80 = (t3 * 74.666666736349413 + eta * 7.0334926021123527) - t2 *
                76.366825996784044;
              t81 = (eta * 5.7227573781081444 + t3 * 46.0701833833608) - t2 *
                38.279935796300748;
              t85 = (eta * 5.7227571238932189 - t3 * 3.3089619900123068) + t2 *
                0.40653316316559313;
              t87 = ((eta * 65.657086733831548 + t3 * 64.326239040280072) - t2 *
                     118.98332555300919) - 10.000000227266;
              t88 = ((-(eta * 67.37343663413661) + t2 * 99.930616063047822) - t3
                     * 46.070184426177441) + 13.513004997266229;
              t89 = ((eta * 3.3910618415802021 + t3 * 3.30896052274144) - t2 *
                     9.5203505844727339) + 2.820328220151092;
              t90 = ((eta * 7.0334914079706774 + t2 * 6.4484498741441652) - t3 *
                     8.1486082137324232) - 5.3333330683824176;
              c_N[0] = ((((eta * -9.99999997065184 + t2 * 29.999999876443749) -
                          t3 * 34.999999834768367) + t4 * 13.999999928976459) +
                        t7 * 14.00000061099419) + (((t6 * (eta *
                64.326240355586762 - 35.000001371023266) + t87 * xi) + t5 *
                ((eta * -118.9833270405354 + t2 * 100.65247885589621) +
                 30.000000987295081)) + 1.0);
              c_N[1] = ((t7 * 13.999999515758841 + t91 * xi) - t6 * (eta *
                         8.3262385889289252 + 20.99999911717607)) + t5 * ((eta *
                10.99539092686223 - t2 * 8.3262374152585821) + 8.99999952318614);
              N_tmp = eta * t6;
              c_N[2] = ((((eta * -1.000000006163611 + t2 * 9.0000000261243382) -
                          t3 * 21.000000035227739) + t4 * 14.000000015267011) +
                        N_tmp * 3.5311773678704662E-7) + (t5 * (eta *
                2.669152254921999 - t2 * 8.3262377365015183) - xi * ((t24 - t43)
                + t53));
              c_N[3] = ((t7 * -32.66666689620714 + t88 * xi) + t6 *
                        (76.026010338843165 - eta * 114.71247878438351)) + -t5 *
                ((eta * -179.26558696768271 + t2 * 128.11599631435379) +
                 56.872348439902261);
              c_N[4] = ((t7 * 37.33333310799469 + t6 * (eta * 74.66666479127538
                          - 74.666665798756867)) + t90 * xi) + t5 * ((eta *
                -76.366822713631137 + t2 * 29.18472346954827) + 42.6666657591446);
              c_N[5] = ((t7 * -32.666666338540587 + t89 * xi) - t5 * ((eta *
                          0.9498780889532179 - t2 * 20.02143815953583) +
                         24.794317829723571)) + t6 * (54.640655948113057 - eta *
                15.95418870174618);
              c_N[6] = (-t5 * (eta * 38.279935217607623 - t2 *
                               10.094554544440889) + N_tmp * 46.0701830588826) +
                t85 * xi;
              c_N[7] = (N_tmp * 8.1486087058664829 + t77 * xi) - t5 * (eta *
                17.9973757997027 - t2 * 53.630550094838867);
              c_N[8] = (N_tmp * -3.308961665534107 + t81 * xi) + t5 * (eta *
                0.40653258447246859 + t2 * 10.094555193397291);
              c_N[9] = ((((eta * 2.8203283739419209 - t2 * 24.794318476984891) +
                          t3 * 54.640656813361232) - t4 * 32.66666671031826) +
                        N_tmp * 3.308960617326318) + (-t5 * (eta *
                9.52035055096242 - t2 * 20.021437939268768) - xi * ((t21 - t32)
                + t63));
              c_N[10] = (((eta * -5.33333337455031 + t2 * 42.666666839878957) -
                          t3 * 74.666666897784708) + t4 * 37.333333432456058) +
                ((t5 * (eta * 6.4484485169566828 + t2 * 29.184725559374641) -
                  N_tmp * 8.1486077445187259) + t80 * xi);
              c_N[11] = ((((eta * 13.51300497742384 - t2 * 56.872348265462151) +
                           t3 * 76.026009954419578) - t4 * 32.666666666381261) -
                         N_tmp * 46.070184680045188) + (t5 * (eta *
                99.93061654127132 - t2 * 128.11599691638949) - xi * ((t16 - t40)
                + t51));
              c_N[12] = (N_tmp * 107.3657037460065 + t78 * xi) - t5 * (eta *
                191.48218447965391 - t2 * 214.73140749201309);
              c_N[13] = (t5 * (eta * 130.61492447526439 - t2 *
                               107.36570032135459) - N_tmp * 107.36570260445581)
                + t86 * xi;
              c_N[14] = (N_tmp * 1.1415506004681411E-6 - xi * ((t20 - t37) + t38))
                + t5 * (eta * 23.24922162361451 - t2 * 107.36570260445581);
              b_dv[0] = ((t6 * 56.000002443976761 + t87) + t5 * (eta *
                          192.9787210667603 - 105.00000411306981)) + xi * ((eta *
                -237.96665408107069 + t2 * 201.30495771179241) +
                60.000001974590162);
              b_dv[1] = ((t6 * 55.999998063035363 + t91) - t5 * (eta *
                          24.978715766786781 + 62.999997351528222)) + xi * ((eta
                * 21.99078185372446 - t2 * 16.652474830517161) +
                17.999999046372281);
              N_tmp = eta * t5;
              b_dv[2] = (((t43 - t24) - t53) + N_tmp * 1.05935321036114E-6) + xi
                * (eta * 5.3383045098439981 - t2 * 16.65247547300304);
              b_dv[3] = ((t6 * -130.66666758482859 + t88) - xi * ((eta *
                -358.53117393536547 + t2 * 256.23199262870759) +
                          113.74469687980449)) + t5 * (228.07803101652951 - eta *
                344.13743635315041);
              b_dv[4] = ((t6 * 149.33333243197879 + t90) + xi * ((eta *
                -152.7336454272623 + t2 * 58.369446939096548) + 85.3333315182892))
                + t5 * (eta * 223.9999943738261 - 223.9999973962706);
              b_dv[5] = ((t6 * -130.66666535416229 + t89) - xi * ((eta *
                1.899756177906436 - t2 * 40.042876319071667) +
                          49.588635659447142)) + t5 * (163.92196784433921 - eta *
                47.862566105238542);
              b_dv[6] = (t85 - xi * (eta * 76.559870435215245 - t2 *
                          20.189109088881779)) + N_tmp * 138.21054917664779;
              b_dv[7] = (t77 + N_tmp * 24.445826117599449) + xi * (t2 *
                107.26110018967771 - t8);
              b_dv[8] = (t81 - N_tmp * 9.9268849966023218) + xi * (eta *
                0.8130651689449373 + t2 * 20.189110386794582);
              b_dv[9] = (((t32 - t21) - t63) + N_tmp * 9.9268818519789548) - xi *
                (eta * 19.040701101924839 - t2 * 40.042875878537536);
              b_dv[10] = (t80 + xi * (eta * 12.896897033913371 + t2 *
                58.369451118749282)) - N_tmp * 24.44582323355618;
              b_dv[11] = (((-t16 + t40) - t51) - N_tmp * 138.21055404013561) +
                xi * (eta * 199.86123308254261 - t2 * 256.231993832779);
              b_dv[12] = (t78 + xi * (t2 * 429.46281498402612 - t12)) + N_tmp *
                322.09711123801958;
              b_dv[13] = (t86 + xi * (eta * 261.22984895052872 - t2 *
                214.73140064270919)) - N_tmp * 322.09710781336742;
              b_dv[14] = (((-t20 + t37) - t38) + N_tmp * 3.4246518014044239E-6)
                + xi * (eta * 46.498443247229019 - t2 * 214.73140520891161);
              b_dv[15] = ((((eta * 59.9999997528875 - t2 * 104.99999950430509) +
                            t3 * 55.99999971590583) + t6 * 64.326240355586762) +
                          (t5 * (eta * 201.30495771179241 - 118.9833270405354) +
                           xi * ((eta * -237.9666511060185 + t2 *
                                  192.9787171208402) + 65.657086733831548))) +
                -9.99999997065184;
              b_dv[16] = (t6 * -8.3262385889289252 + t5 * (10.99539092686223 -
                eta * 16.652474830517161)) + xi * ((eta * 5.3383040169544582 +
                t2 * 1.519658123669648E-6) - 2.66915259326103);
              b_dv[17] = ((((eta * 18.00000005224868 - t2 * 63.000000105683213)
                            + t3 * 56.000000061068043) + t6 *
                           3.5311773678704662E-7) + (-xi * ((eta *
                -21.990781538273 + t2 * 24.97871477168616) + 2.6691526018761249)
                + t5 * (2.669152254921999 - eta * 16.65247547300304))) +
                -1.000000006163611;
              b_dv[18] = (t6 * -114.71247878438351 + t5 * (179.26558696768271 -
                eta * 256.23199262870759)) + -xi * ((eta * -199.86123212609559 +
                t2 * 138.2105532785323) + 67.37343663413661);
              b_dv[19] = (t6 * 74.66666479127538 + xi * ((eta *
                12.89689974828833 - t2 * 24.44582464119727) + 7.0334914079706774))
                + t5 * (eta * 58.369446939096548 - 76.366822713631137);
              b_dv[20] = (t6 * -15.95418870174618 + t5 * (eta *
                40.042876319071667 - 0.9498780889532179)) + xi * ((eta *
                -19.040701168945471 + t2 * 9.92688156822432) +
                3.3910618415802021);
              b_dv[21] = (t6 * 46.0701830588826 + t5 * (eta * 20.189109088881779
                - 38.279935217607623)) + xi * ((eta * 0.81306632633118625 - t2 *
                9.92688597003692) + 5.7227571238932189);
              b_dv[22] = (t6 * 8.1486087058664829 + t5 * (eta *
                107.26110018967771 - 17.9973757997027)) + xi * ((t2 *
                24.445826117599449 - t8) + 4.5154339230597351);
              b_dv[23] = (t6 * -3.308961665534107 + xi * ((eta *
                -76.5598715926015 + t2 * 138.21055015008241) +
                5.7227573781081444)) + t5 * (eta * 20.189110386794582 +
                0.40653258447246859);
              b_dv[24] = ((((eta * -49.58863695396979 + t2 * 163.9219704400837)
                            - t3 * 130.666666841273) + t6 * 3.308960617326318) +
                          (-xi * ((eta * 1.8997543050711829 + t2 *
                                   47.862568165127392) - 3.3910615596941822) +
                           t5 * (eta * 40.042875878537536 - 9.52035055096242)))
                + 2.8203283739419209;
              b_dv[25] = ((((eta * 85.333333679757914 - t2 * 224.00000069335411)
                            + t3 * 149.3333337298242) - t6 * 8.1486077445187259)
                          + (t5 * (eta * 58.369451118749282 + 6.4484485169566828)
                             + xi * ((eta * -152.73365199356809 + t2 *
                224.00000020904821) + 7.0334926021123527))) + -5.33333337455031;
              b_dv[26] = ((((eta * -113.7446965309243 + t2 * 228.07802986325871)
                            - t3 * 130.666666665525) - t6 * 46.070184680045188)
                          + (-xi * ((eta * -358.53117477121748 + t2 *
                344.13743670817672) + 67.373436838649965) + t5 *
                             (99.93061654127132 - eta * 256.231993832779))) +
                13.51300497742384;
              b_dv[27] = (t6 * 107.3657037460065 + xi * ((t2 *
                322.09711123801958 - t12) + 84.116480733647336)) + t5 * (eta *
                429.46281498402612 - 191.48218447965391);
              b_dv[28] = (t6 * -107.36570260445581 + t5 * (130.61492447526439 -
                eta * 214.73140064270919)) + xi * ((eta * 46.498439175414717 +
                t2 * 6.8493036182959423E-6) - 23.249221870808569);
              b_dv[29] = (t6 * 1.1415506004681411E-6 + t5 * (23.24922162361451 -
                eta * 214.73140520891161)) + -xi * ((eta * -261.229853022343 +
                t2 * 322.09711123801918) + 23.249222765165111);
              xi_tmp = 0;
              shapes_tmp = 0;
              for (int b_i{0}; b_i < 30; b_i++) {
                c_deriv[shapes_tmp + (xi_tmp << 1)] = b_dv[b_i];
                xi_tmp++;
                if (xi_tmp > 14) {
                  xi_tmp = 0;
                  shapes_tmp++;
                }
              }

              for (int i{0}; i < 15; i++) {
                shapes[i + shapes.size(1) * q] = c_N[i];
                xi_tmp = i << 1;
                derivs[derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q]
                  = c_deriv[xi_tmp];
                derivs[(derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q)
                  + 1] = c_deriv[xi_tmp + 1];
              }
            }
          }
          break;

         case 86:
          for (int q{0}; q <= nqp; q++) {
            tri_fek_21(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1], N,
                       deriv);
            for (int i{0}; i < 21; i++) {
              shapes[i + shapes.size(1) * q] = N[i];
              xi_tmp = i << 1;
              derivs[derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q] =
                deriv[xi_tmp];
              derivs[(derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q)
                + 1] = deriv[xi_tmp + 1];
            }
          }
          break;

         case 89:
          for (int q{0}; q <= nqp; q++) {
            tri_fek_28(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1], b_N,
                       b_deriv);
            for (int i{0}; i < 28; i++) {
              shapes[i + shapes.size(1) * q] = b_N[i];
              xi_tmp = i << 1;
              derivs[derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q] =
                b_deriv[xi_tmp];
              derivs[(derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q)
                + 1] = b_deriv[xi_tmp + 1];
            }
          }
          break;
        }
      }
      break;
    }
  }

  static inline
  void sfe3_tabulate_shapefuncs(int etype, const double cs_data[], const
    int cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double,
    3U> &derivs)
  {
    double c_deriv[105];
    double b_deriv[60];
    double c_N[35];
    double deriv[30];
    double b_N[20];
    double N[10];
    int nqp;
    int xi_tmp;

    // sfe3_tabulate_shapefuncs - Tabulate shape functions and derivs at qpoints
    nqp = cs_size[0] - 1;

    // obtain_nnodes - Obtain number of nodes per element given etype
    xi_tmp = iv[etype - 1];
    shapes.set_size(cs_size[0], xi_tmp);
    derivs.set_size(cs_size[0], xi_tmp, cs_size[1]);
    switch (etype) {
     case 132:
      {
        for (int q{0}; q <= nqp; q++) {
          double eta;
          double xi;
          double zeta;
          xi_tmp = cs_size[1] * q;
          xi = cs_data[xi_tmp];
          eta = cs_data[xi_tmp + 1];
          zeta = cs_data[xi_tmp + 2];

          // TET_4    Linear tetrahedral element
          shapes[shapes.size(1) * q] = -xi + ((1.0 - zeta) - eta);
          derivs[derivs.size(2) * derivs.size(1) * q] = -1.0;
          derivs[derivs.size(2) * derivs.size(1) * q + 1] = -1.0;
          derivs[derivs.size(2) * derivs.size(1) * q + 2] = -1.0;
          shapes[shapes.size(1) * q + 1] = xi;
          derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] = 1.0;
          derivs[(derivs.size(2) + derivs.size(2) * derivs.size(1) * q) + 1] =
            0.0;
          derivs[(derivs.size(2) + derivs.size(2) * derivs.size(1) * q) + 2] =
            0.0;
          shapes[shapes.size(1) * q + 2] = eta;
          derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] = 0.0;
          derivs[(derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q) + 1]
            = 1.0;
          derivs[(derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q) + 2]
            = 0.0;
          shapes[shapes.size(1) * q + 3] = zeta;
          derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] = 0.0;
          derivs[(derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q) + 1]
            = 0.0;
          derivs[(derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q) + 2]
            = 1.0;
        }
      }
      break;

     case 136:
      for (int q{0}; q <= nqp; q++) {
        tet_10(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1],
               cs_data[cs_size[1] * q + 2], N, deriv);
        shapes[shapes.size(1) * q] = N[0];
        derivs[derivs.size(2) * derivs.size(1) * q] = deriv[0];
        derivs[derivs.size(2) * derivs.size(1) * q + 1] = deriv[1];
        derivs[derivs.size(2) * derivs.size(1) * q + 2] = deriv[2];
        shapes[shapes.size(1) * q + 1] = N[1];
        derivs[derivs.size(2) + derivs.size(2) * derivs.size(1) * q] = deriv[3];
        derivs[(derivs.size(2) + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[4];
        derivs[(derivs.size(2) + derivs.size(2) * derivs.size(1) * q) + 2] =
          deriv[5];
        shapes[shapes.size(1) * q + 2] = N[2];
        derivs[derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q] =
          deriv[6];
        derivs[(derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[7];
        derivs[(derivs.size(2) * 2 + derivs.size(2) * derivs.size(1) * q) + 2] =
          deriv[8];
        shapes[shapes.size(1) * q + 3] = N[3];
        derivs[derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q] =
          deriv[9];
        derivs[(derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[10];
        derivs[(derivs.size(2) * 3 + derivs.size(2) * derivs.size(1) * q) + 2] =
          deriv[11];
        shapes[shapes.size(1) * q + 4] = N[4];
        derivs[derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q] =
          deriv[12];
        derivs[(derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[13];
        derivs[(derivs.size(2) * 4 + derivs.size(2) * derivs.size(1) * q) + 2] =
          deriv[14];
        shapes[shapes.size(1) * q + 5] = N[5];
        derivs[derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q] =
          deriv[15];
        derivs[(derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[16];
        derivs[(derivs.size(2) * 5 + derivs.size(2) * derivs.size(1) * q) + 2] =
          deriv[17];
        shapes[shapes.size(1) * q + 6] = N[6];
        derivs[derivs.size(2) * 6 + derivs.size(2) * derivs.size(1) * q] =
          deriv[18];
        derivs[(derivs.size(2) * 6 + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[19];
        derivs[(derivs.size(2) * 6 + derivs.size(2) * derivs.size(1) * q) + 2] =
          deriv[20];
        shapes[shapes.size(1) * q + 7] = N[7];
        derivs[derivs.size(2) * 7 + derivs.size(2) * derivs.size(1) * q] =
          deriv[21];
        derivs[(derivs.size(2) * 7 + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[22];
        derivs[(derivs.size(2) * 7 + derivs.size(2) * derivs.size(1) * q) + 2] =
          deriv[23];
        shapes[shapes.size(1) * q + 8] = N[8];
        derivs[derivs.size(2) * 8 + derivs.size(2) * derivs.size(1) * q] =
          deriv[24];
        derivs[(derivs.size(2) * 8 + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[25];
        derivs[(derivs.size(2) * 8 + derivs.size(2) * derivs.size(1) * q) + 2] =
          deriv[26];
        shapes[shapes.size(1) * q + 9] = N[9];
        derivs[derivs.size(2) * 9 + derivs.size(2) * derivs.size(1) * q] =
          deriv[27];
        derivs[(derivs.size(2) * 9 + derivs.size(2) * derivs.size(1) * q) + 1] =
          deriv[28];
        derivs[(derivs.size(2) * 9 + derivs.size(2) * derivs.size(1) * q) + 2] =
          deriv[29];
      }
      break;

     case 140:
      for (int q{0}; q <= nqp; q++) {
        tet_20(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1],
               cs_data[cs_size[1] * q + 2], b_N, b_deriv);
        for (int i{0}; i < 20; i++) {
          shapes[i + shapes.size(1) * q] = b_N[i];
          derivs[derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q] =
            b_deriv[3 * i];
          derivs[(derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q) + 1]
            = b_deriv[3 * i + 1];
          derivs[(derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q) + 2]
            = b_deriv[3 * i + 2];
        }
      }
      break;

     case 144:
      for (int q{0}; q <= nqp; q++) {
        tet_35(cs_data[cs_size[1] * q], cs_data[cs_size[1] * q + 1],
               cs_data[cs_size[1] * q + 2], c_N, c_deriv);
        for (int i{0}; i < 35; i++) {
          shapes[i + shapes.size(1) * q] = c_N[i];
          derivs[derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q] =
            c_deriv[3 * i];
          derivs[(derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q) + 1]
            = c_deriv[3 * i + 1];
          derivs[(derivs.size(2) * i + derivs.size(2) * derivs.size(1) * q) + 2]
            = c_deriv[3 * i + 2];
        }
      }
      break;

     case 148:
     case 152:
      break;
    }

    //  For compilation purpose
  }

  static inline
  void sfe_init_grad(SfeObject *b_sfe, int q)
  {
    double Jt[9];
    int b_i;
    int d;
    int dim;
    int i;
    int n;
    int sfe_idx_0;

    // sfe_grad - Compute gradients of shape functions in physical space
    if (b_sfe->jacTs.size(0) == 1) {
      for (i = 0; i < 9; i++) {
        Jt[i] = b_sfe->jacTs[0].data[i];
      }
    } else {
      for (i = 0; i < 9; i++) {
        Jt[i] = b_sfe->jacTs[q - 1].data[i];
      }
    }

    dim = b_sfe->derivs_trial.size(2);
    n = b_sfe->derivs_trial.size(1);
    sfe_idx_0 = b_sfe->derivs_trial.size(1);
    b_sfe->grads_trial.set_size(sfe_idx_0, b_sfe->derivs_trial.size(2));
    for (b_i = 0; b_i < n; b_i++) {
      for (d = 0; d < dim; d++) {
        b_sfe->grads_trial[d + b_sfe->grads_trial.size(1) * b_i] =
          b_sfe->derivs_trial[(d + b_sfe->derivs_trial.size(2) * b_i) +
          b_sfe->derivs_trial.size(2) * b_sfe->derivs_trial.size(1) * (q - 1)];
      }
    }

    //  compute gradient for both trial and test
    if (b_sfe->etypes[0] == b_sfe->etypes[2]) {
      solve_sq(Jt, b_sfe->geom_dim, b_sfe->grads_trial);
      sfe_idx_0 = b_sfe->grads_trial.size(1) * b_sfe->grads_trial.size(0);
      b_sfe->grads_test.set_size(b_sfe->grads_trial.size(0),
        b_sfe->grads_trial.size(1));
      for (i = 0; i < sfe_idx_0; i++) {
        b_sfe->grads_test[i] = b_sfe->grads_trial[i];
      }
    } else {
      //  solve for test at the same time
      dim = b_sfe->derivs_test.size(2);
      n = b_sfe->derivs_test.size(1);
      sfe_idx_0 = b_sfe->derivs_test.size(1);
      b_sfe->grads_test.set_size(sfe_idx_0, b_sfe->derivs_test.size(2));
      for (b_i = 0; b_i < n; b_i++) {
        for (d = 0; d < dim; d++) {
          b_sfe->grads_test[d + b_sfe->grads_test.size(1) * b_i] =
            b_sfe->derivs_test[(d + b_sfe->derivs_test.size(2) * b_i) +
            b_sfe->derivs_test.size(2) * b_sfe->derivs_test.size(1) * (q - 1)];
        }
      }

      solve_sq(Jt, b_sfe->geom_dim, b_sfe->grads_trial, b_sfe->grads_test);
    }
  }

  static inline
  boolean_T solve_sq(double J[9], int n, ::coder::array<double, 2U> &b1, ::
    coder::array<double, 2U> &b2)
  {
    int m1;
    int m2;
    boolean_T info;

    // solve_local - Solve local 1x1, 2x2, or 3x3 systems
    m1 = b1.size(0) - 1;
    m2 = b2.size(0) - 1;
    info = false;
    if (n == 1) {
      if (J[0] == 0.0) {
        info = true;
      } else {
        double ji;
        int b_i;
        int i;
        int i1;
        ji = 1.0 / J[0];
        for (i = 0; i <= m1; i++) {
          b_i = b1.size(0);
          i1 = b1.size(0);
          b1[i % b_i * b1.size(1) + i / b_i] = b1[i % i1 * b1.size(1) + i / i1] *
            ji;
        }

        for (i = 0; i <= m2; i++) {
          b_i = b2.size(0);
          i1 = b2.size(0);
          b2[i % b_i * b2.size(1) + i / b_i] = b2[i % i1 * b2.size(1) + i / i1] *
            ji;
        }
      }
    } else {
      double pivot;
      double t;
      int i;
      boolean_T guard1{ false };

      boolean_T guard2{ false };

      boolean_T guard3{ false };

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
          for (i = 0; i <= m1; i++) {
            t = b1[b1.size(1) * i + 1];
            b1[b1.size(1) * i + 1] = b1[b1.size(1) * i];
            b1[b1.size(1) * i] = t;
          }

          for (i = 0; i <= m2; i++) {
            t = b2[b2.size(1) * i + 1];
            b2[b2.size(1) * i + 1] = b2[b2.size(1) * i];
            b2[b2.size(1) * i] = t;
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
            for (i = 0; i <= m1; i++) {
              t = b1[b1.size(1) * i + 1];
              b1[b1.size(1) * i + 1] = b1[b1.size(1) * i];
              b1[b1.size(1) * i] = t;
            }

            for (i = 0; i <= m2; i++) {
              t = b2[b2.size(1) * i + 1];
              b2[b2.size(1) * i + 1] = b2[b2.size(1) * i];
              b2[b2.size(1) * i] = t;
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
          for (i = 0; i <= m1; i++) {
            t = b1[b1.size(1) * i + 2];
            b1[b1.size(1) * i + 2] = b1[b1.size(1) * i];
            b1[b1.size(1) * i] = t;
          }

          for (i = 0; i <= m2; i++) {
            t = b2[b2.size(1) * i + 2];
            b2[b2.size(1) * i + 2] = b2[b2.size(1) * i];
            b2[b2.size(1) * i] = t;
          }

          guard3 = true;
        }
      }

      if (guard3) {
        J[3] /= pivot;
        J[4] -= J[1] * J[3];
        J[5] -= J[2] * J[3];
        for (i = 0; i <= m1; i++) {
          b1[b1.size(1) * i + 1] = b1[b1.size(1) * i + 1] - J[3] * b1[b1.size(1)
            * i];
        }

        for (i = 0; i <= m2; i++) {
          b2[b2.size(1) * i + 1] = b2[b2.size(1) * i + 1] - J[3] * b2[b2.size(1)
            * i];
        }

        J[6] /= pivot;
        J[7] -= J[1] * J[6];
        J[8] -= J[2] * J[6];
        for (i = 0; i <= m1; i++) {
          b1[b1.size(1) * i + 2] = b1[b1.size(1) * i + 2] - J[6] * b1[b1.size(1)
            * i];
        }

        for (i = 0; i <= m2; i++) {
          b2[b2.size(1) * i + 2] = b2[b2.size(1) * i + 2] - J[6] * b2[b2.size(1)
            * i];
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
          for (i = 0; i <= m1; i++) {
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
          for (i = 0; i <= m1; i++) {
            b1[b1.size(1) * i + 1] = (b1[b1.size(1) * i + 1] - J[3] * b1[b1.size
              (1) * i]) / J[4];
            b1[b1.size(1) * i] = (b1[b1.size(1) * i] - J[1] * b1[b1.size(1) * i
                                  + 1]) / J[0];
          }

          for (i = 0; i <= m2; i++) {
            b2[b2.size(1) * i + 1] = (b2[b2.size(1) * i + 1] - J[3] * b2[b2.size
              (1) * i]) / J[4];
            b2[b2.size(1) * i] = (b2[b2.size(1) * i] - J[1] * b2[b2.size(1) * i
                                  + 1]) / J[0];
          }
        }
      }

      if (guard1) {
        J[7] /= pivot;
        J[8] -= J[5] * J[7];
        if (J[8] == 0.0) {
          info = true;
        } else {
          for (i = 0; i <= m1; i++) {
            b1[b1.size(1) * i + 2] = (b1[b1.size(1) * i + 2] - J[7] * b1[b1.size
              (1) * i + 1]) / J[8];
            b1[b1.size(1) * i + 1] = (b1[b1.size(1) * i + 1] - J[5] * b1[b1.size
              (1) * i + 2]) / J[4];
            b1[b1.size(1) * i] = ((b1[b1.size(1) * i] - J[2] * b1[b1.size(1) * i
              + 2]) - J[1] * b1[b1.size(1) * i + 1]) / J[0];
          }
        }
      }
    }

    return info;
  }

  static inline
  boolean_T solve_sq(double J[9], int n, ::coder::array<double, 2U> &b1)
  {
    int m1;
    boolean_T info;

    // solve_local - Solve local 1x1, 2x2, or 3x3 systems
    m1 = b1.size(0) - 1;
    info = false;
    if (n == 1) {
      if (J[0] == 0.0) {
        info = true;
      } else {
        double ji;
        ji = 1.0 / J[0];
        for (int i{0}; i <= m1; i++) {
          int b_i;
          int i1;
          b_i = b1.size(0);
          i1 = b1.size(0);
          b1[i % b_i * b1.size(1) + i / b_i] = b1[i % i1 * b1.size(1) + i / i1] *
            ji;
        }
      }
    } else {
      double pivot;
      double t;
      int i;
      boolean_T guard1{ false };

      boolean_T guard2{ false };

      boolean_T guard3{ false };

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
          for (i = 0; i <= m1; i++) {
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
            for (i = 0; i <= m1; i++) {
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
          for (i = 0; i <= m1; i++) {
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
        for (i = 0; i <= m1; i++) {
          b1[b1.size(1) * i + 1] = b1[b1.size(1) * i + 1] - J[3] * b1[b1.size(1)
            * i];
        }

        J[6] /= pivot;
        J[7] -= J[1] * J[6];
        J[8] -= J[2] * J[6];
        for (i = 0; i <= m1; i++) {
          b1[b1.size(1) * i + 2] = b1[b1.size(1) * i + 2] - J[6] * b1[b1.size(1)
            * i];
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
          for (i = 0; i <= m1; i++) {
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
          for (i = 0; i <= m1; i++) {
            b1[b1.size(1) * i + 1] = (b1[b1.size(1) * i + 1] - J[3] * b1[b1.size
              (1) * i]) / J[4];
            b1[b1.size(1) * i] = (b1[b1.size(1) * i] - J[1] * b1[b1.size(1) * i
                                  + 1]) / J[0];
          }
        }
      }

      if (guard1) {
        J[7] /= pivot;
        J[8] -= J[5] * J[7];
        if (J[8] == 0.0) {
          info = true;
        } else {
          for (i = 0; i <= m1; i++) {
            b1[b1.size(1) * i + 2] = (b1[b1.size(1) * i + 2] - J[7] * b1[b1.size
              (1) * i + 1]) / J[8];
            b1[b1.size(1) * i + 1] = (b1[b1.size(1) * i + 1] - J[5] * b1[b1.size
              (1) * i + 2]) / J[4];
            b1[b1.size(1) * i] = ((b1[b1.size(1) * i] - J[2] * b1[b1.size(1) * i
              + 2]) - J[1] * b1[b1.size(1) * i + 1]) / J[0];
          }
        }
      }
    }

    return info;
  }

  static inline
  void tabulate_quadratures(int etype, int qd, int *nqp, double ws_data[],
    int *ws_size, double cs_data[], int cs_size[2])
  {
    static const double b_dv1[18]{ 0.112701665379258, 0.112701665379258,
      0.887298334620742, 0.112701665379258, 0.887298334620742, 0.887298334620742,
      0.112701665379258, 0.887298334620742, 0.5, 0.112701665379258,
      0.887298334620742, 0.5, 0.5, 0.887298334620742, 0.112701665379258, 0.5,
      0.5, 0.5 };

    static const double b_dv[8]{ 0.21132486540518711, 0.21132486540518711,
      0.21132486540518711, 0.78867513459481287, 0.78867513459481287,
      0.21132486540518711, 0.78867513459481287, 0.78867513459481287 };

    double b_cs_data[1029];
    double y_data[931];
    double b_data[133];
    double d_cs_data[98];
    double b_tmp_data[49];
    double b_ws_data[49];
    double tmp_data[49];
    double xi_data[49];
    double c_cs_data[7];
    double c_ws_data[7];
    double ps1_data[7];
    double ws1_data[7];
    int b_cs_size[2];
    int b_size_idx_1_tmp;
    int ps1_size;
    int shape;
    int ws1_size;

    // tabulate_quadratures - Tabulate quadrature rules
    shape = etype >> 5 & 7;
    switch (((shape > 0) + (shape > 1)) + (shape > 3)) {
     case 3:
      {
        int k;

        // obtain_nnodes - Obtain number of nodes per element given etype
        fe3_quadrule(iv[etype - 1], qd, ws_data, ws_size, b_cs_data, b_cs_size,
                     nqp);
        cs_size[1] = 3;
        cs_size[0] = b_cs_size[0];
        k = 3 * b_cs_size[0];
        if (0 <= k - 1) {
          std::copy(&b_cs_data[0], &b_cs_data[k], &cs_data[0]);
        }
      }
      break;

     case 2:
      {
        int i;
        int k;
        boolean_T guard1{ false };

        boolean_T guard2{ false };

        // obtain_nnodes - Obtain number of nodes per element given etype
        guard1 = false;
        guard2 = false;
        switch (iv[etype - 1]) {
         case 3:
          guard1 = true;
          break;

         case 6:
          guard1 = true;
          break;

         case 10:
          guard1 = true;
          break;

         case 15:
          guard1 = true;
          break;

         case 21:
          guard1 = true;
          break;

         case 28:
          guard1 = true;
          break;

         case 4:
          guard2 = true;
          break;

         case 8:
          guard2 = true;
          break;

         case 9:
          guard2 = true;
          break;

         case 12:
          guard2 = true;
          break;

         case 16:
          guard2 = true;
          break;

         case 25:
          guard2 = true;
          break;

         case 36:
          guard2 = true;
          break;

         case 49:
          guard2 = true;
          break;
        }

        if (guard2) {
          //  QUAD_4, QUAD_8, QUAD_9, QUAD_12, QUAD_16, QUAD_25
          i = iv[etype - 1];
          if ((i <= 4) && (qd <= 1)) {
            *nqp = 1;
            *ws_size = 1;
            b_ws_data[0] = 1.0;
            b_size_idx_1_tmp = 1;
            d_cs_data[0] = 0.5;
            d_cs_data[1] = 0.5;
          } else if ((i <= 9) && (qd <= 3)) {
            *nqp = 4;
            *ws_size = 4;
            b_ws_data[0] = 0.25;
            b_ws_data[1] = 0.25;
            b_ws_data[2] = 0.25;
            b_ws_data[3] = 0.25;
            b_size_idx_1_tmp = 4;
            std::copy(&b_dv[0], &b_dv[8], &d_cs_data[0]);
          } else if ((i <= 16) && (qd <= 5)) {
            //  cubic
            *nqp = 9;
            *ws_size = 9;
            b_ws_data[0] = 0.07716049382716049;
            b_ws_data[4] = 0.12345679012345678;
            b_ws_data[1] = 0.07716049382716049;
            b_ws_data[5] = 0.12345679012345678;
            b_ws_data[2] = 0.07716049382716049;
            b_ws_data[6] = 0.12345679012345678;
            b_ws_data[3] = 0.07716049382716049;
            b_ws_data[7] = 0.12345679012345678;
            b_ws_data[8] = 0.19753086419753085;
            b_size_idx_1_tmp = 9;
            std::copy(&b_dv1[0], &b_dv1[18], &d_cs_data[0]);
          } else {
            int i1;
            int t;
            signed char xi_idx_0;

            //  quartic or higher degree
            fe1_quadrule(qd, ws1_data, &ws1_size, ps1_data, &ps1_size);
            b_size_idx_1_tmp = static_cast<signed char>(ps1_size);
            for (k = 0; k < ps1_size; k++) {
              i = static_cast<signed char>(ps1_size) - 1;
              for (t = 0; t <= i; t++) {
                b_data[t + static_cast<signed char>(ps1_size) * k] = ps1_data[k];
              }
            }

            for (i = 0; i < b_size_idx_1_tmp; i++) {
              for (i1 = 0; i1 < b_size_idx_1_tmp; i1++) {
                xi_data[i1 + static_cast<signed char>(ps1_size) * i] = b_data[i
                  + static_cast<signed char>(ps1_size) * i1];
              }
            }

            xi_idx_0 = static_cast<signed char>(static_cast<signed char>
              (ps1_size) * static_cast<signed char>(ps1_size));
            i = 0;
            i1 = 0;
            b_size_idx_1_tmp = xi_idx_0;
            for (t = 0; t < xi_idx_0; t++) {
              tmp_data[t] = xi_data[i1 + static_cast<signed char>(ps1_size) * i];
              i++;
              if (i > static_cast<signed char>(ps1_size) - 1) {
                i = 0;
                i1++;
              }
            }

            xi_idx_0 = static_cast<signed char>(static_cast<signed char>
              (ps1_size) * static_cast<signed char>(ps1_size));
            i = 0;
            i1 = 0;
            k = xi_idx_0;
            for (t = 0; t < xi_idx_0; t++) {
              b_tmp_data[t] = b_data[i1 + static_cast<signed char>(ps1_size) * i];
              i++;
              if (i > static_cast<signed char>(ps1_size) - 1) {
                i = 0;
                i1++;
              }
            }

            for (i = 0; i < b_size_idx_1_tmp; i++) {
              d_cs_data[2 * i] = tmp_data[i];
            }

            for (i = 0; i < k; i++) {
              d_cs_data[2 * i + 1] = b_tmp_data[i];
            }

            for (i = 0; i < ws1_size; i++) {
              for (i1 = 0; i1 < ws1_size; i1++) {
                y_data[i1 + ws1_size * i] = ws1_data[i1] * ws1_data[i];
              }
            }

            xi_idx_0 = static_cast<signed char>(static_cast<signed char>
              (ws1_size) * static_cast<signed char>(ws1_size));
            i = 0;
            i1 = 0;
            *ws_size = xi_idx_0;
            for (t = 0; t < xi_idx_0; t++) {
              b_ws_data[t] = y_data[i1 + ws1_size * i];
              i++;
              if (i > ws1_size - 1) {
                i = 0;
                i1++;
              }
            }

            *nqp = xi_idx_0;
          }
        }

        if (guard1) {
          //  TRI_3, TRI_6, TRI_10, or TRI_15
          i = iv[etype - 1];
          if ((i <= 3) && (qd <= 1)) {
            *nqp = 1;
            *ws_size = 1;
            b_ws_data[0] = 0.5;
            b_size_idx_1_tmp = 1;
            d_cs_data[0] = 0.33333333333333331;
            d_cs_data[1] = 0.33333333333333331;
          } else if ((i <= 6) && (qd <= 2)) {
            *nqp = 3;
            *ws_size = 3;
            b_ws_data[0] = 0.16666666666666666;
            b_ws_data[1] = 0.16666666666666666;
            b_ws_data[2] = 0.16666666666666666;
            b_size_idx_1_tmp = 3;
            for (i = 0; i < 6; i++) {
              d_cs_data[i] = dv[i];
            }
          } else if ((i <= 10) && (qd <= 4)) {
            *nqp = 6;
            *ws_size = 6;
            for (i = 0; i < 6; i++) {
              b_ws_data[i] = dv1[i];
            }

            b_size_idx_1_tmp = 6;
            std::copy(&dv2[0], &dv2[12], &d_cs_data[0]);
          } else if ((i <= 15) && (qd <= 5)) {
            *nqp = 7;
            b_size_idx_1_tmp = 7;
            std::copy(&dv3[0], &dv3[14], &d_cs_data[0]);
            *ws_size = 7;
            for (i = 0; i < 7; i++) {
              b_ws_data[i] = dv4[i];
            }
          } else if ((i <= 21) && (qd <= 6)) {
            //  degree 6
            *nqp = 12;
            b_size_idx_1_tmp = 12;
            std::copy(&dv5[0], &dv5[24], &d_cs_data[0]);
            *ws_size = 12;
            std::copy(&dv6[0], &dv6[12], &b_ws_data[0]);
          } else if ((i <= 28) && (qd <= 7)) {
            *nqp = 12;
            b_size_idx_1_tmp = 12;
            std::copy(&dv7[0], &dv7[24], &d_cs_data[0]);
            *ws_size = 12;
            std::copy(&dv8[0], &dv8[12], &b_ws_data[0]);
          } else if ((i <= 28) && (qd <= 8)) {
            *nqp = 16;
            b_size_idx_1_tmp = 16;
            std::copy(&dv9[0], &dv9[32], &d_cs_data[0]);
            *ws_size = 16;
            std::copy(&dv10[0], &dv10[16], &b_ws_data[0]);
          } else {
            *nqp = 19;
            b_size_idx_1_tmp = 19;
            std::copy(&dv11[0], &dv11[38], &d_cs_data[0]);
            *ws_size = 19;
            std::copy(&dv12[0], &dv12[19], &b_ws_data[0]);
          }
        }

        if (0 <= *ws_size - 1) {
          std::copy(&b_ws_data[0], &b_ws_data[*ws_size], &ws_data[0]);
        }

        cs_size[1] = 2;
        cs_size[0] = b_size_idx_1_tmp;
        k = 2 * b_size_idx_1_tmp;
        if (0 <= k - 1) {
          std::copy(&d_cs_data[0], &d_cs_data[k], &cs_data[0]);
        }
      }
      break;

     default:
      {
        int i;
        int k;

        // obtain_nnodes - Obtain number of nodes per element given etype
        i = iv[etype - 1];
        if ((i <= 2) && (qd <= 1)) {
          *nqp = 1;
          k = 1;
          c_cs_data[0] = 0.5;
          *ws_size = 1;
          c_ws_data[0] = 1.0;
        } else if ((i <= 3) && (qd <= 3)) {
          *nqp = 2;
          k = 2;
          *ws_size = 2;
          c_cs_data[0] = 0.211324865405187;
          c_ws_data[0] = 0.5;
          c_cs_data[1] = 0.788675134594813;
          c_ws_data[1] = 0.5;
        } else if ((i <= 4) && (qd <= 5)) {
          *nqp = 3;
          k = 3;
          *ws_size = 3;
          c_cs_data[0] = 0.112701665379258;
          c_ws_data[0] = 0.27777777777777779;
          c_cs_data[1] = 0.5;
          c_ws_data[1] = 0.44444444444444442;
          c_cs_data[2] = 0.887298334620742;
          c_ws_data[2] = 0.27777777777777779;
        } else if ((i <= 5) && (qd <= 7)) {
          *nqp = 4;
          k = 4;
          *ws_size = 4;
          c_cs_data[0] = 0.069431844202974;
          c_ws_data[0] = 0.173927422568727;
          c_cs_data[1] = 0.330009478207572;
          c_ws_data[1] = 0.326072577431273;
          c_cs_data[2] = 0.669990521792428;
          c_ws_data[2] = 0.326072577431273;
          c_cs_data[3] = 0.930568155797026;
          c_ws_data[3] = 0.173927422568727;
        } else if ((i <= 6) && (qd <= 8)) {
          *nqp = 5;
          k = 5;
          *ws_size = 5;
          for (i = 0; i < 5; i++) {
            c_cs_data[i] = dv13[i];
            c_ws_data[i] = dv14[i];
          }
        } else if ((i <= 7) && (qd <= 9)) {
          *nqp = 6;
          k = 6;
          *ws_size = 6;
          for (i = 0; i < 6; i++) {
            c_cs_data[i] = dv15[i];
            c_ws_data[i] = dv16[i];
          }
        } else {
          *nqp = 7;
          k = 7;
          *ws_size = 7;
          for (i = 0; i < 7; i++) {
            c_cs_data[i] = dv17[i];
            c_ws_data[i] = dv18[i];
          }
        }

        if (0 <= *ws_size - 1) {
          std::copy(&c_ws_data[0], &c_ws_data[*ws_size], &ws_data[0]);
        }

        cs_size[1] = 1;
        cs_size[0] = k;
        if (0 <= k - 1) {
          std::copy(&c_cs_data[0], &c_cs_data[k], &cs_data[0]);
        }
      }
      break;
    }
  }

  static inline
  void tabulate_shapefuncs(int etype, const double cs_data[], const int
    cs_size[2], ::coder::array<double, 2U> &shapes, ::coder::array<double, 3U>
    &derivs)
  {
    int shape;

    // tabulate_shapefuncs - kerneo for tabulating shape functions
    shape = etype >> 5 & 7;
    switch (((shape > 0) + (shape > 1)) + (shape > 3)) {
     case 3:
      sfe3_tabulate_shapefuncs(etype, cs_data, cs_size, shapes, derivs);
      break;

     case 2:
      sfe2_tabulate_shapefuncs(etype, cs_data, cs_size, shapes, derivs);
      break;

     default:
      sfe1_tabulate_shapefuncs(etype, cs_data, cs_size, shapes, derivs);
      break;
    }
  }

  static inline
  void tet_10(double xi, double eta, double zeta, double shape_funcs[10],
                     double deriv[30])
  {
    double b_dv[30];
    double shape_funcs_tmp;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t18;
    double t2;
    double t3;
    double t4;
    double t5;
    double t6;
    double t7;
    double t8;
    int i;
    int i1;

    // TET_10    Quadratic tetrahedral element with equidistant nodes
    t2 = eta * 4.0;
    t3 = eta * eta;
    t4 = 4.0 * xi;
    t5 = xi * xi;
    t6 = zeta * 4.0;
    t7 = zeta * zeta;
    t15 = eta * zeta * -4.0;
    t8 = t2 * zeta;
    t12 = t3 * 2.0;
    t13 = t5 * 2.0;
    t14 = t7 * 2.0;
    t16 = (t2 + t6) - 3.0;
    shape_funcs[0] = ((((((eta * -3.0 + t8) + t12) + t13) + t14) - zeta * 3.0) +
                      t16 * xi) + 1.0;
    shape_funcs[1] = t13 + -xi;
    shape_funcs[2] = -eta + t12;
    shape_funcs[3] = t14 - zeta;
    shape_funcs[4] = t5 * -4.0 - xi * (t16 - 1.0);
    shape_funcs_tmp = t2 * xi;
    shape_funcs[5] = shape_funcs_tmp;
    shape_funcs[6] = ((t2 - t3 * 4.0) + t15) - shape_funcs_tmp;
    shape_funcs_tmp = t6 * xi;
    shape_funcs[7] = ((t6 - t7 * 4.0) + t15) - shape_funcs_tmp;
    shape_funcs[8] = shape_funcs_tmp;
    shape_funcs[9] = t8;
    t18 = t4 + t16;
    b_dv[0] = t18;
    b_dv[1] = t4 - 1.0;
    b_dv[2] = 0.0;
    b_dv[3] = 0.0;
    b_dv[4] = ((-t2 - t6) + 4.0) + -8.0 * xi;
    b_dv[5] = t2;
    b_dv[6] = -t2;
    b_dv[7] = -t6;
    b_dv[8] = t6;
    b_dv[9] = 0.0;
    b_dv[10] = t18;
    b_dv[11] = 0.0;
    b_dv[12] = t2 - 1.0;
    b_dv[13] = 0.0;
    b_dv[14] = -t4;
    b_dv[15] = t4;
    b_dv[16] = ((eta * -8.0 - t4) - t6) + 4.0;
    b_dv[17] = -t6;
    b_dv[18] = 0.0;
    b_dv[19] = t6;
    b_dv[20] = t18;
    b_dv[21] = 0.0;
    b_dv[22] = 0.0;
    b_dv[23] = t6 - 1.0;
    b_dv[24] = -t4;
    b_dv[25] = 0.0;
    b_dv[26] = -t2;
    b_dv[27] = ((-t2 - t4) - zeta * 8.0) + 4.0;
    b_dv[28] = t4;
    b_dv[29] = t2;
    i = 0;
    i1 = 0;
    for (int i2{0}; i2 < 30; i2++) {
      deriv[i1 + 3 * i] = b_dv[i2];
      i++;
      if (i > 9) {
        i = 0;
        i1++;
      }
    }
  }

  static inline
  void tet_20(double xi, double eta, double zeta, double shape_funcs[20],
                     double deriv[60])
  {
    double b_dv[60];
    double t10;
    double t11;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t2;
    double t22;
    double t23;
    double t24;
    double t25;
    double t25_tmp;
    double t26;
    double t27;
    double t28;
    double t29;
    double t3;
    double t30;
    double t31;
    double t32;
    double t33;
    double t34;
    double t35;
    double t39;
    double t4;
    double t41;
    double t44;
    double t5;
    double t52;
    double t53;
    double t54;
    double t55;
    double t56;
    double t57;
    double t58;
    double t59;
    double t6;
    double t60;
    double t61;
    double t62;
    double t64;
    double t66;
    double t68;
    double t69;
    double t7;
    double t70;
    double t71;
    double t72;
    double t72_tmp;
    double t73;
    double t73_tmp;
    double t74;
    double t76_tmp;
    double t78;
    double t79;
    double t8;
    double t80;
    double t81;
    double t82;
    double t83;
    double t87;
    double t88;
    double t89;
    double t9;
    double t90;
    double t91;
    double t92;
    double t94;
    double t95;
    int i;
    int i1;

    // TET_20    Cubic tetrahedral element with equidistant nodes
    t2 = eta * eta;
    t3 = std::pow(eta, 3.0);
    t4 = xi * xi;
    t5 = std::pow(xi, 3.0);
    t6 = zeta * zeta;
    t7 = std::pow(zeta, 3.0);
    t8 = eta * 9.0;
    t9 = eta * 18.0;
    t10 = eta * 27.0;
    t11 = eta * 54.0;
    t12 = zeta * 9.0;
    t13 = zeta * 18.0;
    t14 = zeta * 27.0;
    t15 = zeta * 54.0;
    t25_tmp = eta * zeta;
    t25 = t25_tmp * -27.0;
    t26 = t25_tmp * -54.0;
    t29 = eta * 4.5;
    t30 = eta * 13.5;
    t31 = eta * 22.5;
    t32 = 4.5 * xi;
    t33 = zeta * 4.5;
    t34 = zeta * 13.5;
    t35 = zeta * 22.5;
    t61 = t25_tmp * -4.5;
    t62 = t25_tmp * -22.5;
    t16 = t10 * zeta;
    t17 = t11 * zeta;
    t22 = t2 * 27.0;
    t23 = t4 * 27.0;
    t24 = t6 * 27.0;
    t27 = t10 * xi;
    t28 = t14 * xi;
    t39 = t29 * zeta;
    t52 = t3 * 4.5;
    t53 = t2 * 13.5;
    t54 = t3 * 13.5;
    t55 = t5 * 4.5;
    t56 = t4 * 13.5;
    t57 = t5 * 13.5;
    t58 = t7 * 4.5;
    t59 = t6 * 13.5;
    t60 = t7 * 13.5;
    t64 = t2 * 40.5;
    t66 = t4 * 40.5;
    t68 = t6 * 40.5;
    t69 = t6 * t30;
    t70 = t2 * t34;
    t71 = t4 * t34;
    t72_tmp = eta * t6;
    t72 = t72_tmp * -13.5;
    t73_tmp = t2 * zeta;
    t73 = t73_tmp * -13.5;
    t74 = t4 * t30;
    t76_tmp = t10 + t14;
    t87 = (t29 + t33) - 4.5;
    t41 = -t10 * xi;
    t44 = -t14 * xi;
    t78 = -t29 + t53;
    t81 = -t32 + t56;
    t82 = -t33 + t59;
    t88 = (t16 + t22) - t31;
    t89 = (t16 + t24) - t35;
    t94 = ((((t16 - t31) - t35) + t53) + t59) + 9.0;
    t25_tmp = t30 + t34;
    shape_funcs[0] = (((((((((((eta * -5.5 + t2 * 9.0) + t6 * 9.0) - t52) - t55)
      - t58) + t72) + t73) - zeta * 5.5) - t4 * (t25_tmp - 9.0)) - xi * (((((-t9
      - t13) + t16) + t53) + t59) + 5.5)) + t9 * zeta) + 1.0;
    shape_funcs[1] = (t4 * -4.5 + t55) + xi;
    shape_funcs[2] = (eta - t2 * 4.5) + t52;
    shape_funcs[3] = (t6 * -4.5 + t58) + zeta;
    shape_funcs[4] = (t57 + t4 * (t76_tmp - 22.5)) + t94 * xi;
    shape_funcs[5] = (-t57 - t4 * (t25_tmp - 18.0)) + t87 * xi;
    shape_funcs[6] = t74 - t29 * xi;
    t25_tmp = t78 * xi;
    shape_funcs[7] = t25_tmp;
    shape_funcs[8] = ((((t2 * 18.0 + t39) - t29) - t54) + t73) - t25_tmp;
    shape_funcs[9] = ((((((t2 * -22.5 + t8) + t2 * t14) + t54) + t62) + t69) +
                      t74) + t88 * xi;
    shape_funcs[10] = ((((((t6 * -22.5 + t12) + t6 * t10) + t60) + t62) + t70) +
                       t71) + t89 * xi;
    t25_tmp = t82 * xi;
    shape_funcs[11] = ((((t6 * 18.0 + t39) - t33) - t60) + t72) - t25_tmp;
    shape_funcs[12] = t71 - t33 * xi;
    shape_funcs[13] = t25_tmp;
    shape_funcs[14] = t61 + t70;
    shape_funcs[15] = t61 + t69;
    shape_funcs[16] = eta * t4 * -27.0 - xi * ((t16 - t10) + t22);
    shape_funcs[17] = t4 * zeta * -27.0 - xi * ((t16 - t14) + t24);
    shape_funcs[18] = t16 * xi;
    shape_funcs[19] = ((t16 - t72_tmp * 27.0) + t25 * xi) - t73_tmp * 27.0;
    t79 = t29 - t53;
    t80 = t32 - t56;
    t83 = t33 - t59;
    t90 = t23 + (t76_tmp - 22.5) * xi;
    t91 = t27 + t88;
    t92 = t28 + t89;
    t95 = (-t56 + -xi * (t76_tmp - 18.0)) + (((((t9 + t13) + t25) - t53) - t59)
      - 5.5);
    b_dv[0] = t95;
    b_dv[1] = (t56 + -9.0 * xi) + 1.0;
    b_dv[2] = 0.0;
    b_dv[3] = 0.0;
    b_dv[4] = (t66 + t94) + xi * ((t11 + t15) - 45.0);
    b_dv[5] = (-t66 + t87) - xi * (t76_tmp - 36.0);
    b_dv[6] = t27 - t29;
    b_dv[7] = t78;
    b_dv[8] = t79;
    b_dv[9] = t91;
    b_dv[10] = t92;
    b_dv[11] = t83;
    b_dv[12] = t28 - t33;
    b_dv[13] = t82;
    b_dv[14] = 0.0;
    b_dv[15] = 0.0;
    b_dv[16] = ((t10 + t25) - t22) - t11 * xi;
    b_dv[17] = ((t14 + t25) - t24) - t15 * xi;
    b_dv[18] = t16;
    b_dv[19] = t25;
    b_dv[20] = t95;
    b_dv[21] = 0.0;
    b_dv[22] = (-t8 + t53) + 1.0;
    b_dv[23] = 0.0;
    b_dv[24] = t90;
    b_dv[25] = t80;
    b_dv[26] = t81;
    t72_tmp = xi * (t10 - 4.5);
    b_dv[27] = t72_tmp;
    b_dv[28] = ((((eta * 36.0 + t25) + t33) - t64) - t72_tmp) - 4.5;
    t72_tmp = t11 + t14;
    b_dv[29] = ((((((eta * -45.0 + t17) - t35) + t56) + t59) + t64) + xi *
                (t72_tmp - 22.5)) + 9.0;
    b_dv[30] = t92;
    b_dv[31] = t83;
    b_dv[32] = 0.0;
    b_dv[33] = 0.0;
    b_dv[34] = t16 - t33;
    b_dv[35] = t82;
    b_dv[36] = -t23 - xi * (t72_tmp - 27.0);
    b_dv[37] = t44;
    b_dv[38] = t28;
    b_dv[39] = ((t14 + t26) - t24) + t44;
    b_dv[40] = t95;
    b_dv[41] = 0.0;
    b_dv[42] = 0.0;
    b_dv[43] = (-t12 + t59) + 1.0;
    b_dv[44] = t90;
    b_dv[45] = t80;
    b_dv[46] = 0.0;
    b_dv[47] = 0.0;
    b_dv[48] = t79;
    b_dv[49] = t91;
    t72_tmp = t10 + t15;
    b_dv[50] = ((((((t17 - t31) + t53) + t56) + t68) - zeta * 45.0) + xi *
                (t72_tmp - 22.5)) + 9.0;
    t25_tmp = xi * (t14 - 4.5);
    b_dv[51] = ((((t25 + t29) - t68) + zeta * 36.0) - t25_tmp) - 4.5;
    b_dv[52] = t81;
    b_dv[53] = t25_tmp;
    b_dv[54] = t78;
    b_dv[55] = t16 - t29;
    b_dv[56] = t41;
    b_dv[57] = -t23 - xi * (t72_tmp - 27.0);
    b_dv[58] = t27;
    b_dv[59] = ((t10 + t26) - t22) + t41;
    i = 0;
    i1 = 0;
    for (int i2{0}; i2 < 60; i2++) {
      deriv[i1 + 3 * i] = b_dv[i2];
      i++;
      if (i > 19) {
        i = 0;
        i1++;
      }
    }
  }

  static inline
  void tet_35(double xi, double eta, double zeta, double shape_funcs[35],
                     double deriv[105])
  {
    double b_dv[105];
    double b_shape_funcs_tmp;
    double shape_funcs_tmp;
    double t10;
    double t101;
    double t102;
    double t103;
    double t105;
    double t106;
    double t107;
    double t108;
    double t109;
    double t11;
    double t110;
    double t113;
    double t114;
    double t115;
    double t116;
    double t117;
    double t12;
    double t120;
    double t121;
    double t123;
    double t124;
    double t125;
    double t128;
    double t13;
    double t130;
    double t131;
    double t132;
    double t14;
    double t140;
    double t142;
    double t15;
    double t150;
    double t153;
    double t153_tmp;
    double t154;
    double t154_tmp;
    double t155;
    double t156;
    double t157;
    double t158;
    double t159;
    double t16;
    double t160;
    double t161;
    double t162;
    double t167;
    double t169;
    double t17;
    double t170;
    double t171;
    double t172;
    double t174;
    double t175;
    double t176;
    double t177;
    double t178;
    double t179;
    double t179_tmp;
    double t18;
    double t180;
    double t180_tmp;
    double t181;
    double t182;
    double t183;
    double t184;
    double t185;
    double t186;
    double t186_tmp;
    double t189;
    double t19;
    double t192;
    double t195;
    double t196;
    double t197;
    double t198;
    double t199;
    double t199_tmp;
    double t2;
    double t20;
    double t200;
    double t205;
    double t206;
    double t207;
    double t208;
    double t209;
    double t211;
    double t213;
    double t214;
    double t216;
    double t219;
    double t221;
    double t222;
    double t223;
    double t224;
    double t225;
    double t228;
    double t23;
    double t231;
    double t232;
    double t233;
    double t234;
    double t239;
    double t24;
    double t240;
    double t244;
    double t246;
    double t247;
    double t248;
    double t249;
    double t25;
    double t250;
    double t251;
    double t254;
    double t255;
    double t26;
    double t262;
    double t263;
    double t263_tmp;
    double t264;
    double t264_tmp;
    double t267;
    double t268;
    double t269;
    double t27;
    double t270;
    double t272;
    double t273;
    double t274;
    double t28;
    double t29;
    double t3;
    double t30;
    double t31;
    double t32;
    double t33;
    double t36;
    double t37;
    double t38;
    double t39;
    double t4;
    double t40;
    double t41;
    double t42;
    double t43;
    double t44;
    double t45;
    double t46;
    double t47;
    double t48;
    double t49;
    double t5;
    double t50;
    double t51;
    double t52;
    double t52_tmp;
    double t53;
    double t54;
    double t56;
    double t58;
    double t6;
    double t60;
    double t61;
    double t63;
    double t7;
    double t72;
    double t73;
    double t8;
    double t84;
    double t86;
    double t87;
    double t88;
    double t90;
    double t91;
    double t92;
    double t93;
    double t94;
    double t96;
    double t99;
    int i;
    int i1;

    // TET_35    Quartic tetrahedral element with equidistant nodes
    t2 = eta * 4.0;
    t3 = eta * eta;
    t4 = std::pow(eta, 3.0);
    t6 = xi * xi;
    t7 = std::pow(xi, 3.0);
    t10 = zeta * zeta;
    t11 = std::pow(zeta, 3.0);
    t13 = eta * 16.0;
    t14 = eta * 28.0;
    t15 = eta * 32.0;
    t16 = zeta * 16.0;
    t17 = zeta * 28.0;
    t18 = zeta * 32.0;
    t23 = eta * 64.0;
    t24 = eta * 96.0;
    t25 = eta * 128.0;
    t26 = eta * 160.0;
    t27 = eta * 192.0;
    t28 = eta * 224.0;
    t29 = eta * 256.0;
    t30 = eta * 288.0;
    t31 = eta * 320.0;
    t32 = eta * 384.0;
    t33 = eta * 448.0;
    t36 = zeta * 64.0;
    t37 = zeta * 96.0;
    t38 = zeta * 128.0;
    t39 = zeta * 160.0;
    t40 = zeta * 192.0;
    t41 = zeta * 224.0;
    t42 = zeta * 256.0;
    t43 = zeta * 288.0;
    t44 = zeta * 320.0;
    t45 = zeta * 384.0;
    t46 = zeta * 448.0;
    t52_tmp = eta * zeta;
    t52 = t52_tmp * -32.0;
    t63 = eta * 5.333333333333333;
    t72 = 5.333333333333333 * xi;
    t73 = zeta * 5.333333333333333;
    t113 = t52_tmp * -224.0;
    t114 = t52_tmp * -256.0;
    t115 = t52_tmp * -288.0;
    t116 = t52_tmp * -448.0;
    t117 = t52_tmp * 512.0;
    t123 = eta * 42.666666666666664;
    t124 = eta * 46.666666666666664;
    t125 = eta * 69.333333333333329;
    t128 = zeta * 42.666666666666664;
    t130 = zeta * 69.333333333333329;
    t150 = t52_tmp * -5.333333333333333;
    t176 = t52_tmp * -69.333333333333329;
    t5 = t3 * t3;
    t8 = t6 * t6;
    t12 = t10 * t10;
    t19 = t14 * zeta;
    t20 = t15 * zeta;
    t47 = t3 * 16.0;
    t48 = t3 * 32.0;
    t49 = t6 * 32.0;
    t50 = t10 * 16.0;
    t51 = t10 * 32.0;
    t53 = t23 * zeta;
    t54 = t25 * zeta;
    t56 = t27 * zeta;
    t58 = t29 * zeta;
    t60 = t31 * zeta;
    t61 = t32 * zeta;
    t84 = t3 * 64.0;
    t86 = t3 * 96.0;
    t87 = t3 * 128.0;
    t88 = t4 * 128.0;
    t90 = t3 * 160.0;
    t91 = t3 * 192.0;
    t92 = t3 * 224.0;
    t93 = t3 * 256.0;
    t94 = t3 * 384.0;
    t96 = t7 * 128.0;
    t99 = t10 * 64.0;
    t101 = t10 * 96.0;
    t102 = t10 * 128.0;
    t103 = t11 * 128.0;
    t105 = t10 * 160.0;
    t106 = t10 * 192.0;
    t107 = t10 * 224.0;
    t108 = t10 * 256.0;
    t109 = t10 * 384.0;
    t110 = t63 * zeta;
    t120 = t10 * t15;
    t121 = t3 * t18;
    t153_tmp = eta * t10;
    t153 = t153_tmp * -16.0;
    t154_tmp = t3 * zeta;
    t154 = t154_tmp * -16.0;
    t155 = t10 * t25;
    t156 = t3 * t38;
    t157 = t11 * t25;
    t158 = t4 * t38;
    t159 = t10 * t29;
    t160 = t3 * t42;
    t161 = t10 * t32;
    t162 = t3 * t45;
    t167 = t6 * t38;
    t169 = t4 * 42.666666666666664;
    t171 = t7 * 42.666666666666664;
    t174 = t11 * 42.666666666666664;
    t177 = t153_tmp * -128.0;
    t178 = t154_tmp * -128.0;
    t179_tmp = eta * t11;
    t179 = t179_tmp * -128.0;
    t180_tmp = t4 * zeta;
    t180 = t180_tmp * -128.0;
    t181 = t153_tmp * -256.0;
    t182 = t154_tmp * -256.0;
    t183 = t153_tmp * -384.0;
    t184 = t154_tmp * -384.0;
    t185 = t6 * t25;
    t186_tmp = t6 * zeta;
    t186 = t186_tmp * -128.0;
    t189 = t4 * 170.66666666666666;
    t192 = t7 * 170.66666666666666;
    t195 = t11 * 170.66666666666666;
    t197 = t11 * t123;
    t198 = t4 * t128;
    t199_tmp = eta * t6;
    t199 = t199_tmp * -128.0;
    t207 = t179_tmp * -42.666666666666664;
    t208 = t180_tmp * -42.666666666666664;
    t209 = t3 * t10 * -128.0;
    t131 = t58 * xi;
    t132 = t5 * 10.666666666666666;
    t140 = t8 * 10.666666666666666;
    t142 = t12 * 10.666666666666666;
    t170 = t5 * 42.666666666666664;
    t172 = t8 * 42.666666666666664;
    t175 = t12 * 42.666666666666664;
    t196 = t6 * t54;
    t200 = t10 * t84;
    t211 = -t15 + t87;
    t213 = t6 * (t25 - 16.0);
    t214 = t6 * (t38 - 16.0);
    t216 = -t18 + t102;
    t221 = t20 + t177;
    t222 = t20 + t178;
    t223 = t52 + t155;
    t224 = t52 + t156;
    t228 = ((t25 - 16.0) + (t38 - 16.0)) - 48.0;
    t232 = (t20 - t15) + t48;
    t234 = (t20 - t18) + t51;
    t239 = (t58 - t28) + t93;
    t240 = (t58 - t41) + t108;
    t251 = (t113 + t159) + t160;
    t205 = t2 - t47;
    t206 = zeta * 4.0 - t50;
    t219 = t211 * xi;
    t225 = t216 * xi;
    t231 = t6 * (-t13 + t84);
    t233 = t6 * (-t16 + t99);
    t244 = (t63 - t48) + t169;
    t246 = (t72 - t49) + t171;
    t247 = (t73 - t51) + t174;
    t248 = (t48 - t63) - t169;
    t249 = (t49 - t72) - t171;
    t250 = (t51 - t73) - t174;
    t254 = ((t14 + t88) - t3 * 144.0) + t224;
    t255 = ((t17 + t103) - t10 * 144.0) + t223;
    t263_tmp = t37 + t103;
    t263 = (((t263_tmp + t113) - t107) + t156) + t159;
    t264_tmp = t24 + t88;
    t264 = (((t264_tmp + t113) - t92) + t155) + t160;
    t179_tmp = ((((-t27 - t40) + t58) + t87) + t102) + 69.333333333333329;
    t269 = (-t96 + -t6 * ((t29 + t42) - 192.0)) + -xi * t179_tmp;
    t270 = ((((((((t52_tmp * -160.0 + t124) + zeta * 46.666666666666664) - t3 *
                 80.0) - t10 * 80.0) + t155) + t156) + t169) + t174) -
      8.3333333333333339;
    shape_funcs_tmp = t123 + t128;
    shape_funcs[0] = (((((((((((((((((eta * -8.3333333333333339 + t3 *
      23.333333333333332) - t4 * 26.666666666666668) + t10 * 23.333333333333332)
      - t11 * 26.666666666666668) + t132) + t140) + t142) + t197) + t198) + t200)
      - zeta * 8.3333333333333339) + t7 * (shape_funcs_tmp - 26.666666666666668))
                          + t6 * (((((eta * -80.0 + t54) + t84) + t99) - zeta *
      80.0) + 23.333333333333332)) - t153_tmp * 80.0) + t270 * xi) - t154_tmp *
                       80.0) + t124 * zeta) + 1.0;
    shape_funcs[1] = ((t6 * 7.333333333333333 - t7 * 16.0) + t140) + -xi;
    shape_funcs[2] = ((-eta + t3 * 7.333333333333333) - t4 * 16.0) + t132;
    shape_funcs[3] = ((t10 * 7.333333333333333 - t11 * 16.0) + t142) - zeta;
    t180_tmp = t52_tmp * 192.0;
    shape_funcs[4] = ((-t172 - t6 * t179_tmp) - t7 * (t228 - 16.0)) - xi *
      (((((((((-t86 - t101) + t125) + t130) + t155) + t156) + t169) + t174) -
        t180_tmp) - 16.0);
    shape_funcs[5] = ((t8 * 64.0 + t6 * (((((eta * -144.0 + t54) + t84) + t99) -
      zeta * 144.0) + 76.0)) - xi * (((((-t14 - t17) + t20) + t47) + t50) + 12.0))
      + t7 * (t228 - 48.0);
    b_shape_funcs_tmp = t15 + t18;
    shape_funcs[6] = ((-t172 + t6 * (b_shape_funcs_tmp - 37.333333333333336)) -
                      t7 * (shape_funcs_tmp - 74.666666666666671)) - xi * ((t63
      + t73) - 5.333333333333333);
    shape_funcs[7] = (t199_tmp * -32.0 + t7 * t123) + t63 * xi;
    shape_funcs[8] = t231 + t205 * xi;
    shape_funcs_tmp = t244 * xi;
    shape_funcs[9] = shape_funcs_tmp;
    shape_funcs[10] = ((((((t3 * -37.333333333333336 + t4 * 74.666666666666671)
      + t63) + t121) + t150) - t170) + t208) - shape_funcs_tmp;
    shape_funcs[11] = (((((((((eta * -12.0 + t3 * 76.0) + t5 * 64.0) + t19) -
      t88) + t153) + t158) + t200) + t231) + t254 * xi) - t154_tmp * 144.0;
    shape_funcs_tmp = eta * t7;
    shape_funcs[12] = (((((((((((t3 * -69.333333333333329 + t4 * 96.0) + t13) +
      t176) + t180) - t170) + t207) + t209) - xi * (((((t88 - t91) + t125) +
      t155) + t160) - t180_tmp)) - shape_funcs_tmp * 42.666666666666664) + t10 *
                        t24) + t3 * t40) - t6 * ((-t24 + t54) + t87);
    t179_tmp = t7 * zeta;
    shape_funcs[13] = (((((((((((t10 * -69.333333333333329 + t11 * 96.0) + t16)
      + t176) + t179) - t175) + t208) + t209) - xi * (((((t103 - t106) + t130) +
      t156) + t159) - t180_tmp)) + t10 * t27) + t3 * t37) - t179_tmp *
                       42.666666666666664) - t6 * ((-t37 + t54) + t102);
    shape_funcs[14] = (((((((((t10 * 76.0 + t12 * 64.0) + t19) - t103) + t154) +
      t157) + t200) + t233) - zeta * 12.0) - t153_tmp * 144.0) + t255 * xi;
    t180_tmp = t247 * xi;
    shape_funcs[15] = ((((((t10 * -37.333333333333336 + t11 * 74.666666666666671)
      + t73) + t120) + t150) - t175) + t207) - t180_tmp;
    shape_funcs[16] = (t7 * t128 + t73 * xi) - t186_tmp * 32.0;
    shape_funcs[17] = t233 + t206 * xi;
    shape_funcs[18] = t180_tmp;
    shape_funcs[19] = (t110 + t198) - t154_tmp * 32.0;
    shape_funcs[20] = ((t153 + t154) + t200) + t2 * zeta;
    shape_funcs[21] = (t110 + t197) - t153_tmp * 32.0;
    shape_funcs[22] = (t7 * t25 + t6 * t239) + t264 * xi;
    shape_funcs[23] = (shape_funcs_tmp * -128.0 + t232 * xi) - t6 * ((t54 - t26)
      + t87);
    shape_funcs[24] = -t6 * t211 - xi * (((t15 + t88) - t90) + t224);
    shape_funcs[25] = (t7 * t38 + t6 * t240) + t263 * xi;
    shape_funcs[26] = (t234 * xi - t179_tmp * 128.0) - t6 * ((t54 - t39) + t102);
    shape_funcs[27] = -t6 * t216 - xi * (((t18 + t103) - t105) + t223);
    shape_funcs[28] = t196 + t52 * xi;
    shape_funcs[29] = -t222 * xi;
    shape_funcs_tmp = t52_tmp * 32.0 + t10 * -t25;
    shape_funcs[30] = -xi * shape_funcs_tmp;
    shape_funcs[31] = ((((t52 + t120) + t180) + t209) + t3 * t39) + t222 * xi;
    shape_funcs[32] = ((((((t157 + t158) + t196) - t153_tmp * 224.0) + t10 * t93)
                        + t251 * xi) - t154_tmp * 224.0) + t24 * zeta;
    shape_funcs[33] = ((((t52 + t121) + t179) + t209) + t10 * t26) + xi *
      shape_funcs_tmp;
    shape_funcs[34] = t6 * t114 - xi * ((t114 + t159) + t160);
    t267 = t225 + t255;
    t268 = t219 + t254;
    t272 = (t186 + -xi * ((-t40 + t58) + t108)) + (((((t56 + t106) - t103) -
      t130) + t178) + t181);
    t273 = (t199 + -xi * ((-t27 + t58) + t93)) + (((((t56 + t91) - t88) - t125)
      + t177) + t182);
    t274 = ((t171 + t6 * t228) + (((((t58 - t26) - t39) + t87) + t102) +
             46.666666666666664) * xi) + t270;
    t262 = (t96 + -xi * (b_shape_funcs_tmp - 28.0)) + t6 * (t228 - 64.0);
    b_dv[0] = t274;
    b_dv[1] = ((t6 * -48.0 + t171) + 14.666666666666666 * xi) - 1.0;
    b_dv[2] = 0.0;
    b_dv[3] = 0.0;
    t180_tmp = t32 + t45;
    b_dv[4] = ((-t192 + (((((((((t56 + t86) + t101) - t125) - t130) + t177) +
      t178) - t169) - t174) + 16.0)) - t6 * (t180_tmp - 288.0)) - xi * (((((-t32
      - t45) + t93) + t108) + t117) + 138.66666666666666);
    b_dv[5] = ((t7 * 256.0 + (((((t14 + t17) + t52) - t47) - t50) - 12.0)) + t6 *
               (t180_tmp - 384.0)) + xi * (((((t58 - t30) - t43) + t87) + t102)
      + 152.0);
    b_dv[6] = ((-t192 + ((-t63 - t73) + 5.333333333333333)) + xi * ((t23 + t36)
                - 74.666666666666671)) - t6 * ((t228 - 64.0) - 80.0);
    b_dv[7] = (t63 + t185) - t23 * xi;
    b_dv[8] = t205 + t219;
    b_dv[9] = t244;
    b_dv[10] = t248;
    b_dv[11] = t268;
    b_dv[12] = t273;
    b_dv[13] = t272;
    b_dv[14] = t267;
    b_dv[15] = t250;
    b_dv[16] = (t73 + t167) - t36 * xi;
    b_dv[17] = t206 + t225;
    b_dv[18] = t247;
    b_dv[19] = 0.0;
    b_dv[20] = 0.0;
    b_dv[21] = 0.0;
    b_dv[22] = (t264 + t6 * t32) + xi * ((t3 * 512.0 - t33) + t117);
    b_dv[23] = (t232 - t199_tmp * 384.0) - xi * ((-t31 + t58) + t93);
    b_dv[24] = (((-t15 + t90) - t88) + t222) - xi * (-t23 + t93);
    b_dv[25] = (t263 + t6 * t45) + xi * ((t10 * 512.0 - t46) + t117);
    b_dv[26] = (t234 - t186_tmp * 384.0) - xi * ((-t44 + t58) + t108);
    b_dv[27] = (((-t18 + t105) - t103) + t221) - xi * (-t36 + t108);
    b_dv[28] = t52 + t131;
    b_dv[29] = t224;
    b_dv[30] = t223;
    b_dv[31] = t222;
    b_dv[32] = t131 + t251;
    b_dv[33] = t221;
    b_dv[34] = ((t58 + t181) + t182) - t117 * xi;
    b_dv[35] = t274;
    b_dv[36] = 0.0;
    b_dv[37] = ((eta * 14.666666666666666 - t3 * 48.0) + t169) - 1.0;
    b_dv[38] = 0.0;
    b_dv[39] = t269;
    b_dv[40] = t262;
    b_dv[41] = t249;
    b_dv[42] = t246;
    b_dv[43] = t213 - xi * (t15 - 4.0);
    t180_tmp = xi * ((-t23 + t87) + 5.333333333333333);
    b_dv[44] = t180_tmp;
    b_dv[45] = ((((((eta * -74.666666666666671 + t53) + t92) - t73) + t178) -
                 t189) - t180_tmp) + 5.333333333333333;
    b_dv[46] = (((((((((eta * 152.0 + t4 * 256.0) + t17) - t50) + t115) - t94) +
                   t155) + t162) + t213) + xi * ((((-t18 + t58) - t30) + t94) +
      28.0)) - 12.0;
    t180_tmp = t29 + (t38 - 16.0);
    b_dv[47] = (((((((((((eta * -138.66666666666666 + t3 * 288.0) + t61) + t101)
                       - t130) + t181) + t184) - t171) - t174) - t189) - t6 *
                 (t180_tmp - 80.0)) - xi * (((((-t40 - t32) + t94) + t102) +
      t117) + 69.333333333333329)) + 16.0;
    b_dv[48] = t272;
    b_dv[49] = t267;
    b_dv[50] = t250;
    b_dv[51] = 0.0;
    b_dv[52] = 0.0;
    b_dv[53] = 0.0;
    b_dv[54] = (t73 + t156) + -64.0 * zeta * eta;
    b_dv[55] = t206 + t223;
    b_dv[56] = t247;
    b_dv[57] = (t96 + t6 * ((eta * 512.0 + t42) - 224.0)) + xi * (((((-t33 - t41)
      + t94) + t102) + t117) + 96.0);
    b_dv[58] = (-t96 - t6 * (t180_tmp - 144.0)) + xi * ((t18 + t23) - 32.0);
    b_dv[59] = -xi * ((((-t31 - t18) + t58) + t94) + 32.0) - t6 * (t29 - 32.0);
    b_dv[60] = t6 * t42 + t240 * xi;
    t180_tmp = t18 * xi;
    b_dv[61] = t186 + t180_tmp;
    b_dv[62] = -t225;
    b_dv[63] = t167 - t180_tmp;
    t180_tmp = t18 + t114;
    b_dv[64] = -xi * t180_tmp;
    b_dv[65] = t225;
    b_dv[66] = ((((-t18 + t51) + t60) + t181) + t184) + xi * t180_tmp;
    b_dv[67] = (((((t263_tmp + t116) - t107) + t162) + t167) + t153_tmp * 512.0)
      + xi * ((-t41 + t108) + t117);
    b_dv[68] = ((((-t18 + t53) + t105) - t103) + t181) - t225;
    b_dv[69] = t186_tmp * -256.0 - xi * ((-t42 + t108) + t117);
    b_dv[70] = t274;
    b_dv[71] = 0.0;
    b_dv[72] = 0.0;
    b_dv[73] = ((t10 * -48.0 + t174) + zeta * 14.666666666666666) - 1.0;
    b_dv[74] = t269;
    b_dv[75] = t262;
    b_dv[76] = t249;
    b_dv[77] = 0.0;
    b_dv[78] = 0.0;
    b_dv[79] = 0.0;
    b_dv[80] = t248;
    b_dv[81] = t268;
    b_dv[82] = t273;
    t180_tmp = t42 + (t25 - 16.0);
    b_dv[83] = (((((((((((t10 * 288.0 + t61) + t86) - t125) + t182) + t183) -
                     t169) - t171) - t195) - zeta * 138.66666666666666) - t6 *
                 (t180_tmp - 80.0)) - xi * (((((-t27 - t45) + t87) + t109) +
      t117) + 69.333333333333329)) + 16.0;
    b_dv[84] = (((((((((t11 * 256.0 + t14) - t47) + t115) - t109) + t156) + t161)
                  + t214) + zeta * 152.0) + xi * ((((-t15 + t58) - t43) + t109)
      + 28.0)) - 12.0;
    t179_tmp = xi * ((-t36 + t102) + 5.333333333333333);
    b_dv[85] = ((((((t53 + t107) - t63) + t177) - t195) - zeta *
                 74.666666666666671) - t179_tmp) + 5.333333333333333;
    b_dv[86] = t246;
    b_dv[87] = t214 - xi * (t18 - 4.0);
    b_dv[88] = t179_tmp;
    b_dv[89] = t244;
    b_dv[90] = t205 + t224;
    b_dv[91] = (t63 + t155) + -64.0 * eta * zeta;
    b_dv[92] = t6 * t29 + t239 * xi;
    t179_tmp = t15 * xi;
    b_dv[93] = t199 + t179_tmp;
    b_dv[94] = -t219;
    b_dv[95] = (t96 + xi * (((((-t28 - t46) + t87) + t109) + t117) + 96.0)) + t6
      * ((t29 + zeta * 512.0) - 224.0);
    b_dv[96] = (-t96 - t6 * (t180_tmp - 144.0)) + xi * ((t15 + t36) - 32.0);
    b_dv[97] = -xi * ((((-t15 - t44) + t58) + t109) + 32.0) - t6 * (t42 - 32.0);
    b_dv[98] = t185 - t179_tmp;
    b_dv[99] = t219;
    t180_tmp = t15 + t114;
    b_dv[100] = -xi * t180_tmp;
    b_dv[101] = ((((-t15 + t53) + t90) - t88) + t182) - t219;
    b_dv[102] = (((((t264_tmp + t116) - t92) + t161) + t185) + t154_tmp * 512.0)
      + xi * ((-t28 + t93) + t117);
    b_dv[103] = ((((-t15 + t48) + t60) + t182) + t183) + xi * t180_tmp;
    b_dv[104] = t199_tmp * -256.0 - xi * ((-t29 + t93) + t117);
    i = 0;
    i1 = 0;
    for (int i2{0}; i2 < 105; i2++) {
      deriv[i1 + 3 * i] = b_dv[i2];
      i++;
      if (i > 34) {
        i = 0;
        i1++;
      }
    }
  }

  static inline
  void tri_10(double xi, double eta, double shape_funcs[10], double
                     deriv[20])
  {
    double b_dv[20];
    double shape_funcs_tmp;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t2;
    double t24;
    double t25;
    double t26;
    double t27;
    double t28;
    double t29;
    double t3;
    double t31;
    double t33;
    double t36;
    double t39;
    double t4;
    double t40;
    double t42;
    double t44;
    double t5;
    double t6;
    double t7;
    double t8;
    double t9;
    int i;
    int i1;

    // TRI_10   Cubic triangular element with equidistant points
    t2 = eta * eta;
    t3 = std::pow(eta, 3.0);
    t4 = xi * xi;
    t5 = std::pow(xi, 3.0);
    t6 = eta * 9.0;
    t7 = eta * 18.0;
    t8 = eta * 27.0;
    t9 = eta * 54.0;
    t15 = eta * 4.5;
    t16 = eta * 13.5;
    t17 = eta * 22.5;
    t18 = 4.5 * xi;
    t12 = t2 * 27.0;
    t13 = t4 * 27.0;
    t14 = t8 * xi;
    t24 = t3 * 4.5;
    t25 = t2 * 13.5;
    t26 = t3 * 13.5;
    t27 = t5 * 4.5;
    t28 = t4 * 13.5;
    t29 = t5 * 13.5;
    t31 = t2 * 40.5;
    t33 = t4 * 40.5;
    t36 = t4 * t16;
    t39 = t12 - t17;
    t40 = -t15 + t25;
    t42 = (-t17 + t25) + 9.0;
    shape_funcs[0] = (((((eta * -5.5 + t2 * 9.0) - t24) - t27) - xi * ((-t7 +
      t25) + 5.5)) - t4 * (t16 - 9.0)) + 1.0;
    shape_funcs[1] = (t4 * -4.5 + t27) + xi;
    shape_funcs[2] = (eta - t2 * 4.5) + t24;
    shape_funcs[3] = (t29 + t4 * (t8 - 22.5)) + t42 * xi;
    shape_funcs[4] = (-t29 + (t15 - 4.5) * xi) - t4 * (t16 - 18.0);
    shape_funcs[5] = t36 - t15 * xi;
    shape_funcs_tmp = t40 * xi;
    shape_funcs[6] = shape_funcs_tmp;
    shape_funcs[7] = ((t2 * 18.0 - t15) - t26) - shape_funcs_tmp;
    shape_funcs[8] = (((t2 * -22.5 + t6) + t26) + t36) + t39 * xi;
    shape_funcs[9] = -xi * (-t8 + t12) - eta * t4 * 27.0;
    t44 = (-t28 + -xi * (t8 - 18.0)) + ((t7 - t25) - 5.5);
    b_dv[0] = t44;
    b_dv[1] = (t28 + -9.0 * xi) + 1.0;
    b_dv[2] = 0.0;
    b_dv[3] = (t33 + t42) + xi * (t9 - 45.0);
    b_dv[4] = (-t33 + (t15 - 4.5)) - xi * (t8 - 36.0);
    b_dv[5] = t14 - t15;
    b_dv[6] = t40;
    b_dv[7] = t15 - t25;
    b_dv[8] = t14 + t39;
    b_dv[9] = (t8 - t12) - t9 * xi;
    b_dv[10] = t44;
    b_dv[11] = 0.0;
    b_dv[12] = (-t6 + t25) + 1.0;
    b_dv[13] = t13 + (t8 - 22.5) * xi;
    b_dv[14] = t18 - t28;
    b_dv[15] = -t18 + t28;
    shape_funcs_tmp = xi * (t8 - 4.5);
    b_dv[16] = shape_funcs_tmp;
    b_dv[17] = ((eta * 36.0 - t31) - shape_funcs_tmp) - 4.5;
    b_dv[18] = (((eta * -45.0 + t28) + t31) + xi * (t9 - 22.5)) + 9.0;
    b_dv[19] = -t13 - xi * (t9 - 27.0);
    i = 0;
    i1 = 0;
    for (int i2{0}; i2 < 20; i2++) {
      deriv[i1 + (i << 1)] = b_dv[i2];
      i++;
      if (i > 9) {
        i = 0;
        i1++;
      }
    }
  }

  static inline
  void tri_15(double xi, double eta, double shape_funcs[15], double
                     deriv[30])
  {
    double b_dv[30];
    double b_shape_funcs_tmp;
    double c_shape_funcs_tmp;
    double d_shape_funcs_tmp;
    double e_shape_funcs_tmp;
    double shape_funcs_tmp;
    double t10;
    double t100;
    double t101;
    double t11;
    double t14;
    double t15;
    double t16;
    double t18;
    double t19;
    double t20;
    double t21;
    double t22;
    double t23;
    double t24;
    double t25;
    double t26;
    double t27;
    double t3;
    double t35;
    double t38;
    double t4;
    double t41;
    double t42;
    double t44;
    double t45;
    double t46;
    double t47;
    double t48;
    double t49;
    double t5;
    double t51;
    double t53;
    double t54;
    double t6;
    double t62;
    double t67;
    double t68;
    double t69;
    double t7;
    double t70;
    double t74;
    double t77;
    double t8;
    double t80;
    double t82;
    double t84;
    double t85;
    double t87;
    double t89;
    double t9;
    double t92;
    double t95;
    double t96;
    int i;
    int i1;

    // TRI_15   Quartic triangular element with equidistant points
    t3 = eta * eta;
    t4 = std::pow(eta, 3.0);
    t6 = xi * xi;
    t7 = std::pow(xi, 3.0);
    t9 = eta * 16.0;
    t10 = eta * 28.0;
    t11 = eta * 32.0;
    t14 = eta * 64.0;
    t15 = eta * 96.0;
    t16 = eta * 128.0;
    t18 = eta * 192.0;
    t19 = eta * 256.0;
    t20 = eta * 288.0;
    t21 = eta * 320.0;
    t22 = eta * 384.0;
    t23 = eta * 448.0;
    t27 = eta * 5.333333333333333;
    t35 = 5.333333333333333 * xi;
    t51 = eta * 42.666666666666664;
    t53 = eta * 69.333333333333329;
    t5 = t3 * t3;
    t8 = t6 * t6;
    t24 = t3 * 16.0;
    t25 = t3 * 32.0;
    t26 = t6 * 32.0;
    t38 = t3 * 64.0;
    t41 = t3 * 128.0;
    t42 = t4 * 128.0;
    t44 = t3 * 160.0;
    t45 = t3 * 192.0;
    t46 = t3 * 224.0;
    t47 = t3 * 256.0;
    t48 = t3 * 384.0;
    t49 = t7 * 128.0;
    t67 = t4 * 42.666666666666664;
    t69 = t7 * 42.666666666666664;
    t74 = t4 * 170.66666666666666;
    t77 = t7 * 170.66666666666666;
    t54 = t5 * 10.666666666666666;
    t62 = t8 * 10.666666666666666;
    t68 = t5 * 42.666666666666664;
    t70 = t8 * 42.666666666666664;
    t82 = -t11 + t25;
    t84 = -t11 + t41;
    t85 = t6 * (t16 - 16.0);
    t80 = eta * 4.0 - t24;
    t87 = t84 * xi;
    t89 = t6 * (-t9 + t38);
    t92 = (t10 + t42) - t3 * 144.0;
    t95 = (t15 + t42) - t46;
    t96 = (t27 - t25) + t67;
    t100 = ((eta * 46.666666666666664 - t3 * 80.0) + t67) - 8.3333333333333339;
    shape_funcs[0] = (((((((eta * -8.3333333333333339 + t3 * 23.333333333333332)
      - t4 * 26.666666666666668) + t54) + t62) + t100 * xi) + t6 * ((eta * -80.0
      + t38) + 23.333333333333332)) + t7 * (t51 - 26.666666666666668)) + 1.0;
    shape_funcs[1] = ((t6 * 7.333333333333333 - t7 * 16.0) + t62) + -xi;
    shape_funcs[2] = ((-eta + t3 * 7.333333333333333) - t4 * 16.0) + t54;
    shape_funcs_tmp = ((t3 * 96.0 - t53) - t67) + 16.0;
    b_shape_funcs_tmp = (-t18 + t41) + 69.333333333333329;
    shape_funcs[3] = ((-t70 - t6 * b_shape_funcs_tmp) - t7 * (((t16 - 16.0) -
      64.0) - 16.0)) + xi * shape_funcs_tmp;
    shape_funcs[4] = ((t8 * 64.0 + t6 * ((eta * -144.0 + t38) + 76.0)) - xi * ((
      -t10 + t24) + 12.0)) + t7 * (((t16 - 16.0) - 64.0) - 48.0);
    shape_funcs[5] = ((-t70 + t6 * (t11 - 37.333333333333336)) - t7 * (t51 -
      74.666666666666671)) - xi * (t27 - 5.333333333333333);
    c_shape_funcs_tmp = eta * t6;
    shape_funcs[6] = (c_shape_funcs_tmp * -32.0 + t7 * t51) + t27 * xi;
    shape_funcs[7] = t89 + t80 * xi;
    d_shape_funcs_tmp = t96 * xi;
    shape_funcs[8] = d_shape_funcs_tmp;
    shape_funcs[9] = (((t3 * -37.333333333333336 + t4 * 74.666666666666671) +
                       t27) - t68) - d_shape_funcs_tmp;
    shape_funcs[10] = ((((eta * -12.0 + t3 * 76.0) + t5 * 64.0) - t42) + t89) +
      t92 * xi;
    d_shape_funcs_tmp = eta * t7;
    shape_funcs[11] = (((((t3 * -69.333333333333329 + t4 * 96.0) + t9) - t68) +
                        t6 * (t15 - t41)) - d_shape_funcs_tmp *
                       42.666666666666664) - xi * ((t42 - t45) + t53);
    shape_funcs[12] = (t7 * t16 + t95 * xi) - t6 * (eta * 224.0 - t47);
    e_shape_funcs_tmp = -(eta * 160.0) + t41;
    shape_funcs[13] = (-t6 * e_shape_funcs_tmp - d_shape_funcs_tmp * 128.0) +
      t82 * xi;
    shape_funcs[14] = -t6 * t84 - xi * ((t11 + t42) - t44);
    t101 = ((t69 + t6 * ((t16 - 16.0) - 64.0)) + (e_shape_funcs_tmp +
             46.666666666666664) * xi) + t100;
    b_dv[0] = t101;
    b_dv[1] = ((t6 * -48.0 + t69) + 14.666666666666666 * xi) - 1.0;
    b_dv[2] = 0.0;
    b_dv[3] = ((-t77 + shape_funcs_tmp) - xi * ((-t22 + t47) +
                138.66666666666666)) - t6 * (t22 - 288.0);
    b_dv[4] = ((t7 * 256.0 + ((t10 - t24) - 12.0)) + xi * ((-t20 + t41) + 152.0))
      + t6 * (t22 - 384.0);
    b_dv[5] = ((-t77 + (-t27 + 5.333333333333333)) - t6 * (((t16 - 16.0) - 64.0)
                - 144.0)) + xi * (t14 - 74.666666666666671);
    b_dv[6] = (t27 + t6 * t16) - t14 * xi;
    b_dv[7] = t80 + t87;
    b_dv[8] = t96;
    b_dv[9] = (t25 - t27) - t67;
    b_dv[10] = t87 + t92;
    b_dv[11] = (((t45 - t42) - t53) + xi * (t18 - t47)) - c_shape_funcs_tmp *
      128.0;
    b_dv[12] = (t95 + t6 * t22) + xi * (t3 * 512.0 - t23);
    b_dv[13] = (t82 + xi * (t21 - t47)) - c_shape_funcs_tmp * 384.0;
    b_dv[14] = ((-t11 + t44) - t42) - xi * (-t14 + t47);
    b_dv[15] = t101;
    b_dv[16] = 0.0;
    b_dv[17] = ((eta * 14.666666666666666 - t3 * 48.0) + t67) - 1.0;
    b_dv[18] = (-t49 - xi * b_shape_funcs_tmp) - t6 * (t19 - 192.0);
    b_dv[19] = (t49 + t6 * (((t16 - 16.0) - 64.0) - 64.0)) - xi * (t11 - 28.0);
    b_dv[20] = (t26 - t35) - t69;
    b_dv[21] = (-t26 + t35) + t69;
    b_dv[22] = t85 - xi * (t11 - 4.0);
    e_shape_funcs_tmp = xi * ((-t14 + t41) + 5.333333333333333);
    b_dv[23] = e_shape_funcs_tmp;
    b_dv[24] = (((eta * -74.666666666666671 + t46) - t74) - e_shape_funcs_tmp) +
      5.333333333333333;
    b_dv[25] = ((((eta * 152.0 + t4 * 256.0) - t48) + t85) + xi * ((-t20 + t48)
      + 28.0)) - 12.0;
    b_dv[26] = (((((eta * -138.66666666666666 + t3 * 288.0) - t69) - t74) - xi *
                 ((-t22 + t48) + 69.333333333333329)) - t6 * (t19 - 96.0)) +
      16.0;
    b_dv[27] = (t49 + xi * ((-t23 + t48) + 96.0)) + t6 * (eta * 512.0 - 224.0);
    b_dv[28] = (-t49 - t6 * (t19 - 160.0)) + xi * (t14 - 32.0);
    b_dv[29] = -xi * ((-t21 + t48) + 32.0) - t6 * (t19 - 32.0);
    i = 0;
    i1 = 0;
    for (int i2{0}; i2 < 30; i2++) {
      deriv[i1 + (i << 1)] = b_dv[i2];
      i++;
      if (i > 14) {
        i = 0;
        i1++;
      }
    }
  }

  static inline
  void tri_21(double xi, double eta, double shape_funcs[21], double
                     deriv[42])
  {
    double b_dv[42];
    double shape_funcs_tmp;
    double t10;
    double t100;
    double t101;
    double t102;
    double t104;
    double t105;
    double t107;
    double t108;
    double t109;
    double t11;
    double t110;
    double t111;
    double t112;
    double t113;
    double t114;
    double t119;
    double t12;
    double t123;
    double t124;
    double t125;
    double t128;
    double t13;
    double t136;
    double t137;
    double t138;
    double t139;
    double t14;
    double t140;
    double t15;
    double t150;
    double t151;
    double t152;
    double t153;
    double t155;
    double t156;
    double t157;
    double t166;
    double t170;
    double t171;
    double t173;
    double t174;
    double t175;
    double t177;
    double t178;
    double t179;
    double t179_tmp;
    double t181;
    double t182;
    double t183;
    double t186;
    double t189;
    double t19;
    double t192;
    double t193;
    double t195;
    double t196;
    double t198;
    double t2;
    double t20;
    double t202;
    double t203;
    double t204;
    double t206;
    double t207;
    double t208;
    double t21;
    double t210;
    double t212;
    double t25;
    double t26;
    double t27;
    double t28;
    double t29;
    double t3;
    double t30;
    double t31;
    double t34;
    double t35;
    double t36;
    double t37;
    double t4;
    double t40;
    double t41;
    double t42;
    double t44;
    double t45;
    double t47;
    double t48;
    double t49;
    double t5;
    double t50;
    double t51;
    double t52;
    double t53;
    double t54;
    double t55;
    double t56;
    double t57;
    double t59;
    double t6;
    double t60;
    double t66;
    double t67;
    double t68;
    double t7;
    double t70;
    double t76;
    double t8;
    double t82;
    double t85;
    double t86;
    double t87;
    double t88;
    double t89;
    double t9;
    double t91;
    double t94;
    double t95;
    double t96;
    double t97;
    double t98;
    double t99;
    int i;
    int i1;

    // TRI_21   Quintic triangular element with equidistant points
    t2 = eta * eta;
    t3 = std::pow(eta, 3.0);
    t5 = std::pow(eta, 5.0);
    t6 = xi * xi;
    t7 = std::pow(xi, 3.0);
    t9 = std::pow(xi, 5.0);
    t10 = eta * 25.0;
    t11 = eta * 125.0;
    t12 = eta * 250.0;
    t13 = eta * 375.0;
    t14 = eta * 6.25;
    t15 = eta * 4.166666666666667;
    t19 = eta * 625.0;
    t20 = eta * 3125.0;
    t21 = 6.25 * xi;
    t25 = eta * 37.5;
    t26 = eta * 62.5;
    t27 = eta * 41.666666666666664;
    t28 = eta * 31.25;
    t29 = eta * 20.833333333333332;
    t30 = eta * 83.333333333333329;
    t31 = eta * 93.75;
    t40 = eta * 312.5;
    t41 = eta * 156.25;
    t42 = eta * 562.5;
    t44 = eta * 468.75;
    t45 = eta * 708.33333333333326;
    t47 = eta * 1562.5;
    t48 = eta * 1041.666666666667;
    t49 = eta * 781.25;
    t50 = eta * 520.83333333333326;
    t51 = eta * 1812.5;
    t52 = eta * 645.83333333333326;
    t53 = eta * 2187.5;
    t54 = eta * 1093.75;
    t55 = eta * 1958.333333333333;
    t56 = eta * 2083.333333333333;
    t57 = eta * 3437.5;
    t66 = eta * 97.916666666666671;
    t67 = eta * 114.5833333333333;
    t68 = eta * 57.291666666666671;
    t70 = eta * 160.41666666666671;
    t76 = eta * 130.20833333333329;
    t82 = eta * 1479.166666666667;
    t119 = eta * 739.58333333333326;
    t4 = t2 * t2;
    t8 = t6 * t6;
    t34 = t2 * 625.0;
    t35 = t3 * 1250.0;
    t36 = t2 * 2500.0;
    t37 = t3 * 3125.0;
    t59 = t2 * 31.25;
    t60 = t2 * 20.833333333333332;
    t85 = t2 * 312.5;
    t86 = t3 * 312.5;
    t87 = t2 * 156.25;
    t88 = t3 * 156.25;
    t89 = t2 * 281.25;
    t91 = t2 * 468.75;
    t94 = t2 * 1562.5;
    t95 = t3 * 1562.5;
    t96 = t2 * 781.25;
    t97 = t3 * 1041.666666666667;
    t98 = t3 * 781.25;
    t99 = t2 * 520.83333333333326;
    t101 = t3 * 520.83333333333326;
    t104 = t2 * 2187.5;
    t105 = t2 * 1093.75;
    t107 = t3 * 1406.25;
    t108 = t2 * 979.16666666666674;
    t109 = t3 * 2083.333333333333;
    t110 = t2 * 3437.5;
    t111 = t2 * 1718.75;
    t112 = t7 * 156.25;
    t123 = t3 * 52.083333333333336;
    t124 = t5 * 26.041666666666668;
    t125 = t2 * 57.291666666666671;
    t128 = t2 * 265.625;
    t136 = t2 * 260.41666666666669;
    t137 = t3 * 260.41666666666669;
    t138 = t5 * 260.41666666666669;
    t140 = t5 * 130.20833333333329;
    t150 = t2 * 4687.5;
    t151 = t2 * 2343.75;
    t152 = t9 * 26.041666666666668;
    t153 = t6 * 57.291666666666671;
    t155 = t9 * 260.41666666666669;
    t157 = t9 * 130.20833333333329;
    t166 = t2 * 739.58333333333326;
    t175 = t7 * t50;
    t179_tmp = eta * t7;
    t179 = t179_tmp * -2083.333333333333;
    t100 = t4 * 781.25;
    t102 = t4 * 520.83333333333326;
    t113 = t8 * 781.25;
    t114 = t8 * 520.83333333333326;
    t139 = t4 * 130.20833333333329;
    t156 = t8 * 130.20833333333329;
    t170 = t4 * 1302.083333333333;
    t171 = t4 * 651.04166666666674;
    t173 = t8 * 1302.083333333333;
    t174 = t8 * 651.04166666666674;
    t177 = eta * t8 * -520.83333333333326;
    t178 = t8 * t76;
    t181 = -t15 + t60;
    t183 = -t41 + t96;
    t186 = (-t25 + t60) + 16.666666666666668;
    t182 = t27 - t2 * 41.666666666666664;
    t189 = (t28 - t2 * 187.5) + t88;
    t192 = (t27 + t101) - t85;
    t193 = t6 * ((-t40 + t96) + 20.833333333333332);
    t196 = ((-(t2 * 125.0) + t66) + t123) - 25.0;
    t202 = ((-t11 + t100) + t2 * 906.25) - t95;
    t203 = ((t101 + t119) - t105) - 160.41666666666671;
    t206 = ((-t14 - t88) + t125) + t139;
    t207 = ((-t25 + t102) - t98) + t2 * 322.91666666666669;
    t208 = ((t102 - t70) - t3 * 1093.75) + t166;
    t210 = (((-t70 + t139) - t3 * 364.58333333333331) + t2 * 369.79166666666669)
      + 25.0;
    t195 = t192 * xi;
    t198 = t6 * ((t29 - t87) + t137);
    t204 = ((t27 + t3 * 833.33333333333326) - t2 * 354.16666666666669) - t102;
    shape_funcs[0] = (((((((((eta * -11.416666666666666 + t2 * 46.875) - t3 *
      88.541666666666671) + t4 * 78.125) - t124) - t152) - t7 * ((-t40 + t136) +
      88.541666666666671)) - t8 * (t76 - 78.125)) - xi * ((((-t31 - t86) + t128)
      + t139) + 11.416666666666666)) - t6 * (((eta * 265.625 - t91) + t137) -
      46.875)) + 1.0;
    shape_funcs[1] = (((t6 * -10.416666666666666 + t7 * 36.458333333333336) - t8
                       * 52.083333333333336) + t152) + xi;
    shape_funcs[2] = (((eta - t2 * 10.416666666666666) + t3 * 36.458333333333336)
                      - t4 * 52.083333333333336) + t124;
    shape_funcs[3] = (((t157 + t7 * ((-t54 + t96) + 369.79166666666669)) + t6 *
                       t203) + t210 * xi) + t8 * (t50 - 364.58333333333331);
    shape_funcs[4] = (((-t155 + t196 * xi) - t7 * ((eta * -1406.25 + t96) +
      614.58333333333326)) - t6 * (((t119 - t96) + t137) - 222.91666666666671))
      - t8 * (t49 - 677.08333333333326);
    shape_funcs[5] = (((t155 + t7 * ((-t49 + t136) + 510.41666666666669)) + t186
                       * xi) - t6 * ((eta * -322.91666666666669 + t87) + 162.5))
      + t8 * (t50 - 625.0);
    shape_funcs[6] = (((-t157 + (t14 - 6.25) * xi) - t6 * (t68 -
      63.541666666666671)) + t7 * (t41 - 213.54166666666671)) - t8 * (t76 -
      286.45833333333331);
    shape_funcs[7] = ((t178 - t179_tmp * 156.25) + t6 * t68) - t14 * xi;
    shape_funcs_tmp = t7 * (eta * 52.083333333333336 - t136);
    shape_funcs[8] = (t6 * (t28 - t87) - shape_funcs_tmp) + t181 * xi;
    shape_funcs[9] = t198 - xi * ((t15 - t59) + t123);
    t179_tmp = t206 * xi;
    shape_funcs[10] = t179_tmp;
    shape_funcs[11] = ((((t2 * 63.541666666666671 - t3 * 213.54166666666671) +
                         t4 * 286.45833333333331) - t14) - t140) - t179_tmp;
    shape_funcs[12] = (((((eta * 16.666666666666668 - t2 * 162.5) + t3 *
                          510.41666666666669) - t4 * 625.0) + t138) + t198) +
      t207 * xi;
    shape_funcs[13] = ((((((t2 * 222.91666666666671 - t3 * 614.58333333333326) +
      t4 * 677.08333333333326) - t10) - t138) + shape_funcs_tmp) + xi * (((t66 -
      t100) + t107) - t166)) - t6 * ((t11 + t98) - t96);
    shape_funcs[14] = (((((((t2 * -160.41666666666671 + t3 * 369.79166666666669)
      - t4 * 364.58333333333331) + t10) + t140) + t178) + t208 * xi) - t7 * (eta
      * 364.58333333333331 - t99)) + t6 * ((eta * 369.79166666666669 + t98) -
      t105);
    shape_funcs[15] = ((t177 - t6 * ((eta * 979.16666666666674 - t36) + t95)) -
                       xi * (((-t12 - t35) + t102) + t108)) + t7 * (eta * 1250.0
      - t94);
    shape_funcs[16] = ((t7 * (-t47 + t94) + t8 * t49) + t6 * ((eta * 906.25 +
      t98) - t111)) - xi * ((t11 + t88) - t89);
    shape_funcs[17] = ((t177 + t182 * xi) - t6 * (eta * 354.16666666666669 - t85))
      + t7 * (eta * 833.33333333333326 - t99);
    shape_funcs[18] = (-t7 * t183 + t189 * xi) - t6 * ((eta * 187.5 + t98) -
      t105);
    shape_funcs[19] = -t6 * t192 + t204 * xi;
    shape_funcs[20] = (t7 * t183 + t202 * xi) + t6 * ((eta * 281.25 + t95) -
      t111);
    t212 = (((-t156 + -t7 * (t50 - 312.5)) + -t6 * ((-(eta * 937.5) + t96) +
              265.625)) + (((-(eta * 531.25) + t2 * 937.5) - t101) + 93.75) * xi)
      + ((((t31 + t86) - t128) - t139) - 11.416666666666666);
    b_dv[0] = t212;
    b_dv[1] = (((t6 * 109.375 - t7 * 208.33333333333334) + t156) +
               -20.833333333333332 * xi) + 1.0;
    b_dv[2] = 0.0;
    b_dv[3] = (((t174 + t210) + t6 * ((eta * -3281.25 + t151) + 1109.375)) + xi *
               (((t82 + t97) - t104) - 320.83333333333331)) + t7 * (t56 -
      1458.333333333333);
    b_dv[4] = (((-t173 + t196) - t6 * ((eta * -4218.75 + t151) + 1843.75)) - xi *
               (((t82 + t101) - t94) - 445.83333333333331)) - t7 * (t20 -
      2708.333333333333);
    b_dv[5] = (((t173 + t186) + t6 * ((eta * -2343.75 + t96) + 1531.25)) - xi *
               ((-t52 + t85) + 325.0)) + t7 * (t56 - 2500.0);
    b_dv[6] = ((((t14 - 6.25) - t174) + t6 * (t44 - 640.625)) - t7 * (t50 -
                1145.833333333333)) - xi * (t67 - 127.0833333333333);
    b_dv[7] = ((-t14 + t175) - eta * t6 * 468.75) + t67 * xi;
    shape_funcs_tmp = t6 * t183;
    b_dv[8] = (t181 + xi * (t26 - t85)) + shape_funcs_tmp;
    b_dv[9] = ((-t15 + t59) - t123) + t195;
    b_dv[10] = t206;
    b_dv[11] = ((t14 + t88) - t125) - t139;
    b_dv[12] = t195 + t207;
    b_dv[13] = ((((t66 + t107) - t100) - t166) - shape_funcs_tmp) - xi * ((t12 +
      t95) - t94);
    b_dv[14] = ((t175 + t208) + t6 * (-t54 + t94)) + xi * ((t95 + t119) - t104);
    b_dv[15] = ((t179 + (((t12 + t35) - t102) - t108)) + t6 * (eta * 3750.0 -
      t150)) - xi * ((t2 * -5000.0 + t37) + t55);
    b_dv[16] = ((((-t11 + t89) - t88) + t7 * t20) - t6 * (eta * 4687.5 - t150))
      + xi * ((t51 + t95) - t110);
    b_dv[17] = ((t179 + t182) + xi * (t34 - t45)) + t6 * (eta * 2500.0 - t94);
    shape_funcs_tmp = t6 * (-t44 + t151);
    b_dv[18] = (t189 - shape_funcs_tmp) - xi * ((t13 + t95) - t104);
    b_dv[19] = t204 - xi * ((t30 - t34) + t97);
    b_dv[20] = (t202 + shape_funcs_tmp) + xi * ((t37 + t42) - t110);
    b_dv[21] = t212;
    b_dv[22] = 0.0;
    b_dv[23] = (((t2 * 109.375 - t3 * 208.33333333333334) - t29) + t139) + 1.0;
    b_dv[24] = ((t114 + t6 * ((-t53 + t94) + 739.58333333333326)) + t203 * xi) +
      t7 * (t47 - 1093.75);
    b_dv[25] = ((-t113 - t6 * ((-t47 + t96) + 739.58333333333326)) + xi * ((-t12
      + t87) + 97.916666666666671)) - t7 * (t47 - 1406.25);
    b_dv[26] = ((t114 + t7 * (t50 - 781.25)) - t6 * (t40 - 322.91666666666669))
      + xi * (t27 - 37.5);
    b_dv[27] = ((t21 + t112) - t153) - t156;
    b_dv[28] = ((-t21 - t112) + t153) + t156;
    shape_funcs_tmp = t7 * (t50 - 52.083333333333336);
    b_dv[29] = (-t6 * (t40 - 31.25) + shape_funcs_tmp) + xi * (t27 -
      4.166666666666667);
    b_dv[30] = t193 - xi * ((-t26 + t87) + 4.166666666666667);
    t179_tmp = xi * (((t67 + t101) - t91) - 6.25);
    b_dv[31] = t179_tmp;
    b_dv[32] = ((((eta * 127.0833333333333 - t2 * 640.625) + t3 *
                  1145.833333333333) - t171) - t179_tmp) - 6.25;
    b_dv[33] = (((((eta * -325.0 + t2 * 1531.25) - t3 * 2500.0) + t170) + t193)
                - xi * (((-t52 - t109) + t151) + 37.5)) + 16.666666666666668;
    b_dv[34] = ((((((eta * 445.83333333333331 - t2 * 1843.75) + t3 *
                    2708.333333333333) - t170) - t6 * ((-t47 + t151) + 125.0)) +
                 xi * (((t2 * 4218.75 - t37) - t82) + 97.916666666666671)) -
                shape_funcs_tmp) - 25.0;
    shape_funcs_tmp = -t53 + t151;
    b_dv[35] = (((((((eta * -320.83333333333331 + t2 * 1109.375) - t3 *
                     1458.333333333333) + t156) + t171) + t6 * (shape_funcs_tmp
      + 369.79166666666669)) + t7 * (t48 - 364.58333333333331)) - xi * (((t2 *
      3281.25 - t82) - t109) + 160.41666666666671)) + 25.0;
    b_dv[36] = ((-t114 - t6 * ((eta * -5000.0 + t150) + 979.16666666666674)) -
                t7 * (t20 - 1250.0)) + xi * (((t2 * 3750.0 - t55) - t109) +
      250.0);
    b_dv[37] = ((t113 + t6 * ((-t57 + t151) + 906.25)) - xi * ((-t42 + t91) +
      125.0)) + t7 * (t20 - 1562.5);
    b_dv[38] = ((-t114 + t6 * (t19 - 354.16666666666669)) - t7 * (t48 -
      833.33333333333326)) - xi * (t30 - 41.666666666666664);
    t179_tmp = t7 * (t47 - 156.25);
    b_dv[39] = (-t6 * (shape_funcs_tmp + 187.5) + xi * ((-t13 + t91) + 31.25)) -
      t179_tmp;
    b_dv[40] = -t6 * ((-t19 + t94) + 41.666666666666664) + xi * (((t36 - t45) -
      t109) + 41.666666666666664);
    b_dv[41] = (t6 * ((-t57 + t150) + 281.25) + t179_tmp) - xi * (((-t51 - t37)
      + t150) + 125.0);
    i = 0;
    i1 = 0;
    for (int i2{0}; i2 < 42; i2++) {
      deriv[i1 + (i << 1)] = b_dv[i2];
      i++;
      if (i > 20) {
        i = 0;
        i1++;
      }
    }
  }

  static inline
  void tri_28(double xi, double eta, double shape_funcs[28], double
                     deriv[56])
  {
    double b_dv[56];
    double b_shape_funcs_tmp;
    double c_shape_funcs_tmp;
    double d_shape_funcs_tmp;
    double e_shape_funcs_tmp;
    double f_shape_funcs_tmp;
    double shape_funcs_tmp;
    double shape_funcs_tmp_tmp;
    double t10;
    double t11;
    double t117;
    double t118;
    double t119;
    double t12;
    double t120;
    double t121;
    double t122;
    double t123;
    double t124;
    double t125;
    double t132;
    double t133;
    double t134;
    double t135;
    double t136;
    double t137;
    double t138;
    double t139;
    double t14;
    double t143;
    double t144;
    double t145;
    double t146;
    double t15;
    double t151;
    double t152;
    double t153;
    double t154;
    double t155;
    double t156;
    double t158;
    double t160;
    double t161;
    double t162;
    double t164;
    double t166;
    double t167;
    double t170;
    double t171;
    double t172;
    double t173;
    double t174;
    double t176;
    double t177;
    double t178;
    double t179;
    double t180;
    double t181;
    double t182;
    double t183;
    double t184;
    double t185;
    double t186;
    double t19;
    double t190;
    double t191;
    double t192;
    double t194;
    double t195;
    double t196;
    double t197;
    double t198;
    double t199;
    double t200;
    double t201;
    double t202;
    double t203;
    double t21;
    double t210;
    double t22;
    double t24;
    double t252;
    double t254;
    double t256;
    double t257;
    double t258;
    double t259;
    double t26;
    double t260;
    double t261;
    double t262;
    double t263;
    double t264;
    double t265;
    double t266;
    double t267;
    double t268;
    double t269;
    double t270;
    double t271;
    double t272;
    double t273;
    double t274;
    double t275;
    double t276;
    double t277;
    double t278;
    double t279;
    double t28;
    double t280;
    double t281;
    double t282;
    double t283;
    double t284;
    double t29;
    double t290;
    double t292;
    double t293;
    double t294;
    double t3;
    double t30;
    double t31;
    double t314;
    double t315;
    double t32;
    double t322;
    double t325;
    double t332;
    double t334;
    double t335;
    double t336;
    double t339;
    double t341;
    double t342;
    double t345;
    double t346;
    double t348;
    double t349;
    double t35;
    double t350;
    double t351;
    double t356;
    double t359;
    double t36;
    double t360;
    double t362;
    double t363;
    double t364;
    double t365;
    double t372;
    double t373;
    double t374;
    double t378;
    double t380;
    double t383;
    double t4;
    double t45;
    double t46;
    double t47;
    double t48;
    double t49;
    double t5;
    double t50;
    double t51;
    double t52;
    double t53;
    double t54;
    double t56;
    double t57;
    double t58;
    double t59;
    double t6;
    double t60;
    double t61;
    double t62;
    double t64;
    double t65;
    double t66;
    double t68;
    double t69;
    double t7;
    double t70;
    double t71;
    double t72;
    double t73;
    double t74;
    double t75;
    double t76;
    double t77;
    double t78;
    double t8;
    double t81;
    double t82;
    double t84;
    double t86;
    double t87;
    double t88;
    double t89;
    double t9;
    double t91;
    double t93;
    double t94;
    double t95;
    double t97;
    int i;
    int i1;

    // TRI_28   Sextic triangular element with equidistant points.
    t3 = eta * eta;
    t4 = std::pow(eta, 3.0);
    t6 = std::pow(eta, 5.0);
    t8 = xi * xi;
    t9 = std::pow(xi, 3.0);
    t11 = std::pow(xi, 5.0);
    t14 = eta * 36.0;
    t15 = eta * 54.0;
    t19 = eta * 72.0;
    t21 = eta * 99.0;
    t22 = eta * 108.0;
    t24 = eta * 148.0;
    t26 = eta * 180.0;
    t28 = eta * 360.0;
    t29 = eta * 378.0;
    t30 = eta * 486.0;
    t31 = eta * 504.0;
    t35 = eta * 4.5;
    t36 = eta * 7.2;
    t45 = eta * 594.0;
    t46 = eta * 648.0;
    t47 = eta * 720.0;
    t48 = eta * 792.0;
    t49 = eta * 972.0;
    t50 = eta * 1071.0;
    t51 = eta * 1134.0;
    t52 = eta * 1188.0;
    t53 = eta * 1197.0;
    t54 = eta * 1296.0;
    t56 = eta * 1944.0;
    t57 = eta * 2088.0;
    t58 = eta * 2214.0;
    t59 = eta * 2592.0;
    t60 = eta * 2664.0;
    t61 = eta * 3384.0;
    t62 = eta * 3672.0;
    t64 = eta * 3888.0;
    t65 = eta * 4032.0;
    t66 = eta * 4176.0;
    t68 = eta * 4968.0;
    t69 = eta * 5022.0;
    t70 = eta * 5184.0;
    t71 = eta * 5220.0;
    t72 = eta * 5832.0;
    t73 = eta * 6156.0;
    t74 = eta * 6984.0;
    t75 = eta * 7128.0;
    t76 = eta * 7776.0;
    t77 = eta * 7992.0;
    t78 = 7.2 * xi;
    t97 = eta * 49.5;
    t117 = eta * 9342.0;
    t118 = eta * 9720.0;
    t119 = eta * 10044.0;
    t120 = eta * 10368.0;
    t121 = eta * 11664.0;
    t122 = eta * 15552.0;
    t123 = eta * 19440.0;
    t124 = eta * 22464.0;
    t125 = eta * 23328.0;
    t200 = eta * 256.5;
    t201 = eta * 162.4;
    t202 = eta * 313.2;
    t203 = eta * 388.8;
    t5 = t3 * t3;
    t7 = std::pow(t3, 3.0);
    t10 = t8 * t8;
    t12 = std::pow(t8, 3.0);
    t32 = t3 * 27.0;
    t81 = t4 * 72.0;
    t82 = t3 * 90.0;
    t86 = t3 * 216.0;
    t87 = t4 * 216.0;
    t88 = t3 * 252.0;
    t89 = t3 * 297.0;
    t91 = t4 * 378.0;
    t93 = t4 * 486.0;
    t94 = t8 * 90.0;
    t95 = t9 * 378.0;
    t132 = t3 * 594.0;
    t133 = t3 * 648.0;
    t134 = t4 * 648.0;
    t136 = t3 * 972.0;
    t137 = t4 * 972.0;
    t144 = t3 * 1188.0;
    t145 = t4 * 1260.0;
    t146 = t4 * 1296.0;
    t151 = t3 * 1692.0;
    t152 = t3 * 1836.0;
    t153 = t3 * 1944.0;
    t154 = t4 * 1944.0;
    t156 = t6 * 1944.0;
    t158 = t3 * 2088.0;
    t160 = t3 * 2484.0;
    t161 = t4 * 2538.0;
    t162 = t4 * 2592.0;
    t164 = t3 * 2916.0;
    t166 = t3 * 3492.0;
    t167 = t3 * 3672.0;
    t170 = t3 * 3888.0;
    t171 = t4 * 3888.0;
    t173 = t6 * 3888.0;
    t174 = t3 * 3996.0;
    t176 = t3 * 4671.0;
    t177 = t3 * 4968.0;
    t178 = t3 * 5022.0;
    t179 = t4 * 5022.0;
    t180 = t3 * 5184.0;
    t181 = t4 * 5184.0;
    t183 = t3 * 5832.0;
    t185 = t6 * 5832.0;
    t186 = t4 * 6120.0;
    t190 = t3 * 7776.0;
    t191 = t4 * 7776.0;
    t194 = t3 * 7992.0;
    t197 = t11 * 1944.0;
    t198 = t11 * 3888.0;
    t199 = t11 * 5832.0;
    t254 = t3 * 9342.0;
    t256 = t4 * 9612.0;
    t258 = t3 * 10044.0;
    t259 = t4 * 10368.0;
    t261 = t3 * 10692.0;
    t262 = t3 * 11232.0;
    t263 = t3 * 11664.0;
    t264 = t4 * 11664.0;
    t266 = t3 * 15552.0;
    t267 = t4 * 15552.0;
    t269 = t3 * 17496.0;
    t270 = t3 * 19440.0;
    t272 = t3 * 22464.0;
    t273 = t3 * 23328.0;
    t274 = t4 * 23328.0;
    t275 = t3 * 29160.0;
    t276 = t3 * 31104.0;
    t277 = t4 * 31104.0;
    t278 = t3 * 33048.0;
    t279 = t3 * 34992.0;
    t280 = t4 * 34992.0;
    t281 = t3 * 40824.0;
    t282 = t3 * 52488.0;
    t283 = t3 * 64152.0;
    t290 = t3 * 535.5;
    t292 = t3 * 661.5;
    t293 = t6 * 388.8;
    t314 = t11 * 388.8;
    t322 = t6 * 2332.8;
    t325 = t11 * 2332.8;
    t84 = t5 * 162.0;
    t135 = t5 * 648.0;
    t138 = t5 * 972.0;
    t139 = t7 * 972.0;
    t143 = t5 * 1134.0;
    t155 = t5 * 1944.0;
    t172 = t5 * 3888.0;
    t182 = t5 * 5184.0;
    t184 = t5 * 5832.0;
    t192 = t5 * 7776.0;
    t195 = t10 * 648.0;
    t196 = t12 * 972.0;
    t210 = t7 * 64.8;
    t252 = t5 * 8424.0;
    t257 = t5 * 9720.0;
    t260 = t5 * 10368.0;
    t265 = t5 * 11664.0;
    t268 = t5 * 15552.0;
    t271 = t5 * 19440.0;
    t284 = t12 * 64.8;
    t294 = t7 * 388.8;
    t315 = t12 * 388.8;
    t332 = -t15 + t3 * 54.0;
    t334 = -(eta * 162.0) + t136;
    t335 = t10 * (t56 - 162.0);
    t336 = -t46 + t170;
    t339 = -t10 * (t76 - 648.0);
    t341 = (eta * 4.0 - t3 * 36.0) + t81;
    t342 = t10 * t334;
    t345 = t9 * t336;
    t346 = -t10 * t336;
    t348 = (t26 + t87) - t3 * 396.0;
    t350 = (eta * 216.0 + t171) - t153;
    t351 = ((-t24 + t3 * 180.0) - t81) + 40.0;
    t356 = ((-t14 + t3 * 360.0) + t135) - t137;
    t359 = ((-t15 + t132) + t155) - t154;
    t362 = ((-t28 + t135) + t3 * 1332.0) - t4 * 1620.0;
    t349 = t9 * (t59 - t266);
    t360 = t8 * (((t45 + t171) - t164) - 27.0);
    t363 = ((eta * 135.0 + t154) - t138) - t3 * 1107.0;
    t364 = t359 * xi;
    t365 = t8 * (((-(eta * 27.0) + t89) + t138) - t137);
    t372 = (((t36 + t91) - t82) - t135) + t293;
    t373 = (((eta * 540.0 + t156) + t4 * 6426.0) - t3 * 3078.0) - t184;
    t374 = (((t26 + t173) + t4 * 7020.0) - t3 * 2016.0) - t5 * 9072.0;
    t378 = (((t97 + t156) + t4 * 2376.0) - t5 * 3726.0) - t3 * 598.5;
    t380 = (((t173 + t4 * 7884.0) + t200) - t3 * 2610.0) - t5 * 9396.0;
    shape_funcs[0] = (((((((((((eta * -14.7 + t3 * 81.2) - t4 * 220.5) + t5 *
      315.0) - t6 * 226.8) + t210) + t284) + t8 * ((((eta * -661.5 + t3 * 1890.0)
      - t4 * 2268.0) + t138) + 81.2)) + t10 * ((-t51 + t136) + 315.0)) - xi *
                        (((((t143 - t145) - t201) + t292) - t293) + 14.7)) + t9 *
                       (((eta * 1260.0 - t3 * 2268.0) + t146) - 220.5)) + t11 *
                      (t203 - 226.8)) + 1.0;
    shape_funcs[1] = ((((t8 * 13.7 - t9 * 67.5) + t10 * 153.0) - t11 * 162.0) +
                      t284) + -xi;
    shape_funcs[2] = ((((-eta + t3 * 13.7) - t4 * 67.5) + t5 * 153.0) - t6 *
                      162.0) + t210;
    shape_funcs_tmp = ((((t3 * 1044.0 + t5 * 1296.0) - t4 * 1674.0) - t202) -
                       t293) + 36.0;
    b_shape_funcs_tmp = (((-t57 + t155) + t178) - t181) + 313.2;
    shape_funcs[3] = ((((-t315 + xi * shape_funcs_tmp) - t10 * ((-t70 + t170) +
      1674.0)) + t9 * (((-t69 + t190) - t171) + 1044.0)) - t11 * (((t56 - 162.0)
      - 972.0) - 162.0)) - t8 * b_shape_funcs_tmp;
    shape_funcs[4] = ((((t196 + t9 * (((eta * 7884.0 - t3 * 9720.0) + t171) -
      2074.5)) + t10 * ((eta * -9396.0 + t183) + 3699.0)) + t11 * (t64 - 3078.0))
                      + t8 * ((((eta * -2610.0 - t4 * 3564.0) + t138) + t176) +
      526.5)) - xi * ((((t84 - t93) - t200) + t290) + 45.0);
    shape_funcs[5] = ((((t12 * -1296.0 - t9 * (((eta * 6120.0 + t146) - t180) -
      2232.0)) + t351 * xi) - t10 * ((eta * -8424.0 + t170) + 4356.0)) - t11 *
                      (t64 - 3888.0)) + t8 * (((eta * 1692.0 + t134) - t152) -
      508.0);
    shape_funcs[6] = ((((t196 + t8 * ((eta * -598.5 + t89) + 297.0)) - t9 *
                        ((eta * -2376.0 + t136) + 1381.5)) + t10 * ((eta *
      -3726.0 + t136) + 2889.0)) - xi * ((t32 - t97) + 22.5)) + t11 * (((t56 -
      162.0) - 972.0) - 1620.0);
    shape_funcs[7] = ((((-t315 - t9 * (t29 - 468.0)) + t8 * (eta * 90.0 - 97.2))
                       + t10 * (t46 - 1026.0)) - t11 * (t203 - 1036.8)) - xi *
      (t36 - 7.2);
    c_shape_funcs_tmp = eta * t10;
    shape_funcs[8] = (((eta * t8 * -90.0 - c_shape_funcs_tmp * 648.0) + t9 * t29)
                      + t11 * t203) + t36 * xi;
    shape_funcs[9] = ((t342 - t9 * t334) + t8 * (t89 - t97)) - xi * (t32 - t35);
    shape_funcs_tmp_tmp = (t19 + t146) - t133;
    d_shape_funcs_tmp = t9 * shape_funcs_tmp_tmp;
    shape_funcs[10] = (t341 * xi + d_shape_funcs_tmp) - t8 * ((t3 * -324.0 + t14)
      + t134);
    e_shape_funcs_tmp = ((t35 + t4 * 162.0) - t84) - t3 * 49.5;
    shape_funcs[11] = t365 + xi * e_shape_funcs_tmp;
    f_shape_funcs_tmp = t372 * xi;
    shape_funcs[12] = f_shape_funcs_tmp;
    shape_funcs[13] = (((((t3 * -97.2 + t4 * 468.0) - t5 * 1026.0) + t6 * 1036.8)
                        + t36) - t294) - f_shape_funcs_tmp;
    shape_funcs[14] = ((((((eta * -22.5 - t4 * 1381.5) + t5 * 2889.0) - t6 *
                          2754.0) + t89) + t139) + t365) + t378 * xi;
    shape_funcs[15] = (((((((eta * 40.0 - t3 * 508.0) + t4 * 2232.0) - t5 *
      4356.0) - t7 * 1296.0) + t173) - xi * ((((t24 - t151) + t173) + t186) -
      t252)) - t8 * (((-t26 + t152) + t172) - t181)) - d_shape_funcs_tmp;
    shape_funcs[16] = ((((((((eta * -45.0 + t3 * 526.5) - t4 * 2074.5) + t5 *
      3699.0) - t6 * 3078.0) + t139) + t342) - t8 * (((eta * 535.5 + t4 * 9720.0)
      - t176) - t184)) + t380 * xi) + t9 * ((t3 * -3564.0 + t30) + t171);
    d_shape_funcs_tmp = eta * t11;
    shape_funcs[17] = (((((((((t3 * -313.2 + t4 * 1044.0) - t5 * 1674.0) + t6 *
      1296.0) + t14) - t294) + t10 * (t54 - t153)) - d_shape_funcs_tmp * 388.8)
                        - xi * ((((t156 - t158) + t179) - t182) + t202)) - t9 *
                       ((eta * 1674.0 + t171) - t180)) + t8 * (((eta * 1044.0 +
      t191) - t172) - t178);
    shape_funcs[18] = (((-t8 * (((eta * 3078.0 - t3 * 12852.0) + t4 * 17496.0) -
      t192) - t10 * (t72 - t190)) + t9 * ((eta * 6426.0 + t264) - t269)) + t11 *
                       t56) + t373 * xi;
    shape_funcs[19] = (((t10 * (t120 - t263) - d_shape_funcs_tmp * 3888.0) - t9 *
                        ((eta * 9612.0 - t3 * 21384.0) + t264)) + t362 * xi) +
      t8 * (((eta * 3492.0 - t172) + t264) - t262);
    shape_funcs[20] = (((-t8 * ((eta * 2016.0 + t154) - t174) + t9 * ((eta *
      7020.0 - t3 * 11016.0) + t171)) + t11 * t64) + t348 * xi) - t10 * (eta *
      9072.0 - t190);
    shape_funcs[21] = (((-t8 * (-t46 + t132) - t10 * (-t64 + t153)) -
                        d_shape_funcs_tmp * 1944.0) + t332 * xi) - t9 * (eta *
      2538.0 - t153);
    shape_funcs[22] = ((t346 + t8 * ((t28 + t154) - t160)) - t9 * ((t3 * -6480.0
      + t49) + t171)) - xi * ((t14 + t87) - t88);
    shape_funcs[23] = (-t9 * t350 + t356 * xi) + t8 * (((eta * 252.0 + t4 *
      6480.0) - t160) - t172);
    shape_funcs[24] = -t8 * t359 - xi * ((((t15 + t156) + t161) - t133) - t172);
    shape_funcs[25] = (-t8 * (((eta * 396.0 + t4 * 11016.0) - t174) - t192) + t9
                       * t350) + t374 * xi;
    shape_funcs[26] = ((t346 + t8 * (((eta * 1332.0 + t4 * 21384.0) - t265) -
      t262)) - xi * ((((t28 - t166) + t173) + t256) - t260)) - t9 * ((eta *
      1620.0 + t264) - t263);
    shape_funcs[27] = ((-t8 * (((eta * 1107.0 - t3 * 8748.0) + t4 * 13608.0) -
      t184) + t10 * (-t49 + t183)) + t363 * xi) + t9 * ((t3 * -13608.0 + t56) +
      t264);
    t383 = ((((t314 + t10 * ((t56 - 162.0) - 972.0)) + t9 * ((-(eta * 4536.0) +
                t170) + 1260.0)) + t8 * (((eta * 3780.0 + t171) - t3 * 6804.0) -
              661.5)) + ((((-(eta * 1323.0) + t155) + t3 * 3780.0) - t4 * 4536.0)
                         + 162.4) * xi) + (((((t145 + t201) - t143) + t293) -
      t292) - 14.7);
    b_dv[0] = t383;
    b_dv[1] = ((((t8 * -202.5 + t9 * 612.0) - t10 * 810.0) + t314) + 27.4 * xi)
      - 1.0;
    b_dv[2] = 0.0;
    b_dv[3] = ((((-t325 + shape_funcs_tmp) - t8 * (((eta * 15066.0 + t264) -
      t273) - 3132.0)) - t9 * ((eta * -20736.0 + t266) + 6696.0)) - t10 * (t118
                - 6480.0)) - xi * ((((-t66 + t172) + t258) - t259) + 626.4);
    b_dv[4] = ((((t199 + ((((t93 - t84) + t200) - t290) - 45.0)) + xi * ((((t4 *
      -7128.0 - t71) + t155) + t254) + 1053.0)) + t9 * ((eta * -37584.0 + t273)
      + 14796.0)) + t10 * (t123 - 15390.0)) + t8 * (((eta * 23652.0 + t264) -
      t275) - 6223.5);
    b_dv[5] = ((((t11 * -7776.0 + t351) - t9 * ((eta * -33696.0 + t266) +
      17424.0)) + xi * (((t61 + t146) - t167) - 1016.0)) - t10 * (t123 - 19440.0))
      - t8 * (((eta * 18360.0 + t171) - t266) - 6696.0);
    b_dv[6] = ((((t199 + ((-t32 + t97) - 22.5)) + xi * ((-t53 + t132) + 594.0))
                + t9 * ((eta * -14904.0 + t170) + 11556.0)) - t8 * ((-t75 + t164)
                + 4144.5)) + t10 * (t118 - 13770.0);
    b_dv[7] = (((((-t36 + 7.2) - t325) - t8 * (t51 - 1404.0)) + t9 * (t59 -
      4104.0)) - t10 * (((t56 - 162.0) - 972.0) - 4050.0)) + xi * (t26 - 194.4);
    b_dv[8] = (((t36 - eta * t9 * 2592.0) + t8 * t51) + t10 * t56) - t26 * xi;
    b_dv[9] = (((t35 - t32) + t345) + t8 * (t30 - t164)) + xi * (-t21 + t132);
    f_shape_funcs_tmp = t8 * t350;
    b_dv[10] = (t341 + f_shape_funcs_tmp) - xi * shape_funcs_tmp_tmp;
    b_dv[11] = e_shape_funcs_tmp + t364;
    b_dv[12] = t372;
    b_dv[13] = (((t82 - t36) - t91) + t135) - t293;
    b_dv[14] = t364 + t378;
    b_dv[15] = (((((-t24 + t151) - t173) - t186) + t252) - f_shape_funcs_tmp) -
      xi * (((-t28 + t167) + t192) - t259);
    b_dv[16] = ((t345 + t380) + xi * (((t4 * -19440.0 - t50) + t254) + t265)) +
      t8 * ((eta * 1458.0 + t264) - t261);
    b_dv[17] = (((((((t158 + t182) - t156) - t179) - t202) + t9 * (t70 - t190))
                 - c_shape_funcs_tmp * 1944.0) + xi * (((t57 - t192) + t267) -
      t258)) - t8 * ((t69 + t264) - t266);
    b_dv[18] = (((t373 + t9 * (-t125 + t276)) + t10 * t118) + xi * (((t3 *
      25704.0 - t73) + t268) - t280)) + t8 * ((eta * 19278.0 + t280) - t282);
    b_dv[19] = (((t362 - c_shape_funcs_tmp * 19440.0) - t8 * ((eta * 28836.0 +
      t280) - t283)) + xi * (((t74 - t192) + t274) - t272)) + t9 * (eta *
      41472.0 - t3 * 46656.0);
    b_dv[20] = (((t348 + t10 * t123) - t9 * (eta * 36288.0 - t276)) + t8 * ((eta
      * 21060.0 + t264) - t278)) - xi * ((t65 + t171) - t194);
    b_dv[21] = (((t332 + t9 * (t122 - t190)) + xi * (t54 - t144)) -
                c_shape_funcs_tmp * 9720.0) - t8 * (eta * 7614.0 - t183);
    b_dv[22] = ((((-t14 + t88) - t87) + t349) - t8 * ((eta * 2916.0 + t264) -
      t270)) + xi * ((t47 + t171) - t177);
    f_shape_funcs_tmp = t8 * ((t46 - t183) + t264);
    b_dv[23] = (t356 + xi * (((t4 * 12960.0 + t31) - t177) - t192)) -
      f_shape_funcs_tmp;
    b_dv[24] = ((((-t15 + t133) + t172) - t156) - t161) + xi * (((t22 + t171) -
      t144) - t172);
    b_dv[25] = (t374 + xi * (((t4 * -22032.0 - t48) + t194) + t268)) +
      f_shape_funcs_tmp;
    b_dv[26] = ((t349 + ((((-t28 + t166) - t173) + t260) - t256)) + xi * (((t4 *
      42768.0 - t5 * 23328.0) + t60) - t272)) - t8 * ((eta * 4860.0 + t280) -
      t279);
    b_dv[27] = ((t363 + t9 * (-t64 + t273)) + xi * (((t4 * -27216.0 - t58) +
      t265) + t269)) + t8 * ((t72 + t280) - t281);
    b_dv[28] = t383;
    b_dv[29] = 0.0;
    b_dv[30] = ((((eta * 27.4 - t3 * 202.5) + t4 * 612.0) - t5 * 810.0) + t293)
      - 1.0;
    b_dv[31] = (((-t197 - t9 * ((-t122 + t263) + 5022.0)) + t8 * (((-t119 - t191)
      + t266) + 2088.0)) - t10 * (t76 - 5184.0)) - xi * b_shape_funcs_tmp;
    b_dv[32] = (((t198 + t9 * ((-t123 + t263) + 7884.0)) + t10 * (t121 - 9396.0))
                - t8 * (((-t117 - t171) + t261) + 2610.0)) + xi * (((t3 * 1458.0
      - t50) - t134) + 256.5);
    b_dv[33] = (((-t198 + t8 * ((-t62 + t153) + 1692.0)) - xi * ((-t28 + t86) +
      148.0)) - t9 * ((-t120 + t170) + 6120.0)) - t10 * (t76 - 8424.0);
    b_dv[34] = (((t197 + t8 * (t45 - 598.5)) - t9 * (((t56 - 162.0) - 972.0) -
      1242.0)) + t10 * (((t56 - 162.0) - 972.0) - 2592.0)) - xi * (t15 - 49.5);
    b_dv[35] = (((-t78 + t94) - t95) + t195) - t314;
    b_dv[36] = (((t78 - t94) + t95) - t195) + t314;
    b_dv[37] = ((t335 - t9 * (t56 - 162.0)) + t8 * (t45 - 49.5)) - xi * (t15 -
      4.5);
    f_shape_funcs_tmp = t9 * ((-t54 + t170) + 72.0);
    b_dv[38] = (-t8 * ((-t46 + t153) + 36.0) + xi * ((-t19 + t86) + 4.0)) +
      f_shape_funcs_tmp;
    b_dv[39] = t360 + xi * (((t3 * 486.0 - t21) - t134) + 4.5);
    d_shape_funcs_tmp = xi * ((((-t26 + t3 * 1134.0) + t155) - t162) + 7.2);
    b_dv[40] = d_shape_funcs_tmp;
    b_dv[41] = (((((eta * -194.4 + t3 * 1404.0) - t4 * 4104.0) + t182) - t322) -
                d_shape_funcs_tmp) + 7.2;
    b_dv[42] = ((((((t3 * -4144.5 + t4 * 11556.0) - t5 * 13770.0) + t45) + t185)
                 + t360) + xi * ((((t3 * 7128.0 - t4 * 14904.0) - t53) + t257) +
      49.5)) - 22.5;
    b_dv[43] = (((((((eta * -1016.0 + t3 * 6696.0) - t4 * 17424.0) - t6 * 7776.0)
                   + t271) - xi * ((((t3 * 18360.0 - t4 * 33696.0) - t61) + t271)
      + 148.0)) - f_shape_funcs_tmp) + t8 * (((-t62 + t266) - t267) + 180.0)) +
      40.0;
    b_dv[44] = ((((((((eta * 1053.0 - t3 * 6223.5) + t4 * 14796.0) - t5 *
                     15390.0) + t185) + t335) + t9 * ((-t75 + t263) + 486.0)) +
                 t8 * (((t117 + t274) - t275) - 535.5)) + xi * ((((t3 * 23652.0
      - t4 * 37584.0) - t71) + t271) + 256.5)) - 45.0;
    b_dv[45] = (((((((((eta * -626.4 + t3 * 3132.0) - t4 * 6696.0) + t5 * 6480.0)
                     - t314) - t322) - xi * ((((t3 * 15066.0 - t4 * 20736.0) -
      t66) + t257) + 313.2)) - t9 * ((-t120 + t263) + 1674.0)) + t8 * (((-t119 +
      t273) - t267) + 1044.0)) - t10 * (t64 - 1296.0)) + 36.0;
    b_dv[46] = (((t197 + t9 * ((eta * -34992.0 + t279) + 6426.0)) + t10 * (t122
      - 5832.0)) + xi * ((((t3 * 19278.0 - t73) + t257) - t274) + 540.0)) + t8 *
      (((eta * 25704.0 + t277) - t282) - 3078.0);
    b_dv[47] = (((-t198 - t9 * ((eta * -42768.0 + t279) + 9612.0)) + t8 *
                 (((-t124 + t279) - t267) + 3492.0)) - t10 * (t125 - 10368.0)) -
      xi * (((t3 * 4860.0 - t60) - t162) + 360.0);
    b_dv[48] = (((t198 + xi * ((-t48 + t133) + 180.0)) + t9 * ((eta * -22032.0 +
      t263) + 7020.0)) - t8 * ((-t77 + t183) + 2016.0)) + t10 * (t122 - 9072.0);
    b_dv[49] = (((-t197 - t8 * (t52 - 648.0)) + t9 * (t64 - 2538.0)) - t10 *
                (t64 - 3888.0)) + xi * (t22 - 54.0);
    b_dv[50] = ((t339 + t8 * ((-t68 + t183) + 360.0)) - t9 * ((eta * -12960.0 +
      t263) + 972.0)) - xi * ((-t31 + t133) + 36.0);
    f_shape_funcs_tmp = (-t64 + t263) + 216.0;
    b_dv[51] = (-t9 * f_shape_funcs_tmp + t8 * (((-t68 + t270) - t267) + 252.0))
      + xi * (((t47 + t162) - t164) - 36.0);
    b_dv[52] = t8 * (((-t52 + t183) - t191) + 54.0) - xi * ((((t3 * 7614.0 - t54)
      + t257) - t267) + 54.0);
    b_dv[53] = (t9 * f_shape_funcs_tmp + t8 * (((t77 + t277) - t278) - 396.0)) +
      xi * ((((t3 * 21060.0 - t4 * 36288.0) - t65) + t271) + 180.0);
    b_dv[54] = ((t339 - t9 * ((-t125 + t279) + 1620.0)) - xi * ((((t3 * 28836.0
      - t4 * 41472.0) - t74) + t271) + 360.0)) + t8 * (((t4 * -46656.0 - t124) +
      t283) + 1332.0);
    b_dv[55] = ((t9 * ((eta * -27216.0 + t279) + 1944.0) + xi * (((-t58 + t183)
      - t171) + 135.0)) + t10 * (t121 - 972.0)) + t8 * (((eta * 17496.0 + t274)
      - t281) - 1107.0);
    i = 0;
    i1 = 0;
    for (int i2{0}; i2 < 56; i2++) {
      deriv[i1 + (i << 1)] = b_dv[i2];
      i++;
      if (i > 27) {
        i = 0;
        i1++;
      }
    }
  }

  static inline
  void tri_6(double xi, double eta, double shape_funcs[6], double deriv
                    [12])
  {
    double b_dv[12];
    double shape_funcs_tmp;
    double t12;
    double t2;
    double t3;
    double t4;
    double t5;
    double t8;
    double t9;
    int i;
    int i1;

    // TRI_6   Quadratic triangular element
    t2 = eta * 4.0;
    t3 = eta * eta;
    t4 = 4.0 * xi;
    t5 = xi * xi;
    t8 = t3 * 2.0;
    t9 = t5 * 2.0;
    shape_funcs[0] = (((eta * -3.0 + t8) + t9) + (t2 - 3.0) * xi) + 1.0;
    shape_funcs[1] = t9 + -xi;
    shape_funcs[2] = -eta + t8;
    shape_funcs[3] = t5 * -4.0 - xi * ((t2 - 3.0) - 1.0);
    shape_funcs_tmp = t2 * xi;
    shape_funcs[4] = shape_funcs_tmp;
    shape_funcs[5] = (t2 - t3 * 4.0) - shape_funcs_tmp;
    t12 = t4 + (t2 - 3.0);
    b_dv[0] = t12;
    b_dv[1] = t4 - 1.0;
    b_dv[2] = 0.0;
    b_dv[3] = (-t2 + 4.0) + -8.0 * xi;
    b_dv[4] = t2;
    b_dv[5] = -t2;
    b_dv[6] = t12;
    b_dv[7] = 0.0;
    b_dv[8] = t2 - 1.0;
    b_dv[9] = -t4;
    b_dv[10] = t4;
    b_dv[11] = (eta * -8.0 - t4) + 4.0;
    i = 0;
    i1 = 0;
    for (int i2{0}; i2 < 12; i2++) {
      deriv[i1 + (i << 1)] = b_dv[i2];
      i++;
      if (i > 5) {
        i = 0;
        i1++;
      }
    }
  }

  static inline
  void tri_fek_21(double xi, double eta, double shape_funcs[21], double
    deriv[42])
  {
    double b_dv[42];
    double shape_funcs_tmp;
    double t105;
    double t106;
    double t118;
    double t12;
    double t133;
    double t135;
    double t137;
    double t138;
    double t139;
    double t14;
    double t140;
    double t141;
    double t142;
    double t144;
    double t145;
    double t147;
    double t148;
    double t149;
    double t150;
    double t152;
    double t153;
    double t155;
    double t17;
    double t19;
    double t2;
    double t3;
    double t32;
    double t34;
    double t38;
    double t4;
    double t5;
    double t50;
    double t51;
    double t58;
    double t6;
    double t61;
    double t69;
    double t7;
    double t72;
    double t76;
    double t78;
    double t8;
    double t9;
    double t90;
    int i;
    int i1;

    // TRI_FEK_21
    t2 = eta * eta;
    t3 = std::pow(eta, 3.0);
    t5 = std::pow(eta, 5.0);
    t6 = xi * xi;
    t7 = std::pow(xi, 3.0);
    t9 = std::pow(xi, 5.0);
    t12 = eta * 158.47675323169219;
    t19 = eta * 9.7574705142608167;
    t32 = eta * 9.7574724278917913;
    t34 = eta * 58.766509099728218;
    t72 = eta * 6.9929893470511049;
    t4 = t2 * t2;
    t8 = t6 * t6;
    t14 = t3 * 38.656864441892587;
    t17 = t2 * 114.9523599108952;
    t50 = t2 * 501.0383602766729;
    t51 = t3 * 219.77714320924181;
    t58 = t2 * 78.177891422146445;
    t61 = t2 * 59.661714239606852;
    t76 = t3 * 615.912032868982;
    t78 = t3 * 8.283033119707266;
    t90 = t2 * 20.6808809158801;
    t105 = t3 * 73.5500273661704;
    t38 = t4 * 259.3504259543372;
    t69 = t4 * 168.87507294402059;
    t106 = t4 * 17.5289863692744;
    t118 = t4 * 3.3629537739789779;
    t133 = t4 * 0.059449288784265218;
    t135 = ((-(eta * 165.531655671499) + t4 * 503.723998492346) + t2 *
            758.25291463129508) - t3 * 1093.745430525091;
    t138 = ((eta * 4.3123121299698246 + t4 * 194.71447113380921) + t2 *
            36.294567342544347) - t3 * 227.24897533255159;
    t139 = ((t2 * 539.2452152301305 - eta * 58.766508887052467) + t4 *
            480.47870136891868) - t3 * 960.95740771199667;
    t144 = ((t4 * 15.0470457728708 + eta * 23.816927190137161) - t3 *
            30.09409634718623) - t2 * 8.7698766158217314;
    t145 = ((t2 * 38.196832699950562 + t4 * 31.62678644092809) - eta *
            3.9015526060694552) - t3 * 73.994441243849664;
    t149 = ((-(t2 * 3.8115266118404421) - eta * 6.9929879354500288) + t3 *
            8.0452381998915747) + t4 * 0.059449686339120858;
    t150 = (((t2 * 432.09689290318221 - eta * 165.53165630672831) + t4 *
             168.87506281297121) - t3 * 455.72313144010189) + 20.28283203067684;
    t153 = (((eta * 22.984068642502891 + t4 * 31.626785689213641) - t3 *
             52.512698294878938) + t2 * 5.9742187127844231) - 8.0723747496220071;
    t137 = ((eta * 203.7175142733243 + t3 * 1004.795367380717) - t2 *
            796.065492393157) - t4 * 412.44738926088382;
    t140 = ((eta * 22.984066639874129 + t3 * 729.18719012966551) - t4 *
            411.12280127618533) - t2 * 345.53782523574722;
    t141 = ((eta * 23.816931829146689 + t3 * 644.99423710362942) - t2 *
            256.36376105295938) - t4 * 412.44740787981681;
    t142 = ((-(t2 * 106.19214799746121) + eta * 14.948325572951889) + t3 *
            108.7728104063407) - t4 * 17.52898798183136;
    t147 = ((eta * 5.2655734330098491 + t3 * 85.489683895937034) - t2 *
            41.404824627705331) - t4 * 49.350433184761137;
    t148 = ((-(eta * 3.9015528921734441) + t2 * 16.539686149758889) + t3 *
            0.89507485045248036) - t4 * 9.0438386535819753;
    t152 = (((eta * 4.3123102982361914 + t3 * 35.280277206286293) - t2 *
             35.038119035572748) - t4 * 9.0438378107945585) + 4.48936934184483;
    t155 = (((eta * 5.2655724470594807 + t3 * 1.17133699076664) - t4 *
             0.58566903271396931) - t2 * 5.8512403112366034) +
      0.99999990873039446;
    shape_funcs[0] = ((((((eta * -14.99999996093378 + t2 * 70.000000043594426) -
                          t3 * 140.00000069119289) + t4 * 126.00000118660719) -
                        t5 * 42.000000578074953) + (t9 * -42.000000578074953 -
      t6 * (((eta * 501.03836594588762 - t2 * 979.2384142321639) + t3 *
             567.46562017083636) - 70.000000043594426))) + (-t7 * ((eta *
      -615.91204519235646 + t2 * 567.46562682499621) + 140.00000069119289) + t8 *
      (126.00000118660719 - eta * 259.350432608497))) + (-xi * ((((-t12 + t38) +
      t50) - t76) + 14.99999996093378) + 1.0);
    shape_funcs[1] = ((t9 * 41.999996744751463 + t7 * ((eta * 85.4896695594327 -
      t2 * 49.936086496039259) + 55.999994971562742)) + -t6 * (((eta *
      41.404815986822911 - t2 * 37.31057321815981) + t3 * 1.1713318154662049) +
      13.9999986831593)) + (-t8 * (eta * 49.3504265093239 + 83.999992941885282)
      + t155 * xi);
    shape_funcs_tmp = eta * t8;
    shape_funcs[2] = (((((eta * 0.99999990873039446 - t2 * 13.9999986831593) +
                         t3 * 55.999994971562742) - t4 * 83.999992941885282) +
                       t5 * 41.999996744751463) + (t7 * (eta * 1.171338936250347
      - t2 * 1.171345087298086) - t6 * ((eta * 5.8512432633420781 - t2 *
      37.310596177734048) + t3 * 49.936106568217468))) + (shape_funcs_tmp *
      -0.58566901725445342 + t147 * xi);
    shape_funcs[3] = ((t9 * 100.0722138247298 + t150 * xi) + t7 * ((eta *
      -1093.745456707268 + t2 * 876.047007761566) + 299.68786372166522)) + (t8 *
      (eta * 503.724012222635 - 288.46092311906341) + t6 * (((eta *
      758.25292771841168 - t2 * 1260.94822700582) + t3 * 641.27027217663192) -
      131.5819864580084));
    shape_funcs[4] = ((t9 * -121.16746050312111 - t6 * (((eta *
      345.53784249318568 - t2 * 347.431653622072) + t3 * 96.490494851178525) -
      98.4982376625818)) + t153 * xi) + (-t7 * ((eta * -729.18722046838968 + t2 *
      418.07263639737079) + 289.45744183702578) + t8 * (320.19903942718707 - eta
      * 411.1228163600997));
    shape_funcs[5] = (((t9 * 121.1674595220625 + t152 * xi) + t8 * (eta *
      194.7144862177235 - 285.63825840592062)) + -t7 * ((eta *
      227.24900532948541 + t2 * 14.744022856687319) - 220.33588286127019)) + t6 *
      (((eta * 36.294584087297487 + t2 * 125.2963091978737) - t3 *
        97.334887363142926) - 60.354453319256983);
    shape_funcs[6] = (((t9 * -100.07220901034781 - xi * ((((t19 + t78) - t90) -
      t133) + 2.6998265706962861)) + t8 * (eta * 3.362940043690628 +
      211.90013385307509)) + -t7 * ((eta * 73.549998627191727 - t2 *
      138.1268855895085) + 146.56629902627949)) + t6 * (((eta *
      59.661697317285572 - t2 * 124.8580947822738) + t3 * 34.751185824254406) +
      37.438200754248463);
    shape_funcs[7] = ((shape_funcs_tmp * 168.8750641653038 + t149 * xi) + t6 *
                      ((eta * 78.177879204274376 + t2 * 3.5312016284685912) - t3
                       * 34.513406789988778)) + -t7 * (eta * 219.77712360339709
      - t2 * 34.2299973222599);
    shape_funcs[8] = ((t6 * ((eta * 38.19683453567891 - t2 * 164.02313793713921)
      + t3 * 61.159538200408868) + shape_funcs_tmp * 31.626785739127421) + t148 *
                      xi) + -t7 * (eta * 73.994442101093085 - t2 *
      222.9976218462748);
    shape_funcs[9] = ((t6 * ((eta * 16.539683375822719 - t2 * 164.02311934846031)
      + t3 * 222.99760789847451) - shape_funcs_tmp * 9.0438390209894948) + t145 *
                      xi) + t7 * (eta * 0.89507768875444382 + t2 *
      61.1595234376381);
    shape_funcs[10] = (shape_funcs_tmp * 0.0594497062682195 + t6 * ((eta *
      -3.8115218172848242 + t2 * 3.531164804550972) + t3 * 34.230028932840327))
      + (t7 * (eta * 8.0452348138553678 - t2 * 34.513384301883271) - xi * (((t51
            - t58) - t69) + t72));
    shape_funcs[11] = (((((eta * -2.6998265706962861 + t2 * 37.438200754248463)
                          - t3 * 146.56629902627949) + t4 * 211.90013385307509)
                        - t5 * 100.07220901034781) + ((shape_funcs_tmp *
      0.059449220453796657 + t6 * ((eta * 20.680886082046751 - t2 *
      124.8581354105028) + t3 * 138.12692168679979)) - xi * (((t32 - t61) + t105)
      - t118))) + -t7 * (eta * 8.2830363039124748 - t2 * 34.751208122926933);
    shape_funcs[12] = (((((eta * 4.48936934184483 - t2 * 60.354453319256983) +
                          t3 * 220.33588286127019) - t4 * 285.63825840592062) +
                        t5 * 121.1674595220625) + ((shape_funcs_tmp *
      -9.0438373770265414 + t138 * xi) - t6 * ((eta * 35.038122559562566 - t2 *
      125.29633973252039) + t3 * 14.744051869972671))) + t7 * (eta *
      35.280278464774462 - t2 * 97.334900858745925);
    shape_funcs[13] = (((((eta * -8.0723747496220071 + t2 * 98.4982376625818) -
                          t3 * 289.45744183702578) + t4 * 320.19903942718707) -
                        t5 * 121.16746050312111) + ((shape_funcs_tmp *
      31.626786409990419 + t140 * xi) + t6 * ((eta * 5.974223733109298 + t2 *
      347.43161911110519) - t3 * 418.07260507499558))) + -t7 * (eta *
      52.512702033351843 + t2 * 96.490477891940969);
    shape_funcs[14] = ((((((eta * 20.28283203067684 - t2 * 131.5819864580084) +
      t3 * 299.68786372166522) - t4 * 288.46092311906341) + t5 *
                         100.0722138247298) + shape_funcs_tmp *
                        168.8750715180154) + t135 * xi) + (t6 * ((eta *
      432.09689893053269 - t2 * 1260.9482161229371) + t3 * 876.04698893770114) -
      t7 * (eta * 455.72314680772593 - t2 * 641.27027578810021));
    shape_funcs[15] = ((shape_funcs_tmp * -412.44742060142181 + t137 * xi) - t6 *
                       ((eta * 796.06551909468533 - t2 * 2024.637859421618) + t3
                        * 1252.389265741308)) + t7 * (eta * 1004.795425422783 -
      t2 * 1252.3892970818461);
    shape_funcs[16] = ((shape_funcs_tmp * 480.478701368921 - xi * (((t14 - t17)
      + t34) + t106)) + t6 * ((eta * 539.24521586815956 - t2 * 1017.143284128235)
      + t3 * 462.94974017936221)) + -t7 * (eta * 960.95740813735233 - t2 *
      960.95742791755754);
    shape_funcs[17] = ((shape_funcs_tmp * -412.44737653928109 + t144 * xi) + t7 *
                       (eta * 644.994169783548 - t2 * 397.40029868232182)) + t6 *
      ((eta * -256.36372043440412 + t2 * 202.4526648129922) + t3 *
       30.09412362983015);
    shape_funcs[18] = (-t6 * ((eta * 106.1921467733297 - t2 * 698.02432520425771)
      + t3 * 533.065669561202) - shape_funcs_tmp * 17.528986545024448) + (t7 *
      (eta * 108.7728077454023 - t2 * 533.065668124395) + t142 * xi);
    shape_funcs[19] = ((shape_funcs_tmp * 15.0470457728708 + t141 * xi) - t7 *
                       (eta * 30.094087069166889 - t2 * 30.0940609487558)) + -t6
      * ((eta * 8.7698905328506118 - t2 * 202.45277275163161) + t3 *
         397.40039270393191);
    shape_funcs[20] = ((t6 * ((eta * 114.9523580487364 - t2 * 1017.14327917978)
      + t3 * 960.95742504393706) - shape_funcs_tmp * 17.52898780608146) + t139 *
                       xi) + -t7 * (eta * 38.656861355602437 - t2 *
      462.94973586893678);
    b_dv[0] = ((t8 * -210.0000028903747 + ((((t12 - t38) + t76) - t50) -
      14.99999996093378)) - t6 * ((eta * -1847.736135577069 + t2 *
      1702.3968804749891) + 420.00000207357863)) + (-xi * (((eta *
      1002.076731891775 - t2 * 1958.476828464328) + t3 * 1134.9312403416729) -
      140.00000008718891) + t7 * (504.0000047464286 - eta * 1037.401730433988));
    b_dv[1] = ((t8 * 209.99998372375731 + t155) - xi * (((eta *
      82.809631973645821 - t2 * 74.62114643631962) + t3 * 2.34266363093241) +
                27.9999973663186)) + (-t7 * (eta * 197.40170603729561 +
      335.99997176754113) + t6 * ((eta * 256.46900867829811 - t2 *
      149.80825948811781) + 167.99998491468821));
    shape_funcs_tmp = eta * t7;
    b_dv[2] = ((t147 - xi * ((eta * 11.70248652668416 - t2 * 74.6211923554681) +
      t3 * 99.872213136434937)) - shape_funcs_tmp * 2.3426760690178141) + t6 *
      (eta * 3.51401680875104 - t2 * 3.514035261894259);
    b_dv[3] = (((t8 * 500.361069123649 + t150) + t6 * ((eta *
      -3281.2363701218019 + t2 * 2628.1410232846979) + 899.06359116499561)) + t7
               * (eta * 2014.89604889054 - 1153.8436924762541)) + xi * (((eta *
      1516.5058554368229 - t2 * 2521.89645401164) + t3 * 1282.5405443532641) -
      263.16397291601692);
    b_dv[4] = ((t8 * -605.83730251560542 + t153) - xi * (((eta *
      691.07568498637147 - t2 * 694.86330724414393) + t3 * 192.980989702357) -
                196.9964753251636)) + (-t6 * ((eta * -2187.5616614051692 + t2 *
      1254.217909192113) + 868.37232551107729) + t7 * (1280.7961577087481 - eta *
      1644.491265440399));
    b_dv[5] = (((t8 * 605.8372976103127 + t152) + t7 * (eta * 778.85794487089413
      - 1142.553033623682)) + xi * (((eta * 72.589168174594974 + t2 *
      250.59261839574751) - t3 * 194.66977472628591) - 120.708906638514)) + -t6 *
      ((eta * 681.74701598845627 + t2 * 44.232068570061969) - 661.00764858381058);
    b_dv[6] = (((t8 * -500.36104505173881 + ((((-t19 + t90) - t78) + t133) -
      2.6998265706962861)) + t7 * (eta * 13.45176017476251 + 847.60053541230025))
               + -t6 * ((eta * 220.64999588157519 - t2 * 414.38065676852551) +
                        439.6988970788384)) + xi * (((eta * 119.3233946345711 -
      t2 * 249.71618956454759) + t3 * 69.502371648508827) + 74.876401508496926);
    b_dv[7] = ((t149 + shape_funcs_tmp * 675.5002566612153) + xi * ((eta *
      156.35575840854881 + t2 * 7.0624032569371824) - t3 * 69.026813579977556))
      + -t6 * (eta * 659.3313708101914 - t2 * 102.6899919667797);
    b_dv[8] = ((t148 + xi * ((eta * 76.39366907135782 - t2 * 328.04627587427842)
      + t3 * 122.31907640081771)) + shape_funcs_tmp * 126.5071429565097) + -t6 *
      (eta * 221.98332630327931 - t2 * 668.99286553882428);
    b_dv[9] = ((t145 - shape_funcs_tmp * 36.175356083957979) + xi * ((eta *
      33.079366751645438 - t2 * 328.04623869692062) + t3 * 445.99521579694908))
      + t6 * (eta * 2.685233066263331 + t2 * 183.47857031291429);
    b_dv[10] = (((((t58 + t69) - t51) - t72) + shape_funcs_tmp *
                 0.237798825072878) + t6 * (eta * 24.1357044415661 - t2 *
      103.5401529056498)) + xi * ((eta * -7.6230436345696484 + t2 *
      7.0623296091019441) + t3 * 68.460057865680653);
    b_dv[11] = (((((t61 - t32) + t118) - t105) + shape_funcs_tmp *
                 0.23779688181518671) + xi * ((eta * 41.361772164093509 - t2 *
      249.71627082100551) + t3 * 276.25384337359969)) + -t6 * (eta *
      24.849108911737432 - t2 * 104.25362436878081);
    b_dv[12] = ((t138 - shape_funcs_tmp * 36.175349508106173) + t6 * (eta *
      105.84083539432341 - t2 * 292.00470257623778)) + -xi * ((eta *
      70.076245119125147 - t2 * 250.5926794650409) + t3 * 29.488103739945341);
    b_dv[13] = ((t140 + shape_funcs_tmp * 126.50714563996171) + xi * ((eta *
      11.9484474662186 + t2 * 694.8632382222105) - t3 * 836.14521014999127)) +
      -t6 * (eta * 157.5381061000555 + t2 * 289.47143367582288);
    b_dv[14] = ((t135 + shape_funcs_tmp * 675.5002860720615) - t6 * (eta *
      1367.169440423178 - t2 * 1923.8108273643011)) + xi * ((eta *
      864.19379786106549 - t2 * 2521.8964322458742) + t3 * 1752.0939778754021);
    b_dv[15] = ((t137 - shape_funcs_tmp * 1649.789682405687) + t6 * (eta *
      3014.3862762683489 - t2 * 3757.1678912455382)) + -xi * ((eta *
      1592.1310381893711 - t2 * 4049.2757188432361) + t3 * 2504.778531482616);
    b_dv[16] = (((((t17 - t14) - t34) - t106) + shape_funcs_tmp *
                 1921.914805475684) + xi * ((eta * 1078.4904317363189 - t2 *
      2034.28656825647) + t3 * 925.89948035872442)) + -t6 * (eta *
      2882.8722244120572 - t2 * 2882.872283752673);
    b_dv[17] = ((t144 - shape_funcs_tmp * 1649.7895061571239) + xi * ((eta *
      -512.72744086880823 + t2 * 404.90532962598451) + t3 * 60.188247259660287))
      + t6 * (eta * 1934.982509350644 - t2 * 1192.200896046965);
    b_dv[18] = ((t142 - xi * ((eta * 212.38429354665939 - t2 * 1396.048650408515)
      + t3 * 1066.1313391224039)) - shape_funcs_tmp * 70.115946180097808) + t6 *
      (eta * 326.3184232362068 - t2 * 1599.1970043731851);
    b_dv[19] = ((t141 - xi * ((eta * 17.53978106570122 - t2 * 404.90554550326328)
      + t3 * 794.80078540786383)) + shape_funcs_tmp * 60.188183091483218) + -t6 *
      (eta * 90.282261207500667 - t2 * 90.282182846267389);
    b_dv[20] = ((t139 + xi * ((eta * 229.9047160974728 - t2 * 2034.28655835956)
      + t3 * 1921.9148500878739)) - t6 * (eta * 115.97058406680731 - t2 *
      1388.849207606811)) + shape_funcs_tmp * -70.11595122432584;
    b_dv[21] = ((((((eta * 140.00000008718891 - t2 * 420.00000207357863) + t3 *
                    504.0000047464286) - t4 * 210.0000028903747) - t8 *
                  259.350432608497) + -t6 * ((eta * -1958.476828464328 + t2 *
      1702.396860512509) + 501.03836594588762)) + -xi * (((eta *
      1002.076720553346 - t2 * 1847.7360986069459) + t3 * 1037.401703817349) -
      158.47675323169219)) + (t7 * (615.91204519235646 - eta * 1134.931253649992)
      - 14.99999996093378);
    b_dv[22] = ((t8 * -49.3504265093239 + t7 * (85.4896695594327 - eta *
      99.872172992078518)) + -t6 * ((eta * -74.62114643631962 + t2 *
      3.5139954463986149) + 41.404815986822911)) + -xi * (((eta *
      11.70248062247321 - t2 * 3.5140109722999191) + t3 * 2.3426761308558768) -
      5.2655724470594807);
    b_dv[23] = ((((((eta * -27.9999973663186 + t2 * 167.99998491468821) - t3 *
                    335.99997176754113) + t4 * 209.99998372375731) - t8 *
                  0.58566901725445342) + t7 * (1.171338936250347 - eta *
      2.3426901745961728)) + -xi * (((eta * 82.809649255410662 - t2 *
      256.46905168781109) + t3 * 197.4017327390446) - 5.2655734330098491)) +
      (-t6 * ((eta * -74.6211923554681 + t2 * 149.8083197046524) +
              5.8512432633420781) + 0.99999990873039446);
    b_dv[24] = (t8 * 503.724012222635 + t6 * ((eta * -2521.89645401164 + t2 *
      1923.8108165298961) + 758.25292771841168)) + (xi * (((eta *
      864.1937858063643 - t2 * 1367.1693943203061) + t3 * 675.50025125188472) -
      165.53165630672831) + t7 * (eta * 1752.0940155231319 - 1093.745456707268));
    b_dv[25] = ((t8 * -411.1228163600997 - t6 * ((eta * -694.86330724414393 + t2
      * 289.47148455353562) + 345.53784249318568)) + xi * (((eta *
      11.94843742556885 - t2 * 157.53809488463679) + t3 * 126.50714275685461) +
      22.984068642502891)) + t7 * (729.18722046838968 - eta * 836.14527279474169);
    b_dv[26] = ((t8 * 194.7144862177235 + t6 * ((eta * 250.59261839574751 - t2 *
      292.00466208942879) + 36.294584087297487)) + -xi * (((eta *
      70.0762380711455 - t2 * 105.8408316188589) + t3 * 36.175351243178227) -
      4.3123102982361914)) + -t7 * (eta * 29.48804571337465 + 227.24900532948541);
    b_dv[27] = ((t8 * 3.362940043690628 + t6 * ((eta * -249.71618956454759 + t2 *
      104.25355747276321) + 59.661697317285572)) + xi * (((eta *
      41.361761831760212 - t2 * 24.8490993591218) + t3 * 0.2377971551370609) -
      9.7574705142608167)) + t7 * (eta * 276.253771179017 - 73.549998627191727);
    b_dv[28] = ((t8 * 168.8750641653038 + t6 * ((eta * 7.0624032569371824 - t2 *
      103.54022036996631) + 78.177879204274376)) + -xi * (((eta *
      7.6230532236808841 - t2 * 24.135714599674731) - t3 * 0.23779874535648349)
      + 6.9929879354500288)) + t7 * (eta * 68.4599946445198 - 219.77712360339709);
    b_dv[29] = ((t8 * 31.626785739127421 + t6 * ((eta * -328.04627587427842 + t2
      * 183.47861460122661) + 38.19683453567891)) + xi * (((eta *
      33.079372299517772 + t2 * 2.6852245513574409) - t3 * 36.1753546143279) -
      3.9015528921734441)) + t7 * (eta * 445.99524369254948 - 73.994442101093085);
    b_dv[30] = ((t8 * -9.0438390209894948 + t7 * (eta * 122.3190468752762 +
      0.89507768875444382)) + t6 * ((eta * -328.04623869692062 + t2 *
      668.99282369542368) + 16.539683375822719)) + xi * (((eta *
      76.393665399901124 - t2 * 221.983323731549) + t3 * 126.5071457637124) -
      3.9015526060694552);
    b_dv[31] = ((t8 * 0.0594497062682195 + t6 * ((eta * 7.0623296091019441 + t2 *
      102.690086798521) - 3.8115218172848242)) + xi * (((eta *
      156.35578284429289 - t2 * 659.33142962772547) + t3 * 675.50029177608224) -
      6.9929893470511049)) + t7 * (8.0452348138553678 - eta * 69.026768603766541);
    b_dv[32] = (((((eta * 74.876401508496926 - t2 * 439.6988970788384) + t3 *
                   847.60053541230025) - t4 * 500.36104505173881) + t8 *
                 0.059449220453796657) + (t7 * (eta * 69.502416245853865 -
      8.2830363039124748) + t6 * ((eta * -249.71627082100551 + t2 *
      414.3807650603996) + 20.680886082046751))) + (xi * (((eta *
      119.3234284792137 - t2 * 220.65008209851121) + t3 * 13.45181509591591) -
      9.7574724278917913) - 2.6998265706962861);
    b_dv[33] = ((((((eta * -120.708906638514 + t2 * 661.00764858381058) - t3 *
                    1142.553033623682) + t4 * 605.8372976103127) - t8 *
                  9.0438373770265414) + -t6 * ((eta * -250.5926794650409 + t2 *
      44.23215560991801) + 35.038122559562566)) + xi * (((eta * 72.5891346850887
      - t2 * 681.74692599765467) + t3 * 778.85788453523685) + 4.3123121299698246))
      + (t7 * (35.280278464774462 - eta * 194.66980171749191) + 4.48936934184483);
    b_dv[34] = ((((((eta * 196.9964753251636 - t2 * 868.37232551107729) + t3 *
                    1280.7961577087481) - t4 * 605.83730251560542) + t8 *
                  31.626786409990419) + t6 * ((eta * 694.8632382222105 - t2 *
      1254.2178152249869) + 5.974223733109298)) + -xi * (((eta *
      691.07565047149433 - t2 * 2187.5615703889962) + t3 * 1644.4912051047411) -
      22.984066639874129)) + (-t7 * (eta * 192.98095578388191 +
      52.512702033351843) - 8.0723747496220071);
    b_dv[35] = (((((eta * -263.16397291601692 + t2 * 899.06359116499561) - t3 *
                   1153.8436924762541) + t4 * 500.361069123649) + t8 *
                 168.8750715180154) + xi * (((eta * 1516.50582926259 - t2 *
      3281.2362915752742) + t3 * 2014.8959939693841) - 165.531655671499)) + ((t6
      * ((eta * -2521.8964322458742 + t2 * 2628.1409668131032) +
         432.09689893053269) + t7 * (eta * 1282.5405515762 - 455.72314680772593))
      + 20.28283203067684);
    b_dv[36] = (t8 * -412.44742060142181 - t6 * ((eta * -4049.2757188432361 + t2
      * 3757.167797223924) + 796.06551909468533)) + (-xi * (((eta *
      1592.130984786314 - t2 * 3014.38610214215) + t3 * 1649.7895570435351) -
      203.7175142733243) + t7 * (1004.795425422783 - eta * 2504.7785941636921));
    b_dv[37] = (t8 * 480.478701368921 - xi * (((eta * -229.90471982179039 + t2 *
      115.9705933256778) + t3 * 70.115945477097611) + 58.766509099728218)) + (t6
      * ((eta * -2034.28656825647 + t2 * 1388.849220538086) + 539.24521586815956)
      + t7 * (eta * 1921.9148558351151 - 960.95740813735233));
    b_dv[38] = ((t8 * -412.44737653928109 + t6 * ((eta * 404.90532962598451 + t2
      * 90.282370889490437) - 256.36372043440412)) + -xi * (((eta *
      17.539753231643459 + t2 * 90.2822890415587) - t3 * 60.188183091483211) -
      23.816927190137161)) + t7 * (644.994169783548 - eta * 794.80059736464364);
    b_dv[39] = (t8 * -17.528986545024448 - xi * (((eta * 212.3842959949225 - t2 *
      326.3184312190221) + t3 * 70.115951927325426) - 14.948325572951889)) + (t7
      * (108.7728077454023 - eta * 1066.13133624879) - t6 * ((eta *
      -1396.048650408515 + t2 * 1599.1970086836061) + 106.1921467733297));
    b_dv[40] = ((t8 * 15.0470457728708 - t6 * ((eta * -404.90554550326328 + t2 *
      1192.201178111796) + 8.7698905328506118)) + t7 * (eta * 60.188121897511593
      - 30.094087069166889)) + -xi * (((eta * 512.72752210591875 - t2 *
      1934.9827113108879) + t3 * 1649.789631519267) - 23.816931829146689);
    b_dv[41] = (t8 * -17.52898780608146 + xi * (((eta * 1078.490430460261 - t2 *
      2882.87222313599) + t3 * 1921.9148054756749) - 58.766508887052467)) + (t6 *
      ((eta * -2034.28655835956 + t2 * 2882.872275131811) + 114.9523580487364) +
      t7 * (eta * 925.89947173787368 - 38.656861355602437));
    i = 0;
    i1 = 0;
    for (int i2{0}; i2 < 42; i2++) {
      deriv[i1 + (i << 1)] = b_dv[i2];
      i++;
      if (i > 20) {
        i = 0;
        i1++;
      }
    }
  }

  static inline
  void tri_fek_28(double xi, double eta, double shape_funcs[28], double
    deriv[56])
  {
    double b_dv[56];
    double shape_funcs_tmp;
    double t10;
    double t100;
    double t101;
    double t102;
    double t104;
    double t105;
    double t106;
    double t107;
    double t11;
    double t111;
    double t112;
    double t121;
    double t123;
    double t127;
    double t129;
    double t131;
    double t132;
    double t134;
    double t139;
    double t140;
    double t141;
    double t145;
    double t146;
    double t15;
    double t153;
    double t154;
    double t16;
    double t160;
    double t168;
    double t174;
    double t175;
    double t176;
    double t177;
    double t18;
    double t183;
    double t189;
    double t19;
    double t191;
    double t199;
    double t2;
    double t20;
    double t203;
    double t215;
    double t218;
    double t219;
    double t22;
    double t220;
    double t224;
    double t225;
    double t226;
    double t229;
    double t231;
    double t232;
    double t233;
    double t239;
    double t241;
    double t242;
    double t245;
    double t246;
    double t248;
    double t249;
    double t26;
    double t3;
    double t32;
    double t38;
    double t39;
    double t4;
    double t41;
    double t42;
    double t46;
    double t48;
    double t5;
    double t50;
    double t53;
    double t55;
    double t58;
    double t59;
    double t6;
    double t61;
    double t7;
    double t71;
    double t74;
    double t78;
    double t79;
    double t8;
    double t80;
    double t81;
    double t83;
    double t88;
    double t9;
    double t91;
    double t92;
    double t97;
    double t98;
    int i;
    int i1;

    // TRI_FEK_28
    t2 = eta * eta;
    t3 = std::pow(eta, 3.0);
    t5 = std::pow(eta, 5.0);
    t7 = xi * xi;
    t8 = std::pow(xi, 3.0);
    t10 = std::pow(xi, 5.0);
    t18 = eta * 57.052415531159312;
    t20 = eta * 346.03390024817378;
    t32 = eta * 31.71506767754061;
    t38 = eta * 53.678187956052838;
    t42 = eta * 26.254341105207359;
    t50 = eta * 16.819178500689809;
    t55 = eta * 124.30174448469469;
    t61 = eta * 124.3017500565313;
    t71 = eta * 16.819185060112229;
    t74 = eta * 26.254335250912121;
    t91 = eta * 11.975131280659641;
    t92 = eta * 11.9751313038326;
    t100 = eta * 8.671383657182167;
    t121 = eta * 8.6713859642770874;
    t4 = t2 * t2;
    t6 = std::pow(t2, 3.0);
    t9 = t7 * t7;
    t11 = std::pow(t7, 3.0);
    t15 = t5 * 120.9787104207699;
    t16 = t3 * 4894.8993316730339;
    t19 = t3 * 5783.6257952213673;
    t22 = t2 * 109.81390707850819;
    t26 = t3 * 522.8407767445151;
    t39 = t2 * 1671.6358010814711;
    t48 = t5 * 1978.2111800661819;
    t78 = t5 * 1587.819153861871;
    t79 = t5 * 2144.950812735502;
    t80 = t3 * 1954.5345337674889;
    t81 = t2 * 2394.6862745499839;
    t83 = t3 * 620.15130314132;
    t88 = t5 * 256.19335179468391;
    t97 = t5 * 102.1966757629833;
    t101 = t3 * 338.70733435288031;
    t102 = t2 * 400.917052595231;
    t105 = t5 * 402.42388968821808;
    t107 = t3 * 180.8365713925044;
    t111 = t3 * 403.88094381286618;
    t112 = t3 * 81.245949254646973;
    t123 = t3 * 108.679818094666;
    t127 = t5 * 102.19667108060671;
    t129 = t3 * 82.053119633529548;
    t132 = t2 * 94.866895154237142;
    t134 = t2 * 433.99625568148628;
    t139 = t2 * 122.86052577328211;
    t140 = t5 * 46.618739455097987;
    t141 = t2 * 166.13387827577691;
    t146 = t2 * 341.790720098438;
    t153 = t2 * 30.93597128483972;
    t160 = t2 * 55.474307709901709;
    t168 = t2 * 68.750078984309724;
    t174 = t3 * 68.027857680838892;
    t175 = t3 * 53.511458182855307;
    t183 = t5 * 46.618748277571207;
    t189 = t2 * 14.772229687002771;
    t199 = t2 * 8.3648022245079776;
    t203 = t5 * 1.4605149873586529;
    t215 = t3 * 0.61315937081908445;
    t218 = t5 * 2.4384153625978569E-6;
    t219 = t5 * 6.3540580719209678E-6;
    t220 = t5 * 2.3444904749865271E-6;
    t41 = t4 * 5877.2894866391443;
    t46 = t4 * 3134.6117730530809;
    t53 = t4 * 5325.7764607142763;
    t58 = t4 * 415.88131048776842;
    t59 = t4 * 310.07564828200731;
    t98 = t4 * 470.87870553555422;
    t104 = t4 * 75.9990539682934;
    t106 = t4 * 558.93177394708857;
    t131 = t4 * 157.09467730361291;
    t145 = t4 * 287.03680764175277;
    t154 = t4 * 41.02654834155657;
    t176 = t4 * 21.657401569321308;
    t177 = t4 * 40.104644838262672;
    t191 = t4 * 0.30657565325906222;
    t231 = (((t4 * 2523.232845746903 + t2 * 211.34971953373139) - t3 *
             1475.26581385022) + eta * 1.483207991314871) - t5 *
      1267.1999594377539;
    t239 = (((t4 * 9.283354498866089 + t3 * 51.275283060181692) + eta *
             2.400077366758619) - t5 * 27.24170557222828) - t2 *
      29.317009606608782;
    t241 = (((eta * 8.25486604172513 - t3 * 27.595387225284359) + t2 *
             14.24302315156161) + t4 * 10.84975227219549) - t5 *
      3.1175074843283381;
    t242 = (((t5 * 1.460509052851773 + eta * 4.0755611195914474) + t4 *
             14.35484009732564) - t2 * 19.99423271735499) - t3 *
      3.996606911555515;
    t246 = ((((t4 * 2044.525649661324 - eta * 346.03389774688537) + t2 *
              1387.7749473923229) - t3 * 2478.73789961823) - t5 *
            635.93195313199442) + 28.40315344346228;
    t224 = (((-(t2 * 2500.1282323768251) + eta * 422.51411244907769) + t3 *
             5294.2788864859931) + t5 * 1587.819101342915) - t4 *
      4804.4838679011618;
    t225 = (((t3 * 3373.905417245478 + t5 * 1978.211279366473) + eta *
             53.6781956358675) - t4 * 4565.2796430628287) - t2 *
      840.5152491849899;
    t226 = (((eta * 57.052409116386677 + t3 * 3942.8148064572952) + t5 *
             1982.3580453270761) - t2 * 1146.532744785912) - t4 *
      4831.5925864087167;
    t229 = (((eta * 18.23378199921089 + t3 * 659.39557383437523) + t5 *
             235.3688042009351) - t4 * 734.08480266559172) - t2 *
      207.31651055128651;
    t232 = (((eta * 8.25486793740524 - t4 * 1135.1340416250521) + t3 *
             659.95479397482143) + t5 * 635.93190946076982) - t2 *
      140.60437648184561;
    t233 = (((eta * 4.0755611597693218 + t5 * 120.9787002107773) + t3 *
             242.47642163095529) - t4 * 317.85671735776072) - t2 *
      61.011935747517768;
    t245 = ((((eta * 325.92607485546279 + t5 * 1048.193392010169) + t3 *
              3250.0874804666219) - t4 * 3032.0350961284139) - t2 *
            1570.171850758597) - 21.00000037073665;
    t248 = ((((t3 * 184.008369601338 + eta * 1.483201007077666) - t4 *
              126.9251895235401) - t2 * 92.208091674668879) + t5 *
            27.24171100292072) + 6.3999995868725206;
    t249 = ((((eta * 18.233776814757618 + t3 * 15.37146288022497) - t2 *
              34.619698810623063) + t5 * 3.117514826433577) - t4 *
            4.7378024362309139) + 2.634746725437807;
    shape_funcs[0] = ((((((((eta * -21.00000037073665 + t2 * 140.000003983934) -
      t3 * 420.0000148801609) + t4 * 630.00002533652253) - t5 *
                          462.0000201891209) + t6 * 132.0000061195619) + (t11 *
      132.0000061195619 + t10 * (eta * 1048.1934069073229 - 462.0000201891209)))
                       + (t8 * (((eta * 3250.0875097435451 - t2 *
      6781.3714528894607) + t3 * 4172.7330616918307) - 420.0000148801609) + t245
                          * xi)) + t9 * ((eta * -3032.0351328120928 + t2 *
      3002.5599395722) + 630.00002533652253)) + (t7 * ((((eta *
      -1570.171858248995 + t2 * 5237.654749703468) - t3 * 6781.37141522589) + t4
      * 3002.559908797999) + 140.000003983934) + 1.0);
    shape_funcs[1] = (((t11 * 131.99999628479529 - xi * (((((t100 + t191) - t199)
      - t215) + t220) + 0.99999992549419592)) + -t8 * (((eta * 403.880863763396
      - t2 * 306.85894676995508) + t3 * 4.4271830235682037) + 119.99999467250061))
                      + t7 * ((((eta * 109.8138815574714 - t2 *
      102.7429251991616) + t3 * 3.8140392696516958) - t4 * 2.213609916882298) +
      19.999998880620549)) + (-t10 * (eta * 256.19331567159082 +
      329.99998948264249) + t9 * ((eta * 558.9316810182695 - t2 *
      258.40688515216328) + 299.99998891522148));
    shape_funcs_tmp = eta * t10;
    shape_funcs[2] = ((((((eta * -0.99999992549419592 + t2 * 19.999998880620549)
                          - t3 * 119.99999467250061) + t4 * 299.99998891522148)
                        - t5 * 329.99998948264249) + ((t6 * 131.99999628479529 -
      t9 * (eta * 0.3065710434644609 + t2 * 2.213615781946046)) -
      shape_funcs_tmp * 4.3135075421904053E-6)) + (t7 * (((eta *
      8.3648089772031913 - t2 * 102.74299182296009) + t3 * 306.85910925895217) -
      t4 * 258.40698751743412) - xi * ((((-t22 + t88) - t106) + t111) + t121)))
      + t8 * ((eta * 0.6131522546389333 + t2 * 3.8140852475693672) - t3 *
              4.4272551287458661);
    shape_funcs[3] = (((t11 * -318.263670445131 + t10 * (1086.9060613246129 -
      eta * 2144.9508329317282)) - t9 * ((eta * -5877.289530233772 + t2 *
      5170.200527782521) + 1426.7203547843869)) + (t246 * xi - t8 * (((eta *
      5783.6258204709366 - t2 * 10554.885519308211) + t3 * 5817.65272301495) -
      891.54561380300618))) + -t7 * ((((eta * -2394.686273899863 + t2 *
      6843.144259931837) - t3 * 7812.145231392954) + t4 * 3110.0713108510208) +
      261.87080334156337);
    shape_funcs[4] = ((((t11 * 397.46366005821722 + t10 * (eta *
      1982.358090995197 - 1285.566156897163)) + t9 * ((eta * -4831.59270949642 +
      t2 * 3336.38036931205) + 1555.570636437717)) + -xi * (((((t15 - t18) +
      t107) - t145) + t153) + 11.337970074798079)) + t7 * ((((eta *
      -1146.532790987477 + t2 * 2120.21088817959) - t3 * 1496.7172695423119) +
      t4 * 323.55829633582022) + 195.40531326150781)) + t8 * (((eta *
      3942.8149236636709 - t2 * 5328.32008010227) + t3 * 2196.02294513166) -
      851.53548278548055);
    shape_funcs[5] = (((t11 * -422.39999074262067 + t248 * xi) + t8 * (((eta *
      -1475.2659985543071 + t2 * 437.3261831331161) + t3 * 385.13982812140267) +
      652.79997780212113)) + (t10 * (1267.199969080737 - eta * 1267.200033798342)
      - t9 * ((eta * -2523.233044940635 + t2 * 863.43013617002237) +
              1382.3999612515011))) + t7 * ((((eta * 211.34978638890971 + t2 *
      395.22883251457768) - t3 * 918.390333284306) + t4 * 431.0116322386246) -
      121.5999944756086);
    shape_funcs[6] = ((((t11 * 397.46365649899508 - xi * (((((t50 - t168) + t174)
      - t176) + t203) + 4.0999293847436764)) + t10 * (eta * 402.42398552948862 -
      1099.215787686172)) + -t8 * (((eta * 81.245738063948565 - t2 *
      1311.431065819535) + t3 * 724.80893050947145) + 464.35868026675172)) + t7 *
                      ((((eta * 122.86045607546259 - t2 * 628.37331286851054) +
                         t3 * 528.77547996309875) - t4 * 107.85419694106) +
                       80.516011536914164)) + -t9 * ((eta * 415.8815543813401 +
      t2 * 613.45491952527652) - 1089.6947293017579);
    shape_funcs[7] = ((t11 * -318.2636577738179 + (-t7 * ((((eta *
      207.31645405831409 - t2 * 375.36636075694719) + t3 * 121.09114062431109) +
      t4 * 2.7631040070869379) + 52.450529845804539) + t249 * xi)) + (t10 * (eta
      * 235.36872634414991 + 822.67592384974932) + t8 * (((eta *
      659.39540023520874 - t2 * 1037.18191947943) + t3 * 221.08534432175281) +
      311.54858099976627))) + -t9 * ((eta * 734.08460251815939 - t2 *
      780.598347273241) + 766.145063955331);
    shape_funcs[8] = (-t7 * (((eta * 140.604352625109 + t2 * 87.271936726343284)
      - t3 * 175.5426275065974) + t4 * 18.350646151093631) + ((t8 * ((eta *
      659.9547119087789 + t2 * 87.6035954040094) - t3 * 263.31295303737721) +
      shape_funcs_tmp * 635.93187054059513) + t241 * xi)) + -t9 * (eta *
      1135.133942686442 - t2 * 69.588397998904043);
    shape_funcs[9] = (((shape_funcs_tmp * 120.9787007748926 + t242 * xi) - t9 *
                       (eta * 317.85672191409208 - t2 * 928.45181388855542)) +
                      -t7 * (((eta * 61.011935580431377 - t2 *
      298.83814113303129) + t3 * 39.939367551964253) + t4 * 100.5516465669705))
      + t8 * ((eta * 242.47642568766241 - t2 * 1068.9428289060349) + t3 *
              307.99730918947438);
    shape_funcs[10] = ((shape_funcs_tmp * -27.241700656661429 + t239 * xi) - t7 *
                       (((eta * 29.317011815839521 - t2 * 379.95344634539663) +
                         t3 * 768.5227213317072) - t4 * 294.80308711961789)) +
      (t8 * ((eta * 51.275288805506243 - t2 * 768.52269424987855) + t3 *
             1066.489548430148) + t9 * (eta * 9.28334604720544 + t2 *
        294.80306141726231));
    shape_funcs[11] = (((shape_funcs_tmp * 1.460504294981618 + t233 * xi) - t8 *
                        ((eta * 3.9966104831645941 + t2 * 39.939386270622848) -
                         t3 * 307.997286389233)) + -t7 * (((eta *
      19.994231932867919 - t2 * 298.83813859928091) + t3 * 1068.942783674969) -
      t4 * 928.4517769839764)) + t9 * (eta * 14.35484741074044 - t2 *
      100.5516251522513);
    shape_funcs[12] = ((shape_funcs_tmp * -3.1175044667845131 + t9 * (eta *
      10.8497489060677 - t2 * 18.350660403768948)) + (t7 * (((eta *
      14.243018973494721 - t2 * 87.271882601249672) + t3 * 87.603426086837842) +
      t4 * 69.588514951361134) + t232 * xi)) + -t8 * ((eta * 27.59538450776342 -
      t2 * 175.54261316177929) + t3 * 263.31288656300171);
    shape_funcs[13] = ((((((eta * 2.634746725437807 - t2 * 52.450529845804539) +
      t3 * 311.54858099976627) - t4 * 766.145063955331) + t5 *
                         822.67592384974932) + (((t6 * -318.2636577738179 +
      shape_funcs_tmp * 3.1175166533020149) + t229 * xi) + t8 * ((eta *
      15.37147900872638 - t2 * 121.0912639644794) + t3 * 221.085506643802))) +
                       -t7 * (((eta * 34.619714574116877 - t2 *
      375.36651447556642) + t3 * 1037.1822699635379) - t4 * 780.59856149242717))
      + -t9 * (eta * 4.7378098125602133 + t2 * 2.7630762205703991);
    shape_funcs[14] = ((((((eta * -4.0999293847436764 + t2 * 80.516011536914164)
      - t3 * 464.35868026675172) + t4 * 1089.6947293017579) - t5 *
                         1099.215787686172) + t6 * 397.46365649899508) +
                       ((shape_funcs_tmp * -1.4605168286570711 - xi * ((((t58 +
      t71) - t105) + t112) - t139)) + t7 * (((eta * 68.750100646324313 - t2 *
      628.37350730294622) + t3 * 1311.4314758474829) - t4 * 613.455161148747)))
      + (-t8 * ((eta * 68.027883251126383 - t2 * 528.77566023530119) + t3 *
                724.80912990273237) + t9 * (eta * 21.65741387831504 - t2 *
          107.8542523934192));
    shape_funcs[15] = (((((((eta * 6.3999995868725206 - t2 * 121.5999944756086)
      + t3 * 652.79997780212113) - t4 * 1382.3999612515011) + t5 *
                          1267.199969080737) - t6 * 422.39999074262067) + -t9 *
                        (eta * 126.9252184198177 - t2 * 431.01171850151388)) +
                       ((-t7 * (((eta * 92.208120997458607 - t2 *
      395.22905456055429) - t3 * 437.32576974318681) + t4 * 863.42991308913349)
                         + shape_funcs_tmp * 27.24171768388749) + t231 * xi)) +
      t8 * ((eta * 184.00841415520139 - t2 * 918.39057491802248) + t3 *
            385.14005642362662);
    shape_funcs[16] = (((((((eta * -11.337970074798079 + t2 * 195.40531326150781)
      - t3 * 851.53548278548055) + t4 * 1555.570636437717) - t5 *
                          1285.566156897163) + t6 * 397.46366005821722) + ((t9 *
      (eta * 287.03688177576532 + t2 * 323.55819154414422) - shape_funcs_tmp *
      120.9787355126963) + t226 * xi)) + -t7 * (((eta * 30.9359338939282 - t2 *
      2120.210705280409) + t3 * 5328.3197888800078) - t4 * 3336.3802219774989))
      + -t8 * ((eta * 180.8366514107293 + t2 * 1496.717028664227) - t3 *
               2196.0227637654812);
    shape_funcs[17] = ((((((eta * 28.40315344346228 - t2 * 261.87080334156337) +
      t3 * 891.54561380300618) - t4 * 1426.7203547843869) + t5 *
                         1086.9060613246129) - t6 * 318.263670445131) + ((-t8 *
      ((eta * 2478.737975343593 - t2 * 7812.1453730480143) + t3 *
       5817.6527748319641) - shape_funcs_tmp * 635.93198379183184) - xi *
      ((((t19 + t20) - t41) + t79) - t81))) + (t9 * (eta * 2044.5257318336221 -
      t2 * 3110.0713944336958) + t7 * (((eta * 1387.7749741065149 - t2 *
      6843.1443195133361) + t3 * 10554.885532023751) - t4 * 5170.2005064804735));
    shape_funcs[18] = ((shape_funcs_tmp * 1587.819174363809 - t7 * (((eta *
      2500.12827244441 - t2 * 10762.359772764759) + t3 * 14802.08203619065) - t4
      * 6566.1048781336349)) + t224 * xi) + (t8 * ((eta * 5294.2790370055691 -
      t2 * 14802.08222351328) + t3 * 9956.5716304520774) - t9 * (eta *
      4804.4840513740464 - t2 * 6566.1050280251666));
    shape_funcs[19] = (((t9 * (eta * 5325.7764649481142 - t2 * 6082.90093282478)
                         - shape_funcs_tmp * 1978.2111911735331) - xi * ((((t55
      + t101) - t102) - t127) + t177)) + t7 * (((eta * 1671.635774048272 - t2 *
      5420.2135047918146) + t3 * 5636.0193710904659) - t4 * 1875.4665066498139))
      + -t8 * ((eta * 4894.8993033381576 - t2 * 11048.51918254353) + t3 *
               6082.3529193816676);
    shape_funcs[20] = (((-t9 * (eta * 4565.2793797560516 - t2 *
      3808.154858697053) + shape_funcs_tmp * 1978.2111819179249) - xi * ((((-t38
      + t123) - t131) + t140) + t160)) + -t7 * (((eta * 840.51516232831273 - t2 *
      1349.6541922363319) + t3 * 153.46233291480269) + t4 * 343.70156680200392))
      + t8 * ((eta * 3373.9051722103868 - t2 * 4978.0329727274784) + t3 *
              1532.860849432222);
    shape_funcs[21] = (t9 * (eta * 3134.6114614983712 - t2 * 1372.990540133439)
                       + t8 * ((eta * -1954.5342762170851 + t2 *
      1076.1089489285671) + t3 * 429.6568598829702)) + ((shape_funcs_tmp *
      -1587.819029947193 + t7 * (((eta * 433.99617991681907 - t2 *
      110.8602869191362) - t3 * 511.70991757368517) + t4 * 214.82836371515651))
      - xi * ((((t74 - t129) + t154) + t189) + t219));
    shape_funcs[22] = ((t7 * (((eta * 166.13388398557279 - t2 *
      1333.4766218118691) + t3 * 1224.2722824786531) - t4 * 110.6077346584252) -
                        shape_funcs_tmp * 102.1967068196229) - xi * ((((t91 +
      t104) - t132) + t175) - t183)) + (t9 * (eta * 470.8787734452913 - t2 *
      2386.4497730840549) - t8 * ((eta * 522.84081933058155 - t2 *
      3749.3612381234789) + t3 * 2441.4795492004282));
    shape_funcs[23] = (t7 * (((eta * 94.866902605343469 - t2 *
      1333.4766800007451) + t3 * 3749.361257146727) - t4 * 2386.4497414098491) +
                       ((-t8 * ((eta * 53.511471683125457 - t2 *
      1224.272447055612) + t3 * 2441.4796505935728) + shape_funcs_tmp *
                         46.618756103634723) - xi * ((((t26 + t92) + t97) - t98)
      - t141))) + -t9 * (eta * 75.999055722020131 + t2 * 110.60782884307309);
    shape_funcs[24] = (t8 * ((eta * 82.053119722241192 - t2 * 511.70983074170658)
      + t3 * 429.6566464640826) - t9 * (eta * 41.026555740948183 - t2 *
      214.8283779238277)) + ((shape_funcs_tmp * -5.1804845841027186E-6 - xi *
      ((((t42 - t46) + t78) + t80) - t134)) - t7 * (((eta * 14.772217695601061 +
      t2 * 110.860469059509) - t3 * 1076.109469115479) + t4 * 1372.9908905021009));
    shape_funcs[25] = (((t9 * (eta * 157.0946838168089 - t2 * 343.70149314566783)
                         - shape_funcs_tmp * 46.618745536817677) + t225 * xi) +
                       -t8 * ((eta * 108.67980570776319 + t2 * 153.4625700572644)
      - t3 * 1532.8611072511169)) + -t7 * (((eta * 55.474328208095578 - t2 *
      1349.6544420674561) + t3 * 4978.0334745024293) - t4 * 3808.1551342264411);
    shape_funcs[26] = ((shape_funcs_tmp * 102.1966762905637 - xi * ((((t16 - t39)
      + t48) - t53) + t61)) + t7 * (((eta * 400.917073199764 - t2 *
      5420.2136041355561) + t3 * 11048.5192789442) - t4 * 6082.9009483948976)) +
      (-t9 * (eta * 40.10464469690524 + t2 * 1875.46653829629) - t8 * ((eta *
         338.70735473689109 - t2 * 5636.0194761478961) + t3 * 6082.35298291557));
    shape_funcs[27] = (((shape_funcs_tmp * -1.770298779578048E-6 - xi * ((((-t32
      + t59) - t83) + t146) + t218)) - t9 * (eta * 310.075659378618 - t2 *
      2663.3740951890209)) + -t7 * (((eta * 341.79072899005757 - t2 *
      3593.601064067605) + t3 * 5946.899498607464) - t4 * 2663.374095114435)) +
      t8 * ((eta * 620.15132246143378 - t2 * 5946.8995084424278) + t3 *
            5326.74819451217);
    b_dv[0] = (((t10 * 792.00003671737159 + t245) + xi * ((((eta *
      -3140.343716497991 + t2 * 10475.30949940694) - t3 * 13562.74283045178) +
      t4 * 6005.1198175959989) + 280.000007967868)) + t7 * (((eta *
      9750.2625292306348 - t2 * 20344.114358668379) + t3 * 12518.199185075489) -
                1260.0000446404831)) + (t8 * ((eta * -12128.140531248369 + t2 *
      12010.2397582888) + 2520.00010134609) + t9 * (eta * 5240.9670345366167 -
      2310.000100945605));
    b_dv[1] = (((t10 * 791.999977708772 + (((((-t100 + t199) - t191) + t215) -
      t220) - 0.99999992549419592)) + xi * ((((eta * 219.62776311494289 - t2 *
      205.48585039832329) + t3 * 7.6280785393033916) - t4 * 4.4272198337645952)
      + 39.99999776124109)) + (-t9 * (eta * 1280.9665783579539 +
      1649.999947413213) - t7 * (((eta * 1211.642591290188 - t2 *
      920.57684030986547) + t3 * 13.28154907070461) + 359.99998401750179))) + t8
      * ((eta * 2235.726724073078 - t2 * 1033.6275406086529) +
         1199.9999556608859);
    shape_funcs_tmp = eta * t9;
    b_dv[2] = (((((((t22 + t106) - t88) - t111) - t121) - t8 * (eta *
      1.2262841738578441 + t2 * 8.8544631277841823)) - shape_funcs_tmp *
                2.156753771095203E-5) + xi * (((eta * 16.729617954406379 - t2 *
      205.48598364592019) + t3 * 613.71821851790446) - t4 * 516.81397503486824))
      + t7 * ((eta * 1.8394567639168 + t2 * 11.4422557427081) - t3 *
              13.2817653862376);
    b_dv[3] = (((t10 * -1909.582022670786 + t246) - t7 * (((eta *
      17350.877461412809 - t2 * 31664.656557924649) + t3 * 17452.95816904485) -
      2674.636841409018)) + (-t8 * ((eta * -23509.158120935092 + t2 *
      20680.80211113008) + 5706.8814191375468) + t9 * (5434.5303066230636 - eta *
      10724.75416465864))) + -xi * ((((eta * -4789.3725477997259 + t2 *
      13686.28851986367) - t3 * 15624.29046278591) + t4 * 6220.1426217020426) +
      523.74160668312675);
    b_dv[4] = ((((t10 * 2384.781960349304 + (((((t18 - t15) + t145) - t107) -
      t153) - 11.337970074798079)) + t9 * (eta * 9911.7904549759824 -
      6427.8307844858173)) + t7 * (((eta * 11828.444770991009 - t2 *
      15984.960240306809) + t3 * 6588.0688353949818) - 2554.606448356441)) + t8 *
               ((eta * -19326.37083798568 + t2 * 13345.5214772482) +
                6222.2825457508679)) + xi * ((((eta * -2293.065581974955 + t2 *
      4240.42177635918) - t3 * 2993.4345390846238) + t4 * 647.11659267164032) +
      390.81062652301569);
    b_dv[5] = (((t10 * -2534.3999444557239 + t248) + xi * ((((eta *
      422.69957277781953 + t2 * 790.45766502915546) - t3 * 1836.7806665686121) +
      t4 * 862.0232644772492) - 243.19998895121731)) + t7 * (((eta *
      -4425.79799566292 + t2 * 1311.9785493993479) + t3 * 1155.4194843642081) +
                1958.399933406364)) + (-t8 * ((eta * -10092.93217976254 + t2 *
      3453.720544680089) + 5529.5998450060051) + t9 * (6335.999845403685 - eta *
      6336.000168991709));
    b_dv[6] = ((((t10 * 2384.7819389939709 + (((((-t50 + t168) + t176) - t174) -
      t203) - 4.0999293847436764)) + t9 * (eta * 2012.1199276474431 -
      5496.07893843086)) + xi * ((((eta * 245.7209121509251 - t2 *
      1256.7466257370211) + t3 * 1057.550959926197) - t4 * 215.70839388211991) +
      161.0320230738283)) + -t8 * ((eta * 1663.52621752536 + t2 *
      2453.8196781011061) - 4358.7789172070316)) + -t7 * (((eta *
      243.73721419184571 - t2 * 3934.2931974586049) + t3 * 2174.426791528414) +
      1393.076040800255);
    b_dv[7] = ((((t10 * -1909.581946642907 + t249) + t7 * (((eta *
      1978.1862007056261 - t2 * 3111.5457584382912) + t3 * 663.25603296525844) +
      934.645742999299)) + t9 * (eta * 1176.84363172075 + 4113.3796192487462)) +
               -xi * ((((eta * 414.63290811662819 - t2 * 750.73272151389449) +
                        t3 * 242.18228124862219) + t4 * 5.5262080141738767) +
                      104.90105969160911)) + -t8 * ((eta * 2936.338410072638 -
      t2 * 3122.3933890929638) + 3064.580255821324);
    b_dv[8] = ((t241 + t7 * ((eta * 1979.8641357263371 + t2 * 262.81078621202818)
      - t3 * 789.93885911213147)) + (-xi * (((eta * 281.20870525021809 + t2 *
      174.5438734526866) - t3 * 351.08525501319491) + t4 * 36.701292302187262) +
                shape_funcs_tmp * 3179.6593527029759)) + -t8 * (eta *
      4540.535770745767 - t2 * 278.35359199561623);
    b_dv[9] = (((t242 + shape_funcs_tmp * 604.89350387446314) - t8 * (eta *
      1271.4268876563681 - t2 * 3713.8072555542221)) + t7 * ((eta *
      727.42927706298713 - t2 * 3206.8284867181051) + t3 * 923.99192756842319))
      + -xi * (((eta * 122.0238711608628 - t2 * 597.67628226606269) + t3 *
                79.878735103928491) + t4 * 201.103293133941);
    b_dv[10] = ((t239 - shape_funcs_tmp * 136.20850328330721) - xi * (((eta *
      58.634023631679042 - t2 * 759.90689269079314) + t3 * 1537.045442663414) -
      t4 * 589.60617423923577)) + (t7 * ((eta * 153.82586641651869 - t2 *
      2305.5680827496358) + t3 * 3199.4686452904448) + t8 * (eta *
      37.133384188821758 + t2 * 1179.212245669049));
    b_dv[11] = ((t233 + shape_funcs_tmp * 7.3025214749080876) - xi * (((eta *
      39.988463865735852 - t2 * 597.67627719856171) + t3 * 2137.8855673499379) -
      t4 * 1856.903553967953)) + (-t7 * ((eta * 11.98983144949378 + t2 *
      119.8181588118686) - t3 * 923.991859167699) + t8 * (eta *
      57.419389642961747 - t2 * 402.20650060900539));
    b_dv[12] = (((t232 - shape_funcs_tmp * 15.587522333922569) + t8 * (eta *
      43.398995624270782 - t2 * 73.402641615075808)) + xi * (((eta *
      28.48603794698943 - t2 * 174.54376520249929) + t3 * 175.20685217367571) +
      t4 * 139.1770299027223)) + -t7 * ((eta * 82.786153523290253 - t2 *
      526.62783948533786) + t3 * 789.93865968900491);
    b_dv[13] = (((t229 + shape_funcs_tmp * 15.58758326651008) + t7 * ((eta *
      46.114437026179139 - t2 * 363.27379189343822) + t3 * 663.25651993140593))
                + -xi * (((eta * 69.239429148233754 - t2 * 750.73302895113272) +
                          t3 * 2074.3645399270758) - t4 * 1561.1971229848541)) +
      -t8 * (eta * 18.95123925024085 + t2 * 11.0523048822816);
    b_dv[14] = (((((((t105 - t58) - t71) + t139) - t112) - shape_funcs_tmp *
                  7.3025841432853547) - t7 * ((eta * 204.08364975337921 - t2 *
      1586.3269807059039) + t3 * 2174.4273897081971)) + xi * (((eta *
      137.5002012926486 - t2 * 1256.747014605892) + t3 * 2622.862951694965) - t4
      * 1226.9103222974941)) + t8 * (eta * 86.629655513260161 - t2 *
      431.41700957367669);
    b_dv[15] = (((t231 - t8 * (eta * 507.70087367927079 - t2 * 1724.046874006056))
                 + shape_funcs_tmp * 136.20858841943749) + -xi * (((eta *
      184.41624199491719 - t2 * 790.45810912110869) - t3 * 874.65153948637351) +
      t4 * 1726.859826178267)) + t7 * ((eta * 552.02524246560426 - t2 *
      2755.1717247540678) + t3 * 1155.42016927088);
    b_dv[16] = (((t226 + t8 * (eta * 1148.1475271030611 + t2 *
      1294.2327661765769)) - shape_funcs_tmp * 604.89367756348167) + -t7 * ((eta
      * 542.509954232188 + t2 * 4490.151085992683) - t3 * 6588.0682912964421)) +
      -xi * (((eta * 61.8718677878564 - t2 * 4240.4214105608171) + t3 *
              10656.639577760019) - t4 * 6672.7604439549987);
    b_dv[17] = (((((((-t19 - t20) + t41) + t81) - t79) - shape_funcs_tmp *
                  3179.6599189591589) + t8 * (eta * 8178.1029273344884 - t2 *
      12440.28557773478)) + -t7 * ((eta * 7436.2139260307813 - t2 *
      23436.43611914404) + t3 * 17452.958324495889)) + xi * (((eta *
      2775.54994821303 - t2 * 13686.28863902667) + t3 * 21109.771064047509) - t4
      * 10340.401012960951);
    b_dv[18] = ((t224 + shape_funcs_tmp * 7939.0958718190432) - xi * (((eta *
      5000.2565448888208 - t2 * 21524.719545529519) + t3 * 29604.1640723813) -
      t4 * 13132.20975626727)) + (t7 * ((eta * 15882.83711101671 - t2 *
      44406.246670539833) + t3 * 29869.714891356231) - t8 * (eta *
      19217.936205496178 - t2 * 26264.42011210067));
    b_dv[19] = (((((((t102 - t55) + t127) - t101) - t177) + t8 * (eta *
      21303.10585979246 - t2 * 24331.603731299121)) - shape_funcs_tmp *
                 9891.0559558676632) + xi * (((eta * 3343.2715480965439 - t2 *
      10840.427009583629) + t3 * 11272.03874218093) - t4 * 3750.933013299627)) +
      -t7 * ((eta * 14684.69791001448 - t2 * 33145.557547630589) + t3 *
             18247.058758145009);
    b_dv[20] = (((((((t38 + t131) - t123) - t140) - t160) - t8 * (eta *
      18261.11751902421 - t2 * 15232.61943478821)) + shape_funcs_tmp *
                 9891.0559095896224) + t7 * ((eta * 10121.71551663116 - t2 *
      14934.098918182441) + t3 * 4598.5825482966648)) + -xi * (((eta *
      1681.030324656625 - t2 * 2699.3083844726648) + t3 * 306.92466582960549) +
      t4 * 687.40313360400785);
    b_dv[21] = (((((((t129 - t74) - t154) - t189) - t219) + t8 * (eta *
      12538.445845993479 - t2 * 5491.9621605337543)) - shape_funcs_tmp *
                 7939.0951497359674) + xi * (((eta * 867.99235983363826 - t2 *
      221.7205738382724) - t3 * 1023.41983514737) + t4 * 429.656727430313)) + t7
      * ((eta * -5863.6028286512555 + t2 * 3228.326846785701) + t3 *
         1288.9705796489111);
    b_dv[22] = ((((((t132 - t91) - t104) + t183) - t175) - shape_funcs_tmp *
                 510.98353409811432) + xi * (((eta * 332.26776797114559 - t2 *
      2666.9532436237391) + t3 * 2448.5445649573062) - t4 * 221.2154693168504))
      + (-t7 * ((eta * 1568.5224579917449 - t2 * 11248.083714370439) + t3 *
                7324.4386476012851) + t8 * (eta * 1883.515093781165 - t2 *
          9545.79909233622));
    b_dv[23] = ((((((-t26 + t98) + t141) - t92) - t97) + xi * (((eta *
      189.73380521068691 - t2 * 2666.9533600014911) + t3 * 7498.722514293454) -
      t4 * 4772.8994828196983)) + shape_funcs_tmp * 233.09378051817359) + (-t7 *
      ((eta * 160.53441504937641 - t2 * 3672.8173411668381) + t3 *
       7324.43895178072) - t8 * (eta * 303.99622288808052 + t2 *
      442.4313153722922));
    b_dv[24] = (((((((t46 - t42) + t134) - t78) - t80) - t8 * (eta *
      164.1062229637927 - t2 * 859.31351169531081)) - shape_funcs_tmp *
                 2.59024229205136E-5) + -xi * (((eta * 29.544435391202121 + t2 *
      221.720938119018) - t3 * 2152.218938230958) + t4 * 2745.9817810042018)) +
      t7 * ((eta * 246.15935916672359 - t2 * 1535.12949222512) + t3 *
            1288.9699393922481);
    b_dv[25] = (((t225 + t8 * (eta * 628.37873526723558 - t2 *
      1374.8059725826711)) - shape_funcs_tmp * 233.09372768408841) + -t7 * ((eta
      * 326.03941712328952 + t2 * 460.38771017179317) - t3 * 4598.5833217533518))
      + -xi * (((eta * 110.9486564161912 - t2 * 2699.3088841349122) + t3 *
                9956.0669490048585) - t4 * 7616.3102684528822);
    b_dv[26] = (((((((-t16 + t39) + t53) - t48) - t61) - t7 * ((eta *
      1016.122064210673 - t2 * 16908.058428443692) + t3 * 18247.058948746711)) +
                 shape_funcs_tmp * 510.98338145281838) + xi * (((eta *
      801.834146399528 - t2 * 10840.42720827111) + t3 * 22097.038557888391) - t4
      * 12165.8018967898)) + -t8 * (eta * 160.418578787621 + t2 *
      7501.8661531851612);
    b_dv[27] = (((((((t32 + t83) - t59) - t146) - t218) - shape_funcs_tmp *
                  8.85149389789024E-6) - t8 * (eta * 1240.3026375144721 - t2 *
      10653.49638075608)) + -xi * (((eta * 683.58145798011526 - t2 *
      7187.2021281352108) + t3 * 11893.79899721493) - t4 * 5326.748190228871)) +
      t7 * ((eta * 1860.453967384301 - t2 * 17840.69852532728) + t3 *
            15980.244583536511);
    b_dv[28] = (((((((eta * 280.000007967868 - t2 * 1260.0000446404831) + t3 *
                     2520.00010134609) - t4 * 2310.000100945605) + t5 *
                   792.00003671737159) + t10 * 1048.1934069073229) + t8 * ((eta *
      -13562.74290577892 + t2 * 12518.199185075489) + 3250.0875097435451)) + (t7
      * (((eta * 10475.30949940694 - t2 * 20344.114245677669) + t3 *
          12010.239635192) - 1570.171858248995) + t9 * (eta * 6005.1198791444 -
      3032.0351328120928))) + (xi * ((((eta * -3140.343701517193 + t2 *
      9750.2624413998656) - t3 * 12128.140384513659) + t4 * 5240.966960050845) +
      325.92607485546279) - 21.00000037073665);
    b_dv[29] = (((t10 * -256.19331567159082 + t9 * (558.9316810182695 - eta *
      516.81377030432668)) + -t7 * (((eta * 205.48585039832329 - t2 *
      11.442117808955089) + t3 * 8.85443966752919) - 109.8138815574714)) + -xi *
                ((((eta * -16.729604449015959 - t2 * 1.839478112457253) + t3 *
                   1.2263026130362491) + t4 * 1.1722452374932629E-5) +
                 8.671383657182167)) + -t8 * ((eta * -613.71789353991028 + t2 *
      13.28154907070461) + 403.880863763396);
    b_dv[30] = (((((((eta * 39.99999776124109 - t2 * 359.99998401750179) + t3 *
                     1199.9999556608859) - t4 * 1649.999947413213) + t5 *
                   791.999977708772) + (t10 * -4.3135075421904053E-6 - t9 * (eta
      * 4.4272315638920912 + 0.3065710434644609))) + -xi * ((((eta *
      -219.6278141570165 + t2 * 1211.6428314385989) - t3 * 2235.7270957883538) +
      t4 * 1280.96675897342) + 8.6713859642770874)) + -t7 * (((eta *
      205.48598364592019 - t2 * 920.57732777685669) + t3 * 1033.627950069736) -
      8.3648089772031913)) + (t8 * ((eta * 7.6281704951387326 - t2 *
      13.2817653862376) + 0.6131522546389333) - 0.99999992549419592);
    b_dv[31] = (((t10 * -2144.9508329317282 - t7 * (((eta * 13686.28851986367 -
      t2 * 23436.435694178861) + t3 * 12440.285243404091) - 2394.686273899863))
                 + -t8 * ((eta * -21109.771038616429 + t2 * 17452.95816904485) +
                          5783.6258204709366)) + -xi * ((((eta *
      -2775.5498947846472 + t2 * 7436.213698854689) - t3 * 8178.102598645296) +
      t4 * 3179.659765659972) + 346.03389774688537)) + t9 * (5877.289530233772 -
      eta * 10340.40105556504);
    b_dv[32] = ((t10 * 1982.358090995197 + t7 * (((eta * 4240.42177635918 - t2 *
      4490.1518086269361) + t3 * 1294.2331853432811) - 1146.532790987477)) + (t9
      * (eta * 6672.7607386241007 - 4831.59270949642) + t8 * ((eta *
      -10656.640160204541 + t2 * 6588.0688353949818) + 3942.8149236636709))) +
      -xi * ((((eta * 61.871942569679433 + t2 * 542.50971417751327) - t3 *
               1148.1472305670111) + t4 * 604.89355210384929) -
             57.052415531159312);
    b_dv[33] = (((t10 * -1267.200033798342 + t9 * (2523.233044940635 - eta *
      1726.860272340045)) + t7 * (((eta * 790.45766502915546 - t2 *
      2755.1709998529182) + t3 * 1724.0465289544979) + 211.34978638890971)) + t8
                * ((eta * 874.65236626623221 + t2 * 1155.4194843642081) -
                   1475.2659985543071)) + xi * ((((eta * -184.41618334933781 +
      t2 * 552.02510880401417) - t3 * 507.70075809416028) + t4 *
      136.2085550146036) + 1.483201007077666);
    b_dv[34] = (((t10 * 402.42398552948862 - t8 * ((eta * -2622.86213163907 + t2
      * 2174.426791528414) + 81.245738063948565)) - t9 * (eta *
      1226.909839050553 + 415.8815543813401)) + -t7 * (((eta *
      1256.7466257370211 - t2 * 1586.3264398892959) + t3 * 431.41678776423993) -
      122.86045607546259)) + -xi * ((((eta * -137.50015796861939 + t2 *
      204.08357304251669) - t3 * 86.629606277285248) + t4 * 7.3025749367932642)
      + 16.819178500689809);
    b_dv[35] = (((t10 * 235.36872634414991 + t8 * ((eta * -2074.3638389588609 +
      t2 * 663.25603296525844) + 659.39540023520874)) + -t7 * (((eta *
      -750.73272151389449 + t2 * 363.27342187293323) + t3 * 11.05241602834775) +
      207.31645405831409)) + xi * ((((eta * -69.239397621246127 + t2 *
      46.114388640674917) - t3 * 18.951209744923659) + t4 * 15.58757413216788) +
      18.233776814757618)) + t9 * (eta * 1561.1966945464819 - 734.08460251815939);
    b_dv[36] = (((t10 * 635.93187054059513 + t9 * (eta * 139.17679599780811 -
      1135.133942686442)) + t8 * ((eta * 175.20719080801879 - t2 *
      789.93885911213147) + 659.9547119087789)) + xi * ((((eta *
      28.486046303123231 - t2 * 82.786161675853066) + t3 * 43.399009088781959) -
      t4 * 15.58753742164169) + 8.25486604172513)) + -t7 * (((eta *
      174.5438734526866 - t2 * 526.62788251979237) + t3 * 73.402584604374525) +
      140.604352625109);
    b_dv[37] = ((t10 * 120.9787007748926 - t7 * (((eta * -597.67628226606269 +
      t2 * 119.8181026558927) + t3 * 402.2065862678819) + 61.011935580431377)) +
                xi * ((((eta * -39.988465434709973 - t2 * 11.989820734666541) +
                        t3 * 57.419360389302547) + t4 * 7.302545264258864) +
                      4.0755611195914474)) + (t9 * (eta * 1856.9036277771111 -
      317.85672191409208) + t8 * ((eta * -2137.88565781207 + t2 *
      923.99192756842319) + 242.47642568766241));
    b_dv[38] = (((t10 * -27.241700656661429 + xi * ((((eta * -58.634019213217563
      + t2 * 153.82584918054511) + t3 * 37.133417995464363) - t4 *
      136.20852786114139) + 2.400077366758619)) + t9 * (eta * 589.60612283452463
      + 9.28334604720544)) + t7 * (((eta * 759.90689269079314 - t2 *
      2305.5681639951208) + t3 * 1179.212348478472) - 29.317011815839521)) + t8 *
      ((eta * -1537.0453884997571 + t2 * 3199.4686452904448) +
       51.275288805506243);
    b_dv[39] = (((t10 * 1.460504294981618 - t8 * ((eta * 79.8787725412457 - t2 *
      923.991859167699) + 3.9966104831645941)) + xi * ((((eta *
      -122.02387149503549 + t2 * 727.429264892866) - t3 * 1271.4268694310431) +
      t4 * 604.89350105388655) + 4.0755611597693218)) + t7 * (((eta *
      597.67627719856171 - t2 * 3206.8283510249071) + t3 * 3713.8071079359061) -
      19.994231932867919)) + t9 * (14.35484741074044 - eta * 201.10325030450269);
    b_dv[40] = (((t10 * -3.1175044667845131 + t9 * (10.8497489060677 - eta *
      36.7013208075379)) + t7 * (((eta * -174.54376520249929 + t2 *
      262.81027826051348) + t3 * 278.35405980544448) + 14.243018973494721)) + xi
                * ((((eta * -281.20875296369121 + t2 * 1979.8643819244639) - t3 *
                     4540.5361665002092) + t4 * 3179.6595473038492) +
                   8.25486793740524)) + -t8 * ((eta * -351.08522632355857 + t2 *
      789.93865968900491) + 27.59538450776342);
    b_dv[41] = ((((((((eta * -104.90105969160911 + t2 * 934.645742999299) - t3 *
                      3064.580255821324) + t4 * 4113.3796192487462) - t5 *
                    1909.581946642907) + t10 * 3.1175166533020149) + -t9 * (eta *
      5.5261524411407983 + 4.7378098125602133)) + t7 * (((eta *
      750.73302895113272 - t2 * 3111.546809890614) + t3 * 3122.3942459697091) -
      34.619714574116877)) + xi * ((((eta * -414.63302110257308 + t2 *
      1978.1867215031259) - t3 * 2936.3392106623669) + t4 * 1176.8440210046749)
      + 18.23378199921089)) + (t8 * ((eta * -242.18252792895879 + t2 *
      663.25651993140593) + 15.37147900872638) + 2.634746725437807);
    b_dv[42] = ((((((((eta * 161.0320230738283 - t2 * 1393.076040800255) + t3 *
                      4358.7789172070316) - t4 * 5496.07893843086) + t5 *
                    2384.7819389939709) - t10 * 1.4605168286570711) + t9 *
                  (21.65741387831504 - eta * 215.70850478683829)) + -xi *
                 ((((eta * -245.7210515465641 + t2 * 243.73784776394089) + t3 *
                    1663.525241951073) - t4 * 2012.119448441091) +
                  16.819185060112229)) + -t8 * ((eta * -1057.5513204706019 + t2 *
      2174.4273897081971) + 68.027883251126383)) + (-t7 * (((eta *
      1256.747014605892 - t2 * 3934.2944275424479) + t3 * 2453.8206445949882) -
      68.750100646324313) - 4.0999293847436764);
    b_dv[43] = (((((((eta * -243.19998895121731 + t2 * 1958.399933406364) - t3 *
                     5529.5998450060051) + t4 * 6335.999845403685) - t5 *
                   2534.3999444557239) + t10 * 27.24171768388749) + (t8 * ((eta *
      -1836.781149836045 + t2 * 1155.42016927088) + 184.00841415520139) + t9 *
      (eta * 862.02343700302788 - 126.9252184198177))) + xi * ((((eta *
      422.69943906746278 - t2 * 4425.7974415506606) + t3 * 10092.93138298761) -
      t4 * 6335.9997971887706) + 1.483207991314871)) + (t7 * (((eta *
      790.45810912110869 + t2 * 1311.97730922956) - t3 * 3453.719652356534) -
      92.208120997458607) + 6.3999995868725206);
    b_dv[44] = (((((((eta * 390.81062652301569 - t2 * 2554.606448356441) + t3 *
                     6222.2825457508679) - t4 * 6427.8307844858173) + t5 *
                   2384.781960349304) - t10 * 120.9787355126963) + (t9 * (eta *
      647.11638308828844 + 287.03688177576532) - t8 * ((eta * 2993.4340573284549
      - t2 * 6588.0682912964421) + 180.8366514107293))) + xi * ((((eta *
      -2293.065489571823 + t2 * 11828.444419371879) - t3 * 19326.37034563487) +
      t4 * 9911.79022663538) + 57.052409116386677)) + (t7 * (((eta *
      4240.4214105608171 - t2 * 15984.95936664002) + t3 * 13345.52088791) -
      30.9359338939282) - 11.337970074798079);
    b_dv[45] = ((((((((eta * -523.74160668312675 + t2 * 2674.636841409018) - t3 *
                      5706.8814191375468) + t4 * 5434.5303066230636) - t5 *
                    1909.582022670786) - t10 * 635.93198379183184) + -xi *
                  ((((eta * -4789.3725490999677 + t2 * 17350.8773856641) - t3 *
                     23509.157946556581) + t4 * 10724.75406367751) +
                   346.03390024817378)) + -t8 * ((eta * -15624.29074609603 + t2 *
      17452.958324495889) + 2478.737975343593)) + (-t7 * (((eta *
      13686.28863902667 - t2 * 31664.656596071261) + t3 * 20680.80202592189) -
      1387.7749741065149) + t9 * (2044.5257318336221 - eta * 6220.1427888673916)))
      + 28.40315344346228;
    b_dv[46] = (((t10 * 1587.819174363809 + t7 * (((eta * 21524.719545529519 -
      t2 * 44406.246108571941) + t3 * 26264.41951253454) - 2500.12827244441)) +
                 t8 * ((eta * -29604.164447026549 + t2 * 29869.714891356231) +
                       5294.2790370055691)) + xi * ((((eta * -5000.2564647536492
      + t2 * 15882.83665945798) - t3 * 19217.935471604651) + t4 *
      7939.095506714576) + 422.51411244907769)) + t9 * (eta * 13132.21005605033
      - 4804.4840513740464);
    b_dv[47] = (((t10 * -1978.2111911735331 - t8 * ((eta * -22097.038365087061 +
      t2 * 18247.058758145009) + 4894.8993033381576)) + t9 * (5325.7764649481142
      - eta * 12165.801865649561)) + -xi * ((((eta * -801.83410519046208 + t2 *
      1016.122003058641) + t3 * 160.41857935305069) - t4 * 510.98335540303339) +
      124.30174448469469)) + -t7 * (((eta * 10840.427009583629 - t2 *
      16908.0581132714) + t3 * 7501.8660265992548) - 1671.635774048272);
    b_dv[48] = (((t10 * 1978.2111819179249 + t9 * (eta * 7616.3097173941051 -
      4565.2793797560516)) + t8 * ((eta * -9956.0659454549568 + t2 *
      4598.5825482966648) + 3373.9051722103868)) + -t7 * (((eta *
      -2699.3083844726648 + t2 * 460.38699874440829) + t3 * 1374.8062672080159)
      + 840.51516232831273)) + -xi * ((((eta * 110.9486154198034 + t2 *
      326.03945428399811) - t3 * 628.37870921445153) + t4 * 233.09369727549) -
      53.678187956052838);
    b_dv[49] = (((t10 * -1587.819029947193 + t9 * (3134.6114614983712 - eta *
      2745.9810802668771)) + -t7 * (((eta * 221.7205738382724 + t2 *
      1535.1297527210561) - t3 * 859.31345486062594) - 433.99617991681907)) +
                -xi * ((((eta * 29.544459374005552 - t2 * 246.15935890058859) +
                         t3 * 164.10619336622631) + t4 * 3.1770290359604838E-5)
                       + 26.254335250912121)) + t8 * ((eta * 2152.2178978571342
      + t2 * 1288.9705796489111) - 1954.5342762170851);
    b_dv[50] = ((t10 * -102.1967068196229 - t7 * (((eta * 2666.9532436237391 -
      t2 * 3672.8168474359591) + t3 * 442.43093863370092) - 166.13388398557279))
                + -xi * ((((eta * -189.73379030847431 + t2 * 160.53437454856589)
      + t3 * 303.99621587317358) - t4 * 233.09374138785611) + 11.975131280659641))
      + (-t8 * ((eta * -7498.7224762469577 + t2 * 7324.4386476012851) +
                522.84081933058155) + t9 * (470.8787734452913 - eta *
          4772.89954616811));
    b_dv[51] = (((t10 * 46.618756103634723 - t7 * (((eta * 2666.9533600014911 -
      t2 * 11248.08377144018) + t3 * 9545.7989656393966) - 94.866902605343469))
                 + -t8 * ((eta * -2448.5448941112249 + t2 * 7324.43895178072) +
                          53.511471683125457)) + -xi * ((((eta *
      -332.26775655155382 + t2 * 1568.5223302335451) - t3 * 1883.5148221422171)
      + t4 * 510.9833788149167) + 11.9751313038326)) + -t9 * (eta *
      221.2156576861461 + 75.999055722020131);
    b_dv[52] = (((t10 * -5.1804845841027186E-6 + t8 * ((eta *
      -1023.4196614834131 + t2 * 1288.9699393922481) + 82.053119722241192)) + t9
                 * (eta * 429.6567558476554 - 41.026555740948183)) + -t7 *
                (((eta * 221.720938119018 - t2 * 3228.328407346437) + t3 *
                  5491.9635620084046) + 14.772217695601061)) + -xi * ((((eta *
      -867.99251136297255 + t2 * 5863.6036013024668) - t3 * 12538.44709221232) +
      t4 * 7939.0957693093524) + 26.254341105207359);
    b_dv[53] = ((t10 * -46.618745536817677 + xi * ((((eta * -1681.03049836998 +
      t2 * 10121.71625173643) - t3 * 18261.118572251311) + t4 *
      9891.0563968323659) + 53.6781956358675)) + (t9 * (157.0946838168089 - eta *
      687.40298629133554) - t8 * ((eta * 306.9251401145288 - t2 *
      4598.5833217533518) + 108.67980570776319))) + t7 * (((eta *
      2699.3088841349122 - t2 * 14934.100423507291) + t3 * 15232.620536905761) -
      55.474328208095578);
    b_dv[54] = ((t10 * 102.1966762905637 - xi * ((((eta * -3343.2716021629421 +
      t2 * 14684.6979950191) - t3 * 21303.105842857109) + t4 *
      9891.0559003309081) + 124.3017500565313)) + -t8 * ((eta *
      -11272.03895229579 + t2 * 18247.058948746711) + 338.70735473689109)) +
      (-t7 * (((eta * 10840.42720827111 - t2 * 33145.557836832588) + t3 *
               24331.60379357959) - 400.917073199764) - t9 * (eta *
        3750.9330765925811 + 40.10464469690524));
    b_dv[55] = ((t10 * -1.770298779578048E-6 + -xi * ((((eta *
      683.58144019687609 - t2 * 1860.45390942396) + t3 * 1240.302593128029) + t4
      * 1.2192076812989289E-5) - 31.71506767754061)) + (t7 * (((eta *
      7187.2021281352108 - t2 * 17840.698495822391) + t3 * 10653.49638045774) -
      341.79072899005757) + t9 * (eta * 5326.7481903780417 - 310.075659378618)))
      + t8 * ((eta * -11893.799016884859 + t2 * 15980.244583536511) +
              620.15132246143378);
    i = 0;
    i1 = 0;
    for (int i2{0}; i2 < 56; i2++) {
      deriv[i1 + (i << 1)] = b_dv[i2];
      i++;
      if (i > 27) {
        i = 0;
        i1++;
      }
    }
  }

  static inline
  void tri_gl_15(double xi, double eta, double shape_funcs[15], double
                        deriv[30])
  {
    double b_dv[30];
    double shape_funcs_tmp;
    double t10;
    double t104;
    double t106;
    double t107;
    double t108;
    double t11;
    double t110;
    double t111;
    double t118;
    double t119;
    double t12;
    double t120;
    double t121;
    double t124;
    double t126;
    double t127;
    double t128;
    double t13;
    double t130;
    double t131;
    double t139;
    double t14;
    double t140;
    double t141;
    double t142;
    double t146;
    double t147;
    double t149;
    double t15;
    double t150;
    double t151;
    double t16;
    double t2;
    double t20;
    double t21;
    double t22;
    double t23;
    double t24;
    double t25;
    double t26;
    double t28;
    double t3;
    double t34;
    double t36;
    double t39;
    double t4;
    double t40;
    double t41;
    double t42;
    double t43;
    double t45;
    double t46;
    double t47;
    double t48;
    double t5;
    double t50;
    double t51;
    double t53;
    double t54;
    double t55;
    double t57;
    double t59;
    double t6;
    double t62;
    double t63;
    double t7;
    double t70;
    double t71;
    double t72;
    double t74;
    double t82;
    double t84;
    double t85;
    double t88;
    double t89;
    double t9;
    double t90;
    double t92;
    double t93;
    double t94;
    double t95;
    double t96;
    double t97;
    int i;
    int i1;

    // TRI_GL_15   Quartic triangular element with Gauss-Lobatto points
    t2 = eta * eta;
    t3 = std::pow(eta, 3.0);
    t5 = xi * xi;
    t6 = std::pow(xi, 3.0);
    t39 = eta * 367.54650876527251;
    t40 = eta * 376.96596108139909;
    t41 = eta * 69.69079963456926;
    t42 = eta * 253.88492437159061;
    t43 = eta * 82.997248307717143;
    t45 = eta * 210.28362848432991;
    t46 = eta * 61.441382279744722;
    t47 = eta * 3.2640033791765219;
    t48 = eta * 266.14865168554968;
    t50 = eta * 154.33202097703341;
    t51 = eta * 241.74901573277509;
    t53 = eta * 210.0320081252209;
    t54 = eta * 21.800647943630331;
    t55 = eta * 43.601295887260669;
    t57 = eta * 26.880604747388311;
    t59 = eta * 31.449256417544021;
    t62 = eta * 17.631144200380451;
    t63 = eta * 43.268046938161419;
    t82 = eta * 8.226596743221835;
    t85 = eta * 7.8326771551833918;
    t90 = eta * 1.2437020096073479;
    t95 = eta * 6.026249587820387;
    t4 = t2 * t2;
    t7 = t5 * t5;
    t10 = t3 * 56.0;
    t12 = t6 * 56.0;
    t13 = t2 * 224.0;
    t14 = eta * 2.6457513110645907;
    t22 = t3 * 74.666666666666671;
    t23 = t3 * 130.66666666666666;
    t25 = t6 * 130.66666666666666;
    t26 = t2 * 2.6457513110645907;
    t34 = t3 * 2.6457513110645907 * 3.5;
    t70 = t2 * 315.42544272649479;
    t71 = t2 * 133.0743258427749;
    t72 = t2 * 266.14865168554968;
    t74 = t2 * 146.514628216469;
    t84 = t2 * 183.77325438263631;
    t88 = t3 * 116.9027831039519;
    t89 = t2 * 126.94246218579531;
    t92 = t2 * 105.1418142421649;
    t93 = t2 * 210.28362848432991;
    t94 = t3 * 105.1418142421649;
    t96 = t2 * 61.441382279744722;
    t97 = t6 * 105.1418142421649;
    t104 = t2 * 26.880604747388311;
    t106 = t3 * 48.838209405489671;
    t107 = t6 * 48.838209405489671;
    t108 = t2 * 19.837926580382931;
    t110 = t2 * 21.634023469080709;
    t111 = t2 * 43.268046938161419;
    t118 = t2 * 30.720691139872361;
    t119 = t2 * 3.0131247939101931;
    t120 = t2 * 13.440302373694159;
    t121 = t2 * 8.193721095386552;
    t124 = t3 * 6.6126421934609754;
    t126 = t3 * 2.7312403651288508;
    t127 = t6 * 6.6126421934609754;
    t128 = t6 * 2.7312403651288508;
    t130 = t3 * 13.76388356271481;
    t131 = t2 * 0.621851004803674;
    t9 = t4 * 14.0;
    t11 = t7 * 14.0;
    t15 = t14 * 2.0;
    t16 = t14 * 7.0;
    t20 = t14 * 9.0;
    t21 = t4 * 32.666666666666664;
    t24 = t7 * 32.666666666666664;
    t28 = t14 * 2.3333333333333335;
    t36 = t26 * 4.5;
    t139 = -t54 + t2 * 21.800647943630331;
    t140 = (t22 + t85) - t2 * 77.166010488516719;
    t141 = (t14 * 31.5 + t94) - t2 * 188.48298054069949;
    t142 = (t28 + t106) - t2 * 41.498624153858572;
    t146 = ((eta * 66.614378277661473 + t3 * 65.260129588726073) - t2 *
            120.8745078663875) - 10.0;
    t147 = (eta * 3.7786526819777 + t124) - t2 * 15.72462820877201;
    t149 = ((t85 + t2 * 4.1132983716109166) - t124) - 5.333333333333333;
    t150 = ((-t41 + t2 * 105.01600406261041) - t106) + 13.51300497744848;
    t151 = ((t47 + t126) - t2 * 8.8155721001902254) + 2.820328355884854;
    shape_funcs[0] = (((((((eta * -10.0 + t2 * 30.0) - t3 * 35.0) + t9) + t11) +
                        t146 * xi) + t5 * ((eta * -120.8745078663875 + t2 *
      102.5202591774521) + 30.0)) + t6 * (eta * 65.260129588726073 - 35.0)) +
      1.0;
    shape_funcs[1] = ((t11 - t6 * (t14 * 3.5 + 21.0)) + t5 * ((t14 * 4.5 - t26 *
      3.5) + 9.0)) - xi * ((t14 + t2 * -2.6457513110645907) + 1.0);
    shape_funcs[2] = ((((-eta + t2 * 9.0) - t3 * 21.0) + t9) + t5 * (t14 - t26 *
      3.5)) - xi * ((t14 + t34) - t36);
    shape_funcs[3] = ((-t24 + t150 * xi) + t6 * (76.026009954896963 - eta *
      116.9027831039519)) - t5 * ((eta * -183.77325438263631 + t71) +
      56.872348265678767);
    shape_funcs[4] = ((t7 * 37.333333333333336 + t149 * xi) + t5 * ((eta *
      -77.166010488516719 + t118) + 42.666666666666664)) + t6 * (eta *
      74.666666666666671 - 74.666666666666671);
    shape_funcs[5] = ((-t24 + t151 * xi) - t5 * ((eta * 3.0131247939101931 -
      t110) + 24.794318400987891)) + t6 * (54.640656711769708 - eta *
      13.76388356271481);
    shape_funcs[6] = (t6 * (eta * 48.838209405489671) - t5 * (eta *
      41.498624153858572 - t120)) - xi * ((-t28 + t126) + t131);
    shape_funcs[7] = (t6 * (eta * 6.6126421934609754) + t147 * xi) - t5 * (eta *
      15.72462820877201 - t2 * 50.558617720255278);
    shape_funcs_tmp = eta * t6;
    shape_funcs[8] = (shape_funcs_tmp * -2.7312403651288508 + t142 * xi) - t5 *
      (eta * 0.621851004803674 - t120);
    shape_funcs[9] = (((((eta * 2.820328355884854 - t2 * 24.794318400987891) +
                         t3 * 54.640656711769708) - t21) + t6 * (eta *
      2.7312403651288508)) - t5 * (eta * 8.8155721001902254 - t110)) - xi *
      ((-t47 + t119) + t130);
    shape_funcs[10] = (((((eta * -5.333333333333333 + t2 * 42.666666666666664) +
                          t4 * 37.333333333333336) - t22) - shape_funcs_tmp *
                        6.6126421934609754) + t140 * xi) + t5 * (eta *
      4.1132983716109166 + t118);
    shape_funcs[11] = (((((eta * 13.51300497744848 - t2 * 56.872348265678767) +
                          t3 * 76.026009954896963) - t21) - shape_funcs_tmp *
                        48.838209405489671) + t5 * (eta * 105.01600406261041 -
      t71)) - xi * ((t41 - t84) + t88);
    shape_funcs[12] = (t6 * (eta * 105.1418142421649) + t141 * xi) - t5 * (eta *
      188.48298054069949 - t93);
    shape_funcs[13] = (t5 * (eta * 126.94246218579531 - t92) - shape_funcs_tmp *
                       105.1418142421649) + t139 * xi;
    shape_funcs[14] = -t5 * (-t54 + t92) - xi * ((t54 - t89) + t94);
    b_dv[0] = ((t12 + t146) + xi * ((t2 * 205.04051835490429 - t51) + 60.0)) +
      t5 * (eta * 195.78038876617819 - 105.0);
    b_dv[1] = ((t12 + ((-t14 + t26) - 1.0)) - t5 * (t14 * 10.5 + 63.0)) + xi *
      ((t20 - t26 * 7.0) + 18.0);
    b_dv[2] = ((-t14 - t34) + t36) + xi * (t15 - t26 * 7.0);
    b_dv[3] = ((-t25 + t150) + t5 * (228.0780298646909 - eta *
                350.70834931185561)) - xi * ((-t39 + t72) + 113.7446965313575);
    b_dv[4] = ((t6 * 149.33333333333334 + t149) + xi * ((-t50 + t96) +
                85.333333333333329)) + t5 * (eta * 224.0 - 224.0);
    b_dv[5] = ((-t25 + t151) + t5 * (163.9219701353091 - eta *
                41.291650688144429)) - xi * ((t95 - t111) + 49.588636801975788);
    b_dv[6] = (((t28 - t126) - t131) + xi * (-t43 + t104)) + t5 * (eta *
      146.514628216469);
    b_dv[7] = (t147 + t5 * (eta * 19.837926580382931)) + xi * (t2 *
      101.1172354405106 - t59);
    shape_funcs_tmp = eta * t5;
    b_dv[8] = (t142 - shape_funcs_tmp * 8.193721095386552) - xi * (t90 - t104);
    b_dv[9] = (((t47 - t119) - t130) + xi * (-t62 + t111)) + t5 * (eta *
      8.193721095386552);
    b_dv[10] = (t140 + xi * (t82 + t96)) - shape_funcs_tmp * 19.837926580382931;
    b_dv[11] = (((-t41 + t84) - t88) + xi * (t53 - t72)) - shape_funcs_tmp *
      146.514628216469;
    b_dv[12] = (t141 + xi * (t2 * 420.56725696865982 - t40)) + t5 * (eta *
      315.42544272649479);
    b_dv[13] = (t139 + xi * (t42 - t93)) - shape_funcs_tmp * 315.42544272649479;
    b_dv[14] = ((-t54 + t89) - t94) + xi * (t55 - t93);
    b_dv[15] = (((((eta * 60.0 - t2 * 105.0) + t6 * 65.260129588726073) + t10) +
                 t5 * (eta * 205.04051835490429 - 120.8745078663875)) + xi *
                ((t2 * 195.78038876617819 - t51) + 66.614378277661473)) - 10.0;
    b_dv[16] = (t6 * 2.6457513110645907 * -3.5 + t5 * (11.905880899790658 - t16))
      - xi * (2.6457513110645907 - t15);
    b_dv[17] = ((((eta * 18.0 - t2 * 63.0) + t10) + t5 * (2.6457513110645907 -
      t16)) - xi * ((2.6457513110645907 - t20) + t26 * 10.5)) - 1.0;
    b_dv[18] = (t6 * -116.9027831039519 - xi * ((-t53 + t74) + 69.69079963456926))
      - t5 * (t48 - 183.77325438263631);
    b_dv[19] = (t6 * 74.666666666666671 + xi * ((t82 - t108) +
      7.8326771551833918)) + t5 * (t46 - 77.166010488516719);
    b_dv[20] = (t6 * -13.76388356271481 + t5 * (t63 - 3.0131247939101931)) + xi *
      ((-t62 + t121) + 3.2640033791765219);
    b_dv[21] = (t107 + t5 * (t57 - 41.498624153858572)) - xi * ((t90 +
      -6.1734197258173786) + t121);
    b_dv[22] = (t127 + t5 * (eta * 101.1172354405106 - 15.72462820877201)) + xi *
      ((-t59 + t108) + 3.7786526819777);
    b_dv[23] = (-t128 + xi * ((6.1734197258173786 - t43) + t74)) + t5 * (t57 -
      0.621851004803674);
    b_dv[24] = (((((eta * -49.588636801975788 + t2 * 163.9219701353091) - t23) +
                  t128) + t5 * (t63 - 8.8155721001902254)) - xi * ((t2 *
      41.291650688144429 + t95) - 3.2640033791765219)) + 2.820328355884854;
    b_dv[25] = (((((eta * 85.333333333333329 + t3 * 149.33333333333334) - t13) -
                  t127) + t5 * (t46 + 4.1132983716109166)) + xi * ((t13 - t50) +
      7.8326771551833918)) - 5.333333333333333;
    b_dv[26] = (((((eta * -113.7446965313575 + t2 * 228.0780298646909) - t23) -
                  t107) - t5 * (t48 - 105.01600406261041)) - xi * ((t2 *
      350.70834931185561 - t39) + 69.69079963456926)) + 13.51300497744848;
    b_dv[27] = (t97 + xi * ((83.3411662985346 - t40) + t70)) + t5 * (eta *
      420.56725696865982 - 188.48298054069949);
    b_dv[28] = (-t97 - t5 * (t45 - 126.94246218579531)) + xi * (t55 -
      21.800647943630331);
    b_dv[29] = -xi * ((-t42 + t70) + 21.800647943630331) - t5 * (t45 -
      21.800647943630331);
    i = 0;
    i1 = 0;
    for (int i2{0}; i2 < 30; i2++) {
      deriv[i1 + (i << 1)] = b_dv[i2];
      i++;
      if (i > 14) {
        i = 0;
        i1++;
      }
    }
  }

  static inline
  void tri_gl_21(double xi, double eta, double shape_funcs[21], double
                        deriv[42])
  {
    double b_dv[42];
    double t10;
    double t100;
    double t104;
    double t105;
    double t106;
    double t109;
    double t11;
    double t111;
    double t112;
    double t114;
    double t115;
    double t117;
    double t119;
    double t12;
    double t122;
    double t123;
    double t124;
    double t126;
    double t128;
    double t13;
    double t131;
    double t132;
    double t133;
    double t134;
    double t135;
    double t136;
    double t14;
    double t140;
    double t142;
    double t143;
    double t146;
    double t147;
    double t149;
    double t15;
    double t150;
    double t151;
    double t152;
    double t153;
    double t156;
    double t157;
    double t16;
    double t161;
    double t164;
    double t167;
    double t175;
    double t18;
    double t180;
    double t181;
    double t189;
    double t19;
    double t190;
    double t194;
    double t195;
    double t2;
    double t20;
    double t200;
    double t200_tmp;
    double t201;
    double t205;
    double t21;
    double t211;
    double t212;
    double t217;
    double t218;
    double t220;
    double t221;
    double t227;
    double t229;
    double t231;
    double t233;
    double t234;
    double t239;
    double t24;
    double t240;
    double t241;
    double t245;
    double t246;
    double t247;
    double t249;
    double t251;
    double t252;
    double t254;
    double t255;
    double t256;
    double t258;
    double t259;
    double t26;
    double t262;
    double t263;
    double t265;
    double t267;
    double t268;
    double t269;
    double t27;
    double t277;
    double t278;
    double t28;
    double t286;
    double t287;
    double t288;
    double t289;
    double t29;
    double t291;
    double t292;
    double t295;
    double t297;
    double t298;
    double t299;
    double t3;
    double t300;
    double t301;
    double t302;
    double t303;
    double t304;
    double t307;
    double t309;
    double t31;
    double t33;
    double t35;
    double t38;
    double t4;
    double t40;
    double t41;
    double t44;
    double t45;
    double t46;
    double t47;
    double t48;
    double t49;
    double t5;
    double t51;
    double t52;
    double t54;
    double t55;
    double t56;
    double t57;
    double t58;
    double t59;
    double t6;
    double t60;
    double t64;
    double t65;
    double t66;
    double t67;
    double t69;
    double t7;
    double t72;
    double t73;
    double t74;
    double t75;
    double t77;
    double t78;
    double t79;
    double t8;
    double t80;
    double t81;
    double t82;
    double t83;
    double t85;
    double t86;
    double t87;
    double t89;
    double t9;
    double t91;
    double t92;
    double t93;
    double t95;
    double t96;
    double t97;
    double t98;
    double t99;
    int i;
    int i1;

    // TRI_GL_21    Quintic triangular element with Gauss-Lobatto points
    t2 = eta * eta;
    t3 = std::pow(eta, 3.0);
    t5 = std::pow(eta, 5.0);
    t6 = xi * xi;
    t7 = std::pow(xi, 3.0);
    t9 = std::pow(xi, 5.0);
    t14 = eta * 1571.2820245706239;
    t16 = eta * 919.2843739283162;
    t18 = eta * 3.08454769850681;
    t19 = eta * 2660.6480686153409;
    t20 = eta * 208.806976365287;
    t21 = eta * 758.45946965882149;
    t24 = eta * 1024.381684660445;
    t26 = eta * 510.25546888786431;
    t27 = eta * 1601.6453258779129;
    t28 = eta * 1831.2947667511851;
    t33 = eta * 1932.570567583459;
    t35 = eta * 405.98957894857438;
    t38 = eta * 326.39925920100359;
    t40 = eta * 25.83708989075333;
    t45 = eta * 1023.178558908606;
    t46 = eta * 715.69567997785646;
    t47 = eta * 58.255830971139723;
    t48 = eta * 161.330908345799;
    t55 = eta * 129.30296565255219;
    t56 = eta * 172.22545153592509;
    t57 = eta * 72.453852661706549;
    t58 = eta * 172.54443075650971;
    t59 = eta * 250.31860450203979;
    t60 = eta * 238.67993488322861;
    t64 = eta * 86.70850526258485;
    t65 = eta * 191.64921549063189;
    t67 = eta * 34.0145953177231;
    t73 = eta * 5.0520451128222348;
    t77 = eta * 68.482394961168623;
    t83 = eta * 59.372840853710969;
    t86 = eta * 35.4703755031302;
    t91 = eta * 53.765587766506627;
    t93 = eta * 23.005029484075049;
    t99 = eta * 74.981502057742873;
    t100 = eta * 12.97711087614652;
    t104 = eta * 9.292633736045719;
    t109 = eta * 10.679368320188219;
    t111 = eta * 16.88214348258024;
    t119 = eta * 7.938702855218259;
    t132 = eta * 3.501286404027534;
    t156 = eta * 7.4689466124992041;
    t161 = eta * 1.6229129791975;
    t167 = eta * 5.634639814494169;
    t180 = eta * 9.3041397487953272;
    t4 = t2 * t2;
    t8 = t6 * t6;
    t10 = t5 * 42.0;
    t11 = t9 * 42.0;
    t15 = t2 * 785.64101228531217;
    t41 = t2 * 104.4034881826435;
    t44 = t3 * 64.419192906065064;
    t51 = t3 * 629.44100473587059;
    t52 = t2 * 2660.6480686153409;
    t66 = t2 * 656.56043321088214;
    t69 = t2 * 1198.371170146241;
    t72 = t3 * 1656.0840578327941;
    t74 = t2 * 966.2852837917294;
    t75 = t2 * 1932.570567583459;
    t78 = t2 * 1518.414259102035;
    t80 = t2 * 1325.15668038384;
    t81 = t2 * 379.22973482941069;
    t82 = t2 * 758.45946965882149;
    t89 = t2 * 2746.942150126778;
    t92 = t2 * 512.19084233022272;
    t95 = t2 * 1330.32403430767;
    t96 = t2 * 3769.8810033521409;
    t97 = t2 * 1752.4468214974211;
    t98 = t2 * 2752.2725663360688;
    t105 = t3 * 1127.029968909131;
    t106 = t2 * 2051.2018592935628;
    t112 = t2 * 349.13653236758609;
    t114 = t3 * 1831.2947667511851;
    t115 = t2 * 1311.9871538318471;
    t117 = t3 * 38.043689593656516;
    t122 = t2 * 250.31860450203979;
    t123 = t2 * 119.33996744161431;
    t124 = t2 * 238.67993488322861;
    t126 = t2 * 445.15968237890309;
    t133 = t2 * 109.6591932766143;
    t135 = t2 * 143.24735288510729;
    t136 = t3 * 34.533102189620621;
    t140 = t2 * 95.824607745315944;
    t142 = t3 * 98.952295095685685;
    t143 = t2 * 162.52602751994269;
    t146 = t2 * 202.99478947428719;
    t147 = t2 * 405.98957894857438;
    t149 = t3 * 731.48307072622345;
    t151 = t2 * 275.133463376943;
    t152 = t2 * 163.19962960050179;
    t153 = t2 * 326.39925920100359;
    t164 = t2 * 196.55829453585511;
    t175 = t3 * 58.255830971139723;
    t181 = t3 * 915.64738337559254;
    t189 = t2 * 37.490751028871443;
    t190 = t2 * 74.981502057742873;
    t194 = t2 * 125.15930225101989;
    t195 = t2 * 50.977203658315076;
    t200_tmp = eta * t7;
    t200 = t200_tmp * -64.419192906065064;
    t201 = t5 * 100.0722106463179;
    t205 = t9 * 100.0722106463179;
    t211 = t2 * 17.00729765886155;
    t212 = t2 * 87.383746456709574;
    t217 = t3 * 102.474633614432;
    t221 = t2 * 91.6156930525829;
    t227 = t5 * 121.1674570846437;
    t229 = t2 * 17.7351877515651;
    t231 = t9 * 121.1674570846437;
    t233 = t3 * 26.191722947029319;
    t234 = t3 * 29.127915485569861;
    t239 = t200_tmp * -1656.0840578327941;
    t240 = t3 * 0.81145648959875016;
    t241 = t3 * 1.6229129791975;
    t245 = t3 * 4.2275963557195144;
    t246 = t2 * 2.817319907247084;
    t247 = t2 * 5.634639814494169;
    t249 = t3 * 10.242096430396639;
    t251 = t2 * 5.3396841600941114;
    t254 = t7 * (eta * 731.48307072622345);
    t256 = t2 * 3.96935142760913;
    t258 = t3 * 6.0145000746771249;
    t263 = t2 * 2.43436946879625;
    t268 = t3 * 2.4687112217243512;
    t277 = t7 * (eta * 102.474633614432);
    t286 = t200_tmp * -26.191722947029319;
    t287 = t200_tmp * -6.0145000746771249;
    t12 = t4 * 210.0;
    t13 = t8 * 210.0;
    t29 = t4 * 605.83728542321842;
    t31 = t8 * 605.83728542321842;
    t49 = t4 * 500.36105323158972;
    t54 = t8 * 500.36105323158972;
    t79 = t4 * 516.63321400870927;
    t85 = t4 * 16.104798226516269;
    t87 = t8 * 16.104798226516269;
    t128 = t4 * 414.02101445819852;
    t131 = t4 * 264.58107075144687;
    t134 = t8 * 414.02101445819852;
    t150 = t4 * 182.87076768155589;
    t157 = t8 * 182.87076768155589;
    t218 = t4 * 25.618658403608;
    t220 = t8 * 25.618658403608;
    t200_tmp = eta * t8;
    t252 = t200_tmp * -16.104798226516269;
    t255 = t8 * (eta * 182.87076768155589);
    t259 = t4 * 1.503625018669281;
    t262 = t8 * 1.503625018669281;
    t265 = t4 * 6.5479307367573307;
    t267 = t8 * 6.5479307367573307;
    t269 = t200_tmp * -414.02101445819852;
    t278 = t8 * (eta * 25.618658403608);
    t288 = t200_tmp * -1.503625018669281;
    t289 = t200_tmp * -6.5479307367573307;
    t291 = ((t18 + t2 * 36.226926330853267) + t4 * 189.338279587429) - t3 *
      220.5773790761784;
    t299 = ((-t91 + t2 * 511.58927945430293) + t4 * 457.82369168779633) - t181;
    t300 = ((t4 * 16.2721607771195 + t2 * 64.65148282627608) - t3 *
            91.902335727239574) - t180;
    t301 = ((t150 + t2 * 86.112725767962573) - t156) - t3 * 241.2317149643799;
    t302 = ((t93 + t4 * 14.563957742784931) - t234) - t2 * 8.4410717412901182;
    t303 = ((-t132 + t218) + t2 * 34.241197480584312) - t3 * 64.43094402077547;
    t304 = (((t73 + t4 * 0.40572824479937508) - t240) - t2 * 4.6463168680228586)
      + 1.0;
    t307 = (((t2 * 459.6421869641581 - t58) + t150) - t3 * 490.25135576184363) +
      20.282831872639338;
    t292 = ((eta * 204.9033389824165 + t3 * 1009.940338414738) - t128) - t2 *
      800.82266293895634;
    t295 = ((t3 * 646.14371941805553 + t93) - t128) - t2 * 255.1277344439321;
    t297 = ((t40 + t3 * 744.020386637612) - t4 * 416.49900583578938) - t2 *
      357.84783998892817;
    t298 = ((t3 * 92.883278269917128 + t73) - t2 * 43.354252631292432) - t4 *
      54.581070751446937;
    t309 = (((t18 + t3 * 28.660434168753671) - t2 * 29.686420426855481) - t265)
      + 4.4893692963523337;
    shape_funcs[0] = (((((((((eta * -15.0 + t2 * 70.0) - t3 * 140.0) + t4 *
      126.0) - t10) - t11) + t8 * (126.0 - eta * 264.58107075144687)) - t7 *
                        ((eta * -629.44100473587059 + t2 * 584.14894049914017) +
                         140.0)) - t6 * (((eta * 512.19084233022272 - t2 *
      1007.287737716541) + t3 * 584.14894049914017) - 70.0)) - xi * ((((-t48 -
      t51) + t92) + t131) + 15.0)) + 1.0;
    shape_funcs[1] = (((t11 + t304 * xi) - t6 * (((eta * 43.354252631292432 -
      t189) - t240) + 14.0)) - t8 * (eta * 54.581070751446937 + 84.0)) + t7 *
      ((eta * 92.883278269917128 - t2 * 54.17534250664756) + 56.0);
    shape_funcs[2] = (((((((eta - t2 * 14.0) + t3 * 56.0) - t4 * 84.0) + t10) +
                        t200_tmp * 0.40572824479937508) - t6 * ((eta *
      4.6463168680228586 + t3 * 54.17534250664756) - t189)) + t298 * xi) - t7 *
      (eta * 0.81145648959875016 - t2 * 0.81145648959875016);
    shape_funcs[3] = (((t205 + t7 * ((eta * -1127.029968909131 + t2 *
      917.42418877868977) + 299.68785732601259)) + t8 * (eta *
      516.63321400870927 - 288.46091538197311)) + t307 * xi) + t6 * (((eta *
      785.64101228531217 + t3 * 683.73395309785428) - t95) - 131.58198446299679);
    shape_funcs[4] = (((-t231 - t6 * (((eta * 357.84783998892817 + t3 *
      116.3788441225287) - t81) - 98.49823568607377)) + t8 * (320.1990314777874
      - eta * 416.49900583578938)) - t7 * ((eta * -744.020386637612 + t2 *
      437.32905127728242) + 289.45743553860677)) - xi * ((((-t40 + t117) - t218)
      + t251) + 8.0723745406106957);
    shape_funcs[5] = (((t231 + t309 * xi) + t6 * (((eta * 36.226926330853267 -
      t3 * 91.711154458981014) + t123) - 60.354452909459013)) + t8 * (eta *
      189.338279587429 - 285.638253945431)) - t7 * ((eta * 220.5773790761784 +
      t2 * 16.99240121943836) - 220.335880473894);
    shape_funcs[6] = (((-t205 - xi * ((((t180 - t229) + t245) + t259) +
      2.699826628380976)) - t7 * ((eta * 91.902335727239574 - t2 *
      148.38656079296771) + 146.5663022612998)) + t8 * (eta * 16.2721607771195 +
      211.9001378496167)) + t6 * (((eta * 64.65148282627608 + t3 *
      30.53856435086097) - t194) + 37.438201686382072);
    shape_funcs[7] = ((t255 - xi * (((t156 - t249) + t256) + t259)) - t7 * (eta *
      241.2317149643799 - t2 * 47.7491176283691)) - t6 * ((eta *
      -86.112725767962573 + t3 * 36.553064425538089) + t246);
    shape_funcs[8] = ((t278 - t7 * (eta * 64.43094402077547 - t2 *
      218.85347773696071)) - xi * (((t132 - t211) + t265) + t268)) + t6 * ((eta *
      34.241197480584312 + t3 * 65.5194315119517) - t152);
    shape_funcs[9] = ((t289 + t303 * xi) + t6 * ((eta * 17.00729765886155 + t3 *
      218.85347773696071) - t152)) - t7 * (eta * 2.4687112217243512 - t2 *
      65.5194315119517);
    shape_funcs[10] = ((t288 + t301 * xi) - t6 * ((eta * 3.96935142760913 - t3 *
      47.7491176283691) + t246)) + t7 * (eta * 10.242096430396639 - t2 *
      36.553064425538089);
    shape_funcs[11] = (((((((eta * -2.699826628380976 + t2 * 37.438201686382072)
      - t3 * 146.5663022612998) + t4 * 211.9001378496167) - t201) + t288) + t300
                        * xi) + t6 * ((eta * 17.7351877515651 + t3 *
      148.38656079296771) - t194)) - t7 * (eta * 4.2275963557195144 - t2 *
      30.53856435086097);
    shape_funcs[12] = (((((((eta * 4.4893692963523337 - t2 * 60.354452909459013)
      + t3 * 220.335880473894) - t4 * 285.638253945431) + t227) + t289) - t6 *
                        ((eta * 29.686420426855481 + t3 * 16.99240121943836) -
                         t123)) + t291 * xi) + t7 * (eta * 28.660434168753671 -
      t2 * 91.711154458981014);
    shape_funcs[13] = (((((((eta * -8.0723745406106957 + t2 * 98.49823568607377)
      - t3 * 289.45743553860677) + t4 * 320.1990314777874) - t227) + t278) +
                        t297 * xi) - t6 * ((eta * 5.3396841600941114 + t3 *
      437.32905127728242) - t81)) - t7 * (eta * 38.043689593656516 + t2 *
      116.3788441225287);
    shape_funcs[14] = (((((((eta * 20.282831872639338 - t2 * 131.58198446299679)
      + t3 * 299.68785732601259) - t4 * 288.46091538197311) + t201) + t255) - t7
                        * (eta * 490.25135576184363 - t2 * 683.73395309785428))
                       + xi * (((t15 - t58) + t79) - t105)) + t6 * ((eta *
      459.6421869641581 + t3 * 917.42418877868977) - t95);
    shape_funcs[15] = ((t269 + t292 * xi) - t6 * ((eta * 800.82266293895634 - t2
      * 2034.444634572262) + t3 * 1256.62700111738)) + t7 * (eta *
      1009.940338414738 - t2 * 1256.62700111738);
    shape_funcs[16] = ((t6 * ((eta * 511.58927945430293 + t3 * 441.71889346128)
      - t74) + t200_tmp * 457.82369168779633) - xi * (((-t41 + t85) + t91) +
      t136)) - t7 * (eta * 915.64738337559254 - t2 * 915.64738337559254);
    shape_funcs[17] = ((t269 + t7 * (eta * 646.14371941805553 - t2 *
      399.45705671541361)) + t302 * xi) + t6 * ((eta * -255.1277344439321 + t146)
      + t234);
    shape_funcs[18] = ((t252 + t7 * (eta * 98.952295095685685 - t2 *
      506.13808636734512)) - t6 * ((eta * 95.824607745315944 - t2 *
      655.72828187916764) + t3 * 506.13808636734512)) - xi * (((t85 - t100) +
      t140) - t142);
    shape_funcs[19] = ((t200_tmp * 14.563957742784931 + t295 * xi) - t7 * (eta *
      29.127915485569861 - t2 * 29.127915485569861)) - t6 * ((eta *
      8.4410717412901182 + t3 * 399.45705671541361) - t146);
    shape_funcs[20] = ((t252 - t7 * (eta * 34.533102189620621 - t2 *
      441.71889346128)) + t6 * ((eta * 104.4034881826435 - t74) + t181)) + t299 *
      xi;
    b_dv[0] = (((-t13 + ((((t48 + t51) - t92) - t131) - 15.0)) + t7 * (504.0 -
      eta * 1058.3242830057879)) + xi * (((t2 * 2014.575475433081 - t3 *
      1168.29788099828) - t24) + 140.0)) - t6 * ((eta * -1888.323014207612 + t97)
      + 420.0);
    b_dv[1] = (((t13 + t304) - t7 * (eta * 218.32428300578769 + 336.0)) + xi *
               (((-t64 + t190) + t241) - 28.0)) + t6 * ((eta *
      278.64983480975138 - t143) + 168.0);
    b_dv[2] = ((t298 + t7 * t161) - t6 * (eta * 2.43436946879625 - t263)) - xi *
      ((t3 * 108.35068501329511 + t104) - t190);
    b_dv[3] = (((t54 + t307) + t7 * (eta * 2066.5328560348371 -
      1153.843661527892)) + xi * (((t3 * 1367.467906195709 + t14) - t52) -
                263.16396892599357)) + t6 * ((eta * -3381.0899067273922 + t98) +
      899.06357197803788);
    b_dv[4] = (((-t31 + ((((t40 - t117) + t218) - t251) - 8.0723745406106957)) -
                xi * (((t3 * 232.75768824505741 + t46) - t82) -
                      196.99647137214751)) + t7 * (1280.79612591115 - eta *
                1665.996023343158)) - t6 * ((eta * -2232.061159912836 + t115) +
      868.37230661582043);
    b_dv[5] = (((t31 + t309) + t7 * (eta * 757.353118349716 - 1142.5530157817241))
               - t6 * ((eta * 661.73213722853518 + t195) - 661.007641421682)) -
      xi * (((t3 * 183.422308917962 - t57) - t124) + 120.708905818918);
    b_dv[6] = (((-t54 + ((((t229 - t180) - t245) - t259) - 2.699826628380976)) -
                t6 * ((eta * 275.70700718171872 - t126) + 439.69890678389942)) +
               t7 * (eta * 65.088643108477982 + 847.60055139846668)) + xi *
      (((t3 * 61.077128701721932 + t55) - t122) + 74.87640337276413);
    b_dv[7] = ((t254 + (((-t156 + t249) - t256) - t259)) - xi * ((t3 *
      73.106128851076178 - t56) + t247)) - t6 * (eta * 723.69514489313963 - t135);
    b_dv[8] = ((t277 + (((-t132 + t211) - t265) - t268)) + xi * ((t3 *
      131.03886302390339 + t77) - t153)) - t6 * (eta * 193.2928320623264 - t66);
    b_dv[9] = ((t286 + t303) - t6 * (eta * 7.4061336651730523 - t164)) + xi *
      ((t3 * 437.70695547392143 + t67) - t153);
    b_dv[10] = ((t287 + t301) - xi * ((t3 * -95.4982352567382 + t119) + t247)) +
      t6 * (eta * 30.726289291189911 - t133);
    b_dv[11] = ((t287 + t300) - t6 * (eta * 12.68278906715854 - t221)) + xi *
      ((t3 * 296.77312158593543 + t86) - t122);
    b_dv[12] = ((t286 + t291) + t6 * (eta * 85.981302506261017 - t151)) - xi *
      ((t3 * 33.98480243887672 + t83) - t124);
    b_dv[13] = ((t277 + t297) - xi * ((t3 * 874.65810255456483 - t82) + t109)) -
      t6 * (eta * 114.1310687809696 + t112);
    b_dv[14] = ((t254 + (((t15 + t79) - t58) - t105)) + xi * ((t3 *
      1834.84837755738 + t16) - t52)) - t6 * (eta * 1470.7540672855309 - t106);
    b_dv[15] = ((t239 + t292) - xi * ((t2 * -4068.889269144523 + t3 *
      2513.2540022347612) + t27)) + t6 * (eta * 3029.8210152442148 - t96);
    b_dv[16] = (((((t41 - t85) - t91) - t136) + xi * ((t3 * 883.43778692256 +
      t45) - t75)) - t6 * (eta * 2746.942150126778 - t89)) + t7 * t28;
    b_dv[17] = ((t239 + t302) + xi * ((-t26 + t147) + t175)) + t6 * (eta *
      1938.431158254167 - t69);
    b_dv[18] = ((t200 + (((t100 + t142) - t85) - t140)) + t6 * (eta *
      296.85688528705708 - t78)) - xi * ((t2 * -1311.4565637583351 + t3 *
      1012.27617273469) + t65);
    b_dv[19] = ((t295 - t6 * (eta * 87.383746456709574 - t212)) + t7 * t47) - xi
      * ((t3 * 798.91411343082711 + t111) - t147);
    b_dv[20] = ((t200 + t299) - t6 * (eta * 103.59930656886191 - t80)) + xi *
      ((t20 + t114) - t75);
    b_dv[21] = (((((((eta * 140.0 - t2 * 420.0) + t3 * 504.0) - t8 *
                    264.58107075144687) - t12) - t6 * ((eta * -2014.575475433081
      + t97) + 512.19084233022272)) + t7 * (629.44100473587059 - eta *
      1168.29788099828)) + xi * (((t2 * 1888.323014207612 - t3 *
      1058.3242830057879) - t24) + 161.330908345799)) - 15.0;
    b_dv[22] = ((t8 * -54.581070751446937 + t7 * (92.883278269917128 - eta *
      108.35068501329511)) + t6 * ((t99 + t263) - 43.354252631292432)) - xi *
      (((t104 - t241) + t263) - 5.0520451128222348);
    b_dv[23] = (((((((eta * -28.0 + t2 * 168.0) - t3 * 336.0) + t8 *
                    0.40572824479937508) + t12) - t6 * ((-t99 + t143) +
      4.6463168680228586)) + t7 * (t161 - 0.81145648959875016)) + xi * (((t2 *
      278.64983480975138 - t3 * 218.32428300578769) - t64) + 5.0520451128222348))
      + 1.0;
    b_dv[24] = ((t8 * 516.63321400870927 + t6 * ((-t19 + t106) +
      785.64101228531217)) - xi * (((t2 * 1470.7540672855309 - t16) - t149) +
      172.54443075650971)) + t7 * (eta * 1834.84837755738 - 1127.029968909131);
    b_dv[25] = ((t8 * -416.49900583578938 - t6 * ((-t21 + t112) +
      357.84783998892817)) - xi * (((t2 * 114.1310687809696 + t109) - t217) -
      25.83708989075333)) + t7 * (744.020386637612 - eta * 874.65810255456483);
    b_dv[26] = ((t8 * 189.338279587429 + t6 * ((t60 - t151) + 36.226926330853267))
                + xi * (((t2 * 85.981302506261017 - t83) - t233) +
                        3.08454769850681)) - t7 * (eta * 33.98480243887672 +
      220.5773790761784);
    b_dv[27] = ((t8 * 16.2721607771195 - xi * (((t2 * 12.68278906715854 - t86) +
      t258) + 9.3041397487953272)) + t7 * (eta * 296.77312158593543 -
      91.902335727239574)) + t6 * ((-t59 + t221) + 64.65148282627608);
    b_dv[28] = ((t157 - t6 * ((t133 + t167) - 86.112725767962573)) - xi * (((t2 *
      -30.726289291189911 + t119) + t258) + 7.4689466124992041)) + t7 * (eta *
      95.4982352567382 - 241.2317149643799);
    b_dv[29] = ((t220 - xi * (((t2 * 7.4061336651730523 - t67) + t233) +
      3.501286404027534)) + t7 * (eta * 437.70695547392143 - 64.43094402077547))
      + t6 * ((-t38 + t164) + 34.241197480584312);
    b_dv[30] = ((-t267 - xi * (((t2 * 193.2928320623264 - t77) - t217) +
      3.501286404027534)) + t6 * ((t66 - t38) + 17.00729765886155)) + t7 * (eta *
      131.03886302390339 - 2.4687112217243512);
    b_dv[31] = ((-t262 - xi * (((t2 * 723.69514489313963 - t56) - t149) +
      7.4689466124992041)) - t6 * ((-t135 + t167) + 3.96935142760913)) + t7 *
      (10.242096430396639 - eta * 73.106128851076178);
    b_dv[32] = (((((((eta * 74.87640337276413 - t2 * 439.69890678389942) + t3 *
                     847.60055139846668) - t49) - t262) - xi * (((t2 *
      275.70700718171872 - t3 * 65.088643108477982) - t55) + 9.3041397487953272))
                 + t6 * ((-t59 + t126) + 17.7351877515651)) + t7 * (eta *
      61.077128701721932 - 4.2275963557195144)) - 2.699826628380976;
    b_dv[33] = (((((((eta * -120.708905818918 + t2 * 661.007641421682) - t3 *
                     1142.5530157817241) + t29) - t267) - t6 * ((-t60 + t195) +
      29.686420426855481)) + xi * (((t2 * -661.73213722853518 + t3 *
      757.353118349716) + t57) + 3.08454769850681)) + t7 * (28.660434168753671 -
      eta * 183.422308917962)) + 4.4893692963523337;
    b_dv[34] = (((((((eta * 196.99647137214751 - t2 * 868.37230661582043) + t3 *
                     1280.79612591115) - t29) + t220) + xi * (((t2 *
      2232.061159912836 - t3 * 1665.996023343158) - t46) + 25.83708989075333)) -
                 t6 * ((-t21 + t115) + 5.3396841600941114)) - t7 * (eta *
      232.75768824505741 + 38.043689593656516)) - 8.0723745406106957;
    b_dv[35] = (((((((eta * -263.16396892599357 + t2 * 899.06357197803788) - t3 *
                     1153.843661527892) + t49) + t157) + t6 * ((-t19 + t98) +
      459.6421869641581)) + t7 * (eta * 1367.467906195709 - 490.25135576184363))
                - xi * (((t2 * 3381.0899067273922 - t3 * 2066.5328560348371) -
                         t14) + 172.54443075650971)) + 20.282831872639338;
    b_dv[36] = ((-t134 - t6 * ((eta * -4068.889269144523 + t96) +
      800.82266293895634)) + xi * (((t2 * 3029.8210152442148 - t27) - t72) +
      204.9033389824165)) + t7 * (1009.940338414738 - eta * 2513.2540022347612);
    b_dv[37] = ((t8 * 457.82369168779633 + t7 * (t28 - 915.64738337559254)) - xi
                * (((t2 * 103.59930656886191 - t20) + t44) + 53.765587766506627))
      + t6 * ((-t33 + t80) + 511.58927945430293);
    b_dv[38] = ((-t134 + t7 * (646.14371941805553 - eta * 798.91411343082711)) +
                t6 * ((t35 + t212) - 255.1277344439321)) - xi * (((t111 - t175)
      + t212) - 23.005029484075049);
    b_dv[39] = ((-t87 - t6 * ((eta * -1311.4565637583351 + t78) +
      95.824607745315944)) + t7 * (98.952295095685685 - eta * 1012.27617273469))
      + xi * (((t2 * 296.85688528705708 - t44) - t65) + 12.97711087614652);
    b_dv[40] = ((t8 * 14.563957742784931 + xi * (((t2 * 1938.431158254167 - t26)
      - t72) + 23.005029484075049)) + t7 * (t47 - 29.127915485569861)) - t6 * ((
      -t35 + t69) + 8.4410717412901182);
    b_dv[41] = ((-t87 + t7 * (eta * 883.43778692256 - 34.533102189620621)) + t6 *
                ((-t33 + t89) + 104.4034881826435)) + xi * (((t45 - t89) + t114)
      - 53.765587766506627);
    i = 0;
    i1 = 0;
    for (int i2{0}; i2 < 42; i2++) {
      deriv[i1 + (i << 1)] = b_dv[i2];
      i++;
      if (i > 20) {
        i = 0;
        i1++;
      }
    }
  }

  static inline
  void sfe_apply_dbc1(::coder::array<double, 2U> &elemmat, ::coder::array<double,
                      1U> &load, const ::coder::array<boolean_T, 1U> &dtags,
                      const ::coder::array<double, 1U> &dvals, const ::coder::
                      array<int, 1U> &gdofs)
  {
    int n;

    // sfe_apply_dbc - Apply Dirichlet boundary conditions (DBC)
    n = elemmat.size(0);
    for (int i{0}; i < n; i++) {
      if (dtags[gdofs[i] - 1]) {
        double dv_tmp;
        int b_i;
        int j;

        //  not a dirichlet node
        dv_tmp = dvals[gdofs[i] - 1];
        for (j = 0; j < i; j++) {
          load[j] = load[j] - elemmat[i + elemmat.size(1) * j] * dv_tmp;
          elemmat[i + elemmat.size(1) * j] = 0.0;
        }

        b_i = i + 2;
        for (j = b_i; j <= n; j++) {
          load[j - 1] = load[j - 1] - elemmat[i + elemmat.size(1) * (j - 1)] *
            dv_tmp;
          elemmat[i + elemmat.size(1) * (j - 1)] = 0.0;
        }

        b_i = elemmat.size(1);
        for (j = 0; j < b_i; j++) {
          elemmat[j + elemmat.size(1) * i] = 0.0;
        }

        elemmat[i + elemmat.size(1) * i] = 1.0;
        load[i] = dv_tmp;
      }
    }
  }

  static inline
  void sfe_apply_dbc2(::coder::array<double, 2U> &elemmat, ::coder::array<double,
                      1U> &load, const ::coder::array<boolean_T, 1U> &dtags,
                      const ::coder::array<double, 1U> &dvals)
  {
    int n;

    // sfe_apply_dbc - Apply Dirichlet boundary conditions (DBC)
    n = elemmat.size(0);
    for (int i{0}; i < n; i++) {
      if (dtags[i]) {
        double b_dv;
        int b_i;
        int j;

        //  not a dirichlet node
        b_dv = dvals[i];
        for (j = 0; j < i; j++) {
          load[j] = load[j] - elemmat[i + elemmat.size(1) * j] * b_dv;
          elemmat[i + elemmat.size(1) * j] = 0.0;
        }

        b_i = i + 2;
        for (j = b_i; j <= n; j++) {
          load[j - 1] = load[j - 1] - elemmat[i + elemmat.size(1) * (j - 1)] *
            b_dv;
          elemmat[i + elemmat.size(1) * (j - 1)] = 0.0;
        }

        b_i = elemmat.size(1);
        for (j = 0; j < b_i; j++) {
          elemmat[j + elemmat.size(1) * i] = 0.0;
        }

        elemmat[i + elemmat.size(1) * i] = 1.0;
        load[i] = dvals[i];
      }
    }
  }

  static inline
  void sfe_elem_le3d1(SfeObject *b_sfe, double nu, double lambda, ::coder::array<
                      double, 2U> &elemmat)
  {
    double d;
    int b_i;
    int i;
    int i3;
    int j;
    int j3;
    int m;
    int n;
    int y_tmp;

    // sfe_elem_le3d - Computing the stiffness matrix for linear elasticity in 3D
    n = b_sfe->nnodes[0];
    y_tmp = b_sfe->nnodes[0] * 3;
    elemmat.set_size(y_tmp, y_tmp);
    y_tmp *= y_tmp;
    for (i = 0; i < y_tmp; i++) {
      elemmat[i] = 0.0;
    }

    d = lambda + 2.0 * nu;

    //  loop through all quadrature points
    i = b_sfe->nqp;
    for (int q{0}; q < i; q++) {
      double wdetj;

      //  initialize gradient
      sfe_init_grad(b_sfe, q + 1);
      wdetj = b_sfe->wdetJ[q];
      for (b_i = 0; b_i < n; b_i++) {
        double vx;
        double vy;
        double vz;
        vx = b_sfe->grads_test[b_sfe->grads_test.size(1) * b_i] * wdetj;

        //  multiplied with wdetj
        vy = b_sfe->grads_test[b_sfe->grads_test.size(1) * b_i + 1] * wdetj;
        vz = b_sfe->grads_test[b_sfe->grads_test.size(1) * b_i + 2] * wdetj;
        i3 = b_i * 3;
        for (j = b_i + 1; j <= n; j++) {
          double b_elemmat_tmp;
          double c_elemmat_tmp;
          double elemmat_tmp;
          double ux;
          double uy;
          double uz;
          j3 = (j - 1) * 3 + 2;
          ux = b_sfe->grads_trial[b_sfe->grads_trial.size(1) * (j - 1)];
          uy = b_sfe->grads_trial[b_sfe->grads_trial.size(1) * (j - 1) + 1];
          uz = b_sfe->grads_trial[b_sfe->grads_trial.size(1) * (j - 1) + 2];

          //  use order of standard engineering notation for symmetric  tensors
          elemmat_tmp = ux * vx;
          b_elemmat_tmp = uz * vz;
          c_elemmat_tmp = uy * vy;
          elemmat[(j3 + elemmat.size(1) * i3) - 2] = (elemmat[(j3 + elemmat.size
            (1) * i3) - 2] + nu * (c_elemmat_tmp + b_elemmat_tmp)) + elemmat_tmp
            * d;
          elemmat[(j3 + elemmat.size(1) * (i3 + 1)) - 1] = (elemmat[(j3 +
            elemmat.size(1) * (i3 + 1)) - 1] + nu * (elemmat_tmp + b_elemmat_tmp))
            + c_elemmat_tmp * d;
          elemmat[j3 + elemmat.size(1) * (i3 + 2)] = (elemmat[j3 + elemmat.size
            (1) * (i3 + 2)] + nu * (elemmat_tmp + c_elemmat_tmp)) +
            b_elemmat_tmp * d;
          elemmat_tmp = lambda * ux;
          elemmat[(j3 + elemmat.size(1) * i3) - 1] = (elemmat[(j3 + elemmat.size
            (1) * i3) - 1] + elemmat_tmp * vy) + nu * uy * vx;
          b_elemmat_tmp = nu * uz;
          elemmat[j3 + elemmat.size(1) * (i3 + 1)] = (elemmat[j3 + elemmat.size
            (1) * (i3 + 1)] + lambda * uy * vz) + b_elemmat_tmp * vy;
          elemmat[j3 + elemmat.size(1) * i3] = (elemmat[j3 + elemmat.size(1) *
            i3] + elemmat_tmp * vz) + b_elemmat_tmp * vx;
        }
      }
    }

    //  fill in lower part
    for (b_i = 0; b_i <= n - 2; b_i++) {
      i3 = b_i * 3 + 2;
      i = b_i + 2;
      for (j = i; j <= n; j++) {
        j3 = (j - 1) * 3;
        elemmat[j3 + elemmat.size(1) * (i3 - 1)] = elemmat[(i3 + elemmat.size(1)
          * j3) - 1];
        elemmat[j3 + elemmat.size(1) * i3] = elemmat[i3 + elemmat.size(1) * j3];
        elemmat[(j3 + elemmat.size(1) * i3) + 1] = elemmat[i3 + elemmat.size(1) *
          (j3 + 1)];
      }
    }

    m = 3 * n;
    for (b_i = 2; b_i <= m; b_i++) {
      for (j = 0; j <= b_i - 2; j++) {
        elemmat[j + elemmat.size(1) * (b_i - 1)] = elemmat[(b_i + elemmat.size(1)
          * j) - 1];
      }
    }
  }

  static inline
  void sfe_elem_mass1(const SfeObject *b_sfe, ::coder::array<double, 2U>
                      &elemmat)
  {
    int i;
    int loop_ub;
    int m;
    int n;

    // sfe_elem_mass - Computing the local mass matrix for an element
    m = b_sfe->nnodes[0];
    n = b_sfe->nnodes[2];
    elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[2]);
    loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[2];
    for (i = 0; i < loop_ub; i++) {
      elemmat[i] = 0.0;
    }

    if (b_sfe->etypes[0] == b_sfe->etypes[2]) {
      int b_i;
      int j;

      //  for each qpoint
      i = b_sfe->nqp;
      for (int q{0}; q < i; q++) {
        //  get weighted volume
        for (b_i = 0; b_i < m; b_i++) {
          double psi;
          psi = b_sfe->wdetJ[q] * b_sfe->shapes_test[b_i +
            b_sfe->shapes_test.size(1) * q];
          for (j = b_i + 1; j <= m; j++) {
            elemmat[(j + elemmat.size(1) * b_i) - 1] = elemmat[(j + elemmat.size
              (1) * b_i) - 1] + b_sfe->shapes_trial[(j +
              b_sfe->shapes_trial.size(1) * q) - 1] * psi;
          }
        }
      }

      //  fill in lower part
      for (b_i = 2; b_i <= m; b_i++) {
        for (j = 0; j <= b_i - 2; j++) {
          elemmat[j + elemmat.size(1) * (b_i - 1)] = elemmat[(b_i + elemmat.size
            (1) * j) - 1];
        }
      }
    } else {
      //  Trial and test spaces are different
      i = b_sfe->nqp;
      for (int q{0}; q < i; q++) {
        //  get weighted volume
        for (int b_i{0}; b_i < m; b_i++) {
          double psi;
          psi = b_sfe->wdetJ[q] * b_sfe->shapes_test[b_i +
            b_sfe->shapes_test.size(1) * q];
          for (int j{0}; j < n; j++) {
            elemmat[j + elemmat.size(1) * b_i] = elemmat[j + elemmat.size(1) *
              b_i] + b_sfe->shapes_trial[j + b_sfe->shapes_trial.size(1) * q] *
              psi;
          }
        }
      }
    }
  }

  static inline
  void sfe_elem_mass2(const SfeObject *b_sfe, double rho, ::coder::array<double,
                      2U> &elemmat)
  {
    int i;
    int loop_ub;
    int m;
    int n;

    // sfe_elem_mass - Computing the local mass matrix for an element
    m = b_sfe->nnodes[0];
    n = b_sfe->nnodes[2];
    elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[2]);
    loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[2];
    for (i = 0; i < loop_ub; i++) {
      elemmat[i] = 0.0;
    }

    if (b_sfe->etypes[0] == b_sfe->etypes[2]) {
      int b_i;
      int j;

      //  for each qpoint
      i = b_sfe->nqp;
      for (int q{0}; q < i; q++) {
        double wdetj;

        //  get weighted volume
        wdetj = b_sfe->wdetJ[q] * rho;
        for (b_i = 0; b_i < m; b_i++) {
          double psi;
          psi = wdetj * b_sfe->shapes_test[b_i + b_sfe->shapes_test.size(1) * q];
          for (j = b_i + 1; j <= m; j++) {
            elemmat[(j + elemmat.size(1) * b_i) - 1] = elemmat[(j + elemmat.size
              (1) * b_i) - 1] + b_sfe->shapes_trial[(j +
              b_sfe->shapes_trial.size(1) * q) - 1] * psi;
          }
        }
      }

      //  fill in lower part
      for (b_i = 2; b_i <= m; b_i++) {
        for (j = 0; j <= b_i - 2; j++) {
          elemmat[j + elemmat.size(1) * (b_i - 1)] = elemmat[(b_i + elemmat.size
            (1) * j) - 1];
        }
      }
    } else {
      //  Trial and test spaces are different
      i = b_sfe->nqp;
      for (int q{0}; q < i; q++) {
        double wdetj;

        //  get weighted volume
        wdetj = b_sfe->wdetJ[q] * rho;
        for (int b_i{0}; b_i < m; b_i++) {
          double psi;
          psi = wdetj * b_sfe->shapes_test[b_i + b_sfe->shapes_test.size(1) * q];
          for (int j{0}; j < n; j++) {
            elemmat[j + elemmat.size(1) * b_i] = elemmat[j + elemmat.size(1) *
              b_i] + b_sfe->shapes_trial[j + b_sfe->shapes_trial.size(1) * q] *
              psi;
          }
        }
      }
    }
  }

  static inline
  void sfe_elem_mass3(const SfeObject *b_sfe, const ::coder::array<double, 1U>
                      &rho, ::coder::array<double, 2U> &elemmat)
  {
    int i;
    int loop_ub;
    int m;
    int n;

    // sfe_elem_mass - Computing the local mass matrix for an element
    m = b_sfe->nnodes[0];
    n = b_sfe->nnodes[2];
    elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[2]);
    loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[2];
    for (i = 0; i < loop_ub; i++) {
      elemmat[i] = 0.0;
    }

    if (b_sfe->etypes[0] == b_sfe->etypes[2]) {
      int b_i;
      int j;

      //  for each qpoint
      i = b_sfe->nqp;
      for (int q{0}; q < i; q++) {
        double wdetj;

        //  get weighted volume
        if (rho.size(0) == 1) {
          wdetj = b_sfe->wdetJ[q] * rho[0];
        } else {
          double dr_data;
          int b_m;

          //  during analyzing stage, the Coder seems not sure this is
          b_m = b_sfe->shapes_trial.size(1);
          dr_data = b_sfe->shapes_trial[b_sfe->shapes_trial.size(1) * q] * rho[0];
          for (b_i = 2; b_i <= b_m; b_i++) {
            dr_data += b_sfe->shapes_trial[(b_i + b_sfe->shapes_trial.size(1) *
              q) - 1] * rho[b_i - 1];
          }

          wdetj = b_sfe->wdetJ[q] * dr_data;
        }

        for (b_i = 0; b_i < m; b_i++) {
          double psi;
          psi = wdetj * b_sfe->shapes_test[b_i + b_sfe->shapes_test.size(1) * q];
          for (j = b_i + 1; j <= m; j++) {
            elemmat[(j + elemmat.size(1) * b_i) - 1] = elemmat[(j + elemmat.size
              (1) * b_i) - 1] + b_sfe->shapes_trial[(j +
              b_sfe->shapes_trial.size(1) * q) - 1] * psi;
          }
        }
      }

      //  fill in lower part
      for (b_i = 2; b_i <= m; b_i++) {
        for (j = 0; j <= b_i - 2; j++) {
          elemmat[j + elemmat.size(1) * (b_i - 1)] = elemmat[(b_i + elemmat.size
            (1) * j) - 1];
        }
      }
    } else {
      //  Trial and test spaces are different
      i = b_sfe->nqp;
      for (int q{0}; q < i; q++) {
        double wdetj;
        int b_i;

        //  get weighted volume
        if (rho.size(0) == 1) {
          wdetj = b_sfe->wdetJ[q] * rho[0];
        } else {
          double dr_data;
          int b_m;

          //  The Coder will compile dr into a scalar
          b_m = b_sfe->shapes_trial.size(1);
          dr_data = b_sfe->shapes_trial[b_sfe->shapes_trial.size(1) * q] * rho[0];
          for (b_i = 2; b_i <= b_m; b_i++) {
            dr_data += b_sfe->shapes_trial[(b_i + b_sfe->shapes_trial.size(1) *
              q) - 1] * rho[b_i - 1];
          }

          wdetj = b_sfe->wdetJ[q] * dr_data;
        }

        for (b_i = 0; b_i < m; b_i++) {
          double psi;
          psi = wdetj * b_sfe->shapes_test[b_i + b_sfe->shapes_test.size(1) * q];
          for (int j{0}; j < n; j++) {
            elemmat[j + elemmat.size(1) * b_i] = elemmat[j + elemmat.size(1) *
              b_i] + b_sfe->shapes_trial[j + b_sfe->shapes_trial.size(1) * q] *
              psi;
          }
        }
      }
    }
  }

  static inline
  void sfe_elem_stiff1(SfeObject *b_sfe, double nu, ::coder::array<double, 2U>
                       &elemmat)
  {
    int i;
    int loop_ub;
    int m;
    int n;

    // sfe_elem_stiff - Compute the element-wise stiffness matrix
    m = b_sfe->nnodes[0];
    n = b_sfe->nnodes[2];
    elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[2]);
    loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[2];
    for (i = 0; i < loop_ub; i++) {
      elemmat[i] = 0.0;
    }

    //  for each qpoint
    i = b_sfe->nqp;
    for (int q{0}; q < i; q++) {
      double stiff_coeff;

      //  initialize gradients at this qpoint
      sfe_init_grad(b_sfe, q + 1);

      //  get weighted volume
      stiff_coeff = nu * b_sfe->wdetJ[q];
      for (int b_i{0}; b_i < m; b_i++) {
        for (int j{0}; j < n; j++) {
          loop_ub = b_sfe->geom_dim;
          for (int k{0}; k < loop_ub; k++) {
            elemmat[j + elemmat.size(1) * b_i] = elemmat[j + elemmat.size(1) *
              b_i] + stiff_coeff * b_sfe->grads_trial[k +
              b_sfe->grads_trial.size(1) * j] * b_sfe->grads_test[k +
              b_sfe->grads_test.size(1) * b_i];
          }
        }
      }

      //  Convection part
    }
  }

  static inline
  void sfe_elem_stiff2(SfeObject *b_sfe, double nu, const double vel_data[],
                       const int vel_size[2], ::coder::array<double, 2U>
                       &elemmat)
  {
    double vel_coeff_data[3];
    int i;
    int loop_ub;
    int m;
    int n;

    // sfe_elem_stiff - Compute the element-wise stiffness matrix
    m = b_sfe->nnodes[0] - 1;
    n = b_sfe->nnodes[2] - 1;
    elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[2]);
    loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[2];
    for (i = 0; i < loop_ub; i++) {
      elemmat[i] = 0.0;
    }

    //  for each qpoint
    i = b_sfe->nqp;
    for (int q{0}; q < i; q++) {
      double stiff_coeff;
      int b_i;
      int j;
      int k;

      //  initialize gradients at this qpoint
      sfe_init_grad(b_sfe, q + 1);

      //  get weighted volume
      stiff_coeff = nu * b_sfe->wdetJ[q];
      for (b_i = 0; b_i <= m; b_i++) {
        for (j = 0; j <= n; j++) {
          loop_ub = b_sfe->geom_dim;
          for (k = 0; k < loop_ub; k++) {
            elemmat[j + elemmat.size(1) * b_i] = elemmat[j + elemmat.size(1) *
              b_i] + stiff_coeff * b_sfe->grads_trial[k +
              b_sfe->grads_trial.size(1) * j] * b_sfe->grads_test[k +
              b_sfe->grads_test.size(1) * b_i];
          }
        }
      }

      //  Convection part
      loop_ub = vel_size[1];
      if (vel_size[1] != 0) {
        if (0 <= loop_ub - 1) {
          std::copy(&vel_data[0], &vel_data[loop_ub], &vel_coeff_data[0]);
        }

        //  scale with weighted volume
        loop_ub = b_sfe->geom_dim;
        for (k = 0; k < loop_ub; k++) {
          vel_coeff_data[k] *= b_sfe->wdetJ[q];
        }

        for (b_i = 0; b_i <= m; b_i++) {
          double psi;
          psi = b_sfe->shapes_test[b_i + b_sfe->shapes_test.size(1) * q];
          for (j = 0; j <= n; j++) {
            for (k = 0; k < loop_ub; k++) {
              elemmat[j + elemmat.size(1) * b_i] = elemmat[j + elemmat.size(1) *
                b_i] + vel_coeff_data[k] * b_sfe->grads_trial[k +
                b_sfe->grads_trial.size(1) * j] * psi;
            }
          }
        }
      }
    }
  }

  static inline
  void sfe_elem_stiff3(SfeObject *b_sfe, const ::coder::array<double, 1U> &nu, ::
                       coder::array<double, 2U> &elemmat)
  {
    int i;
    int loop_ub;
    int m;
    int n;

    // sfe_elem_stiff - Compute the element-wise stiffness matrix
    m = b_sfe->nnodes[0];
    n = b_sfe->nnodes[2];
    elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[2]);
    loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[2];
    for (i = 0; i < loop_ub; i++) {
      elemmat[i] = 0.0;
    }

    //  for each qpoint
    i = b_sfe->nqp;
    for (int q{0}; q < i; q++) {
      double stiff_coeff;
      int b_i;

      //  initialize gradients at this qpoint
      sfe_init_grad(b_sfe, q + 1);

      //  get weighted volume
      if (nu.size(0) == 1) {
        stiff_coeff = nu[0] * b_sfe->wdetJ[q];
      } else {
        double nuq_data;
        int b_m;

        // interpolate_shape - Interpolate f with q-th shape function in the table
        b_m = b_sfe->shapes_trial.size(1);
        nuq_data = b_sfe->shapes_trial[b_sfe->shapes_trial.size(1) * q] * nu[0];
        for (b_i = 2; b_i <= b_m; b_i++) {
          nuq_data += b_sfe->shapes_trial[(b_i + b_sfe->shapes_trial.size(1) * q)
            - 1] * nu[b_i - 1];
        }

        stiff_coeff = nuq_data * b_sfe->wdetJ[q];
      }

      for (b_i = 0; b_i < m; b_i++) {
        for (int j{0}; j < n; j++) {
          loop_ub = b_sfe->geom_dim;
          for (int k{0}; k < loop_ub; k++) {
            elemmat[j + elemmat.size(1) * b_i] = elemmat[j + elemmat.size(1) *
              b_i] + stiff_coeff * b_sfe->grads_trial[k +
              b_sfe->grads_trial.size(1) * j] * b_sfe->grads_test[k +
              b_sfe->grads_test.size(1) * b_i];
          }
        }
      }

      //  Convection part
    }
  }

  static inline
  void sfe_elem_stiff4(SfeObject *b_sfe, double nu, const ::coder::array<double,
                       2U> &vel, ::coder::array<double, 2U> &elemmat)
  {
    ::coder::array<double, 2U> v;
    double vel_coeff_data[3];
    int i;
    int loop_ub;
    int m;
    int n;

    // sfe_elem_stiff - Compute the element-wise stiffness matrix
    m = b_sfe->nnodes[0] - 1;
    n = b_sfe->nnodes[2] - 1;
    elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[2]);
    loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[2];
    for (i = 0; i < loop_ub; i++) {
      elemmat[i] = 0.0;
    }

    //  for each qpoint
    i = b_sfe->nqp;
    for (int q{0}; q < i; q++) {
      double stiff_coeff;
      int b_i;
      int i1;
      int j;
      int k;

      //  initialize gradients at this qpoint
      sfe_init_grad(b_sfe, q + 1);

      //  get weighted volume
      stiff_coeff = nu * b_sfe->wdetJ[q];
      for (b_i = 0; b_i <= m; b_i++) {
        for (j = 0; j <= n; j++) {
          i1 = b_sfe->geom_dim;
          for (k = 0; k < i1; k++) {
            elemmat[j + elemmat.size(1) * b_i] = elemmat[j + elemmat.size(1) *
              b_i] + stiff_coeff * b_sfe->grads_trial[k +
              b_sfe->grads_trial.size(1) * j] * b_sfe->grads_test[k +
              b_sfe->grads_test.size(1) * b_i];
          }
        }
      }

      //  Convection part
      if ((vel.size(0) != 0) && (vel.size(1) != 0)) {
        if (vel.size(0) == 1) {
          loop_ub = vel.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            vel_coeff_data[i1] = vel[i1];
          }
        } else {
          int b_m;
          int nrhs;

          // interpolate_shape - Interpolate f with q-th shape function in the table
          b_m = b_sfe->shapes_trial.size(1);
          nrhs = vel.size(1) - 1;
          v.set_size(1, static_cast<int>(static_cast<signed char>(vel.size(1))));
          for (j = 0; j <= nrhs; j++) {
            v[j] = b_sfe->shapes_trial[b_sfe->shapes_trial.size(1) * q] * vel[j];
          }

          for (b_i = 2; b_i <= b_m; b_i++) {
            double Ni;
            Ni = b_sfe->shapes_trial[(b_i + b_sfe->shapes_trial.size(1) * q) - 1];
            for (j = 0; j <= nrhs; j++) {
              v[j] = v[j] + Ni * vel[j + vel.size(1) * (b_i - 1)];
            }
          }

          loop_ub = v.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            vel_coeff_data[i1] = v[i1];
          }
        }

        //  scale with weighted volume
        i1 = b_sfe->geom_dim;
        for (k = 0; k < i1; k++) {
          vel_coeff_data[k] *= b_sfe->wdetJ[q];
        }

        for (b_i = 0; b_i <= m; b_i++) {
          double psi;
          psi = b_sfe->shapes_test[b_i + b_sfe->shapes_test.size(1) * q];
          for (j = 0; j <= n; j++) {
            for (k = 0; k < i1; k++) {
              elemmat[j + elemmat.size(1) * b_i] = elemmat[j + elemmat.size(1) *
                b_i] + vel_coeff_data[k] * b_sfe->grads_trial[k +
                b_sfe->grads_trial.size(1) * j] * psi;
            }
          }
        }
      }
    }
  }

  static inline
  void sfe_elem_stiff5(SfeObject *b_sfe, const ::coder::array<double, 1U> &nu,
                       const ::coder::array<double, 2U> &vel, int coefftag, ::
                       coder::array<double, 2U> &elemmat)
  {
    ::coder::array<double, 2U> v;
    double vel_coeff_data[3];
    int i;
    int loop_ub;
    int m;
    int n;

    // sfe_elem_stiff - Compute the element-wise stiffness matrix
    m = b_sfe->nnodes[0] - 1;
    n = b_sfe->nnodes[2] - 1;
    elemmat.set_size(b_sfe->nnodes[0], b_sfe->nnodes[2]);
    loop_ub = b_sfe->nnodes[0] * b_sfe->nnodes[2];
    for (i = 0; i < loop_ub; i++) {
      elemmat[i] = 0.0;
    }

    //  for each qpoint
    i = b_sfe->nqp;
    for (int q{0}; q < i; q++) {
      double stiff_coeff;
      int b_i;
      int b_m;
      int i1;
      int j;
      int k;

      //  initialize gradients at this qpoint
      sfe_init_grad(b_sfe, q + 1);

      //  get weighted volume
      if ((coefftag & 1) == 1) {
        if (nu.size(0) == 1) {
          stiff_coeff = nu[0] * b_sfe->wdetJ[q];
        } else {
          double nuq_data;

          // interpolate_shape - Interpolate f with q-th shape function in the table
          b_m = b_sfe->shapes_trial.size(1);
          nuq_data = b_sfe->shapes_trial[b_sfe->shapes_trial.size(1) * q] * nu[0];
          for (b_i = 2; b_i <= b_m; b_i++) {
            nuq_data += b_sfe->shapes_trial[(b_i + b_sfe->shapes_trial.size(1) *
              q) - 1] * nu[b_i - 1];
          }

          stiff_coeff = nuq_data * b_sfe->wdetJ[q];
        }
      } else {
        stiff_coeff = nu[0] * b_sfe->wdetJ[q];
      }

      for (b_i = 0; b_i <= m; b_i++) {
        for (j = 0; j <= n; j++) {
          i1 = b_sfe->geom_dim;
          for (k = 0; k < i1; k++) {
            elemmat[j + elemmat.size(1) * b_i] = elemmat[j + elemmat.size(1) *
              b_i] + stiff_coeff * b_sfe->grads_trial[k +
              b_sfe->grads_trial.size(1) * j] * b_sfe->grads_test[k +
              b_sfe->grads_test.size(1) * b_i];
          }
        }
      }

      //  Convection part
      if ((vel.size(0) != 0) && (vel.size(1) != 0)) {
        if ((coefftag >> 1 & 1) == 1) {
          if (vel.size(0) == 1) {
            loop_ub = vel.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              vel_coeff_data[i1] = vel[i1];
            }
          } else {
            int nrhs;

            // interpolate_shape - Interpolate f with q-th shape function in the table
            b_m = b_sfe->shapes_trial.size(1);
            nrhs = vel.size(1) - 1;
            v.set_size(1, static_cast<int>(static_cast<signed char>(vel.size(1))));
            for (j = 0; j <= nrhs; j++) {
              v[j] = b_sfe->shapes_trial[b_sfe->shapes_trial.size(1) * q] *
                vel[j];
            }

            for (b_i = 2; b_i <= b_m; b_i++) {
              double Ni;
              Ni = b_sfe->shapes_trial[(b_i + b_sfe->shapes_trial.size(1) * q) -
                1];
              for (j = 0; j <= nrhs; j++) {
                v[j] = v[j] + Ni * vel[j + vel.size(1) * (b_i - 1)];
              }
            }

            loop_ub = v.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              vel_coeff_data[i1] = v[i1];
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
        for (k = 0; k < i1; k++) {
          vel_coeff_data[k] *= b_sfe->wdetJ[q];
        }

        for (b_i = 0; b_i <= m; b_i++) {
          double psi;
          psi = b_sfe->shapes_test[b_i + b_sfe->shapes_test.size(1) * q];
          for (j = 0; j <= n; j++) {
            for (k = 0; k < i1; k++) {
              elemmat[j + elemmat.size(1) * b_i] = elemmat[j + elemmat.size(1) *
                b_i] + vel_coeff_data[k] * b_sfe->grads_trial[k +
                b_sfe->grads_trial.size(1) * j] * psi;
            }
          }
        }
      }
    }
  }

  static inline
  double sfe_eval_div1(const SfeObject *b_sfe, const ::coder::array<double, 2U>
                       &fs)
  {
    double d;
    int i;

    // sfe_eval_grads - Evaluate the divergence of a vector-field function
    d = 0.0;
    i = b_sfe->nnodes[0];
    for (int j{0}; j < i; j++) {
      int i1;
      i1 = b_sfe->geom_dim;
      for (int k{0}; k < i1; k++) {
        d += b_sfe->grads_trial[k + b_sfe->grads_trial.size(1) * j] * fs[k +
          fs.size(1) * j];
      }
    }

    return d;
  }

  static inline
  void sfe_eval_funcs1(const SfeObject *b_sfe, int q, const ::coder::array<
                       double, 2U> &fs, ::coder::array<double, 2U> &vals)
  {
    int j;
    int m;
    int nrhs;

    // sfe_eval_funcs - Evaluate a set of discrete function values
    m = b_sfe->shapes_trial.size(1);
    nrhs = fs.size(1) - 1;
    vals.set_size(1, fs.size(1));
    for (j = 0; j <= nrhs; j++) {
      vals[j] = b_sfe->shapes_trial[b_sfe->shapes_trial.size(1) * (q - 1)] *
        fs[j];
    }

    for (int i{2}; i <= m; i++) {
      double Ni;
      Ni = b_sfe->shapes_trial[(i + b_sfe->shapes_trial.size(1) * (q - 1)) - 1];
      for (j = 0; j <= nrhs; j++) {
        vals[j] = vals[j] + Ni * fs[j + fs.size(1) * (i - 1)];
      }
    }
  }

  static inline
  void sfe_eval_grads1(const SfeObject *b_sfe, const ::coder::array<double, 2U>
                       &fs, ::coder::array<double, 2U> &grads)
  {
    int m;

    // sfe_eval_grads - Evaluate the gradients of a set of function fields
    m = fs.size(1);
    grads.set_size(b_sfe->geom_dim, fs.size(1));
    for (int i{0}; i < m; i++) {
      int b_i;
      b_i = b_sfe->geom_dim;
      for (int k{0}; k < b_i; k++) {
        double v;
        int i1;
        v = 0.0;
        i1 = b_sfe->nnodes[0];
        for (int j{0}; j < i1; j++) {
          v += b_sfe->grads_trial[k + b_sfe->grads_trial.size(1) * j] * fs[i +
            fs.size(1) * j];
        }

        grads[i + grads.size(1) * k] = v;
      }
    }
  }

  static inline
  void sfe_init1(SfeObject *b_sfe, const int etypes_data[], const int
                 etypes_size[1], const ::coder::array<double, 2U> &xs, const ::
                 coder::array<double, 2U> &userquad)
  {
    ::coder::array<double, 2U> v;
    double b_dv[9];
    int b_i;
    int geom_dim;
    int geom_etype;
    int i;
    int i1;
    int j;
    int k;
    int loop_ub;
    int nrhs;
    int q;
    int topo_dim;
    signed char unnamed_idx_1;

    // sfe_init - Initialize/reinitialize an sfe object for non-boundary element
    if (etypes_data[0] != -1) {
      int shape;

      // obtain_nnodes - Obtain number of nodes per element given etype
      if ((etypes_size[0] < 2) || (etypes_data[1] <= 0)) {
        geom_etype = etypes_data[0];
      } else {
        geom_etype = etypes_data[1];
      }

      //  Obtain test type
      if ((etypes_size[0] < 3) || (etypes_data[2] <= 0)) {
        b_sfe->etypes[2] = etypes_data[0];
      } else {
        b_sfe->etypes[2] = etypes_data[2];
      }

      //  Geometric dimension
      geom_dim = xs.size(1);

      //  Topological dimension
      shape = etypes_data[0] >> 5 & 7;
      topo_dim = ((shape > 0) + (shape > 1)) + (shape > 3);

      // obtain_nnodes - Obtain number of nodes per element given etype
      b_sfe->etypes[0] = etypes_data[0];
      b_sfe->etypes[1] = geom_etype;

      //  Get number of nodes per element
      b_sfe->nnodes[0] = iv[etypes_data[0] - 1];

      // obtain_nnodes - Obtain number of nodes per element given etype
      b_sfe->nnodes[1] = iv[geom_etype - 1];

      // obtain_nnodes - Obtain number of nodes per element given etype
      b_sfe->nnodes[2] = iv[b_sfe->etypes[2] - 1];
      b_sfe->topo_dim = topo_dim;

      //  Geometric dimension
      if (xs.size(1) < topo_dim) {
        geom_dim = topo_dim;
      }

      b_sfe->geom_dim = geom_dim;

      //  Set up quadrature
      b_sfe->nqp = userquad.size(0);
      b_sfe->ws.size[0] = userquad.size(0);
      b_sfe->cs.size[1] = topo_dim;
      b_sfe->cs.size[0] = userquad.size(0);
      i = userquad.size(0);
      for (q = 0; q < i; q++) {
        b_sfe->ws.data[q] = userquad[userquad.size(1) * q];
        for (k = 0; k < topo_dim; k++) {
          b_sfe->cs.data[k + b_sfe->cs.size[1] * q] = userquad[(k +
            userquad.size(1) * q) + 1];
        }
      }

      //  Trial space shape functions & derivs
      tabulate_shapefuncs(etypes_data[0], b_sfe->cs.data, b_sfe->cs.size,
                          b_sfe->shapes_trial, b_sfe->derivs_trial);

      //  Geometry space shape functions & derivs
      if (etypes_data[0] != geom_etype) {
        tabulate_shapefuncs(geom_etype, b_sfe->cs.data, b_sfe->cs.size,
                            b_sfe->shapes_geom, b_sfe->derivs_geom);
      } else {
        loop_ub = b_sfe->shapes_trial.size(1) * b_sfe->shapes_trial.size(0);
        b_sfe->shapes_geom.set_size(b_sfe->shapes_trial.size(0),
          b_sfe->shapes_trial.size(1));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->shapes_geom[i] = b_sfe->shapes_trial[i];
        }

        loop_ub = b_sfe->derivs_trial.size(2) * b_sfe->derivs_trial.size(1) *
          b_sfe->derivs_trial.size(0);
        b_sfe->derivs_geom.set_size(b_sfe->derivs_trial.size(0),
          b_sfe->derivs_trial.size(1), b_sfe->derivs_trial.size(2));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->derivs_geom[i] = b_sfe->derivs_trial[i];
        }
      }

      //  Test space shape functions & derivs
      if ((etypes_data[0] != b_sfe->etypes[2]) && (geom_etype != b_sfe->etypes[2]))
      {
        tabulate_shapefuncs(b_sfe->etypes[2], b_sfe->cs.data, b_sfe->cs.size,
                            b_sfe->shapes_test, b_sfe->derivs_test);
      } else if (etypes_data[0] == b_sfe->etypes[2]) {
        loop_ub = b_sfe->shapes_trial.size(1) * b_sfe->shapes_trial.size(0);
        b_sfe->shapes_test.set_size(b_sfe->shapes_trial.size(0),
          b_sfe->shapes_trial.size(1));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->shapes_test[i] = b_sfe->shapes_trial[i];
        }

        loop_ub = b_sfe->derivs_trial.size(2) * b_sfe->derivs_trial.size(1) *
          b_sfe->derivs_trial.size(0);
        b_sfe->derivs_test.set_size(b_sfe->derivs_trial.size(0),
          b_sfe->derivs_trial.size(1), b_sfe->derivs_trial.size(2));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->derivs_test[i] = b_sfe->derivs_trial[i];
        }
      } else {
        loop_ub = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
        b_sfe->shapes_test.set_size(b_sfe->shapes_geom.size(0),
          b_sfe->shapes_geom.size(1));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->shapes_test[i] = b_sfe->shapes_geom[i];
        }

        loop_ub = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
          b_sfe->derivs_geom.size(0);
        b_sfe->derivs_test.set_size(b_sfe->derivs_geom.size(0),
          b_sfe->derivs_geom.size(1), b_sfe->derivs_geom.size(2));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->derivs_test[i] = b_sfe->derivs_geom[i];
        }
      }
    } else {
      geom_dim = b_sfe->geom_dim;
      topo_dim = b_sfe->topo_dim;
      geom_etype = b_sfe->etypes[1];
    }

    //  potentially skip re-tabulating
    b_sfe->cs_phy.set_size(b_sfe->nqp, geom_dim);
    i = b_sfe->nqp;
    if (0 <= i - 1) {
      nrhs = xs.size(1) - 1;
      unnamed_idx_1 = static_cast<signed char>(xs.size(1));
    }

    for (q = 0; q < i; q++) {
      int m;

      //  NOTE The following can be optimized efficiently due to the the upper
      m = b_sfe->shapes_geom.size(1);
      v.set_size(1, static_cast<int>(unnamed_idx_1));
      for (j = 0; j <= nrhs; j++) {
        v[j] = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[j];
      }

      for (b_i = 2; b_i <= m; b_i++) {
        double Ni;
        Ni = b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1];
        for (j = 0; j <= nrhs; j++) {
          v[j] = v[j] + Ni * xs[j + xs.size(1) * (b_i - 1)];
        }
      }

      loop_ub = v.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sfe->cs_phy[i1 + b_sfe->cs_phy.size(1) * q] = v[i1];
      }
    }

    //  Compute Jacobian
    b_sfe->wdetJ.set_size(b_sfe->nqp);
    if ((geom_etype == 68) || (geom_etype == 132) || (geom_etype == 36) ||
        (((geom_etype >> 2 & 7) == 1) && (topo_dim == geom_dim))) {
      double a;
      double d;
      int n;

      //  Either a simplex or a multi-linear volume element, so a single
      b_sfe->jacTs.set_size(1);

      // compute_jact - Compute Jacobian^T and its determinant from q-th deriv in table
      geom_dim = xs.size(1);
      topo_dim = b_sfe->derivs_geom.size(2);
      std::memset(&b_dv[0], 0, 9U * sizeof(double));
      n = xs.size(0);
      for (k = 0; k < n; k++) {
        for (b_i = 0; b_i < topo_dim; b_i++) {
          for (j = 0; j < geom_dim; j++) {
            i = j + 3 * b_i;
            b_dv[i] += xs[j + xs.size(1) * k] * b_sfe->derivs_geom[b_i +
              b_sfe->derivs_geom.size(2) * k];
          }
        }
      }

      if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
        if (xs.size(1) == 1) {
          a = b_dv[0];
        } else if (xs.size(1) == 2) {
          // det2 - Compute determinant of 2x2 matrix.
          a = b_dv[0] * b_dv[4] - b_dv[1] * b_dv[3];
        } else {
          // det3 - Compute determinant of 3x3 matrix.
          a = (b_dv[2] * (b_dv[3] * b_dv[7] - b_dv[4] * b_dv[6]) + b_dv[5] *
               (b_dv[1] * b_dv[6] - b_dv[0] * b_dv[7])) + b_dv[8] * (b_dv[0] *
            b_dv[4] - b_dv[1] * b_dv[3]);
        }
      } else if (b_sfe->derivs_geom.size(2) == 1) {
        d = b_dv[0] * b_dv[0] + b_dv[1] * b_dv[1];
        if (xs.size(1) == 3) {
          d += b_dv[2] * b_dv[2];
        }

        a = std::sqrt(d);
      } else {
        //  must be 2x3
        b_dv[6] = b_dv[1] * b_dv[5] - b_dv[2] * b_dv[4];
        b_dv[7] = b_dv[2] * b_dv[3] - b_dv[0] * b_dv[5];
        b_dv[8] = b_dv[0] * b_dv[4] - b_dv[1] * b_dv[3];
        a = std::sqrt((b_dv[6] * b_dv[6] + b_dv[7] * b_dv[7]) + b_dv[8] * b_dv[8]);
      }

      for (i = 0; i < 9; i++) {
        b_sfe->jacTs[0].data[i] = b_dv[i];
      }

      d = std::abs(a);
      i = b_sfe->nqp;
      for (q = 0; q < i; q++) {
        b_sfe->wdetJ[q] = d * b_sfe->ws.data[q];
      }
    } else {
      // obtain_elemdegree - Decode the element degree from etype
      b_sfe->jacTs.set_size(b_sfe->nqp);
      i = b_sfe->nqp;
      for (q = 0; q < i; q++) {
        double a;
        int n;

        // compute_jact - Compute Jacobian^T and its determinant from q-th deriv in table
        geom_dim = xs.size(1);
        topo_dim = b_sfe->derivs_geom.size(2);
        std::memset(&b_dv[0], 0, 9U * sizeof(double));
        n = xs.size(0);
        for (k = 0; k < n; k++) {
          for (b_i = 0; b_i < topo_dim; b_i++) {
            for (j = 0; j < geom_dim; j++) {
              i1 = j + 3 * b_i;
              b_dv[i1] += xs[j + xs.size(1) * k] * b_sfe->derivs_geom[(b_i +
                b_sfe->derivs_geom.size(2) * k) + b_sfe->derivs_geom.size(2) *
                b_sfe->derivs_geom.size(1) * q];
            }
          }
        }

        if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
          if (xs.size(1) == 1) {
            a = b_dv[0];
          } else if (xs.size(1) == 2) {
            // det2 - Compute determinant of 2x2 matrix.
            a = b_dv[0] * b_dv[4] - b_dv[1] * b_dv[3];
          } else {
            // det3 - Compute determinant of 3x3 matrix.
            a = (b_dv[2] * (b_dv[3] * b_dv[7] - b_dv[4] * b_dv[6]) + b_dv[5] *
                 (b_dv[1] * b_dv[6] - b_dv[0] * b_dv[7])) + b_dv[8] * (b_dv[0] *
              b_dv[4] - b_dv[1] * b_dv[3]);
          }
        } else if (b_sfe->derivs_geom.size(2) == 1) {
          a = b_dv[0] * b_dv[0] + b_dv[1] * b_dv[1];
          if (xs.size(1) == 3) {
            a += b_dv[2] * b_dv[2];
          }

          a = std::sqrt(a);
        } else {
          //  must be 2x3
          b_dv[6] = b_dv[1] * b_dv[5] - b_dv[2] * b_dv[4];
          b_dv[7] = b_dv[2] * b_dv[3] - b_dv[0] * b_dv[5];
          b_dv[8] = b_dv[0] * b_dv[4] - b_dv[1] * b_dv[3];
          a = std::sqrt((b_dv[6] * b_dv[6] + b_dv[7] * b_dv[7]) + b_dv[8] *
                        b_dv[8]);
        }

        for (i1 = 0; i1 < 9; i1++) {
          b_sfe->jacTs[q].data[i1] = b_dv[i1];
        }

        b_sfe->wdetJ[q] = a;
        b_sfe->wdetJ[q] = std::abs(b_sfe->wdetJ[q]) * b_sfe->ws.data[q];
      }
    }
  }

  static inline
  void sfe_init2(SfeObject *b_sfe, const int etypes_data[], const int
                 etypes_size[1], const ::coder::array<double, 2U> &xs, int qd)
  {
    ::coder::array<double, 2U> v;
    double b_dv[9];
    int b_i;
    int geom_dim;
    int geom_etype;
    int i;
    int i1;
    int j;
    int loop_ub;
    int nrhs;
    int q;
    int topo_dim;
    signed char unnamed_idx_1;

    // sfe_init - Initialize/reinitialize an sfe object for non-boundary element
    if (etypes_data[0] != -1) {
      int shape;

      // obtain_nnodes - Obtain number of nodes per element given etype
      if ((etypes_size[0] < 2) || (etypes_data[1] <= 0)) {
        geom_etype = etypes_data[0];
      } else {
        geom_etype = etypes_data[1];
      }

      //  Obtain test type
      if ((etypes_size[0] < 3) || (etypes_data[2] <= 0)) {
        b_sfe->etypes[2] = etypes_data[0];
      } else {
        b_sfe->etypes[2] = etypes_data[2];
      }

      //  Geometric dimension
      geom_dim = xs.size(1);

      //  Topological dimension
      shape = etypes_data[0] >> 5 & 7;
      topo_dim = ((shape > 0) + (shape > 1)) + (shape > 3);

      // obtain_nnodes - Obtain number of nodes per element given etype
      b_sfe->etypes[0] = etypes_data[0];
      b_sfe->etypes[1] = geom_etype;

      //  Get number of nodes per element
      b_sfe->nnodes[0] = iv[etypes_data[0] - 1];

      // obtain_nnodes - Obtain number of nodes per element given etype
      b_sfe->nnodes[1] = iv[geom_etype - 1];

      // obtain_nnodes - Obtain number of nodes per element given etype
      b_sfe->nnodes[2] = iv[b_sfe->etypes[2] - 1];
      b_sfe->topo_dim = topo_dim;

      //  Geometric dimension
      if (xs.size(1) < topo_dim) {
        geom_dim = topo_dim;
      }

      b_sfe->geom_dim = geom_dim;

      //  Set up quadrature
      if (qd != MAX_int32_T) {
        if (qd <= 0) {
          //  trial+test+nonlinear-geom?1:0
          qd = (((etypes_data[0] >> 2 & 7) + (b_sfe->etypes[2] >> 2 & 7)) +
                ((geom_etype >> 2 & 7) > 1)) + (geom_dim > topo_dim);
        }

        tabulate_quadratures(etypes_data[0], qd, &b_sfe->nqp, b_sfe->ws.data,
                             &b_sfe->ws.size[0], b_sfe->cs.data, b_sfe->cs.size);
      }

      //  Trial space shape functions & derivs
      tabulate_shapefuncs(etypes_data[0], b_sfe->cs.data, b_sfe->cs.size,
                          b_sfe->shapes_trial, b_sfe->derivs_trial);

      //  Geometry space shape functions & derivs
      if (etypes_data[0] != geom_etype) {
        tabulate_shapefuncs(geom_etype, b_sfe->cs.data, b_sfe->cs.size,
                            b_sfe->shapes_geom, b_sfe->derivs_geom);
      } else {
        loop_ub = b_sfe->shapes_trial.size(1) * b_sfe->shapes_trial.size(0);
        b_sfe->shapes_geom.set_size(b_sfe->shapes_trial.size(0),
          b_sfe->shapes_trial.size(1));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->shapes_geom[i] = b_sfe->shapes_trial[i];
        }

        loop_ub = b_sfe->derivs_trial.size(2) * b_sfe->derivs_trial.size(1) *
          b_sfe->derivs_trial.size(0);
        b_sfe->derivs_geom.set_size(b_sfe->derivs_trial.size(0),
          b_sfe->derivs_trial.size(1), b_sfe->derivs_trial.size(2));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->derivs_geom[i] = b_sfe->derivs_trial[i];
        }
      }

      //  Test space shape functions & derivs
      if ((etypes_data[0] != b_sfe->etypes[2]) && (geom_etype != b_sfe->etypes[2]))
      {
        tabulate_shapefuncs(b_sfe->etypes[2], b_sfe->cs.data, b_sfe->cs.size,
                            b_sfe->shapes_test, b_sfe->derivs_test);
      } else if (etypes_data[0] == b_sfe->etypes[2]) {
        loop_ub = b_sfe->shapes_trial.size(1) * b_sfe->shapes_trial.size(0);
        b_sfe->shapes_test.set_size(b_sfe->shapes_trial.size(0),
          b_sfe->shapes_trial.size(1));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->shapes_test[i] = b_sfe->shapes_trial[i];
        }

        loop_ub = b_sfe->derivs_trial.size(2) * b_sfe->derivs_trial.size(1) *
          b_sfe->derivs_trial.size(0);
        b_sfe->derivs_test.set_size(b_sfe->derivs_trial.size(0),
          b_sfe->derivs_trial.size(1), b_sfe->derivs_trial.size(2));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->derivs_test[i] = b_sfe->derivs_trial[i];
        }
      } else {
        loop_ub = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
        b_sfe->shapes_test.set_size(b_sfe->shapes_geom.size(0),
          b_sfe->shapes_geom.size(1));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->shapes_test[i] = b_sfe->shapes_geom[i];
        }

        loop_ub = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
          b_sfe->derivs_geom.size(0);
        b_sfe->derivs_test.set_size(b_sfe->derivs_geom.size(0),
          b_sfe->derivs_geom.size(1), b_sfe->derivs_geom.size(2));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->derivs_test[i] = b_sfe->derivs_geom[i];
        }
      }
    } else {
      geom_dim = b_sfe->geom_dim;
      topo_dim = b_sfe->topo_dim;
      geom_etype = b_sfe->etypes[1];
    }

    //  potentially skip re-tabulating
    b_sfe->cs_phy.set_size(b_sfe->nqp, geom_dim);
    i = b_sfe->nqp;
    if (0 <= i - 1) {
      nrhs = xs.size(1) - 1;
      unnamed_idx_1 = static_cast<signed char>(xs.size(1));
    }

    for (q = 0; q < i; q++) {
      int m;

      //  NOTE The following can be optimized efficiently due to the the upper
      m = b_sfe->shapes_geom.size(1);
      v.set_size(1, static_cast<int>(unnamed_idx_1));
      for (j = 0; j <= nrhs; j++) {
        v[j] = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[j];
      }

      for (b_i = 2; b_i <= m; b_i++) {
        double Ni;
        Ni = b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1];
        for (j = 0; j <= nrhs; j++) {
          v[j] = v[j] + Ni * xs[j + xs.size(1) * (b_i - 1)];
        }
      }

      loop_ub = v.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sfe->cs_phy[i1 + b_sfe->cs_phy.size(1) * q] = v[i1];
      }
    }

    //  Compute Jacobian
    b_sfe->wdetJ.set_size(b_sfe->nqp);
    if ((geom_etype == 68) || (geom_etype == 132) || (geom_etype == 36) ||
        (((geom_etype >> 2 & 7) == 1) && (topo_dim == geom_dim))) {
      double a;
      double d;
      int n;

      //  Either a simplex or a multi-linear volume element, so a single
      b_sfe->jacTs.set_size(1);

      // compute_jact - Compute Jacobian^T and its determinant from q-th deriv in table
      geom_dim = xs.size(1);
      topo_dim = b_sfe->derivs_geom.size(2);
      std::memset(&b_dv[0], 0, 9U * sizeof(double));
      n = xs.size(0);
      for (int k{0}; k < n; k++) {
        for (b_i = 0; b_i < topo_dim; b_i++) {
          for (j = 0; j < geom_dim; j++) {
            i = j + 3 * b_i;
            b_dv[i] += xs[j + xs.size(1) * k] * b_sfe->derivs_geom[b_i +
              b_sfe->derivs_geom.size(2) * k];
          }
        }
      }

      if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
        if (xs.size(1) == 1) {
          a = b_dv[0];
        } else if (xs.size(1) == 2) {
          // det2 - Compute determinant of 2x2 matrix.
          a = b_dv[0] * b_dv[4] - b_dv[1] * b_dv[3];
        } else {
          // det3 - Compute determinant of 3x3 matrix.
          a = (b_dv[2] * (b_dv[3] * b_dv[7] - b_dv[4] * b_dv[6]) + b_dv[5] *
               (b_dv[1] * b_dv[6] - b_dv[0] * b_dv[7])) + b_dv[8] * (b_dv[0] *
            b_dv[4] - b_dv[1] * b_dv[3]);
        }
      } else if (b_sfe->derivs_geom.size(2) == 1) {
        d = b_dv[0] * b_dv[0] + b_dv[1] * b_dv[1];
        if (xs.size(1) == 3) {
          d += b_dv[2] * b_dv[2];
        }

        a = std::sqrt(d);
      } else {
        //  must be 2x3
        b_dv[6] = b_dv[1] * b_dv[5] - b_dv[2] * b_dv[4];
        b_dv[7] = b_dv[2] * b_dv[3] - b_dv[0] * b_dv[5];
        b_dv[8] = b_dv[0] * b_dv[4] - b_dv[1] * b_dv[3];
        a = std::sqrt((b_dv[6] * b_dv[6] + b_dv[7] * b_dv[7]) + b_dv[8] * b_dv[8]);
      }

      for (i = 0; i < 9; i++) {
        b_sfe->jacTs[0].data[i] = b_dv[i];
      }

      d = std::abs(a);
      i = b_sfe->nqp;
      for (q = 0; q < i; q++) {
        b_sfe->wdetJ[q] = d * b_sfe->ws.data[q];
      }
    } else {
      // obtain_elemdegree - Decode the element degree from etype
      b_sfe->jacTs.set_size(b_sfe->nqp);
      i = b_sfe->nqp;
      for (q = 0; q < i; q++) {
        double a;
        int n;

        // compute_jact - Compute Jacobian^T and its determinant from q-th deriv in table
        geom_dim = xs.size(1);
        topo_dim = b_sfe->derivs_geom.size(2);
        std::memset(&b_dv[0], 0, 9U * sizeof(double));
        n = xs.size(0);
        for (int k{0}; k < n; k++) {
          for (b_i = 0; b_i < topo_dim; b_i++) {
            for (j = 0; j < geom_dim; j++) {
              i1 = j + 3 * b_i;
              b_dv[i1] += xs[j + xs.size(1) * k] * b_sfe->derivs_geom[(b_i +
                b_sfe->derivs_geom.size(2) * k) + b_sfe->derivs_geom.size(2) *
                b_sfe->derivs_geom.size(1) * q];
            }
          }
        }

        if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
          if (xs.size(1) == 1) {
            a = b_dv[0];
          } else if (xs.size(1) == 2) {
            // det2 - Compute determinant of 2x2 matrix.
            a = b_dv[0] * b_dv[4] - b_dv[1] * b_dv[3];
          } else {
            // det3 - Compute determinant of 3x3 matrix.
            a = (b_dv[2] * (b_dv[3] * b_dv[7] - b_dv[4] * b_dv[6]) + b_dv[5] *
                 (b_dv[1] * b_dv[6] - b_dv[0] * b_dv[7])) + b_dv[8] * (b_dv[0] *
              b_dv[4] - b_dv[1] * b_dv[3]);
          }
        } else if (b_sfe->derivs_geom.size(2) == 1) {
          a = b_dv[0] * b_dv[0] + b_dv[1] * b_dv[1];
          if (xs.size(1) == 3) {
            a += b_dv[2] * b_dv[2];
          }

          a = std::sqrt(a);
        } else {
          //  must be 2x3
          b_dv[6] = b_dv[1] * b_dv[5] - b_dv[2] * b_dv[4];
          b_dv[7] = b_dv[2] * b_dv[3] - b_dv[0] * b_dv[5];
          b_dv[8] = b_dv[0] * b_dv[4] - b_dv[1] * b_dv[3];
          a = std::sqrt((b_dv[6] * b_dv[6] + b_dv[7] * b_dv[7]) + b_dv[8] *
                        b_dv[8]);
        }

        for (i1 = 0; i1 < 9; i1++) {
          b_sfe->jacTs[q].data[i1] = b_dv[i1];
        }

        b_sfe->wdetJ[q] = a;
        b_sfe->wdetJ[q] = std::abs(b_sfe->wdetJ[q]) * b_sfe->ws.data[q];
      }
    }
  }

  static inline
  void sfe_init3(SfeObject *b_sfe, const int etypes_data[], const int
                 etypes_size[1], const ::coder::array<double, 2U> &xs)
  {
    ::coder::array<double, 2U> v;
    double b_dv[9];
    int b_i;
    int geom_dim;
    int geom_etype;
    int i;
    int i1;
    int j;
    int loop_ub;
    int nrhs;
    int q;
    int topo_dim;
    signed char unnamed_idx_1;

    // sfe_init - Initialize/reinitialize an sfe object for non-boundary element
    if (etypes_data[0] != -1) {
      int shape;

      // obtain_nnodes - Obtain number of nodes per element given etype
      if ((etypes_size[0] < 2) || (etypes_data[1] <= 0)) {
        geom_etype = etypes_data[0];
      } else {
        geom_etype = etypes_data[1];
      }

      //  Obtain test type
      if ((etypes_size[0] < 3) || (etypes_data[2] <= 0)) {
        b_sfe->etypes[2] = etypes_data[0];
      } else {
        b_sfe->etypes[2] = etypes_data[2];
      }

      //  Geometric dimension
      geom_dim = xs.size(1);

      //  Topological dimension
      shape = etypes_data[0] >> 5 & 7;
      topo_dim = ((shape > 0) + (shape > 1)) + (shape > 3);

      // obtain_nnodes - Obtain number of nodes per element given etype
      b_sfe->etypes[0] = etypes_data[0];
      b_sfe->etypes[1] = geom_etype;

      //  Get number of nodes per element
      b_sfe->nnodes[0] = iv[etypes_data[0] - 1];

      // obtain_nnodes - Obtain number of nodes per element given etype
      b_sfe->nnodes[1] = iv[geom_etype - 1];

      // obtain_nnodes - Obtain number of nodes per element given etype
      b_sfe->nnodes[2] = iv[b_sfe->etypes[2] - 1];
      b_sfe->topo_dim = topo_dim;

      //  Geometric dimension
      if (xs.size(1) < topo_dim) {
        geom_dim = topo_dim;
      }

      b_sfe->geom_dim = geom_dim;

      //  Set up quadrature
      tabulate_quadratures(etypes_data[0], (((etypes_data[0] >> 2 & 7) +
        (b_sfe->etypes[2] >> 2 & 7)) + ((geom_etype >> 2 & 7) > 1)) + (geom_dim >
        topo_dim), &b_sfe->nqp, b_sfe->ws.data, &b_sfe->ws.size[0],
                           b_sfe->cs.data, b_sfe->cs.size);

      //  Trial space shape functions & derivs
      tabulate_shapefuncs(etypes_data[0], b_sfe->cs.data, b_sfe->cs.size,
                          b_sfe->shapes_trial, b_sfe->derivs_trial);

      //  Geometry space shape functions & derivs
      if (etypes_data[0] != geom_etype) {
        tabulate_shapefuncs(geom_etype, b_sfe->cs.data, b_sfe->cs.size,
                            b_sfe->shapes_geom, b_sfe->derivs_geom);
      } else {
        loop_ub = b_sfe->shapes_trial.size(1) * b_sfe->shapes_trial.size(0);
        b_sfe->shapes_geom.set_size(b_sfe->shapes_trial.size(0),
          b_sfe->shapes_trial.size(1));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->shapes_geom[i] = b_sfe->shapes_trial[i];
        }

        loop_ub = b_sfe->derivs_trial.size(2) * b_sfe->derivs_trial.size(1) *
          b_sfe->derivs_trial.size(0);
        b_sfe->derivs_geom.set_size(b_sfe->derivs_trial.size(0),
          b_sfe->derivs_trial.size(1), b_sfe->derivs_trial.size(2));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->derivs_geom[i] = b_sfe->derivs_trial[i];
        }
      }

      //  Test space shape functions & derivs
      if ((etypes_data[0] != b_sfe->etypes[2]) && (geom_etype != b_sfe->etypes[2]))
      {
        tabulate_shapefuncs(b_sfe->etypes[2], b_sfe->cs.data, b_sfe->cs.size,
                            b_sfe->shapes_test, b_sfe->derivs_test);
      } else if (etypes_data[0] == b_sfe->etypes[2]) {
        loop_ub = b_sfe->shapes_trial.size(1) * b_sfe->shapes_trial.size(0);
        b_sfe->shapes_test.set_size(b_sfe->shapes_trial.size(0),
          b_sfe->shapes_trial.size(1));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->shapes_test[i] = b_sfe->shapes_trial[i];
        }

        loop_ub = b_sfe->derivs_trial.size(2) * b_sfe->derivs_trial.size(1) *
          b_sfe->derivs_trial.size(0);
        b_sfe->derivs_test.set_size(b_sfe->derivs_trial.size(0),
          b_sfe->derivs_trial.size(1), b_sfe->derivs_trial.size(2));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->derivs_test[i] = b_sfe->derivs_trial[i];
        }
      } else {
        loop_ub = b_sfe->shapes_geom.size(1) * b_sfe->shapes_geom.size(0);
        b_sfe->shapes_test.set_size(b_sfe->shapes_geom.size(0),
          b_sfe->shapes_geom.size(1));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->shapes_test[i] = b_sfe->shapes_geom[i];
        }

        loop_ub = b_sfe->derivs_geom.size(2) * b_sfe->derivs_geom.size(1) *
          b_sfe->derivs_geom.size(0);
        b_sfe->derivs_test.set_size(b_sfe->derivs_geom.size(0),
          b_sfe->derivs_geom.size(1), b_sfe->derivs_geom.size(2));
        for (i = 0; i < loop_ub; i++) {
          b_sfe->derivs_test[i] = b_sfe->derivs_geom[i];
        }
      }
    } else {
      geom_dim = b_sfe->geom_dim;
      topo_dim = b_sfe->topo_dim;
      geom_etype = b_sfe->etypes[1];
    }

    //  potentially skip re-tabulating
    b_sfe->cs_phy.set_size(b_sfe->nqp, geom_dim);
    i = b_sfe->nqp;
    if (0 <= i - 1) {
      nrhs = xs.size(1) - 1;
      unnamed_idx_1 = static_cast<signed char>(xs.size(1));
    }

    for (q = 0; q < i; q++) {
      int m;

      //  NOTE The following can be optimized efficiently due to the the upper
      m = b_sfe->shapes_geom.size(1);
      v.set_size(1, static_cast<int>(unnamed_idx_1));
      for (j = 0; j <= nrhs; j++) {
        v[j] = b_sfe->shapes_geom[b_sfe->shapes_geom.size(1) * q] * xs[j];
      }

      for (b_i = 2; b_i <= m; b_i++) {
        double Ni;
        Ni = b_sfe->shapes_geom[(b_i + b_sfe->shapes_geom.size(1) * q) - 1];
        for (j = 0; j <= nrhs; j++) {
          v[j] = v[j] + Ni * xs[j + xs.size(1) * (b_i - 1)];
        }
      }

      loop_ub = v.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sfe->cs_phy[i1 + b_sfe->cs_phy.size(1) * q] = v[i1];
      }
    }

    //  Compute Jacobian
    b_sfe->wdetJ.set_size(b_sfe->nqp);
    if ((geom_etype == 68) || (geom_etype == 132) || (geom_etype == 36) ||
        (((geom_etype >> 2 & 7) == 1) && (topo_dim == geom_dim))) {
      double a;
      double d;
      int n;

      //  Either a simplex or a multi-linear volume element, so a single
      b_sfe->jacTs.set_size(1);

      // compute_jact - Compute Jacobian^T and its determinant from q-th deriv in table
      geom_dim = xs.size(1);
      topo_dim = b_sfe->derivs_geom.size(2);
      std::memset(&b_dv[0], 0, 9U * sizeof(double));
      n = xs.size(0);
      for (int k{0}; k < n; k++) {
        for (b_i = 0; b_i < topo_dim; b_i++) {
          for (j = 0; j < geom_dim; j++) {
            i = j + 3 * b_i;
            b_dv[i] += xs[j + xs.size(1) * k] * b_sfe->derivs_geom[b_i +
              b_sfe->derivs_geom.size(2) * k];
          }
        }
      }

      if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
        if (xs.size(1) == 1) {
          a = b_dv[0];
        } else if (xs.size(1) == 2) {
          // det2 - Compute determinant of 2x2 matrix.
          a = b_dv[0] * b_dv[4] - b_dv[1] * b_dv[3];
        } else {
          // det3 - Compute determinant of 3x3 matrix.
          a = (b_dv[2] * (b_dv[3] * b_dv[7] - b_dv[4] * b_dv[6]) + b_dv[5] *
               (b_dv[1] * b_dv[6] - b_dv[0] * b_dv[7])) + b_dv[8] * (b_dv[0] *
            b_dv[4] - b_dv[1] * b_dv[3]);
        }
      } else if (b_sfe->derivs_geom.size(2) == 1) {
        d = b_dv[0] * b_dv[0] + b_dv[1] * b_dv[1];
        if (xs.size(1) == 3) {
          d += b_dv[2] * b_dv[2];
        }

        a = std::sqrt(d);
      } else {
        //  must be 2x3
        b_dv[6] = b_dv[1] * b_dv[5] - b_dv[2] * b_dv[4];
        b_dv[7] = b_dv[2] * b_dv[3] - b_dv[0] * b_dv[5];
        b_dv[8] = b_dv[0] * b_dv[4] - b_dv[1] * b_dv[3];
        a = std::sqrt((b_dv[6] * b_dv[6] + b_dv[7] * b_dv[7]) + b_dv[8] * b_dv[8]);
      }

      for (i = 0; i < 9; i++) {
        b_sfe->jacTs[0].data[i] = b_dv[i];
      }

      d = std::abs(a);
      i = b_sfe->nqp;
      for (q = 0; q < i; q++) {
        b_sfe->wdetJ[q] = d * b_sfe->ws.data[q];
      }
    } else {
      // obtain_elemdegree - Decode the element degree from etype
      b_sfe->jacTs.set_size(b_sfe->nqp);
      i = b_sfe->nqp;
      for (q = 0; q < i; q++) {
        double a;
        int n;

        // compute_jact - Compute Jacobian^T and its determinant from q-th deriv in table
        geom_dim = xs.size(1);
        topo_dim = b_sfe->derivs_geom.size(2);
        std::memset(&b_dv[0], 0, 9U * sizeof(double));
        n = xs.size(0);
        for (int k{0}; k < n; k++) {
          for (b_i = 0; b_i < topo_dim; b_i++) {
            for (j = 0; j < geom_dim; j++) {
              i1 = j + 3 * b_i;
              b_dv[i1] += xs[j + xs.size(1) * k] * b_sfe->derivs_geom[(b_i +
                b_sfe->derivs_geom.size(2) * k) + b_sfe->derivs_geom.size(2) *
                b_sfe->derivs_geom.size(1) * q];
            }
          }
        }

        if (xs.size(1) == b_sfe->derivs_geom.size(2)) {
          if (xs.size(1) == 1) {
            a = b_dv[0];
          } else if (xs.size(1) == 2) {
            // det2 - Compute determinant of 2x2 matrix.
            a = b_dv[0] * b_dv[4] - b_dv[1] * b_dv[3];
          } else {
            // det3 - Compute determinant of 3x3 matrix.
            a = (b_dv[2] * (b_dv[3] * b_dv[7] - b_dv[4] * b_dv[6]) + b_dv[5] *
                 (b_dv[1] * b_dv[6] - b_dv[0] * b_dv[7])) + b_dv[8] * (b_dv[0] *
              b_dv[4] - b_dv[1] * b_dv[3]);
          }
        } else if (b_sfe->derivs_geom.size(2) == 1) {
          a = b_dv[0] * b_dv[0] + b_dv[1] * b_dv[1];
          if (xs.size(1) == 3) {
            a += b_dv[2] * b_dv[2];
          }

          a = std::sqrt(a);
        } else {
          //  must be 2x3
          b_dv[6] = b_dv[1] * b_dv[5] - b_dv[2] * b_dv[4];
          b_dv[7] = b_dv[2] * b_dv[3] - b_dv[0] * b_dv[5];
          b_dv[8] = b_dv[0] * b_dv[4] - b_dv[1] * b_dv[3];
          a = std::sqrt((b_dv[6] * b_dv[6] + b_dv[7] * b_dv[7]) + b_dv[8] *
                        b_dv[8]);
        }

        for (i1 = 0; i1 < 9; i1++) {
          b_sfe->jacTs[q].data[i1] = b_dv[i1];
        }

        b_sfe->wdetJ[q] = a;
        b_sfe->wdetJ[q] = std::abs(b_sfe->wdetJ[q]) * b_sfe->ws.data[q];
      }
    }
  }

  static inline
  void sfe_init_grad1(SfeObject *b_sfe, int q)
  {
    double Jt[9];
    int b_i;
    int d;
    int dim;
    int i;
    int n;
    int sfe_idx_0;

    // sfe_grad - Compute gradients of shape functions in physical space
    if (b_sfe->jacTs.size(0) == 1) {
      for (i = 0; i < 9; i++) {
        Jt[i] = b_sfe->jacTs[0].data[i];
      }
    } else {
      for (i = 0; i < 9; i++) {
        Jt[i] = b_sfe->jacTs[q - 1].data[i];
      }
    }

    dim = b_sfe->derivs_trial.size(2);
    n = b_sfe->derivs_trial.size(1);
    sfe_idx_0 = b_sfe->derivs_trial.size(1);
    b_sfe->grads_trial.set_size(sfe_idx_0, b_sfe->derivs_trial.size(2));
    for (b_i = 0; b_i < n; b_i++) {
      for (d = 0; d < dim; d++) {
        b_sfe->grads_trial[d + b_sfe->grads_trial.size(1) * b_i] =
          b_sfe->derivs_trial[(d + b_sfe->derivs_trial.size(2) * b_i) +
          b_sfe->derivs_trial.size(2) * b_sfe->derivs_trial.size(1) * (q - 1)];
      }
    }

    //  compute gradient for both trial and test
    if (b_sfe->etypes[0] == b_sfe->etypes[2]) {
      solve_sq(Jt, b_sfe->geom_dim, b_sfe->grads_trial);
      sfe_idx_0 = b_sfe->grads_trial.size(1) * b_sfe->grads_trial.size(0);
      b_sfe->grads_test.set_size(b_sfe->grads_trial.size(0),
        b_sfe->grads_trial.size(1));
      for (i = 0; i < sfe_idx_0; i++) {
        b_sfe->grads_test[i] = b_sfe->grads_trial[i];
      }
    } else {
      //  solve for test at the same time
      dim = b_sfe->derivs_test.size(2);
      n = b_sfe->derivs_test.size(1);
      sfe_idx_0 = b_sfe->derivs_test.size(1);
      b_sfe->grads_test.set_size(sfe_idx_0, b_sfe->derivs_test.size(2));
      for (b_i = 0; b_i < n; b_i++) {
        for (d = 0; d < dim; d++) {
          b_sfe->grads_test[d + b_sfe->grads_test.size(1) * b_i] =
            b_sfe->derivs_test[(d + b_sfe->derivs_test.size(2) * b_i) +
            b_sfe->derivs_test.size(2) * b_sfe->derivs_test.size(1) * (q - 1)];
        }
      }

      solve_sq(Jt, b_sfe->geom_dim, b_sfe->grads_trial, b_sfe->grads_test);
    }
  }

  static inline
  void sfe_init_grad2(SfeObject *b_sfe, int q)
  {
    double Jt[9];
    int b_i;
    int d;
    int dim;
    int i;
    int n;
    int sfe_idx_0;

    // sfe_grad - Compute gradients of shape functions in physical space
    if (b_sfe->jacTs.size(0) == 1) {
      for (i = 0; i < 9; i++) {
        Jt[i] = b_sfe->jacTs[0].data[i];
      }
    } else {
      for (i = 0; i < 9; i++) {
        Jt[i] = b_sfe->jacTs[q - 1].data[i];
      }
    }

    dim = b_sfe->derivs_trial.size(2);
    n = b_sfe->derivs_trial.size(1);
    sfe_idx_0 = b_sfe->derivs_trial.size(1);
    b_sfe->grads_trial.set_size(sfe_idx_0, b_sfe->derivs_trial.size(2));
    for (b_i = 0; b_i < n; b_i++) {
      for (d = 0; d < dim; d++) {
        b_sfe->grads_trial[d + b_sfe->grads_trial.size(1) * b_i] =
          b_sfe->derivs_trial[(d + b_sfe->derivs_trial.size(2) * b_i) +
          b_sfe->derivs_trial.size(2) * b_sfe->derivs_trial.size(1) * (q - 1)];
      }
    }

    //  compute gradient for both trial and test
    if (b_sfe->etypes[0] == b_sfe->etypes[2]) {
      solve_sq(Jt, b_sfe->geom_dim, b_sfe->grads_trial);
      sfe_idx_0 = b_sfe->grads_trial.size(1) * b_sfe->grads_trial.size(0);
      b_sfe->grads_test.set_size(b_sfe->grads_trial.size(0),
        b_sfe->grads_trial.size(1));
      for (i = 0; i < sfe_idx_0; i++) {
        b_sfe->grads_test[i] = b_sfe->grads_trial[i];
      }
    } else {
      //  solve for test at the same time
      dim = b_sfe->derivs_test.size(2);
      n = b_sfe->derivs_test.size(1);
      sfe_idx_0 = b_sfe->derivs_test.size(1);
      b_sfe->grads_test.set_size(sfe_idx_0, b_sfe->derivs_test.size(2));
      for (b_i = 0; b_i < n; b_i++) {
        for (d = 0; d < dim; d++) {
          b_sfe->grads_test[d + b_sfe->grads_test.size(1) * b_i] =
            b_sfe->derivs_test[(d + b_sfe->derivs_test.size(2) * b_i) +
            b_sfe->derivs_test.size(2) * b_sfe->derivs_test.size(1) * (q - 1)];
        }
      }

      solve_sq(Jt, b_sfe->geom_dim, b_sfe->grads_trial, b_sfe->grads_test);
    }
  }

  static inline
  void sfe_init_grad3(SfeObject *b_sfe, int q)
  {
    double a__4[9];
    int dim;
    int n;
    int sfe_idx_0;

    // sfe_grad - Compute gradients of shape functions in physical space
    if (b_sfe->jacTs.size(0) == 1) {
      for (sfe_idx_0 = 0; sfe_idx_0 < 9; sfe_idx_0++) {
        a__4[sfe_idx_0] = b_sfe->jacTs[0].data[sfe_idx_0];
      }
    } else {
      for (sfe_idx_0 = 0; sfe_idx_0 < 9; sfe_idx_0++) {
        a__4[sfe_idx_0] = b_sfe->jacTs[q - 1].data[sfe_idx_0];
      }
    }

    //  only compute for test
    dim = b_sfe->derivs_test.size(2);
    n = b_sfe->derivs_test.size(1);
    sfe_idx_0 = b_sfe->derivs_test.size(1);
    b_sfe->grads_test.set_size(sfe_idx_0, b_sfe->derivs_test.size(2));
    for (int i{0}; i < n; i++) {
      for (int d{0}; d < dim; d++) {
        b_sfe->grads_test[d + b_sfe->grads_test.size(1) * i] =
          b_sfe->derivs_test[(d + b_sfe->derivs_test.size(2) * i) +
          b_sfe->derivs_test.size(2) * b_sfe->derivs_test.size(1) * (q - 1)];
      }
    }

    solve_sq(a__4, b_sfe->geom_dim, b_sfe->grads_test);
  }

  static inline
  void sfe_init_grad4(SfeObject *b_sfe, int q)
  {
    double a__3[9];
    int dim;
    int n;
    int sfe_idx_0;

    // sfe_grad - Compute gradients of shape functions in physical space
    if (b_sfe->jacTs.size(0) == 1) {
      for (sfe_idx_0 = 0; sfe_idx_0 < 9; sfe_idx_0++) {
        a__3[sfe_idx_0] = b_sfe->jacTs[0].data[sfe_idx_0];
      }
    } else {
      for (sfe_idx_0 = 0; sfe_idx_0 < 9; sfe_idx_0++) {
        a__3[sfe_idx_0] = b_sfe->jacTs[q - 1].data[sfe_idx_0];
      }
    }

    //  only compute for trial
    dim = b_sfe->derivs_trial.size(2);
    n = b_sfe->derivs_trial.size(1);
    sfe_idx_0 = b_sfe->derivs_trial.size(1);
    b_sfe->grads_trial.set_size(sfe_idx_0, b_sfe->derivs_trial.size(2));
    for (int i{0}; i < n; i++) {
      for (int d{0}; d < dim; d++) {
        b_sfe->grads_trial[d + b_sfe->grads_trial.size(1) * i] =
          b_sfe->derivs_trial[(d + b_sfe->derivs_trial.size(2) * i) +
          b_sfe->derivs_trial.size(2) * b_sfe->derivs_trial.size(1) * (q - 1)];
      }
    }

    solve_sq(a__3, b_sfe->geom_dim, b_sfe->grads_trial);
  }

  static inline
  void sfe_loadvec1(const SfeObject *b_sfe, const ::coder::array<double, 2U> &fs,
                    ::coder::array<double, 1U> &load)
  {
    ::coder::array<double, 2U> v;
    int i;
    int loop_ub;
    int m;
    int n;
    int ncomps;
    int nrhs;
    signed char unnamed_idx_1;

    // sfe_loadvec - Computing load vector for an element
    n = b_sfe->nnodes[2];
    ncomps = fs.size(1);
    load.set_size(fs.size(1) * b_sfe->nnodes[2]);
    loop_ub = fs.size(1) * b_sfe->nnodes[2];
    for (i = 0; i < loop_ub; i++) {
      load[i] = 0.0;
    }

    //  for each quadrature point
    i = b_sfe->nqp;
    if (0 <= i - 1) {
      m = b_sfe->shapes_trial.size(1);
      nrhs = fs.size(1) - 1;
      unnamed_idx_1 = static_cast<signed char>(fs.size(1));
    }

    for (int q{0}; q < i; q++) {
      int b_i;
      int j;

      // interpolate_shape - Interpolate f with q-th shape function in the table
      v.set_size(1, static_cast<int>(unnamed_idx_1));
      for (j = 0; j <= nrhs; j++) {
        v[j] = b_sfe->shapes_trial[b_sfe->shapes_trial.size(1) * q] * fs[j];
      }

      for (b_i = 2; b_i <= m; b_i++) {
        double Ni;
        Ni = b_sfe->shapes_trial[(b_i + b_sfe->shapes_trial.size(1) * q) - 1];
        for (j = 0; j <= nrhs; j++) {
          v[j] = v[j] + Ni * fs[j + fs.size(1) * (b_i - 1)];
        }
      }

      j = 0;
      for (b_i = 0; b_i < n; b_i++) {
        double psi;
        psi = b_sfe->shapes_test[b_i + b_sfe->shapes_test.size(1) * q] *
          b_sfe->wdetJ[q];
        for (int k{0}; k < ncomps; k++) {
          loop_ub = j + k;
          load[loop_ub] = load[loop_ub] + v[k] * psi;
        }

        j += ncomps;
      }
    }
  }

  static inline
  void sfe_loadvec2(const SfeObject *b_sfe, const ::coder::array<double, 2U> &fs,
                    boolean_T compwise, ::coder::array<double, 1U> &load)
  {
    ::coder::array<double, 2U> v;
    int i;
    int loop_ub;
    int m;
    int n;
    int ncomps;
    int nrhs;
    signed char unnamed_idx_1;

    // sfe_loadvec - Computing load vector for an element
    n = b_sfe->nnodes[2] - 1;
    ncomps = fs.size(1) - 1;
    load.set_size(fs.size(1) * b_sfe->nnodes[2]);
    loop_ub = fs.size(1) * b_sfe->nnodes[2];
    for (i = 0; i < loop_ub; i++) {
      load[i] = 0.0;
    }

    //  for each quadrature point
    if (compwise) {
      i = b_sfe->nqp;
      if (0 <= i - 1) {
        m = b_sfe->shapes_trial.size(1);
        nrhs = fs.size(1) - 1;
        unnamed_idx_1 = static_cast<signed char>(fs.size(1));
      }

      for (int q{0}; q < i; q++) {
        int b_i;
        int j;

        // interpolate_shape - Interpolate f with q-th shape function in the table
        v.set_size(1, static_cast<int>(unnamed_idx_1));
        for (j = 0; j <= nrhs; j++) {
          v[j] = b_sfe->shapes_trial[b_sfe->shapes_trial.size(1) * q] * fs[j];
        }

        for (b_i = 2; b_i <= m; b_i++) {
          double Ni;
          Ni = b_sfe->shapes_trial[(b_i + b_sfe->shapes_trial.size(1) * q) - 1];
          for (j = 0; j <= nrhs; j++) {
            v[j] = v[j] + Ni * fs[j + fs.size(1) * (b_i - 1)];
          }
        }

        j = 0;
        for (int k{0}; k <= ncomps; k++) {
          double a;
          a = v[k] * b_sfe->wdetJ[q];
          for (b_i = 0; b_i <= n; b_i++) {
            loop_ub = j + b_i;
            load[loop_ub] = load[loop_ub] + a * b_sfe->shapes_test[b_i +
              b_sfe->shapes_test.size(1) * q];
          }

          j = (j + n) + 1;
        }
      }
    } else {
      //  tensor blocks of DOFs, not component-wise
      i = b_sfe->nqp;
      if (0 <= i - 1) {
        m = b_sfe->shapes_trial.size(1);
        nrhs = fs.size(1) - 1;
        unnamed_idx_1 = static_cast<signed char>(fs.size(1));
      }

      for (int q{0}; q < i; q++) {
        int b_i;
        int j;

        // interpolate_shape - Interpolate f with q-th shape function in the table
        v.set_size(1, static_cast<int>(unnamed_idx_1));
        for (j = 0; j <= nrhs; j++) {
          v[j] = b_sfe->shapes_trial[b_sfe->shapes_trial.size(1) * q] * fs[j];
        }

        for (b_i = 2; b_i <= m; b_i++) {
          double Ni;
          Ni = b_sfe->shapes_trial[(b_i + b_sfe->shapes_trial.size(1) * q) - 1];
          for (j = 0; j <= nrhs; j++) {
            v[j] = v[j] + Ni * fs[j + fs.size(1) * (b_i - 1)];
          }
        }

        j = 0;
        for (b_i = 0; b_i <= n; b_i++) {
          double psi;
          psi = b_sfe->shapes_test[b_i + b_sfe->shapes_test.size(1) * q] *
            b_sfe->wdetJ[q];
          for (int k{0}; k <= ncomps; k++) {
            loop_ub = j + k;
            load[loop_ub] = load[loop_ub] + v[k] * psi;
          }

          j = (j + ncomps) + 1;
        }
      }
    }
  }

  static inline
  void sfe_loadvec3(const SfeObject *b_sfe, const ::coder::array<double, 2U> &fs,
                    ::coder::array<double, 1U> &load)
  {
    ::coder::array<double, 2U> v;
    int i;
    int loop_ub;
    int m;
    int n;
    int ncomps;
    int nrhs;
    signed char unnamed_idx_1;

    // sfe_loadvec - Computing load vector for an element
    n = b_sfe->nnodes[2];
    ncomps = fs.size(1);
    load.set_size(fs.size(1) * b_sfe->nnodes[2]);
    loop_ub = fs.size(1) * b_sfe->nnodes[2];
    for (i = 0; i < loop_ub; i++) {
      load[i] = 0.0;
    }

    //  for each quadrature point
    i = b_sfe->nqp;
    if (0 <= i - 1) {
      m = b_sfe->shapes_trial.size(1);
      nrhs = fs.size(1) - 1;
      unnamed_idx_1 = static_cast<signed char>(fs.size(1));
    }

    for (int q{0}; q < i; q++) {
      int b_i;
      int j;

      // interpolate_shape - Interpolate f with q-th shape function in the table
      v.set_size(1, static_cast<int>(unnamed_idx_1));
      for (j = 0; j <= nrhs; j++) {
        v[j] = b_sfe->shapes_trial[b_sfe->shapes_trial.size(1) * q] * fs[j];
      }

      for (b_i = 2; b_i <= m; b_i++) {
        double Ni;
        Ni = b_sfe->shapes_trial[(b_i + b_sfe->shapes_trial.size(1) * q) - 1];
        for (j = 0; j <= nrhs; j++) {
          v[j] = v[j] + Ni * fs[j + fs.size(1) * (b_i - 1)];
        }
      }

      j = 0;
      for (int k{0}; k < ncomps; k++) {
        double a;
        a = v[k] * b_sfe->wdetJ[q];
        for (b_i = 0; b_i < n; b_i++) {
          loop_ub = j + b_i;
          load[loop_ub] = load[loop_ub] + a * b_sfe->shapes_test[b_i +
            b_sfe->shapes_test.size(1) * q];
        }

        j += n;
      }
    }
  }
}

// End of code generation (sfe_internal.cpp)
