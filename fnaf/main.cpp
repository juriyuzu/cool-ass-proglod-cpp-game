#include <iostream>
#include <string>
using namespace std;

string x;
int H = 55, W = 176;
char screen[][55][176] = {
{
    "#include <iostream>",
    "using namespace std;",
    "",
    "int main() {",
    "    cout << \"Hello World!\"",
    "",
    "    return 0;",
    "}",
},
};

void play();
void display();

int main() {
    play();
    
    return 0;
}

void play() {
    display();

    cin >> x;
}

void display() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) 
            cout << screen[0][i][j];
        cout << endl;
    }
}