//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    private:
    string reverse(string str)
{
    int len = str.length();
    int n = len;
    string ans = "";
    while(n--)
        ans+= str[n];
    return ans;    
}
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        string s ="";
        Node *last = head;
        while(last!=NULL){
            s+=to_string(last->data);
            last=last->next;
        }
        string k = reverse(s);
        int ans = (k==s)? 1 : 0;
        return ans;
        
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}
