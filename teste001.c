#include "pico/stdlib.h"

// Define os pinos
#define LED_PIN 11
#define BUZZER_PIN1 10
#define BUZZER_PIN2 21

// Funções para controle dos buzzers e do LED
void buzz(int duration) {
    gpio_put(BUZZER_PIN1, 1);
    gpio_put(BUZZER_PIN2, 1);
    sleep_ms(duration);
    gpio_put(BUZZER_PIN1, 0);
    gpio_put(BUZZER_PIN2, 0);
}

void blinkLED(int duration) {
    gpio_put(LED_PIN, 1);
    buzz(duration);  // Aciona os buzzers junto com o LED
    sleep_ms(duration);
    gpio_put(LED_PIN, 0);
    sleep_ms(125);  // Tempo GAP entre sinais
}

void sendCharacter(char character) {
    switch (character) {
        case 'S':
            for (int i = 0; i < 3; i++) {
                blinkLED(200);
            }
            break;
        case 'O':
            for (int i = 0; i < 3; i++) {
                blinkLED(800);
            }
            break;
    }
    sleep_ms(250);  // Intervalo entre letras
}

void sendSOS() {
    sendCharacter('S');
    sendCharacter('O');
    sendCharacter('S');
    sleep_ms(3000);  // Intervalo antes de reiniciar o ciclo
}

int main() {
    // Inicializa o SDK da Pico
    stdio_init_all();
    
    // Configura os pinos do LED e dos buzzers como saída
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_init(BUZZER_PIN1);
    gpio_set_dir(BUZZER_PIN1, GPIO_OUT);
    gpio_init(BUZZER_PIN2);
    gpio_set_dir(BUZZER_PIN2, GPIO_OUT);

    // Loop principal
    while (true) {
        sendSOS();  // Faz o envio do sinal SOS continuamente
    }
}
