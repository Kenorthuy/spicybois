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

int value_LineM = 0;
int value_LineR = 0;
int value_LineL = 0;
int value_ProxM = 0;
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
  value_LineM = analogRead(analogInput_zero);
  value_LineR = analogRead(analogInput_one);
  value_LineL = analogRead(analogInput_two);
  value_ProxM = analogRead(analogInput_three);
  //value_ProxR = analogRead(analogInput_four);
  //value_ProxL = analogRead(analogInput_five); //Reads all analog values

  /*if(value_ProxM > 800){
    digitalWrite(RIGHT_FORWARD, LOW);
    digitalWrite(RIGHT_BACKWARD, HIGH);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
  }*/

  if(value_LineM > 750 && value_LineR < 750 && value_LineL < 750){   // detect only middle line
    digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 150);
    analogWrite(PWMB, 150);
    
  }
  
  if(value_LineM > 750 && value_LineR > 750 && value_LineL > 750){  // detect highway
    digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 255);
    analogWrite(PWMB, 255);
    
  }

  if(value_LineM > 750 && value_LineR > 750 && value_LineL < 750){   // detect turn right
    digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 150);
    analogWrite(PWMB, 200);
    delay(50);
  }
  
  if(value_LineM < 750 && value_LineR > 750 && value_LineL < 750){   // correct course right side
    digitalWrite(RIGHT_FORWARD, LOW);
    digitalWrite(RIGHT_BACKWARD, HIGH);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 150);
    analogWrite(PWMB, 150);
    //delay(100);
  }

   if(value_LineM > 750 && value_LineR < 750 && value_LineL > 750){   // detect turn left
    digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 200);
    analogWrite(PWMB, 150);
    delay(50);
   }
   
    if(value_LineM < 750 && value_LineR < 750 && value_LineL > 750){   // correct course left side
    digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(LEFT_BACKWARD, HIGH);
    analogWrite(PWMA, 150);
    analogWrite(PWMB, 150);
    //delay(100);
    }

    if(value_LineM < 150 && value_LineR < 150 && value_LineL <150){   // detect none
    digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
    //delay(125);
    }

}
