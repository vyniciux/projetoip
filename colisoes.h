#ifndef COLISOES_PERS
#define COLISOES_PERS

typedef struct{
    int codigoCena;
    Rectangle *obstaculos;
    int qtdObstaculos;
} Cenas;

void criarCenas(Cenas **cenas);

int colisao(Rectangle player, Cenas cena);

#endif