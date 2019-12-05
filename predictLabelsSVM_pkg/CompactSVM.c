/*
 * CompactSVM.c
 *
 * Code generation for function 'CompactSVM'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "predictLabelsSVM.h"
#include "CompactSVM.h"
#include "Linear.h"

/* Function Definitions */
void CompactSVM_score(const double obj_Alpha[24], const double
                      obj_SupportVectorsT[48], const double Xin[200], double S
                      [100])
{
  double dv0[2400];
  int i0;
  double d1;
  int i1;
  Linear(obj_SupportVectorsT, Xin, dv0);
  for (i0 = 0; i0 < 100; i0++) {
    d1 = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d1 += dv0[i0 + 100 * i1] * obj_Alpha[i1];
    }

    S[i0] = d1 + -14.414878048780476;
  }
}

/* End of code generation (CompactSVM.c) */
