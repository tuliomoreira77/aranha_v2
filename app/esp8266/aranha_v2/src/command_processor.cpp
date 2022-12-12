#include<command_processor.h>
#include<default_command.h>


int CommandProcessor::processCommand(String rawCommand) {
    String commandType = rawCommand.substring(0,2);
    Command* command = NULL;

    if(commandType.equals("FR")) {
        command = new DefaultCommand(rawCommand);
    }
    if(commandType.equals("TR")) {
        command = new DefaultCommand(rawCommand);
    }
    if(commandType.equals("VD")) {
        command = new DefaultCommand(rawCommand);
    }
    if(commandType.equals("VE")) {
        command = new DefaultCommand(rawCommand);
    }

    if(command == NULL) {
        return -1;
    }

    robotState.setActualCommand(command);
    robotState.setActualFace(command->getFace());
    robotState.setActualSound(command->getSound());

    Serial.print(command->getFace());

    return 0;
}