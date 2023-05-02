#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if(root == NULL){
    return;
  }
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if(node == NULL){
    struct node *new_node = new struct node;
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }
  if(key>node->key){
    node->right = insertNode(node->right, key);
    return node;
  }
  else{
    node->left = insertNode(node->left, key);
    return node;
  }
}

struct node *maxValueNode(struct node *node){
  struct node *temp = node;
  while (node->right != NULL){
    temp = node->right; 
  }
  return temp;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key){
  if(root == NULL){
    return NULL;
  }
  if(key < root->key){
    root->left = deleteNode(root->left, key);
    return root;
  }
  else if(key > root->key){
    root->right = deleteNode(root->right, key);
    return root;
  }
  else{
    // root with no child
    if(root->left == NULL and root->right == NULL){
      return NULL;
    }
    // root with only one child
    else if(root->left == NULL){
      struct node* temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == NULL){
      struct node* temp = root->left;
      delete root;
      return temp;
    }
    else{
      struct node* temp = maxValueNode(root->left);
      root->key = temp->key;
      root->left = deleteNode(root->right, temp->key);
      return root;
    }
  }
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