float metalDetected;
int gripper_1 = 24;
int gripper_2 = 25;
int updown_motor_1 = 22;
int updown_motor_2 = 23;
int pump_2 = 8;
int pump_2_2 =9;
int monitoring;
int monitoring_1;
int monitoring_2;
int metalDetection_2 = 7;
int metalDetection = 2;
int metalDetection_1 = 6;
int conveyor_motorPin = 3;
int conveyor_motorPin_1 = 4;
int solenoid = 5;
void setup()
{
Serial.begin(9600);
pinMode(conveyor_motorPin_1, OUTPUT);
pinMode(conveyor_motorPin, OUTPUT);

pinMode(pump_2_2, OUTPUT);
pinMode(solenoid, OUTPUT);
pinMode(pump_2, OUTPUT);
pinMode(gripper_1, OUTPUT);
pinMode(gripper_2, OUTPUT);
pinMode(updown_motor_1, OUTPUT);
pinMode(updown_motor_2, OUTPUT);
pinMode(metalDetection_1, INPUT);
pinMode(metalDetection_2, INPUT);
pinMode(metalDetection, INPUT);
}
void loop()
{
monitoring = digitalRead(metalDetection);
monitoring_1 = digitalRead(metalDetection_1);
monitoring_2 = digitalRead(metalDetection_2);

if (monitoring == HIGH)
{

digitalWrite(conveyor_motorPin , LOW);
digitalWrite(conveyor_motorPin_1 , LOW);
digitalWrite(solenoid, HIGH);
delay(35000);

digitalWrite(conveyor_motorPin , HIGH);
digitalWrite(conveyor_motorPin_1 , LOW);
digitalWrite(solenoid, LOW);
delay(2000);
}

if (monitoring_1 == HIGH )
{
digitalWrite(conveyor_motorPin , LOW);
digitalWrite(conveyor_motorPin_1 , LOW);
digitalWrite(pump_2 , HIGH);
pinMode(pump_2_2, LOW);
delay(2000);
digitalWrite(conveyor_motorPin , HIGH);
digitalWrite(conveyor_motorPin_1 , LOW);
digitalWrite(pump_2 , LOW);
pinMode(pump_2_2, LOW);
delay(2000);
}

if (monitoring_2 == HIGH)
{
digitalWrite(conveyor_motorPin , LOW);
digitalWrite(conveyor_motorPin_1 , LOW);

digitalWrite(updown_motor_1,HIGH);
digitalWrite(updown_motor_2,LOW);
delay(3000);
digitalWrite(updown_motor_1,LOW);
digitalWrite(updown_motor_2,LOW);
digitalWrite(conveyor_motorPin , LOW);
digitalWrite(conveyor_motorPin_1 , LOW);
digitalWrite(gripper_1,HIGH);
digitalWrite(gripper_2,LOW);
delay(5000);
digitalWrite(gripper_1,LOW);
digitalWrite(gripper_2,HIGH);
delay(5000);
digitalWrite(gripper_1,LOW);
digitalWrite(gripper_2,LOW);
digitalWrite(conveyor_motorPin , LOW);
digitalWrite(conveyor_motorPin_1 , LOW);
digitalWrite(updown_motor_1,LOW);
digitalWrite(updown_motor_2,HIGH);
delay(3200);
digitalWrite(updown_motor_1,LOW);
digitalWrite(updown_motor_2,LOW);
digitalWrite(conveyor_motorPin , HIGH);
digitalWrite(conveyor_motorPin_1 , LOW);

delay(2000);
}

if (monitoring_2 == LOW)
{
digitalWrite(gripper_1,LOW);
digitalWrite(gripper_2,LOW);
digitalWrite(updown_motor_1,LOW);
digitalWrite(updown_motor_2,LOW);
}
else
{
digitalWrite(solenoid, LOW);
digitalWrite(conveyor_motorPin , HIGH);
digitalWrite(conveyor_motorPin_1 , LOW);
}
}
