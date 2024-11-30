#include <WiFi.h>          // Biblioteca para conectar o ESP32 ao WiFi (simulação do WiFi)

// Credenciais da rede WiFi (para exibir como conectado, mesmo sem função prática aqui)
const char* ssid = "Rosa Azul";        // Nome da rede WiFi
const char* password = "Rosaazul3090"; // Senha do WiFi

// Definição dos pinos do botão e LEDs
#define botao 21   // Pino de conexão para o botão
#define led1 23    // Pino para o LED externo na protoboard
#define led2 2     // Pino para o LED interno do ESP32

bool flag = true;  // Variável de controle para evitar múltiplos envios da mensagem

// Função para simular envio de mensagem
void simulateSendMessage(String message) {
    // Simula o processo de envio
    Serial.println("Enviando mensagem...");
    Serial.println("Mensagem: " + message);
    for (int i = 0; i < 6; i++) { // Faz o LED piscar durante o envio (6 vezes)
        digitalWrite(led1, HIGH); // Acende o LED externo
        delay(200);               // Aguarda 200ms
        digitalWrite(led1, LOW);  // Apaga o LED externo
        delay(200);               // Aguarda 200ms
    }
    Serial.println("Mensagem simulada como enviada com sucesso!");
}

void setup() {
    Serial.begin(115200);  // Inicializa a comunicação serial

    // Configuração dos pinos
    pinMode(botao, INPUT_PULLUP); // Configura o pino do botão como entrada com pull-up interno
    pinMode(led1, OUTPUT);        // Configura o pino do LED externo como saída
    pinMode(led2, OUTPUT);        // Configura o pino do LED interno como saída

    digitalWrite(led1, LOW);  // Inicialmente, os LEDs ficam apagados
    digitalWrite(led2, LOW);

    // Simulação de conexão WiFi
    Serial.println("Conectando ao WiFi (simulado)...");
    delay(1000); // Simula tempo de conexão
    Serial.println("Conexão WiFi simulada com sucesso!");
    Serial.println("Endereço IP: 192.168.1.100 (simulado)");
    digitalWrite(led2, HIGH); // LED interno aceso indicando "conexão bem-sucedida"
}

void loop() {
    int estado_botao = digitalRead(botao); // Lê o estado do botão

    if (estado_botao == LOW) { // Se o botão estiver pressionado
        Serial.println("Botão pressionado, preparando para enviar mensagem...");
        if (flag) { // Verifica se a flag está ativada (evita envio repetido)
            String mensagem = "ALERTA! Estou em perigo. Preciso de ajuda imediatamente.";
            simulateSendMessage(mensagem); // Chama a função que simula o envio
            flag = false; // Desativa a flag após o envio
        }
    } else {
        flag = true;         // Reseta a flag se o botão não estiver pressionado
        digitalWrite(led1, LOW); // Apaga o LED externo
    }
}
