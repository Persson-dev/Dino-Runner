// Include
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
using namespace std;
#include <string.h>
#include <cstdio>
#include <SDL2/SDL_mixer.h>
#include "SDL2/SDL_image.h"
#include "dino.cpp"

/// @brief
/// @return

int main()
{

    srand(time(NULL));
    // Initialisation
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Erreur lors de l'initialisation de SDL: %s\n", SDL_GetError());
        return 1;
    }
    if (TTF_Init() == -1)
    {
        printf("TTF_Init: %s\n", TTF_GetError());
        return 1;
    }
    if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
    {
        SDL_Log("Erreur initialisation SDL_mixer : %s", Mix_GetError());
        SDL_Quit();
        return -1;
    }

    // Initialisation window

    SDL_Window *win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);

    dino d(rend);

    map m(rend);

    bool stop = false;

    SDL_Event event;
    while (!stop)
    {

        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

        SDL_RenderClear(rend);

        d.chooseClip();

        d.show(rend);

        m.show(rend);

        d.moveDino(event, m, stop);

        d.Gravity();

        m.addObstacle(rend);

        m.moveObstacle();

        m.chooseClip();

        // d.collision(m);

        SDL_RenderPresent(rend);
        SDL_Delay(1000 / 60);
    }

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);

    Mix_CloseAudio();

    SDL_Quit();
    return 0;
}
