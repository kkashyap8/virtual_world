/*
 * File: autosar_multirunnables.c
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

#include "autosar_multirunnables.h"
#ifndef PORTABLE_WORDSIZES
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif
#endif                                 /* PORTABLE_WORDSIZES */

/* Block signals (auto storage) */
BlockIO rtB;

/* Block states (auto storage) */
D_Work rtDWork;

/* Model step function */
void Runnable1(void)
{
  int8_T Delay_n;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable1_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Runnable1_subsystem'
   */
  /* UnitDelay: '<S1>/Delay' */
  Delay_n = rtDWork.Delay_DSTATE_a;

  /* Outputs for Enabled SubSystem: '<S1>/Subsystem' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* RelationalOperator: '<S1>/Data Valid' incorporates:
   *  Inport: '<Root>/RPort_DE1 (ErrorStatus)'
   */
  if (Rte_IStatus_Runnable1_RPort_DE1() == 0) {
    /* Sum: '<S4>/Add' incorporates:
     *  Inport: '<Root>/RPort_DE1'
     *  SignalConversion: '<S1>/TmpSignal ConversionAtIn2Outport1'
     *  SignalConversion: '<S3>/TmpSignal ConversionAtTicToc_irvInport1'
     */
    rtB.Add = Rte_IRead_Runnable1_RPort_DE1() + (real_T)
      Rte_IrvIRead_Runnable1_IRV3();
  }

  /* End of RelationalOperator: '<S1>/Data Valid' */
  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* SignalConversion: '<S1>/TmpSignal ConversionAtAdderInport1' incorporates:
   *  SignalConversion: '<S1>/OutportBufferForAdder'
   */
  Rte_IrvIWrite_Runnable1_IRV1(rtB.Add);

  /* Update for UnitDelay: '<S1>/Delay' incorporates:
   *  Gain: '<S1>/Gain'
   *  UnitDelay: '<S1>/Delay'
   */
  rtDWork.Delay_DSTATE_a = (int8_T)-rtDWork.Delay_DSTATE_a;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable1_at_outport_1' */

  /* Outport: '<Root>/PPort_DE1' */
  Rte_IWrite_Runnable1_PPort_DE1(Delay_n);
}

/* Model step function */
void Runnable2(void)
{
  int8_T Delay[2];
  real_T OutportBufferForSubtracter;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable2_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Runnable2_subsystem'
   */
  /* UnitDelay: '<S2>/Delay' */
  Delay[0] = rtDWork.Delay_DSTATE_m[0];
  Delay[1] = rtDWork.Delay_DSTATE_m[1];

  /* SignalConversion: '<S2>/OutportBufferForSubtracter' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   */
  OutportBufferForSubtracter = rtDWork.DiscreteTimeIntegrator_DSTATE;

  /* SignalConversion: '<S2>/TmpSignal ConversionAtSubtracter_irvInport1' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   */
  Rte_IrvIWrite_Runnable2_IRV4(rtDWork.DiscreteTimeIntegrator_DSTATE);

  /* Update for UnitDelay: '<S2>/Delay' incorporates:
   *  Gain: '<S2>/Gain'
   *  UnitDelay: '<S2>/Delay'
   */
  rtDWork.Delay_DSTATE_m[0] = (int8_T)-rtDWork.Delay_DSTATE_m[0];
  rtDWork.Delay_DSTATE_m[1] = (int8_T)-rtDWork.Delay_DSTATE_m[1];

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  SignalConversion: '<S1>/TmpSignal ConversionAtAdderInport1'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtIn1Outport1'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtIn2Outport1'
   *  SignalConversion: '<S3>/TmpSignal ConversionAtMultiplierInport1'
   *  Sum: '<S2>/Subtract'
   */
  rtDWork.DiscreteTimeIntegrator_DSTATE += Rte_IrvIRead_Runnable2_IRV1() -
    Rte_IrvIRead_Runnable2_IRV2();

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable2_at_outport_1' */

  /* Outport: '<Root>/PPort_DE3' */
  Rte_IWrite_Runnable2_PPort_DE3(Delay);

  /* Outport: '<Root>/PPort_DE4' */
  Rte_IWrite_Runnable2_PPort_DE4(OutportBufferForSubtracter);
}

/* Model step function */
void Runnable3(void)
{
  const real_T *tmp;
  int8_T OutportBufferForTicToc;

  /* Inport: '<Root>/RPort_DE2' */
  tmp = Rte_IRead_Runnable3_RPort_DE2();

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable3_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Runnable3_subsystem'
   */
  /* SignalConversion: '<S3>/OutportBufferForTicToc' incorporates:
   *  UnitDelay: '<S3>/Delay'
   */
  OutportBufferForTicToc = rtDWork.Delay_DSTATE;

  /* SignalConversion: '<S3>/TmpSignal ConversionAtTicToc_irvInport1' incorporates:
   *  UnitDelay: '<S3>/Delay'
   */
  Rte_IrvIWrite_Runnable3_IRV3(rtDWork.Delay_DSTATE);

  /* SignalConversion: '<S3>/TmpSignal ConversionAtMultiplierInport1' incorporates:
   *  Product: '<S3>/Product'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtSubtracter_irvInport1'
   *  SignalConversion: '<S3>/TmpSignal ConversionAtIn1Outport1'
   */
  Rte_IrvIWrite_Runnable3_IRV2(Rte_IrvIRead_Runnable3_IRV4() * tmp[0]);

  /* Update for UnitDelay: '<S3>/Delay' incorporates:
   *  Gain: '<S3>/Gain'
   *  UnitDelay: '<S3>/Delay'
   */
  rtDWork.Delay_DSTATE = (int8_T)-rtDWork.Delay_DSTATE;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable3_at_outport_1' */

  /* Outport: '<Root>/PPort_DE2' */
  Rte_IWrite_Runnable3_PPort_DE2(OutportBufferForTicToc);
}

/* Model initialize function */
void Runnable_Init(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable1_at_outport_1' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Runnable1_subsystem'
   */
  /* InitializeConditions for UnitDelay: '<S1>/Delay' */
  rtDWork.Delay_DSTATE_a = 1;

  /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable1_at_outport_1' */

  /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable2_at_outport_1' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Runnable2_subsystem'
   */
  /* InitializeConditions for UnitDelay: '<S2>/Delay' */
  rtDWork.Delay_DSTATE_m[0] = 1;
  rtDWork.Delay_DSTATE_m[1] = 1;

  /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable2_at_outport_1' */

  /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable3_at_outport_1' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Runnable3_subsystem'
   */
  /* InitializeConditions for UnitDelay: '<S3>/Delay' */
  rtDWork.Delay_DSTATE = 1;

  /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable3_at_outport_1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
