int l1 = 13,l2=12,l3=11;


void setup() {
  // put your setup code here, to run once:
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(l1,HIGH);
  digitalWrite(l2,HIGH);
  digitalWrite(l3,HIGH);
  delay(1000);
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(l3,LOW);
  delay(1000);
}
