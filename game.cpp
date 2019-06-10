#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <sstream>

template<typename T> std::string toString(T val){std::ostringstream oss; oss << val; return oss.str();}
using namespace std;
using namespace sf;
vector<vector<char> > desk;
int maxy = 0, maxx = 0;
pair<vector<vector<int> >, vector<vector<int> > > generateLevel(string s) {
    desk.clear();
    maxy = 0, maxx = 0;
    cout << s;
    ifstream fin;
    fin.open(s);
    int sizex, sizey;

    fin >> sizex >> sizey;
    vector<vector<int> > horisontal(sizey);
    desk.resize(sizey);
    for(int i = 0;i < sizey;i++){
        desk[i].resize(sizex);
    }
    int n = 0;
    for (int i = 0; i < sizey; i++) {
        for (int j = 0; j < sizex; j++) {
            fin >> desk[i][j];
            if (desk[i][j] == '1') {
                n++;
            } else if (n != 0) {
                horisontal[i].push_back(n);
                //cout << horisontal[i].back() << ' ';
                n = 0;
            }
            if ((n != 0) && (j == (sizex - 1))) {
                horisontal[i].push_back(n);
                //cout << horisontal[i].back() << ' ';
                n = 0;
            }
        }
        maxy = max(maxy, (int)horisontal[i].size());
        //cout << endl;
    }
    n = 0;
    vector<vector<int> > vertical(sizex);
    for (int i = 0; i < sizex; i++) {
        for (int j = 0; j < sizey; j++) {
            if (desk[j][i] == '1') {
                n++;
            } else if (n != 0) {
                vertical[i].push_back(n);
               // cout << vertical[i].back() << ' ';
                n = 0;
            }
            if ((n != 0) && (j == (sizey - 1))) {
                vertical[i].push_back(n);
                //cout << vertical[i].back() << ' ';
                n = 0;
            }

        }
        maxx = max(maxx, (int)vertical[i].size());
        //cout << endl;
    }
    return {vertical, horisontal};
}
void startGame(RenderWindow &window,int level){
    window.setMouseCursorVisible(1);
    string path = "tests/";
    switch (level){
        case 0:
            path += "easy/";
            break;
        case 1:
            path += "normal/";
            break;
        case 2:
            path += "hard/";
            break;
        default:
            return;
    }
    mt19937 gen;
    gen.seed('J' + 'O' + 'P' + 'A' + time(0));
    int newNum = gen() % 15 + 1;
    path += toString(newNum) + ".txt";
    auto newVectors = generateLevel(path);
    Texture backgroundTX, cursorTX;
    backgroundTX.loadFromFile("Images/levelMenu.png");
    cursorTX.loadFromFile("Images/cursor.png");

    Texture back1, back2;
    back1.loadFromFile("Images/backFirst.png");
    back2.loadFromFile("Images/backSecond.png");

    Texture gameTX;
    gameTX.loadFromFile("Images/gameOver.png");
    Sprite game(gameTX);
    game.setPosition(270, 230);
    Sprite back_1(back1), back_2(back2);
    Texture field, blackElement, crossElement;
    field.loadFromFile("Images/field30x30.png");
    vector<vector<int> > fieldArr(30, vector<int>(30, 0));
    blackElement.loadFromFile("Images/blackElement.png");
    crossElement.loadFromFile("Images/crossElement.png");
    Texture numbers;
    numbers.loadFromFile("Images/numbers.png");
    back_1.setPosition(40, 40);
    back_2.setPosition(40, 40);
    Sprite fieldSP(field), black(blackElement), cross(crossElement), background(backgroundTX), cursor(cursorTX);
    Sprite numb(numbers);
    int X = 300, Y = 200;
    fieldSP.setPosition(X, Y);
    int n = desk.size(), m = desk[0].size();
    swap(n, m);
    swap(maxx, maxy);
    vector<vector<int> > draws(n, vector<int>(m, 0));
    fieldSP.setTextureRect(IntRect((5 - maxx) * 23 + 1,(5 - maxy) * 20 + 1, (n + 5) * 23 - (5 - maxx) * 23 , (m + 5) * 20 - (5 - maxy) * 20));
    while(window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
                exit(0);
            }
        }
        bool inBack = 0;
        window.clear();
        sleep(seconds(0.1));
        vector<vector<int> > w(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(IntRect(X + (i + maxx) * 23, Y + (j + maxy) * 20, 23, 20).contains(Mouse::getPosition(window))){
                    w[i][j] = 1;
                    cursor.setPosition(static_cast<Vector2f>(Mouse::getPosition(window)));
                    break;
                }
            }
        }
        if(IntRect(40, 40, 140, 40).contains(Mouse::getPosition(window))){
            inBack = 1;
        }
        if(Mouse::isButtonPressed(Mouse::Left)){
            if(inBack){
                sleep(seconds(0.1));
                return;
            }
            for(int i = 0;i < n;i++){
                for(int j = 0;j < m;j++){
                    if(w[i][j]){
                        if(draws[i][j] == 1 || draws[i][j] == 0){
                            draws[i][j] ^= 1;
                        }
                        else{
                            draws[i][j] = 1;
                        }
                        break;
                    }
                }
            }
        }
        if(Mouse::isButtonPressed(Mouse::Right)){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < m;j++){
                    if(w[i][j]){
                        if(draws[i][j] == 1 || draws[i][j] == 0){
                            draws[i][j] = 2;
                        }
                        else{
                            draws[i][j] = 0;
                        }
                        break;
                    }
                }
            }
        }
        window.draw(background);
        window.draw(fieldSP);
        for(int i = 0;i < n;i++){
            for(int j = newVectors.second[i].size() - 1, k = 1;j >= 0;j--, k++){
                int num = newVectors.second[i][j] - 1;
                numb.setPosition(X + (maxx - k) * 23, Y + (maxy + i) * 20 - 1);
                numb.setTextureRect(IntRect(23 * num, 0, 23, 20));
                window.draw(numb);

            }
        }
        for(int i = 0;i < m;i++){
            for(int j = newVectors.first[i].size() - 1, k = 1;j >= 0;j--, k++){
                int num = newVectors.first[i][j] - 1;
                numb.setPosition(X + (i + maxx) * 23, Y + (maxy - k) * 20 - 1);
                numb.setTextureRect(IntRect(23 * num, 0, 23, 20));
                window.draw(numb);
            }
        }
        for(int i = 0; i < n;i++){
            for(int j = 0;j < m;j++){
                if(draws[i][j] == 1){
                    black.setPosition(X + (i + maxx) * 23, Y + (j + maxy) * 20);
                    window.draw(black);
                }
                if(draws[i][j] == 2){
                    cross.setPosition(X + (i + maxx) * 23, Y + (j + maxy) * 20);
                    window.draw(cross);
                }
            }
        }
        if(inBack){
            window.draw(back_2);
        }
        else{
            window.draw(back_1);
        }
        window.display();
        bool can = 1;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(draws[i][j] == 1){
                    if(desk[j][i] != '1'){
                        can = 0;
                    }
                }
                if(desk[j][i] == '1'){
                    if(draws[i][j] != 1){
                        can = 0;
                    }
                }
            }
        }
        if(can) {
            window.clear();
            window.draw(game);
            window.display();
            sleep(seconds(2));
            return;
        }
    }




}