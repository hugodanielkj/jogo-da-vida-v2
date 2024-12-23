#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "Celula.h"
#include <vector>

class Tabuleiro {
  private:
    // Atributos
    Celula*** _grade;
    int _dimensao;
    int _dimensao_maxima;

    // Funcoes privadas
    int getNumeroDeVizinhosDaCelula(int linha, int coluna); // Chamada dentro de avancar uma rodada
    bool deveAumentarDimensaoDaGrade();
    void aumentarTabuleiro();
    void setarProximoEstadoDasNovasCelulas();
    void setDimensao(int nova_dimensao);
  public:
    // Funcoes publicas
    Tabuleiro();    // Aloca celulas na grade e inicia dimensao = 10
    void setarEstadoInicial(int estado_inicial);   // Seta quais celulas estaram vivas na geracao 0
    bool construirTabuleiro(int estado_inicial);
    void avancarUmaRodada();
    int getDimensao();
    bool getEstadoCelula(int linha, int coluna);
    ~Tabuleiro();
};

#endif