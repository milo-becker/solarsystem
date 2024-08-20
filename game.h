#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game {
public:
    static const int WINDOW_WIDTH;
    static const int WINDOW_HEIGHT;
    static const int WINDOWCENTERX;
    static const int WINDOWCENTERY;

    Game();
    bool init();
    void run();
    void cleanup();
private:
    void update();
    void render();

    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
};

#endif // GAME_H

