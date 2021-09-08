int r1=2,r2=3;


void setup() {
  // put your setup code here, to run once:
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);

  //Turning motor off
//  digitalWrite(r1,HIGH);
//  digitalWrite(r2,HIGH);

  Serial.begin(9600);
  Serial.println("Running motor with 2 relays");
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

//    digitalWrite(r1,HIGH);
//    digitalWrite(r2,HIGH);
//    delay(2000);
    digitalWrite(r1,LOW);
    digitalWrite(r2,LOW);
    delay(2000);
//  // Running in CW direction
//  Serial.println("CW rotation");
//  digitalWrite(r1,HIGH);
//  digitalWrite(r2,LOW);
//  delay(3000);
//  
//  // Stopping
//  Serial.println("Stopped");
//  digitalWrite(r1,HIGH);
//  digitalWrite(r2,HIGH);
//  delay(1500);
//  
//  // Running in CCW direction
//  Serial.println("CCW rotation");
//  digitalWrite(r1,LOW);
//  digitalWrite(r2,HIGH);
//  delay(3000);

}
