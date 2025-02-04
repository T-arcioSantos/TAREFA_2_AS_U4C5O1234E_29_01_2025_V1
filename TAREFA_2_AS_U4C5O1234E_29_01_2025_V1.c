#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define INTERVAL_MS 3000
#define DEBOUNCE_TIME_US 200000  

#define PIN_LED_VERMELHO 13
#define PIN_LED_AZUL 12
#define PIN_LED_VERDE 11
#define BUTTON_PIN 5

volatile bool rodando = false;  // Flag para evitar múltiplos acionamentos
volatile uint32_t ultimo_botao = 0;  // Tempo do último clique
volatile int estado = 0; // Estado atual do LED

// Callback para desligar os LEDs
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if (estado == 0) {
        gpio_put(PIN_LED_AZUL, 0);  // Desliga o azul
    } else if (estado == 1) {
        gpio_put(PIN_LED_VERMELHO, 0); // Desliga o vermelho
    } else if (estado == 2) {
        gpio_put(PIN_LED_VERDE, 0); // Desliga o verde
        rodando = false; // Libera o botão
        return 0;
    }

    estado++;
    add_alarm_in_ms(INTERVAL_MS, turn_off_callback, NULL, false); // Agenda próximo desligamento
    return 0;
}

// Callback para acionar os LEDs
void button_callback(uint gpio, uint32_t events) {
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    if ((current_time - ultimo_botao > DEBOUNCE_TIME_US)&& !rodando) {  
        ultimo_botao = current_time; // Atualiza o tempo do último clique
        rodando = true;
        estado = 0;

        // Liga todos os LEDs
        gpio_put(PIN_LED_AZUL, 1);
        gpio_put(PIN_LED_VERMELHO, 1);
        gpio_put(PIN_LED_VERDE, 1);

        // Agenda o desligamento
        add_alarm_in_ms(INTERVAL_MS, turn_off_callback, NULL, false);
    }
}
void configurar_pinos(void) {
    stdio_init_all();

    // Configura LEDs como saída
    gpio_init(PIN_LED_AZUL);
    gpio_set_dir(PIN_LED_AZUL, GPIO_OUT);
    gpio_init(PIN_LED_VERMELHO);
    gpio_set_dir(PIN_LED_VERMELHO, GPIO_OUT);
    gpio_init(PIN_LED_VERDE);
    gpio_set_dir(PIN_LED_VERDE, GPIO_OUT);

    // Configura botão como entrada
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
}

int main() {
    stdio_init_all();
    configurar_pinos();

    // Configura interrupção com callback
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (true) {
        tight_loop_contents();  // Aguarda interrupção
    }

    return 0;
}
