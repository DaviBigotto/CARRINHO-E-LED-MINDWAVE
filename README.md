# CARRINHO E LED MINDWAVE

### 1. DESCRIÇÃO:

 ● Nosso projeto foi com base na utilização do aparelho mindwave, para a captação de ondas cerebrais e medir o nível de concentração. Sendo assim, fizemos um carrinho básico de arduino com motores DC para se mover, e o módulo  hc-05 para realizar a conexão bluetooth com o mindwave. Além do carrinho, emparelhamos 4 Leds em sequencia na protoboard, e, utilizando também um arduino e o módulo hc-05, conforme o nível de concentração da pessoa, os leds vão se acendendo gradualmente. Já o carrinho, ao atingir o nível de 55% e concentração, ele anda para frente. Para realizar a conexão do mindwave com os módulos HC-05, necessitamos utilizar os comandos AT, para pegar a serial do mindwave.

---

### 2. BIBLIOTECAS UTILIZADAS:

Utilizamos a linguagem do arduino para a realização dos códigos, e utilizamos algumas bibliotecas como:

#include <SoftwareSerial.h>

#include <Mindwave.h> 
  
  -> [Mindwave.h](https://github.com/orgicus/Mindwave.git), Baixar o Arquivo Zipado e adicionar no aplicativo do arduino!

---

### 3. COMANDOS AT
- AT+UART=57600,0,0
- AT+ROLE=1
- AT+PSWD="0000"
- AT+CMODE=0
- AT+BIND=xxxx,xx,xxxxxx (endereço MAC do Mindwave, utilizando esse formato, obtenha conectando ele ao bluetooth de outro dispositivo)
- AT+IAC=9E8B33
- AT+CLASS=0
- AT+INQM=1,9,48
---

### 4. COMANDOS DOS LEDS:

Código No arquivo "ComandoDosLEDS.ino"

---

### 5. COMANDOS DO CARRINHO:

Código no arquivo "ComadoDoCarrinho.ino"

---

### 6. COMPONENTES UTILIZADOS:

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


---
### 7. FUNCIONAMENTO:

  ● O Mindwave capta a atividade elétrica do cérebro e calcula o nível de concentração do usuário. Esse nível é enviado ao Arduino, que, por sua vez, controla o motor DC do carrinho. Quando a concentração aumenta, o carrinho avança; quando a concentração diminui, o carrinho para. O mesmo ocorre para os Leds, conforme aumenta, acende mais leds, caso diminua a concentração, os leds apagam.

### 8. OBJETIVOS:
  
  ● Demonstrar a relação entre atividade cerebral e comportamento físico.
  
  ● Oferecer uma experiência educativa sobre neurociência e tecnologia.
  
  ● Demonstrar a infinidade de ideais e funções que podemos implementar para ajudar pessoas necessitadas, como uma mão robótica, para uma pessoa que não possui mão.


---
### 9. RESULTADOS ESPERADOS:

  ● Promover a capacidade que a tecnologia possui de mudar vidas e realizar adaptações para casos necessitados, pessando na temática pós apocaliptica da Fecart.

