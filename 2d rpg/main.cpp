#include <iostream>
#include <limits>
using namespace std;

char x;
int coords[2] = {3, 3};
char map[7][11] = {
    "##########",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "##########"
};

void play();
void display(int y, int x);

int main() {
    play();
    
    return 0;
}

void play() {
    do {
        display(coords[0], coords[1]);
        
        cin >> x;

        switch (x) {
            case 'w':
                if (map[coords[0] - 1][coords[1]] == ' ') coords[0]--;
                break;
            case 'a':
                if (map[coords[0]][coords[1] - 1] == ' ') coords[1]--;
                break;
            case 's':   
                if (map[coords[0] + 1][coords[1]] == ' ') coords[0]++;
                break;
            case 'd':
                if (map[coords[0]][coords[1] + 1] == ' ') coords[1]++;
                break;
        }

        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");
    }
    while (true);
}

void display(int y, int x) {
    cout << endl;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < sizeof(map[i]); j++) {
            if (i == y && j == x) cout << '@';
            else cout << map[i][j];
        }
        cout << endl;
    }
    cout << endl;
}