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
                 << "Press Enter to proceed..." << endl;
            getline(cin, x, '\n');
            if (x == "") sd = 1;
            break;

        case 1:
            ifstream filer("main.txt");
            while (getline(filer, line)) content.push_back(line);
            filer.close();
            cout << "Type [Play] or [Edit], space, then the corresponding number of your choice" << endl;
            int num = 1;
            for (string i : content) cout << num++ << "\t| " << i << endl;
            cout << num++ << "\t| blank template..." << endl;
            content.clear();
            getline(cin, x, '\n');
            stringstream iss(x);
            string word[2];
            int numb;
            while (iss >> word[0]) try { numb = stoi(word[0]); } catch(exception) { word[1] = word[0]; }
            // cout << numb << word[1] << endl; // debug
            getline(cin, x, '\n'); // temp buffer
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

    return 0;
}

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