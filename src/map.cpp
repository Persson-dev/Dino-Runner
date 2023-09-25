#include "map.h"
#include <iostream>
using namespace std;

void sup_case(int i, int &indice, SDL_Rect elt[100])
{
    // Supprime une case d'un tab de block
    for (int y = i; y <= indice; y++)
    {
        elt[y] = elt[y + 1];
    }
}

void initialiseMap(map &m)
{

    m.spawn = true;

    SDL_Rect sol;
    sol.h = 100;
    sol.w = 2000;
    sol.x = -20;
    sol.y = 500;

    m.elt[0] = sol;
    m.indice = 0;

    SDL_Rect oiseau;
    oiseau.h = 30;
    oiseau.w = 30;
    oiseau.x = 500;
    oiseau.y = 410;

    SDL_Rect cactus;
    cactus.h = 40;
    cactus.w = 30;
    cactus.x = 500;
    cactus.y = 470;

    m.obstacles[0] = oiseau;
    m.obstacles[1] = cactus;
}

void afficherMap(map &m, SDL_Renderer *rend)
{
    for (int i = 0; i <= m.indice; i++)
    {
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderFillRect(rend, &m.elt[i]);
    }
}

void actualiserMap(map &m)
{
    long time = SDL_GetTicks();
    int nb = rand() % 2;

    if ((time / 1000) % 3 == 0 && m.spawn == true)
    {
        m.spawn = false;
        cout << nb << endl;

        switch (nb)
        {
        case 0:
            m.indice += 1;
            m.elt[m.indice] = m.obstacles[0];
            break;

        case 1:
            m.indice += 1;
            m.elt[m.indice] = m.obstacles[1];
            break;

        default:
            break;
        }
    }

    for (int i = 1; i <= m.indice; i++)
    {
        if (m.elt[i].x < -20)
        {
            sup_case(i, m.indice, m.elt);
            m.indice -= 1;
        }
        else

        {
            m.elt[i].x -= 3;
        }
    }
    if ((time / 1000) % 3 != 0 && m.spawn == false)
    {
        m.spawn = true;
    }
}