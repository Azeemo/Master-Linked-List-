int countNodesinLoop(struct Node *head)
{
    if (head == NULL || head->next == NULL) {
        return 0;
        // No loop, so return 0
    }
    
    Node* slow = head;
    Node* fast = head;
    bool loopDetected = false;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            loopDetected = true;
            break;
        }
    }
    
    if (loopDetected) {
        int count = 1;
        slow = slow->next;
        while (slow != fast) {
            slow = slow->next;
            count++;
        }
        return count;
    }
    
    return 0; // No loop found, so return 0
}
