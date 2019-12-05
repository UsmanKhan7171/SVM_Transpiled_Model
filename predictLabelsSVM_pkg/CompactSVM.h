/*
 * CompactSVM.h
 *
 * Code generation for function 'CompactSVM'
 *
 */

#ifndef COMPACTSVM_H
#define COMPACTSVM_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "predictLabelsSVM_types.h"

/* Function Declarations */
extern void CompactSVM_score(const double obj_Alpha[24], const double
  obj_SupportVectorsT[48], const double Xin[200], double S[100]);

#endif

/* End of code generation (CompactSVM.h) */
