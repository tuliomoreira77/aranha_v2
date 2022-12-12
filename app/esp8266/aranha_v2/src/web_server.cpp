#include <web_server.h>

void RobotWebServer::startServer() {
    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP(wifiName, wifiPass);

    server.on("/basic", std::bind(&RobotWebServer::handleBasicCommand, this));
    server.begin();
}

String RobotWebServer::getIpAddr() {
    return WiFi.softAPIP().toString();
}

void RobotWebServer::processarComando() {
    server.handleClient();
}

void RobotWebServer::handleBasicCommand() {
    if (server.hasArg("plain") == false) { 
        server.send(404, "text/plain", "Body not received");
        return;
    }

    String body = server.arg("plain");
    int response = commandProcessor->processCommand(body);

    if(response == -1) {
        server.send(400, "text/plain", "Body invalid");
        return;
    } 

    server.send(200, "text/plain", "OK");
}