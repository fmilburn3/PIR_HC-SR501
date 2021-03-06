 /* 
 PIR motion sensor example
 Demonstrates Addicore PIR infrared motion sensor (HC-SR501) on the
 Texas Instruments MSP-Exp430F5529 LaunchPad with Energia.
 https://www.addicore.com/PIR-Infrared-Motion-Sensor-HC-SR501-p/168.htm
 Lights LED and displays to serial monitor when motion is detected
  
 Created by Frank Milburn, 28 May 2015
 Released into the public domain.
 
 PIR or Passive Infrared is a method of motion detection that 
 takes IR (heat) images on 2 sensors at different times.  When
 they differ something has changed and the sensor sends a HIGH digital
 signal to the microcontroller.  The HC-SR501 has two potentiometers
 for adjusting sensitivity and time delay. My specimen seemed very
 sensitive to these settings. Note that it will normally  take
 10 - 60 seconds for the device to warm up and readings may be spurious
 during this period.
 
 Pin and wiring connections
 --------------------------
 Pin connections can be changed but OUT on the sensor must be connected
 to a digital pin. Pin connections that will work for most Texas 
 Instruments LaunchPads are given below...
 
 PIR           LaunchPads  
 --------      ----------      
 VCC           5V                  
 OUT           4.7k to pin 3             Route OUT through a voltage divider 
               pin 3 to 10k to GND 
 GND           GND         
 
 LaunchPads are 3V3 devices!  Do not wire pins directly to 5V.
 The specifications say that this is a 5-20 V device.  I couldn't get it
 to work on 3.3V.  Accordingly a voltage divider was used.
 
 Caution! The CC3200 LaunchPad is limited to 1.8V for analog input!  Use a
 voltage divider or other means to reduce analog voltage down to 1.8V.
 
 */

int pirPin = 3;            //  Connect OUT on the PIR to this digital pin
int ledPin = RED_LED;      //  LED indicates motion occurred

void setup()
  {
    
  Serial.begin(9600); 
  pinMode(pirPin, INPUT);   // Set the PIR pin to input
  pinMode(ledPin, OUTPUT);  // LED will be an output for when motion is detected
  delay(1000);              // let things settle
  Serial.println("Start motion detection...");  // and send a message to the serial monitor
                                                // to let the user know we are starting
  }

void loop()
  {   
  static unsigned int motionCounter = 0;     // Initialize the motion counter (number
                                             // of times motion has been detected since
                                             // the program started or was reset)   

  if(digitalRead(pirPin) == HIGH)            // Read the PIR pin to see if motion occurred
    { 
    motionCounter = motionCounter ++;        // if so, then increment the motion counter and
    Serial.print("Motion Detected: ");       // write Motion Detected to serial monitor
    Serial.println(motionCounter);           // with the number of times detected
    while (digitalRead(pirPin) == HIGH){     // and while the pin is high...    
      digitalWrite(ledPin, HIGH);            // light the LED           
      }    
    digitalWrite(ledPin, LOW);               // after pirPin goes low, turn LED off
    }  
  }
