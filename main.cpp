//
//  main.cpp
//  cs161_assignment1
//
//  Created by Vincent Lee on 10/10/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include <iostream>

#define COLUMNS 40
#define ROWS    20
#define DEAD    0
#define ALIVE   1

//starting coordinates for pattern
typedef struct POINT {
    int x;
    int y;
} Point;


//function prototypes
void PrintWelcomeMessage(void);
void PrintGrid(int[ROWS][COLUMNS]);
void InitializeArrays(int[ROWS][COLUMNS], int[ROWS][COLUMNS]);
void SetUpGame(Point *);
void CusomizeGrid(int pattern, Point *startCoordinate);


int main() {

    Point point;
    int arr1[ROWS][COLUMNS];
    int arr2[ROWS][COLUMNS];
    
    PrintWelcomeMessage();
    SetUpGame(&point);
    
    InitializeArrays(arr1, arr2);
    
    PrintGrid(arr1);
    PrintGrid(arr2);

    return 0;
}



void SetUpGame(Point *point) {
    int patternChoice = 0;
    
    while(true) {
        std::cout << "Enter 1 for Fixed Oscillator\n";
        std::cout << "Enter 2 for Glider\n";
        std::cout << "Enter 3 for Glider Cannon\n\n";
        std::cout << "Your choice: " << std::endl;
        std::cin >> patternChoice;
        
        if(patternChoice < 1 || patternChoice > 3) {
            std::cout << "\nThat was not a valid choice.\n" << std::endl;
        } else {
            break;
        }
    }
    CusomizeGrid(patternChoice, point);
}


void CusomizeGrid(int pattern, Point *startCoordinate) {

    if(pattern == 1) {
        std::cout << "\nYou chose Fixed Oscillator\n" << std::endl;
        
    } else if (pattern == 2) {
        std::cout << "\nYou chose Glider\n" << std::endl;
        
    } else {
        std::cout << "\nYou chose Glider Cannon\n" << std::endl;
        
    }

}



void InitializeArrays(int array1[ROWS][COLUMNS], int array2[ROWS][COLUMNS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            array1[i][j] = ALIVE;
            array2[i][j] = DEAD;
        }
    }
}


void PrintWelcomeMessage(void) {
    std::cout << "This program simulates Conway's Game of Life.\n";
    std::cout << "The patterns that evolve are determined by\n";
    std::cout << "the initial state of the board.\n\n";
    std::cout << "Please select the initial state:\n" << std::endl;
}


void PrintGrid(int array[ROWS][COLUMNS]) {
//    std::cout << "\r" << std::endl;
    
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(array[i][j]==DEAD) {
                std::cout << ". ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << "\n" << std::endl;
    }
}




