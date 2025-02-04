# Tarefa: Temporizador de Um Disparo (One Shot)

##  Descrição do Projeto
Este projeto implementa um sistema de temporização para o acionamento de LEDs utilizando o microcontrolador Raspberry Pi Pico W, três LEDs (azul, vermelho e verde), três resistores de 330 Ω (ambiente simulado) e um botão (pushbutton). O sistema atua a partir do clique no botão, ligando os LEDs e alternando entre os estados a cada 3 segundos.

## Requisitos

1. **Acionamento dos LEDs pelo botão**: Ao clicar no botão, os três LEDs serão ligados (todos em nível alto). A partir da primeira rotina de atraso, ocorrerá uma mudança de estado para dois LEDs ligados e, em seguida, apenas um.
2. **Temporização de 3 segundos**: O temporizador do alarme é ajustado para um atraso de 3.000 ms entre os estados de acionamento dos LEDs.
3. **Callback do temporizador**: A mudança de estado dos LEDs é implementada em funções de callback do temporizador.
4. **Controle do botão**: O botão só pode alterar o estado dos LEDs quando o último LED for desligado. Durante a execução das rotinas de temporização, o botão não pode iniciar uma nova chamada da função callback.
5. **Experimento com BitDogLab**: Utilize o LED RGB – GPIOs 11, 12 e 13 e o Botão A, GPIO 05.
6. **Debounce do botão (Opcional)**: Implementar uma rotina em software para atenuação do efeito bouncing no botão.
---

## Configuração do Hardware

- Conecte o LED azul ao GPIO 12.
- Conecte o LED vermelho ao GPIO 13.
- Caso necessário, Conecte o LED verde ao GPIO 11.
- Conecte os resistores de 330 Ω aos catodos dos LEDs e ao GND.
- Conecte o botão ao GPIO 5.

## Compilação e Execução

1. Clone o repositório do projeto.
2. Configure o ambiente de desenvolvimento do Raspberry Pi Pico.
3. Compile o código usando o CMake:
4. Carregue o binário no Raspberry Pi Pico.
5. Para testar a simulaçao do wokwi é necessário compilar o projeto pela extensão do pi-pico

###  Testando no Simulador
Se quiser testar no **Wokwi**, abra o arquivo `diagram.json` e inicie a simulação.
obs: Para testar a simulaçao do wokwi é necessário compilar o projeto pela extensão do pi-pico
---

##  Tutorial para testar o codigo caso não consiga clonar
 **Assista o video**:
https://youtu.be/AEYJUYi0vuI
 

---

##  Equipe de Desenvolvimento
| Nome | GitHub |
|------|--------|
| Guilherme Lopes | [@GuilhermeFRLopes](https://github.com/GuilhermeFRLopes) |


