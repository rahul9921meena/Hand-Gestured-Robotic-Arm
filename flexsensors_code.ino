const int flexPin1 = A0; // Analog pin for Flex Sensor 1
const int flexPin2 = A1; // Analog pin for Flex Sensor 2
const int flexPin3 = A2; // Analog pin for Flex Sensor 3
const int flexPin4 = A5;
const int flexPin5 = A4;


void setup() {
  pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
  pinMode(flexPin3, INPUT);
  pinMode(flexPin4, INPUT);
  pinMode(flexPin5, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read analog values from flex sensors
  int flexValue1 = analogRead(flexPin1);
  int flexValue2 = analogRead(flexPin2);
  int flexValue3 = analogRead(flexPin3);
  int flexValue4 = analogRead(flexPin4);
  int flexValue5 = analogRead(flexPin5);

  int flex1 = map(flexValue1,9,17,9,0);
   int flex2 = map(flexValue2,101,149,0,9);
    int flex3 = map(flexValue3,111,150,0,9);
     int flex4 = map(flexValue4,170,270,9,0);
     int flex5 = map(flexValue5,175,212,0,9);

    // if(flex1>=9)
     //flex1=9;
    // if(flex1<=0)
    // flex1=0;


     if(flex2>=9)
     flex2=9;
     if(flex2<=0)
     flex2=0;


    // if(flex3>=9)
    // flex3=9;
    // if(flex3<=0)
    // flex3=0;


     //if(flex4>=9)
    //flex4=9;
     if(flex4<=4)
     flex4=0;


    // if(flex5>=9)
    // flex5=9;
    // if(flex5<=0)
    // flex5=0;


  // Print the analog values to the serial monitor
  //Serial.print("Flex Sensor 1: ");
  Serial.print(" ");
  Serial.print(flex1);
  Serial.print(" ");
  Serial.print(flex2);
  Serial.print(" ");
  Serial.print(flex3);
  Serial.print(" ");
  Serial.print(flex4);
  Serial.print(" ");
  Serial.print(flex5);
  Serial.println();
  delay(100); // Adjust delay as needed
}