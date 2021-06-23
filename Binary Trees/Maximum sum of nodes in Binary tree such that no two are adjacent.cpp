#include <bits/stdc++.h>
using namespace std;

// Maximum sum of nodes in Binary tree such that no two are adjacent

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data)
{
    struct Node *temp = new struct Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
 int getMaxSumUtil(Node* root,int inorOut,unordered_map<Node*,unordered_map<int,int>>& memo){

    if (root == NULL) return 0;
    if(memo.find(root) != memo.end()) {
        if(memo[root].find(inorOut) != memo[root].end()){
            return memo[root][inorOut];
        }
    }
    int result,r1,r2,r3,r4;
    if(inorOut == 1){
        result = root->data + getMaxSumUtil(root->left,0,memo) + getMaxSumUtil(root->right,0,memo);
    }
    else{
        r1 = getMaxSumUtil(root->left,0,memo) + getMaxSumUtil(root->right,0,memo);
        r2 = getMaxSumUtil(root->left,1,memo) + getMaxSumUtil(root->right,1,memo);
        result = max(r1,r2);
        r3 = getMaxSumUtil(root->left,0,memo) + getMaxSumUtil(root->right,1,memo);
        result = max(result,r3);
        r4 = getMaxSumUtil(root->left,1,memo) + getMaxSumUtil(root->right,0,memo);
        result = max(result,r4);
    }

    memo[root][inorOut] = result;
    return result;
 }

int getMaxSum(Node* root){

    unordered_map<Node*,unordered_map<int,int>> memo;
    return max(getMaxSumUtil(root,0,memo),getMaxSumUtil(root,1,memo));
}
 

int main()
{
    Node *root= newNode(10);
    root->left= newNode(1);
    root->left->left= newNode(2);
    root->left->left->left= newNode(1);
    root->left->right= newNode(3);
    root->left->right->left= newNode(4);
    root->left->right->right= newNode(5);
 
    cout << getMaxSum(root) << endl;
    return 0;
