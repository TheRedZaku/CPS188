#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h> //included so that "FILE" is defined

void sumDiagonal(int SIZE, double num[][SIZE], FILE *fptr);

void sumAll(int SIZE, double num[][SIZE], FILE *fptr);

void avgLast(int SIZE, double num[][SIZE], FILE *fptr);

void sumCorners(int SIZE, double num[][SIZE], FILE *fptr);

#endif