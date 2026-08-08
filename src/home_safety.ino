void setup() {
  Serial.begin(9600);
  //gas sensor input
  pinMode(A0, INPUT);
  pinMode(2, INPUT);
  //water sensor input
  pinMode(A1, INPUT);
  //temperature sensor input
  pinMode(A2, INPUT);
  //motion sensor
  pinMode(3, INPUT);


  //gas sensor output from low to high
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  //temperature sensor output from low to high
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //water  sensor output from low to high
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  //motion sensor output 
  pinMode(13, OUTPUT);
}

void loop() {
  
  int watersensor = analogRead(A1);
  int gassensor = analogRead(A0);
  int motionsensor = digitalRead(3);
  int temperaturesensor = analogRead(A2);
  Serial.print("Data of motion sensor:");
  Serial.println(motionsensor);
  Serial.print("Data of gassensor:");
  Serial.println(gassensor);
  Serial.print("Data of watersensor:");
  Serial.println(watersensor);
  Serial.print("Data of temperaturesensor:");
  Serial.println(temperaturesensor);
  delay(1000);
  
  if (gassensor<=874){
    //this 874 represents household gas used in Bangladesh's
     //safe 200 safe ppm range as 200 is
      //represented by sensors 874 range so it was used.
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6,LOW);
  }
  else if (gassensor>874 && gassensor<=961){
    //this 874 to 961 represents household gas used in Bangladesh's
     //safe 200 to moderate danger 2000 ppm is 
      //represented by sensors 874 to 961range so it was used.
    digitalWrite(4, LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
  }
  else {
    // above 2000 is considered as dangerous. 
    //This section will represent that
    digitalWrite(4, LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
  }
  if(temperaturesensor>=683){
    //this LED will be connected to AC off indicator
    //value was according to the sensor when it was
    // 10 degree 
    digitalWrite(7, HIGH);  
    digitalWrite(8, LOW);
    digitalWrite(9,LOW);
  }
  else if (temperaturesensor<683 && temperaturesensor>=455){
    //this LED will be connected to 
    //moderate temperature "NO NEED FOR CHANGE"
    //value was according to the sensor when it was
    // 10 degree to 30 degree
    digitalWrite(7, LOW);  
    digitalWrite(8, HIGH);
    digitalWrite(9,LOW);
  }
  else{ 
    // his LED will be connected to AC on indicator
    //value was according to the sensor when it was
    // above 30 degree 
    digitalWrite(7, LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
  }
  if (watersensor==0){
    //if water level is that the point where the potentio meter is 
    //exactly at the bottom then this segment will signal
    //Water level: SAFE

    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12,LOW);
  }
  else if (watersensor>0 && watersensor<1023){
    //if water level is that the point where the potentio meter is 
    //exactly at the middle then this segment will signal
    //Water level: MODERATE DANGER
    
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12,LOW);
  }
  else{
    //if water level is that the point where the potentio meter is 
    //exactly at the top then this segment will signal
    //Water level: DANGER
    
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12,HIGH);
  }

  if(motionsensor==1){
    //if it detects any motion than this part will be activated
    digitalWrite(13, HIGH); 
    delay(1000); 
    digitalWrite(13, LOW);
    delay(100); 
  }
}
  




