#include <DHT.h>


int pinoDHT =  23;
int trigPin =  22;
int echoPin =  21;
int inputPin = 34;
int pirLED  = 19;
int ldrPin = 33;
int sonarLED = 18;
int buzzerPin = 5;
int buttonPin = 17;
DHT dht(pinoDHT, DHT22);

void setup() {

  Serial.begin(115200);
  // inicia o sensor dht
  dht.begin();
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(inputPin, INPUT);
  pinMode(pirLED, OUTPUT);
  pinMode(sonarLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // pega as informações de temperatura e umidade do sensor dht
  float temp = dht.readTemperature();
  float umi = dht.readHumidity();
  
  // pega a informação do sensor PIR
  int val = digitalRead(inputPin); 
  
  //pega informação do sensor de luz
  int ldrvalue = analogRead(ldrPin);

  int buttonState = HIGH;

  //seta os LED em LOW
  digitalWrite(pirLED, LOW);
  digitalWrite(sonarLED, LOW);

  // ativa o echosonar
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);


  // calcula a distancia de acordo com o tempo
  long duration = pulseIn(echoPin,HIGH);
  int distance = duration * 0.034/2;

  // imprime as informações coletados pelo sensor dht2
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println("°C");
  Serial.print("Umidade: ");
  Serial.print(umi);
  Serial.println("%");

  // imprime a distancia
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Nivel de luz: ");
  Serial.println(ldrvalue);
  Serial.println("------");

  // caso a distancia do sonar for maior que 200 uma mensagem  sera enviada alertando sobre o nivel de água
  if(distance > 200){
    Serial.println("Reservatorios abaixo dos niveis recomendados");
  }


  // caso a distancia que o sonar retornar for menor que 25, a temperatura seja maior que 35 
  // e a umidade seja menor que 45 a irrigação será acionada
  if(distance < 25 || temp > 35 || umi < 45){
    digitalWrite(sonarLED, HIGH);
    Serial.println("Irrigação Iniciada");
    // checa a incidencia solar, caso o valor retornado pelo sensor ldr seja menor que 100 
    // mais agua será utilizado para a irrigação
      if(ldrvalue < 100){
        Serial.println("Utilizando mais água para a irrigação");
      }
    //caso o valor retonardo pelo ldr seja maior que 200 menos agua será utilizado pela irrigação
      if(ldrvalue > 200){
        Serial.println("Utilizando menos água para a irrigação");
      }
  }

  // caso o sensor pir detectar alguém um led vermelho irá acender, um buzzer será ativado,  e uma mensagem será enviada sobre 
  // o movimento detectado, e o buzzer, led e a mesnagem só será desativada quando o botÃo for pressionado
  if(val == HIGH){
    digitalWrite(pirLED, HIGH);
    // um buzzer será ativado e somente desligado quando o botão for pressionado
    while(buttonState == HIGH){
      tone(buzzerPin, 1500);
      Serial.println("Movimento Detectado ");
      buttonState = digitalRead(buttonPin);
    }
    noTone(buzzerPin);
    digitalWrite(pirLED, LOW);
  }


  
  delay(2000);
}
