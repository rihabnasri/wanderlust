#include  "fonctionr.h"


void initialiservie_score (Vie *v,int score)
{ 
v->nbr_vie=3;
int score=0;
v->pos.w=v->image_vie->w;
v->pos.h=v->image_vie->h;
v->pos.x=0;
v->pos.y=0;
}
 
void gest_vie (Vie *v,perso *hero,ENTITE_SECONDAIRE_object *o)
{
  if (collision_object (&hero,&o)==1)
     {v->nbr_vie--;}
}

void affichvie(Vie *v,SDL_Surface *screen)
{       
         if(v->nbr_vie==3)
         {
           v->coeur3=IMG_Load("coeur3.png");
           SDL_BlitSurface(v->image_vie,&v->pos,screen,NULL);
          }
        if(v->nbr_vie==2)
         {
           v->coeur2=IMG_Load("coeur2.png");
           SDL_BlitSurface( v->coeur1,&v->pos,screen,NULL);
         }
      if(v->nbr_vie==1)
        {
         v->coeur1=IMG_Load("coeur1.png");
         SDL_BlitSurface( v->coeur2,&v->pos,screen,NULL);
        }    
      if(v->nbr_vie==0)
         {       
            v->coeur0=IMG_Load("coeur0.png");
            SDL_BlitSurface( v->coeur3,&v->pos,screen,NULL);
           // enigme();
          }
}
///*****code score*****///

void loadFont()
{TTF_Font *font ;
	font = TTF_OpenFont("Walkway Bold.TTF", 56);
	if (font == NULL)
        {
	printf("Can not to open Font : %s\n", TTF_GetError());
		exit(1);
	}
}
void closeFont()
{ TTF_Font *font ;
	if (font != NULL)
        {
		TTF_CloseFont(font);
	}
}
void calculate(int score,ENTITE_SECONDAIRE_STAR *s,perso *hero)
{
	if (collision_star (&hero,&s);==1)
        {
		score += 5;
	}

}
void DrawScore(SDL_Surface *screen, int score)
{
TTF_Font *font;
font = TTF_OpenFont("Walkway Bold.TTF", 56);
        char actualScore[100];
        SDL_Color color;
        color.r = 255 ;
        color.g = 255 ;
        color.b = 255 ;
        sprintf (actualScore,"%d",score);
        SDL_Rect pospoints;
        pospoints.x=600;
        pospoints.y=30;
        game.points =TTF_RenderText_Blended(font,actualScore,color);
        SDL_BlitSurface	(game.points,NULL,screen,&pospoints);

}
