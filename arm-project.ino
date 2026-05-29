#include <Servo.h>

// base = 0
// main arm = 1
// forearm = 2
Servo servo[3];

String servo_num;
int servo_angle;

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
    String angle_str = Serial.readStringUntil('\n');
    angle_str.trim();
    servo_angle = angle_str.toInt();
    
    servo[servo_index].write(servo_angle);
  }
}
