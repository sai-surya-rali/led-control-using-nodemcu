#include<ESP8266WebServer.h>  
ESP8266WebServer server;
const char username[]="train";
const char password[]="padhlokuch";
#define pin 16
void setup()
{pinMode(pin,OUTPUT);
Serial.begin(115200);

WiFi.softAP(username,password);//create access point
Serial.println('connected');
IPAddress myIP=WiFi.softAPIP();
Serial.print("AP IP address: ");
Serial.println(myIP);
server.begin();
server.on("/led",led);
//server.on("/check",check);
}
void loop()
{server.handleClient();
}
void led()
{String myhtml="<html><head><title>Program</title></head><body style=\"background-color: red\"><h1><centre>TASK</centre></h1><form>What do you want to do?<br> <button type=\"submit\" name=\"state\" value=\"0\">ON</button><br><button type=\"submit\" name=\"state\" value=\"1\">OFF</button></form></body></html>";
   server.send(200,"text/html",myhtml);
   if(server.arg("state")=="1")
    {
      digitalWrite(pin,HIGH);
    }
    else
    {
      digitalWrite(pin,LOW);
    }
}
