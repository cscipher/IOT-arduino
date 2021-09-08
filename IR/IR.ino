int IRsensor=13;
int led=12;
int Status;


void setup() {
  // put your setup code here, to run once:
pinMode(IRsensor,INPUT);
pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led,HIGH);
Status = digitalRead(IRsensor);
if(Status==1){
  digitalWrite(led,LOW);
  delay(300);
}
}
