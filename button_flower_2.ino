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

void setup() 
{ 
   pinMode(LED, OUTPUT); 
   pinMode(btn, INPUT); 
   pinMode(buzzer, OUTPUT);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(led, OUTPUT);
   digitalWrite(LED, LOW);
   Serial.begin(9600);
  // put your setup code here, to run once:

}
 
 

void loop() 
{ 
   btn_state = digitalRead(btn); 
   //Filters out the noise by setting a time buffer

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

   if ( (millis() - lastDebounceTime) > debounceDelay) 
   { 
     if(btn_state == HIGH) 
     { 
        if((distance<=25))
          {
             digitalWrite(buzzer, HIGH);
             digitalWrite(led, LOW);
             
             if(flag == 0) 
               { 
                 digitalWrite(LED, HIGH); 
                  flag = 1; 
                   lastDebounceTime = millis(); //Sets current time

                      if((distance<=25))
                        {
                            digitalWrite(buzzer, HIGH);
                            digitalWrite(led, LOW);

       } 
               }
       else if(flag == 1) 
       { 
         digitalWrite(LED, LOW); 
         flag = 0; 
         lastDebounceTime = millis(); //Sets current time
       }
         else if(distance>25)
         {
           digitalWrite(buzzer, LOW);
           digitalWrite(led, HIGH);
         } 
       }
      } 
    } 
}
