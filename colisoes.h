#ifndef COLISOES_PERS
#define COLISOES_PERS

typedef struct{
    Rectangle area;
    int check;  
    int origem;
    int destino;
} Porta;

typedef struct{
    int codigoCena;
    Rectangle *obstaculos;
    int qtdObstaculos;
    Porta *portas;
} Cenas;

void criarCenas(Cenas **cenas);

int colisao(Rectangle player, Cenas cena);

#endif
