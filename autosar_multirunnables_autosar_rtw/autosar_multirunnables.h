/*
 * File: autosar_multirunnables.h
 *
 * Code generated for Simulink model 'autosar_multirunnables'.
 *
 * Model version                  : 1.246
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Thu Apr 11 13:43:45 2019
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_autosar_multirunnables_h_
#define RTW_HEADER_autosar_multirunnables_h_
#ifndef autosar_multirunnables_COMMON_INCLUDES_
# define autosar_multirunnables_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_ASWC.h"
#endif                                 /* autosar_multirunnables_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct tag_BlockIO {
  real_T Add;                          /* '<S4>/Add' */
} BlockIO;

/* Block states (auto storage) for system '<Root>' */
typedef struct tag_D_Work {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  int8_T Delay_DSTATE;                 /* '<S3>/Delay' */
  int8_T Delay_DSTATE_m[2];            /* '<S2>/Delay' */
  int8_T Delay_DSTATE_a;               /* '<S1>/Delay' */
} D_Work;

/* Block signals (auto storage) */
extern BlockIO rtB;

/* Block states (auto storage) */
extern D_Work rtDWork;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'autosar_multirunnables'
 * '<S1>'   : 'autosar_multirunnables/Runnable1_subsystem'
 * '<S2>'   : 'autosar_multirunnables/Runnable2_subsystem'
 * '<S3>'   : 'autosar_multirunnables/Runnable3_subsystem'
 * '<S4>'   : 'autosar_multirunnables/Runnable1_subsystem/Subsystem'
 */
#endif                                 /* RTW_HEADER_autosar_multirunnables_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
