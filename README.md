# Projeto de Controle de LEDs com Botão - Raspberry Pi Pico W

Este projeto utiliza um Raspberry Pi Pico W para controlar três LEDs (vermelho, azul e verde) através de um botão. Ao pressionar o botão, os três LEDs acendem simultaneamente. Em seguida, eles são desligados em sequência (azul, vermelho, verde) a cada 3 segundos.

## Funcionalidades

*   Acionamento simultâneo de três LEDs (vermelho, azul e verde) ao pressionar um botão.
*   Desligamento sequencial dos LEDs (azul, vermelho, verde) com intervalo de 3 segundos.
*   Prevenção de múltiplos acionamentos do botão (debounce de 200ms).
*   Utilização da biblioteca `hardware/timer` para temporização precisa.
*   Utilização da biblioteca `pico/stdlib` para funções padrão do Pico.

## Hardware

| Componente            | GPIO no Pico | Descrição                                                                     |
| :-------------------- | :----------- | :---------------------------------------------------------------------------- |
| LED Vermelho          | 13           | LED vermelho controlado pelo programa                                         |
| LED Azul              | 12           | LED azul controlado pelo programa                                            |
| LED Verde             | 11           | LED verde controlado pelo programa                                           |
| Botão                 | 5            | Botão usado para acionar a sequência de LEDs                                 |
| Resistor (x3)         | -            | Resistores de 330 ohms para limitar a corrente dos LEDs                        |
| Raspberry Pi Pico W | -            | Microcontrolador usado para controlar os LEDs e ler o estado do botão |

## Instalação

1. **Hardware:**
    *   Raspberry Pi Pico W
    *   3 LEDs (um vermelho, um azul, um verde)
    *   1 Botão
    *   3 resistores de 330 ohms
      
2. **Execução:**

    *   Após a gravação do programa, o Pico W executará o código automaticamente.
    *   Pressione o botão (A, caso seja BitDogLab)  para iniciar a sequência de acendimento e desligamento dos LEDs.
    *   Observe os LEDs acenderem simultaneamente e, em seguida, desligarem em sequência (azul, vermelho, verde) a cada 3 segundos.

   **Link do experimento na placa BitDogLab:** https://youtu.be/YzahSJJ5KQ8
