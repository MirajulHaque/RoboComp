
// WIN22.SEEE-106.1.1 
// Code By Md Mirajul Haque Miraj
// Group: UGV Hunter

int r1, r2, r3, r4;


void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  
  pinMode(2, OUTPUT);  // left wheel
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);  //right wheel
  pinMode(5, OUTPUT);

  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  // distance messurement 
  pinMode(A5, OUTPUT);
  pinMode(A6, INPUT);

  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  
}

void loop(){
//  checkRun();
//  forward();
//  left();
//  right();
//  sensorCheck();
  followLine();
//back();
}


void followLine(){
  r1 = digitalRead(A1);
//  r2 = digitalRead(A2);
  r3 = digitalRead(A3);
//  r4 = digitalRead(A4);

  if(r1==1 && r3==0){
    right();
  }
  else if(r1==0 && r3==1){
    left();
  }
  else if(r1==1 && r3==1){
    stop_car();
    delay(100);
    stop_car();
    delay(2900);
    if(r1==1 && r3==1){
      forward();
      delay(500);
    }
    forward();
  }
  else if(r1==0 && r3==0){
    forward();
  }
  else{
    forward();
  }

  
}

void sensorCheck(){
  r1 = digitalRead(A1);
  r2 = digitalRead(A2);
  r3 = digitalRead(A3);
  r4 = digitalRead(A4);

  Serial.print("r1=");
  Serial.println(r1);
  delay(1000);

//  Serial.pri
//print("r2=");
//  Serial.println(r2);
//  delay(1000);

  Serial.print("r3=");
  Serial.println(r3);
  delay(1000);

//  Serial.print("r4=");
//  Serial.println(r4);
}


void checkRun(){
  forward();
  delay(4000);
  stop_car();
  delay(1000);
  left();
  delay(3000);
  stop_car();
  delay(1000);
  right();
  delay(3000);
  stop_car();
  delay(1000);
  back();
  delay(5000);
  stop_car();
  delay(1000);
}

void forward(){
//  digitalWrite(2, HIGH);
  analogWrite(2, 60);
  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
  analogWrite(4, 69);
  digitalWrite(5,LOW);
  
}

void left(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
  analogWrite(4,65);
  digitalWrite(5,LOW);
}


void right(){
//  digitalWrite(2,LOW);
  analogWrite(2, 60);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}

void stop_car(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}

void back(){
  digitalWrite(2,LOW);
//  digitalWrite(3,HIGH);
  analogWrite(3, 100);
  digitalWrite(4,LOW);
//  digitalWrite(5,HIGH);
  analogWrite(5, 100);
}
