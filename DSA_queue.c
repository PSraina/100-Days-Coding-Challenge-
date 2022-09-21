//Write a menu driven program for a circular queue using an array.
//Author: Sraina Panchangam

#include <stdio.h>
#include <stdlib.h>

# define size 5

void enqueue();
void dequeue();
void show();
int queue[size];

int rear = - 1;
int front = - 1;

int main()
{
    int ch;
    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations: ");
        scanf("\n%d", &ch);
        switch (ch)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                show();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice \n");
        } 
    } 
} 
 
void enqueue()
{
    int num;

    if (rear == size - 1)
       printf("Overflow \n");
    else
    {
        if (front == - 1)
      
        front = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &num);
        rear = rear + 1;
        queue[rear] = num;
    }
} 
 
void dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", queue[front]);
        front = front + 1;
    }
} 
 
void show()
{
    
    if (front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}