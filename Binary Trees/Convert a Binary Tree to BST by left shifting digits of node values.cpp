#include <bits/stdc++.h>
using namespace std;
 
// Convert a Binary Tree to BST by left shifting digits of node values

struct TreeNode
{
   int val;
   TreeNode *left, *right;
 
    TreeNode(int key)
    {
        val = key;
        left = NULL;
        right = NULL;
    }
};

void levelOrder(TreeNode *root)
{
    queue<TreeNode*> que;
    que.push(root);
    while(true)
    {
        int length = que.size();
        if (length == 0)
            break;
        while (length)
        {
            auto temp = que.front();
            que.pop();
            cout << temp->val << " ";
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
            length -= 1;
          }
          cout << endl;
        }
   
        cout << endl;
}

void reformMe(TreeNode** root,int prev){

    int miniMA = INT_MAX;
    int modi;
    string str = to_string((*root)->val);
    for(int len = 0; len<str.size() ; len++){
        modi = stoi(str.substr(len) + str.substr(0,len));
        if(modi > prev && modi < miniMA){
            miniMA = modi;
        } 
    }
    (*root)->val = miniMA; 

}

void ConvTree(TreeNode* root,int* prev){

    if(root == NULL) return;
    ConvTree(root->left,prev);
    reformMe(&root,*prev);
    *prev = root->val;
    ConvTree(root->right,prev);
    return;
}

bool isBST(TreeNode* root){

    if(root == NULL) return true;
    if(root->left != NULL && root->left->val >= root->val){
        return false;
    }
    if(root->right != NULL && root->right->val <= root->val){
        return false;
    }

    if(isBST(root->left) && isBST(root->right)){
        return true;
    }

    return true;
}

int main()
{
 
  TreeNode *root = new TreeNode(443);
  root->left = new TreeNode(132);
  root->right = new TreeNode(543);
  root->right->left = new TreeNode(343);
  root->right->right = new TreeNode(237);
 
  // Converts the tree to BST
  int prev = -9999;
  ConvTree(root, &prev);
 
  // If tree is converted to a BST
  if (isBST(root))
  {
      // Print its level order traversal
      levelOrder(root);
    }
  else
  {
     
      // not possible
      cout << (-1);
    }
}
