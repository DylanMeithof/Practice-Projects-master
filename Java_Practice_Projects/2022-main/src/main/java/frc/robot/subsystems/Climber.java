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

public class Climber extends SubsystemBase {
  /** Creates a new Climber. */
  TalonFX LeftArmMotor = new TalonFX(25);
  TalonFX RightArmMotor = new TalonFX(21);


  public Climber() {

    RightArmMotor.follow(LeftArmMotor);
    RightArmMotor.setNeutralMode(NeutralMode.Brake);
    LeftArmMotor.setNeutralMode(NeutralMode.Brake);
  }

  @Override
  public void periodic() {
    // This method will be called once per scheduler run
  if(RobotState.isEnabled() && RobotState.isTeleop()){
      LeftArmMotor.set(TalonFXControlMode.PercentOutput, -1 * Tools.featherJoystick(RobotContainer.OperatorController.getLeftY(), Constants.JoystickSensitivity));
  }}
}
