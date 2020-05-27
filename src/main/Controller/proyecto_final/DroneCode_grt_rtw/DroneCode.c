/*
 * DroneCode.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DroneCode".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue May 26 21:25:24 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "DroneCode.h"
#include "DroneCode_private.h"

/* Block signals (default storage) */
B_DroneCode_T DroneCode_B;

/* Continuous states */
X_DroneCode_T DroneCode_X;

/* Block states (default storage) */
DW_DroneCode_T DroneCode_DW;

/* External inputs (root inport signals with default storage) */
ExtU_DroneCode_T DroneCode_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_DroneCode_T DroneCode_Y;

/* Real-time model */
RT_MODEL_DroneCode_T DroneCode_M_;
RT_MODEL_DroneCode_T *const DroneCode_M = &DroneCode_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 13;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  DroneCode_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  DroneCode_step();
  DroneCode_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  DroneCode_step();
  DroneCode_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void DroneCode_step(void)
{
  real_T rtb_Drone1;
  real_T rtb_Drone2;
  real_T rtb_Drone3;
  if (rtmIsMajorTimeStep(DroneCode_M)) {
    /* set solver stop time */
    if (!(DroneCode_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&DroneCode_M->solverInfo,
                            ((DroneCode_M->Timing.clockTickH0 + 1) *
        DroneCode_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&DroneCode_M->solverInfo,
                            ((DroneCode_M->Timing.clockTick0 + 1) *
        DroneCode_M->Timing.stepSize0 + DroneCode_M->Timing.clockTickH0 *
        DroneCode_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(DroneCode_M)) {
    DroneCode_M->Timing.t[0] = rtsiGetT(&DroneCode_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Drone1' */
  rtb_Drone1 = ((DroneCode_P.Drone1_C[0] * DroneCode_X.Drone1_CSTATE[0] +
                 DroneCode_P.Drone1_C[1] * DroneCode_X.Drone1_CSTATE[1]) +
                DroneCode_P.Drone1_C[2] * DroneCode_X.Drone1_CSTATE[2]) +
    DroneCode_P.Drone1_C[3] * DroneCode_X.Drone1_CSTATE[3];

  /* Outport: '<Root>/Continuous_Response' */
  DroneCode_Y.Continuous_Response = rtb_Drone1;

  /* TransferFcn: '<Root>/Drone2' */
  rtb_Drone2 = ((DroneCode_P.Drone2_C[0] * DroneCode_X.Drone2_CSTATE[0] +
                 DroneCode_P.Drone2_C[1] * DroneCode_X.Drone2_CSTATE[1]) +
                DroneCode_P.Drone2_C[2] * DroneCode_X.Drone2_CSTATE[2]) +
    DroneCode_P.Drone2_C[3] * DroneCode_X.Drone2_CSTATE[3];

  /* Outport: '<Root>/Bilinear_Response' */
  DroneCode_Y.Bilinear_Response = rtb_Drone2;

  /* TransferFcn: '<Root>/Drone3' */
  rtb_Drone3 = ((DroneCode_P.Drone3_C[0] * DroneCode_X.Drone3_CSTATE[0] +
                 DroneCode_P.Drone3_C[1] * DroneCode_X.Drone3_CSTATE[1]) +
                DroneCode_P.Drone3_C[2] * DroneCode_X.Drone3_CSTATE[2]) +
    DroneCode_P.Drone3_C[3] * DroneCode_X.Drone3_CSTATE[3];

  /* Outport: '<Root>/Forward_Response' */
  DroneCode_Y.Forward_Response = rtb_Drone3;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Inport: '<Root>/ReferenceValue'
   */
  DroneCode_B.Sum2 = DroneCode_U.ReferenceValue - rtb_Drone3;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Inport: '<Root>/ReferenceValue'
   */
  DroneCode_B.Sum1 = DroneCode_U.ReferenceValue - rtb_Drone2;
  if (rtmIsMajorTimeStep(DroneCode_M)) {
    /* DiscreteTransferFcn: '<Root>/Discrete2_Transfer_Fcn' incorporates:
     *  Gain: '<S136>/Proportional Gain'
     */
    DroneCode_DW.Discrete2_Transfer_Fcn_tmp = (DroneCode_P.Z_Controller3_P *
      DroneCode_B.Sum2 - DroneCode_P.Discrete2_Transfer_Fcn_DenCoef[1] *
      DroneCode_DW.Discrete2_Transfer_Fcn_states) /
      DroneCode_P.Discrete2_Transfer_Fcn_DenCoef[0];
    DroneCode_B.Discrete2_Transfer_Fcn =
      DroneCode_P.Discrete2_Transfer_Fcn_NumCoef[0] *
      DroneCode_DW.Discrete2_Transfer_Fcn_tmp +
      DroneCode_P.Discrete2_Transfer_Fcn_NumCoef[1] *
      DroneCode_DW.Discrete2_Transfer_Fcn_states;

    /* DiscreteTransferFcn: '<Root>/Discrete_1_Transfer_Fcn' incorporates:
     *  Gain: '<S88>/Proportional Gain'
     */
    DroneCode_DW.Discrete_1_Transfer_Fcn_tmp = (DroneCode_P.Z_Controller2_P *
      DroneCode_B.Sum1 - DroneCode_P.Discrete_1_Transfer_Fcn_DenCoef[1] *
      DroneCode_DW.Discrete_1_Transfer_Fcn_states) /
      DroneCode_P.Discrete_1_Transfer_Fcn_DenCoef[0];
    DroneCode_B.Discrete_1_Transfer_Fcn =
      DroneCode_P.Discrete_1_Transfer_Fcn_NumCoef[0] *
      DroneCode_DW.Discrete_1_Transfer_Fcn_tmp +
      DroneCode_P.Discrete_1_Transfer_Fcn_NumCoef[1] *
      DroneCode_DW.Discrete_1_Transfer_Fcn_states;
  }

  /* Gain: '<S40>/Proportional Gain' incorporates:
   *  Inport: '<Root>/ReferenceValue'
   *  Sum: '<Root>/Sum'
   */
  DroneCode_B.ProportionalGain = (DroneCode_U.ReferenceValue - rtb_Drone1) *
    DroneCode_P.S_Controller_P;

  /* TransferFcn: '<Root>/Transfer Fcn 1' */
  DroneCode_B.TransferFcn1 = 0.0;
  DroneCode_B.TransferFcn1 += DroneCode_P.TransferFcn1_C *
    DroneCode_X.TransferFcn1_CSTATE;
  DroneCode_B.TransferFcn1 += DroneCode_P.TransferFcn1_D *
    DroneCode_B.ProportionalGain;
  if (rtmIsMajorTimeStep(DroneCode_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(DroneCode_M->rtwLogInfo, (DroneCode_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(DroneCode_M)) {
    if (rtmIsMajorTimeStep(DroneCode_M)) {
      /* Update for DiscreteTransferFcn: '<Root>/Discrete2_Transfer_Fcn' */
      DroneCode_DW.Discrete2_Transfer_Fcn_states =
        DroneCode_DW.Discrete2_Transfer_Fcn_tmp;

      /* Update for DiscreteTransferFcn: '<Root>/Discrete_1_Transfer_Fcn' */
      DroneCode_DW.Discrete_1_Transfer_Fcn_states =
        DroneCode_DW.Discrete_1_Transfer_Fcn_tmp;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(DroneCode_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(DroneCode_M)!=-1) &&
          !((rtmGetTFinal(DroneCode_M)-(((DroneCode_M->Timing.clockTick1+
               DroneCode_M->Timing.clockTickH1* 4294967296.0)) * 0.012)) >
            (((DroneCode_M->Timing.clockTick1+DroneCode_M->Timing.clockTickH1*
               4294967296.0)) * 0.012) * (DBL_EPSILON))) {
        rtmSetErrorStatus(DroneCode_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&DroneCode_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DroneCode_M->Timing.clockTick0)) {
      ++DroneCode_M->Timing.clockTickH0;
    }

    DroneCode_M->Timing.t[0] = rtsiGetSolverStopTime(&DroneCode_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.012s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.012, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      DroneCode_M->Timing.clockTick1++;
      if (!DroneCode_M->Timing.clockTick1) {
        DroneCode_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void DroneCode_derivatives(void)
{
  XDot_DroneCode_T *_rtXdot;
  _rtXdot = ((XDot_DroneCode_T *) DroneCode_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Drone1' */
  _rtXdot->Drone1_CSTATE[0] = 0.0;
  _rtXdot->Drone1_CSTATE[0] += DroneCode_P.Drone1_A[0] *
    DroneCode_X.Drone1_CSTATE[0];
  _rtXdot->Drone1_CSTATE[1] = 0.0;
  _rtXdot->Drone1_CSTATE[0] += DroneCode_P.Drone1_A[1] *
    DroneCode_X.Drone1_CSTATE[1];
  _rtXdot->Drone1_CSTATE[2] = 0.0;
  _rtXdot->Drone1_CSTATE[0] += DroneCode_P.Drone1_A[2] *
    DroneCode_X.Drone1_CSTATE[2];
  _rtXdot->Drone1_CSTATE[3] = 0.0;
  _rtXdot->Drone1_CSTATE[0] += DroneCode_P.Drone1_A[3] *
    DroneCode_X.Drone1_CSTATE[3];
  _rtXdot->Drone1_CSTATE[1] += DroneCode_X.Drone1_CSTATE[0];
  _rtXdot->Drone1_CSTATE[2] += DroneCode_X.Drone1_CSTATE[1];
  _rtXdot->Drone1_CSTATE[3] += DroneCode_X.Drone1_CSTATE[2];
  _rtXdot->Drone1_CSTATE[0] += DroneCode_B.TransferFcn1;

  /* Derivatives for TransferFcn: '<Root>/Drone2' */
  _rtXdot->Drone2_CSTATE[0] = 0.0;
  _rtXdot->Drone2_CSTATE[0] += DroneCode_P.Drone2_A[0] *
    DroneCode_X.Drone2_CSTATE[0];
  _rtXdot->Drone2_CSTATE[1] = 0.0;
  _rtXdot->Drone2_CSTATE[0] += DroneCode_P.Drone2_A[1] *
    DroneCode_X.Drone2_CSTATE[1];
  _rtXdot->Drone2_CSTATE[2] = 0.0;
  _rtXdot->Drone2_CSTATE[0] += DroneCode_P.Drone2_A[2] *
    DroneCode_X.Drone2_CSTATE[2];
  _rtXdot->Drone2_CSTATE[3] = 0.0;
  _rtXdot->Drone2_CSTATE[0] += DroneCode_P.Drone2_A[3] *
    DroneCode_X.Drone2_CSTATE[3];
  _rtXdot->Drone2_CSTATE[1] += DroneCode_X.Drone2_CSTATE[0];
  _rtXdot->Drone2_CSTATE[2] += DroneCode_X.Drone2_CSTATE[1];
  _rtXdot->Drone2_CSTATE[3] += DroneCode_X.Drone2_CSTATE[2];
  _rtXdot->Drone2_CSTATE[0] += DroneCode_B.Discrete_1_Transfer_Fcn;

  /* Derivatives for TransferFcn: '<Root>/Drone3' */
  _rtXdot->Drone3_CSTATE[0] = 0.0;
  _rtXdot->Drone3_CSTATE[0] += DroneCode_P.Drone3_A[0] *
    DroneCode_X.Drone3_CSTATE[0];
  _rtXdot->Drone3_CSTATE[1] = 0.0;
  _rtXdot->Drone3_CSTATE[0] += DroneCode_P.Drone3_A[1] *
    DroneCode_X.Drone3_CSTATE[1];
  _rtXdot->Drone3_CSTATE[2] = 0.0;
  _rtXdot->Drone3_CSTATE[0] += DroneCode_P.Drone3_A[2] *
    DroneCode_X.Drone3_CSTATE[2];
  _rtXdot->Drone3_CSTATE[3] = 0.0;
  _rtXdot->Drone3_CSTATE[0] += DroneCode_P.Drone3_A[3] *
    DroneCode_X.Drone3_CSTATE[3];
  _rtXdot->Drone3_CSTATE[1] += DroneCode_X.Drone3_CSTATE[0];
  _rtXdot->Drone3_CSTATE[2] += DroneCode_X.Drone3_CSTATE[1];
  _rtXdot->Drone3_CSTATE[3] += DroneCode_X.Drone3_CSTATE[2];
  _rtXdot->Drone3_CSTATE[0] += DroneCode_B.Discrete2_Transfer_Fcn;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn 1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += DroneCode_P.TransferFcn1_A *
    DroneCode_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += DroneCode_B.ProportionalGain;
}

/* Model initialize function */
void DroneCode_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)DroneCode_M, 0,
                sizeof(RT_MODEL_DroneCode_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DroneCode_M->solverInfo,
                          &DroneCode_M->Timing.simTimeStep);
    rtsiSetTPtr(&DroneCode_M->solverInfo, &rtmGetTPtr(DroneCode_M));
    rtsiSetStepSizePtr(&DroneCode_M->solverInfo, &DroneCode_M->Timing.stepSize0);
    rtsiSetdXPtr(&DroneCode_M->solverInfo, &DroneCode_M->derivs);
    rtsiSetContStatesPtr(&DroneCode_M->solverInfo, (real_T **)
                         &DroneCode_M->contStates);
    rtsiSetNumContStatesPtr(&DroneCode_M->solverInfo,
      &DroneCode_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&DroneCode_M->solverInfo,
      &DroneCode_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&DroneCode_M->solverInfo,
      &DroneCode_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&DroneCode_M->solverInfo,
      &DroneCode_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&DroneCode_M->solverInfo, (&rtmGetErrorStatus
      (DroneCode_M)));
    rtsiSetRTModelPtr(&DroneCode_M->solverInfo, DroneCode_M);
  }

  rtsiSetSimTimeStep(&DroneCode_M->solverInfo, MAJOR_TIME_STEP);
  DroneCode_M->intgData.y = DroneCode_M->odeY;
  DroneCode_M->intgData.f[0] = DroneCode_M->odeF[0];
  DroneCode_M->intgData.f[1] = DroneCode_M->odeF[1];
  DroneCode_M->intgData.f[2] = DroneCode_M->odeF[2];
  DroneCode_M->contStates = ((X_DroneCode_T *) &DroneCode_X);
  rtsiSetSolverData(&DroneCode_M->solverInfo, (void *)&DroneCode_M->intgData);
  rtsiSetSolverName(&DroneCode_M->solverInfo,"ode3");
  rtmSetTPtr(DroneCode_M, &DroneCode_M->Timing.tArray[0]);
  rtmSetTFinal(DroneCode_M, 9.996);
  DroneCode_M->Timing.stepSize0 = 0.012;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    DroneCode_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    /*
     * Set pointers to the data and signal info each state
     */
    {
      static int_T rt_LoggedStateWidths[] = {
        4,
        4,
        4,
        1,
        1,
        1
      };

      static int_T rt_LoggedStateNumDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedStateDimensions[] = {
        4,
        4,
        4,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedStateIsVarDims[] = {
        0,
        0,
        0,
        0,
        0,
        0
      };

      static BuiltInDTypeId rt_LoggedStateDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedStateComplexSignals[] = {
        0,
        0,
        0,
        0,
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedStateLabels[] = {
        "CSTATE",
        "CSTATE",
        "CSTATE",
        "CSTATE",
        "states",
        "states"
      };

      static const char_T *rt_LoggedStateBlockNames[] = {
        "DroneCode/Drone1",
        "DroneCode/Drone2",
        "DroneCode/Drone3",
        "DroneCode/Transfer Fcn 1",
        "DroneCode/Discrete2_Transfer_Fcn",
        "DroneCode/Discrete_1_Transfer_Fcn"
      };

      static const char_T *rt_LoggedStateNames[] = {
        "",
        "",
        "",
        "",
        "",
        ""
      };

      static boolean_T rt_LoggedStateCrossMdlRef[] = {
        0,
        0,
        0,
        0,
        0,
        0
      };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedStateSignalInfo = {
        6,
        rt_LoggedStateWidths,
        rt_LoggedStateNumDimensions,
        rt_LoggedStateDimensions,
        rt_LoggedStateIsVarDims,
        (NULL),
        (NULL),
        rt_LoggedStateDataTypeIds,
        rt_LoggedStateComplexSignals,
        (NULL),
        rt_LoggingStatePreprocessingFcnPtrs,

        { rt_LoggedStateLabels },
        (NULL),
        (NULL),
        (NULL),

        { rt_LoggedStateBlockNames },

        { rt_LoggedStateNames },
        rt_LoggedStateCrossMdlRef,
        rt_RTWLogDataTypeConvert
      };

      static void * rt_LoggedStateSignalPtrs[6];
      rtliSetLogXSignalPtrs(DroneCode_M->rtwLogInfo, (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
      rtliSetLogXSignalInfo(DroneCode_M->rtwLogInfo, &rt_LoggedStateSignalInfo);
      rt_LoggedStateSignalPtrs[0] = (void*)&DroneCode_X.Drone1_CSTATE[0];
      rt_LoggedStateSignalPtrs[1] = (void*)&DroneCode_X.Drone2_CSTATE[0];
      rt_LoggedStateSignalPtrs[2] = (void*)&DroneCode_X.Drone3_CSTATE[0];
      rt_LoggedStateSignalPtrs[3] = (void*)&DroneCode_X.TransferFcn1_CSTATE;
      rt_LoggedStateSignalPtrs[4] = (void*)
        &DroneCode_DW.Discrete2_Transfer_Fcn_states;
      rt_LoggedStateSignalPtrs[5] = (void*)
        &DroneCode_DW.Discrete_1_Transfer_Fcn_states;
    }

    rtliSetLogT(DroneCode_M->rtwLogInfo, "tout");
    rtliSetLogX(DroneCode_M->rtwLogInfo, "xout");
    rtliSetLogXFinal(DroneCode_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(DroneCode_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(DroneCode_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(DroneCode_M->rtwLogInfo, 0);
    rtliSetLogDecimation(DroneCode_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &DroneCode_Y.Continuous_Response,
        &DroneCode_Y.Bilinear_Response,
        &DroneCode_Y.Forward_Response
      };

      rtliSetLogYSignalPtrs(DroneCode_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "DroneCode/Continuous_Response",
        "DroneCode/Bilinear_Response",
        "DroneCode/Forward_Response" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          3,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(DroneCode_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
    }

    rtliSetLogY(DroneCode_M->rtwLogInfo, "yout");
  }

  /* block I/O */
  (void) memset(((void *) &DroneCode_B), 0,
                sizeof(B_DroneCode_T));

  /* states (continuous) */
  {
    (void) memset((void *)&DroneCode_X, 0,
                  sizeof(X_DroneCode_T));
  }

  /* states (dwork) */
  (void) memset((void *)&DroneCode_DW, 0,
                sizeof(DW_DroneCode_T));

  /* external inputs */
  DroneCode_U.ReferenceValue = 0.0;

  /* external outputs */
  (void) memset((void *)&DroneCode_Y, 0,
                sizeof(ExtY_DroneCode_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(DroneCode_M->rtwLogInfo, 0.0, rtmGetTFinal
    (DroneCode_M), DroneCode_M->Timing.stepSize0, (&rtmGetErrorStatus
    (DroneCode_M)));

  /* InitializeConditions for TransferFcn: '<Root>/Drone1' */
  DroneCode_X.Drone1_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Drone2' */
  DroneCode_X.Drone2_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Drone3' */
  DroneCode_X.Drone3_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Drone1' */
  DroneCode_X.Drone1_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Drone2' */
  DroneCode_X.Drone2_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Drone3' */
  DroneCode_X.Drone3_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Drone1' */
  DroneCode_X.Drone1_CSTATE[2] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Drone2' */
  DroneCode_X.Drone2_CSTATE[2] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Drone3' */
  DroneCode_X.Drone3_CSTATE[2] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Drone1' */
  DroneCode_X.Drone1_CSTATE[3] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Drone2' */
  DroneCode_X.Drone2_CSTATE[3] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Drone3' */
  DroneCode_X.Drone3_CSTATE[3] = 0.0;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete2_Transfer_Fcn' */
  DroneCode_DW.Discrete2_Transfer_Fcn_states =
    DroneCode_P.Discrete2_Transfer_Fcn_InitialS;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete_1_Transfer_Fcn' */
  DroneCode_DW.Discrete_1_Transfer_Fcn_states =
    DroneCode_P.Discrete_1_Transfer_Fcn_Initial;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn 1' */
  DroneCode_X.TransferFcn1_CSTATE = 0.0;
}

/* Model terminate function */
void DroneCode_terminate(void)
{
  /* (no terminate code required) */
}
