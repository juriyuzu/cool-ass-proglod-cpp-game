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
//// disp
// 0. Base
// 1. Floor + Ceiling
// 2. Left 0
// 3. Front Left 1
// 4. Front Center 1
// 5. Left 1
// 6. Front Left 2
// 7. Front Center 2
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
        "@ssssssss=========                                                                                                                                                            @",   
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssss=                                                                                                                                                             @",  
        "@ssssssssssss====a                                                                                                                                                             @",  
        "@ssssssss====ssssa                                                                                                                                                             @",  
        "@ssss====ssssssssa                                                                                                                                                             @",  
        "@====ssssssssssssa                                                                                                                                                             @",  
        "@ssssssssssssssssa                                                                                                                                                             @",  
        "@sssssssssssss====                                                                                                                                                             @",  
        "@==============================================================================================================================================================================@",    
    },
    { // Front Left 1
        "@==============================================================================================================================================================================@", 
        "@==================                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@==================                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@sssssssssssssssssa                                                                                                                                                            @", 
        "@==================                                                                                                                                                            @", 
        "@==============================================================================================================================================================================@", 
    },
    { // Front Center 1
        "@==============================================================================================================================================================================@", 
        "@                 =============================================================================================================================================                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 =============================================================================================================================================                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 @sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                @", 
        "@                 =============================================================================================================================================                @", 
        "@==============================================================================================================================================================================@",  
    },
    { // Left 1
        "@==============================================================================================================================================================================@", 
        "@=================                                                                                                                                                             @", 
        "@ssssssssssssssss@===========                                                                                                                                                  @", 
        "@ssssssssssssssss@sssssssssss========                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@sssssssssssssssss==                                                                                                                                          @", 
        "@ssssssssssssssss@sssssssssssss====sa                                                                                                                                          @", 
        "@ssssssssssssssss@sssssssss====sssssa                                                                                                                                          @", 
        "@ssssssssssssssss@sssss====sssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss@sss==sssssssssssssa                                                                                                                                          @", 
        "@ssssssssssssssss====sssssssssssssssa                                                                                                                                          @", 
        "@================@ssssssssssssss=====                                                                                                                                          @", 
        "@ssssssssssssssss@ssssssssss=====                                                                                                                                              @", 
        "@ssssssssssssssss@sssssss====                                                                                                                                                  @", 
        "@ssssssssssssssss@sss====                                                                                                                                                      @", 
        "@ssssssssssssssss@===                                                                                                                                                          @", 
        "@=================                                                                                                                                                             @", 
        "@==============================================================================================================================================================================@",  
    },
    { // Front Left 2
        "@==============================================================================================================================================================================@",  
        "@                                                                                                                                                                              @",  
        "@                                                                                                                                                                              @",  
        "@====================================                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@====================================                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@sssssssssssssssssssssssssssssssssssa                                                                                                                                          @",  
        "@====================================                                                                                                                                          @",  
        "@                                                                                                                                                                              @",  
        "@                                                                                                                                                                              @",  
        "@                                                                                                                                                                              @",  
        "@                                                                                                                                                                              @",  
        "@                                                                                                                                                                              @",  
        "@                                                                                                                                                                              @",  
        "@                                                                                                                                                                              @",  
        "@==============================================================================================================================================================================@",  
    },
    { // Front Center 2
        "@==============================================================================================================================================================================@",  
        "@                                                                                                                                                                              @",  
        "@                                                                                                                                                                              @",  
        "@                                  ========================================================================================================                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  ========================================================================================================                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  @ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss@                                    @",  
        "@                                  ========================================================================================================                                    @",  
        "@                                                                                                                                                                              @",  
        "@                                                                                                                                                                              @",  
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
    // merge(2, 0);
    merge(4, 0);
    merge(3, 0);
    merge(3, 1);
    // merge(2, 1);
    // merge(7, 0);
    // merge(6, 1);
    // merge(6, 0);
    
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
            else if (disp[a][i][j] == 'b' && disp[0][i][abs((W - 1) * b - j)] == '@') disp[0][i][abs((W - 1) * b - j)] = '@';
            else if (disp[a][i][j] == 'a' && disp[0][i][abs((W - 1) * b - j)] == '@') disp[0][i][abs((W - 1) * b - j)] = ' ';
            else if (disp[a][i][j] == 'a') disp[0][i][abs((W - 1) * b - j)] = '@';
            else if (disp[a][i][j] != ' ') disp[0][i][abs((W - 1) * b - j)] = disp[a][i][j];
            else disp[0][i][abs((W - 1) * b - j)] = (disp[0][i][abs((W - 1) * b - j)]) ? disp[0][i][abs((W - 1) * b - j)] : ' ';
        }
    }
}
