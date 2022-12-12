#pragma once

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <command_processor.h>

class RobotWebServer {
    public:
        RobotWebServer(CommandProcessor* commandProcessor) {
            this->commandProcessor = commandProcessor;
        }

        void startServer();
        String getIpAddr();
        void processarComando();

    private:
        String wifiName = "Robo_Aranha";
        String wifiPass = "robot123";
        IPAddress local_IP = IPAddress(192,168,0,2);
        IPAddress gateway = IPAddress(192,168,0,1);
        IPAddress subnet = IPAddress(255,255,255,0);
        ESP8266WebServer server = ESP8266WebServer(8080);
        CommandProcessor* commandProcessor;

        void handleBasicCommand();
};