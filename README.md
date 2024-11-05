## Cap 12 - A Eletrônica de uma IA
### Objetivo
O objetivo deste projeto é criar um sistema inteligente de monitoramento agrícola utilizando um microcontrolador ESP32 e quatro sensores diferentes; o primeiro sensor de umidade e temperatura (DHT22), o segundo um sensor de ultrassom (HC-SR04), o terceiro um sensor de movimento PIR, e por último um sensor de luz LDR, além destes sensores, são utilizados 2 LEDs, dois resistores de 150 ohms, um buzzer e por fim um botão.

### Sensor DHT (22)
O sensor DHT22 utilizado para medir a temperatura e umidade do ambiente, ele será colocado ao decorrer da lavoura, quando a temperatura estiver acima de 33 graus celsius ou a umidade estiver abaixo de 40% o processo de irrigação será iniciado.

### Sensor HC-SR04
O Sensor HC-SR04 é utilizado para medir o volume de água dos reservatórios, ele será colocado no dentro no topo de cada reservatório, ele calculara a distância da água até o topo, quando o sensor detectar que a água estiver próxima do topo (quando o sensor retornar um valor menor que 25) ele iniciara o sistema de irrigação, caso o sensor retornar um valor acima de 200 uma mensagem será enviada alertando sobre os níveis dos reservatórios.

### Sensor PIR
O sensor PIR irá detectar pessoas e animais que estiverem no meio da plantação, ele será colocado junto aos redores da plantação e junto com o sensor DHT, caso o sensor detecte alguém uma mensagem será enviada, um led e um buzzer será ativada alertando que o sensor detectou algo, para desativar as mensagens, o led e o buzzer um botão terá que ser pressionado.

### Sensor LDR
No começo do processo de irrigação o sensor LDR irá retornar o valor do fluxo luminoso, caso esse valor seja inferior do que 150 o processo irá utilizar mais água, caso o valor seja maior que 200 o processo irá utilizar menos água.

