#pragma once

#include<animation_frame.h>

class Animation {
    public:
        virtual int getSize();

        virtual AnimationFrame** getAnimation() = 0;

        virtual bool isAnimationPlayed() = 0;

        virtual ~Animation() {};
};