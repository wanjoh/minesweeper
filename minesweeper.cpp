// minesweeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"

int main()
{
    int a[DIM][DIM] = { 0 };
    srand(time(NULL));
    initializeMatrix(a, MINES);
    int f = DIM * DIM - MINES; // broj slobodnih polja
    printMatrix(a, false);
    while (f != 0)
    {
        guess(a, &f);
        printMatrix(a, false);
       // f = remaining(a);
    }
    printf(":) pobeda\n");
    cin.ignore();
    cin.ignore();
    return 0;
}

