#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <cmath>
#include <random>
#include <iostream>
#include "game.h"

extern float sunCenterX;
extern float sunCenterY;

const SDL_Color ORANGE = {255, 108, 0, 255};
const SDL_Color MERCURY = {169, 169, 169, 255};
const SDL_Color VENUS = {218, 110, 56, 255};
const SDL_Color BLUE  = {44, 44, 195, 255};
const SDL_Color MARS  = {218, 56, 66, 255};
const SDL_Color WHITE  = {255, 255, 255, 255};
const SDL_Color GREEN  = {170, 255, 85, 255};
const SDL_Color PINK = {255, 85, 255, 255};
const SDL_Color ELECTRICBLUE  = {85, 170, 255, 255};
const SDL_Color YELLOW  = {255, 255, 85, 255};

class DrawCelestialObjects{
public:
    void DrawCelestial(SDL_Renderer* renderer, int centerX, int centerY, int radius, SDL_Color color);
    void moveMercury(SDL_Renderer* renderer);
    void moveVenus(SDL_Renderer* renderer);
    void moveEarth(SDL_Renderer* renderer);
    void moveMars(SDL_Renderer* renderer);

    void drawStars(SDL_Renderer* renderer);
};

#endif // PLAYER_H

