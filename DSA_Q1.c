//Author: Sraina Panchangam     Branch: IT    Roll no.: 43
//Write a menu driven program to perform the following operations in an ARRAY to 1.Insert 2.Delete 3.Traverse 4.Search

#include <stdio.h>
#define size 5 //setting stack size

int array[size], top=-1; //declaring array, top and functions
void insert();
void delete();
void traverse();
void search();

int main()
{
    int choice;

    while(1) //to loop the program
    {   //printing a menu
        printf("\n*****Select a function to be performed*****");
        printf("\n1.Insert\n2.Delete\n3.Traverse\n4.Search\n5.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice); //saves the users choice
 
        switch (choice)
        {
            case 1: insert();
                    break;
        
            case 2: delete();
                    break;
    
            case 3: traverse();
                    break;
    
            case 4: search();
                    break;

            case 5: return 0; 
        
            default:printf("\nInvalid choice!\n");
        }

    }

}

void insert()
{
    int choice;
    if (top==size-1) //checks if the stack is full
    {
        printf("Overflow!\n");
    }
    else
    {
        printf("\nEnter the element to be added to the stack : ");
        scanf("%d", &choice);
        top++; //increments top
        array[top]=choice; //adds element in the stack
    }    

}

void delete()
{
    if (top==-1) //checks if stack is empty
    {
        printf("Underflow!\n");
    }
    else
    {
        printf("Deleted element %d from the stack.\n", array[top]);
        top--; //decrements top
    }
    
}

void traverse()
{
    if (top==-1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        for (int i = top; i >= 0; i--) //prints the stack
        {
            printf("%d\n",array[i]);            
        }
    }
    
}

void search()
{
    int count=0, choice;
    if (top==-1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("\nEnter element : ");
        scanf("%d", &choice);
        for (int i = top; i >= 0; i--)
        {
            if (choice==array[i]) //checks if the element accepted from the user is present in the stack
            {
                printf("%d is present in the stack!\n", choice);
                count = 1;
                break;
            }                
        }
        if (count!=1)
        {
            printf("%d is not present in the stack!\n", choice);            
        }
        
    }

}