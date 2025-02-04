#include <stdio.h> 
#include "pico/stdlib.h" 
#include "pico/time.h"   

#define LED_PIN_GREEN 11
#define LED_PIN_RED 13
#define LED_PIN_BLUE 12

const uint BUTTON_PIN = 5;  // Define o pino GPIO 5 para ler o estado do botão.

bool led_active = false;    // Indica se os LEDs estao atualmente acesos

// Função de callback para desligar os LEDs após o tempo programado.
int64_t funcao_callback(alarm_id_t id, void *user_data) {
    //array pra armazenar os estados dos leds
    bool leds_states[3] = {gpio_get(LED_PIN_RED),gpio_get(LED_PIN_GREEN),gpio_get(LED_PIN_BLUE)};
    
    if (leds_states[0] == true && leds_states[1] == true && leds_states[2] == true){        
        gpio_put(LED_PIN_BLUE,0);//desliga o primeiro led (azul)             
        printf("passou os 3 segundos\n\n");        
        printf("\nEstados dos Leds:\n %d - vermelho\n %d - azul\n %d - verde\n",leds_states[0],leds_states[2],leds_states[1]);
        // Agenda um alarme para desligar o segundo LED após 3 segundos (3000 ms).
        add_alarm_in_ms(3000, funcao_callback, NULL, false);
       
    } else if(leds_states[0] == true && leds_states[1] == true && leds_states[2] == false) {        
        gpio_put(LED_PIN_RED,0);//desliga o vermelho
        printf("passou os 3 segundos\n\n");        
        printf("\nEstados dos Leds:\n %d - vermelho\n %d - azul\n %d - verde\n",leds_states[0],leds_states[2],leds_states[1]);
        // Agenda um alarme para desligar o terceiro LED após 3 segundos (3000 ms).
        add_alarm_in_ms(3000, funcao_callback, NULL, false);
    
    } else if (leds_states[0] == false && leds_states[1] == true && leds_states[2] == false){               
        gpio_put(LED_PIN_GREEN,0);//desliga o verde
        printf("passou os 3 segundos\n\n");        
        printf("\nEstados dos Leds:\n %d - vermelho\n %d - amarelo\n %d - verde\n",leds_states[0],leds_states[2],leds_states[1]);
        // Atualiza o estado de 'led_active' para falso, indicando que os LEDs estao desligados.
        led_active = false;
    }    

    // Retorna 0 para indicar que o alarme não deve se repetir.
    return 0;
}

int main() {
    
    stdio_init_all();

    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    // Inicializa o pino do botão como entrada com pull-up
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    // Loop principal do programa que verifica continuamente o estado do botão.
    while (true) {
        // Verifica se o botão foi pressionado (nível baixo no pino) e se o LED não está ativo.
        if (gpio_get(BUTTON_PIN) == 0 && !led_active) {
            // debouncing
            sleep_ms(50);

            // Verifica o estado do botão após o debouncing.
            if (gpio_get(BUTTON_PIN) == 0) {
                // Liga todos os LEDs e inicia a rotina de temporização
                gpio_put(LED_PIN_GREEN, true);
                gpio_put(LED_PIN_RED, true);
                gpio_put(LED_PIN_BLUE, true);
                printf("Botão foi acionado, todos os LEDs ligados\n");

                // Define 'led_active' como true para indicar que os LEDs estao acesos.
                led_active = true;

                // Agenda um alarme para desligar o primeiro LED após 3 segundos (3000 ms).                
                add_alarm_in_ms(3000, funcao_callback, NULL, false);
            }
        }

        // Introduz uma pequena pausa de 10 ms para reduzir o uso da CPU.        
        sleep_ms(10);
    }
    
    return 0;
}
