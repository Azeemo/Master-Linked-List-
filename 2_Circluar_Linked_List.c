#include<stdio.h>
#include<stdlib.h>
struct nodetype
{
    int info;
    struct nodetype *next;
    
};
typedef struct nodetype node;
node *temp,*start,*ptr;

void create()
{
    int n;
    printf("How many nodes do you want to create = ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        temp= (node *)malloc(sizeof(node));
        if(temp==NULL)
        {
            printf("OVERFLOW\n");
            return;
        }
        printf("Enter the data = ");
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
            ptr=temp;
        }
        else
        {
            ptr->next=temp;
            ptr=temp;
        }
        ptr->next=start;
    }
}

display()
{
    if(start==NULL)
    {
        printf("Nothing to show\n");
    }
    ptr=start;
    while (ptr->next!=start)
    {
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->info);
}

void insert_beg()
{
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Overflow");
        return;
    }
    printf("Enter the data = ");
    scanf("%d",&temp->info);
    ptr=start;
    if(start==NULL)
    {
        start=temp;
        start->next=start;
    }
    else
    {
        while (ptr->next!=start)
        {
            ptr=ptr->next;
        }
        temp->next=start;
        start=temp;
        ptr->next=start;
    }
    
}

void insert_end()
{
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Overflow\n");
        return;
    }
    printf("Enter the data = ");
    scanf("%d",&temp->info);
    ptr=start;
    if(start==NULL)
    {
        start=temp;
        temp->next=start;
    }
    else
    {
        while (ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=start;
        
    }
}

void del_beg()
{
    node * ptr2;
    if(start==NULL)
    {
        printf("Nothing to delete\n");
        return;
    }
    ptr=ptr2=start;
    printf("Deleted data = %d\n",start->info);
    if(start->next==start)
    {
        free(ptr);
    }
    else
    {
        while (ptr2->next!=start)
        {
            ptr2=ptr2->next;
        }
        start=start->next;
        ptr2->next=start;
        free(ptr);
    }
}

void del_end()
{
    node *ptr2;
    if(start==NULL)
    {
        printf("Nothing to delete\n");
        return;
    }

    ptr=start;
    if(ptr->next==start)
    {
        printf("Deleted data = %d\n",start->info);
        start=NULL;
        free(ptr);
    }
    else
    {
        while (ptr->next!=start)
        {
            ptr2=ptr;
            ptr=ptr->next;
        } 
        printf("Deleted data = %d\n",ptr->info);
        ptr2->next=start;
        free(ptr);
    }
}

void main()
{
    int choice,ch=1;
    printf ("CIRCULAR LINKED LIST OPERATIONS:\n");
    while (ch)
    {
        printf ("*********************************************************\n");
        printf ("      1    -->    CREATE   \n");
        printf ("      2    -->    INSERT AT BEG    \n");
        printf ("      3    -->    DISPLAY\n");
        printf ("      4    -->    INSERT AT END   \n");        
        printf ("      5    -->    INSERT AT POSITION   \n");        
        printf ("      6    -->    DELETE FROM BEGINING   \n");        
        printf ("      7    -->    DELETE FROM END   \n");        
        printf ("      8    -->    DELETE FROM A POSITION   \n");        
        printf ("      9    -->    EXIT   \n");
        printf ("*********************************************************\n");
 
        printf ("Enter your choice: ");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_beg();
            break;
        case 3:
            display();
            break;
        case 4:
            insert_end();
            break;
        // case 5:
        //     insert_after();
        //     break;
        case 6:
            del_beg();
            break;
        case 7:
            del_end();
            break;
        // case 8:
        //     del_pos();
        //     break;
        // case 9:
        //     printf("Program Exits");
        //     return;
        default:
            printf("Wrong Choice\n");
        }
        printf ("Do you want to continue(enter 0 or 1)?\n");
        scanf    ("%d", &ch);
    }
}