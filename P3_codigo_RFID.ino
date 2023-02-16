#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN  22    //Pin 22 para el reset del RC522
#define SS_PIN  21   //Pin 21 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); //Creamos el objeto para el RC522
void setup() {
  Serial.begin(9600); //Iniciamos la comunicación  serial
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos  el MFRC522
  Serial.println("Lectura del UID");
}
void loop() {
  delay(1500);
  // Revisamos si hay nuevas tarjetas  presentes
  // Look for new cards
  if ( mfrc522.PICC_IsNewCardPresent())
        {
            delay(50);
            //Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial())
            {
                  Serial.println("Present");
                  // Enviamos serialemente su UID
                  Serial.println("Card UID:");
                  for (byte i = 0; i < mfrc522.uid.size; i++) {
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          Serial.print(mfrc522.uid.uidByte[i], HEX);
                  }
                  Serial.println();
                  // Terminamos la lectura de la tarjeta  actual
                  mfrc522.PICC_HaltA();
            }
  } else Serial.println("No card... waiting for one");
}
