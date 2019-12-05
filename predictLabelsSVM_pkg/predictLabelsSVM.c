/*
 * predictLabelsSVM.c
 *
 * Code generation for function 'predictLabelsSVM'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "predictLabelsSVM.h"
#include "CompactSVM.h"

/* Function Definitions */
void predictLabelsSVM(const double x[200], cell_wrap_0 label[100])
{
  static const double Mdl_Alpha[24] = { -1.0, -1.0, -1.0, -1.0,
    -0.70731707317073189, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    0.70731707317073189, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

  static const double Mdl_SupportVectorsT[48] = { 4.7, 1.4, 4.9, 1.5, 4.6, 1.5,
    4.7, 1.6, 4.7, 1.4, 4.8, 1.8, 4.9, 1.5, 4.8, 1.4, 5.0, 1.7, 5.1, 1.6, 4.5,
    1.6, 4.7, 1.5, 5.1, 1.9, 4.5, 1.7, 5.0, 1.5, 4.9, 2.0, 4.9, 1.8, 4.8, 1.8,
    4.9, 1.8, 5.1, 1.5, 5.6, 1.4, 4.8, 1.8, 5.0, 1.9, 5.1, 1.8 };

  double f[100];
  int i;
  double scores[200];
  double a[100];
  int i1;
  boolean_T exitg1;
  boolean_T rowmatch;
  int ix;
  int j;
  boolean_T exitg2;
  boolean_T b[200];
  boolean_T notNaN[100];
  static const char Mdl_NonzeroProbClasses[20] = { 'v', 'v', 'e', 'i', 'r', 'r',
    's', 'g', 'i', 'i', 'c', 'n', 'o', 'i', 'l', 'c', 'o', 'a', 'r', ' ' };

  int i2;
  char t0_f1_data[10];
  double d0;
  unsigned int u0;

  /* PREDICTLABELSSVM Label new observations using trained SVM model Mdl */
  /*    predictLabelsSVM predicts the vector of labels label using  */
  /*    the saved SVM model Mdl and the predictor data x. */
  CompactSVM_score(Mdl_Alpha, Mdl_SupportVectorsT, x, f);
  for (i = 0; i < 100; i++) {
    a[i] = -f[i];
  }

  memcpy(&scores[0], &a[0], 100U * sizeof(double));
  memcpy(&scores[100], &a[0], 100U * sizeof(double));
  i1 = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 2)) {
    rowmatch = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 10)) {
      ix = j << 1;
      if (!(Mdl_NonzeroProbClasses[1 + ix] == Mdl_NonzeroProbClasses[i + ix])) {
        rowmatch = false;
        exitg2 = true;
      } else {
        j++;
      }
    }

    if (rowmatch) {
      i1 = i + 1;
      exitg1 = true;
    } else {
      i++;
    }
  }

  memcpy(&scores[i1 * 100 + -100], &f[0], 100U * sizeof(double));
  for (ix = 0; ix < 200; ix++) {
    b[ix] = rtIsNaN(scores[ix]);
  }

  for (i = 0; i < 100; i++) {
    notNaN[i] = true;
  }

  i = -1;
  i1 = 0;
  i2 = 100;
  for (j = 0; j < 100; j++) {
    i1++;
    i2++;
    i++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2)) {
      if (!b[ix - 1]) {
        notNaN[i] = false;
        exitg1 = true;
      } else {
        ix += 100;
      }
    }
  }

  for (i2 = 0; i2 < 100; i2++) {
    rowmatch = !notNaN[i2];
    f[i2] = rtNaN;
    if (rowmatch) {
      d0 = scores[100 + i2];
      if ((scores[i2] < d0) || (rtIsNaN(scores[i2]) && (!rtIsNaN(d0)))) {
        i = 2;
      } else {
        i = 1;
      }

      f[i2] = i;
    }

    notNaN[i2] = rowmatch;
  }

  for (ix = 0; ix < 10; ix++) {
    t0_f1_data[ix] = Mdl_NonzeroProbClasses[ix << 1];
  }

  for (i = 0; i < 100; i++) {
    label[i].f1.size[0] = 1;
    label[i].f1.size[1] = 10;
    for (ix = 0; ix < 10; ix++) {
      label[i].f1.data[ix] = t0_f1_data[ix];
    }
  }

  for (i2 = 0; i2 < 100; i2++) {
    if (notNaN[i2]) {
      if (f[i2] < 4.294967296E+9) {
        if (f[i2] >= 0.0) {
          u0 = (unsigned int)f[i2];
        } else {
          u0 = 0U;
        }
      } else if (f[i2] >= 4.294967296E+9) {
        u0 = MAX_uint32_T;
      } else {
        u0 = 0U;
      }

      i = 11 - (int)u0;
      if (f[i2] < 4.294967296E+9) {
        if (f[i2] >= 0.0) {
          u0 = (unsigned int)f[i2];
        } else {
          u0 = 0U;
        }
      } else if (f[i2] >= 4.294967296E+9) {
        u0 = MAX_uint32_T;
      } else {
        u0 = 0U;
      }

      i1 = (int)u0;
      label[i2].f1.size[0] = 1;
      label[i2].f1.size[1] = i;
      for (ix = 0; ix < i; ix++) {
        label[i2].f1.data[ix] = Mdl_NonzeroProbClasses[(i1 + (ix << 1)) - 1];
      }
    }
  }
}

/* End of code generation (predictLabelsSVM.c) */
