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
