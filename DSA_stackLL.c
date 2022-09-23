#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next; //Self referential
};

struct node* getnode()  //Dynamic memory allocation
{
	return((struct node*) malloc(sizeof(struct node)));
}

void freenode(struct node *p)
{
	free(p);  //Memory released
}

//Function prototypes
void Push();
void Pop();
void Display();

struct node *Top = NULL;  //Global variable
int size;  //Global variable
char c;  //To continue

main()
{
	int ch;
	struct node *temp = NULL, *newnode;

	do
	{
		printf("\nThe new list is: \n");
		Display();

		printf("\n\n--------STACKS--------\n");
		printf("\n\n1.PUSH");
		printf("\n2.POP");
		printf("\n3.DISPLAY");

		printf("\n\nEnter your choice: ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
			{
				printf("\n\n\tPUSH\t\n");

				if( size == 10)
					printf("\nStack overflow.\n");
				else
					Push ();  //Function call
			}
			break;

			case 2:
			{
				printf("\n\n\tPOP\t\n");
				Pop (); //Function call
			}
			break;

			case 3:
			{
				printf("\n\n\tDISPLAY\t\n");
				Display ();  //Function call
			}
			break;

			default:
				printf("\n\nINVALID INPUT!!\n");
		}
    }while(ch != 3);

	return(0);
}



//F1: Push function
void Push()
{
	int x;
	struct node *temp, *newnode;

	temp = Top;

	printf("\n\nEnter value to be inserted: ");
	scanf("%d", &x);

	newnode = getnode();
	newnode->data = x;

	if(Top == NULL)
	{
		temp = newnode;
		temp->next = NULL;
		Top = newnode;
	}

	else
	{
		newnode->next = temp;
		Top = newnode;
	}

	size++;

	Display();
}



//F2: Pop function
void Pop()
{
	int x;
	struct node *temp;

	temp = Top;

	if(Top == NULL)
		printf("\n\nStack underflow.\n");

	else
	{
		x = temp->data;

		Top = temp->next;

		freenode(temp);

		size--;

		Display();
	}
}

//F4: Display function
void Display()
{
	struct node *temp;

	temp = Top;

	if(temp==NULL)
		printf("\nThe list is empty (Underflow).\n");
	else
	{
		printf("\nThe list elements are: ");

		while(temp != NULL)
		{
			printf("\n%d",temp->data);
			temp = temp->next;
		}
	}
}
