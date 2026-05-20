const int trigPin = 10;
const int echoPin = 9;

int straight1 = 70;
int straight2 = 55;

int pos = 0;


#include <Servo.h>

#define BUZZER 13




Servo servo;
Servo servo2;
int angle = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);


  servo.attach(11);
  servo2.attach(6);

  pinMode(BUZZER, OUTPUT);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {
    int dist = meas1();
    Serial.println(dist);

    servo.write(pos);
    delay(15);
    digitalWrite(12, LOW);



    if (dist <= 3) {
      servo2.write(pos);

      tone(BUZZER, 85);
      delay(1000);
      noTone(BUZZER);
      delay(100);
      digitalWrite(12, HIGH);
      digitalWrite(8, HIGH);
      delay(500);
      digitalWrite(8, LOW);
      delay(500);
    }
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(15);
  }
}


int meas1() {

  float duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration * .0343) / 2;

  return distance;
}
