#define LED 10 //Declared pin 10 as LED
#define btn 4 //Declared pin 4 as btn

int btn_state = 0; //Declared variable to store state (Low by default)
int flag = 0; //Declared variable flag to store switch state

void setup() 
{
  pinMode(LED, OUTPUT); //Set LED as output
  pinMode(btn, INPUT); //Set btn as input
  digitalWrite(LED, LOW); //Sets LED LOW by default
}

void loop() 
{
  btn_state = digitalRead(btn); //Store btn state (HIGH/LOW)in variable
  if(btn_state == HIGH)//If btn is pressed
  {
    if(flag == 0) //Check if flag is 0
    {
      digitalWrite(LED, HIGH); //Turn LED on
      flag = 1; //Set flag to 1
    }
    else if(flag == 1) //If flag is 1
    {
      digitalWrite(LED, LOW); //Turn LED off
      flag = 0; //Set flag to 0
    }
  }
}
