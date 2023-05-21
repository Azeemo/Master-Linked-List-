#include<stdio.h>
#include<stdlib.h>

struct nodetype 
{
    struct nodetype *prev;
    int info;
    struct nodetype *next;
};
typedef struct nodetype node;
node*start =NULL;
node*prev,*next,*ptr,*temp;

void create()
{
    int ch=1;
    
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory not available");
        return;
    }
    if(start==NULL)
    {
        printf("Enter the info of first node = ");
        scanf("%d",&temp->info);
        temp->prev=NULL;
        start=temp;
    }
    do
    {
        ptr=(node *)malloc(sizeof(node));
        printf("Enter the info of next node = ");
        scanf("%d",&ptr->info);
        temp->next=ptr;
        ptr->prev=temp;
        temp=ptr;
        printf("Do you want to add more (0 or 1)=");
        scanf("%d",&ch);
    } 
    while (ch==1);
    temp->next=NULL;
}

void fdisplay()
{
    if(start==NULL)
    {
        printf("Nothing to show\n");
        return;
    }
    else
    {
        ptr=start;
        while (ptr!=NULL)
        {
            printf("%p || %d || %p ",ptr->prev,ptr->info,ptr->next);
            ptr=ptr->next;
        }
    }
    printf("\n");
}

void bdisplay()
{
    if(start==NULL)
    {
        printf("Nothing to show\n");
        return;
    }
    else
    {
        ptr=start;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        while (ptr!=NULL)
        {
            printf("%p || %d || %p ",ptr->next,ptr->info,ptr->prev);
            ptr=ptr->prev;
        }
    }
    printf("\n");
}

void insert_beg()
{
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory not available\n");
        return;
    }
    printf("Enter the info of the node = ");
    scanf("%d",&temp->info);
    temp->prev=NULL;
    if(start==NULL)
    {
        start=temp;
        temp->next=NULL;   
    }
    else
    {
        temp->next=start;
        start->prev=temp;
        start=temp;
    }
}
void insert_end()
{
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory not available\n");
        return;
    }
    printf("Enter the info of the node = ");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        temp->prev=NULL;   
    }
    else
    {
        ptr=start;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
        
    }
}

void del_beg()
{
    if(start==NULL)
    {
        printf("Nothing to delete");
        return;
    }
    ptr=start;
    printf("Deleted data = %d\n",ptr->info);
    if(start->next==NULL)
    {
        start=NULL;
        free(ptr);
    }
    else
    {
        start=start->next;
        start->prev=NULL;
        free(ptr);
    }
}

void del_end()
{
    node * ptr2;
    if(start==NULL)
    {
        printf("Nothing to delete");
        return;
    }
    ptr=start;
    if(start->next==NULL)
    {
        start=NULL;
        free(ptr);
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr2=ptr;
            ptr=ptr->next;
        }
        printf("Deleted data = %d\n",ptr->info);
        ptr2->next=NULL;
        free(ptr);

    }
}

void main()
{
    int choice,ch=1;
    printf ("DOUBLY LINKED LIST OPERATIONS:\n");
    while (ch)
    {
        printf ("*********************************************************\n");
        printf ("      1    -->    CREATE   \n");
        printf ("      2    -->    INSERT AT BEG    \n");
        printf ("      3    -->    DISPLAY FROM FRONT\n");
        printf ("      4    -->    DISPLAY FROM BACK\n");
        printf ("      5    -->    INSERT AT END   \n");        
        printf ("      6    -->    INSERT AT POSITION   \n");        
        printf ("      7    -->    DELETE FROM BEGINING   \n");        
        printf ("      8    -->    DELETE FROM END   \n");        
        printf ("      9    -->    DELETE FROM A POSITION   \n");        
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
            fdisplay();
            break;
        case 4:
            bdisplay();
            break;
        case 5:
            insert_end();
            break;
        // case 6:
        //     insert_after();
        //     break;
        case 7:
            del_beg();
            break;
        case 8:
            del_end();
            break;
        // case 9:
        //     del_pos();
        //     break;
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