// C++ code
#include <DHT.h>
DHT dht(2, DHT11);
float luz_ant = 9999.00;
void setup()
{
   Serial.begin(9600);
   dht.begin();

   
}

void loop()
{
  float vibracao = analogRead(A1)/1023.00;

  float temperatura = dht.readTemperature();

  float luz = analogRead(A0);


  if (vibracao == 1.0) {
    Serial.println("IMPACTO DETETACTADO: " + String(vibracao));
    
  }else if (vibracao >= 0.6) {
    Serial.println("PREPARAR PARA IMPACTO: " + String(vibracao));
  }else if (vibracao >= 0.3) {
    Serial.println("POSSIVEL IMPACTO: " + String(vibracao));
  }else {
    Serial.println("Vibrção OK: " + String(vibracao));
  }


  if (temperatura >= 25) {
    Serial.println("MOTORES MUITO QUENTES: " + String(temperatura));
  }else if (temperatura >= 24.5) {
    Serial.println("MOTORES AQUECENDO: " + String(temperatura));
  
  }else{
    Serial.println("Temperatura OK: " + String(temperatura));
    
  }

  if (luz <= 100) {
      Serial.println("LADO ESCURO DA ORBITA "+ String(luz));
  } else if (luz < 200 && luz < luz_ant) {
      Serial.println("ENTRANDO NO LADO ESCURO DA ORBITA "+ String(luz) );
  } else if (luz < 200 && luz > luz_ant) {
      Serial.println("SAINDO DO LADO ESCURO DA ORBITA "+ String(luz));
  } else {
      Serial.println("LADO CLARO DA ORBITA "+ String(luz));
  }

  luz_ant = luz;
  
  
  // Serial.println("Vibracao: "+ );
  // Serial.println("Temperatura: "+ );
  // Serial.println("Iluminação: "+ );
  Serial.println("============================================");
  delay(2000);
}