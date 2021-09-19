#define s_l A3 //left sensor
#define s_c A0 //centar sensor
#define s_r A1 //right sensor
int left=0,right=0,center=0; //to store the readings

void setup() {
  // put your setup code here, to run once:
pinMode(s_l,INPUT);
pinMode(s_c,INPUT);
pinMode(s_r,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
left=digitalRead(s_l);
right=digitalRead(s_r);
center=digitalRead(s_c);

if (left==0&&right==0&&center==1)
{
  moveForward(); }
  
if (left==0&&right==0&&center==0)
{
  moveBackward(); } 

else if (left==1&&center==0&&right==0)
{
  rotate90left();
}

else if (left==0&&center==0&&right==1)
{
  rotate90right();
}
}

void moveForward()
{}
void moveBackward()
{}
void rotate90right()
{}
void rotate90left()
{}
