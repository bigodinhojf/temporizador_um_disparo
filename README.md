<div align="center">
    <img src="https://moodle.embarcatech.cepedi.org.br/pluginfile.php/1/theme_moove/logo/1733422525/Group%20658.png" alt="Logo Embarcatech" height="100">
</div>

<br>

# Temporizador de um disparo (One Shot)

## Sumário

- [Descrição](#descrição)
- [Funcionalidades Implementadas](#funcionalidades-implementadas)
- [Ferramentas utilizadas](#ferramentas-utilizadas)
- [Objetivos](#objetivos)
- [Instruções de uso](#instruções-de-uso)
- [Vídeo de apresentação](#vídeo-de-apresentação)
- [Aluno e desenvolvedor do projeto](#aluno-e-desenvolvedor-do-projeto)
- [Licensa](#licença)

## Descrição

Este projeto implementa um sistema interativo utilizando a placa de desenvolvimento BitDogLab e o microcontrolador Raspberry Pi Pico W. Ele também foi desenvolvido e testado no simulador de eletrônica Wokwi, integrando 3 LEDs, um vermelho, um azul e um verde para explorar o uso de temporizadores a partir da função ***add_alarm_in_ms()***. O objetivo principal é projetar um sistema de temporização, que atua a partir do clique de um botão.

## Funcionalidades Implementadas

1. Acionamento de LEDs a partir de um temporizador alarme:

  
   - Quando um botão é pressionado todos os LEDs acendem e um temporizador é ajustado para 3 segundos (3.000ms).
   - O temporizador dispara uma função de *callback* que apaga um LED e ajusta o temporizador novamente, até que todos os LEDs se apaguem.
   - Uma variável trava o botão de ser pressinado enquanto todos os LEDs não se apagam.

2. Debouncing via software:

   - Implementação de um algoritmo de debouncing para evitar leituras indesejadas devido ao bouncing mecânico do botão.

## Ferramentas utilizadas

- **Simulador de eletrônica wokwi**: Ambiente utilizado para simular o hardware e validar o funcionamento do sistema.
- **Ferramenta educacional BitDogLab (versão 6.3)**: Placa de desenvolvimento utilizada para programar o microcontrolador.
- **Microcontrolador Raspberry Pi Pico W**: Responsável pelo controle do botão e dos LEDs.
- **LED RGB**: Dispositivo utilizado para acender e apagar de acordo com a rotina de temporização.
- **Botão físico**: Utilizado para acender os LEDs e ajustar o temporizador inicial.
- **Visual Studio Code (VS Code)**: IDE utilizada para o desenvolvimento do código com integração ao Pico SDK.
- **Pico SDK**: Kit de desenvolvimento de software utilizado para programar o Raspberry Pi Pico W em linguagem C.

## Objetivos

1. Compreender o funcionamento e a aplicação de temporizadores em microcontroladores.
2. Fazer a utilização da função ***add_alarm_in_ms()***.
3. Desenvolver um projeto funcional que combine hardware e software.

## Instruções de uso

1. **Clonar o Repositório**:

```bash
git clone https://github.com/bigodinhojf/temporizador_um_disparo.git
```

2. **Compilar e Carregar o Código**:
   No VS Code, configure o ambiente e compile o projeto com os comandos:

```bash	
cmake -G Ninja ..
ninja
```

3. **Interação com o Sistema**:
   - Conecte a placa ao computador.
   - Clique em run usando a extensão do raspberry pi pico.
   - Clique no botão A para dar início a rotina de temporização.

## Vídeo de apresentação

O vídeo apresentando o projeto pode ser assistido [clicando aqui](https://youtu.be/vi-1jh6bHWo).

## Aluno e desenvolvedor do projeto

<a href="https://github.com/bigodinhojf">
        <img src="https://github.com/bigodinhojf.png" width="150px;" alt="João Felipe"/><br>
        <sub>
          <b>João Felipe</b>
        </sub>
</a>

## Licença

Este projeto está licenciado sob a licença MIT.
