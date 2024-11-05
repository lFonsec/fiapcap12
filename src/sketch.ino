#include <DHT.h>


int pinoDHT =  23;
int trigPin =  22;
int echoPin =  21;
int pirLED  = 19;
int inputPin = 34;
int buzzerPin = 5;
int buttonPin = 17;

DHT dht(pinoDHT, DHT22);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(inputPin, INPUT);
  pinMode(pirLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  float temp = dht.readTemperature();
  float umi = dht.readHumidity();

  int val = digitalRead(inputPin); 
  int buttonState = HIGH;

  
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


    if(val == HIGH){
    digitalWrite(pirLED, HIGH);
    while(buttonState == HIGH){
      tone(buzzerPin, 1500);
      Serial.println("Movimento Detectado ");
      buttonState = digitalRead(buttonPin);
    }
    noTone(buzzerPin);
    digitalWrite(pirLED, LOW);
  }


  delay(1000); // this speeds up the simulation
}
