#include <DHT.h>


const int pinoDHT = 23;
DHT dht(pinoDHT, DHT22);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  // pega as informações de temperatura e umidade do sensor dht
  float temp = dht.readTemperature();
  float umi = dht.readHumidity();
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println("°C");
  Serial.print("Umidade: ");
  Serial.print(umi);
  Serial.println("%");
  Serial.println("-------");

  
  delay(3000);
}
