#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
float luz_ant = 9999.00;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(6, OUTPUT); // buzzer
}

void loop() {
  // leitura dos sensores
  float vibracao    = analogRead(A1) / 1023.00;
  float tensao      = analogRead(A0) * 5.0 / 1024.0;
  float temperatura = (tensao - 0.5) * 100.0;
  float luz         = analogRead(A2); // LDR em A2 para nao conflitar com TMP36

  bool alerta = false;
  String msgLinha1 = "";
  String msgLinha2 = "";

  // --- VIBRACAO ---
  if (vibracao == 1.0) {
    Serial.println("IMPACTO DETECTADO: " + String(vibracao));
    msgLinha1 = "!!IMPACTO!!";
    msgLinha2 = "Vibr: " + String(vibracao);
    alerta = true;
  } else if (vibracao >= 0.6) {
    Serial.println("PREPARAR PARA IMPACTO: " + String(vibracao));
    msgLinha1 = "PREP IMPACTO";
    msgLinha2 = "Vibr: " + String(vibracao);
    alerta = true;
  } else if (vibracao >= 0.3) {
    Serial.println("POSSIVEL IMPACTO: " + String(vibracao));
    msgLinha1 = "POSSIV IMPACTO";
    msgLinha2 = "Vibr: " + String(vibracao);
    alerta = true;
  }

  // --- TEMPERATURA ---
  if (temperatura >= 25) {
    Serial.println("MOTORES MUITO QUENTES: " + String(temperatura));
    msgLinha1 = "MOTOR MT QUENTE";
    msgLinha2 = "Temp: " + String(temperatura) + "C";
    alerta = true;
  } else if (temperatura >= 24.5) {
    Serial.println("MOTORES AQUECENDO: " + String(temperatura));
    msgLinha1 = "MOTOR AQUECENDO";
    msgLinha2 = "Temp: " + String(temperatura) + "C";
    alerta = true;
  }

  // --- LUMINOSIDADE ---
  if (luz <= 100) {
    Serial.println("LADO ESCURO DA ORBITA: " + String(luz));
  } else if (luz < 200 && luz < luz_ant) {
    Serial.println("ENTRANDO NO LADO ESCURO: " + String(luz));
  } else if (luz < 200 && luz > luz_ant) {
    Serial.println("SAINDO DO LADO ESCURO: " + String(luz));
  } else {
    Serial.println("LADO CLARO DA ORBITA: " + String(luz));
  }
  luz_ant = luz;

  // --- BUZZER ---
  if (vibracao >= 0.3) {
    tone(6, 1000, 500); // 1000Hz por 500ms
  } else {
    noTone(6);
  }

  // --- DISPLAY ---
  lcd.clear();
  if (alerta) {
    lcd.setCursor(0, 0);
    lcd.print(msgLinha1);
    lcd.setCursor(0, 1);
    lcd.print(msgLinha2);
  } else {
    int tela = (millis() / 2000) % 3; // alterna a cada 2 segundos
    if (tela == 0) {
      lcd.setCursor(0, 0);
      lcd.print("Temperatura:");
      lcd.setCursor(0, 1);
      lcd.print(String(temperatura) + " C  OK");
    } else if (tela == 1) {
      lcd.setCursor(0, 0);
      lcd.print("Luminosidade:");
      lcd.setCursor(0, 1);
      lcd.print(String(luz) + "  OK");
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Vibracao:");
      lcd.setCursor(0, 1);
      lcd.print(String(vibracao) + "  OK");
    }
  }

  Serial.println("============================================");
  delay(2000);
}
