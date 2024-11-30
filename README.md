# Botão de Pânico com ESP32
Este projeto consiste em um sistema de botão de pânico desenvolvido com ESP32, configurável para:

Caso 1: Simulação no Wokwi, um ambiente de prototipagem virtual.
Caso 2: Implementação real utilizando a IDE Arduino e plataformas externas, como CallMeBot para envio de mensagens via WhatsApp.

# Descrição Geral
O Botão de Pânico com ESP32 é projetado para situações de emergência. Quando o botão é pressionado:

Caso 1: No simulador Wokwi, o sistema simula o envio da mensagem exibindo-a no Monitor Serial e piscando um LED virtual.
Caso 2: Na implementação física, o ESP32 envia mensagens reais para contatos configurados via CallMeBot, utilizando a conexão WiFi.

# **Caso 1: Prototipagem no Wokwi**

Faça a simulação diretamente no Wokwi clicando no [projeto pronto aqui](https://wokwi.com/projects/415930697193758721).

Ou, caso prefira, faça o download da pasta **Caso 1 - Projeto MIC014Aula01** do repositório clicando neste [link](https://github.com/nataliaalmada/MIC014HandsOnBasic/tree/main/Caso%201%20-%20Projeto%20MIC014Aula01). Após o download, você pode importar o projeto manualmente para a plataforma Wokwi: [https://wokwi.com](https://wokwi.com).

---

## **Imagem da Simulação**

Veja abaixo uma captura de tela da mensagem de alerta simulada:

![Mensagem de Alerta Simulada](https://github.com/nataliaalmada/MIC014HandsOnBasic/blob/main/Caso%201%20-%20Projeto%20MIC014Aula01/Mensagem%20de%20Alerta%20Simula%C3%A7%C3%A3o%20Aula%201%20MIC014.png)
