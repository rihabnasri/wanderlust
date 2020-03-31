#ifndef struct_H_INCLUDED
#define struct_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct Vie
{
SDL_Surface *coeur0;
SDL_Surface *coeur1;
SDL_Surface *coeur2;
SDL_Surface *coeur3;
SDL_Rect pos;
int nbr_vie;
} Vie;

//typedef struct score
//{int best;
//int nbr;

//} score ;

typedef struct Temps
{
Uint32 temps;
} Temps;

void initialiservie_score (Vie *v,int score);
void gest_vie (Vie *v,perso *hero,ENTITE_SECONDAIRE_object *o);
void affichvie(Vie *v,SDL_Surface *screen);

void loadFont();
void closeFont();

void calculate(int score,ENTITE_SECONDAIRE_STAR *s,perso *hero);
void DrawScore(SDL_Surface *screen, int score);

#endif









