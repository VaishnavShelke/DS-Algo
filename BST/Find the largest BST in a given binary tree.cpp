#include<bits/stdc++.h>
 
using namespace std;
 
// Find the largest BST in a given binary tree

class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
         
    }
};
 
bool isBSTCheck(node* root,int& minm,int& maxim,unordered_map<node*,int>& nodesCount){

    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        minm = root->data; maxim = root->data;
        nodesCount[root] = 1;
        return true;
    }

    int leftMaxim = INT_MIN,leftMinm = INT_MAX,rightMaxim = INT_MIN,rightMinm = INT_MAX;
    if(isBSTCheck(root->left,leftMinm,leftMaxim,nodesCount) && isBSTCheck(root->right,rightMinm,rightMaxim,nodesCount)){
        if(root->data>leftMaxim && root->data<rightMinm){
            minm = leftMinm;
            maxim = rightMaxim;
            if(root->left == NULL){ nodesCount[root] = nodesCount[root->right] + 1;}
            else if(root->right == NULL){ nodesCount[root] = nodesCount[root->left] + 1;}
            else nodesCount[root] = nodesCount[root->left] + nodesCount[root->right] + 1;
            
            return true;
        }
    }

    return false;

}

int largestBST(node* root){

    unordered_map<node*,int> nodesCount;
    int minm,maxim;
    bool istree = isBSTCheck(root,minm,maxim,nodesCount);
    node* maxTree = NULL;
    int maxMem = 0 ;
    int arr[nodesCount.size()]; int index = 0;
    for(auto itr = nodesCount.begin(); itr != nodesCount.end() ; itr++){
        arr[index] = itr->second ; index++;
    }
    for(int i = 0; i<nodesCount.size() ; i++){
        maxMem = std::max(arr[i],maxMem);
    }
    return maxMem;
}
 

int main()
{
        /* Let us construct the following Tree
             50
            / \
           10  60
        / \     / \
        5 20   55 70
               /   / \
              45  65 80
    */
         
    node *root = new node(50);
    root->left = new node(10);
    root->right = new node(60);
    root->left->left = new node(5);
    root->left->right = new node(20);
    root->right->left = new node(10);
    //root->right->left->left = new node(45);
    root->right->right = new node(70);
    root->right->right->left = new node(65);
    root->right->right->right = new node(80);
    
    /* The complete tree is not BST
    as 45 is in right subtree of 50.*/
  
    
    cout<<"Size of the largest BST is "<< largestBST(root);
 
    return 0;
}
