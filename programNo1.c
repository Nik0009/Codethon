// 1. Write a program to find the cube of a number use loop.

#include<stdio.h>
int main()
{
    int n,cube;
    printf("Enter any number for cube :");
    scanf("%d",&n);
    for (int i = 0; i <=n; i++)
    {
        cube=n*n*n;
    }
    printf("Cube of %d is %d.",n,cube);
    return 0;
}

// output:-

// Enter any number for cube :2
// Cube of 2 is 8.