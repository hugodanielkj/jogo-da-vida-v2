#include <iostream>

#include "app/CelulaMutante.h"
#include "app/CelulaImortal.h"
#include "app/CelulaPadrao.h"
#include "app/Simulacao.h"
#include "app/Tabuleiro.h"

// g++ main.cpp app/Celula.cpp app/CelulaPadrao.cpp app/CelulaMutante.cpp app/CelulaImortal.cpp app/Simulacao.cpp app/Tabuleiro.cpp

int main(){
  Simulacao simulacao;
  simulacao.iniciarJogo();    // Inicializa o tabuleiro e seta o estado inicial a escolha do usuario

  simulacao.avancarXGeracoes(5);    // Avanca para a quinta geracao
  simulacao.exibirTabuleiro();    // Exibe a quinta geracao

  simulacao.avancarXGeracoes(95);   // Avanca para a centesima geracao
  simulacao.exibirTabuleiro();    // Exibe a centesima geracao

  return 0;
}