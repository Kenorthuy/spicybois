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

int tempsum;


void setup() {
  Serial.begin(9600);
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
  value_ProxM = analogRead(analogInput_three);
  value_ProxR = analogRead(analogInput_one);
  value_ProxL = analogRead(analogInput_two); //Reads all analog values

  if(value_ProxM < 800 && value_ProxR < 950 && value_ProxL < 950){
    digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 125);
    analogWrite(PWMB, 125);
  }
  if(value_ProxM > 800){
    //tempsum = value_ProxR - valueProxL;
    digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
    delay(200);
    if(value_ProxR < value_ProxL){
    digitalWrite(RIGHT_FORWARD, LOW);
    digitalWrite(RIGHT_BACKWARD, HIGH);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 175);
    analogWrite(PWMB, 175);
    delay(200);
    }
    else if (value_ProxR > value_ProxL){
      digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(LEFT_BACKWARD, HIGH);
    analogWrite(PWMA, 175);
    analogWrite(PWMB, 175);
    delay(200);
    }
    else{
      digitalWrite(RIGHT_FORWARD, LOW);
    digitalWrite(RIGHT_BACKWARD, HIGH);
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(LEFT_BACKWARD, HIGH);
    analogWrite(PWMA, 100);
    analogWrite(PWMB, 100);
    delay(100);
    }
    if(value_ProxR > 950 || value_ProxL > 950){
    /*digitalWrite(RIGHT_FORWARD, LOW);
    digitalWrite(RIGHT_BACKWARD, HIGH);
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(LEFT_BACKWARD, HIGH);
    analogWrite(PWMA, 150);
    analogWrite(PWMB, 150);
    delay(100);*/
    digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
    delay(200);
    if(value_ProxR < value_ProxL){
    digitalWrite(RIGHT_FORWARD, LOW);
    digitalWrite(RIGHT_BACKWARD, HIGH);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 175);
    analogWrite(PWMB, 175);
    delay(200);
    }
    else if (value_ProxR > value_ProxL){
      digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(LEFT_BACKWARD, HIGH);
    analogWrite(PWMA, 175);
    analogWrite(PWMB, 175);
    delay(200);
    }
    else{
      digitalWrite(RIGHT_FORWARD, LOW);
    digitalWrite(RIGHT_BACKWARD, HIGH);
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(LEFT_BACKWARD, HIGH);
    analogWrite(PWMA, 100);
    analogWrite(PWMB, 100);
    delay(100);
    }
    }
  
  }


}
