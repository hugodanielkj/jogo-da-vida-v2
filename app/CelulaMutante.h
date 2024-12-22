#ifndef CELULA_MUTANTE_H
#define CELULA_MUTANTE_H

#include "Celula.h"

class CelulaMutante : public Celula {
  public:
    CelulaMutante(int coordenada_x, int coordenada_y, int tipo_celular);
    virtual void interagir(int numero_de_vizinhos) override;
};

#endif