#include "CelulaPadrao.h"
#include <iostream>

CelulaPadrao::CelulaPadrao(int coordenada_x, int coordenada_y, int tipo_celular): Celula(coordenada_x, coordenada_y, tipo_celular) {
  setEstado(false);
}

void CelulaPadrao::interagir(int numero_de_vizinhos){
  if(numero_de_vizinhos < 2 && getEstado())
    setEstadoProximaGeracao(false);
  else if(numero_de_vizinhos > 3 && getEstado())
    setEstadoProximaGeracao(false);
  else if(numero_de_vizinhos == 3 && !(getEstado()))
    setEstadoProximaGeracao(true);
  else if(getEstado())
    setEstadoProximaGeracao(true);
  else if(!getEstado())
    setEstadoProximaGeracao(false);
}