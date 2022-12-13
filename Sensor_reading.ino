int sensorPin = A1; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}
int sensorValue=0;
void loop() {
  // put your main code here, to run repeatedly:
sensorValue = analogRead(sensorPin);


Serial.println(sensorValue);
delay(50);
}
//280~400
//74~