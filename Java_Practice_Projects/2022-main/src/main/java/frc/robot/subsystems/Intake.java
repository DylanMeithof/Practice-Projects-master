// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.subsystems;

import edu.wpi.first.wpilibj.RobotState;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import com.ctre.phoenix.motorcontrol.NeutralMode;
import com.ctre.phoenix.motorcontrol.FeedbackDevice;
import com.ctre.phoenix.motorcontrol.TalonFXControlMode;
import com.ctre.phoenix.motorcontrol.TalonFXFeedbackDevice;
import com.ctre.phoenix.motorcontrol.can.TalonFXConfiguration;
import com.ctre.phoenix.motorcontrol.can.TalonFX;
import frc.robot.Constants;
import frc.robot.RobotContainer;
import frc.robot.Tools;

public class Intake extends SubsystemBase {
  /** Creates a new Intake. */
  TalonFX IntakeMotor = new TalonFX(24);
  public Intake() {}

  @Override
  public void periodic() {
    // This method will be called once per scheduler run
    if(RobotState.isEnabled() && RobotState.isTeleop()){
      IntakeMotor.set(TalonFXControlMode.PercentOutput, -1 * Tools.featherJoystick(RobotContainer.OperatorController.getRightY(), Constants.JoystickSensitivity));
  }
}

  public void getBalls(){
    IntakeMotor.set(TalonFXControlMode.PercentOutput, -0.5);
  }
  public void shootBalls(){
    IntakeMotor.set(TalonFXControlMode.PercentOutput, 1);
  }
  public void disableIntake(){
    IntakeMotor.set(TalonFXControlMode.PercentOutput, 0);
  }
}
