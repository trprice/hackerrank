#include <iostream>
#include <cstddef>

using namespace std;    

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
        }
        else {
            Node* cur;
            if(data <= root->data){
                cur = insert(root->left, data);
                root->left = cur;
            }
            else{
                cur = insert(root->right, data);
                root->right = cur;
           }

           return root;
       }
    }
    
    int height(Node* root) {
        int leftHeight = 0,
            rightHeight = 0;

        if (root->left) {
            leftHeight++;

            leftHeight += height(root->left);
        }
        
        if (root->right) {
            rightHeight++;

            rightHeight += height(root->right);
        }

        // Return whichever height is greater.    
        if (leftHeight >= rightHeight)
            return leftHeight;
        else
            return rightHeight;
    }

}; // End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.height(root);
    cout << height;

    return 0;
}
