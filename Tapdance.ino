#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>

AsyncDelay timeRemaining;
volatile bool leftButtonFlag = false;
volatile bool rightButtonFlag = false;
volatile bool switchFlag = false;
bool standbyFlag = true;
int score = 0;

void setup() {
    CircuitPlayground.begin();
    Serial.begin(9600);

    attachInterrupt(digitalPinToInterrupt(4), leftButton, FALLING);
    attachInterrupt(digitalPinToInterrupt(5), rightButton, FALLING);
    attachInterrupt(digitalPinToInterrupt(7), switched, CHANGE);

    randomSeed(analogRead(0));
}

void loop() {
    
    delay(10);
    
    if (switchFlag == false) {
        
        if (standbyFlag == false) {
        
            delay(5);
        
            rightButtonFlag = false;
            leftButtonFlag = false;
        
            timeRemaining.start(25000 / (score + 11), AsyncDelay::MILLIS);
        
            int randLight = random(10);
        
            CircuitPlayground.clearPixels();
            CircuitPlayground.setPixelColor(randLight, 0x00FF00);

            while (true) {
        
                if (rightButtonFlag == true || leftButtonFlag == true) {
        
                    } else if (randLight >= 5 && leftButtonFlag == true) {
        
                        failstate();
                        break;
        
                    } else if (randLight < 5 && rightButtonFlag == true) {
        
                        failstate();
                        break;
        
                    } else {
        
                        ++score;
                        Serial.print("Score: ");
                        Serial.println(score);
        
                        CircuitPlayground.playTone(400, 100, false);
        
                        rightButtonFlag = false;
                        leftButtonFlag = false;
                        break;
                    }
                }
                if (timeRemaining.isExpired()) {
        
                    failstate();
                    break;
        
                }
            }
        }
    }
}

void failstate() {
   
    for (int i = 0; i < 10; ++i) {
        CircuitPlayground.setPixelColor(i, 0xFF0000);
    }
    CircuitPlayground.playTone(200, 500);
    CircuitPlayground.clearPixels();
   
    rightButtonFlag = false;
    leftButtonFlag = false;
    standbyFlag = true;
    score = 0;

}

void leftButton() {
    
    noInterrupts();
    leftButtonFlag = true;
    standbyFlag = false;
    interrupts();

}

void rightButton() {
    
    noInterrupts();
    rightButtonFlag = true;
    standbyFlag = false;
    interrupts();

}

void switched() {
   
    noInterrupts();
    switchFlag = !switchFlag;
    CircuitPlayground.clearPixels();
    score = 0;
    standbyFlag = true;
    interrupts();

}
