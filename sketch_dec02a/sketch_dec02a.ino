const int LEFT_FORWARD = 13;
const int LEFT_BACKWARD = 12;
const int PWMB = 11;
const int RIGHT_FORWARD = 9;
const int RIGHT_BACKWARD = 8;
const int PWMA = 10;

int analogInput_zero = 0;
int analogInput_one = 1;
int analogInput_two = 2;
int analogInput_three = 3;
int analogInput_four = 4;
int analogInput_five = 5;


int value_ProxM = 0;
int value_ProxR = 0;
int value_ProxL = 0;

int value_four = 0;
int value_five = 0;


void setup() {
  Serial.begin(9750);
  pinMode(analogInput_zero, INPUT);
  pinMode(analogInput_one, INPUT);
  pinMode(analogInput_two, INPUT);
  pinMode(analogInput_three, INPUT);
  pinMode(analogInput_four, INPUT);
  pinMode(analogInput_five, INPUT);

  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(PWMB, OUTPUT);


}

void loop() {
  value_ProxM = analogRead(analogInput_zero);
  value_ProxR = analogRead(analogInput_one);
  value_ProxL = analogRead(analogInput_two); //Reads all analog values

  if(value_ProxM > 800){
    digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 150);
    analogWrite(PWMB, 150);
  }*/


}
