//SERVO
#include <Servo.h>
Servo servo1;  // create servo object to control a servo
Servo servo2; 

// Declaration of trigger and echo pins

int trigPin = 5;

int echoPin = 6;

 

// declaration of variables going to be used for the program

int distance1 = 0;

int distance2 = 0;

int measured_speed = 0;

long duration = 0;

int distance = 0;

void setup()
{
    servo1.attach(13,600,2300);  // (pin, min, max)
    servo2.attach(8,600,2300);  // (pin, min, max)

    Serial.begin(9600); 
    servo2.write(0);  // tell servo to go to a particular angle
    servo1.write(180);  // tell servo to go to a particular angle
    Serial.println("0,180");

}

 

void loop()

{

//button
// read the state of the pushbutton value:
    //SERVO OPEN
    Serial.println("open");
    servo1.write(180);  
    servo2.write(0); 
    // Measuring distance 1
    distance1 = ultrasonicRead();
    delay(3000);                  
    distance2 = ultrasonicRead(); 
    measured_speed = abs(distance2 - distance1) / 1.0;

    if(measured_speed < 30){
        Serial.println(1);
    }else{
         Serial.println(2);
    }
    Serial.print("Speed in cm/s :");

    Serial.println(measured_speed);
    //RECORDING END
    digitalWrite(10, LOW);

    Serial.println("blinking");
    //BLINK eyelid
    delay(200); 
    servo1.write(90);  
    servo2.write(90);  
    delay(200); 
    servo1.write(180); 
    servo2.write(0);  
    delay(200); 
    servo1.write(90);  
    servo2.write(90);  
    delay(200); 
    servo1.write(90);  
    servo2.write(90);  
    delay(200); 
    servo1.write(180); 
    servo2.write(0);  
    delay(200); 
    servo1.write(90);  
    servo2.write(90);  
    delay(200); 

    Serial.println("open");
    servo1.write(180);  
    servo2.write(00); 
    delay(8000); 


    //eye CLOSE
    Serial.println("close");
    servo1.write(80);  
    servo2.write(100);  
    delay(1000); 
 
}
float ultrasonicRead()

{
    digitalWrite(trigPin, HIGH);

    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = duration * 0.034 / 2;

    return distance;
        
}

