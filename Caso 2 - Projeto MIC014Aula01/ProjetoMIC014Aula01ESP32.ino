#include <WiFi.h>          // Biblioteca para conectar o ESP32 ao WiFi
#include <HTTPClient.h>    // Biblioteca para fazer requisições HTTP
#include <UrlEncode.h>     // Biblioteca para codificar texto em formato de URL

// Credenciais da rede WiFi
const char* ssid = "Rosa Azul";        // Nome da rede WiFi
const char* password = "Rosaazul3090"; // Senha do WiFi

// Definição dos pinos do botão e LEDs
#define botao 21   // Pino de conexão para o botão
#define led1 23    // Pino para o LED externo na protoboard
#define led2 2     // Pino para o LED interno do ESP32

bool flag = true;  // Variável de controle para evitar múltiplos envios da mensagem

// Número de telefone e chave API para CallMeBot
String phoneNumber1 = "559581117758"; // Seu número de WhatsApp em formato internacional
String apiKey1 = "2030323";           // Sua chave API do CallMeBot

// Função para enviar a mensagem via CallMeBot API
void sendMessage(String phoneNumber, String apiKey, String message) {
    // Monta a URL com os parâmetros fixos
    String url = "https://api.callmebot.com/whatsapp.php?phone=559581117758&apikey=2030323&text=" + urlEncode(message);

    HTTPClient http;  // Cria um objeto HTTPClient
    http.begin(url);  // Inicia a conexão com a URL

    // Adiciona o cabeçalho indicando que a requisição está no formato x-www-form-urlencoded
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Envia a requisição GET
    int httpResponseCode = http.GET();

    // Verifica o código de resposta HTTP
    if (httpResponseCode == 200) { 
        Serial.println("Mensagem enviada com sucesso");
    } else {
        Serial.println("Erro no envio da mensagem");
        Serial.print("Código de resposta HTTP: ");
        Serial.println(httpResponseCode);
    }

    http.end();  // Libera os recursos usados pela requisição HTTP
}

void setup() {
    Serial.begin(115200);  // Inicializa a comunicação serial

    // Configuração dos pinos
    pinMode(botao, INPUT_PULLUP); // Configura o pino do botão como entrada com pull-up interno
    pinMode(led1, OUTPUT);        // Configura o pino do LED externo como saída
    pinMode(led2, OUTPUT);        // Configura o pino do LED interno como saída

    digitalWrite(led1, LOW);  // Inicialmente, os LEDs ficam apagados
    digitalWrite(led2, LOW);

    // Conexão WiFi
    WiFi.begin(ssid, password);  // Inicia a conexão com o WiFi
    Serial.println("Conectando ao WiFi...");

    // Enquanto não estiver conectado ao WiFi, pisca o LED interno
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);                      // Aguarda 500 ms
        Serial.print(".");               // Imprime um ponto para indicar tentativa de conexão
        digitalWrite(led2, !digitalRead(led2)); // Inverte o estado do LED interno
    }

    // Quando conectado ao WiFi
    Serial.println("\nConectado ao WiFi!");
    Serial.print("Endereço IP: ");
    Serial.println(WiFi.localIP());  // Exibe o IP local do ESP32 na rede
    digitalWrite(led2, HIGH);       // Mantém o LED interno aceso indicando conexão bem-sucedida
}

void loop() {
    int estado_botao = digitalRead(botao); // Lê o estado do botão

    if (estado_botao == LOW) { // Se o botão estiver pressionado
        Serial.println("Botão pressionado, enviando mensagem de perigo...");
        digitalWrite(led1, HIGH); // Acende o LED externo enquanto a mensagem é enviada

        if (flag) { // Verifica se a flag está ativada (evita envio repetido)
            sendMessage(phoneNumber1, apiKey1, "ALERTA! Estou em perigo. Preciso de ajuda imediatamente.");
            flag = false; // Desativa a flag após o envio
        }
    } else {
        flag = true;         // Reseta a flag se o botão não estiver pressionado
        digitalWrite(led1, LOW); // Apaga o LED externo
    }
}
