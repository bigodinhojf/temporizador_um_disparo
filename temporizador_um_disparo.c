// Inclusão das bibliotecas utilizadas
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h" // Biblioteca de temporizadores

// Definição dos pinos GPIO
const int led_pin_green = 11; // LED Verde GPIO 11
const int led_pin_blue = 12; // LED azul GPIO 12
const int led_pin_red = 13; // LED vermelho GPIO 13
const int button_pin_a = 5; // Botão A GPIO 5

// Variáveis globais
bool rotine_activate = false; // Armazena a informação se a rotina está rodando
static volatile uint32_t last_time = 0; // Armazena o tempo do último clique dos botões
int marcador = 0; // Auxilia an decisão de qual LED apagar

// Função de callback do alarme
int64_t alarm_callback(alarm_id_t id, void *user_data) {

  // Decide qual LED deve apagar quando rodar a função
  switch (marcador) {
        case 0:
            gpio_put(led_pin_green, 0); // Apaga apenas o LED verde
            marcador++; // Adiciona mais 1 no marcador, para quando a fução de callback ser chamada novamente, entrar no próximo "case" do "Switch"
            add_alarm_in_ms(3000, alarm_callback, NULL, false); // Adiciona o mesmo alarme para que a função de callback seja chamada novamente
            break;
        case 1:
            gpio_put(led_pin_blue, 0); // Apaga apenas o LED azul
            marcador++; // Adiciona mais 1 no marcador, para quando a fução de callback ser chamada novamente, entrar no próximo "case" do "Switch"
            add_alarm_in_ms(3000, alarm_callback, NULL, false); // Adiciona o mesmo alarme para que a função de callback seja chamada novamente
            break;
        case 2:
            gpio_put(led_pin_red, 0); // Apaga apenas o LED Vermelho
            rotine_activate = false; // Define a rotina como 'desativada', permitindo o acionamento do botão
            marcador = 0; // Reinicia o marcador
            break;
    }
  return 0;
}


// Função principal
int main()
{
    // Inicialização da comunicação serial
    stdio_init_all();

    // Inicialização dos pinos GPIO

    // Inicializa o LED Verde GPIO 11 e o define como saída
    gpio_init(led_pin_green);
    gpio_set_dir(led_pin_green, GPIO_OUT);

    // Inicializa o LED Azul GPIO 12 e o define como saída
    gpio_init(led_pin_blue);
    gpio_set_dir(led_pin_blue, GPIO_OUT);

    // Inicializa o LED Vermelho GPIO 13 e o define como saída
    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);

    // Inicializa o Botão A, o define como entrada e habilita o resistor de pull up
    gpio_init(button_pin_a);
    gpio_set_dir(button_pin_a, GPIO_IN);
    gpio_pull_up(button_pin_a);


    while (true) {
        // Verifica se o botão foi pressionado e se não há uma rotina rodando
        if(gpio_get(button_pin_a) == 0){
            // Debouncing
            uint32_t current_time = to_us_since_boot(get_absolute_time()); // Pega o tempo atual e transforma em us
            // 200 ms
            if(current_time - last_time > 200000 && !rotine_activate){
                last_time = current_time; // Atualização de tempo do último clique

                // Define a rotina como 'ativada', não permitindo o acionamento do botão
                rotine_activate = true;

                // Liga todos os LEDs
                gpio_put(led_pin_green, 1);
                gpio_put(led_pin_blue, 1);
                gpio_put(led_pin_red, 1);

                // Define um alarme para desligar os LEDs a cada 3s
                add_alarm_in_ms(3000, alarm_callback, NULL, false);
            }
        }
      //
      sleep_ms(10);
    }
}
