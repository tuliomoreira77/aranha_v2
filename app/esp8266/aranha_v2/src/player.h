#pragma once

#include<animation_queue.h>
#include<animation_frame.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

class Player {
    private:
        AnimationQueue* animationQueue;
        unsigned long lastExecution = 0;
        Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);

    public:
        Player(AnimationQueue* animationQueue) {
            this->animationQueue = animationQueue;
        }

        void init() {
            display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
            display.clearDisplay();
            display.display();
        }

        void execute() {
            unsigned long now = millis();
            if(animationQueue->getSize() > 0) {
                AnimationFrame* frame = animationQueue->getFirst();
                if(now >= lastExecution + frame->time) {
                    display.clearDisplay();
                    display.drawBitmap(frame->offset_x, frame->offset_y, frame->frame, 128, 64, 1);
                    display.display();
                    animationQueue->popFromQueue();
                    lastExecution = now;
                }
            }
        }
};