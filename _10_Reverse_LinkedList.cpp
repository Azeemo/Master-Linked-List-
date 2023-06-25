//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/
//////////////////////////////////////////////////////////////////////////////
class Solution
{
    public:  // learned by apni collge
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {  
        // there is anotherr recursive approach for this 
        // in this approach
        
        Node * currptr=head;  // initalized to head
        Node * prevptr =NULL;
        Node * nextptr=NULL;
        
        while(currptr!=NULL){
        nextptr=currptr->next; // we dont need ot update the next as it already being done in the beginnning
        currptr->next=prevptr; //  we have to reverse all the arrows of linking 
            // and keep mooving all the pointers in the forward direction
        prevptr=currptr;
        currptr=nextptr;
            
        }
      head = prevptr; // prevptr has reached the end which is the new head
      return head;
    }
    
};
    
///////////////////////////////////////////////////////////////////////////////////////

//{ Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}
