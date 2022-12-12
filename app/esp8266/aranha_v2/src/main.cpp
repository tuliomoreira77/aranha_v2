#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "faces.h"
#include "web_server.h"
#include <screen_coordinator.h>

RobotState robotState = RobotState();
CommandProcessor commandProcessor = CommandProcessor(robotState);
RobotWebServer webServer = RobotWebServer(&commandProcessor);
ScreenCoordinator screenCoordinator = ScreenCoordinator();


void setup() {
  Serial.begin(9600);
  Serial.println();

  Serial.print("Setting soft-AP configuration ... ");

  webServer.startServer();

  Serial.print("Soft-AP IP address = ");
  Serial.println(webServer.getIpAddr());

  screenCoordinator.initScreen();
}

void loop() {
  webServer.processarComando();
  screenCoordinator.handleScreen();
}