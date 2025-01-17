/*-----------------------------------------------------------------------------

 Slave_Propulsion.ino

 @authors: Tyler Rose

 @date: 4/7/2024

 @brief: This code for the StarTanker project represents the slave Arduino Mega program used 
for manual control and testing of the propulsion system via Bluetooth communication. 
It enables a user to operate and verify the movement of servo motors connected 
to valves and thrusters in the satellite refueling system. The system receives 
commands from a master Bluetooth device to perform specific actions on the servos, 
simulating real-world propulsion and refueling behaviors.
------------------------------------------------------------------------------*/

#include <SoftwareSerial.h>
#include <Servo.h>

Servo servoMotorValve1;
Servo servoMotorValve2;
Servo servoMotorValve3;
Servo servoMotorValve4;
Servo servoMotorThruster;

#define BT_NAME   "BT_Slave"

//SoftwareSerial mySerial(3, 4); // RX, TX

void setup()
{
  //Home Valves
  homeValve(160, servoMotorValve1);
  homeValve(160, servoMotorValve2);
  homeValve(160, servoMotorValve3);
  homeValve(160, servoMotorValve4);

  Serial.begin(9600);// Initialize serial communication at 9600 baud rate

  Serial1.begin(9600);// Initialize serial1 communication at 9600 baud rate
  Serial.println("Arduino receiver");

  servoMotorValve1.attach(7);// Attach servo 1 to pin 7
  servoMotorValve2.attach(8);// Attach servo 2 to pin 8
  servoMotorValve3.attach(9);// Attach servo 3 to pin 9
  servoMotorValve4.attach(11); // Attach servo 4 to pin 11
  servoMotorThruster.attach(10); // Attach servo 5 to pin 10

}

void loop()
{
  if (Serial1.available()) {
    int command = Serial1.parseInt(); // Read the incoming command
    Serial.println(Serial1.parseInt());
    Serial.print("the command ");
    Serial.println(command);


    if (command == 5) {
      openValve(servoMotorValve1); // Move servo 1 from 80 to 150 then back to 80 in 10 ms
    } 
    else if (command == 6) {
      openValve(servoMotorValve2); // Move servo 1 from 80 to 150 then back to 80 in 10 ms
    } 
    else if (command == 7) {
      openValve(servoMotorValve3); // Move servo 1 from 80 to 150 then back to 80 in 10 ms
    } 
    else if (command == 8) {
      openValve(servoMotorValve4); // Move servo 1 from 80 to 150 then back to 80 in 10 ms
    } 
    else if (command == 2) {
      moveThruster(30, servoMotorThruster); // Move servo 2 to position 0
    } 
    else if (command == 3) {
      moveThruster(90, servoMotorThruster); // Move servo 2 to position 90
    } 
    else if (command == 4) {
      moveThruster(150, servoMotorThruster); // Move servo 2 to position 180
    }
  }



  if (Serial1.available()) {
    Serial1.println(Serial.parseInt());
  }
}



void openValve(Servo &servo) {
  for (int pos = 140; pos >= 40; pos--) { // Move from 80 to 150
    servo.write(pos);
    delay(100);
  }
  for (int pos = 40; pos <= 140; pos++) { // Move from 150 back to 80
    servo.write(pos);
    delay(100);
  }
}

void moveThruster(int targetPosition, Servo &servo) {
  servo.write(targetPosition); // Move the specified servo to the specified position
}
void homeValve(int targetPosition, Servo &servo) {
  servo.write(targetPosition); // Move the specified servo to the specified position
}