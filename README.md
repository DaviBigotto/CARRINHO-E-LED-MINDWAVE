#DESCRIÇÂO:
 ● Nosso projeto foi com base na utilização do aparelho mindwave, para a captação de ondas cerebrais e medir o nível de concentração. Sendo assim, fizemos um carrinho básico de arduino com motores DC para se mover, e o módulo  hc-05 para realizar a conexão bluetooth com o mindwave. Além do carrinho, emparelhamos 4 Leds em sequencia na protoboard, e, utilizando também um arduino e o módulo hc-05, conforme o nível de concentração da pessoa, os leds vão se acendendo gradualmente. Já o carrinho, ao atingir o nível de 55% e concentração, ele anda para frente. Para realizar a conexão do mindwave com os módulos HC-05, necessitamos utilizar os comandos AT, para pegar a serial do mindwave.

❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐

#BIBLIOTECAS UTILIZADAS:
Utilizamos a linguagem do arduino para a realização dos códigos, e utilizamos algumas bibliotecas como:
#include <SoftwareSerial.h>
#include <Mindwave.h>

❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐

#COMANDOS AT
/*
  *Configuration through AT Commands for HC-05
  *Pairing  Headset Neurosky Mindwave Mobile with Arduino
  *Commands:
  *   AT+UART=57600,0,0
  *   AT+ROLE=1
  *   AT+PSWD="0000"
  *   AT+CMODE=0
  *   AT+BIND=0081,F9,12CF79
  *   AT+IAC=9E8B33
  *   AT+CLASS=0
  *   AT+INQM=1,9,48
  *   
  *   Lozano Ramirez Angel Ivan
  *   02.07.2018
  *   NOTE: Set the Serial monitor with NL&CR and 9600 baud
*/


#include <SoftwareSerial.h>
SoftwareSerial BT(11,10); //Rx/Tx
 
void setup(){
  BT.begin(38400);
  Serial.begin(9600);
}
 
void loop(){
  if( BT.available() ) Serial.write( BT.read() );
  if( Serial.available() ) BT.write(Serial.read());
}

❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐

COMANDOS DOS LEDS:
#include <Mindwave.h>  // Inclui a biblioteca Mindwave
Mindwave mindwave;     // Inicializa o objeto Mindwave


// Definição dos pinos dos LEDs
int led1 = 2;  // LED 1 conectado ao pino 2
int led2 = 3;  // LED 2 conectado ao pino 3
int led3 = 4;  // LED 3 conectado ao pino 4
int led4 = 5;  // LED 4 conectado ao pino 5


void setup() {
  Serial.begin(57600);  // Inicia a comunicação serial a 57600 baud rate
 
  // Configura os pinos dos LEDs como saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);


  Serial.println("Mindwave and LED control initialized");
}


// Função chamada quando novos dados do Mindwave estão disponíveis
void onMindwaveData() {
  int attentionValue = mindwave.attention();  // Lê o nível de atenção


  // Verifica se o nível de atenção é 0 ou 1 e exibe "Carregando"
  if (attentionValue == 0 || attentionValue == 1) {
    Serial.println("Carregando...");
  } else {
    // Mostra o valor de atenção no monitor serial
    Serial.print("Attention value: ");
    Serial.println(attentionValue);


    // Controle dos LEDs baseado no nível de atenção
    if (attentionValue >= 0 && attentionValue <= 25) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    }
    else if (attentionValue > 25 && attentionValue <= 50) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    }
    else if (attentionValue > 50 && attentionValue <= 75) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
    }
    else if (attentionValue > 75 && attentionValue <= 100) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
    }
  }
}


void loop() {
  // Atualiza os dados do Mindwave e chama a função onMindwaveData quando há novos dados
  mindwave.update(Serial, onMindwaveData);
}

❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐

COMANDOS DO CARRINHO:
#include <SoftwareSerial.h>
#include <Mindwave.h>


Mindwave mindwave;   // Inicializa o Mindwave


// Pinos do módulo L298N para controlar os motores
const int motor1Pin1 = 9; // Motor A - Pino 1
const int motor1Pin2 = 8; // Motor A - Pino 2
const int motor2Pin1 = 7; // Motor B - Pino 1
const int motor2Pin2 = 6; // Motor B - Pino 2


void setup() {
  // Configuração dos pinos dos motores
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);


  // Inicializa a comunicação serial para o Mindwave
  Serial.begin(57600);
  delay(500); // Pequeno delay para garantir a inicialização


  Serial.println("Mindwave Ready!");
}


// Função para mover o carrinho para frente
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}


// Função para parar os motores
void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}


// Função para exibir o nível de atenção e controlar o carrinho
void onMindwaveData() {
  int attentionLevel = mindwave.attention(); // Obter o valor de atenção


  if (attentionLevel == 0 || attentionLevel == 1) {
    Serial.println("Carregando..."); // Exibir "Carregando" se o valor for 0 ou 1
  } else {
    // Exibir o nível de atenção
    Serial.print("Nível de atenção: ");
    Serial.println(attentionLevel);


    // Se o nível de atenção for maior que 45, mover o carrinho; caso contrário, parar
    if (attentionLevel > 45) {
      moveForward();
      Serial.println("Movendo para frente");
    } else {
      stopMotors();
      Serial.println("Parado");
    }
  }
}


void loop() {
  // Atualiza os dados do Mindwave no loop principal
  mindwave.update(Serial, onMindwaveData);
}

❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐

COMPONENTES UTILIZADOS:
● 2 Arduinos
● 2 Motores DC
● Aparelho Mindwave
● Chassi do carrinho
● Fonte de alimentação do arduino(Bateria 9V)
● 4 pilhas AA para alimentar os motores DC
● 4 Leds
● Protoboard
● Jumpers
● Resistores
● Shield PonteH L298n

❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐

Funcionamento:
  ● O Mindwave capta a atividade elétrica do cérebro e calcula o nível de concentração do usuário. Esse nível é enviado ao Arduino, que, por sua vez, controla o motor DC do carrinho. Quando a concentração aumenta, o carrinho avança; quando a concentração diminui, o carrinho para. O mesmo ocorre para os Leds, conforme aumenta, acende mais leds, caso diminua a concentração, os leds apagam.

Objetivos:
  ● Demonstrar a relação entre atividade cerebral e comportamento físico.
  ● Oferecer uma experiência educativa sobre neurociência e tecnologia.
  ● Demonstrar a infinidade de ideais e funções que podemos implementar para ajudar pessoas necessitadas, como uma mão robótica, para uma pessoa que não possui mão.

❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐ ❑ ❒ ❏ ❐ ❏ ❐

Resultados Esperados:
  ● Promover a capacidade que a tecnologia possui de mudar vidas e realizar adaptações para casos necessitados, pessando na temática pós apocaliptica da Fecart.
