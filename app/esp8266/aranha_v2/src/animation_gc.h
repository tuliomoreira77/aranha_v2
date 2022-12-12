#pragma once

#include<abstract_animation.h>

class NaiveAnimationGC {
    private:
        Animation** trackedAnimations = new Animation*[20];
        int index = 0;

    public:
        NaiveAnimationGC() {
            for(int i = 0; i < 20; i++) {
                trackedAnimations[i] = 0;
            }
        }

        void track(Animation* animation) {
            for(int i = 0; i < 20; i++) {
                if(trackedAnimations[i] == 0) {
                    trackedAnimations[i] = animation;
                    index = index + 1;
                    return;
                }
            }
        }

        void collect() {
            if(index > 15) {
                int collectedCounter = 0;
                for(int i=0; i<index; i++) {
                    Animation* animation = trackedAnimations[i];
                    if(animation->isAnimationPlayed()) {
                        delete animation;
                        trackedAnimations[i] = 0;
                        collectedCounter++;
                    }
                }
                index = index - collectedCounter;
            }
        }
};