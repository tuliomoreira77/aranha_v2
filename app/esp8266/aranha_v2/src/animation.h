#pragma once

#include <Arduino.h>
#include<animation_frame.h>
#include<faces.h>
#include<abstract_animation.h>

class AnimationNeutral:public Animation {
    public:
        int size = 3;
        AnimationFrame* frames[3];

        int getSize() {
            return size;
        }

        AnimationFrame** getAnimation() {
            int randon_x = random(0,8) - 4;
            int randon_y = random(0,8) -4;
            frames[0] = new AnimationFrame(idle6, 100, 0, 0);
            frames[1] = new AnimationFrame(idle6, 50, randon_x, randon_y);
            frames[2] = new AnimationFrame(idle6, 500, 0, 0);
            return frames;
        }

        bool isAnimationPlayed() {
            for(int i=0; i < 3; i++) {
                if(!frames[i]->isPlayed) {
                    return false;
                }
            }
            return true;
        }

        ~AnimationNeutral() {
            for(int i=0; i<3; i++) {
                delete frames[i];
            }
        };

};

class AnimationNeutralBlink:public Animation {
    public:
        int size = 6;
        AnimationFrame* frames[6];

        int getSize() {
            return size;
        }

        AnimationFrame** getAnimation() {
            frames[0] = new AnimationFrame(idle6, 100, 0, 0);
            frames[1] = new AnimationFrame(idle9, 25, 0, 0);
            frames[2] = new AnimationFrame(idle10, 25, 0, 0);
            frames[3] = new AnimationFrame(idle11, 25, 0, 0);
            frames[4] = new AnimationFrame(idle12, 100, 0, 0);
            frames[5] = new AnimationFrame(idle6, 25, 0, 0);
            return frames;
        }

        bool isAnimationPlayed() {
            for(int i=0; i < size; i++) {
                if(!frames[i]->isPlayed) {
                    return false;
                }
            }
            return true;
        }

        ~AnimationNeutralBlink() {
            for(int i=0; i<size; i++) {
                delete frames[i];
            }
        };

};