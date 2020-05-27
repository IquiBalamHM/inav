/*
 * DroneCode.h
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

#ifndef RTW_HEADER_DroneCode_h_
#define RTW_HEADER_DroneCode_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef DroneCode_COMMON_INCLUDES_
# define DroneCode_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* DroneCode_COMMON_INCLUDES_ */

#include "DroneCode_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Discrete2_Transfer_Fcn;       /* '<Root>/Discrete2_Transfer_Fcn' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Discrete_1_Transfer_Fcn;      /* '<Root>/Discrete_1_Transfer_Fcn' */
  real_T ProportionalGain;             /* '<S40>/Proportional Gain' */
  real_T TransferFcn1;                 /* '<Root>/Transfer Fcn 1' */
} B_DroneCode_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Discrete2_Transfer_Fcn_states;/* '<Root>/Discrete2_Transfer_Fcn' */
  real_T Discrete_1_Transfer_Fcn_states;/* '<Root>/Discrete_1_Transfer_Fcn' */
  real_T Discrete2_Transfer_Fcn_tmp;   /* '<Root>/Discrete2_Transfer_Fcn' */
  real_T Discrete_1_Transfer_Fcn_tmp;  /* '<Root>/Discrete_1_Transfer_Fcn' */
} DW_DroneCode_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Drone1_CSTATE[4];             /* '<Root>/Drone1' */
  real_T Drone2_CSTATE[4];             /* '<Root>/Drone2' */
  real_T Drone3_CSTATE[4];             /* '<Root>/Drone3' */
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn 1' */
} X_DroneCode_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Drone1_CSTATE[4];             /* '<Root>/Drone1' */
  real_T Drone2_CSTATE[4];             /* '<Root>/Drone2' */
  real_T Drone3_CSTATE[4];             /* '<Root>/Drone3' */
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn 1' */
} XDot_DroneCode_T;

/* State disabled  */
typedef struct {
  boolean_T Drone1_CSTATE[4];          /* '<Root>/Drone1' */
  boolean_T Drone2_CSTATE[4];          /* '<Root>/Drone2' */
  boolean_T Drone3_CSTATE[4];          /* '<Root>/Drone3' */
  boolean_T TransferFcn1_CSTATE;       /* '<Root>/Transfer Fcn 1' */
} XDis_DroneCode_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ReferenceValue;               /* '<Root>/ReferenceValue' */
} ExtU_DroneCode_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Continuous_Response;          /* '<Root>/Continuous_Response' */
  real_T Bilinear_Response;            /* '<Root>/Bilinear_Response' */
  real_T Forward_Response;             /* '<Root>/Forward_Response' */
} ExtY_DroneCode_T;

/* Parameters (default storage) */
struct P_DroneCode_T_ {
  real_T Z_Controller3_P;              /* Mask Parameter: Z_Controller3_P
                                        * Referenced by: '<S136>/Proportional Gain'
                                        */
  real_T Z_Controller2_P;              /* Mask Parameter: Z_Controller2_P
                                        * Referenced by: '<S88>/Proportional Gain'
                                        */
  real_T S_Controller_P;               /* Mask Parameter: S_Controller_P
                                        * Referenced by: '<S40>/Proportional Gain'
                                        */
  real_T Drone1_A[4];                  /* Computed Parameter: Drone1_A
                                        * Referenced by: '<Root>/Drone1'
                                        */
  real_T Drone1_C[4];                  /* Computed Parameter: Drone1_C
                                        * Referenced by: '<Root>/Drone1'
                                        */
  real_T Drone2_A[4];                  /* Computed Parameter: Drone2_A
                                        * Referenced by: '<Root>/Drone2'
                                        */
  real_T Drone2_C[4];                  /* Computed Parameter: Drone2_C
                                        * Referenced by: '<Root>/Drone2'
                                        */
  real_T Drone3_A[4];                  /* Computed Parameter: Drone3_A
                                        * Referenced by: '<Root>/Drone3'
                                        */
  real_T Drone3_C[4];                  /* Computed Parameter: Drone3_C
                                        * Referenced by: '<Root>/Drone3'
                                        */
  real_T Discrete2_Transfer_Fcn_NumCoef[2];/* Expression: [1 -0.964]
                                            * Referenced by: '<Root>/Discrete2_Transfer_Fcn'
                                            */
  real_T Discrete2_Transfer_Fcn_DenCoef[2];/* Expression: [1 -0.88]
                                            * Referenced by: '<Root>/Discrete2_Transfer_Fcn'
                                            */
  real_T Discrete2_Transfer_Fcn_InitialS;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete2_Transfer_Fcn'
                                          */
  real_T Discrete_1_Transfer_Fcn_NumCoef[2];/* Expression: [0.956999 -0.926415]
                                             * Referenced by: '<Root>/Discrete_1_Transfer_Fcn'
                                             */
  real_T Discrete_1_Transfer_Fcn_DenCoef[2];/* Expression: [1 -0.877141]
                                             * Referenced by: '<Root>/Discrete_1_Transfer_Fcn'
                                             */
  real_T Discrete_1_Transfer_Fcn_Initial;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete_1_Transfer_Fcn'
                                          */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn 1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn 1'
                                        */
  real_T TransferFcn1_D;               /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<Root>/Transfer Fcn 1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_DroneCode_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_DroneCode_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[13];
  real_T odeF[3][13];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_DroneCode_T DroneCode_P;

/* Block signals (default storage) */
extern B_DroneCode_T DroneCode_B;

/* Continuous states (default storage) */
extern X_DroneCode_T DroneCode_X;

/* Block states (default storage) */
extern DW_DroneCode_T DroneCode_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_DroneCode_T DroneCode_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_DroneCode_T DroneCode_Y;

/* Model entry point functions */
extern void DroneCode_initialize(void);
extern void DroneCode_step(void);
extern void DroneCode_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DroneCode_T *const DroneCode_M;

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
 * '<Root>' : 'DroneCode'
 * '<S1>'   : 'DroneCode/S_Controller'
 * '<S2>'   : 'DroneCode/Z_Controller2'
 * '<S3>'   : 'DroneCode/Z_Controller3'
 * '<S4>'   : 'DroneCode/S_Controller/Anti-windup'
 * '<S5>'   : 'DroneCode/S_Controller/D Gain'
 * '<S6>'   : 'DroneCode/S_Controller/Filter'
 * '<S7>'   : 'DroneCode/S_Controller/Filter ICs'
 * '<S8>'   : 'DroneCode/S_Controller/I Gain'
 * '<S9>'   : 'DroneCode/S_Controller/Ideal P Gain'
 * '<S10>'  : 'DroneCode/S_Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'DroneCode/S_Controller/Integrator'
 * '<S12>'  : 'DroneCode/S_Controller/Integrator ICs'
 * '<S13>'  : 'DroneCode/S_Controller/N Copy'
 * '<S14>'  : 'DroneCode/S_Controller/N Gain'
 * '<S15>'  : 'DroneCode/S_Controller/P Copy'
 * '<S16>'  : 'DroneCode/S_Controller/Parallel P Gain'
 * '<S17>'  : 'DroneCode/S_Controller/Reset Signal'
 * '<S18>'  : 'DroneCode/S_Controller/Saturation'
 * '<S19>'  : 'DroneCode/S_Controller/Saturation Fdbk'
 * '<S20>'  : 'DroneCode/S_Controller/Sum'
 * '<S21>'  : 'DroneCode/S_Controller/Sum Fdbk'
 * '<S22>'  : 'DroneCode/S_Controller/Tracking Mode'
 * '<S23>'  : 'DroneCode/S_Controller/Tracking Mode Sum'
 * '<S24>'  : 'DroneCode/S_Controller/Tsamp - Integral'
 * '<S25>'  : 'DroneCode/S_Controller/Tsamp - Ngain'
 * '<S26>'  : 'DroneCode/S_Controller/postSat Signal'
 * '<S27>'  : 'DroneCode/S_Controller/preSat Signal'
 * '<S28>'  : 'DroneCode/S_Controller/Anti-windup/Disabled'
 * '<S29>'  : 'DroneCode/S_Controller/D Gain/Disabled'
 * '<S30>'  : 'DroneCode/S_Controller/Filter/Disabled'
 * '<S31>'  : 'DroneCode/S_Controller/Filter ICs/Disabled'
 * '<S32>'  : 'DroneCode/S_Controller/I Gain/Disabled'
 * '<S33>'  : 'DroneCode/S_Controller/Ideal P Gain/Passthrough'
 * '<S34>'  : 'DroneCode/S_Controller/Ideal P Gain Fdbk/Disabled'
 * '<S35>'  : 'DroneCode/S_Controller/Integrator/Disabled'
 * '<S36>'  : 'DroneCode/S_Controller/Integrator ICs/Disabled'
 * '<S37>'  : 'DroneCode/S_Controller/N Copy/Disabled wSignal Specification'
 * '<S38>'  : 'DroneCode/S_Controller/N Gain/Disabled'
 * '<S39>'  : 'DroneCode/S_Controller/P Copy/Disabled'
 * '<S40>'  : 'DroneCode/S_Controller/Parallel P Gain/Internal Parameters'
 * '<S41>'  : 'DroneCode/S_Controller/Reset Signal/Disabled'
 * '<S42>'  : 'DroneCode/S_Controller/Saturation/Passthrough'
 * '<S43>'  : 'DroneCode/S_Controller/Saturation Fdbk/Disabled'
 * '<S44>'  : 'DroneCode/S_Controller/Sum/Passthrough_P'
 * '<S45>'  : 'DroneCode/S_Controller/Sum Fdbk/Disabled'
 * '<S46>'  : 'DroneCode/S_Controller/Tracking Mode/Disabled'
 * '<S47>'  : 'DroneCode/S_Controller/Tracking Mode Sum/Passthrough'
 * '<S48>'  : 'DroneCode/S_Controller/Tsamp - Integral/Disabled wSignal Specification'
 * '<S49>'  : 'DroneCode/S_Controller/Tsamp - Ngain/Passthrough'
 * '<S50>'  : 'DroneCode/S_Controller/postSat Signal/Forward_Path'
 * '<S51>'  : 'DroneCode/S_Controller/preSat Signal/Forward_Path'
 * '<S52>'  : 'DroneCode/Z_Controller2/Anti-windup'
 * '<S53>'  : 'DroneCode/Z_Controller2/D Gain'
 * '<S54>'  : 'DroneCode/Z_Controller2/Filter'
 * '<S55>'  : 'DroneCode/Z_Controller2/Filter ICs'
 * '<S56>'  : 'DroneCode/Z_Controller2/I Gain'
 * '<S57>'  : 'DroneCode/Z_Controller2/Ideal P Gain'
 * '<S58>'  : 'DroneCode/Z_Controller2/Ideal P Gain Fdbk'
 * '<S59>'  : 'DroneCode/Z_Controller2/Integrator'
 * '<S60>'  : 'DroneCode/Z_Controller2/Integrator ICs'
 * '<S61>'  : 'DroneCode/Z_Controller2/N Copy'
 * '<S62>'  : 'DroneCode/Z_Controller2/N Gain'
 * '<S63>'  : 'DroneCode/Z_Controller2/P Copy'
 * '<S64>'  : 'DroneCode/Z_Controller2/Parallel P Gain'
 * '<S65>'  : 'DroneCode/Z_Controller2/Reset Signal'
 * '<S66>'  : 'DroneCode/Z_Controller2/Saturation'
 * '<S67>'  : 'DroneCode/Z_Controller2/Saturation Fdbk'
 * '<S68>'  : 'DroneCode/Z_Controller2/Sum'
 * '<S69>'  : 'DroneCode/Z_Controller2/Sum Fdbk'
 * '<S70>'  : 'DroneCode/Z_Controller2/Tracking Mode'
 * '<S71>'  : 'DroneCode/Z_Controller2/Tracking Mode Sum'
 * '<S72>'  : 'DroneCode/Z_Controller2/Tsamp - Integral'
 * '<S73>'  : 'DroneCode/Z_Controller2/Tsamp - Ngain'
 * '<S74>'  : 'DroneCode/Z_Controller2/postSat Signal'
 * '<S75>'  : 'DroneCode/Z_Controller2/preSat Signal'
 * '<S76>'  : 'DroneCode/Z_Controller2/Anti-windup/Disabled'
 * '<S77>'  : 'DroneCode/Z_Controller2/D Gain/Disabled'
 * '<S78>'  : 'DroneCode/Z_Controller2/Filter/Disabled'
 * '<S79>'  : 'DroneCode/Z_Controller2/Filter ICs/Disabled'
 * '<S80>'  : 'DroneCode/Z_Controller2/I Gain/Disabled'
 * '<S81>'  : 'DroneCode/Z_Controller2/Ideal P Gain/Passthrough'
 * '<S82>'  : 'DroneCode/Z_Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S83>'  : 'DroneCode/Z_Controller2/Integrator/Disabled'
 * '<S84>'  : 'DroneCode/Z_Controller2/Integrator ICs/Disabled'
 * '<S85>'  : 'DroneCode/Z_Controller2/N Copy/Disabled wSignal Specification'
 * '<S86>'  : 'DroneCode/Z_Controller2/N Gain/Disabled'
 * '<S87>'  : 'DroneCode/Z_Controller2/P Copy/Disabled'
 * '<S88>'  : 'DroneCode/Z_Controller2/Parallel P Gain/Internal Parameters'
 * '<S89>'  : 'DroneCode/Z_Controller2/Reset Signal/Disabled'
 * '<S90>'  : 'DroneCode/Z_Controller2/Saturation/Passthrough'
 * '<S91>'  : 'DroneCode/Z_Controller2/Saturation Fdbk/Disabled'
 * '<S92>'  : 'DroneCode/Z_Controller2/Sum/Passthrough_P'
 * '<S93>'  : 'DroneCode/Z_Controller2/Sum Fdbk/Disabled'
 * '<S94>'  : 'DroneCode/Z_Controller2/Tracking Mode/Disabled'
 * '<S95>'  : 'DroneCode/Z_Controller2/Tracking Mode Sum/Passthrough'
 * '<S96>'  : 'DroneCode/Z_Controller2/Tsamp - Integral/Disabled wSignal Specification'
 * '<S97>'  : 'DroneCode/Z_Controller2/Tsamp - Ngain/Passthrough'
 * '<S98>'  : 'DroneCode/Z_Controller2/postSat Signal/Forward_Path'
 * '<S99>'  : 'DroneCode/Z_Controller2/preSat Signal/Forward_Path'
 * '<S100>' : 'DroneCode/Z_Controller3/Anti-windup'
 * '<S101>' : 'DroneCode/Z_Controller3/D Gain'
 * '<S102>' : 'DroneCode/Z_Controller3/Filter'
 * '<S103>' : 'DroneCode/Z_Controller3/Filter ICs'
 * '<S104>' : 'DroneCode/Z_Controller3/I Gain'
 * '<S105>' : 'DroneCode/Z_Controller3/Ideal P Gain'
 * '<S106>' : 'DroneCode/Z_Controller3/Ideal P Gain Fdbk'
 * '<S107>' : 'DroneCode/Z_Controller3/Integrator'
 * '<S108>' : 'DroneCode/Z_Controller3/Integrator ICs'
 * '<S109>' : 'DroneCode/Z_Controller3/N Copy'
 * '<S110>' : 'DroneCode/Z_Controller3/N Gain'
 * '<S111>' : 'DroneCode/Z_Controller3/P Copy'
 * '<S112>' : 'DroneCode/Z_Controller3/Parallel P Gain'
 * '<S113>' : 'DroneCode/Z_Controller3/Reset Signal'
 * '<S114>' : 'DroneCode/Z_Controller3/Saturation'
 * '<S115>' : 'DroneCode/Z_Controller3/Saturation Fdbk'
 * '<S116>' : 'DroneCode/Z_Controller3/Sum'
 * '<S117>' : 'DroneCode/Z_Controller3/Sum Fdbk'
 * '<S118>' : 'DroneCode/Z_Controller3/Tracking Mode'
 * '<S119>' : 'DroneCode/Z_Controller3/Tracking Mode Sum'
 * '<S120>' : 'DroneCode/Z_Controller3/Tsamp - Integral'
 * '<S121>' : 'DroneCode/Z_Controller3/Tsamp - Ngain'
 * '<S122>' : 'DroneCode/Z_Controller3/postSat Signal'
 * '<S123>' : 'DroneCode/Z_Controller3/preSat Signal'
 * '<S124>' : 'DroneCode/Z_Controller3/Anti-windup/Disabled'
 * '<S125>' : 'DroneCode/Z_Controller3/D Gain/Disabled'
 * '<S126>' : 'DroneCode/Z_Controller3/Filter/Disabled'
 * '<S127>' : 'DroneCode/Z_Controller3/Filter ICs/Disabled'
 * '<S128>' : 'DroneCode/Z_Controller3/I Gain/Disabled'
 * '<S129>' : 'DroneCode/Z_Controller3/Ideal P Gain/Passthrough'
 * '<S130>' : 'DroneCode/Z_Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S131>' : 'DroneCode/Z_Controller3/Integrator/Disabled'
 * '<S132>' : 'DroneCode/Z_Controller3/Integrator ICs/Disabled'
 * '<S133>' : 'DroneCode/Z_Controller3/N Copy/Disabled wSignal Specification'
 * '<S134>' : 'DroneCode/Z_Controller3/N Gain/Disabled'
 * '<S135>' : 'DroneCode/Z_Controller3/P Copy/Disabled'
 * '<S136>' : 'DroneCode/Z_Controller3/Parallel P Gain/Internal Parameters'
 * '<S137>' : 'DroneCode/Z_Controller3/Reset Signal/Disabled'
 * '<S138>' : 'DroneCode/Z_Controller3/Saturation/Passthrough'
 * '<S139>' : 'DroneCode/Z_Controller3/Saturation Fdbk/Disabled'
 * '<S140>' : 'DroneCode/Z_Controller3/Sum/Passthrough_P'
 * '<S141>' : 'DroneCode/Z_Controller3/Sum Fdbk/Disabled'
 * '<S142>' : 'DroneCode/Z_Controller3/Tracking Mode/Disabled'
 * '<S143>' : 'DroneCode/Z_Controller3/Tracking Mode Sum/Passthrough'
 * '<S144>' : 'DroneCode/Z_Controller3/Tsamp - Integral/Disabled wSignal Specification'
 * '<S145>' : 'DroneCode/Z_Controller3/Tsamp - Ngain/Passthrough'
 * '<S146>' : 'DroneCode/Z_Controller3/postSat Signal/Forward_Path'
 * '<S147>' : 'DroneCode/Z_Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_DroneCode_h_ */
