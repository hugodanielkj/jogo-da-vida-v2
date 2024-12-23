JOGO DA VIDA - DOCUMENTAÇÃO

Introdução:
O trabalho foi desenvolvido a fim de aplicar os conhecimentos adquiridos na disciplina Programação 2 - Programação Orientada á Objetos. Dessa forma, foi feito uma réplica personalizada do Jogo da Vida de um autômato celular, desenvolvido pelo matemático britânico John Horton Conway.

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

Detalhes de implementação e responsabilidades das classes:
A fim de seguir os princípios de encapsulamento da POO, foi feito a separação de funções em diferentes classes, adequadas à sua responsabilidade, que serão detalhadas abaixo:

 - Classe Simulacao: tem por objetivo controlar toda a execução do jogo - funcionando como um controller - sem lidar com a lógica do jogo, apenas chama funções da classe Tabuleiro ou Celula em suas próprias funções. Por isso, possui de atributo um tabuleiro da classe Tabuleiro, criado por composição na classe Simulacao, já que haverá apenas um tabuleiro por simulação. Além disso, possui o atributo geração do tipo inteiro para exibir na tela o tabuleiro e sua respectiva geração.

 - Classe Tabuleiro: tem por objetivo controlar a lógica de funcionamento do tabuleiro. Dessa forma, possui 3 atributos:
    1. Celula*** _grade: ponteiro de ponteiro para ponteiro de Celula, que armazena uma matriz, sendo que cada elemento da matriz armazena um endereço de memória de um objeto de classe Celula gerado.
    2. _dimensao: é a dimensão atual que possui a _grade.
    3. _dimensao_maxima: é o tamanho máximo que a dimensão pode atingir.
 Assim, a classe Tabuleiro lida com o preenchimento de células no tabuleiro, aumento do tabuleiro quando existe a necessidade - há células que ficarão vivas fora do tabuleiro atual - avanço de gerações e exclusão do tabuleiro no fim do programa.

 - Classe Celula e derivadas: responsáveis por armazenar os atributos e implementações específicas de cada um dos tipos celulares.

Além disso, no caso especial das células e suas derivadas, foi utilizado o conceito de herança e polimorfismo, a fim de reutilizar algumas linhas de código e conectar às funções. Para isso, é criado a classe abstrata Celula, que nunca é instanciada e possui como principal função a interagir(), que é do tipo virtual puro, ou seja, precisa ser implementada em suas classes filhas.

Conclusão:
O programa é de simples uso do usuário e foi utilizado os principais conceitos da programação orientada á objetos, com alto nível de abstração, para ser mais intuitiva e fácil de ser utilizada.
