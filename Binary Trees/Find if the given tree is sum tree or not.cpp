#include <iostream>
using namespace std;

// Find if the given tree is sum tree or not

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(
        sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int isSumTree(node* root){

    int left = 9999;
    int right = 9999;
    if(root->left != NULL)  left = isSumTree(root->left);
    if(root->right != NULL)  right = isSumTree(root->right);
    if( root->left == NULL && root->right == NULL) return root->data;

    if(!(left && right)) return 0;

    if(left == 9999){
        left = 0;
    }
    if(right == 9999){
        right = 0;
    }
    if(left + right != root->data) return 0;

    return left + right + root->data;
}

/*
          26
        /   \
      10     3
    /    \     \
  4      6      3
*/



int main()
{
    struct node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);
    
    if (isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";
 
    return 0;
}
