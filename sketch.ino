#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h> 

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "industrial.api.ubidots.com";
const int mqtt_port = 8883;
const char* mqtt_user = "";
const char* mqtt_pass = "";

WiFiClientSecure espClient;
PubSubClient client(espClient);

void connectMQTT() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    if (client.connect("esp32-client", mqtt_user, mqtt_pass)) {
      Serial.println(" conectado!");
    } else {
      Serial.print(" falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente...");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" conectado!");

  espClient.setInsecure();
  client.setServer(mqtt_server, mqtt_port);

  connectMQTT();
}

void loop() {
  client.loop();

  float temperatura = random(200, 350) / 10.0;
  float umidade = random(400, 800) / 10.0;
  int luz = random(0, 100);
  int status = 1;

  String payload = "{";
  payload += "\"temperatura\":" + String(temperatura) + ",";
  payload += "\"umidade\":" + String(umidade) + ",";
  payload += "\"luz\":" + String(luz) + ",";
  payload += "\"status\":" + String(status);
  payload += "}";

  client.publish("/v1.6/devices/esp32-mqtt-stream", payload.c_str());

  Serial.println(payload);
  delay(5000);
}
