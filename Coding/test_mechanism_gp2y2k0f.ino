#include <ZSharpIR.h>
#define ir A0
#define model 999
ZSharpIR ZSharpIR(ir, model);

void setup() {               
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  Serial.begin(115200);
}
int dis=0; float i=0,d=0.0,s=0.00;
boolean t=0;
void loop() {
  i++;
  d = map(i,0,1600,0,360); 
  dis=ZSharpIR.distance();
  if (d>=360){
    i=0;d=0;t=!t;
    digitalWrite(10,t);
  }
  digitalWrite(11, HIGH);
  delayMicroseconds(1000);         
  digitalWrite(11, LOW);
  delay(1);
  Serial.print(d);Serial.print(",");
  Serial.print(t);Serial.println(",");
}
