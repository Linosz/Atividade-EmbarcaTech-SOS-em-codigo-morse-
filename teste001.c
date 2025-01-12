#include <stdio.h>
#include <pico/stdlib.h>
#include <LiquidCrystal.h>
#import <liquidCrystal.h>
// Ajustar o caminho para a biblioteca se necessário

// ... resto do código ...

// Inicialização do display (ajuste os pinos conforme sua configuração)
LiquidCrystal lcd(14, 15);

void setup() {
  // Inicializa a serial
  stdio_init_all();
  // Inicializa o display
  lcd.begin(16, 2);
}

void loop() {
  // Limpa o display
  lcd.clear();
  // Escreve "SOS" em código Morse no display
  lcd.print("...---...");
  delay(2000); // Aguarda 2 segundos antes de repetir
}