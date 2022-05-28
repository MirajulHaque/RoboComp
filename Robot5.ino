

// WIN22.SEEE-106.1.1 
// Code By Md Mirajul Haque Miraj
// Group: UGV Hunter

int r1, r2, r3, r4;

char b;
float dr, df, dl, tr, tf, tl;

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

//  // distance messurement 
//  pinMode(A5, OUTPUT); //right ultra sonic
//  pinMode(A6, INPUT);
//
//  pinMode(A7, OUTPUT); //front ultra sonic
//  pinMode(A8, INPUT);
//
//  pinMode(A9, OUTPUT); //left ultra sonic
//  pinMode(A10, INPUT);

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
//  bluetooth_control();
//  back();
//  checkDistance();
//  distance();
}

void distance(){
  digitalWrite(A5, HIGH);
  delay(10);
  digitalWrite(A5, LOW);
  tr = pulseIn(A6, HIGH);
  df = 0.0343*(tr/2);
  Serial.println(dr);

//  digitalWrite(A7, HIGH);
//  delay(10);
//  digitalWrite(A7, LOW);
//  tf = pulseIn(A8, HIGH);
//  df = 0.0343*(tf/2);
//  Serial.println(df);
//
//  digitalWrite(A9, HIGH);
//  delay(10);
//  digitalWrite(A9, LOW);
//  tl = pulseIn(A10, HIGH);
//  dl = 0.0343*(tl/2);
//  Serial.println(dl);

//  if(df>20){
//    forward();
//  }
//  if(df=<10 && df){
//    right();
//    delay(100);
//  }
//  if(df<25){
//    left();
//  }
//  if(df<10){
//    back();
//  }

//  if((dr<=20&&dr>15) && df>20 && dl<=20){
//    forward();
//  }
//  else if(dr<=15 && df>20 && dl<=20){
//    left();
//  }
//  else if(dr>20 && df<=20 && dl<=20){
//    right();
//  }
//  else if(dr<=20 && df<=20 && dl>20){
//    left();
//  }
//  else if(dr<=20 && df<=20 && dl<=20){
//    back();
//  }
//  else if(dr>20 && df<=20 && dl>20){
//    left();
//  }
//  else if(dr>20 && df>20 && dl>20){
//    forward();
//  }
//  else{
//    
//  }
//  


  
}

void checkDistance(){
  digitalWrite(A5, HIGH);
  delay(10);
  digitalWrite(A5, LOW);
  tr = pulseIn(A6, HIGH);
  dr = 0.0343*(tr/2);
  Serial.println(dr);
  delay(300);

//  digitalWrite(A7, HIGH);
//  delay(10);
//  digitalWrite(A7, LOW);
//  tf = pulseIn(A8, HIGH);
//  df = 0.0343*(tf/2);
//  Serial.println(df);
//  delay(300);
//
//  digitalWrite(A9, HIGH);
//  delay(10);
//  digitalWrite(A9, LOW);
//  tl = pulseIn(A10, HIGH);
//  dl = 0.0343*(tl/2);
//  Serial.println(dl);
//  delay(300);
  
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
    forward();
    delay(500);
  }
  else if(r1==0 && r3==0){
    forward();
  }
  else{
//    forward();
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

//  Serial.print("r2=");
//  Serial.println(r2);
//  delay(1000);

  Serial.print("r3=");
  Serial.println(r3);
  delay(1000);

//  Serial.print("r4=");
//  Serial.println(r4);
}

void bluetooth_control(){
  if(Serial1.available()){
    b = Serial1.read();
    Serial.println(b);

    if(b=='F'){
      forward();
    }
    else if(b=='B'){
      back();
    }
    else if(b=='L'){
      left();
    }
    else if(b=='R'){
      right();
    }
    else if(b=='G'){
      forward_left();
    }
    else if(b=='I'){
      forward_right();
    }
    else if(b=='H'){
      backward_left();
    }
    else if(b=='J'){
      backward_right();
    }
    else{
      stop_car();
    }
  }
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
  analogWrite(2, 66);
  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
  analogWrite(4, 90);
  digitalWrite(5,LOW);
  
}

void forward_right(){
//digitalWrite(2, HIGH);
analogWrite(2, 209);
digitalWrite(3, LOW);
//digitalWrite(4, HIGH);
analogWrite(4, 220);
digitalWrite(5, LOW);
  
}

void forward_left(){
//digitalWrite(2, HIGH);
analogWrite(2, 195);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
//analogWrite(4, 190);
digitalWrite(5, LOW);
  
}


void left(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
  analogWrite(4,102);
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
  analogWrite(3, 80);
  digitalWrite(4,LOW);
//  digitalWrite(5,HIGH);
  analogWrite(5, 80);
}

void backward_left(){
digitalWrite(2, LOW);
//digitalWrite(3, HIGH);
analogWrite(3, 162);
digitalWrite(4, LOW);
//digitalWrite(5, HIGH);
analogWrite(5, 180);
}

void backward_right(){
digitalWrite(2, LOW);
//digitalWrite(3, HIGH);
analogWrite(3, 140);
digitalWrite(4, LOW);
//digitalWrite(5, HIGH);
analogWrite(5, 200);

}
