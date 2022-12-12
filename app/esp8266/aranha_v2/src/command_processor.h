#pragma once

#include <Arduino.h>
#include <state.h>

/*
Comandos:
FR <- frente
TR <- tras
VD <- virar direita
VE <- virar esquerda
DC <- danca
AC <- acenar

*/

class CommandProcessor {
    private:
        RobotState robotState;

    public:
        CommandProcessor(RobotState state) {
            robotState = state;
        }

        int processCommand(String rawCommand);
};