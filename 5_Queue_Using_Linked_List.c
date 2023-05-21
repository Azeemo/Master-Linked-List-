#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int info;
    struct queue * next;
};
typedef struct queue que;
que *temp , *ptr , *front ,*rear;

void enqueue()
{
    temp=(que*)malloc(sizeof(que));
    if(temp==NULL)
    {
        printf("Memory not available\n");
        return;
    }
    printf("Enter data = ");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(front==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

void dequeue()
{
    if(front==NULL)
    {
        printf("Nothing to delete\n");
        return;
    }
    ptr=front;
    printf("Deleted data = %d\n",front->info);
    if(front==rear)
    {
        front=rear=NULL;
    }
    else
    {
        front=front->next;
    }
    free(ptr);
}

void display()
{
    if(front==NULL)
    {
        printf("Nothing to display\n");
        return;
    }
    ptr=front;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
    printf("\n");
    
}

void main()
{
    int choice,ch=1;
    printf ("QUEUE USING LINKED LIST OPERATIONS:\n");
    while (ch)
    {
        printf ("*********************************************************\n");
        printf ("      1    -->    ENQUEUE   \n");
        printf ("      2    -->    DEQUEUE    \n");
        printf ("      3    -->    DISPLAY\n");
        printf ("      4    -->    EXIT   \n");
        printf ("*********************************************************\n");
         printf ("Enter your choice: ");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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