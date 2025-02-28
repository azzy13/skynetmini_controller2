/*
 * skynetmini_controller2.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "skynetmini_controller2".
 *
 * Model version              : 1.6
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Thu Nov 14 09:52:36 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "skynetmini_controller2.h"
#include "rtwtypes.h"
#include "skynetmini_controller2_types.h"
#include "skynetmini_controller2_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>

/* Block signals (default storage) */
B_skynetmini_controller2_T skynetmini_controller2_B;

/* Block states (default storage) */
DW_skynetmini_controller2_T skynetmini_controller2_DW;

/* Real-time model */
RT_MODEL_skynetmini_controlle_T skynetmini_controller2_M_ =
  RT_MODEL_skynetmini_controlle_T();
RT_MODEL_skynetmini_controlle_T *const skynetmini_controller2_M =
  &skynetmini_controller2_M_;

/*
 * System initialize for enable system:
 *    '<S4>/Enabled Subsystem'
 *    '<S5>/Enabled Subsystem'
 */
void skynetmin_EnabledSubsystem_Init(B_EnabledSubsystem_skynetmini_T *localB,
  P_EnabledSubsystem_skynetmini_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S10>/In1' incorporates:
   *  Outport: '<S10>/Out1'
   */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for enable system:
 *    '<S4>/Enabled Subsystem'
 *    '<S5>/Enabled Subsystem'
 */
void skynetmini_con_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_skynetmini_controller2_std_msgs_Float64 *rtu_In1,
  B_EnabledSubsystem_skynetmini_T *localB)
{
  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S10>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
}

/* Model step function */
void skynetmini_controller2_step(void)
{
  SL_Bus_skynetmini_controller2_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_skynetmini_controller2_std_msgs_Float64 tmp;
  real_T rtb_Max;
  real_T rtb_ego_accel_l;
  real_T rtb_ego_accel_m;
  boolean_T b_varargout_1;

  /* Outputs for Atomic SubSystem: '<Root>/space_gap' */
  /* MATLABSystem: '<S5>/SourceBlock' */
  b_varargout_1 = Sub_skynetmini_controller2_2.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S5>/SourceBlock' */
  skynetmini_con_EnabledSubsystem(b_varargout_1, &tmp,
    &skynetmini_controller2_B.EnabledSubsystem_e);

  /* End of Outputs for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/space_gap' */

  /* Outputs for Atomic SubSystem: '<Root>/ego_car_speed' */
  /* MATLABSystem: '<S4>/SourceBlock' */
  b_varargout_1 = Sub_skynetmini_controller2_1.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S4>/SourceBlock' */
  skynetmini_con_EnabledSubsystem(b_varargout_1, &tmp,
    &skynetmini_controller2_B.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/ego_car_speed' */

  /* MinMax: '<S2>/Max' incorporates:
   *  Constant: '<S2>/minimum_speed_for_calculation'
   */
  if ((skynetmini_controller2_P.minimum_speed_for_calculation_V >=
       skynetmini_controller2_B.EnabledSubsystem.In1.Data) || rtIsNaN
      (skynetmini_controller2_B.EnabledSubsystem.In1.Data)) {
    rtb_Max = skynetmini_controller2_P.minimum_speed_for_calculation_V;
  } else {
    rtb_Max = skynetmini_controller2_B.EnabledSubsystem.In1.Data;
  }

  /* End of MinMax: '<S2>/Max' */

  /* MinMax: '<S2>/Min' incorporates:
   *  Constant: '<S2>/maximum_space_gap_for_calculation'
   */
  if ((skynetmini_controller2_B.EnabledSubsystem_e.In1.Data <=
       skynetmini_controller2_P.maximum_space_gap_for_calculati) || rtIsNaN
      (skynetmini_controller2_P.maximum_space_gap_for_calculati)) {
    rtb_ego_accel_m = skynetmini_controller2_B.EnabledSubsystem_e.In1.Data;
  } else {
    rtb_ego_accel_m = skynetmini_controller2_P.maximum_space_gap_for_calculati;
  }

  /* MATLAB Function: '<S2>/accel_normal' incorporates:
   *  Constant: '<S2>/alpha_normal'
   *  Constant: '<S2>/tau_normal'
   *  MinMax: '<S2>/Min'
   */
  rtb_ego_accel_m = (rtb_ego_accel_m - skynetmini_controller2_P.tau_normal_Value
                     * rtb_Max) * skynetmini_controller2_P.alpha_normal_Value;
  if (!(rtb_ego_accel_m <= 1.5)) {
    rtb_ego_accel_m = 1.5;
  }

  if (!(rtb_ego_accel_m >= -3.0)) {
    rtb_ego_accel_m = -3.0;
  }

  /* End of MATLAB Function: '<S2>/accel_normal' */

  /* MATLAB Function: '<S2>/accel_brake' incorporates:
   *  Constant: '<S2>/alpha_break'
   */
  if (skynetmini_controller2_P.alpha_break_Value <= 1.5) {
    rtb_ego_accel_l = skynetmini_controller2_P.alpha_break_Value;
  } else {
    rtb_ego_accel_l = 1.5;
  }

  if (!(rtb_ego_accel_l >= -3.0)) {
    rtb_ego_accel_l = -3.0;
  }

  /* End of MATLAB Function: '<S2>/accel_brake' */

  /* MATLAB Function: '<S2>/calculate_acceleration' incorporates:
   *  Constant: '<S2>/eco_accel'
   */
  if (rtb_ego_accel_m > 0.0) {
    if ((rtb_ego_accel_m <= skynetmini_controller2_P.eco_accel_Value) || rtIsNaN
        (skynetmini_controller2_P.eco_accel_Value)) {
      /* BusAssignment: '<Root>/Bus Assignment' */
      rtb_BusAssignment.Data = rtb_ego_accel_m;
    } else {
      /* BusAssignment: '<Root>/Bus Assignment' */
      rtb_BusAssignment.Data = skynetmini_controller2_P.eco_accel_Value;
    }
  } else if (rtb_ego_accel_l > 0.0) {
    /* MATLAB Function: '<S2>/balance_accel' */
    rtb_Max = rtb_Max * rtb_Max * -0.00021453 - 0.14715;
    if ((rtb_ego_accel_m >= rtb_Max) || rtIsNaN(rtb_Max)) {
      /* BusAssignment: '<Root>/Bus Assignment' */
      rtb_BusAssignment.Data = rtb_ego_accel_m;
    } else {
      /* BusAssignment: '<Root>/Bus Assignment' */
      rtb_BusAssignment.Data = rtb_Max;
    }
  } else {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = rtb_ego_accel_l;
  }

  /* End of MATLAB Function: '<S2>/calculate_acceleration' */

  /* Outputs for Atomic SubSystem: '<Root>/ego_car_accel' */
  /* MATLABSystem: '<S3>/SinkBlock' */
  Pub_skynetmini_controller2_3.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/ego_car_accel' */
}

/* Model initialize function */
void skynetmini_controller2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset((static_cast<void *>(&skynetmini_controller2_B)), 0,
                sizeof(B_skynetmini_controller2_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(&skynetmini_controller2_DW), 0,
                sizeof(DW_skynetmini_controller2_T));

  {
    char_T b_zeroDelimTopic_0[17];
    char_T b_zeroDelimTopic[11];
    static const char_T b_zeroDelimTopic_1[11] = "/lead_dist";
    static const char_T b_zeroDelimTopic_2[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_3[11] = "/cmd_accel";

    /* Start for Atomic SubSystem: '<Root>/space_gap' */
    /* Start for MATLABSystem: '<S5>/SourceBlock' */
    skynetmini_controller2_DW.obj_g.matlabCodegenIsDeleted = false;
    skynetmini_controller2_DW.objisempty = true;
    skynetmini_controller2_DW.obj_g.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_1[i];
    }

    Sub_skynetmini_controller2_2.createSubscriber(&b_zeroDelimTopic[0], 1);
    skynetmini_controller2_DW.obj_g.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/space_gap' */

    /* Start for Atomic SubSystem: '<Root>/ego_car_speed' */
    /* Start for MATLABSystem: '<S4>/SourceBlock' */
    skynetmini_controller2_DW.obj_n.matlabCodegenIsDeleted = false;
    skynetmini_controller2_DW.objisempty_g = true;
    skynetmini_controller2_DW.obj_n.isInitialized = 1;
    for (int32_T i = 0; i < 17; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_2[i];
    }

    Sub_skynetmini_controller2_1.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    skynetmini_controller2_DW.obj_n.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/ego_car_speed' */

    /* Start for Atomic SubSystem: '<Root>/ego_car_accel' */
    /* Start for MATLABSystem: '<S3>/SinkBlock' */
    skynetmini_controller2_DW.obj.matlabCodegenIsDeleted = false;
    skynetmini_controller2_DW.objisempty_j = true;
    skynetmini_controller2_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_3[i];
    }

    Pub_skynetmini_controller2_3.createPublisher(&b_zeroDelimTopic[0], 1);
    skynetmini_controller2_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/ego_car_accel' */
  }

  /* SystemInitialize for Atomic SubSystem: '<Root>/space_gap' */
  /* SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem' */
  skynetmin_EnabledSubsystem_Init(&skynetmini_controller2_B.EnabledSubsystem_e,
    &skynetmini_controller2_P.EnabledSubsystem_e);

  /* End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/space_gap' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/ego_car_speed' */
  /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  skynetmin_EnabledSubsystem_Init(&skynetmini_controller2_B.EnabledSubsystem,
    &skynetmini_controller2_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/ego_car_speed' */
}

/* Model terminate function */
void skynetmini_controller2_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/space_gap' */
  /* Terminate for MATLABSystem: '<S5>/SourceBlock' */
  if (!skynetmini_controller2_DW.obj_g.matlabCodegenIsDeleted) {
    skynetmini_controller2_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/space_gap' */

  /* Terminate for Atomic SubSystem: '<Root>/ego_car_speed' */
  /* Terminate for MATLABSystem: '<S4>/SourceBlock' */
  if (!skynetmini_controller2_DW.obj_n.matlabCodegenIsDeleted) {
    skynetmini_controller2_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/ego_car_speed' */

  /* Terminate for Atomic SubSystem: '<Root>/ego_car_accel' */
  /* Terminate for MATLABSystem: '<S3>/SinkBlock' */
  if (!skynetmini_controller2_DW.obj.matlabCodegenIsDeleted) {
    skynetmini_controller2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/ego_car_accel' */
}
