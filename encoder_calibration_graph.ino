const int sensorPins[]={2,3,4};
int states[] = {0,0,0};
int statesAbs = 0;
int sensorPin0 = A0; 
int sensorPin1 = A1; 
int sensorPin2 = A2;

int sensorValue=0;
int sensorValue1=0;
int sensorValue2=0;

void setup() {
  // put your setup code here, to run once:
  delay( 500 ) ;
  Serial.begin(9600);
//Initialize pins and turn on pull-up resistors
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin0);
sensorValue1 = analogRead(sensorPin1);
sensorValue2 = analogRead(sensorPin2);

//Serial.println(sensorValue);
if(sensorValue2>80)states[2]=1;
if(sensorValue2<50)states[2]=0;
if(sensorValue1>35)states[1]=1;
if(sensorValue1<10)states[1]=0;
if(sensorValue>54)states[0]=1;
if(sensorValue<43)states[0]=0;
Serial.print(states[0]);
Serial.print(',');
Serial.print(states[1]);
Serial.print(',');
Serial.println(states[2]);



  delay( 100 ) ;
}