int FindMergeNode(Node *headA, Node *headB)
{
    if (headA == headB)
        return headA->data;

    // Get Node counts
    int countA = 0;
    Node *temp = headA;
    while (temp) {
        countA++;
        temp = temp->next;
    }
    
    int countB = 0;
    temp = headB;
    while (temp) {
        countB++;
        temp = temp->next;
    }
    
    // Advance whichever list necessary to get the same # of nodes
    while (countB > countA) {
        headB = headB->next;
        countB--;
    }
    
    while (countA > countB) {
        headA = headA->next;
        countA--;
    }
        
    // Step through to see where we find a matching node.
    while (headA && headB) {
      if (headA == headB)
        return headA->data;

      headA = headA->next;
      headB = headB->next;
    }
    
    return -1;
}
