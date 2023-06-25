#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int>&myMap){
    
    while(head){
        if(myMap.find(head)==myMap.end()) return true;
        if(myMap[head] != (head->data)) return true;
        
        head=head->next;
    }
}




// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution
{
    public:  
Node* detectloop(Node *head){
        Node* slow = head;   // change
        Node* fast = head;   // change
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                return slow; // ek point aayega loop mein jha dono intersect karenge and it will give the intersection point in the loop
            }
        }
        return NULL;
    }
    
    Node* getstartingnode(Node *head){
        if(head==NULL){
            return NULL;
        }
        
        if(detectloop(head) == NULL) 
        {
          return NULL;   // change I have done
         }

        // if we start one pointer from the intersection point and one from the starting of the linked list them
      // it will always be coinciding at the starting node of the loop 
      
        Node* intersection = detectloop(head); 
        Node* slow = head;
        while(slow!=intersection){
            slow=slow->next;
            intersection = intersection->next;
        }
        return slow;
    }
    
    void removeLoop(Node* head)
    {
        if(head==NULL) {
            return;
        }
        
        if(getstartingnode(head) == NULL) {
          
          return;
        }    // change I have dome
        
        Node* startofloop = getstartingnode(head);
        Node* temp = startofloop;
      while(temp->next!=startofloop){
          temp=temp->next;
      }
        temp->next=NULL;
      // after this no loop exist in the linked list and the linked list becomes linear
    }   
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<Node *, int>myMap;
        
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        myMap[head]=num;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail]=num;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
