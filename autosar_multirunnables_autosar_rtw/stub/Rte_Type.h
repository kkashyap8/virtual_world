/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "ASWC"
   ARXML schema: "4.2"
   File generated on: "11-Apr-2019 13:43:52"  */

#ifndef Rte_Type_h
#define Rte_Type_h
#include "Std_Types.h"

/* AUTOSAR Implementation data types, specific to software component */
/* AUTOSAR Primitive Types */
typedef float64 Double;
typedef sint8 SInt8;

/* AUTOSAR Array Types */
typedef Double rt_Array_Double_2[2];
typedef SInt8 rt_Array_SInt8_2[2];
typedef void* Rte_Instance;

#endif
