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


# **Caso 2: Implementação Real com IDE Arduino**
> **Disclaimer:** Este projeto foi desenvolvido e testado em ambiente virtual, portanto, pode ser que alguns ajustes sejam necessários para garantir o funcionamento no hardware físico, já que o circuito não foi montado na vida real. Caso identifique melhorias ou problemas, sinta-se à vontade para contribuir ou relatar.

---
O código-fonte para a implementação real do projeto está disponível no seguinte arquivo:  
[ProjetoMIC014Aula01ESP32.ino](https://github.com/nataliaalmada/MIC014HandsOnBasic/blob/main/Caso%202%20-%20Projeto%20MIC014Aula01/ProjetoMIC014Aula01ESP32.ino).

---

## **Configurações Necessárias para Implementação**

Antes de compilar e carregar o código no ESP32, certifique-se de modificar os seguintes dados no arquivo para adequá-los à sua rede WiFi e conta do CallMeBot:

1. **Credenciais da Rede WiFi:**
   - Substitua `SEU_SSID` e `SUA_SENHA` pelos dados da sua rede:
     ```cpp
     const char* ssid = "SEU_SSID";
     const char* password = "SUA_SENHA";
     ```

2. **Dados do CallMeBot:**
   - Atualize o número de WhatsApp e a API Key fornecida pelo CallMeBot:
     ```cpp
     String phoneNumber = "SEU_NUMERO_WHATSAPP";
     String apiKey = "SUA_APIKEY";
     ```

3. **Mensagem Personalizada:**
   - Altere a mensagem que será enviada:
     ```cpp
     String mensagem = "ALERTA! Estou em perigo. Preciso de ajuda imediatamente.";
     ```

---

## **Passos para Implementação**
1. **Configuração do Ambiente:**
   - Instale a [IDE Arduino](https://www.arduino.cc/en/software).
   - Configure a placa ESP32 na IDE.

2. **Montagem do Circuito:**
   - Conecte os componentes ao ESP32:
     - Botão no GPIO 21.
     - LED externo (com resistor de 100Ω) no GPIO 23.
     - LED interno no GPIO 2.

3. **Teste e Upload:**
   - Abra o arquivo `ProjetoMIC014Aula01ESP32.ino` na IDE Arduino.
   - Faça as modificações necessárias e carregue o código no ESP32.
   - Pressione o botão e verifique o funcionamento:  
     - O LED externo piscará durante o envio.
     - A mensagem será enviada para o WhatsApp configurado.

---

Para dúvidas ou problemas abra uma **issue**. 😊
