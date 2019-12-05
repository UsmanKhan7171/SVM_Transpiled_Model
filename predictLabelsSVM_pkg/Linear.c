/*
 * Linear.c
 *
 * Code generation for function 'Linear'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "predictLabelsSVM.h"
#include "Linear.h"

/* Function Definitions */
void Linear(const double svT[48], const double x[200], double kernelProduct[2400])
{
  int i2;
  int i3;
  int kernelProduct_tmp;
  int i4;
  for (i2 = 0; i2 < 100; i2++) {
    for (i3 = 0; i3 < 24; i3++) {
      kernelProduct_tmp = i2 + 100 * i3;
      kernelProduct[kernelProduct_tmp] = 0.0;
      i4 = i3 << 1;
      kernelProduct[kernelProduct_tmp] = x[i2] * svT[i4] + x[i2 + 100] * svT[1 +
        i4];
    }
  }
}

/* End of code generation (Linear.c) */
