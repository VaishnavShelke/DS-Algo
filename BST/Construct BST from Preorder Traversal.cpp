#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
};
 
node* newNode(int data)
{
    node* temp = new node();
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}

void printInorder(node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

node* constructTreeUtil(int* arr,int low, int high,map<int,int>& midFinder){

    if(low == high) return newNode(arr[low]);
    if(low > high) return NULL;
    int mid = midFinder[arr[low]];
    node* root = newNode(arr[low]);


    if(mid == high + 1){
        root->left = constructTreeUtil(arr,low+1,high,midFinder);
        root->right = NULL;
    }
    else{
        root->left = constructTreeUtil(arr,low+1,mid,midFinder);
        root->right = constructTreeUtil(arr,mid+1,high,midFinder);
    }

    return root;
}


void midFinderFun(map<int,int>& midFinder,int* arr,int size){
    //  { 10, 5, 1, 7, 40, 50 }
    stack<int> stc;

    for(int i = 0; i<size ; i++){
        if(stc.empty()){
            stc.push(i);
        }
        else{
            while(!stc.empty() && arr[i] > arr[stc.top()]){
                midFinder[arr[stc.top()]] = i-1;
                stc.pop();
            }
            stc.push(i);
        }
    }
    while(!stc.empty()){
        midFinder[arr[stc.top()]] = size-1; stc.pop();
    }

}

node* constructTree(int* arr,int size){

    map<int,int> midFinder;
    midFinderFun(midFinder,arr,size);

    return constructTreeUtil(arr,0,size-1,midFinder);
}

void printPreorder(node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
    return;
}


int main()
{
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
 
    node* root = constructTree(pre, size);
 
    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);
    cout << "\nPreorder traversal of the constructed tree: \n";
    printPreorder(root);
 
    return 0;
}
