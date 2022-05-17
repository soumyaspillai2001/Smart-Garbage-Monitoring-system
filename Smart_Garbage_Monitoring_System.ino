
#include <Servo.h>

#define IRsensorDryBin 11
#define IRsensorWetBin 4
#define TableIRsensor 10 
#define servopin 9
#define moisture A0
#define buzzer 13  
   
// defines variables

int TableIRvalue = 0;
int DryBinIRvalue = 0;
int WetBinIRvalue = 0;
int MoistureValue = 0; 
int pos = 0;    // variable to store the servo position  


Servo myservo;  // create servo object to control a servo

void setup() {
  // put your setup code here, to run once:

 pinMode(IRsensorWetBin, INPUT); 
 pinMode(IRsensorDryBin, INPUT);
 pinMode(TableIRsensor, INPUT);
 pinMode(moisture, INPUT);
 pinMode(buzzer, OUTPUT);
 
 myservo.attach(servopin);  // attaches the servo on pin 9 to the servo object
 Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}

void loop() {
  // put your main code here, to run repeatedly:

  myservo.write(90);
  TableIRvalue = digitalRead(TableIRsensor);
  delay(2000);
  
   if(TableIRvalue == 0)
  {
    //Serial.println("Object Detected!");
    MoistureValue = analogRead(moisture);
  // Serial.println(MoistureValue);
    if(MoistureValue > 900)
    {
      //Serial.println("DRY WASTE");
      myservo.write(55);
      delay(3000); 
      myservo.write(90);

     
    }
    else{  
      //Serial.println("WET WASTE");
      myservo.write(110);
      delay(3000);
      myservo.write(90);

     
      }
   }
   
   else{
    //Serial.println("No Object Detected!"); 
      }

       DryBinIRvalue = digitalRead(IRsensorDryBin);
          if(DryBinIRvalue == 1) 
       {
          Serial.println("Dry Bin is Full!");
          digitalWrite(buzzer,HIGH);
          delay(4000);
          digitalWrite(buzzer,LOW);
       }

 WetBinIRvalue = digitalRead(IRsensorWetBin);
        if(WetBinIRvalue == 1)
       {
          Serial.println("Wet Bin is Full!"); 
          digitalWrite(buzzer,HIGH);
          delay(4000);
          digitalWrite(buzzer,LOW);
       }

}

 
