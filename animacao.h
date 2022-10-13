#ifndef ANIMACAO
#define ANIMACAO

#include "raylib.h"

void AnimPlayer(Texture2D Player, float FrameWidth, int *frame, float *mov, int *x, int *y);

void AnimPato(Texture2D Pato, float FrameWidth2, int *frame2, float *mov2, int *px, int *py, int *x, int *y, float *Mov, int comida);

void AnimEspelho(Texture2D Espelho, int *frame3);

Rectangle AnimFogo(Texture2D Fire);

void AnimItem(Texture2D *item, bool *itens, int qtdItens, int x, int y);

#endif