#include <Timer.h>
Timer timer;

#define green_led 13
#define white_led 11
#define red_led   9
#define push_button 7

void setup() {
  pinMode(green_led  ,OUTPUT); // set LED pin to OUTPUT
  pinMode(white_led  ,OUTPUT); // set LED pin to OUTPUT
  pinMode(red_led    ,OUTPUT); // set LED pin to OUTPUT
  pinMode(push_button, INPUT); // set LED pin to OUTPUT


if (digitalRead(push_button==HIGH))
 {timer.after(0  , turn_on_red_led);             //turn on the red led for 15 minutes
  timer.every(120000, flash_green );             //flash the green led evey 2 minutes for 5 seconds
  timer.after(480000, flash_white);     //flash the white led after 8 minutes for 10 seconds
  timer.after(900000, flash_white);    //flash the white led after 15 minutes for 10 seconds
 }
}

void loop() {
  timer.update(); // tick the timer
}


void turn_on_red_led()                    //control the red led
{                                      
  digitalWrite(red_led,HIGH);             //turned on for 15min
  delay(900000);
  digitalWrite(red_led,LOW);              //turned off after 15min
  delay(500);   
  }




void flash_green()                        //control the green led 
{
  digitalWrite(green_led,HIGH);           //flash for 5 sec
  delay(5000);
  digitalWrite(green_led,LOW);
  delay(5000);   
  }

void flash_white()                       //control the white led
{
  digitalWrite(white_led,HIGH);           //flash every 10sec
  delay(10000);
  digitalWrite(white_led,LOW);
  delay(10000);   
  }
