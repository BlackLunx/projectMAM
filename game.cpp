//
// Created by JG on 03.06.2019.
//
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
void startGame(RenderWindow &window, std::vector<std::vector<int> > &left, std::vector<std::vector<int> > &top){

    Texture twoConditions, background, numbers;
    twoConditions.loadFromFile("Image/conditions.png");
    background.loadFromFile("Image/backgroundForGame.png");
    numbers.loadFromFile("Image/numbers.png");

    std::vector<Sprite> number(9);
    for(int i = 0;i < 9;i++){
        number[i].setTexture(numbers);
        number[i].setTextureRect(IntRect(10 * i, 0, 10 * (i + 1), 10));
    }
    Sprite firstCondition(twoConditions), secondCondition(twoConditions);
    firstCondition.setTextureRect(IntRect(0, 0, 10, 10));
    secondCondition.setTextureRect(IntRect(10, 0, 20, 10));



}