#pragma once

#include <Arduino.h>
#include <command.h>

class DefaultCommand:public Command {
    private:
        String bodyCommand = "";

    public:
        DefaultCommand(String command) {
            bodyCommand = command;
        }

        String getFace() {
            return "neutral";
        }

        String getSound() {
            return "none";
        }

        String getBodyCommand() {
            return bodyCommand;
        }
};