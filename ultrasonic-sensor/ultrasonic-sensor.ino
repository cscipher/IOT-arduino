#include <DHT_U.h>
#include <DHT.h>


int triggerTop=6,echoTop=7,triggerFront=5,echoFront=4;
int led1=10; // empty
int led2=9; // half
int led3=8; // full
int led4=12;//fire
int led5=13;//pollution
long tT, distanceT, tF, distanceF;
int r1=2,r2=3;
int dhtPin = 11;
float temp=0, hum=0;
int smokeA0 = A1;

DHT dht(dhtPin,DHT11);

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
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    
  //Initially turning motor off
    digitalWrite(r1,HIGH);
    digitalWrite(r2,HIGH);

    pinMode(smokeA0, INPUT);
    
    Serial.begin(9600);
    Serial.println("Testing!");
    dht.begin();
    
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

  temp = dht.readTemperature();
  hum = dht.readHumidity();
  
  Serial.print("temp:");
  Serial.println(temp);
  Serial.print("hum:");
  Serial.println(hum);

  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A1: ");
  Serial.println(analogSensor);
//  if(temp>20){
//    digitalWrite(led4,HIGH);
////    digitalWrite(led5,HIGH);
//  }
//  else{
//    digitalWrite(led4,LOW);
////    digitalWrite(led5,LOW);
//  }
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH);
    delay(200);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    delay(200);
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

    Serial.println("-----------------------------------------");

  
}
