/*
    @autor: Malbolge;
    @data: 31/07/2019;
    @nome: Ciclo de Rubik;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int c[54];
int c2[54];
char s[100];
int m[6][54] = {{6, 3, 0, 7, 4, 1, 8, 5, 2, 18, 19, 20, 12 ,13, 14, 15, 16, 17, 27, 28, 29, 21, 22, 23, 24, 25, 26, 36, 37, 38, 30, 31, 32, 33, 34, 35, 9, 10, 11, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53},
{44, 1, 2, 41, 4, 5, 38, 7, 8, 15, 12, 9, 16 ,13, 10, 17, 14, 11, 0, 19, 20, 3, 22, 23, 6, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 51, 39, 40, 48, 42, 43, 45, 18, 46, 47, 21, 49, 50, 24, 52, 53},
{0, 1, 2, 3, 4, 5, 17, 14, 11, 9, 10, 45, 12 ,13, 46, 15, 16, 47, 24, 21, 18, 25, 22, 19, 26, 23, 20, 6, 28, 29, 7, 31, 32, 8, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 33, 30, 27, 48, 49, 50, 51, 52, 53},
{0, 1, 20, 3, 4, 23, 6, 7, 26, 9, 10, 11, 12 ,13, 14, 15, 16, 17, 18, 19, 47, 21, 22, 50, 24, 25, 53, 33, 30, 27, 34, 31, 28, 35, 32, 29, 8, 37, 38, 5, 40, 41, 2, 43, 44, 45, 46, 42, 48, 49, 39, 51, 52, 36},
{29, 32, 35, 3, 4, 5, 6, 7, 8, 2, 10, 11, 1 ,13, 14, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 53, 30, 31, 52, 33, 34, 51, 42, 39, 36, 43, 40, 37, 44, 41, 38, 45, 46, 47, 48, 49, 50, 9, 12, 15},
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ,13, 14, 42, 43, 44, 18, 19, 20, 21, 22, 23, 15, 16, 17, 27, 28, 29, 30, 31, 32, 24, 25, 26, 36, 37, 38, 39, 40, 41, 33, 34, 35, 51, 48, 45, 52, 49, 46, 53, 50, 47}};

int solve();
_Bool solved();
void move(char);
void rotate(int);

int main(int argc, char **argv)
{

    for (int i = 0; i < 54; ++i)
        c2[i] = c[i] = (i / 9) * 9 + 4;

    while (scanf(" %s", s) != EOF)
        printf("%d\n", solve());

    return 0;

}

void rotate(int f) 
{

    for (int i = 0; i < 54; i++) 
        c[i] = c2[m[f][i]];
    for (int i = 0; i < 54; i++) 
        c2[i] = c[i];

}
 
void move(char m) 
{

    switch (m) 
    {

        case 'F': 
            rotate(0); 
            break;
        case 'f': 
            for (int i = 0; i < 3; i++) 
                rotate(0); 
            break;
        case 'L': 
            rotate(1); 
            break;
        case 'l': 
            for (int i = 0; i < 3; i++) 
                rotate(1); 
            break;
        case 'D': 
            rotate(2); 
            break;
        case 'd': 
            for (int i = 0; i < 3; i++) 
                rotate(2); 
            break;
        case 'R': 
            rotate(3); 
            break;
        case 'r': 
            for (int i = 0; i < 3; i++) 
                rotate(3); 
            break;
        case 'U': 
            rotate(4); 
            break;
        case 'u': 
            for (int i = 0; i < 3; i++) 
                rotate(4); 
            break;
        case 'B': 
            rotate(5); 
            break;
        case 'b': 
            for (int i = 0; i < 3; i++) 
                rotate(5); 
            break;

    }

}
 
_Bool solved() 
{

    for (int i = 0; i < 54; i++) 
        if (c[i] != (i / 9) * 9 + 4) 
            return false;

    return true;

}
 
int solve() 
{

    for (int i = 1; ; i++) 
    {
        for (int j = 0; s[j]; j++) 
            move(s[j]);

        if (solved()) 
            return i;

    }

}