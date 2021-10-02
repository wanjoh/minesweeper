#ifndef _MS_H_
#define _MS_H_

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std; 

#define DIM 9 //dimenzija
#define MINES 10
void printMatrix(int a[][DIM], bool b);

void printEl(int a, bool b); //b= true kad je igra gotova

void surroundingEl(int a[][DIM], int i, int j, int *f); //i, j = kordinate; n - dimenzija

void guess(int a[][DIM], int *f);//n = dimenzija; f = br slobodnih polja

void initializeMatrix(int a[][DIM], int m); // m broj mina

void gameOver(int a[][DIM]);

void guess2(int a[][DIM], int p, int q);

//int remaining(int a[][DIM]);

#endif