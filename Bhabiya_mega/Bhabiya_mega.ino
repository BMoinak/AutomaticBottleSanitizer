int trig = 13;
int echo = 12;
int pump_1 = 10;
int pump_1_2 = 11;
#define DISTANCE 10
void setup()
{
Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo,INPUT);
pinMode(pump_1, OUTPUT);
pinMode(pump_1_2, OUTPUT);
}
void loop() {
long duration1, distance1,duration2, distance2;
digitalWrite(trig , LOW);
//digitalWrite(trig2 , LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
//digitalWrite(trig2, HIGH);
delayMicroseconds(10); // Added this line
digitalWrite(trig, LOW);
//digitalWrite(trig2, LOW);


duration1 = pulseIn(echo, HIGH);
distance1 = (duration1/2) / 29.1;
Serial.print("1. ");Serial.println(distance1);
// put your main code here, to run repeatedly:
if (distance1 < DISTANCE)
{
digitalWrite(pump_1 , LOW);
digitalWrite(pump_1_2 , LOW);
//Serial.println(&quot;MOTOR OFF&quot;);
//delay(1000);
}
if (distance1 > DISTANCE)
{
digitalWrite(pump_1 , HIGH);
digitalWrite(pump_1_2 , LOW);
}
}
