// 10.Write a program to read an integer and print its multiplication table.

#include<stdio.h>
int main()
{
    int n,mul;
    printf("Enter any number :");
    scanf("%d",&n);
    printf("Multiplication Table:\n");
    for (int i = 1; i <=10; i++)
    {
        mul=n*i;
        printf("%d * %d =%d\n",n,i,mul);
    }
    
    return 0;
}

// output:-

// Enter any number :2
// Multiplication Table:
// 2 * 1 =2
// 2 * 2 =4
// 2 * 3 =6
// 2 * 4 =8
// 2 * 5 =10
// 2 * 6 =12
// 2 * 7 =14
// 2 * 8 =16
// 2 * 9 =18
// 2 * 10 =20