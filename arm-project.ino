#include <Servo.h>

Servo servo[5];

int current_angle[5] = {90,180,90,0,0};

String input_serial;
int servo_index;
int target_angle;
int comma;

void setup() {
  Serial.begin(115200);

  servo[0].attach(3);
  servo[1].attach(5);
  servo[2].attach(6);
  servo[3].attach(9);
  servo[4].attach(10);
  
  for (int i=0;i < 5;i++) {
    servo[i].write(current_angle[i]);
  }
}
void loop() {
  if (Serial.available()) {
    input_serial = Serial.readStringUntil('\n');
    
    comma = input_serial.indexOf(',');
    servo_index = input_serial.substring(0, comma).toInt();
    target_angle = input_serial.substring(comma + 1).toInt();
    
    int current = current_angle[servo_index];
    if (current > target_angle) {
      for (; current > target_angle; current--) {
        servo[servo_index].write(current);
        delay(20);
      }
    } else {
      for (; current < target_angle; current++) {
        servo[servo_index].write(current);
        delay(20);
      }
    }
    current_angle[servo_index] = target_angle;
    Serial.println(servo_index);
    Serial.println(current_angle[servo_index]);
  }
}
