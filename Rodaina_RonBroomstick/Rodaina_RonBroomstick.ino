#include <Wire.h>
const int MPU_address = 0x68; // I2C address of the MPU-6050. 
int16_t gyro_x, gyro_y, gyro_z; // variables for gyro 
char tmp_str[7]; // to convert the size of reg
#define led 13
char* convert_int16_to_str(int16_t i) { // converts int16 to string.
  sprintf(tmp_str, "%6d", i);
  return tmp_str;
}

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  Wire.begin();
  Wire.beginTransmission(MPU_address); // Begins a transmission to the I2C slave 
  Wire.write(0x6B); // set the address
  Wire.write(0); // set to zero (the value)
  Wire.endTransmission(true);
}
void loop() {
  Wire.beginTransmission(MPU_address);
  Wire.write(0x3B); // starting with register 0x3B 
  Wire.endTransmission(false); // indicate that the transmission is still exist
  Wire.requestFrom(MPU_address, 2*2, true); // request a total of 2*2=4 registers
  
 

  gyro_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x43 
  gyro_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x45 
  gyro_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x47 
  
 if ((convert_int16_to_str(gyro_x)||convert_int16_to_str(gyro_y))>60)//check that the pitch or roll angles exceeds 60 degrees
 {
  
    digitalWrite(led,HIGH);  //if the angel exceeds 60 degree so the led will turned on
    delay(1000);
    }
   else
   {
    digitalWrite(led,LOW); //if the angel doesn't exceed 60 degree so the led will turned off
    delay(1000);}
}
