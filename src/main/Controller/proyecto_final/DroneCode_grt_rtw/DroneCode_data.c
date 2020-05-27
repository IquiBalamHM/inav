/*
 * DroneCode_data.c
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

/* Block parameters (default storage) */
P_DroneCode_T DroneCode_P = {
  /* Mask Parameter: Z_Controller3_P
   * Referenced by: '<S136>/Proportional Gain'
   */
  3.0,

  /* Mask Parameter: Z_Controller2_P
   * Referenced by: '<S88>/Proportional Gain'
   */
  3.0,

  /* Mask Parameter: S_Controller_P
   * Referenced by: '<S40>/Proportional Gain'
   */
  3.0,

  /* Computed Parameter: Drone1_A
   * Referenced by: '<Root>/Drone1'
   */
  { -5.03, -40.21, -1.5, -2.4 },

  /* Computed Parameter: Drone1_C
   * Referenced by: '<Root>/Drone1'
   */
  { 0.0, 50.0, 150.0, 100.0 },

  /* Computed Parameter: Drone2_A
   * Referenced by: '<Root>/Drone2'
   */
  { -5.03, -40.21, -1.5, -2.4 },

  /* Computed Parameter: Drone2_C
   * Referenced by: '<Root>/Drone2'
   */
  { 0.0, 50.0, 150.0, 100.0 },

  /* Computed Parameter: Drone3_A
   * Referenced by: '<Root>/Drone3'
   */
  { -5.03, -40.21, -1.5, -2.4 },

  /* Computed Parameter: Drone3_C
   * Referenced by: '<Root>/Drone3'
   */
  { 0.0, 50.0, 150.0, 100.0 },

  /* Expression: [1 -0.964]
   * Referenced by: '<Root>/Discrete2_Transfer_Fcn'
   */
  { 1.0, -0.964 },

  /* Expression: [1 -0.88]
   * Referenced by: '<Root>/Discrete2_Transfer_Fcn'
   */
  { 1.0, -0.88 },

  /* Expression: 0
   * Referenced by: '<Root>/Discrete2_Transfer_Fcn'
   */
  0.0,

  /* Expression: [0.956999 -0.926415]
   * Referenced by: '<Root>/Discrete_1_Transfer_Fcn'
   */
  { 0.956999, -0.926415 },

  /* Expression: [1 -0.877141]
   * Referenced by: '<Root>/Discrete_1_Transfer_Fcn'
   */
  { 1.0, -0.877141 },

  /* Expression: 0
   * Referenced by: '<Root>/Discrete_1_Transfer_Fcn'
   */
  0.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<Root>/Transfer Fcn 1'
   */
  -10.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<Root>/Transfer Fcn 1'
   */
  -7.0,

  /* Computed Parameter: TransferFcn1_D
   * Referenced by: '<Root>/Transfer Fcn 1'
   */
  1.0
};
