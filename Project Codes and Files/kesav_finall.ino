/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).


//#define motor D0
int sensorPin = A0;
int sensorValue = 0; 
char auth[] = "a17474f3acff4b8189ba7c701297feb7";//"fd91870cab2340c3ba5f0cab4f07f712"; //

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "a";
char pass[] = "12345678";
int wifi = D4;
void setup()
{
  // Debug console  
  Serial.begin(9600);
  
  pinMode(D3,OUTPUT); // led 1
  pinMode(D4,OUTPUT); // led 1
  pinMode(D8,OUTPUT); // led 2

  pinMode(D5,INPUT); // led 1
  pinMode(D6,INPUT); // led 2


digitalWrite(D4,HIGH);

  Blynk.begin(auth, ssid, pass);
digitalWrite(D4,LOW);
}

int ir1,ir2;
int light1,light2;
int total_time;
void loop()
{
  ir1 = digitalRead(D5);
  ir2 = digitalRead(D6);

 sensorValue = analogRead(sensorPin); // read the value from the sensor
  Serial.println("Sensor : "+ String(sensorValue));

  Serial.println("IR  1: "+ String(ir1));
 Serial.println("IR  2: "+ String(ir2));
 
  if(ir1==1 && ir2==0)
  {
 ir1 = digitalRead(D5);
  ir2 = digitalRead(D6);

  analogWrite(D3,sensorValue);
  analogWrite(D8,LOW);
  delay(2000);
    digitalWrite(D3,LOW);
  analogWrite(D8,LOW);
    
 light1++;

     }

  else if(ir2==1 && ir1==0)
  {

 ir1 = digitalRead(D5);
  ir2 = digitalRead(D6);
   

   digitalWrite(D3,LOW);
   
  analogWrite(D8,sensorValue);
  light2++;
  
   delay(2000);
  digitalWrite(D3,LOW);
  analogWrite(D8,LOW);
    
    }



else if(ir2==1 && ir2==1)
    {

  ir1 = digitalRead(D5);
  ir2 = digitalRead(D6);

   digitalWrite(D3,sensorValue);
  analogWrite(D8,sensorValue);
delay(2000);
     light1++;
 light2++;
   digitalWrite(D3,LOW);
  analogWrite(D8,LOW);
    

    }
    else
    {
 
    }


  

  

  Blynk.virtualWrite(V4,light1);
    Blynk.virtualWrite(V5,light2);
  
  Blynk.run();
 
} 
