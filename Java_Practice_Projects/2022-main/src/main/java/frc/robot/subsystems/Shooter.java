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


public class Shooter extends SubsystemBase {
  TalonFX ShooterMotor = new TalonFX(22);
  TalonFX IndexMotor = new TalonFX(23);
  /** Creates a new Shooter. */
  public Shooter() {}

  @Override
  public void periodic() {
    if(RobotState.isEnabled() && RobotState.isTeleop()){
      ShooterMotor.set(TalonFXControlMode.PercentOutput, -1 * Tools.featherJoystick(RobotContainer.OperatorController.getRightTriggerAxis(), Constants.JoystickSensitivity));
      IndexMotor.set(TalonFXControlMode.PercentOutput, -1 * Tools.featherJoystick(RobotContainer.OperatorController.getLeftTriggerAxis(), Constants.JoystickSensitivity));
  }
    // This method will be called once per scheduler run
  }
}
