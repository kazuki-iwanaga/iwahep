#include <modified_bessel.h>

#include <gsl/gsl_sf_bessel.h>

// https://root.cern/doc/master/SpecFuncMathMore_8cxx_source.html#l00163
double modifiedBessel(double nu, double x) {
  return gsl_sf_bessel_Inu(nu, x);
}