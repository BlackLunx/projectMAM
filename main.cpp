#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
    ifstream fin;
    fin.open("2.txt");
    int sizex, sizey;

    vector <vector<int> > horisontal(sizey);
    fin >> sizex >> sizey;
    char desk [sizey][sizex];
    int n = 0;
    for (int i = 0; i < sizey; i ++){
        for (int j = 0; j < sizex; j ++) {
            fin >> desk[i][j];
            if (desk[i][j] == '1'){
                n ++;
            }
            else if (n != 0){
                horisontal[i].push_back(n);
                cout << horisontal[i].back() << ' ';
                n = 0;
            }
            if ((n != 0)&&(j == (sizex - 1))){
                horisontal[i].push_back(n);
                cout << horisontal[i].back()<<' ';
                n = 0;
            }
        }
        cout << endl;
    }
    n = 0;
    vector <vector<int>> vertical(sizex);
    for (int i = 0; i < sizex; i ++) {
        for (int j = 0; j < sizey; j++) {
            if (desk[j][i] == '1') {
                n++;
            } else if (n != 0) {
                vertical[i].push_back(n);
                cout << vertical[i].back()<<' ';
                n = 0;
            }
            if ((n != 0) && (j == (sizey - 1))) {
                vertical[i].push_back(n);
                cout << vertical[i].back()<<' ';
                n = 0;
            }
        }
        cout << endl;
    }
    return 0;
}
