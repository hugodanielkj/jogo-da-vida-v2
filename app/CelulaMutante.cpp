#include "CelulaMutante.h"

CelulaMutante::CelulaMutante(int coordenada_x, int coordenada_y, int tipo_celular): Celula(coordenada_x, coordenada_y, tipo_celular) {
  setEstado(false);
}

void CelulaMutante::interagir(int numero_de_vizinhos){
  getEstado() ? setEstadoProximaGeracao(false) : setEstadoProximaGeracao(true);
}