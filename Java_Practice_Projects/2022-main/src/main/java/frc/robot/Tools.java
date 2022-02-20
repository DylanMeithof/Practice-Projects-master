// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot;

/** Add your docs here. */
public class Tools {

    public static double featherJoystick(double joystickvalue, double sensitivity) {
        //final double sensitivity = 0.3;//(values of 0-1) 0:y=input y=input^3 
        //Sensitivity is in values of 0 to 1 and it is cubing the input.

        double joystickOutput = joystickvalue;
        joystickOutput = ((1-sensitivity)*joystickOutput) + (sensitivity*Math.pow(joystickOutput, 3));
      
        if (Math.abs(joystickvalue)<.1) {
          return 0;
        } else if (joystickvalue > .95) {
          return 1;
        }else if (joystickvalue < -0.95) {
          return -1;
        } else {
          return (joystickOutput) ;
        }
      }  

      public static double DeadbandJoystick(double joystickvalue) {   
        if (Math.abs(joystickvalue)<.1) {
          return 0;
        } else if (joystickvalue > .95) {
          return 1;
        }else if (joystickvalue < -0.95) {
          return -1;
        } else {
          return joystickvalue;
        }
      }
}
