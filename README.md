# 🚀 CapsuleGuard
### Sistema IoT para Monitoramento de Cápsula Espacial

> **FIAP — Global Solution 2026 · 1º Semestre · Ciência da Computação**

---

## 📡 Sobre o Projeto

O **CapsuleGuard** é um sistema embarcado baseado em IoT desenvolvido para monitorar em tempo real as condições físicas internas de uma cápsula espacial durante uma missão simulada.

O sistema coleta dados de temperatura, luminosidade e vibração, processa as leituras e emite alertas automáticos quando qualquer variável ultrapassa os limites de segurança estabelecidos.

---

## 🛰️ Variáveis Monitoradas

| Variável | Sensor (Físico) | Sensor (Tinkercad) | Pino |
|---|---|---|---|
| Temperatura | DHT11 | TMP36 | D2 / A0 |
| Luminosidade | LDR | LDR | A0 |
| Vibração | Potenciômetro* | Potenciômetro* | A1 |

> *Por limitação de hardware e da plataforma Tinkercad, o potenciômetro simula um acelerômetro. Em produção seria substituído por um MPU-6050 via I2C.

---

## ⚠️ Lógica de Alertas

### 🌡️ Temperatura
```
>= 25°C   → MOTORES MUITO QUENTES
>= 24.5°C → MOTORES AQUECENDO
< 24.5°C  → Temperatura OK
```

### 💡 Luminosidade
```
<= 100         → LADO ESCURO DA ORBITA
< 200 e caindo → ENTRANDO NO LADO ESCURO DA ORBITA
< 200 e subindo→ SAINDO DO LADO ESCURO DA ORBITA
>= 200         → LADO CLARO DA ORBITA
```

### 📳 Vibração
```
= 1.0  → IMPACTO DETECTADO
>= 0.6 → PREPARAR PARA IMPACTO
>= 0.3 → POSSIVEL IMPACTO
< 0.3  → Vibração OK
```

---

## 🔧 Componentes

**Hardware Físico:**
- Arduino UNO
- Sensor DHT11 (temperatura)
- Sensor LDR (luminosidade)
- Potenciômetro (vibração simulada)
- Resistor 10kΩ

**Simulação Tinkercad:**
- Arduino UNO
- Sensor TMP36 (temperatura)
- Sensor LDR (luminosidade)
- Potenciômetro (vibração simulada)
- Resistor 10kΩ

---

## 💻 Como Rodar

### No Tinkercad
1. Acesse o link da simulação abaixo
2. Clique em **"Iniciar Simulação"**
3. Abra o **Serial Monitor**
4. Clique nos componentes para alterar os valores

### No Hardware Físico
1. Clone este repositório
```bash
git clone https://github.com/seu-usuario/capsuleguard.git
```
2. Instale a biblioteca **DHT sensor library** da Adafruit no Arduino IDE
3. Abra o arquivo `capsuleguard.ino`
4. Conecte o Arduino e faça o upload
5. Abra o Serial Monitor em **9600 baud**

---

## 📁 Estrutura do Repositório

```
capsuleguard/
│
├── capsuleguard.ino       # Código principal (hardware físico)
├── capsuleguard_sim.ino   # Código adaptado para Tinkercad (TMP36)
├── README.md              # Este arquivo
└── docs/
    └── relatorio.pdf      # Relatório técnico completo
```

---

## 🔗 Links

- 🔴 [Simulação no Tinkercad](https://www.tinkercad.com/things/bYJ9Ix8977m-fisico-gs-computer-organization?sharecode=undefined)
- 🎥 [Vídeo no YouTube](http://youtube.com/watch?v=tXlYlk_wyR4) 

---

## 🚀 Melhorias Futuras

- [ ] Substituir potenciômetro pelo acelerômetro **MPU-6050**
- [ ] Adicionar **display LCD 16x2** para exibição visual
- [ ] Adicionar **buzzer** com frequências diferentes por tipo de alerta
- [ ] Comunicação **WiFi via ESP32** com dashboard web
- [ ] **Log em cartão SD** para análise pós-missão
- [ ] Sensor de pressão **BMP280**

---

## 📚 Tecnologias

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

---

## 👨‍🚀 Autor

Desenvolvido como parte do **Global Solution 2026** da FIAP.

> *"O próximo grande sistema não está na nuvem — está em órbita."*
