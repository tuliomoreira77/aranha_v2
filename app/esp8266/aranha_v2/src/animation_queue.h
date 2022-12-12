#pragma once

#include <Arduino.h>
#include <animation_frame.h>

class AnimationQueue {

  private:
    AnimationFrame* queue[40];
    int length = 0;
    int queueSize = 40;

  public:

    void addToQueue(AnimationFrame* frame) {
      if(length >= queueSize) {
        return;
      } else {
        queue[length] = frame;
        length++;
      }
    }
    
    AnimationFrame* getFirst() {
      AnimationFrame* frame = queue[0];
      return frame;
    }

    AnimationFrame* popFromQueue() {
      AnimationFrame* frame = queue[0];
      frame->isPlayed = true;
      for(int i=1; i<queueSize; i++) {
        queue[i-1] = queue[i];
      }
      length--;
      return frame;
    }

    void emptyQueue() {
      if(length == 0) {
        return;
      } else {
        length = 0;
      }
    }

    int getSize() {
      return length;
    }

    int getFreeSize() {
      return queueSize - length;
    }

};