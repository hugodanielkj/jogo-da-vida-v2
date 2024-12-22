#ifndef CELULA_H
#define CELULA_H

class Celula {
  private:
    int _coordenada_x;
    int _coordenada_y;
    bool _estaViva;
    bool _proximoEstado;
    int _tipoCelular;
  public:
    Celula(int coordenada_x, int coordenada_y, int tipo_celular);
    bool getEstado();
    void setEstado(bool esta_viva);
    bool getEstadoProximaGeracao();
    void setEstadoProximaGeracao(bool ficara_viva);
    void efetivarEstadoDaNovaGeracao();
    void setNovasCoordenadas(int coordenada_x, int coordenada_y);
    int getTipoCelular();
    virtual void interagir(int numero_de_vizinhos) = 0;
};

#endif