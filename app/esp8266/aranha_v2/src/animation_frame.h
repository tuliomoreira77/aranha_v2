#pragma once

class AnimationFrame {
    public: 
        const unsigned char* frame;
        unsigned long time;
        int offset_x;
        int offset_y;
        bool isPlayed = false;

        AnimationFrame() {
            
        }

        AnimationFrame(const unsigned char* frame, unsigned long time, int offset_x, int offset_y) {
            this->frame = frame;
            this->time = time;
            this->offset_x = offset_x;
            this->offset_y = offset_y;
        }
};