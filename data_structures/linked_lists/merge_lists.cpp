#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

Node* MergeLists(Node *headA, Node* headB)
{
    if (headA == NULL)
        return headB;
    
    if (headB == NULL)
        return headA;

    // Initialize the head to return.
    Node *head, *current;
    
    if (headA->data < headB->data) {
      head = current = headA;
      headA = headA->next;
    }
    else {
      head = current = headB;
      headB = headB->next;
    }

    do {
        cout << "headA->data: " << headA->data << " headB->data: " << headB->data << endl;
        if (headA->data < headB->data) {
            current->next = headA;
            headA = headA->next;
        }
        else if (headB->data < headA->data) {
            current->next = headB;
            headB = headB->next;
        }
        else if (headA->data == headB->data) {
            current->next = headA;
            current = current->next;
            headA = headA->next;
            
            current->next = headB;
            headB = headB->next;
        }
        
        current = current->next;
    } while (headA != NULL && headB != NULL);
        
    Node *remainingHead;
    if (headA == NULL)
        remainingHead = headB;
    else
        remainingHead = headA;
    
    do {
        current->next = remainingHead;
        remainingHead = remainingHead->next;
        current = current->next;
    } while (remainingHead != NULL);
        
    return head;
}

int main(void) {
  Node *headA = new Node,
       *headB = new Node;

  Node *current = headA;
  current->data = 1;
  current->next = new Node;
  current = current->next;
  current->data = 3;
  current->next = new Node;
  current = current->next;
  current->data = 5;
  current->next = new Node;
  current = current->next;
  current->data = 6;
  current->next = NULL;

  cout << "headA: " << headA << endl;
  current = headA;
  do {
    cout << "current: " << current << " data: " << current->data << " next: " << current->next << endl;
    current = current->next;
  } while (current != NULL);

  current = headB;
  current->data = 2;
  current->next = new Node;
  current = current->next;
  current->data = 4;
  current->next = new Node;
  current = current->next;
  current->data = 7;
  current->next = NULL;

  cout << "headB: " << headB << endl;
  current = headB;
  do {
    cout << "current: " << current << " data: " << current->data << " next: " << current->next << endl;
    current = current->next;
  } while (current != NULL);

  Node *headC = MergeLists(headA, headB);

  cout << "headC: " << headC << endl;
  current = headC;
  do {
    cout << "current: " << current << " data: " << current->data << " next: " << current->next << endl;
    current = current->next;
  } while (current != NULL);

  return 0;
}
