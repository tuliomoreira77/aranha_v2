#include<state.h>

String RobotState::getActualFace() {
    return actualFace;
}

void RobotState::setActualFace(String face) {
    actualFace = face;
    stateChanged = true;
}

String RobotState::getActualSound() {
    return actualSoung;
}

void RobotState::setActualSound(String sound) {
    actualSoung = sound;
    stateChanged = true;
}

Command* RobotState::getActualCommand() {
    return actualCommand;
}

void RobotState::setActualCommand(Command* command) {
    delete actualCommand;
    actualCommand = command;
    stateChanged = true;
}

bool RobotState::isReceiveCommand() {
    return receiveCommand;
}

void RobotState::setReceiveCommand(bool command) {
    receiveCommand = command;
    stateChanged = true;
}

bool RobotState::isStateChanged() {
    return stateChanged;
}