// 4. Write a program to compare two no by using the ternary operator in c.

#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter two numbers :");
    scanf("%d%d",&a,&b);
    a>b?printf("a is greater than b.") : printf("b is greater than a.");
    return 0;
}

// output:-

// Enter two numbers :2 1
// a is greater than b.

// Enter two numbers :1 2
// b is greater than a.