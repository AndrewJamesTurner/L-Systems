#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

int main()
{
    std::string str = "AndyIsGreat";
    str = str.substr(4,1) + str.substr(7,100);

    std::cout << str;


    /*
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Default, settings);

    sf::CircleShape shape(50);
    shape.setPosition(50, 50);
    shape.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape line(sf::Vector2f(150, 5));
    line.rotate(45);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
         window.draw(shape);
         window.draw(line);

        // end the current frame
        window.display();
    }
*/
    return 0;
}
