#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

const int LED1 = 2;
const int LED1 = 2;

const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 7;
const int LED5 = 8;

const int button1 = 11;
const int button2 = 12;

int button1Presses = 0;
boolean button2Pressed = false;

const int pot1 = A0;
const int pot2 = A1;
const int pot3 = A2;

int pot1Val;
int pot2Val;
int pot3Val;
int pot1Angle;
int pot2Angle;
int pot3Angle;

int servo1POSSaves[] = {1, 1, 1, 1, 1};
int servo2POSSaves[] = {1, 1, 1, 1, 1};
int servo3POSSaves[] = {1, 1, 1, 1, 1};


void setup() {
    servo1.attach(5);
    servo2.attach(6);
    servo3.attach(9);

    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(LED5, OUTPUT);

    Serial begin(9600);
}


void loop() {

    pot1Val = analogRead(pot1);
    pot1Angle = map(pot1Val, 0, 1023, 0, 179);
    pot2Angle = map(pot2Val, 0, 1023, 0, 179);
    pot2Val = analogRead(pot2);
    pot3Val = analogRead(pot3);
    pot3Angle = map(pot3Val, 0, 1023, 0, 179);

    servo1.write(pot1Angle);
    servo2.write(pot2Angle);
    servo3.write(pot3Angle);

    if(digitalRead(button1)==HIGH){
        button1Presses++;
        switch(button1Presses){
            case 1:
                servo1PosSaves[0] = pot1Angle;
                servo2PosSaves[0] = pot2Angle;
                servo3PosSaves[0] = pot3Angle;
                digitalWrite(LED1, HIGH);
                Serial.println("Position 1 Saved");
                break;
                delay(1000);
            case 2:
                servo1PosSaves[1] = pot1Angle;
                servo2PosSaves[1] = pot2Angle;
                servo3PosSaves[1] = pot3Angle;
                digitalWrite(LED2, HIGH);
                Serial.println("Position 2 Saved");
                break;
                delay(1000);
             case 3:
                servo1PosSaves[2] = pot1Angle;
                servo2PosSaves[2] = pot2Angle;
                servo3PosSaves[2] = pot3Angle;
                digitalWrite(LED3, HIGH);
                Serial.println("Position 3 Saved");
                break;
                delay(1000);
            case 4:
                servo1PosSaves[3] = pot1Angle;
                servo2PosSaves[3] = pot2Angle;
                servo3PosSaves[3] = pot3Angle;
                digitalWrite(LED4, HIGH);
                Serial.println("Position 4 Saved");
                break;
                delay(1000);
            case 5:
                servo1PosSaves[4] = pot1Angle;
                servo2PosSaves[4] = pot2Angle;
                servo3PosSaves[4] = pot3Angle;
                digitalWrite(LED5, HIGH);
                Serial.println("Position 5 Saved");
                break;                                         
        }
    }
    
    if(digitalRead(button2)==HIGH){
        button2Pressed = true;
    }

    if(button2Pressed){
        for(int i=0; i < 5; i++){
            servo1.write(servo1PosSaves[i]);
            servo2.write(servo2PosSaves[i]);
            servo3.write(servo3PosSaves[i]);
            Serial.println("Potentimeter Angles: ");
            Serial.println("servo1PosSaves[i]");
            Serial.println("servo2PosSaves[i]");
            Serial.println("servo3PosSaves[i]");
            delay(1000);
        }
    }
    delay(300)
}