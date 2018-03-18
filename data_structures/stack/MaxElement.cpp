#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Implement the stack as a linked list,
// inserting and deleting at the head.
struct Node {
    int data;
    Node *next;
};

Node *push (Node *head, int data) {
    Node *temp = head;
    
    head = new Node;
    head->data = data;
    head->next = temp;
    
    return head;
}

Node *pop (Node *head) {
    Node *temp = head;
   
    head = head->next;
    delete temp;
    
    return head;
}

void printMax(Node *head) {
    if (head == NULL)
        return;
    
    int currentMax = -1;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data > currentMax)
            currentMax = temp->data;
        
        temp = temp->next;
    }
    
    cout << currentMax << endl;
}

int main() {
    int numQueries = -1;
    cin >> numQueries;
    
    Node *head = NULL;
    string number;
    int data,
        max = -1;
    
    for (int i = 0; i < numQueries; i++) {
        char action;
        cin >> action;

        switch(action) {
            case '1':
                cin >> data;
                head = push(head, data);

                if (data > max)
                  max = data;

                break;
                
            case '2':
                head = pop(head);
                break;
                
            case '3':
                cout << max;
                //printMax(head);
                break;
        }
    }
    
    return 0;
}
