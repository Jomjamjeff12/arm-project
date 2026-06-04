#include <Servo.h>
#include <Dictionary.h>
// base = 0
// main arm = 1
// forearm = 2
Servo servo[3];

String servo_num;
int new_angle;
int old_angle = 0;

void setup() {
  Serial.begin(115200);

  servo[1].attach(9);
  servo[2].attach(10);

  servo[1].write(90);
  servo[2].write(175);
}

void loop() {
  if (Serial.available()) {
    servo_num = Serial.readStringUntil('\n');
    servo_num.trim();
    int servo_index = servo_num.toInt();

    while (Serial.available() == 0); 
    String new_str = Serial.readStringUntil('\n');
    new_str.trim();
    new_angle = new_str.toInt();
    int output_angle = new_angle + servo[servo_index].read();
    
    Serial.println(servo_index);
    Serial.println(old_angle);
    servo[servo_index].write(old_angle);
  }
}
