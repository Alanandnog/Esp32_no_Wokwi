/* pegue o código da pag https://github.com/knolleary/pubsubclient/blob/master/examples/mqtt_esp8266/mqtt_esp8266.ino#L105
é faça asalterações nos lugares que eu vou marcar


*/

//.
#include <WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

//., usuario do esp32
const char* ssid = "Wokwi-GUEST";
const char* password = "";
//.
const char* mqtt_server = "test.mosquitto.org";

// recebem os dados
String my_payload;
String my_topic;

//.
WiFiClient WOKWi_Client;
PubSubClient client(WOKWi_Client);


void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  String conc_payload;

  for (int i = 0; i < length; i++) {
    conc_payload += ((char)payload[i]);

  }
  my_payload = conc_payload;
  my_topic =  topic;
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
   
    // Attempt to connect
    if (client.connect("WOKWi_Client")) {
      Serial.println("connected");
      
      client.subscribe("ESP32_RECEBE");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(2, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  pinMode(15, OUTPUT);  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}
// TEM QUE JOGAR DENTRO DO LOOP
void Conexao_WIFI()
{
if(WiFi.status()){
// se tiver wifi o led que está no pino 2 recebe high
digitalWrite(2, HIGH);
}else{
digitalWrite(2, LOW);
}
}


void Conexao_MQTT()
{
if(client.connected()){
// se tiver wifi o led que está no pino 15 recebe high
digitalWrite(15, HIGH);
}else {
digitalWrite(15, LOW);
}
}


void loop() {

  
  reconnect(); 
  client.loop();
  Conexao_MQTT();
  Conexao_WIFI();

}