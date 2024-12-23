JOGO DA VIDA - DOCUMENTAÇÃO

Introdução:
O trabalho foi desenvolvido para aplicar os conhecimentos adquiridos na disciplina Programação 2 - Programação Orientada á Objetos. Dessa forma, foi feito uma réplica personalizada do Jogo da Vida de um autômato celular, desenvolvido pelo matemático britânico John Horton Conway.

Regras do Jogo:
O jogo inicia dando a opção ao usuário de escolher uma das opções de simulação do jogo. Dentre elas há as seguintes simulações:

1. ESTADO INICIAL ALEATORIO
2. BLOCO.
3. BOTE.
4. PISCADOR.
5. SAPO.
6. PLANADOR.
7. ESPACONAVE PESO-LEVE.

E, caso o usuário queira sair do jogo, seleciona o número 8.

No jogo, temos 3 tipos celulares diferentes que serão detalhadas abaixo.
  - Células Padrão: seguem as seguintes regras:
    1. Toda célula morta com exatamente três vizinhos vivos torna-se viva (nascimento).
    2. Toda célula viva com menos de dois vizinhos vivos morre por isolamento.
    3. Toda célula viva com mais de três vizinhos vivos morre por superpopulação.
    4. Toda célula viva com dois ou três vizinhos vivos permanece viva.

  - Células Mutantes: intercalam entre o estado viva e morta de geração e geração (exemplo: geração 1: viva; geração 2: morta; geração 3: viva; geração 4: morta...).
  - Células Imortais: sempre estão vivas e não podem morrer.

Assim, na opção de número 1 - ESTADO INICIAL ALEATORIO - serão intercaladas aleatoriamente os 3 tipos celulares no tabuleiro, enquantos no demais estados - 2 ao 7 - haverá apenas células padrão.

Ao escolher sua opção, será apresentado ao usuário a quinta e a centésima geração celular.