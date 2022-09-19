/* Q1. WAP to check a given number is Fibonacci Number.
   Author: Sraina   Roll Number: 43     Batch: C */


#include<stdio.h>
int main()
{

    //Declaraing Variables

    int a = 0, b = 1, c = 0, n, flag = 0;

    //Taking Input 

    printf("Enter a number: \n");
    scanf("%d", &n);

    //Checking if the Number is Fibonacci or not

    if( n == a || n == b)
        flag = 1;
    else 
    {
        do
        {
            c = a + b;

            if(n == c)
                flag = 1;
            
            a = b;
            b = c;
        } while(c < n);
    }

    //Display according to the condition

    if (flag == 1)
        printf("It is a Fibonacci Number\n");
    else 
        printf("It is not a Fibonacci Number\n");
}


