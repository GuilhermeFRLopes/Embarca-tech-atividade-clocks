# Tarefa: Semáforo com Temporizador Periódico

##  Descrição do Projeto
Este projeto implementa um semáforo utilizando o microcontrolador Raspberry Pi Pico W, três LEDs (vermelho, amarelo e verde) e três resistores de 330 Ω. O semáforo alterna entre as cores vermelho, amarelo e verde a cada 3 segundos, utilizando a função `add_repeating_timer_ms()` da ferramenta Pico SDK.

## Requisitos

1. **Início na cor vermelha**: O semáforo inicia com o LED vermelho aceso.
2. **Temporização de 3 segundos**: O temporizador é ajustado para um atraso de 3.000 ms.
3. **Callback do temporizador**: A mudança de estado dos LEDs é implementada na função de callback do temporizador, `repeating_timer_callback()`.
4. **Mensagens na porta serial**: A rotina principal imprime uma mensagem a cada segundo (1.000 ms) na porta serial.
5. **GPIOs utilizados**: Os LEDs são conectados aos GPIOs 11, 12 e 13.
---

## Configuração do Hardware

- Conecte o LED vermelho ao GPIO 13.
- Conecte o LED amarelo ao GPIO 12.
- Conecte o LED verde ao GPIO 11.
- Caso necessário, Conecte os resistores de 330 Ω aos catodos dos LEDs e ao GND.

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


