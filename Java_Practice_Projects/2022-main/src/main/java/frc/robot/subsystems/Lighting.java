// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.subsystems;

import edu.wpi.first.wpilibj2.command.SubsystemBase;
import edu.wpi.first.wpilibj.AddressableLED;
import edu.wpi.first.wpilibj.AddressableLEDBuffer;
import edu.wpi.first.wpilibj.RobotState;

public class Lighting extends SubsystemBase {
  /** Creates a new Lighting. */
  private static AddressableLED m_led;
  private static AddressableLEDBuffer m_ledBuffer;
  private static int m_rainbowFirstPixelHue;
  public Lighting() {  
    m_led = new AddressableLED(0);
    m_ledBuffer = new AddressableLEDBuffer(60);
    m_led.setLength(m_ledBuffer.getLength());
    m_led.setData(m_ledBuffer);
    m_led.start();
  }

  @Override
  public void periodic() {
    // This method will be called once per scheduler run
    if(RobotState.isAutonomous()){
      LEDRY();
    }
    if(RobotState.isDisabled()){
      All_LEDRainbow();
    }
    
    if(RobotState.isEnabled() && RobotState.isTeleop()){
      All_LEDRainbow();
      /*if (RobotContainer.m_ColorSensor.proximity>200){
        switch(RobotContainer.m_ColorSensor.DetectedColor){
          case "R":
            Body_LEDColor(255, 0, 0);
            break;
          case "G":
            Body_LEDColor(0, 255, 0);
            break;
          case "B":
            Body_LEDColor(0, 0, 255);
            break;
          case "Y":
            Body_LEDColor(255, 255, 0);
            break;
          case "U":
            Body_LEDColor(255, 255, 255);
            break;
          default:
            Body_LEDColor(255, 255, 255);
            break;
        }
      }else{
        if(DriverStation.getInstance().getAlliance() == DriverStation.Alliance.Blue){
          Body_ShowAlliance(0,0,255);
        }else {
          Body_ShowAlliance(255,0,0);
        }
      }*/
    }
  }
  private void LEDRY(){
      
    for (var i = 0; i < m_ledBuffer.getLength(); i++) {
      if (i % 2 == 0)
        m_ledBuffer.setRGB(i, 255, 150, 0);
      else
        m_ledBuffer.setRGB(i, 255, 0, 0);
      }     
    m_led.setData(m_ledBuffer);
  }
  private void All_LEDRainbow(){
    //--- make a rainbow pattern on LEDs ---//
    int ShowLEDs = m_ledBuffer.getLength();
    for (var i = 0; i < ShowLEDs; i++) {
        final var hue = (m_rainbowFirstPixelHue + (i * 180 / m_ledBuffer.getLength())) % 180;
        m_ledBuffer.setHSV(i, hue, 255, 128);
      }
      m_rainbowFirstPixelHue += 3;
      m_rainbowFirstPixelHue %= 180;
    m_led.setData(m_ledBuffer);
  }

}
