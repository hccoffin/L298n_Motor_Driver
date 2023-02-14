#include <L298n.h>

#define pwma 2
#define fora 3
#define reva 4
#define pwmb 5
#define forb 6
#define revb 7

L298n* motor_driver;
int16_t duty;
String inString = "";

void setup() {
  // put your setup code here, to run once:
  motor_driver = new L298n(pwma, fora, reva, pwmb, forb, revb);
  duty = 0;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor_driver->set(duty, duty);
  long start_t = micros();
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar) || inChar == '-') {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
      duty = (int16_t) inString.toInt();
      Serial.print("Value:");
      Serial.println(duty);
      Serial.print("String: ");
      Serial.println(inString);
      // clear the string for new input:
      inString = "";
    }
    long dt = micros() - start_t;
    Serial.println(dt);
  }
}
