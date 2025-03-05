#include <connection.h>

#include <WiFi.h>
#include <HTTPUpdate.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <cert.h>
#include <SPIFFS.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

const int led1 = 14;
const int led3 = 13;
const int led4 = 15;
const int led2 = 12;

#define bme_sda 32
#define precipita 33
#define speedsense 27
#define dist 26


#define BinFile "https://raw.githubusercontent.com/Ze-r000/Sketches/main/C8.bin"


String Sketch = {"7.0"};

Adafruit_BME280 bme;


int count = 10;

const float Diameter = 0.070; 
const int hpr = 50; 
volatile unsigned int holes = 0;
unsigned long previousMillis = 0;
unsigned long interval = 1000; 
float rpm = 0.0;
float speed = 0.0;
bool isSensorConnected = false; 
int confirmationCount = 0;   
int confirmationCountprep = 0;
int confirmationCountdist = 0;

void setup()
{  
    WiFi.mode(WIFI_STA);
    WiFi.begin(WifiName, WifiPassword);
    pinMode (led1, OUTPUT);
    pinMode (led2, OUTPUT);
    pinMode (led3, OUTPUT);
    pinMode (led4, OUTPUT);
  
    Serial.begin(115200);
///================================================================================BME280 SETUP
    Wire.begin(bme_sda, 22);
    bme.begin(0x76);
///================================================================================PRECIPITATION SETUP
    pinMode(precipita, INPUT);
///================================================================================DISTANCE SETUP
    pinMode(dist, INPUT);
///================================================================================SPEED SETUP
    pinMode(speedsense, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(speedsense), HolesCount, RISING);
///================================================================================END SETUP
    digitalWrite (led1, LOW);
    digitalWrite (led2, LOW);
    digitalWrite (led3, LOW);
    digitalWrite (led4, LOW);
}

void loop()
{
///================================================================================BME280 LOOP

    digitalWrite (led1, LOW);
    digitalWrite (led2, LOW);
    digitalWrite (led3, LOW);
    digitalWrite (led4, LOW);
    
    Serial.print("Code Number:");
    Serial.println(Sketch);
    Serial.println();
    
    WiFi.disconnect(WifiName, WifiPassword);
    float temperature = bme.readTemperature();
    float humidity = bme.readHumidity();
    float pressure = bme.readPressure() / 100.0F;

    if (temperature > 40 || isnan(temperature) || temperature ==0)
    {
      digitalWrite (led1, LOW);
      Serial.print("Finding New Port for BME");
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        delay(100);
        digitalWrite (led1, HIGH);
        delay(100);
        digitalWrite (led1, LOW);
        SketchUpdate();
    }
    else
    {
    Serial.print("Temperature = "); 
    Serial.print(temperature);
    Serial.println(" *C");
    Serial.print("Pressure = ");
    Serial.print(pressure);
    Serial.println(" hPa");
    Serial.print("Humidity = ");
    Serial.print(humidity);
    Serial.println(" %");
    
    delay(1000);
    digitalWrite (led1, HIGH);
    Serial.println();
    }
    
///==============================================================================DISTANCE LOOP
 float dists = analogRead(dist);
  int  dista = (31480/(dists-14));
  
  
  if  (dista > 100 || dista <= 9 || dista >= 24)
  {
        digitalWrite (led2  , LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        confirmationCountdist++;
    while (true) 
    {
     if (confirmationCountdist >= 3)
      {
        Serial.print(dista);
        Serial.print("Finding New Port for Distance");
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        delay(100);
        digitalWrite (led2, LOW);
        delay(100);
        digitalWrite (led2, HIGH);
        SketchUpdate();
     } 
    return;
  }
 }
  else
  {
  Serial.print(dista);
  confirmationCountdist = 0;
  String distan_str;
  if (dista ==20 || dista ==21) 
  {
    distan_str = "North West";
  } 
  else if (dista ==18 || dista ==19) 
  {
    distan_str = "West";
  } 
  else if ( dista ==17) 
  {
    distan_str = "South West";
  } 
  else if (dista ==15 || dista ==16) 
  {
    distan_str = "South";
  } 
  else if (dista ==13 || dista ==14) 
  {
    distan_str = "South East";
  } 
  else if (dista ==12) 
  {
    distan_str = "East";
  } 
  else if (dista == 22 || dista ==23) 
  {
    distan_str = "North East";
  } 
  else if (dista == 11) 
  {  
    distan_str = "North";
  }
 
  
   Serial.print("Wind Direction: " + distan_str);
   Serial.println();
   Serial.print(dista);
   delay(1000);
   digitalWrite (led2, HIGH);
 }  
///==============================================================================PRECIPITATION LOOP
  float Prep = analogRead(precipita);
  float precipitations = ((4095 - Prep) * 100 / 4095);
  
  if (precipitations >= 99 || precipitations == 0 || (precipitations >= 58 & precipitations <= 59)|| (precipitations >= 65 & precipitations <= 68)|| (precipitations >= 83 & precipitations <= 84)) //bigyan ng konting signal or wag pagpalitin ang speed at rain
  {
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        confirmationCountprep++;
    while (true) 
    {
   if (confirmationCountprep >= 7)
   {
    digitalWrite (led3, LOW);
    Serial.print("Finding New Port for Precipitation");
    Serial.print(precipitations);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        delay(100);
        digitalWrite (led3, HIGH);
        delay(100);
        digitalWrite (led3, LOW);
        SketchUpdate();
    } 
    return;
    }
  }
  else
  {
    confirmationCountprep = 0;
    Serial.print("Precipitation: ");
    Serial.println(precipitations);
    
    delay(1000);
    digitalWrite (led3, HIGH);
  } 

///================================================================================SPEED LOOP
  unsigned long currentMillis = millis();
  isSensorConnected = digitalRead(speedsense) == LOW;
  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;
    detachInterrupt(speedsense);
    rpm = holes * (60.0/hpr);
    speed = rpm*Diameter*3.14159/60.0; 
    float windspeed = (speed);
    holes = 0;
    delay(10); 
    attachInterrupt(digitalPinToInterrupt(speedsense), HolesCount, RISING);
    if (isSensorConnected || windspeed > 1000 || windspeed >120) 
    { 
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        confirmationCount++;
      if (confirmationCount >= 4) 
      {
        digitalWrite (led4, LOW);
        Serial.println("Finding New Port for Speed"); 
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        delay(100);
        digitalWrite (led4, HIGH);
        delay(100);
        digitalWrite (led4, LOW);
        Serial.print(windspeed);
        SketchUpdate();        
      }
    }
    
    if (windspeed >= 8 & windspeed <= 45)
    {
      while (true) 
      {
        return;
      } 
    }
    
    else 
    {
      confirmationCount = 0;
      Serial.print("Speed: ");
      Serial.print(windspeed,2); 
      Serial.println(" m/s");
      delay(1000);
      digitalWrite (led4, HIGH);
      
      WiFi.begin(WifiName, WifiPassword);
      delay(7000);
      write_to_google_sheet(temperature, pressure, precipitations, windspeed, dista, humidity);
      delay(10000);
      digitalWrite (led1, LOW);
      digitalWrite (led2, LOW);
      digitalWrite (led3, LOW);
      digitalWrite (led4, LOW);
      delay(300);
      digitalWrite (led1, HIGH);
      delay(300);
      digitalWrite (led2, HIGH);
      delay(300);
      digitalWrite (led3, HIGH);
      delay(300);
      digitalWrite (led4, HIGH);

      digitalWrite (led1, LOW);
      digitalWrite (led2, LOW);
      digitalWrite (led3, LOW);
      digitalWrite (led4, LOW);
      delay(300);
      digitalWrite (led1, HIGH);
      digitalWrite (led2, HIGH);
      digitalWrite (led3, HIGH);
      digitalWrite (led4, HIGH);
      delay(300);
      digitalWrite (led1, LOW);
      digitalWrite (led2, LOW);
      digitalWrite (led3, LOW);
      digitalWrite (led4, LOW);
      delay(300);
      digitalWrite (led1, HIGH);
      digitalWrite (led2, HIGH);
      digitalWrite (led3, HIGH);
      digitalWrite (led4, HIGH);
      delay(300);
      digitalWrite (led1, LOW);
      digitalWrite (led2, LOW);
      digitalWrite (led3, LOW);
      digitalWrite (led4, LOW);
      delay(300);
      digitalWrite (led1, HIGH);
      digitalWrite (led2, HIGH);
      digitalWrite (led3, HIGH);
      digitalWrite (led4, HIGH);
      delay(300);
     }
  } 
}
///================================================================================END LOOP


void write_to_google_sheet(float temperature, float pressure, float precipitations, float windspeed, float dista, float humidity) 
{
   String SCRIPT_ID = "AKfycbzpEMJ-52ayiOc1Uw_JjZ8SHw6ganyoc_l8HYI2TYqxz4eN4zhQiapOOldazMlWfrXt";
   HTTPClient http;
   String url="https://script.google.com/macros/s/"+SCRIPT_ID+"/exec?temperature="+String(temperature)+"&pressure="+String(pressure)+"&humidity="+String(humidity)+"&windspeed="+String(windspeed)+"&precipitations="+String(precipitations)+"&dista="+String(dista);
   http.begin(url.c_str());
   http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);        
   int httpCode = http.GET();  
 
   String payload;
   http.end();
}

void SketchUpdate(void) 
{
    WiFi.begin(WifiName, WifiPassword);
    delay (2000);
    WiFiClientSecure client;
    client.setCACert(rootCACertificate);
    t_httpUpdate_return ret = httpUpdate.update(client, BinFile);

    switch (ret) 
    {
    case HTTP_UPDATE_FAILED:
        Serial.printf("HTTP_UPDATE_FAILED_Error (%d): %s\n", httpUpdate.getLastError(), httpUpdate.getLastErrorString().c_str());
        break;

    case HTTP_UPDATE_NO_UPDATES:
        Serial.println("HTTP_UPDATE_NO_UPDATES");
        break;

    case HTTP_UPDATE_OK:
        Serial.println("HTTP_UPDATE_OKAY");
        break;
    }
}

void HolesCount() 
{
  holes += 5;
  isSensorConnected = true;
}
