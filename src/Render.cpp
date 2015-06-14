#include "Render.h"

Render::Render(sf::RenderWindow* _window) : window{_window}
{
    //ctor
}

Render::~Render()
{
    //dtor
}


void Render::drawLsystem(Lsystem lsystem){



    std::string word = lsystem.getWord();
    Position currentPosition = Position(window->getSize().x/2,window->getSize().y,-90);


    // a 'stack' for storing the positions
    std::vector<Position> positionStack;
    //PositionStack.push_back(Position(window->getSize().x/2,window->getSize().y,-90));

    //std::cout << currentPosition.x << ", " << currentPosition.y << ", " << currentPosition.angle << "\n";


    for(auto i = word.begin(); i != word.end(); i++){

        if(*i == 'F'){

            sf::RectangleShape line(sf::Vector2f(Distance, 2));
            line.setPosition(currentPosition.x, currentPosition.y);
            line.setRotation(currentPosition.angle);
            window->draw(line);

            currentPosition.x += Distance * cos(currentPosition.angle * M_PI / 180.0);
            currentPosition.y += Distance * sin(currentPosition.angle  * M_PI / 180.0);
        }

        else if(*i == '-'){
            currentPosition.angle -= Angle;
        }

        else if(*i == '+'){
            currentPosition.angle += Angle;
        }

        else if(*i == '['){
            positionStack.push_back(currentPosition);
        }

        else if(*i == ']'){
            currentPosition.x = positionStack.back().x;
            currentPosition.y = positionStack.back().y;
            currentPosition.angle = positionStack.back().angle;
            positionStack.pop_back();
        }
    }

   // std::cin.get();
}
