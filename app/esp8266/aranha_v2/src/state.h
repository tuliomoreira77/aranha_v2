#pragma once

#include <Arduino.h>
#include <command.h>

class RobotState {
    public:
        String getActualFace();
        void setActualFace(String face);
        String getActualSound();
        void setActualSound(String sound);
        Command* getActualCommand();
        void setActualCommand(Command* command);
        bool isReceiveCommand();
        void setReceiveCommand(bool command);
        bool isStateChanged();

    private:
        String actualFace = "neutral";
        String actualSoung = "none";
        Command* actualCommand;
        bool receiveCommand = false;
        bool stateChanged = false;
};