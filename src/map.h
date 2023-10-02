
#ifndef MAP
#define MAP

#include <SDL2/SDL.h>
#include <vector>
class oiseau
{
public:
    SDL_Rect clip1, clip2, hitbox, clipActuel;
    int animation = 1;
    void set_clips();
};

class nuage
{
public:
    SDL_Rect hitbox, clipActuel;

    void set_clips();
};

class cactus
{
public:
    SDL_Rect hitbox, clipActuel, chooseClip[10];
    int animation = 1;
    void set_clipsCactus();
};

class map
{
private:
    SDL_Rect sol, clips[10];
    cactus cac[500];
    oiseau oi[500];
    nuage nu[500];

    SDL_Texture *imageOiseau;
    int vx, spawnRate, indiceNuage = 0, indiceCactus = 0, indiceOiseau = 0;
    long timer;
    bool spawn = true, close;

    bool mode1 = true, increaseSpeed = true;

public:
    map(SDL_Renderer *rend, bool choix);
    ~map();
    bool getClose();
    void setClose();
    void show(SDL_Renderer *rend);
    void addObstacle(SDL_Renderer *rend);
    void moveObstacle();

    void chooseClip();
    int getIndiceOiseau();
    int getIndiceCactus();
    cactus *getCactus();
    oiseau *getOiseau();
    bool getMode();
    void setMode(bool choix);
    void ActuVitesse();
};

#endif