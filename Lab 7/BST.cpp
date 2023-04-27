#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root==NULL){
    return;
  }
  else{
    traverseInOrder(root->left);
    cout << root-> key<<" ";
    traverseInOrder(root->right);
  }
}


// Insert a node
struct node *insertNode(struct node *node, int key) {
  //allocating memory from heap segment to cerate new node.
  struct node* new_member = (struct node*)malloc(sizeof(struct node));
  new_member-> key = key;
  new_member->left = NULL;
  new_member->right = NULL;
  if (node == NULL){
    node=new_member;
    return node;
  }
  else{
    struct node* temp = node;
    while (true){
      if (temp->key < key){
        if (temp->right == NULL){
          temp->right = new_member;
          return node;
        }
        else{
          temp = temp->right;
        }
      }
      else if (temp->key > key){
        if (temp->left == NULL){
          temp->left = new_member;
          return node;
        }
        else{
          temp = temp->left;
        }
      }
      else{
        return node;
      }
    }
  }
  
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL){
    return root;
  }
  if (root->key >key){
    root-> left = deleteNode(root->left,key);
  }
  else if (root->key < key){
    root-> right = deleteNode(root->right,key);
  }
  else{
    //case: right child is absent
    if (root -> right == NULL){
      return root-> left;
    }
    //case: left child is absent.
    else if (root -> left == NULL){
      return root-> right;
    }

    //case: both right and left child are present.
    else{
      //find the minimum node in the right subtree.
      struct node* minNode = root->right;
      while(minNode-> left != NULL){
        minNode = minNode-> left;
      }
      root-> key = minNode-> key;
      root->right = deleteNode(root->right,minNode->key);
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