
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include  "fonctionr.h"


int main(void) {
SDL_Surface *screen;
SDL_Surface *barre_vie;
SDL_Surface *OPTION;
SDL_Rect positionOPTION;
SDL_Event event;
score *s;
Vie *v;
perso *hero;
ENTITE_SECONDAIRE_STAR *s;
ENTITE_SECONDAIRE_object *o;
int score;
int nbr;
screen= SDL_SetVideoMode(350,550,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if (screen==NULL){
printf("Unable to set video mode:%s\n",SDL_GetError());
return(-1);
}
barre_vie=IMG_Load("barre des vie.png");
OPTION=IMG_Load("option.png");
if (OPTION==NULL){
printf("Unable to load bitmap:%s\n",SDL_GetError());
return 1;
}

/*positionOPTION.x=0;
positionOPTION.y=0;
positionOPTION.w=0;
positionOPTION.h=0;
while (SDL_PollEvent(&event))
  	 {switch(event.type)
     	  {case SDL_MOUSEMOTION:
 	if(event.motion.x > 325 && event.motion.x < 345 && event.motion.y > 1 	&& event.motion.y < 19)
	{SDL_BlitSurface(OPTION,NULL,screen,&positionOPTION);
        SDL_Flip(screen);
	}
	break;}}*/

initialiservie_score(&v,score);
gest_vie (&v,&hero,&o);
affichvie(&v,&screen);
loadFont();
 closeFont();
calculate(score,&hero,&s);
DrawScore(&screen,score);

SDL_FreeSurface(screen);
return 0;
}
