// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot;

import edu.wpi.first.wpilibj.GenericHID;
import edu.wpi.first.wpilibj.XboxController;
import frc.robot.commands.Auto;
//import frc.robot.commands.ExampleCommand;
import edu.wpi.first.wpilibj2.command.Command;
import frc.robot.subsystems.*;

/**
 * This class is where the bulk of the robot should be declared. Since Command-based is a
 * "declarative" paradigm, very little robot logic should actually be handled in the {@link Robot}
 * periodic methods (other than the scheduler calls). Instead, the structure of the robot (including
 * subsystems, commands, and button mappings) should be declared here.
 */
public class RobotContainer {
  //UI systems are defined here...
  public static XboxController DriverController, OperatorController;

  // The robot's subsystems are defined here...
  //private final ExampleSubsystem m_exampleSubsystem = new ExampleSubsystem();
  public static Climber m_Climber = new Climber();
  public static DriveBase m_DriveBase = new DriveBase();
  public static Intake m_Intake = new Intake();
  public static Lighting m_Lighting = new Lighting();
  public static Shooter m_Shooter = new Shooter();

  //The robot's commands are defined here...
  //private final ExampleCommand m_autoCommand = new ExampleCommand(m_exampleSubsystem);
  private final Auto m_autonomous = new Auto();

  /** The container for the robot. Contains subsystems, OI devices, and commands. */
  public RobotContainer() {
    // Configure the button bindings
    configureButtonBindings();
  }

  /**
   * Use this method to define your button->command mappings. Buttons can be created by
   * instantiating a {@link GenericHID} or one of its subclasses ({@link
   * edu.wpi.first.wpilibj.Joystick} or {@link XboxController}), and then passing it to a {@link
   * edu.wpi.first.wpilibj2.command.button.JoystickButton}.
   */
  private void configureButtonBindings() {
    DriverController = new XboxController(0);
    OperatorController = new XboxController(1);
  }

  /**
   * Use this to pass the autonomous command to the main {@link Robot} class.
   *
   * @return the command to run in autonomous
   */
  public Command getAutonomousCommand() {
    // An ExampleCommand will run in autonomous
    return m_autonomous;
  }
}



//private final XboxController m_joystick = new XboxController(0);
//  final JoystickButton l2 = new JoystickButton(m_joystick, 9);
//  final JoystickButton r2 = new JoystickButton(m_joystick, 10);
//  final JoystickButton l1 = new JoystickButton(m_joystick, 11);
//  final JoystickButton r1 = new JoystickButton(m_joystick, 12);
//  r1.whenPressed(new PrepareToPickup(m_claw, m_wrist, m_elevator));
//  r2.whenPressed(new Pickup(m_claw, m_wrist, m_elevator));
//  l1.whenPressed(new Place(m_claw, m_wrist, m_elevator));
//  l2.whenPressed(new Autonomous(m_drivetrain, m_claw, m_wrist, m_elevator));
// The XboxController class provides named indicies for each of the buttons that you can access with XboxController.Button.kX.value. The rumble feature of the controller can be controlled by using XboxController.setRumble(GenericHID.RumbleType.kRightRumble, value). Many users do a split stick arcade drive that uses the left stick for just forwards / backwards and the right stick for left / right turning.