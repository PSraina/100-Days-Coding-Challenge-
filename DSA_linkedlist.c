#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;    
};

struct node *getnode(void)
{
    return ((struct node *)malloc (sizeof (struct node)));
};

void freenode( struct node *p)
{
    free(p);
}

struct node *start = NULL;

void insertbeg();
void insertpos();
void insertend();
void delbeg();
void delpos();
void delend();
void display();
int Count();

int main()
{
	
    int ch;
    
    do
	{
		printf("\n1. INSERT AT THE BEGINNING");
		printf("\n2. INSERT AT A LOCATION");
		printf("\n3. INSERT AT THE END");
		printf("\n4. DELETE AT THE BEGINNING");
		printf("\n5. DELETE AT A LOCATION");
		printf("\n6. DELETE AT THE END");
		printf("\n7. DISPLAY");

		printf("\nEnter your choice:  ");
		scanf("%d", &ch);

		switch(ch)
		{

			case 1:
			{
				insertbeg();  //Function call
			}
			break;

			case 2:
			{
				insertpos(); //Function call
			}
			break;

			case 3:
			{
				insertend(); //Function call
			}
			break;

			case 4:
			{
				delbeg(); //Function call
			}
			break;

			case 5:
			{
				delpos(); //Function call
			}
			break;

			case 6:
			{
				delend();  //Function call
			}
			break;

			case 7:
			{
				display();  //Function call
			}
			break;

			default:
				printf("\nINVALID INPUT");
		}

    }while(ch != 7);

    return(0);
}

void insertbeg()
{
    struct node *newnode;
    int x;

    printf("Enter a Number: ");
    scanf("%d", &x);

    newnode = getnode();
    newnode -> data = x;
    newnode -> next = start;
    start = newnode;
    display();
}

void insertpos()
{
    struct node *temp, *newnode;
	int i, x, p;

	do
	{
		printf("Enter position: ");
		scanf("%d", &p);
	}while(p<=0);

	temp = start;

	if((temp == NULL)&&(p != 1))
		printf("List is empty");

	else if(p==1)
			insertbeg();

	else
	{
		printf("Enter a Number: ");
		scanf("%d", &x);

		for(i = 1; i < p-1; i++) //p-2 jumps
		{
			if(temp -> next == NULL)
			{
				printf("Invalid Location as Location > Length of list");
				break;
			}

			temp = temp -> next;
		}

		if(i == p-1)
		{
			newnode = getnode();
			newnode -> data = x;
			newnode -> next = temp -> next;
			temp -> next = newnode;

			display();
		}
	}
}

void insertend()
{
    struct node *newnode, *temp;
    int x;

    printf("Enter a Number: ");
    scanf("%d", &x);

    newnode = getnode();
    newnode -> data = x;
    newnode -> next = NULL;
    temp = start;

    if (temp == NULL)
        start = newnode;
    else 
        {
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
                
            temp -> next = newnode;
        }

    display();
}

void delbeg()
{
	struct node *temp;
    int x;
    
	temp = start;

	if(temp == NULL)
		printf("List is empty.");

	else
	{
		x = temp -> data;
		start = temp -> next;

		freenode(temp);

		display();
	}
}

void delpos()
{
	int x, p, i, cnt;
	struct node *temp, *ptr;

	temp = start;
	cnt = Count();

	if(temp == NULL)
		printf("List is empty.");

	else
	{
		do
		{
			printf("Enter location: ");
			scanf("%d", &p);
		}while(p<=0);

		if(p==1)
			delbeg();

		else if((cnt == 1)&&(p == 1))
			delbeg();

		else if((cnt == 1)&&(p != 1))
			printf("Only one element is present in the list.");

		else
		{
			for(i=1;i<p-1;i++)  //p-2 jumps
			{
				if(temp -> next -> next == NULL)
				{
					printf("Invalid location as Location > length.");
					break;
				}

				temp = temp->next;
			}

			if(i == p-1)
			{
				x = (temp->next)->data;

				ptr = temp->next;

				temp->next = (temp->next)->next;

				freenode(ptr);

				display();
			}
		}
	}
}

int Count()
{
	int count = 0;
	struct node *temp;

	temp = start;

	if(temp == NULL)
		printf("The list is empty.");
	else
	{
		while(temp != NULL)
		{
			count++;
			temp = temp -> next;
		}
	}

	return(count);
}

void delend()
{
	int x;
	struct node *temp, *ptr;

	temp = start;

	if(temp == NULL)
		printf("List is empty.");

	else
	{
		while((temp -> next) -> next != NULL)
		{
			temp = temp -> next;
		}

		ptr = temp -> next;

		if(ptr != NULL)
		{
			x = ptr -> data;

			freenode(ptr);

			temp -> next = NULL;

			display();
		}
		else
			delbeg();
	}
}

void display()
{
	struct node *temp;

	temp = start;

	if(temp == NULL)
		printf("The list is empty.");
	else
	{
		printf("The list elements are: ");

		while(temp != NULL)
		{
			printf("%d",temp->data);
			temp = temp->next;
		}
	}
}


