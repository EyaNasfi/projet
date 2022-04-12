#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
typedef struct 
{
SDL_Surface *image; //  affichage de sprite 
SDL_Rect position,max,min; //  position de lennemi
SDL_Rect positionsprite;
int dir;
 //0:droite   // 1: gauche 
}ennemi;
void initennemi (ennemi *e);
void afficherennemi (ennemi e,SDL_Surface *screen);
void animerennemi (ennemi *e);
void deplacer (ennemi *e);
int collisionbb (perso p,ennemi e);
void deplacerIA (ennemi *e,SDL_Rect posPerso);
#endif // ENEMY_H_INCLUDED
