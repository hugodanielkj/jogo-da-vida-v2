#include "Simulacao.h"

#include <iostream>

void Simulacao::iniciarJogo(){
  _geracao = 0;
  int escolha_usuario = abrirMenu();
  _tabuleiro.setarEstadoInicial(escolha_usuario);
}

int Simulacao::abrirMenu(){
  std::cout << "MENU DO JOGO:\n";
  std::cout << "1 - Executar a partir de um estado inicial aleatorio.\n";
  std::cout << "2 - Executar a partir do estado inicial BLOCO.\n";
  std::cout << "3 - Executar a partir do estado inicial BOTE.\n";
  std::cout << "4 - Executar a partir do estado inicial PISCADOR.\n";
  std::cout << "5 - Executar a partir do estado inicial SAPO.\n";
  std::cout << "6 - Executar a partir do estado inicial PLANADOR.\n";
  std::cout << "7 - Executar a partir do estado inicial ESPACONAVE PESO-LEVE.\n";
  std::cout << "8 - Sair.\n";

  int opcao;
  std::cin >> opcao;
  return opcao;
}

void Simulacao::avancarXGeracoes(int num_geracoes_a_avancar){
  for(int i=0;i<num_geracoes_a_avancar;i++)
    _tabuleiro.avancarUmaRodada();
  _geracao += num_geracoes_a_avancar;
}

void Simulacao::exibirTabuleiro(){
  std::cout << "Geracao " << _geracao << " do Jogo da Vida.\n";
  for(int i=0;i<_tabuleiro.getDimensao();i++){
    for(int j=0;j<_tabuleiro.getDimensao();j++){
      char c;
      _tabuleiro.getEstadoCelula(i,j) ? c = '+' : c = '-';
      std::cout << c << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}