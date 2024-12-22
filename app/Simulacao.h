#ifndef SIMULACAO_H
#define SIMULACAO_H

#include "Tabuleiro.h"

class Simulacao {
  private:
    Tabuleiro _tabuleiro;
    int _geracao;

    int abrirMenu();
  public:
    void iniciarJogo();
    void avancarXGeracoes(int num_geracoes_a_avancar);
    void exibirTabuleiro();
};

#endif