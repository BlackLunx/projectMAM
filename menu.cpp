//
// Created by JG on 03.06.2019.
//
#include <SFML/Graphics.hpp>
using namespace sf;
void menu(Window &window){
    Texture newGameTX, exitTX, backgroundTX, nameTX;
    newGameTX.loadFromFile("Images/newGame.png");
    exitTX.loadFromFile("Images/exit.png");
    backgroundTX.loadFromFile("Images/background.png");
    nameTX.loadFromFile("Images/name.png");

    Sprite newGameSP(newGameTX), exitSP(exitTX), backgroundSP(backgroundTX), nameSP(nameTX);

    newGameSP.setPosition(100, 45);
    exitSP.setPosition(100, 90);
    backgroundSP.setPosition(345, 0);
    nameSP.setPosition(100, 30);
    int inMenu = 1;
    while(inMenu){
        int currentPosition = 0;
        if(IntRect(100, 30, 300, 50).contains(Mouse::getPosition())){
            currentPosition = 1;
        }
        if(IntRect(100, 90, 300, 50).contains(Mouse::getPosition())){
            currentPosition = 2;
        }
        if(Mouse::isButtonPressed(Mouse::Left)){
            if(currentPosition == 1){
                inMenu = 0;
                startGame(window);
            }
            if(currentPosition == 2){
                inMenu = 0;
                window.close();
            }
        }
        window.clear();
        window.draw(backgroundSP);
        window.draw(nameSP);
        if(currentPosition == 1){
            window.draw(newGameSPHL)
        }
        else{
            window.draw(newGameSP);
            if(currentPosition == 2){
                window.draw(exitSPHL)
            }
            else{
                window.draw(exitSP);
            }
        }
        window.display();
    }



}