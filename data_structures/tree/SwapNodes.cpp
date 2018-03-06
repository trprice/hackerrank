#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    int depth;
    int nodeNumber;
    Node *left;
    Node *right;
   
    Node() : data(-1), depth(-1), nodeNumber(-1), left(NULL), right(NULL) {}
};

// Breadth First / Level Order Search

// Depth visitor
Node *BFS_Visit_SwapAtDepth(Node *root, int currentDepth, int desiredDepth) {
  if (root == NULL)
    return NULL;

  // This test is wrong ... how do we determine the correct depth?
  if (desiredDepth == 1) {
    Node *temp = root->right;

    root->right = root->left;
    root->left = temp;

    return root;
  }
  else {
    Node *found;

    found = BFS_Visit_SwapAtDepth(root->left, currentDepth - 1, desiredDepth - 1);
    if (found != NULL)
      return found;

    found = BFS_Visit_SwapAtDepth(root->right, currentDepth - 1, desiredDepth - 1);
    if (found != NULL)
      return found;
  }

  return NULL;
}

// Visit based on node number
Node *BFS_Visit_NodeNumber(Node *root, int currentDepth, int searchTerm) {
  if (root == NULL)
    return NULL;

  if (currentDepth == 1) {
    if (root->nodeNumber == searchTerm)
      return root;
  }
  else {
    Node *found;

    found = BFS_Visit_NodeNumber(root->left, currentDepth - 1, searchTerm);
    if (found != NULL)
      return found;

    found = BFS_Visit_NodeNumber(root->right, currentDepth - 1, searchTerm);
    if (found != NULL)
      return found;
  }

  return NULL;
}

// Print visitor
Node *BFS_Visit_Print(Node *root, int currentDepth, int searchTerm) {
  if (root == NULL)
    return NULL;

  if (currentDepth == 1) {
    cout << "NodeNumber: " << root->nodeNumber << " "\
         << "Depth: " << root->depth << " "\
         << "Data: " << root->data << endl; // Finish this.
  }
  else {
    Node *found;

    found = BFS_Visit_Print(root->left, currentDepth - 1, searchTerm);
    if (found != NULL)
      return found;

    found = BFS_Visit_Print(root->right, currentDepth - 1, searchTerm);
    if (found != NULL)
      return found;
  }

  return NULL;
}

// Change to take the visitor as a function pointer.
Node *BreadthFirstSearch(Node *root, int searchTerm, int maxHeight, Node* (*visitor)(Node *, int, int)) {
  if (root == NULL)
    return NULL;

  // Normally we'd have to calculate the height here but,
  // based on the way that input is handed to this program,
  // we can short circuit that because we've figured out the max
  // height upon input.
  for (int i = 1; i <= maxHeight; i++) {
    Node *found = NULL;
    // Always call BFS_Visit with root so the recursion works.
    found = visitor(root, i, searchTerm);

    if (found != NULL)
      return found;
  }

  return NULL;
}


// Breadth First / Level Order Printing
//    Has to visit EVERY node to print

// Tree insert based on HackerRank problem statement.
Node *insertByNodeNumber(Node *root, int leftChildValue, int rightChildValue, int childOfNode, int nodeNumber, int *currentHeight) {
    if (root == NULL) {
      Node *newNode = new Node;
      newNode->data = leftChildValue;
      newNode->depth = 1; // default for root of tree
      *currentHeight = 1;
      newNode->nodeNumber = 1;
      newNode->left = NULL;
      newNode->right = NULL;

      root = newNode;
      return root;
    }

    // Here I need to find the node with nodeNumber == childOfNode
    // This should be a breadth first search.
    Node *current = BreadthFirstSearch(root, childOfNode, *currentHeight, BFS_Visit_NodeNumber);

    if (current != NULL) {
      // Add both children with the specified values (or don't add if -1).
      if (leftChildValue == -1) {
        // Be clear about what we intend even though this is repetetive given
        // that the child would've been set to NULL on initialization.
        current->left = NULL;
      } else {
        current->left = new Node;
        
        current->left->data = leftChildValue;
        current->left->depth = current->depth + 1;
        *currentHeight = current->left->depth;
        current->left->nodeNumber = nodeNumber;
        current->left->left = NULL;
        current->left->right = NULL;
      }

      if (rightChildValue == -1) {
        // Be clear about what we intend even though this is repetetive given
        // that the child would've been set to NULL on initialization.
        current->left = NULL;
      } else {
        current->right = new Node;
        
        current->right->data = rightChildValue;
        current->right->depth = current->depth + 1;
        *currentHeight = current->right->depth;

        if (current->left != NULL)
          current->right->nodeNumber = nodeNumber + 1;
        else
          current->right->nodeNumber = nodeNumber;

        current->right->left = NULL;
        current->right->right = NULL;
      }
    }

    return root;
}

void inorderPrint(Node *root) {
  if (root == NULL)
    return;

  if (root->left != NULL)
    inorderPrint(root->left);

  cout << root->data << " ";

  if (root->right != NULL)
    inorderPrint(root->right);
}

Node *swapAtDepth(Node *root, int swapDepth, int maxHeight) {
  // Traverse to depth? Use BFS Search based on depth to get each side?
  //
  // This is probably not what we want to do because it'll only allow a swap on
  // the first node found.
  //
  // Modify the vistor to handle the swap
  root->left = BreadthFirstSearch(root->left, swapDepth-1, maxHeight, BFS_Visit_SwapAtDepth);
  root->right = BreadthFirstSearch(root->right, swapDepth-1, maxHeight, BFS_Visit_SwapAtDepth);

  return root;
}

int main() {
    // Default is a tree with value 1 at its root.
    Node *root = NULL;
    int numNodes,
        currentHeight = 1; // Cheat on height by tracking here.
    cin >> numNodes;

    root = insertByNodeNumber(root, 1, -1, -1, -1, &currentHeight);
    
    for (int i = 1, nodeNumber = 2; i <= numNodes; i++) {
      // Cheat and track height here so that we don't have
      // to compute it in the breadth first / level order search.
      int leftChildValue, rightChildValue;
      
      // Left Node
      cin >> leftChildValue;
      cin >> rightChildValue;
      root = insertByNodeNumber(root, leftChildValue, rightChildValue, i, nodeNumber++, &currentHeight);

      // Increment again to make sure we're tracking the correct child number.
      if (leftChildValue != -1 &&
          rightChildValue != -1)
        nodeNumber++;
    }
    
    cout << "After Tree creation:" << endl;
    inorderPrint(root);
    cout << endl;

    
    int numSwaps;
    cin >> numSwaps;

    cout << "numSwaps: " << numSwaps << endl;

    for (int i = 0; i < numSwaps; i++) {
      int swapDepth;
      cin >> swapDepth;

      cout << "i: " << i << " swapDepth: " << swapDepth << " currentHeight: " << currentHeight << endl;

      while (swapDepth <= currentHeight) {
        //root = BreadthFirstSearch(root, swapDepth, currentHeight, BFS_Visit_SwapAtDepth);
        root = swapAtDepth(root, swapDepth, currentHeight);

        swapDepth *= 2;
      }
    }
    

    cout << "After Swap:" << endl;
    inorderPrint(root);
    cout << endl;

    return 0;
}
