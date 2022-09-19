//WAP to perform Stack Operations.
//Author: Sraina Panchangam

#include <stdio.h>
#include <stdlib.h>

//declaring array size 

# define size 5

//declaring necessary variables

int arr[size], top = -1;

//declaring main methods

void push();
void pop();
void display();

int main()
{
    int ch;

    while(1)
    {
        printf("\nStack Operations: \n");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter a Choice: \n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                    push();
                    break;
            
            case 2: 
                    pop();
                    break;
                
            case 3: 
                    display();
                    break;

            case 4:
                    exit(0);
                    break;
            
            default: printf("\nEnter a Valid Choice\n");
        }
    }
}


//*begin of push method
void push()
{
    int x;

    if (top == size - 1)
        printf("\nStack Overflow\n");
    else 
    {
        printf("\nEnter the element to be pushed: \n");
        scanf("%d", &x);
        top ++;
        arr[top] = x;
    }
}
//*end of push method


//*begin of pop method
void pop()
{

    if (top < 0)
        printf("\nStack Underflow\n");
    else 
    {
        printf("\nPopped Element: %d \n", arr[top] );
        top --;
    }
}
//*end of pop method


//*begin of display method
void display()
{
    for(int i = top; i >= 0; i--)
        printf("\n%d\n", arr[i]);
}
//*end of display method