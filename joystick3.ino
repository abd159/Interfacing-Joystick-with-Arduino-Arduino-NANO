

#define joyX A0
#define joyY A1

int led1 = 11;
int led2 = 10;
int led3 = 9;
int led4 = 8;
int led5 = 7;

int button=2;
int buttonState = 0;
int buttonState1 = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(led5, OUTPUT);
  
  pinMode(button,INPUT);
  digitalWrite(button, HIGH);
  Serial.begin(9600);
}
 
void loop() {
 int xValue = analogRead(joyX);
 int yValue = analogRead(joyY);
 
  Serial.print(xValue);
  Serial.print("\t");
  Serial.println(yValue);
  
  buttonState = digitalRead(button);
  Serial.println(buttonState);
  if (xValue>=0 && yValue<=10)
  {
    digitalWrite(led2, HIGH);
  }
  else{digitalWrite(led2, LOW);}

  if (xValue<=10 && yValue>=500)
  {
    digitalWrite(led1, HIGH);
  }
  else{digitalWrite(led1, LOW);}

  if (xValue>=1020 && yValue>=500)
  {
    digitalWrite(led3, HIGH);
  }
  else{digitalWrite(led3, LOW);}

  if (xValue>=500 && yValue>=1020)
  {
    digitalWrite(led4, HIGH);
  }
  else{digitalWrite(led4, LOW);}

  if (xValue>=1020 && yValue>=1020)
  {
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  if (buttonState == LOW)
  {
    Serial.println("Switch = High");
    digitalWrite(led5, HIGH);
  }
  else{digitalWrite(led5, LOW);}
  buttonState1 = digitalRead(led5);
  Serial.println(buttonState1);
  delay(50);
}
