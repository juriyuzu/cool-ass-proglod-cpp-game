#include <iostream>
#include <limits>
using namespace std;

char x;
int coords[] = {1, 1, 0};
int ray[4][4][3][2] = {
    {
        {{-3, -1}, {-3, 0}, {-3, 1}},
        {{-2, -1}, {-2, 0}, {-2, 1}},
        {{-1, -1}, {-1, 0}, {-1, 1}},
        {{0, -1}, {0, 1}}
    },
    {
        {{-1, 3}, {0, 3}, {1, 3}},
        {{-1, 2}, {0, 2}, {1, 2}},
        {{-1, 1}, {0, 1}, {1, 1}},
        {{-1, 0}, {1, 0}}
    },
    {
        {{3, 1}, {3, 0}, {3, -1}},
        {{2, 1}, {2, 0}, {2, -1}},
        {{1, 1}, {1, 0}, {1, -1}},
        {{0, 1}, {0, -1}}
    },
    {
        {{1, -3}, {0, -3}, {-1, -3}},
        {{1, -2}, {0, -2}, {-1, -2}},
        {{1, -1}, {0, -1}, {-1, -1}},
        {{1, 0}, {-1, 0}}
    }
};
char map[7][11] = {
    "#########",
    "#   #   #",
    "# # # # #",
    "# ## ## #",
    "# #   # #",
    "#   #   #",
    "#########"
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
                if (map[coords[0] - 1][coords[1]] == ' ' && coords[2] == 0) coords[0]--;
                if (map[coords[0]][coords[1] + 1] == ' ' && coords[2] == 1) coords[1]++;
                if (map[coords[0] + 1][coords[1]] == ' ' && coords[2] == 2) coords[0]++;
                if (map[coords[0]][coords[1] - 1] == ' ' && coords[2] == 3) coords[1]--;
                break;
            case 'q':
                coords[2] += (coords[2] != 0) ? -1 : 3;
                break;
            case 'e':
                coords[2] += (coords[2] != 3) ? 1 : -3;
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
    cout << "Facing " << coords[2] << endl
         << map[coords[0] + ray[coords[2]][0][0][0]][coords[1] + ray[coords[2]][0][0][1]] 
            << map[coords[0] + ray[coords[2]][0][1][0]][coords[1] + ray[coords[2]][0][1][1]] 
            << map[coords[0] + ray[coords[2]][0][2][0]][coords[1] + ray[coords[2]][0][2][1]] << endl
         << map[coords[0] + ray[coords[2]][1][0][0]][coords[1] + ray[coords[2]][1][0][1]] 
            << map[coords[0] + ray[coords[2]][1][1][0]][coords[1] + ray[coords[2]][1][1][1]] 
            << map[coords[0] + ray[coords[2]][1][2][0]][coords[1] + ray[coords[2]][1][2][1]] << endl
         << map[coords[0] + ray[coords[2]][2][0][0]][coords[1] + ray[coords[2]][2][0][1]] 
            << map[coords[0] + ray[coords[2]][2][1][0]][coords[1] + ray[coords[2]][2][1][1]] 
            << map[coords[0] + ray[coords[2]][2][2][0]][coords[1] + ray[coords[2]][2][2][1]] << endl
         << map[coords[0] + ray[coords[2]][3][0][0]][coords[1] + ray[coords[2]][3][0][1]] 
            << '@' 
            << map[coords[0] + ray[coords[2]][3][1][0]][coords[1] + ray[coords[2]][3][1][1]] << endl
         << endl;

}