/*-----------------------------------------------------------------------------

 Master_Propulsion.ino

 @authors: Tyler Rose

 @date: 4/7/2024

 @brief: This code for the StarTanker project represents the Master Arduino Uno program used 
for manual control and testing of the propulsion system via Bluetooth communication. 
It enables a user to operate and verify the movement of servo motors connected 
to valves and thrusters in the satellite refueling system. The system Sends 
commands to a Slave Bluetooth device to perform specific actions on the servos, 
simulating real-world propulsion and refueling behaviors.
------------------------------------------------------------------------------*/
#include <SoftwareSerial.h>

#define BT_NAME   "BT_Master"

#define SLAVE_ADDRESS "14,3,50b97"  //98d3:31:8095c3

SoftwareSerial mySerial(3, 4); // RX, TX

void setup()
{
  Serial.begin(9600);

  mySerial.begin(9600);
  Serial.println("Arduino Sender");

}


void loop()
{
  if (mySerial.available())
    Serial.println(mySerial.parseInt());
  if (Serial.available())
    mySerial.println(Serial.parseInt());
}
