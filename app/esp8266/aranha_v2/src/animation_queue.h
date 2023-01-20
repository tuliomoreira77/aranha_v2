#pragma once

#include <Arduino.h>
#include <animation_frame.h>
#include <array_list.h>

class AnimationQueue {

  private:
    List<AnimationFrame>* list = new ArrayList<AnimationFrame>(40);
    int length = 0;

  public:

    void addToQueue(AnimationFrame* frame) {
      list->add(frame);
    }
    
    AnimationFrame* getFirst() {
      AnimationFrame* frame = list->get(0);
      return frame;
    }

    AnimationFrame* popFromQueue() {
      AnimationFrame* frame = list->remove(0);
      frame->isPlayed = true;
      return frame;
    }

    int getSize() {
      return list->size();
    }

};