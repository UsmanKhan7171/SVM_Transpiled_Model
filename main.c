/*
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include files */
#include "rt_nonfinite.h"
#include "predictLabelsSVM.h"
#include "main.h"
#include "predictLabelsSVM_terminate.h"
#include "predictLabelsSVM_initialize.h"
#include <stdio.h>

/* Function Declarations */
static void argInit_100x2_real_T(double result[200]);
static double argInit_real_T(void);
static void main_predictLabelsSVM(void);

/* Function Definitions */
static void argInit_100x2_real_T(double result[200])
{
  int idx0;
  double result_tmp;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 100; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_tmp = argInit_real_T();
    result[idx0] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 100] = result_tmp;
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_predictLabelsSVM(void)
{
  double dv1[200];
  cell_wrap_0 label[100];

  /* Initialize function 'predictLabelsSVM' input arguments. */
  /* Initialize function input argument 'x'. */
  /* Call the entry-point 'predictLabelsSVM'. */
  argInit_100x2_real_T(dv1);
  predictLabelsSVM(dv1, label);
}

int main(int argc, const char * const argv[])
{
   printf("Application Started...\r\n");
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  predictLabelsSVM_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_predictLabelsSVM();

  /* Terminate the application.
     You do not need to do this more than one time. */
  predictLabelsSVM_terminate();
  return 0;
}

/* End of code generation (main.c) */
