#pragma once

#include<Arduino.h>
#include<animation_frame.h>
#include<animation.h>
#include<abstract_animation.h>
#include<animation_gc.h>
#include<animation_queue.h>
#include<player.h>

class ScreenCoordinator {

    private:
        typedef struct {
            unsigned long nextVariation;
        }Timer;

        Timer variationTimer = {.nextVariation = 0};
        Timer blinkTimer = {.nextVariation = 0};
        NaiveAnimationGC gc = NaiveAnimationGC();
        AnimationQueue* animationQueue = new AnimationQueue();
        Player player = Player(animationQueue);

        void sendAnimationToQueue(Animation* animation) {
            AnimationFrame** frames = animation->getAnimation();
            for(int i=0; i < animation->getSize(); i++) {
                animationQueue->addToQueue(frames[i]);
            }
        }

        void idleAnimationInjector() {
            unsigned long now = millis();
            if(now >= variationTimer.nextVariation) {
                variationTimer.nextVariation = now + random(1000, 5000);
                Animation* animation = new AnimationNeutral();
                gc.track(animation);
                sendAnimationToQueue(animation);
            }
        }

        void idleBlinkAnimationInjector() {
            unsigned long now = millis();
            if(now >= blinkTimer.nextVariation) {
                blinkTimer.nextVariation = now + random(3000, 15000);
                Animation* animation = new AnimationNeutralBlink();
                gc.track(animation);
                sendAnimationToQueue(animation);
            }
        }

    public:

        void initScreen() {
            player.init();
        }

        void handleScreen() {
            idleAnimationInjector();
            idleBlinkAnimationInjector();
            player.execute();
            gc.collect();
        }

};