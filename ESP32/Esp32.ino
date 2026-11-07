#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN  5   
#define RST_PIN 22  

MFRC522 mfrc522(SS_PIN, RST_PIN);


byte tarjetaAutorizada[4] = {0xBC, 0x3B, 0xCB, 0x06};

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial2.begin(9600, SERIAL_8N1, 16, 17);
  
  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println("ESP32 Master con RFID iniciado...");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  if (compararUID(mfrc522.uid.uidByte, tarjetaAutorizada)) {
    Serial.println("[ESP32] ¡Acceso Permitido!");
    Serial2.println("ACCESO_PERMITIDO");
  } else {
    Serial.println("[ESP32] Acceso Denegado.");
    Serial2.println("ACCESO_DENEGADO");
  }

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}

boolean compararUID(byte lectura[], byte autorizada[]) {
  for (byte i = 0; i < 4; i++) {
    if (lectura[i] != autorizada[i]) {
      return false;
    }
  }
  return true;
}
