# Comunicação_Digital

Um simulador de modulação digital em C++ que implementa ASK, FSK e PSK, com funcionalidades de demodulação, adição de ruído e análise de erro.

## Como Compilar e Executar

1. Clone o repositório:
   ```bash
   git clone https://github.com/seu-usuario/Comunicacao_Digital.git
   cd Comunicacao_Digital
   make
   export QT_QPA_PLATFORM=xcb
   ./bin/Comunicacao_Digital
   
## Visualização dos Sinais

O projeto usa GNUplot para gerar gráficos dos sinais modulados e demodulados. Após executar o programa, uma janela do GNUplot será aberta com os seguintes gráficos:

1. **Sinal Original vs Sinal com Ruído**: Comparação do sinal modulado antes e depois da adição de ruído.

Certifique-se de que o GNUplot está instalado no seu sistema.

## Visualização

![image](https://github.com/user-attachments/assets/6538de49-75dc-4041-961e-b1e252a3cdfd)
