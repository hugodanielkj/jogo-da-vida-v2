#include "Tabuleiro.h"

#include "CelulaPadrao.h"
#include "CelulaMutante.h"
#include "CelulaImortal.h"
#include <iostream>
#include <random>

Tabuleiro::Tabuleiro(): _dimensao(10), _dimensao_maxima(50) {}

void Tabuleiro::construirTabuleiro(int estado_inicial){
  if(estado_inicial==1){
    // Seta quantia maxima de celulas mutantes e imortais
    int numero_max_celulas_mutante = 25;
    int numero_max_celulas_imortal = 25;

    // Gera random num entre 1 a 3 a cada iteracao e setar valores para cada tipo celular
    // Numero aleatorio: random_num == 1 (mutante) ; random_num == 2 (imortal) ; random_num == 3 (padrao)
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dist(1, 3); 
    int random_num;

    // Gera o tabuleiro com as celulas
    _grade = new Celula**[_dimensao];
    for(int i=0;i<_dimensao;i++){
      _grade[i] = new Celula*[_dimensao];
      for(int j=0;j<_dimensao;j++){
        random_num = dist(gen);
        if(numero_max_celulas_mutante!= 0 && random_num==1){
          _grade[i][j] = new CelulaMutante(i,j,2);
          numero_max_celulas_mutante--;
        }
        else if(numero_max_celulas_imortal!= 0 && random_num==2){
          _grade[i][j] = new CelulaImortal(i,j,3);
          numero_max_celulas_imortal--;
        }
        else {
          _grade[i][j] = new CelulaPadrao(i,j,1);
        }
      }
    }
  } else if(estado_inicial >=2 || estado_inicial <= 7){
    _grade = new Celula**[_dimensao];
    for(int i=0;i<_dimensao;i++){
      _grade[i] = new Celula*[_dimensao];
      for(int j=0;j<_dimensao;j++){
        _grade[i][j] = new CelulaPadrao(i,j,1);
      }
    }
  }
}

// Inicia a geracao 0 com estado inicial da celulas
void Tabuleiro::setarEstadoInicial(int estado_inicial){
  construirTabuleiro(estado_inicial);

  switch(estado_inicial){
    case 1:{
      std::random_device rd;
      std::mt19937 gen(rd()); 
      std::uniform_int_distribution<> dist(1, 3); 
      int random_num;

      for(int i=0;i<_dimensao;i++)
        for(int j=0;j<_dimensao;j++){
          random_num = dist(gen);

          // Nao e necessario setar morta pois todas sao inicializadas mortas
          // Somente celulas padrao serao setadas igual a true, as outras seguem regras proprias
          if(random_num==1 && _grade[i][j]->getTipoCelular()==1) 
            _grade[i][j]->setEstado(true);
        }
    }
    case 2:{
      _grade[4][4]->setEstado(true);
      _grade[4][5]->setEstado(true);
      _grade[5][4]->setEstado(true);
      _grade[5][5]->setEstado(true);
      break;
    }
    case 3:{
      _grade[3][3]->setEstado(true);
      _grade[3][4]->setEstado(true);
      _grade[4][3]->setEstado(true);
      _grade[4][5]->setEstado(true);
      _grade[5][4]->setEstado(true);
      break;
    }
    case 4:{
      _grade[4][4]->setEstado(true);
      _grade[4][5]->setEstado(true);
      _grade[4][6]->setEstado(true);
      break;
    }
    case 5:{
      _grade[4][5]->setEstado(true);
      _grade[4][6]->setEstado(true);
      _grade[4][7]->setEstado(true);
      _grade[5][4]->setEstado(true);
      _grade[5][5]->setEstado(true);
      _grade[5][6]->setEstado(true);
      break;
    }
    case 6:{
      _grade[3][3]->setEstado(true);
      _grade[3][4]->setEstado(true);
      _grade[3][5]->setEstado(true);
      _grade[4][3]->setEstado(true);
      _grade[5][4]->setEstado(true);
      break;
    }
    case 7:{
      _grade[3][3]->setEstado(true);
      _grade[3][6]->setEstado(true);
      _grade[4][2]->setEstado(true);
      _grade[5][2]->setEstado(true);
      _grade[5][6]->setEstado(true);
      _grade[6][2]->setEstado(true);
      _grade[6][3]->setEstado(true);
      _grade[6][4]->setEstado(true);
      _grade[6][5]->setEstado(true);
      break;
    }
  }
}



int Tabuleiro::getDimensao(){
  return _dimensao;
}

bool Tabuleiro::getEstadoCelula(int linha, int coluna){
  return _grade[linha][coluna]->getEstado();
}

Tabuleiro::~Tabuleiro(){
  for(int i=0;i<_dimensao;i++){
    for(int j=0;j<_dimensao;j++){
      delete _grade[i][j];
    }
    delete[] _grade[i];
  }
  delete[] _grade;
}

void Tabuleiro::avancarUmaRodada(){
  // Seta o estado das celulas na proxima geracao com base no numero de vizinhos
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++){
      int numero_de_vizinhos = getNumeroDeVizinhosDaCelula(i,j);
      _grade[i][j]->interagir(numero_de_vizinhos);
    }
  
  // Verifica se sera necessario aumento da grade
  if(deveAumentarDimensaoDaGrade()){
    aumentarTabuleiro();
    setarProximoEstadoDasNovasCelulas();
  }
  
  // Efetiva o estado das celulas gerados no loop anterior
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++)
      _grade[i][j]->efetivarEstadoDaNovaGeracao();
}

// Verifica existencia de 3 celulas ou mais seguidas nas bordas, se sim, retorna true
bool Tabuleiro::deveAumentarDimensaoDaGrade(){
  if(_dimensao == _dimensao_maxima)
    return false;

  int linha, coluna;
  int numero_celulas_vivas_seguidas = 0;

  linha = 0;
  for(int coluna=0;coluna<_dimensao;coluna++){
    if(_grade[linha][coluna]->getEstadoProximaGeracao())
      numero_celulas_vivas_seguidas++;
    else
      numero_celulas_vivas_seguidas = 0;

    if(numero_celulas_vivas_seguidas > 2)
      return true;
  }

  linha = _dimensao-1;
  for(int coluna=0;coluna<_dimensao;coluna++){
    if(_grade[linha][coluna]->getEstadoProximaGeracao())
      numero_celulas_vivas_seguidas++;
    else
      numero_celulas_vivas_seguidas = 0;

    if(numero_celulas_vivas_seguidas > 2)
      return true;
  }

  coluna = 0;
  for(int linha=0;linha<_dimensao;linha++){
    if(_grade[linha][coluna]->getEstadoProximaGeracao())
      numero_celulas_vivas_seguidas++;
    else
      numero_celulas_vivas_seguidas = 0;

    if(numero_celulas_vivas_seguidas > 2)
      return true;
  }

  coluna = _dimensao-1;
  for(int linha=0;linha<_dimensao;linha++){
    if(_grade[linha][coluna]->getEstadoProximaGeracao())
      numero_celulas_vivas_seguidas++;
    else
      numero_celulas_vivas_seguidas = 0;

    if(numero_celulas_vivas_seguidas > 2)
      return true;
  }

  return false;
}

void Tabuleiro::aumentarTabuleiro(){
  int nova_dimensao = _dimensao+4;
  
  Celula*** nova_grade = new Celula**[nova_dimensao];
  for(int i=0;i<nova_dimensao;i++){
    nova_grade[i] = new Celula*[nova_dimensao];
    for(int j=0;j<nova_dimensao;j++){
      if(i > 1 && j > 1 && i < _dimensao+2 && j < _dimensao+2){   // Sai do limite das borda que foi adicionada
        nova_grade[i][j] = _grade[i-2][j-2];
        nova_grade[i][j]->setNovasCoordenadas(i,j);
      } else {
        nova_grade[i][j] = new CelulaPadrao(i,j,1);
      }
    }
  }

  // Destroi _grade sem destruir as celulas
  for(int i=0;i<_dimensao;i++)
    delete[] _grade[i];
  delete[] _grade;

  // Coloca nova_grade no lugar de _grade
  _grade = nova_grade;

  // Seta o valor da nova dimensao
  _dimensao = nova_dimensao;
}

void Tabuleiro::setarProximoEstadoDasNovasCelulas(){
  int numero_de_vizinhos = 0;
  
  // Seta as novas celulas da borda superior
  for(int i=0;i<2;i++)
    for(int j=0;j<_dimensao;j++){
      numero_de_vizinhos = getNumeroDeVizinhosDaCelula(i,j);
      _grade[i][j]->interagir(numero_de_vizinhos);
    }

  // Seta as novas celulas da borda inferior
  for(int i=_dimensao-2;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++){
      numero_de_vizinhos = getNumeroDeVizinhosDaCelula(i,j);
      _grade[i][j]->interagir(numero_de_vizinhos);
    }

  // Seta as novas celulas da borda esquerda
  for(int i=2;i<_dimensao-2;i++)
    for(int j=0;j<2;j++){
      numero_de_vizinhos = getNumeroDeVizinhosDaCelula(i,j);
      _grade[i][j]->interagir(numero_de_vizinhos);
    }

  // Seta as novas celulas da borda direita
  for(int i=2;i<_dimensao-2;i++)
    for(int j=_dimensao-2;j<_dimensao;j++){
      numero_de_vizinhos = getNumeroDeVizinhosDaCelula(i,j);
      _grade[i][j]->interagir(numero_de_vizinhos);
    }
}

int Tabuleiro::getNumeroDeVizinhosDaCelula(int linha, int coluna){
  int numero_de_vizinhos = 0;

  // Verifica posicoes especiais das celulas na grade
  if(linha > 0 && coluna > 0 && linha < _dimensao-1 && coluna < _dimensao-1){
    for(int i=linha-1;i<=linha+1;i++)
      for(int j=coluna-1;j<=coluna+1;j++){
        if(i==linha && j==coluna) continue;
        if(_grade[i][j]->getEstado())
          numero_de_vizinhos++;
      }
  } else if (linha == 0 && coluna == 0){
    _grade[0][1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos; 
    _grade[1][0]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
    _grade[1][1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
  } else if (linha == 0 && coluna == _dimensao-1) {
    _grade[0][_dimensao-2]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos; 
    _grade[1][_dimensao-2]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
    _grade[1][_dimensao-1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
  } else if (linha == _dimensao-1 && coluna == 0){
    _grade[_dimensao-2][0]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos; 
    _grade[_dimensao-2][1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
    _grade[_dimensao-1][1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
  } else if (linha == _dimensao-1 && coluna == _dimensao-1){
    _grade[_dimensao-2][_dimensao-2]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos; 
    _grade[_dimensao-2][_dimensao-1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
    _grade[_dimensao-1][_dimensao-2]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
  } else if (linha == 0) {
    _grade[0][coluna-1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos; 
    _grade[0][coluna+1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
    _grade[1][coluna-1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
    _grade[1][coluna]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos; 
    _grade[1][coluna+1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
  } else if (coluna == 0) {
    _grade[linha-1][0]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos; 
    _grade[linha+1][0]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
    _grade[linha-1][1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
    _grade[linha][1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos; 
    _grade[linha+1][1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
  } else if (linha == _dimensao-1){
    _grade[linha-1][coluna-1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos; 
    _grade[linha-1][coluna]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
    _grade[linha-1][coluna+1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
    _grade[linha][coluna-1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos; 
    _grade[linha][coluna+1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
  } else if (coluna == _dimensao-1){
    _grade[linha-1][coluna-1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos; 
    _grade[linha][coluna-1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
    _grade[linha+1][coluna-1]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
    _grade[linha-1][coluna]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos; 
    _grade[linha+1][coluna]->getEstado() ? numero_de_vizinhos++ : numero_de_vizinhos;
  }

  return numero_de_vizinhos;
}