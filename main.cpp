#include <SFML/Graphics.hpp>
using namespace sf;
int main(){

    RenderWindow window(VideoMode(480, 360), "SFML works!");
    Image  firstImage;
    firstImage.loadFromFile("Images/lol.jpg");

    Texture firstTexture;
    firstTexture.loadFromImage(firstImage);

    Sprite firstSprite;
    firstSprite.setTexture(firstTexture);
    firstSprite.setTextureRect(IntRect(0, 10, 100, 100));
    firstSprite.setPosition(50, 25);
вуцвуцвц
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(firstSprite);
        window.display();
    }

    return 0;
}