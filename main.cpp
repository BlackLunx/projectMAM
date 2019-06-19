
#include <SFML/Graphics.hpp>
#include "menu.cpp"
//#include "game.cpp"
int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!");


    menu(window);
}

