#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *left, *right;
};

void topView(node *root) {
    if (root == NULL)
        return;

    // Horizontal distance - data map.
    //      - This way, a horizontal distance is only recorded once and
    //        nodes, unseen from the top, are excluded.
    //      - After creation, we can go through once and print the top view.
    unordered_map<int, int> distanceMap;

    // Queue containing node * - distance pairs
    //      - This allows tree traversal without recursion AND track
    //        the horizontal distance for us in one structure.
    //      - Left == Distance - 1
    //      - Right == Distance + 1
    //      - Push left before right so that we get outer nodes first.
    queue<pair<node*, int>> q;

    // Main Root distance == 0
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<node*, int> p = q.front();
        node *currentnode = p.first;
        int currentValue = p.second;
        q.pop();

        // Determine if we should put it in the map
        if (distanceMap.find(currentValue) == distanceMap.end()) {
            distanceMap[currentValue] = currentnode->data;
            cout << currentnode->data << " ";
        }

        // Push left, if exists.
        if (currentnode->left)
            q.push(make_pair(currentnode->left, currentValue - 1));
        
        // Push right, if exists.
        if (currentnode->right)
            q.push(make_pair(currentnode->right, currentValue + 1));
    }
}

struct node* newnode(int key)
{
    struct node* current = new node;
    current->data= key;
    current->left = current->right = NULL;
    return current;
}
 
// main function
int main()
{
    /* Create following Binary Tree
             1
           /  \
          2    3
           \
            4
             \
              5
               \
                6*/
                 
    node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->right=newnode(4);
    root->left->right->right=newnode(5);
    root->left->right->right->right=newnode(6);
     
    topView(root);
    return 0;
}
