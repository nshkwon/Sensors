int sensorPin0 = A0; 
int sensorPin1 = A1; 
int sensorPin2 = A2;

int sensorValue=0;
int sensorValue1=0;
int sensorValue2=0;
int states[] = {0,0,0};


int states_save[]={0,0,0};

long states_sensing_time = millis() ;
long states_chage_time=millis() ;
long states_sensing_time1 = millis() ;
long states_chage_time1=millis() ;
long output_states_time0_1=millis();

int a=0;
int b=0;

long states_sensing_time_v1 = millis() ;
long states_chage_time_v1=millis() ;
long states_sensing_time1_v1 = millis() ;
long states_chage_time1_v1=millis() ;
long output_states_time0_1_v1=millis();

int a_v1=0;
int b_v1=0;


long states_sensing_time_v2 = millis() ;
long states_chage_time_v2=millis() ;
long states_sensing_time1_v2 = millis() ;
long states_chage_time1_v2=millis() ;
long output_states_time0_1_v2=millis();

int a_v2=0;
int b_v2=0;


long output_serial_time=millis();
long output_serial_time_start=millis();

int output_serial_cheak=0;



void setup() {
  // put your setup code here, to run once:
delay( 500 ) ;
Serial.begin(9600);
}

void loop() {

  sensing();
  if(states[0]==0)
  {
    if(a==0)
    {
       states_sensing_time=millis();
       a=1;
    }
    if(b==1)
    {
      states_chage_time1=millis()-states_sensing_time1;
      output_states_time0_1=states_chage_time1;  
      b=0;
    }
    
 
  }
  if(states[0]==1)
  {
    if(a==1)
    {
      states_chage_time=millis()-states_sensing_time;
      output_states_time0_1=states_chage_time;
       a=0;
    }
    if(b==0)
    {
      states_sensing_time1=millis();
      b=1;
    }

 
  }


  if(states[1]==0)
  {
    if(a_v1==0)
    {
       states_sensing_time_v1=millis();
       a_v1=1;
    }
    if(b_v1==1)
    {
      states_chage_time1_v1=millis()-states_sensing_time1_v1;
      output_states_time0_1_v1=states_chage_time1_v1;  
      b_v1=0;
    }
    
 
  }
  if(states[1]==1)
  {
    if(a_v1==1)
    {
      states_chage_time_v1=millis()-states_sensing_time_v1;
      output_states_time0_1_v1=states_chage_time_v1;
       a_v1=0;
    }
    if(b_v1==0)
    {
      states_sensing_time1_v1=millis();
      b_v1=1;
    }
  }


  if(states[2]==0)
  {
    if(a_v2==0)
    {
       states_sensing_time_v2=millis();
       a_v2=1;
    }
    if(b_v2==1)
    {
      states_chage_time1_v2=millis()-states_sensing_time1_v2;
      output_states_time0_1_v2=states_chage_time1_v2;  
      b_v2=0;
    }
    
 
  }
  if(states[2]==1)
  {
    if(a_v2==1)
    {
      states_chage_time_v2=millis()-states_sensing_time_v2;
      output_states_time0_1_v2=states_chage_time_v2;
       a_v2=0;
    }
    if(b_v2==0)
    {
      states_sensing_time1_v2=millis();
      b_v2=1;
    }
  }
/// serial output/////////////////////////
 
  if(output_serial_cheak==0)
{
  output_serial_time_start=millis();
  output_serial_cheak=1;
}
output_serial_time=millis()-output_serial_time_start;
if(output_serial_time>99)   //// 
{
  Serial.print(states[0]);
  Serial.print(",");
  Serial.print(output_states_time0_1);
  Serial.print(",");
  Serial.print(states[1]);
  Serial.print(",");
  Serial.print(output_states_time0_1_v1);
  Serial.print(",");
  Serial.print(states[2]);
  Serial.print(",");
  Serial.println(output_states_time0_1_v2);
  
  output_serial_cheak=0;
}

  

}

void sensing()
{
    int sensorValue_set_stable=0;
    int sensorValue_set_stable1=0;
    int sensorValue_set_stable2=0;
    
    int sensorValue_save_for_stable_calculation;
    int sensorValue_save_for_stable_calculation1;
    int sensorValue_save_for_stable_calculation2;
    for(int i=0; i<2;i++)
    {
      
      sensorValue = analogRead(sensorPin0);
      sensorValue1 = analogRead(sensorPin1);
      sensorValue2 = analogRead(sensorPin2);
    
      sensorValue_set_stable=sensorValue_set_stable+sensorValue;
      sensorValue_set_stable1=sensorValue_set_stable1+sensorValue1;
      sensorValue_set_stable2=sensorValue_set_stable2+sensorValue2;
    }
    
    
      sensorValue_save_for_stable_calculation=sensorValue_set_stable/2;
      sensorValue_save_for_stable_calculation1=sensorValue_set_stable1/2;
      sensorValue_save_for_stable_calculation2=sensorValue_set_stable2/2;
    
    
    //Serial.println(sensorValue);
    if(sensorValue_save_for_stable_calculation2>80)states[2]=1;
    if(sensorValue_save_for_stable_calculation2<50)states[2]=0;
    if(sensorValue_save_for_stable_calculation1>35)states[1]=1;
    if(sensorValue_save_for_stable_calculation1<10)states[1]=0;
    if(sensorValue_save_for_stable_calculation>54)states[0]=1;
    if(sensorValue_save_for_stable_calculation<43)states[0]=0;

    delay( 100 ) ;


/*
Serial.print( states[0] );
Serial.print( "," );
Serial.print( states[1] );
Serial.print( "," );
Serial.println( states[2] );*/
  // put your main code here, to run repeatedly:
}
