# 📡 Projeto IoT com ESP32, MQTT e Ubidots

## 📘 Descrição do Projeto
Este projeto tem como objetivo demonstrar a comunicação de um dispositivo IoT (ESP32) com a nuvem utilizando o protocolo **MQTT**.  
Os dados simulados de sensores são enviados para a plataforma **Ubidots**, onde são armazenados e visualizados em tempo real por meio de dashboards interativos.

O projeto foi desenvolvido utilizando o simulador **Wokwi**, permitindo a validação completa da comunicação sem a necessidade de hardware físico.

---

## 🎯 Objetivos
- Implementar comunicação MQTT segura (TLS)
- Simular coleta de dados de sensores no ESP32
- Enviar dados para a nuvem (Ubidots)
- Visualizar dados em tempo real em dashboards
- Compreender o funcionamento de brokers MQTT e plataformas IoT

---

## 🧰 Tecnologias Utilizadas
- **ESP32**
- **Wokwi Simulator**
- **MQTT (Message Queuing Telemetry Transport)**
- **Ubidots (plataforma IoT em nuvem)**
- **Arduino IDE / Arduino Framework**
- **WiFiClientSecure**
- **PubSubClient**

---

## ☁️ Arquitetura do Sistema
1. O ESP32 conecta-se à rede Wi-Fi
2. Estabelece conexão segura com o broker MQTT do Ubidots
3. Publica dados simulados em formato JSON
4. O Ubidots recebe, armazena e processa os dados
5. Os dados são exibidos em dashboards na nuvem

---

## 📊 Variáveis Enviadas
O dispositivo envia as seguintes variáveis:

| Variável      | Descrição                         |
|---------------|-----------------------------------|
| temperatura   | Temperatura simulada (°C)         |
| umidade       | Umidade simulada (%)              |
| luz           | Intensidade de luz (0–100)         |
| status        | Estado do dispositivo (On/Off)    |

---

## 📡 Comunicação MQTT
- **Broker MQTT:** `industrial.api.ubidots.com`
- **Porta:** `8883`
- **Protocolo:** MQTT com TLS
- **Formato dos dados:** JSON

Exemplo de payload enviado:
```json
{
  "temperatura": 26.5,
  "umidade": 58.6,
  "luz": 70,
  "status": 1
}
[wokwi](https://wokwi.com/projects/455139108337644545))

