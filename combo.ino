#define LED 10
#define btn 4 

int btn_state = 0; 
int flag = 0; 
int trigPin = 2;
int echoPin = 3;
int led = 6;
int buzzer = 7;
long lastDebounceTime = 0; // the last time the output pin was toggled 
long debounceDelay = 200; // the debounce time 


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzzer, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
pinMode(LED, OUTPUT); 
pinMode(btn, INPUT); 
digitalWrite(LED, LOW); 
}

void loop() {
  // put your main code here, to run repeatedly:
//error byn code starts
   btn_state = digitalRead(btn); 
   //Filters out the noise by setting a time buffer

   if ( (millis() - lastDebounceTime) > debounceDelay) 
   { 
     if(btn_state == HIGH) 
     { 
       if(flag == 0) 
       { 
          digitalWrite(LED, HIGH); 
          flag = 1; 
          lastDebounceTime = millis(); //Sets current time
        } 
       else if(flag == 1) 
       { 
         digitalWrite(LED, LOW); 
         flag = 0; 
         lastDebounceTime = millis(); //Sets current time
        } 
      } 
   }
   //------------------------------------------------
   long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/1)/29.1;
   duration=pulseIn(echoPin, LOW);
  Serial.print(distance);
  Serial.println("cm");
  delay(10);

 if((distance<=25))
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, LOW);
}
   else if(distance>25)
 {
     digitalWrite(buzzer, LOW);
     digitalWrite(led, HIGH);
}
}   
