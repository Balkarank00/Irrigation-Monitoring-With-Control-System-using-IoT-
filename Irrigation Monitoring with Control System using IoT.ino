/* 
   -- New project -- 
    
   This source code of graphical user interface  
   has been generated automatically by RemoteXY editor. 
   To compile this code using RemoteXY library 2.3.3 or later version  
   download by link http://remotexy.com/en/library/ 
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                    
     - for ANDROID 4.1.1 or later version; 
     - for iOS 1.2.1 or later version; 
     
   This source code is free software; you can redistribute it and/or 
   modify it under the terms of the GNU Lesser General Public 
   License as published by the Free Software Foundation; either 
   version 2.1 of the License, or (at your option) any later version.     
*/ 

////////////////////////////////////////////// 
//        RemoteXY include library          // 
////////////////////////////////////////////// 

// RemoteXY select connection mode and include library  
#define REMOTEXY_MODE__ESP8266_SOFTSERIAL_POINT
#include <SoftwareSerial.h> 

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_SERIAL_RX 6 
#define REMOTEXY_SERIAL_TX 7
#define REMOTEXY_SERIAL_SPEED 115200 
#define REMOTEXY_WIFI_SSID "kuch bhi" 
#define REMOTEXY_WIFI_PASSWORD "vivek@2870" 
#define REMOTEXY_SERVER_PORT 6377 


int sensorValue=0;
int sensorPin=A0;

// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,1,0,3,0,75,0,8,13,0,
  2,1,43,48,22,11,2,26,31,31,
  79,78,0,79,70,70,0,65,6,73,
  27,9,9,66,0,25,20,7,16,2,
  26,129,0,18,40,20,3,17,83,101,
  110,115,111,114,32,83,116,97,116,117,
  115,0,129,0,68,40,19,3,17,77,
  111,116,111,114,32,83,116,97,116,117,
  115,0 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 

    // output variable
  uint8_t led_1_r; // =0..255 LED Red brightness 
  uint8_t led_1_g; // =0..255 LED Green brightness 
  int8_t level_2; // =0..100 level position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 

#define PIN_SWITCH_1 13


void setup()  
{ 
  RemoteXY_Init ();  
   
  //pinMode (PIN_SWITCH_1, OUTPUT);
   Serial.begin(9600);
  pinMode (PIN_SWITCH_1, OUTPUT);
//  pinMode (PIN_BUTTON_1, OUTPUT);
   
  // TODO you setup code 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  //digitalWrite(PIN_BUTTON_1, (RemoteXY.button_1==0)?LOW:HIGH);

  sensorValue = analogRead(sensorPin);
  RemoteXY.level_2=sensorValue;
  Serial.println(sensorValue);
  if(RemoteXY.switch_1==0)
  {
    digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
    RemoteXY.led_1_r=255;
    RemoteXY.led_1_g=0;
    
  }
  else
  {
    digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
    RemoteXY.led_1_g=255;
    RemoteXY.led_1_r=0;
  }
   
  //digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
 
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 


}
