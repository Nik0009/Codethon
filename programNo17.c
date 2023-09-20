// 17.Write a program to find the sum of two matrices of order 2*2 using
//multidimensional arrays

#include<stdio.h>
int main()
{
    int a[2][2]={1,2,3,4},b[2][2]={1,2,3,4},c[2][2],sum=0;
    for (int i = 0; i <4; i++)
    {
        for (int j = 0; j <4; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
        
    }

    for (int i = 0; i <2; i++)
    {
        for (int j = 0; j <2; j++)
        {
            sum=sum+c[i][j];
        }
        
    }
    printf("sum of two matrices of order 2*2 using multidimensional arrays =%d",sum);
    return 0;
}

// output:-
// sum of two matrices of order 2*2 using multidimensional arrays =20