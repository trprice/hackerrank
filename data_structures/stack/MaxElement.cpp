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

int findMax(Node *head) {
    if (head == NULL)
        return -1;
    
    int currentMax = -1;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data > currentMax)
            currentMax = temp->data;
        
        temp = temp->next;
    }

    return currentMax;
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
                // Another optimization would be to add a bool tracking whether
                // the stack is sorted. If it is, we could simply update from
                // the head after popping. During an add, we'd have to mark it
                // false and wait for another find to update it.
                // 
                // That being said, this implementation is fast enough for
                // HackerRank so I'm not going to bother implementing that now.
                if (head->data == max)
                    max = findMax(head->next);

                head = pop(head);
                break;
                
            case '3':
                cout << max;
                break;
        }
    }
    
    return 0;
}
