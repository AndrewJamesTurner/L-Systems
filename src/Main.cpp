#include <SFML/Graphics.hpp>
#include "Lsystem.h"
#include "Render.h"

int main(void){

    //double angle = 10;





   // std::cout << lsystem;

   // lsystem.iterate();

    // create the window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000, 800), "My window", sf::Style::Default, settings);

    // create the renderer
    Render render(&window);

    // run the program as long as the window is open
    while (window.isOpen())
    {

        Lsystem lsystem("F");

        for(int i=0; i<rand() % 6 + 3; i++)
            lsystem.iterate();

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
        render.drawLsystem(lsystem, rand() % 10 + 3, rand() % 20 + 15);

        // end the current frame
        window.display();

       // std::cin.get();

//        angle++;
    }


    return 0;
}



/*

Lsystem lsystem("X");

    for(int i = 0; i< 4; i++){
        std::cout << "n = " << i << "\n" <<lsystem << "\n\n";
        lsystem.iterate();
    }


    std::cout << lsystem.getWord();

*/
