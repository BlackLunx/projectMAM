#include <SFML/Graphics.hpp>
#include "menu.cpp"
#include "game.cpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1190, 800), "SFML works!");


    menu(window);
    return 0;
}