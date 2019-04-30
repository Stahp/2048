#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <time.h>
#define MAX_IMAGES 13
#define TAILLE 50
#define COTE 4
SDL_Surface *ecran= NULL, *tiles[MAX_IMAGES];
int etat[COTE][COTE];
int something_happened =0;
SDL_Event event;
SDL_Rect pos;
void actualiser()
{
    int i, j;
    for(i=0; i< COTE; i++)
    {
        for(j=0; j< COTE; j++)
        {
            pos.x= j* TAILLE;
            pos.y= i* TAILLE;
            SDL_BlitSurface(tiles[etat[i][j]], NULL, ecran, &pos);
        }
    }
    SDL_Flip(ecran);
}
void mouvement()
{
    int i, j, l;
    switch(event.key.keysym.sym)
    {
    case SDLK_DOWN:
        for(j=0; j< COTE; j++)
        {
            for(i=COTE-1; i>0; i--)// sommation des nombres égaux
            {
                if(etat[i][j]!=0)
                {
                    l=i-1;
                    while(l>=0 && etat[l][j]==0) // sort de cette boucle si l<0 ou etat[l][j]!=0
                        l--;
                    if(l>=0 && etat[l][j]==etat[i][j])
                    {
                        etat[l][j]= 0;
                        etat[i][j]++;
                        something_happened=1;
                    }
                }
            }
            for(i=COTE-1; i>0; i--)
            {
                if(etat[i][j]==0)
                {
                    l=i-1;
                    while(l>=0 && etat[l][j]==0)// sort de cette boucle si l<0 ou etat[l][j]!=0
                        l--;
                    if(l>=0)
                    {
                        etat[i][j]= etat[l][j];
                        etat[l][j]= 0;
                        something_happened=1;
                    }
                }
            }
        }
        break;
    case SDLK_UP:
        for(j=0; j< COTE; j++)
        {
            for(i=0; i< COTE-1; i++)// sommation des nombres égaux
            {
                if(etat[i][j]!=0)
                {
                    l=i+1;
                    while(l<COTE && etat[l][j]==0) // sort de cette boucle si l>= cote ou etat[l][j]!=0
                        l++;
                    if(l< COTE && etat[l][j]==etat[i][j])
                    {
                        etat[l][j]= 0;
                        etat[i][j]++;
                        something_happened=1;
                    }
                }
            }
            for(i=0 ; i<COTE-1; i++)
            {
                if(etat[i][j]==0)
                {
                    l=i+1;
                    while(l<COTE && etat[l][j]==0)// sort de cette boucle si l<0 ou etat[l][j]!=0
                        l++;
                    if(l< COTE)
                    {
                        etat[i][j]= etat[l][j];
                        etat[l][j]= 0;
                        something_happened=1;
                    }
                }
            }
        }
        break;
    case SDLK_LEFT:
        for(j=0; j< COTE; j++)
        {
            for(i=0; i< COTE-1; i++)// sommation des nombres égaux
            {
                if(etat[j][i]!=0)
                {
                    l=i+1;
                    while(l<COTE && etat[j][l]==0) // sort de cette boucle si l>= cote ou etat[l][j]!=0
                        l++;
                    if(l< COTE && etat[j][l]==etat[j][i])
                    {
                        etat[j][l]= 0;
                        etat[j][i]++;
                        something_happened=1;
                    }
                }
            }
            for(i=0 ; i<COTE-1; i++)
            {
                if(etat[j][i]==0)
                {
                    l=i+1;
                    while(l<COTE && etat[j][l]==0)// sort de cette boucle si l<0 ou etat[l][j]!=0
                        l++;
                    if(l< COTE)
                    {
                        etat[j][i]= etat[j][l];
                        etat[j][l]= 0;
                        something_happened=1;
                    }
                }
            }
        }
        break;
    case SDLK_RIGHT:
        for(j=0; j< COTE; j++)
        {
            for(i=COTE-1; i>0; i--)// sommation des nombres égaux
            {
                if(etat[j][i]!=0)
                {
                    l=i-1;
                    while(l>=0 && etat[j][l]==0) // sort de cette boucle si l<0 ou etat[l][j]!=0
                        l--;
                    if(l>=0 && etat[j][l]==etat[j][i])
                    {
                        etat[j][l]= 0;
                        etat[j][i]++;
                        something_happened=1;
                    }
                }
            }
            for(i=COTE-1; i>0; i--)
            {
                if(etat[j][i]==0)
                {
                    l=i-1;
                    while(l>=0 && etat[j][l]==0)// sort de cette boucle si l<0 ou etat[l][j]!=0
                        l--;
                    if(l>=0)
                    {
                        something_happened=1;
                        etat[j][i]= etat[j][l];
                        etat[j][l]= 0;
                    }
                }
            }
        }
        break;
    default:
        break;
    }
}
void charger_images()
{
    tiles
    [0]= SDL_LoadBMP("images/0.bmp");
    tiles[1]= SDL_LoadBMP("images/2.bmp");
    tiles[2]= SDL_LoadBMP("images/4.bmp");
    tiles[3]= SDL_LoadBMP("images/8.bmp");
    tiles[4]= SDL_LoadBMP("images/16.bmp");
    tiles[5]= SDL_LoadBMP("images/32.bmp");
    tiles[6]= SDL_LoadBMP("images/64.bmp");
    tiles[7]= SDL_LoadBMP("images/128.bmp");
    tiles[8]= SDL_LoadBMP("images/256.bmp");
    tiles[9]= SDL_LoadBMP("images/512.bmp");
    tiles[10]= SDL_LoadBMP("images/1024.bmp");
    tiles[11]= SDL_LoadBMP("images/2048.bmp");
    tiles[12]= SDL_LoadBMP("images/4096.bmp");
}
void init()
{
    int i, j, i1, j1, i2, j2;// this can be optimized by using only i1 & j1
    i1= rand()%COTE;
    j1= rand()%COTE;
    i2= rand()%COTE;
    j2= rand()%COTE;
    for(i=0; i< COTE; i++)
    {
        for(j=0; j< COTE; j++)
        {
            etat[i][j]= (i1==i)*(j1==j) +(i2==i)*(j2==j);
            pos.x= j* TAILLE;
            pos.y= i* TAILLE;
            SDL_BlitSurface(tiles[etat[i][j]], NULL, ecran, &pos);
        }
    }
    SDL_Flip(ecran);
}
void new_tile()
{
    int i1, j1;
    do{
        i1= rand()%COTE;
        j1= rand()%COTE;
    }while(etat[i1][j1]!=0);
    etat[i1][j1]=1;
}
void vider()
{
    int i;
    for(i=0; i<MAX_IMAGES; i++)
    {
        SDL_FreeSurface(tiles[i]);
    }
    SDL_Quit();
}

int main ( int argc, char** argv )
{
    int continuer =1;
    SDL_Init(SDL_INIT_EVERYTHING);
    srand(time(NULL));
    SDL_WM_SetCaption("2048", NULL);
    charger_images();
    ecran= SDL_SetVideoMode(COTE*TAILLE, COTE*TAILLE, 32, SDL_HWSURFACE| SDL_DOUBLEBUF);
    init();
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer =0;
            break;
        case SDL_KEYDOWN:
            something_happened=0;
            mouvement();
            if(something_happened)
            {
                new_tile();
                actualiser();
            }
            break;
        }
    }
    vider();
    return 0;
}
