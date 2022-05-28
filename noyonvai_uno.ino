int r1, r2, r3, r4;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);  // left wheel
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);  //right wheel
  pinMode(5, OUTPUT);

  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  forward();

}

void followLine(){
  r1 = digitalRead(A1);
//  r2 = digitalRead(A2);
  r3 = digitalRead(A2);
//  r4 = digitalRead(A4);

  if(r1==1 && r3==0){
    right();
  }
  else if(r1==0 && r3==1){
    left();
  }
//  else if(r1==1 && r3==1){
//    stop_car();
//    delay(100);
//    stop_car();
//    delay(2900);
//    forward();
//    delay(500);
//  }
  else{
    forward();
  }

  
}

void forward(){
//  digitalWrite(2, HIGH);
  analogWrite(2, 100);
  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
  analogWrite(4, 100);
  digitalWrite(5,LOW);
  
}

void left(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
  analogWrite(4,100);
  digitalWrite(5,LOW);
}


void right(){
//  digitalWrite(2,LOW);
  analogWrite(2, 100);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}
