#define LED 10
#define btn 4 

int btn_state = 0; 
int flag = 0; 

long lastDebounceTime = 0; // the last time the output pin was toggled 
long debounceDelay = 200; // the debounce time 

void setup() 
{  
   pinMode(LED, OUTPUT); 
   pinMode(btn, INPUT); 
   digitalWrite(LED, LOW); 
} 

void loop() 
{ 
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
}
