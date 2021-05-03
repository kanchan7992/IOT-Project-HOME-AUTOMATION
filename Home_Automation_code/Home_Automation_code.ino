#include<ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>

char auth[] = " Fxu84-44_sJFViPlXb34rtQS5XMgaasP";
#define ssid "Vivo V20" //can also write const char/string ="saksham"  
#define pass "kanchanr"

WiFiServer server(80);

int m=0;
int n=0;
int p=0;
void setup(){
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
WiFi.begin(ssid, pass);
Serial.println("Connecting to N/W ...");
while(WiFi.status()!=WL_CONNECTED){
delay(400);
Serial.print(".");
}
Serial.println("");
Serial.println("Connected to N/W");
server.begin();
Serial.println("");
Serial.print("Use this IP: ");
Serial.print(WiFi.localIP());
pinMode(D0, OUTPUT);
digitalWrite(D0,0);
pinMode(D1, OUTPUT);
digitalWrite(D1,0);
pinMode(D2, OUTPUT);
digitalWrite(D2,0);

}

void loop(){
 Blynk.run();
 WiFiClient client =server.available();
 if(!client){
return;
}

String request = client.readStringUntil('\r');

if(request.indexOf("/light1")!=-1){
m=!m;
digitalWrite(D0, m);
}

if(request.indexOf("/light2")!=-1){
n=!n;
digitalWrite(D1, n);
}
if(request.indexOf("/light3")!=-1){
p=!p;
digitalWrite(D2, p);
}

client.print("<!DOCTYPE html>\n");
client.print("<html>\n");
client.print("<head>\n");
client.print("\t<title>My Dashboard</title>\n");
client.print("</head>\n");
client.print("<body><center>\n");
client.print("\t<h2 style= \"color : red\">HOME AUTOMATION</h2>\n");
client.print("     <div style=\"margin-top: 30px; margin-bottom: 50px; background-color: cyan; margin-right: 350px; margin-left: 350px; padding-top: 80px; padding-bottom : 80px;\">\n");
client.print("     \t\t<a href=\"light1\"><button style= \"background-color : blue; color : white;\">Light 1</button></a>");
client.print("     <a href=\"light2\"><button style= \"background-color : blue; color : white;\">Light 2 </button></a>");
client.print("     <a href=\"light3\"><button style= \"background-color : blue; color : white;\">Light 3</button></a><p style= \"color : red;\">STATUS : <br></p> ");
if(m==1)
client.print("LIGHT 1 On<br><br>");
if(m==0)
client.print("LIGHT 1 Off<br><br>");
if(n==1)
client.print("LIGHT 2 On<br><br>");
if(n==0)
client.print("\t\tLIGHT 2 Off<br><br>");
if(p==1)
client.print("\t\tLIGHT 3 On<br><br>");
if(p==0)
client.print("\t\tLIGHT 3 Off<br><br>");

client.print(" </div></center>\n");
client.print("     <marquee style=\"color: red;\">Your Homeautomation subscription is ending next month on 10th Nov, 2020.</marquee>\n");
client.print("</body>\n");
client.print("</html>");
}
/*WiFi.status();
IF CONNECTED = WL_CONNECTED
NOT CONNECTED = NO_SHIELD
DISCONNECT = WL_DISCONNECTED
*/
