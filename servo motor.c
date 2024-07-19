#include <esp_now.h>
#include <WiFi.h>
#include <ESP32Servo.h>

// Define servo object
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;

#define led1 4
String ans;
 String sen1;
  String sen2;
  String sen4;
  String sen3;
  String sen5;
  
// Must match the sender structure
typedef struct message_struct {
  char message[100]; // "hello" plus null terminator
} message_struct;

// Create a message_struct called myData
message_struct myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  //Serial.print("Bytes received: ");
  //Serial.println(len);
 // Serial.print("Message: ");
 // Serial.println(myData.message);

  // Check if the received message is "hello"
  if (strcmp(myData.message, "hello") == 0) {
    digitalWrite(led1, HIGH); // Turn on LED
    delay(1000); // Keep LED on for 1 second
    digitalWrite(led1, LOW); // Turn off LED
  }
}

void setup() {
   myServo1.attach(14); // Adjust pin number according to your setup
   myServo2.attach(12);
   myServo3.attach(13.0);
   myServo4.attach(27);
   myServo5.attach(26);

  // Initialize Serial Monitor
  Serial.begin(9600);
  
  pinMode(led1, OUTPUT);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully initialized, we will register for recv CB to
  // get receive packet info
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  // Nothing to do here as the callback function handles received data
  ans = myData.message;
 sen1 = ans.charAt(1);
 sen2 = ans.substring(3,4);
 sen3 = ans.substring(5,6);
 sen4 = ans.substring(7,8);
 sen5 = ans.substring(9,10);

int value1 = sen1.toInt();
int value2 = sen2.toInt();
int value3 = sen3.toInt();
int value4 = sen4.toInt();
int value5 = sen5.toInt();




 int angle1 = map(value1,0,9,90,0);
 int angle2 = map(value2,0,9,90,0);
 int angle3 = map(value3,0,9,90,0);
 int angle4 = map(value4,0,9,90,0);
 int angle5 = map(value5,0,9,90,0);



 Serial.print(value1);
  Serial.print(" ");
  Serial.print(value2);
   Serial.print(" ");
   Serial.print(value3);
    Serial.print(" ");
    Serial.print(value4);
     Serial.print(" ");
     Serial.print(value5);
     Serial.println();
      

myServo1.write(55 + angle1 );
myServo2.write(60 + angle2 );
myServo3.write(90 + angle3 );
myServo4.write(0 + angle4 );
myServo5.write(100 + angle5 );

}