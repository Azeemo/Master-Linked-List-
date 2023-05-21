#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int info;
    struct stack * next;
};

typedef struct stack stk;
stk * top=NULL;
stk * temp , * ptr;

void push()
{
    temp = (stk *)malloc(sizeof(stk));
    if(temp==NULL)
    {
        printf("Memory is full\n");
        return;
    }
    else
    {
        printf("Enter the data = ");
        scanf("%d",&temp->info);
        temp->next=top;
        top=temp;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("Nothing to delete\n");
        return;
    }
    else
    {
        ptr=top;
        printf("Popped data = %d",ptr->info);
        top=top->next;
        free(ptr);
    }
}

void display()
{
    if(top==NULL)
    {
        printf("Nothing to display\n");
        return;
    }
    else
    {
        ptr=top;
        while (ptr!=NULL)
        {
            printf("%d ",ptr->info);
            ptr=ptr->next;
        }
    }
    printf("\n");
}
void main()
{
    int choice,ch=1;
    printf ("STACK USING LINKED LIST OPERATIONS:\n");
    while (ch)
    {
        printf ("*********************************************************\n");
        printf ("      1    -->    PUSH   \n");
        printf ("      2    -->    POP    \n");
        printf ("      3    -->    DISPLAY\n");
        printf ("      4    -->    EXIT   \n");
        printf ("*********************************************************\n");
         printf ("Enter your choice: ");
        scanf    ("%d", &choice);
        switch (choice)
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
            printf("Program Exits");
            return;
        default:
            printf("Wrong Choice\n");
        }
        printf ("Do you want to continue(enter 0 or 1)?\n");
        scanf    ("%d", &ch);
    }
}