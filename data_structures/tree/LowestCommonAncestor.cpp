#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *lca(Node *root, int v1, int v2) {
    if (root == NULL)
        return NULL;
    
    Node *result = NULL;
    
    if (root->data > v1 && root->data > v2)
        result = lca(root->left, v1, v2);
    else if (root->data < v1 && root->data < v2)
        result = lca(root->right, v1, v2);
    else if ((root->data <= v1 && root->data >= v2) ||
             (root->data <= v2 && root->data >= v1))
        result = root;
    
    return result;
}

Node *bst_insert(Node *root, int value) {
	if (root == NULL) {
    root = new Node;
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    return root;
	}

  if (root->data < value)
    root->right = bst_insert(root->right, value);
  else if (root->data >= value)
    root->left = bst_insert(root->left, value);

  return root;
}

void inorder_print(Node *root) {
  if (root == NULL)
    return;

  inorder_print(root->left);

  cout << root->data << " ";

  inorder_print(root->right);
}

int main(void) {
  Node *root = NULL;

  root = bst_insert(root, 4);
  root = bst_insert(root, 2);
  root = bst_insert(root, 1);
  root = bst_insert(root, 3);
  root = bst_insert(root, 7);
  root = bst_insert(root, 6);

  cout << "Current Tree: ";
  inorder_print(root);
  cout << endl;

  Node *found = NULL;
  
  found = lca(root, 1, 7);
  cout << "For 1 and 7, found root with data: " << found->data << endl;

  found = lca(root, 2, 3);
  cout << "For 2 and 3, found root with data: " << found->data << endl;

  found = lca(root, 1, 3);
  cout << "For 1 and 3, found root with data: " << found->data << endl;

  return 0;
}
