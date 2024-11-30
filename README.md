# Botão de Pânico com ESP32
Este projeto consiste em um sistema de botão de pânico desenvolvido com ESP32, configurável para:

Caso 1: Simulação no Wokwi, um ambiente de prototipagem virtual.
Caso 2: Implementação real utilizando a IDE Arduino e plataformas externas, como CallMeBot para envio de mensagens via WhatsApp.

# Descrição Geral
O Botão de Pânico com ESP32 é projetado para situações de emergência. Quando o botão é pressionado:

Caso 1: No simulador Wokwi, o sistema simula o envio da mensagem exibindo-a no Monitor Serial e piscando um LED virtual.
Caso 2: Na implementação física, o ESP32 envia mensagens reais para contatos configurados via CallMeBot, utilizando a conexão WiFi.

# Caso 1: Prototipagem no Wokwi
