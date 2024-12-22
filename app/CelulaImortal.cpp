#include "CelulaImortal.h"

CelulaImortal::CelulaImortal(int coordenada_x, int coordenada_y, int tipo_celular): Celula(coordenada_x, coordenada_y, tipo_celular) {
  setEstado(true);
  setEstadoProximaGeracao(true);
}

void CelulaImortal::interagir(int numero_de_vizinhos){}