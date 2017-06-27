int brightness = 0;
int delayDuration = 30; 
int fadeAmount = 5;
String Str="";
int count = 0;
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(11,OUTPUT);
}

void loop(){
  if (Serial.available())
  {  
   Str="";
   delay(1);
   while(Serial.available())
    {
      Str+=(char)Serial.read(); 
    }
    Serial.println(Str); // send the data back in a new line so that it is not all one long line
  }
  
 Serial.println(Str[0]);
 if(Str[0]=='a'){
  analogWrite(3, brightness);
  analogWrite(11, 0);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount ;
  }
  delay(delayDuration);
    
 }  
 if(Str[0]=='b'){
  analogWrite(3,0);
  analogWrite(11,brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount ;
  }
  delay(delayDuration);
  }  
  if(Str[0]='c'){
  analogWrite(3,0);
  analogWrite(11,0);
  }
}
