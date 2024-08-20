#include "player.h"

float sunCenterX = Game::WINDOWCENTERX; // x cord of sun center
float sunCenterY = Game::WINDOWCENTERY; // y cord of sun center


void DrawCelestialObjects::DrawCelestial(SDL_Renderer* renderer, int centerX, int centerY, int radius, SDL_Color color) {
    const int numSegments = 400; // Number of segments to aprox the circle

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    for (int i = 0; i < numSegments; ++i) {
        double angle1 = 2.0 * M_PI * i / numSegments; // Angle for current segment
        double angle2 = 2.0 * M_PI * (i + 1) / numSegments; // Angle for next segment

        // Calculate the points on the edge of the circle
        int x1 = centerX + radius * cos(angle1);
        int y1 = centerY + radius * sin(angle1);
        int x2 = centerX + radius * cos(angle2);
        int y2 = centerY + radius * sin(angle2);

        // Draw the Triangle
        SDL_RenderDrawLine(renderer, centerX, centerY, x1, y1);
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        SDL_RenderDrawLine(renderer, x2, y2, centerX, centerY);
    }
}

void DrawCelestialObjects::moveMercury(SDL_Renderer* renderer) {
    float orbitRadiusMercury = 160.f; // Orbit radius for mercury
    float angularVelocityMercury = 0.009f; // Angular velocity for mercury (radians per frame)
    static float angleMercury = 0.0f; // Starting Angle

    angleMercury += angularVelocityMercury; // Update the angle
    if (angleMercury >= 2 * M_PI) angleMercury -= 2 * M_PI; // Keep angle within [0, 2*pi]

    float mercuryX = sunCenterX + orbitRadiusMercury * cos(angleMercury);
    float mercuryY = sunCenterY + orbitRadiusMercury * sin(angleMercury);

    DrawCelestial(renderer, mercuryX, mercuryY, 20, MERCURY);
}


void DrawCelestialObjects::moveVenus(SDL_Renderer* renderer) {
    float orbitRadiusVenus = 230.f;
    float angularVelocityVenus = 0.008f;
    static float angleVenus = 0.0f;

    angleVenus += angularVelocityVenus; // Update the angle
    if (angleVenus >= 2 * M_PI) angleVenus -= 2 * M_PI; // Keep angle within [0, 2*pi]

    float VenusX = sunCenterX + orbitRadiusVenus * cos(angleVenus);
    float VenusY = sunCenterY + orbitRadiusVenus * sin(angleVenus);

    DrawCelestial(renderer, VenusX, VenusY, 30, VENUS);
}

void DrawCelestialObjects::moveEarth(SDL_Renderer* renderer) {
    float orbitRadiusEarth = 300.f;
    float angularVelocityEarth = 0.007f;
    static float angleEarth = 0.0f;

    angleEarth += angularVelocityEarth; // Update the angle
    if (angleEarth >= 2 * M_PI) angleEarth -= 2 * M_PI; // Keep angle within [0, 2*pi]

    float EarthX = sunCenterX + orbitRadiusEarth * cos(angleEarth);
    float EarthY = sunCenterY + orbitRadiusEarth * sin(angleEarth);

    DrawCelestial(renderer, EarthX, EarthY, 35, BLUE);
}

void DrawCelestialObjects::moveMars(SDL_Renderer* renderer) {
    float orbitRadiusMars = 370.f;
    float angularVelocityMars = 0.006f;
    static float angleMars = 0.0f;

    angleMars += angularVelocityMars; // Update the angle
    if (angleMars >= 2 * M_PI) angleMars -= 2 * M_PI; // Keep angle within [0, 2*pi]

    float MarsX = sunCenterX + orbitRadiusMars * cos(angleMars);
    float MarsY = sunCenterY + orbitRadiusMars * sin(angleMars);

    DrawCelestial(renderer, MarsX, MarsY, 25, MARS);
}

void DrawCelestialObjects::drawStars(SDL_Renderer* renderer) {
     std::random_device rd; // Seed gen
     std::mt19937 gen(rd()); // engine

     std::vector<SDL_Color> colors = {GREEN, PINK, ELECTRICBLUE, YELLOW};

     // Create a distribution for integers in a specified range
     std::uniform_int_distribution<> distrX(0, Game::WINDOW_WIDTH);
     std::uniform_int_distribution<> distrY(0, Game::WINDOW_HEIGHT);
     std::uniform_int_distribution<> distrColor(0, colors.size() - 1);

     for (int i = 0; i < 500; i++) {
        // Generate the random number
        int randomX = distrX(gen);
        int randomY = distrY(gen);

        // Generate random color index
        int randomColorIndex = distrColor(gen);
        SDL_Color randomColor = colors[randomColorIndex];

        SDL_SetRenderDrawColor(renderer, randomColor.r, randomColor.g, randomColor.b, randomColor.a);
        SDL_RenderDrawPoint(renderer, randomX, randomY);
    }
}
