#include <iostream>
using namespace std;
//node object
struct node {
  int key;
  struct node *left, *right;
};

//creating a new node with a given integer
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    //if the node is empty stop
    if(root == NULL)
        return;
    
    traverseInOrder(root->left);//first traverse the left sub tree
    printf("%d ",root->key);
    traverseInOrder(root->right);//Then traverse the right sub tree

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if(node == NULL)//if the node is empty create the node here
        return newNode(key);

  if(node->key < key)
        node->right = insertNode(node->right,key);// got to the right sub tree and find the suitable node to insert
  
  else if(node->key > key)
        node->left = insertNode(node->left,key);// got to the left sub tree and find the suitable node to insert

  return node;

}

struct node* minValueNode(struct node* node) // finding the minimum value relevant to a BST with the given root
{
    struct node* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

 
// Deleting a node
struct node *deleteNode(struct node *root, int key) {

    if (root == NULL)// if the tree is empty there is nothing to delete
        return root;
 
    if (key < root->key)// if the root is greater than the given value search the left sub tree
        root->left = deleteNode(root->left, key);
 
    else if (key > root->key)// if the root is less than the given value search the right sub tree
        root->right = deleteNode(root->right, key);
 
    else {//if we find the node
        if (root->left == NULL and root->right == NULL){//if the node has no children
            free(root);
            return NULL;
        }
      
        else if (root->left == NULL) {// if the node has only one child on the right
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {// if the node has only one child on the left
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        struct node* temp = minValueNode(root->right);// find the minimum value in the right subtree
 
        root->key = temp->key;// make that the value of the current node
 
        root->right = deleteNode(root->right, temp->key);// delete the node where the value was brought from in the right subtree
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