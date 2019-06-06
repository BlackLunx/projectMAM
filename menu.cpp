//
// Created by JG on 03.06.2019.
//
#include <SFML/Graphics.hpp>
#include "game.cpp"
#include <vector>
#include <iostream>
using namespace sf;

void selectLevel(RenderWindow& window);

void menu(RenderWindow &window){

    Texture newGame_TX1, newGame_TX2, exit_TX1, exit_TX2, background_TX, cursorTX;
    newGame_TX1.loadFromFile("Images/newgamefirst.png");
    newGame_TX2.loadFromFile("Images/newgamesecond.png");

    exit_TX1.loadFromFile("Images/exitfirst.png");
    exit_TX2.loadFromFile("Images/exitsecond.png");

    background_TX.loadFromFile("Images/mainpicture.png");
    cursorTX.loadFromFile("Images/cursor.png");


    Sprite newGameSP(newGame_TX1), newGameSPHL(newGame_TX2), exitSP(exit_TX1), exitSPHL(exit_TX2), backgroundSP(background_TX), cursorSP(cursorTX);

    newGameSP.setPosition(800, 200);
    exitSP.setPosition(800, 260);
    newGameSPHL.setPosition(800, 200);
    exitSPHL.setPosition(800, 260);

    while(window.isOpen()){
        int currentPosition = 0;

        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
                exit(0);
            }
        }
        if(IntRect(800, 200, 150, 40).contains(Mouse::getPosition(window))){
            currentPosition = 1;
            cursorSP.setPosition(static_cast<Vector2f>(Mouse::getPosition(window)));
        }
        if(IntRect(800, 260, 150, 40).contains(Mouse::getPosition(window))){
            currentPosition = 2;
            cursorSP.setPosition(static_cast<Vector2f>(Mouse::getPosition(window)));
        }
        if(Mouse::isButtonPressed(Mouse::Left)){
            if(currentPosition == 1){
                selectLevel(window);
                //startGame(window);
            }
            if(currentPosition == 2){
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

void selectLevel(RenderWindow& window){

    Texture backgroundTX, cursorTX;
    backgroundTX.loadFromFile("Images/levelMenu.png");
    cursorTX.loadFromFile("Images/cursor.png");

    std::vector<Texture> textures(8);
    textures[0].loadFromFile("Images/easyFirst.png");
    textures[1].loadFromFile("Images/easySecond.png");

    textures[2].loadFromFile("Images/mediumFirst.png");
    textures[3].loadFromFile("Images/mediumSecond.png");

    textures[4].loadFromFile("Images/hardFirst.png");
    textures[5].loadFromFile("Images/hardSecond.png");

    textures[6].loadFromFile("Images/backFirst.png");
    textures[7].loadFromFile("Images/backSecond.png");

    Sprite background(backgroundTX), cursorSP(cursorTX);

    std::vector<std::pair<Sprite, Sprite> > draws(4);
    for(int i = 0;i < 4;i++){
        draws[i].first.setTexture(textures[i * 2]);
        draws[i].second.setTexture(textures[i * 2 + 1]);
        draws[i].first.setPosition(800, 200 + i * 60);
        draws[i].second.setPosition(800, 200 + i * 60);
    }

    while(window.isOpen()){


        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
                exit(0);
            }
        }
        std::vector<int> isHere(4, 0);


        for(int i = 0;i < 4;i++){
            if(IntRect(800, 200 + i * 60, 150, 40).contains(Mouse::getPosition(window))){
                isHere[i] = 1;
                cursorSP.setPosition(static_cast<Vector2f>(Mouse::getPosition(window)));
            }
        }
        if(Mouse::isButtonPressed(Mouse::Left)){
            for(int i = 0;i < 3;i++) if(isHere[i]){
                //startGame(window, i);
            }
            if(isHere[3]){
                return;
            }
        }
        window.clear();
        window.draw(background);
        bool wasInButton = false;
        for(int i = 0;i < 4;i++){
            if(isHere[i]){
                window.draw(draws[i].second);
                wasInButton = 1;
            }
            else{
                window.draw(draws[i].first);
            }
        }
        window.setMouseCursorVisible(!wasInButton);
        if(wasInButton){
            window.draw(cursorSP);
        }
        window.display();
    }

}