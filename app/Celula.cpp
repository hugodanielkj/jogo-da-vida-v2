#include "Celula.h"

Celula::Celula(int coordenada_x, int coordenada_y, int tipo_celular): _coordenada_x(coordenada_x), _coordenada_y(coordenada_y), _tipoCelular(tipo_celular) {}

bool Celula::getEstado(){
  return _estaViva;
}

void Celula::setEstado(bool esta_viva){
  _estaViva = esta_viva;
}

bool Celula::getEstadoProximaGeracao(){
  return _proximoEstado;
}

void Celula::setEstadoProximaGeracao(bool ficara_viva){
  _proximoEstado = ficara_viva;
}

void Celula::efetivarEstadoDaNovaGeracao(){
  _estaViva = _proximoEstado;
}

void Celula::setNovasCoordenadas(int coordenada_x, int coordenada_y){
  _coordenada_x = coordenada_x;
  _coordenada_y = coordenada_y;
}

int Celula::getTipoCelular(){
  return _tipoCelular;
}