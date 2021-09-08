int triggerTop=6,echoTop=7,triggerFront=5,echoFront=4;
int led1=10; // empty
int led2=9; // half
int led3=11; // full
long tT, distanceT, tF, distanceF;
int r1=2,r2=3;


void setup() {
  // put your setup code here, to run once:
  pinMode(triggerTop, OUTPUT);
  pinMode(echoTop, INPUT);
  pinMode(triggerFront,OUTPUT);
  pinMode(echoFront,INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
//   Initially turning motor off
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  
  Serial.begin(9600);
  Serial.println("Testing!");
  
}

long getDist(long pin){
  long t = pulseIn(pin,HIGH);
  long d=0;
  d = t * 34400/1000000;
  return d;
}


long Sonar(int echo, int trigger){
  digitalWrite(trigger,LOW);
  delayMicroseconds(10);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);

  long d = getDist(echo);
  d = d/2;
  
  Serial.print("Distance:");
  Serial.println(d);
  return d;
}


void loop() {
  distanceT = Sonar(echoTop,triggerTop);
  distanceF = Sonar(echoFront,triggerFront);
  
  if(distanceT>=33){
    // empty
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  } else if(distanceT<33 && distanceT>=15){
    //half
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
  } else {
    //full
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
  }

    // Motor logic
    if(distanceF<=30){
      digitalWrite(r1,HIGH);
      digitalWrite(r2,LOW);
      delay(100);
    } else {
      digitalWrite(r1,LOW);
      digitalWrite(r2,HIGH);
      delay(100);
    }

    delay(1000);

  
}
