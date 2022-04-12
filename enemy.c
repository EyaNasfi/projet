#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enemy.h"
#include "perso.h"
void initennemi (ennemi *e)
{


e->image= IMG_Load ("SOLDAT.png");
e->positionsprite.x=0;
e->positionsprite.y=0;
e->positionsprite.w=100; //256=1280/5  //hauteur =1280 //NBC =5
e->positionsprite.h=200; //256=512/2  //largeur =1280 //NBL =2

//e->frame=0;
e->dir=0;
e->position.x=500;
e->position.y=50;
e->max.x=400;
e->min.x=50;
}
void afficherennemi (ennemi e,SDL_Surface *screen)
{
SDL_BlitSurface(e.image ,&e.positionsprite,screen,&e.position); //copier de image de position spritesheet sur l'ecran dans la position //
}
void animerennemi (ennemi *e)
{

//e->positionsprite.w = 256 +e->positionsprite.w;

e->positionsprite.y = e->dir * e->positionsprite.h;
//e->positionsprite.x+= 100; //positionner dans la ligne correspond a la dir 
if (e->positionsprite.x == 300)  //dernier frame de sprite est atteint //300=400 largeur de sprite - largeur de frame
{ 
e->positionsprite.x=0;
}//revenir a la premiere frame 
else 
{
e->positionsprite.x = e->positionsprite.x + e->positionsprite.w;
}
}
//avance a la frame suivante  
void deplacer (ennemi *e)
{
if (e->position.x > e->max.x)
{
e->dir =1;
}
if (e->position.x < e->min.x)
{
e->dir =0;
//e->position.x++;
}
if (e->dir==0)
{
e->position.x++;
}
else 
{
e->position.x--;
}
}
int collisionbb (perso p,ennemi e)
{ int collision;
if ((p.pos.x+p.pos.w < e.position.x) ||(p.pos.x > e.position.x+e.position.w) || (p.pos.y+p.pos.h < e.position.y) || (p.pos.y > e.position.y+e.position.h))
collision=0 ;
else 
collision=1;
return collision;
}
