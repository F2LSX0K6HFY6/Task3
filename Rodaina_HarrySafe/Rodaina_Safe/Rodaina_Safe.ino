#define signal_a1 4    //for first encoder
#define signal_b1 5 
   
#define signal_a2 6    //for second encoder
#define signal_b2 7   

#define signal_a3 8    //for third encoder
#define signal_b3 9 
   
#define led 11         //green led  

int count1=0;         //count of the pulses of first encoder
int degree1=0;        //degree of the rotation of the first encoder
int count2=0;         //count of the pulses of second encoder
int degree2=0;        //degree of the rotation of the second encoder
int count3=0;         //count of the pulses of third encoder
int degree3=0;        //degree of the rotation of the third encoder

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(signal_a1,INPUT_PULLUP);     //pinmode for first encoder
pinMode(signal_b1,INPUT_PULLUP);     
pinMode(signal_a2,INPUT_PULLUP);     //pinmode for second encoder
pinMode(signal_b2,INPUT_PULLUP);
pinMode(signal_a3,INPUT_PULLUP);     //pinmode for third encoder
pinMode(signal_b3,INPUT_PULLUP);
pinMode(led     ,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
// attachInterrupt(digitalPinToInterrupt(signal_a),ISR_A,CHANGE);
 //attachInterrupt(digitalPinToInterrupt(signal_b),ISR_B,CHANGE);
  ISR_A1(); //calling the function to calculate the degree of the first encoder
  ISR_A2(); //calling the function to calculate the degree of the second encoder
  ISR_A3(); //calling the function to calculate the degree of the third encoder
}

void ISR_A1 ()
{
 if (digitalRead(signal_a1 != signal_b1)) //check that the signal is cw or not so it will increament the counter or drcrement it
   {count1++;
   degree1=(count1/512)*360;  //degree=count/ppr *360
    if (degree1==37)           //if encoder1 degree==37 will turn on the green led  
    {
   digitalWrite(led,HIGH);
   delay(1000);
   digitalWrite(led,LOW);
   delay(500);
    }
   }
 else 
 {count1--;     //if the direction is opposit to the abone will decrement the counter
  degree1=(count1/512)*360;
    if (degree1==37)
    {
   digitalWrite(led,HIGH);
   delay(1000);
   digitalWrite(led,LOW);
   delay(500);
    }
  }
  }

void ISR_A2 ()
{
 if (digitalRead(signal_a2 != signal_b2))//check that the signal is cw or not so it will increament the counter or drcrement it
   {count2++;
   degree2=(count1/512)*360;  //degree=count/ppr *360
    if (degree2==10)         //if encoder1 degree==10 will turn on the green led  
    {
   digitalWrite(led,HIGH);
   delay(1000);
   digitalWrite(led,LOW);
   delay(500);
    }
   }
 else 
 {count2--;
  degree2=(count1/512)*360;
    if (degree2==10)
    {
   digitalWrite(led,HIGH);
   delay(1000);
   digitalWrite(led,LOW);
   delay(500);
    }
  }
  }

void ISR_A3 ()
{
 if (digitalRead(signal_a3 != signal_b3))//check that the signal is cw or not so it will increament the counter or drcrement it
   {count3++;
   degree3=(count1/512)*360;   //degree=count/ppr *360
    if (degree2==54)           //if encoder1 degree==54 will turn on the green led  
    {
   digitalWrite(led,HIGH);
   delay(1000);
   digitalWrite(led,LOW);
   delay(500);
    }
   }
 else 
 {count3--;
  degree3=(count1/512)*360;
    if (degree2==54)
    {
   digitalWrite(led,HIGH);
   delay(1000);
   digitalWrite(led,LOW);
   delay(500);
    }
  }
  }
