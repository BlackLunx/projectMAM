//
// Created by JG on 03.06.2019.
//
#include <SFML/Graphics.hpp>
#include "game.cpp"
using namespace sf;
void menu(RenderWindow &window){

    Texture newGame_TX1, newGame_TX2, exit_TX1, exit_TX2, background_TX, cursorTX;
    newGame_TX1.loadFromFile("Images/newgamefirst.png");
    newGame_TX2.loadFromFile("Images/newgamesecond.png");
    exit_TX1.loadFromFile("Images/exitfirst.png");
    exit_TX2.loadFromFile("Images/exitsecond.png");
    background_TX.loadFromFile("Images/mainpicture.png");
    cursorTX.loadFromFile("Images/cursor.png");


    Sprite newGameSP(newGame_TX1), newGameSPHL(newGame_TX2), exitSP(exit_TX1), exitSPHL(exit_TX2), backgroundSP(background_TX), cursorSP(cursorTX);

    backgroundSP.setPosition(0, 0);
    newGameSP.setPosition(800, 200);
    exitSP.setPosition(800, 260);
    newGameSPHL.setPosition(800, 200);
    exitSPHL.setPosition(800, 260);
    int inMenu = 1;
    while(inMenu){
        int currentPosition = 0;
        window.clear(Color(129, 181, 221));
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
                exit(0);
            }
        }
        if(IntRect(800, 200, 950, 240).contains(Mouse::getPosition(window))){
            currentPosition = 1;
            cursorSP.setPosition(static_cast<Vector2f>(Mouse::getPosition(window)));
        }
        if(IntRect(800, 260, 950, 300).contains(Mouse::getPosition(window))){
            currentPosition = 2;
            cursorSP.setPosition(static_cast<Vector2f>(Mouse::getPosition(window)));
        }
        if(Mouse::isButtonPressed(Mouse::Left)){
            if(currentPosition == 1){
                inMenu = 0;
                window.close();
                //startGame(window);
            }
            if(currentPosition == 2){
                inMenu = 0;
                window.close();

            }
        }
        window.clear();
        window.draw(backgroundSP);
        if(currentPosition == 1){
            window.setMouseCursorVisible(false);
            window.draw(newGameSPHL);
            window.draw(exitSP);
            window.draw(cursorSP);
        }
        else{
            window.draw(newGameSP);
            if(currentPosition == 2){
                window.setMouseCursorVisible(false);
                window.draw(exitSPHL);
                window.draw(cursorSP);
            }
            else{
                window.setMouseCursorVisible(true);
                window.draw(exitSP);
            }
        }
        window.display();
    }



}