#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <sstream>
using namespace std;

string x;
vector<string> content;
string line;
int sd = 0;

void clear() {
    cin.clear();
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("cls");
}

void display() {
    switch (sd) {
        case 0:
            cout << "Welcome to The C++ Text-Based Game Engine!" << endl
                 << "\tmade by jryz" << endl << endl << endl
                 << "Type [OK] to proceed..." << endl;
            cin  >> x;
            if (x == "OK") sd = 1;
            break;
        case 1:
            ifstream filer("main.txt");
            while (getline(filer, line)) content.push_back(line);
            filer.close();
            cout << "Type [Play] or [Edit], an underscore, then the corresponding number of your choice" << endl;
            int num = 1;
            for (string i : content) cout << num++ << "\t| " << i << endl;
            cout << num++ << "\t| blank template..." << endl;
            content.clear();
            cin >> x;
            string xSub;
            xSub = x.substr(0, 4);
            string digits;
            int uhh;
            for (int i = 0; i < x.size(); i++) {
                uhh = x[i] - '0';
                if (isdigit(uhh)) digits += uhh;
                else break;
            }
            int integer = stoi(digits);
            if (xSub == "Play") cout << "yahallo" << integer;

            cin >> x;
            break;
    }
}

void play() {
    clear();

    while (x != "x") {
        display();

        clear();
    }

    cout << "Thank you for playing!";
}

int main() {
    play();

    // ifstream fileR("file.txt");
    // vector<string> content;
    // string t;

    // while (getline (fileR, t)) {
    //     content.push_back(t);
    // }

    // fileR.close();

    // int c = 0, s = 1;
    // for (string i : content) {
    //     if (i == "`````") {
    //         c++;
    //         if (c == 2) {
    //             break;
    //         }
    //     }
    //     else if (c == 1) cout << s++ << '\t' << "|" << i << endl;
    // }

    return 0;
}