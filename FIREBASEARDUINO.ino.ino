#include <FirebaseArduino.h> 
#include <ESP8266WiFi.h>             //wifi library
#define WIFI_SSID "mechanicalengine"             //replace SSID with your wifi username
#define WIFI_PASSWORD "unaltrocosa"          //replace PWD with your wifi password
#define WIFI_LED 0                  //connect a led to any of the gpio pins of the board and replace pin_number with it eg. D4                      

#define FIREBASE_HOST "android-test-8ccdc.firebaseio.com"                         //link of api
#define FIREBASE_AUTH "3zdJfzRp1hiwEQL6gzF2fdGocNjnVIuPhYN2NJLf"           //database secret


void setup() {
  Serial.begin(9600);
  pinMode(WIFI_LED,OUTPUT);                         //define pinmodes
  digitalWrite(WIFI_LED,LOW); 



  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  
  //connect to wifi
  while (WiFi.status() != WL_CONNECTED) {           //wait till connected to WiFi
    delay(100);  
/*    digitalWrite(WIFI_LED,LOW);                     //Blink the light till connected to WiFi
    delay(100);
    digitalWrite(WIFI_LED,HIGH);*/
    Serial.print("."); 
 }
    
  Serial.println("");
  Serial.println("WiFi connected");
  //digitalWrite(WIFI_LED,HIGH);  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);             //connect to Database
  delay(1000);
}

void loop() {
  String firebaseResult = firebaseGet("led1/status");
  Serial.println(firebaseResult);

  if (firebaseResult=="ON"){
    digitalWrite(WIFI_LED,HIGH);//SONRADAN YAZILDI
      //code to happen if the status is ON  
  }else{
      //code to happen if the status is OFF
      digitalWrite(WIFI_LED,LOW); //SONRADAN YAZILDI
    }
} 

String firebaseGet(String s){
    String x =Firebase.getString(s);
    //yield();
    delay(100);
    return x;
}
