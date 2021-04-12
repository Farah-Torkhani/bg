#ifndef bg_H_INCLUDED
#define bg_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "input.h"

typedef struct
{
    SDL_Surface *bg;
    SDL_Rect BgPos;

    SDL_Rect camera;
    SDL_Rect camera2;

} GameplayBg;

void initBg(GameplayBg *b);
void afficher_background(SDL_Surface *screen, GameplayBg *b);
void scrolling_right(GameplayBg *b, float velocity, SDL_Surface *screen, Input I);
void scrolling_left(GameplayBg *b, float velocity, SDL_Surface *screen, Input I);

#endif
