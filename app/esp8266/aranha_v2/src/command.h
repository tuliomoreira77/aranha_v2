#pragma once

#include <Arduino.h>

class Command {
    private:

    public:
        virtual String getFace() = 0;
        virtual String getSound() = 0;
        virtual String getBodyCommand() = 0;
};