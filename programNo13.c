// 13.Write a program by using switch case if user enter 11 it will have are area of
// circle and when user enter 22 it will have area of rectangle and when user enter
// 33 it will give area of square when user enter 44 it will give area of triangle.

#include <stdio.h>
int main()
{
    int n,l,b,r,pi=3.14,side,area;
    
    printf("11.area of circle \n 22.area of rectangle \n 33.area of square \n 44.area of triangle\n Select any one from above:\n");
    scanf("%d", &n);
    switch (n)
    {
    case 11:
        
        printf("enter radius of circle:");
        scanf("%d", &r);
        area = pi * r * r;
        printf("area of circle is %d", area);
        break;
    
    case 22:
       
        printf("enter length and breadth of rectangle:");
        scanf("%d%d",&l,&b);
        area=l*b;
        printf("area of rectangle is %d",area);
        break;

    case 33:
        printf("enter side of square:");
        scanf("%d",&side);
        area=side*side;
        printf("area of rectangle is %d",area);
        break;
    
     case 44:
        printf("enter length and breadth of triangle:");
        scanf("%d%d",&l,&b);
        area=0.5*l*b;
        printf("area of rectangle is %d",area);
        break;

    default:
    printf("please enter correct options !!!");
        break;
    }
    return 0;
}

//output:-

// 11.area of circle 
//  22.area of rectangle      
//  33.area of square         
//  44.area of triangle       
//  Select any one from above:
// 11
// enter radius of circle:12
// area of circle is 432

// 11.area of circle 
//  22.area of rectangle
//  33.area of square
//  44.area of triangle
//  Select any one from above:
// 22
// enter length and breadth of rectangle:1 2
// area of rectangle is 

// 11.area of circle 
//  22.area of rectangle
//  33.area of square
//  44.area of triangle
//  Select any one from above:
// 33
// enter side of square:2 
// area of rectangle is 4

// 11.area of circle 
//  22.area of rectangle      
//  33.area of square         
//  44.area of triangle       
//  Select any one from above:
// 44
// enter length and breadth of triangle:1 2
// area of rectangle is 1