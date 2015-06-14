#ifndef RENDER_H
#define RENDER_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Lsystem.h"
#include <math.h>

const double Distance = 2;
const double Angle = 25;

struct Position
{
    double x;
    double y;
    double angle;

    Position(int _x, int _y, int _angle) : x(_x), y(_y), angle(_angle) {}
};

class Render
{
    public:
        Render(sf::RenderWindow* _window);
        virtual ~Render();

        void drawLsystem(Lsystem lsystem);

    protected:

    private:
        sf::RenderWindow* window;


};

#endif // RENDER_H
