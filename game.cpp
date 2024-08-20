#include "game.h"
#include "player.h"

#include <SDL2/SDL.h>

const int Game::WINDOW_WIDTH = 1200;
const int Game::WINDOW_HEIGHT = 1000;
const int Game::WINDOWCENTERX= Game::WINDOW_WIDTH / 2;
const int Game::WINDOWCENTERY= Game::WINDOW_HEIGHT / 2;

DrawCelestialObjects drawObject;

Game::Game() : window(nullptr), renderer(nullptr), running(false) {}

bool Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initalize! SDL_Error: %s", SDL_GetError());
    }

    window = SDL_CreateWindow("Solar System", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        SDL_Log("Window could not be created! SDL_Error: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        SDL_Log("Renderer could not be created! SDL_Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    running = true;
    return true;
}

void Game::run() {
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e) !=0) {
            if (e.type == SDL_QUIT) {
                    running = false;
            }
        }

        update();
        render();

        SDL_Delay(16); // Simulate ~60fps
    }

    cleanup();

}

void Game::update() {
    //Game logic
    drawObject.moveMercury(renderer);
    drawObject.moveVenus(renderer);
    drawObject.moveEarth(renderer);
    drawObject.moveMars(renderer);
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 4, 4, 7, 255);
    SDL_RenderClear(renderer);

    // Draw game objects here
    drawObject.DrawCelestial(renderer, WINDOWCENTERX, WINDOWCENTERY, 100, PLAYER_H::ORANGE);// Sun
    drawObject.moveMercury(renderer);
    drawObject.moveVenus(renderer);
    drawObject.moveEarth(renderer);
    drawObject.moveMars(renderer);
    drawObject.drawStars(renderer);


    SDL_RenderPresent(renderer);
}

void Game::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}






















