#include <Nextion.h>

NexButton b0 = NexButton(0, 2, "b0");  // Button added
NexVariable va0 = NexVariable(0, 1, "va0");  // Variable added so we can read it



NexTouch *nex_listen_list[] = 
{
  &b0,  // Button added
  NULL  // String terminated
};

void b0PushCallback(void *ptr)  // Press event for button b0
{
  uint32_t number4 = 0;  // Create variable to store value we are going to get
  va0.getValue(&number4);    // Read variable (inside the display) called vah and stored on variable number4
  Serial.println(number4);
  if(number4==1)
  {
    digitalWrite(13,HIGH);
  }

   else
  {
    digitalWrite(13,LOW);
  }  
}  







void setup() 
{
  Serial.begin(9600);
 
  pinMode(13,OUTPUT);
  b0.attachPush(b0PushCallback);  
}

void loop() {
  
 delay(10);  
 nexLoop(nex_listen_list); 

}
