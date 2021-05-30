#include <SFML/Graphics.hpp>
#include "ManagerScreen.h"

int main()
{
    ManagerScreen s;

    s.main_run();


    /*auto window = sf::RenderWindow(sf::VideoMode(300, 300), "Example");

    while (window.isOpen())
    {
        window.clear();
        window.display();

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
    }
    */
}
