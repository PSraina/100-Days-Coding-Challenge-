/*  Author: Sraina Panchangam   Branch: IT  Roll no.: 43
    Define a structure data type called time_struct containing 3 members int hour, int minute and int second.
    1.Input time    2.Display time  3.Update time(increment time by 1 second)
*/

#include <stdio.h>

void input(); //declaring functions
void display();
void update();

struct time_struct //declaring and defining structure
{
    int hour, minute, second;
}t;

int count=0;

int main()
{
    int choice;

    while (1) //loops the program
    {   //displays menu 
        printf("\n*****Select a function to be performed*****");
        printf("\n1.Input time\n2.Display time\n3.Update time\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice); //saves the choice od=f user    

        switch (choice)
        {
            case 1: input();
                    break;
        
            case 2: display();
                    break;
        
            case 3: update();
                    break;
            
            case 4: return 0;

            default:printf("Invalid input!");
                    break;
        } 
    }
    
}

void input()
{
    int h, m, s;
    printf("Enter hour minute second separated by spaces : ");
    scanf("%d %d %d", &h, &m, &s);
    
    while (s>=60) //to have seconds value under 60
    {
        s = s-60;
        m++; //increments minutes by 1 
    }
    t.second=s; //saves the seconds value
    
    while (m>=60) //to have minutes value under 60
    {
        m = m-60; 
        h++; //increments hours by 1 
    }
    t.minute=m; //saves the minutes value
    
    while (h>=24) //to have hours value under 24
    {
        h = h-24;
    }
    t.hour=h; //saves the hours value
    count=1;

}

void display()
{
    if (count==0) //checks if time was input before display function was called
    {
        printf("Please input time first\n");
    }
    else
    {
        printf("%d %d %d\n", t.hour, t.minute, t.second); //displays time
    }
    
}

void update()
{
    if (count==0) //checks if time was input before display function was called
    {
        printf("Please input time first\n");
    }
    else
    {
        int h, m, s;
        
        h=t.hour, m=t.minute, s=t.second+1; //increments seconds value by 1
        
        while (s>=60) //to have seconds value under 60
        {
            s = s-60;
            m++; //increments minutes by 1 
        }
        t.second=s; //saves the seconds value
    
        while (m>=60) //to have minutes value under 60
        {
            m = m-60; 
            h++; //increments hours by 1 
        }
        t.minute=m; //saves the minutes value
    
        while (h>=24) //to have hours value under 24
        {
            h = h-24;
        }
        t.hour=h; //saves the hours value
        count=1;
    }

}