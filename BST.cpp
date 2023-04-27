#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL) return;
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node* insertNode(struct node* node, int key) 
{
    /* 1. If the tree is empty, return a new, single node */
    if (node == NULL) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        
        newNode ->key = key;
        newNode ->left = newNode->right = NULL;
        return newNode;
        
    }   
        

    // Otherwise, recurse down the tree .
    else
    {
        if (key <= node->key)
            node->left  = insertNode(node->left, key);
        else
            node->right = insertNode(node->right, key);

    }
    /* return the (unchanged) node pointer */
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;

  if (key < root->key) root->left = deleteNode(root->left, key);
  else if (key > root->key) root->right = deleteNode(root->right, key);

  else {
    // node with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }

    // node with two children
    struct node *temp = root->right;
    while (temp->left != NULL) temp = temp->left;

    // Copy the inorder content to this node
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }

  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
