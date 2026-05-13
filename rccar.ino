#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3); // RX, TX

char cmd;

void setup() {

  BT.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {

  if (BT.available()) {

    cmd = BT.read();

    if (cmd == 'F') {
      forward();
    }

    else if (cmd == 'B') {
      backward();
    }

    else if (cmd == 'L') {
      left();
    }

    else if (cmd == 'R') {
      right();
    }

    else if (cmd == 'S') {
      stopCar();
    }
  }
}

void forward() {

  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);

  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void backward() {

  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);

  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void left() {

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);

  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void right() {

  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void stopCar() {

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}