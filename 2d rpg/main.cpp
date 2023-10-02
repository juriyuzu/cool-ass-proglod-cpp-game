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
const int H = 55, W = 177;
char disp[][H][W] = {
    {""},
    { // Floor + Ceiling
        "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
        "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
        "################################################################################################################################################################################",
        "################################################################################################################################################################################",
        "################################################################################################################################################################################",
        "********************************************************************************************************************************************************************************",
        "********************************************************************************************************************************************************************************",
        "********************************************************************************************************************************************************************************",
        "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
        "================================================================================================================================================================================",
        "================================================================================================================================================================================",
        "================================================================================================================================================================================",
        "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------",
        "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------",
        "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::",
        "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::",
        "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::",
        "................................................................................................................................................................................",
        "................................................................................................................................................................................",
        "................................................................................................................................................................................",
        "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
        "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
        "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
        "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
        "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
        "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
        "................................................................................................................................................................................",
        "................................................................................................................................................................................",
        "................................................................................................................................................................................",
        "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::",
        "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::",
        "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::",
        "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------",
        "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------",
        "================================================================================================================================================================================",
        "================================================================================================================================================================================",
        "================================================================================================================================================================================",
        "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
        "********************************************************************************************************************************************************************************",
        "********************************************************************************************************************************************************************************",
        "********************************************************************************************************************************************************************************",
        "################################################################################################################################################################################",
        "################################################################################################################################################################################",
        "################################################################################################################################################################################",
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
        "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
    },
    { // Left 0
        "@==============================================================================================================================================================================@",
        "@ssssssss===========                                                                                                                                                           @",
        "@sssssssssssssssssss===========                                                                                                                                                @",
        "@ssssssssssssssssssssssssssssss==@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssssssss@                                                                                                                                             @",
        "@sssssssssssssssssssssssssssssss=@                                                                                                                                             @",
        "@ssssssssssssssssssssssssssss====@                                                                                                                                             @",
        "@ssssssssssssssssssssssss====ssss@                                                                                                                                             @",
        "@ssssssssssssssssssss====ssssssss@                                                                                                                                             @",
        "@ssssssssssssssss====ssssssssssss@                                                                                                                                             @",
        "@ssssssssssss====sssssssssssssss=@                                                                                                                                             @",
        "@ssssssss====ssssssssssssssss====                                                                                                                                              @",
        "@ssss====ssssssssssssssss====                                                                                                                                                  @",
        "@====ssssssssssssssss====                                                                                                                                                      @",
        "@sssssssssssssssss====                                                                                                                                                         @",
        "@sssssssssssss====                                                                                                                                                             @",  
        "@==============================================================================================================================================================================@",
    },
    { // Front 1
        "@==============================================================================================================================================================================@", 
        "@                                                                                                                                                                              @", 
        "@                                                                                                                                                                              @", 
        "@                                @=============================================================================================================@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @", 
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @",
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @",
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @",
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @",
        "@                                @=============================================================================================================@                               @",
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @",
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @",
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @",
        "@                                @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                               @",
        "@                                @=============================================================================================================@                               @",
        "@                                                                                                                                                                              @",
        "@                                                                                                                                                                              @",
        "@                                                                                                                                                                              @",
        "@                                                                                                                                                                              @",
        "@                                                                                                                                                                              @",
        "@==============================================================================================================================================================================@",
    },
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
void merge(int a, int b);

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
    // cout << endl;
    // for (int i = 0; i < 7; i++) {
    //     for (int j = 0; j < sizeof(map[i]); j++) {
    //         if (i == y && j == x) cout << '@';
    //         else cout << map[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << "Facing " << coords[2] << endl
    //      << map[coords[0] + ray[coords[2]][0][0][0]][coords[1] + ray[coords[2]][0][0][1]] 
    //      << map[coords[0] + ray[coords[2]][0][1][0]][coords[1] + ray[coords[2]][0][1][1]] 
    //      << map[coords[0] + ray[coords[2]][0][2][0]][coords[1] + ray[coords[2]][0][2][1]] 
    //      << endl
    //      << map[coords[0] + ray[coords[2]][1][0][0]][coords[1] + ray[coords[2]][1][0][1]] 
    //      << map[coords[0] + ray[coords[2]][1][1][0]][coords[1] + ray[coords[2]][1][1][1]] 
    //      << map[coords[0] + ray[coords[2]][1][2][0]][coords[1] + ray[coords[2]][1][2][1]] 
    //      << endl
    //      << map[coords[0] + ray[coords[2]][2][0][0]][coords[1] + ray[coords[2]][2][0][1]] 
    //      << map[coords[0] + ray[coords[2]][2][1][0]][coords[1] + ray[coords[2]][2][1][1]] 
    //      << map[coords[0] + ray[coords[2]][2][2][0]][coords[1] + ray[coords[2]][2][2][1]] 
    //      << endl
    //      << map[coords[0] + ray[coords[2]][3][0][0]][coords[1] + ray[coords[2]][3][0][1]] 
    //      << '@' 
    //      << map[coords[0] + ray[coords[2]][3][1][0]][coords[1] + ray[coords[2]][3][1][1]] 
    //      << endl << endl;

    merge(1, 0);
    merge(2, 1);
    merge(2, 0);
    merge(3, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << disp[0][i][j];
        }
        cout << endl;
    }
}   

void merge(int a, int b) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (disp[a][i][j] == 's') disp[0][i][abs((W - 1) * b - j)] = ' ';
            else if (disp[a][i][j] != ' ') disp[0][i][abs((W - 1) * b - j)] = disp[a][i][j];
            else disp[0][i][abs((W - 1) * b - j)] = (disp[0][i][abs((W - 1) * b - j)]) ? disp[0][i][abs((W - 1) * b - j)] : ' ';
        }
    }
}
