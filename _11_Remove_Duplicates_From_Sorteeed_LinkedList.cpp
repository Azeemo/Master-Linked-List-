bool RepeatedElement(Node* head)
{
    set<int> m;
    int count =0;
    Node *ptr =head;
    while(ptr!=NULL){
       m.insert(ptr->data);
       ptr=ptr->next;
       count++;
    }
    
    return ((m.size()!=count)? true:false);
}

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
  if(RepeatedElement(head))  {
         Node* curr = head;
    while(curr->next!=NULL)
    {
        if(curr->data == curr->next->data)
        {
            Node* nodetodelete = curr->next;
            curr->next = curr->next->next;
            delete(nodetodelete);
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

  
  else{
      return head;
  }
 
}
