#include <DHT.h>


int pinoDHT =  23;
int trigPin =  22;
int echoPin =  21;


DHT dht(pinoDHT, DHT22);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  float temp = dht.readTemperature();
  float umi = dht.readHumidity();

  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin,HIGH);
  int distance = duration * 0.034/2;

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println("°C");
  Serial.print("Umidade: ");
  Serial.print(umi);
  Serial.println("%");


  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // this speeds up the simulation
}
