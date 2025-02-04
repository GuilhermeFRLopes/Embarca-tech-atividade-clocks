#include <stdio.h>
#include "pico/stdlib.h"   
#include "hardware/timer.h" 

#define LED_PIN_GREEN 11
#define LED_PIN_BLUE 12
#define LED_PIN_RED 13
bool led_on = false;

// Função de callback que será chamada repetidamente pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    bool leds_states[3] = {gpio_get(LED_PIN_RED),gpio_get(LED_PIN_GREEN),gpio_get(LED_PIN_BLUE)};

    //sinal vermelho estava ligado
    if (leds_states[0] == true && leds_states[1] == false && leds_states[2] == false){
        gpio_put(LED_PIN_RED,0);//desliga o vermelho
        gpio_put(LED_PIN_BLUE,1);//liga o amarelo (nesse caso o blue pra testar na plaquinha)        
        printf("passou os 3 segundos\n\n");        
        printf("\nEstados dos Leds:\n %d - vermelho\n %d - amarelo\n %d - verde\n",leds_states[0],leds_states[2],leds_states[1]);

    //sinal amarelo estava ligado (nesse caso o blue pra testar na plaquinha)    
    } else if(leds_states[0] == false && leds_states[1] == false && leds_states[2] == true) {        
        gpio_put(LED_PIN_BLUE,0);//desliga o amarelo
        gpio_put(LED_PIN_GREEN,1);//liga o verde
        printf("passou os 3 segundos\n\n");        
        printf("\nEstados dos Leds:\n %d - vermelho\n %d - amarelo\n %d - verde\n",leds_states[0],leds_states[2],leds_states[1]);

    //sinal verde estava ligado
    } else if (leds_states[0] == false && leds_states[1] == true && leds_states[2] == false){
        gpio_put(LED_PIN_RED,1);//liga o vermelho        
        gpio_put(LED_PIN_GREEN,0);//desliga o verde
        printf("passou os 3 segundos\n\n");        
        printf("\nEstados dos Leds:\n %d - vermelho\n %d - amarelo\n %d - verde\n",leds_states[0],leds_states[2],leds_states[1]);
    }    
    // Retorna true para manter o temporizador repetindo. Se retornar false, o temporizador para.
    return true;
}

int main() {
    
    stdio_init_all();

    // Inicializar os pinos
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED,true);

    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE,true);

    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN,true);
   
    // Esta estrutura armazenará informações sobre o temporizador configurado.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundos.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    //inicializando os LEDs pra evitar algum erro
    gpio_put(LED_PIN_RED,1);
    gpio_put(LED_PIN_BLUE,0);
    gpio_put(LED_PIN_GREEN,0);

    
    while (true) {
        // Pausa de 1 segundos
        sleep_ms(1000);
        printf("\n passou 1 segundo do while\n");
    }
    return 0;
}
