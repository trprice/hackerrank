#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *addNode(int value) {
  Node *temp = new Node;
  temp->data = value;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

void inorderPrint(Node *root) {
  if (root == NULL)
    return;

  inorderPrint(root->left);

  cout << root->data << " ";

  inorderPrint(root->right);
}

bool findPath(Node *root, vector<int> &path, int k) {
  if (root == NULL)
    return false;

  path.push_back(root->data);

  if (root->data == k)
    return true;

  if ((root->left != NULL && findPath(root->left, path, k)) ||
      (root->right != NULL && findPath(root->right, path, k)))
    return true;

  path.pop_back();
  return false;
}

int lca(Node *root, int v1, int v2) {
  if (root == NULL)
    return -1;

  vector<int> path1, path2;

  if (!findPath(root, path1, v1) ||
      !findPath(root, path2, v2))
    return -1;

  int i;
  for (i = 0; i < path1.size() && i < path2.size(); i++)
  {
    if (path1[i] != path2[i])
      break;
  }

  if (i == 0)
    return path1[i];
  else
    return path1[i-1];
}

int main(void) {
  Node *root = addNode(1);
  root->left = addNode(2);
  root->right = addNode(3);
  root->left->left = addNode(4);
  root->left->right = addNode(5);
  root->right->left = addNode(6);
  root->right->right = addNode(7);

  inorderPrint(root);
  cout << endl;

  cout << "LCA for 4 and 5: " << lca(root, 4, 5) << endl;
  cout << "LCA for 1 and 3: " << lca(root, 1, 3) << endl;

  return 0;
}
