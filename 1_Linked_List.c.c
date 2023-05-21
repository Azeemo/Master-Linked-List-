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
    }
}

void display()
{
    if(start==NULL)
    {
        printf("NOTHING TO SHOW\n");
        return;
    }
    ptr=start;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
    printf("\n");
    
}
void insert_beg()
{
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    printf("Enter data = ");
    scanf("%d",&temp->info);
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        temp->next=start;
        start=temp;
    }

}
void insert_end()
{
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("OVERFLOW");
        return;
    }
    printf("Enter the data = ");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        ptr=start;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        
    }
}

void insert_after()
{
    int pos,i;
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory out of space\n");
        return;
    }
    printf("Enter the data = ");
    scanf("%d",&temp->info);
    printf("Enter the position to insert = ");
    scanf("%d",&pos);
    if(pos==0)
    {
        temp->next=start;
        start=temp;
    }
    else
    {
        ptr=start;
        for(i=1;i<=pos-1;i++)
        {
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("Position not found\n");
            return;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}

// void insert_before()
// {
//     int pos,i;
//     temp=(node *)malloc(sizeof(node));
//     if(temp==NULL)
//     {
//         printf("Memory out of space");
//         return;
//     }
//     printf("Enter position before which the node to innsert = ");
//     scanf("%d",&pos);
//     if(pos==0)
//     {
//         temp->next=start;
//         start=temp;
//     }
//     else
//     {
//         ptr=start;
//         for(i=1;i<pos-1;i++)
//         {
//             ptr=ptr->next;
//         }

//     }
// }

void del_beg()
{
    ptr=start;
    if(start==NULL)
    {
        printf("Nothing to delete\n");
        return;
    }
    else
    {
        start=start->next;
        printf("Deleted data = %d\n",ptr->info);
        free(ptr);
    }
}

void del_end()
{
    node *prev;
    ptr=start;
    if(start==NULL)
    {
        printf("Nothing to delete\n");
        return;
    }
    if(start->next==NULL)
    {
        printf("Deleted data = %d\n",start->info);
        start=NULL;
        free(ptr);
    }
    else
    {
        
        while (ptr->next!=NULL)
        {
           prev=ptr;
           ptr=ptr->next; 
        }
        prev->next=NULL;
        printf("Deleted data = %d\n",ptr->info);
        free(ptr);
    }
}


del_pos()
{
    node * q;
    int pos;
    if(start==NULL)
    {
        printf("Nothing to delete\n");
        return;
    }
    printf("Enter the position = ");
    scanf("%d",&pos);
    ptr=start;
    if(pos==1)
    {
        q=start;
        printf("Deleted data = %d\n",start->info);
        start=start->next;
        free(q);
    }
    else
    {
        int i=1;
        while (i<pos)
        {
            q=ptr;
            ptr=ptr->next;
            i++;
            if(ptr==NULL)
            {
                printf("Position not found\n");
                return;
            }
        }
        printf("Deleted data = %d\n",ptr->info);
        q->next=ptr->next;
        ptr->next=NULL;
        free(ptr);
    }

}

void reverse()
{
    node * prev,*ptr2;
    prev=0;
    ptr=ptr2=start;
    while(ptr2!=0)
    {
        ptr2=ptr2->next;
        ptr->next=prev;
        prev=ptr;
        ptr=ptr2;
    }
    start=prev;
    printf("Linked List REVERSED\n");
}

void main()
{
    int choice,ch=1;
    printf ("LINKED LIST OPERATIONS:\n");
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
        printf ("      9    -->    REVERSE   \n");        
        printf ("      10    -->    EXIT   \n");
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
        case 5:
            insert_after();
            break;
        case 6:
            del_beg();
            break;
        case 7:
            del_end();
            break;
        case 8:
            del_pos();
            break;
        case 9:
            reverse();
            break;
        case 10:
            printf("Program Exits");
            return;
        default:
            printf("Wrong Choice\n");
        }
        printf ("Do you want to continue(enter 0 or 1)?\n");
        scanf    ("%d", &ch);
    }
}