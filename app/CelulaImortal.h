#ifndef CELULA_IMORTAL_H
#define CELULA_IMORTAL_H

#include "Celula.h"

class CelulaImortal : public Celula {
  public:
    CelulaImortal(int coordenada_x, int coordenada_y, int tipo_celular);
    virtual void interagir(int numero_de_vizinhos) override;
};

#endif