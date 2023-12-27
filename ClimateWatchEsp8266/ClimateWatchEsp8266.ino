#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

#include <OneWire.h>
#include <DallasTemperature.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

// Insert Firebase project API Key
#define API_KEY "AIzaSyCrO6W_-e-AiHz5vNCDNZolnD-0JsVa0kI"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://iotproject-694dc-default-rtdb.europe-west1.firebasedatabase.app/"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

//initialization of variables

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false;


//----------VARIABLES-------------
  float WantedTemperatureValue;
    bool AutomatskoIskljucivanje;
    int Upali;
    int UpaliT;


#define ONE_WIRE_BUS D2 // Pin where the DS18B20 is connected

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(){
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  //button


  //DIODA

  pinMode(D1, OUTPUT);
}

void loop()
{



      if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 2000 || sendDataPrevMillis == 0))
          {
              sendDataPrevMillis = millis();

              sensors.requestTemperatures();
              float temperatureC=sensors.getTempCByIndex(0);
              float temperatureF=sensors.getTempFByIndex(0);

              //----------------CHECKING IF SENSOR IS WORKING-----------------
                Serial.print("Temperatura:");
                Serial.print(temperatureC);
                Serial.println(" °C");

               //----------------RETRIEVING DATA FROM FIREBASE-----------------

               if (Firebase.RTDB.getFloat(&fbdo, "WantedTemperature/WantTemp")) 
                  {
                      if (fbdo.dataType() == "float") 
                           {
                                WantedTemperatureValue = fbdo.floatData();
                                 Serial.print("ZELJENA TEMP: ");
                               Serial.println(WantedTemperatureValue);
                           } 
                  }
              

                if (Firebase.RTDB.getInt(&fbdo, "WantedTemperature/nmb"))
                   {
                       if (fbdo.dataType() == "int") 
                          {
                                AutomatskoIskljucivanje = fbdo.intData();
                                Serial.print("AutomatskoIskljucivanje temp ");
                                Serial.println(AutomatskoIskljucivanje);

                           }
                    }

                if (Firebase.RTDB.getInt(&fbdo, "Upali/Upali")) 
                    {
                        if (fbdo.dataType() == "int") 
                           {
                                Upali = fbdo.intData(); 
                                Serial.print("Upali ");
                                Serial.println(Upali);
                            }
                      }
        
                if (Firebase.RTDB.getInt(&fbdo, "Upali/UpaliT")) 
                    {
                        if (fbdo.dataType() == "int") 
                            {
                                UpaliT = fbdo.intData(); 
                                Serial.print("Upali na vrijeme ");
                                Serial.println(UpaliT);
                            }
 
                    } 


            if (Upali == 1 || UpaliT==1) 
                {
                     digitalWrite(D1, HIGH);
                     //checkbtn
                } 
            else
                {
                     digitalWrite(D1, LOW);

                }
            if ((AutomatskoIskljucivanje == 1 && WantedTemperatureValue<temperatureC))
                {
                      Upali=0;
                      UpaliT=0;

                      if(Firebase.RTDB.setInt(&fbdo, "Upali/UpaliT", UpaliT))
                        {

                          Serial.println("PASSED");
                          Serial.println("PATH: " + fbdo.dataPath());
                          Serial.println("TYPE: " + fbdo.dataType() + " " + Upali);
                        }
                      else
                       {

                          Serial.println("FAILED");
                          Serial.println("REASON: " + fbdo.errorReason());
                       }
                      if(Firebase.RTDB.setInt(&fbdo, "Upali/Upali", Upali))
                        {

                          Serial.println("PASSED");
                          Serial.println("PATH: " + fbdo.dataPath());
                          Serial.println("TYPE: " + fbdo.dataType() + " " + Upali);
                        }
                      else 
                        {
                           Serial.println("FAILED");
                          Serial.println("REASON: " + fbdo.errorReason());
                        }


                  digitalWrite(D1, LOW);
    
                }

  
          }
          

}
  
