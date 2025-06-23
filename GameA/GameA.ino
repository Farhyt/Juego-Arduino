#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int botones[] = {2, 3, 4, 5, 6}; // Pines de los botones
int numeroSecreto;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Adivina 1 a 5");

  for (int i = 0; i < 5; i++) {
    pinMode(botones[i], INPUT);
  }

  randomSeed(analogRead(A0));  // Para mejor aleatoriedad
  numeroSecreto = random(1, 6);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    if (digitalRead(botones[i]) == HIGH) {
      lcd.clear();
      if (i + 1 == numeroSecreto) {
        lcd.print("¡Correcto!");
        delay(3000);
        numeroSecreto = random(1, 6);
        lcd.clear();
        lcd.print("Adivina 1 a 5");
      } else {
        lcd.print("No, intenta otra");
        delay(1000);
        lcd.clear();
        lcd.print("Adivina 1 a 5");
      }
    }
  }
}