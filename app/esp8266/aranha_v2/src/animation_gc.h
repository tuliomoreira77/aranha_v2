#pragma once

#include<abstract_animation.h>
#include<linked_list.h>

class NaiveAnimationGC {
    private:
        List<Animation>* animations = new LinkedList<Animation>();
        int index = 0;

    public:
        NaiveAnimationGC() {
            
        }

        void track(Animation* animation) {
            animations->add(animation);
        }

        void collect() {
            if(index > 15) {
                int collectedCounter = 0;
                for(int i=0; i<index; i++) {
                    Animation* animation = animations->get(i);
                    if(animation->isAnimationPlayed()) {
                        delete animation;
                        animations->remove(i);
                        collectedCounter++;
                    }
                }
                index = index - collectedCounter;
            }
        }
};