#include "arduino_secrets.h"

//___TagTrace____
#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN 9 // Define the reset pin for the RFID reader
#define SS_PIN 10 // Define the SS (Slave Select) pin for the RFID reader
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create an MFRC522 instance
unsigned long lastCardDetectedTime = 0;
const unsigned long cardDetectionInterval = 5000; // 5 seconds
void setup() {
 Serial.begin(9600); // Initialize serial communication
 SPI.begin(); // Initialize SPI bus
 mfrc522.PCD_Init(); // Initialize RFID reader
 Serial.println("RFID Reader Initialized");
}
void loop() {
 // Check if a new card is present
 if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) 
{
 Serial.println("Card detected!");
 String cardData = "";
20
 // Read card data as a string
 for (byte i = 0; i < mfrc522.uid.size; i++) {
 cardData += String(mfrc522.uid.uidByte[i], HEX);
 }
 // Print the complete card data
 Serial.print("Card Data: ");
 Serial.println(cardData);
 // Update the last card detection time
 lastCardDetectedTime = millis();
 }
 // Check if no card has been detected for the specified interval
 if (millis() - lastCardDetectedTime > cardDetectionInterval) {
 Serial.println("Card not detected.");
 // Reset the last card detection time to prevent repeated printing
 lastCardDetectedTime = millis();
 }
 delay(100); // Delay between each loop iteration
}