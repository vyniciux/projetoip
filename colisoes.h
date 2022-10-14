#ifndef COLISOES_PERS
#define COLISOES_PERS

typedef struct{
    Rectangle area;
    int origem;
    int destino;
    int check; 
    float destinoX;
    float destinoY;
} Porta;

typedef struct{
    int codigoCena;
    Rectangle *obstaculos;
    int qtdObstaculos;
    Porta *portas;
    int qtdPortas;
} Cenas;

void criarCenas(Cenas **cenas);

int colisaoMapa(Rectangle player, Cenas cena);

int trocarCena(Rectangle player, float *x, float *y, Cenas cena, int *cenaAtual);


#endif
