#include <Servo.h>

Servo servo[5];

int current_angle[5] = {90,180,90,0,0};

void write_servo_angle(int index, int angle) {
  if (index == 1) {
    int us = map(angle, 0, 270, 500, 2500);
    servo[index].writeMicroseconds(us);

  } else {
    servo[index].write(angle);

  }
}
void msg_to_command(String cmd, int targets[]) {
  for(int i = 0;i < 5;i++) {
    targets[i] = current_angle[i];
  }
  int start = 0;

  while (start < cmd.length()) {
    int comma_1 = cmd.indexOf(",",start);
    if (comma_1 == -1) break;
    int comma_2 = cmd.indexOf(",",comma_1 + 1);

    String servo_str = cmd.substring(start,comma_1);
    String angle_str;

    if (comma_2 == -1) {
      angle_str = cmd.substring(comma_1 + 1);
      start = cmd.length();
    } else {
      angle_str = cmd.substring(comma_1 + 1,comma_2);
      start = comma_2 + 1;
    }

    int servo_index = servo_str.toInt();
    int angle = angle_str.toInt();
    
    if (servo_index >= 0 && servo_index < 5) {
      targets[servo_index] = angle;
    }
  }
}

void servo_movement(int targets[]) {
  float position[5];
  float increment[5];

  int max_change = 0;

  for (int i = 0; i < 5; i++) {
    int change = abs(targets[i] - current_angle[i]);
    if (change > max_change) {
      max_change = change;
    }
    position[i] = current_angle[i];
  }

  if (max_change == 0) return;

  for (int i = 0; i < 5; i++) {
    increment[i] =
      (float)(targets[i] - current_angle[i]) / max_change;
  }

  for (int step = 0; step < max_change; step++) {
    for (int i = 0; i < 5; i++) {
      position[i] += increment[i];
      write_servo_angle(i, round(position[i]));
    }
    delay(20);
  }

  for (int i = 0; i < 5; i++) {
    write_servo_angle(i, targets[i]);
    current_angle[i] = targets[i];
  }
}
void setup() {
  Serial.begin(115200);

  servo[0].attach(3);
  servo[1].attach(5);
  servo[2].attach(6);
  servo[3].attach(9);
  servo[4].attach(10);
  for (int i = 0; i < 5; i++) {
    write_servo_angle(i, current_angle[i]);
  }
}

void loop() {
 if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    int targets[5];
    
    msg_to_command(cmd,targets);
    servo_movement(targets);
  }
}
