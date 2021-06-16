#include <bits/stdc++.h>
using namespace std;

// Count pairs from two BSTs whose sum is equal to a given value x

/*
But important thing is that you learnt inorder traversal ITERATIVE
 
*/ 
struct Node {
    int data;
    Node* left, *right;
};

Node* getNode(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
 
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void countPairs(Node* root1,Node* root2,int key){


    Node* top1;
    Node* top2;
    stack<Node*> stc1;
    stack<Node*> stc2;

    while(1){

        while(root1 != NULL){
            stc1.push(root1);
            root1 = root1->left; 
        }
        while(root2 != NULL){
            stc2.push(root2);
            root2 = root2->right;
        }

        if(stc1.empty() || stc2.empty()){
            break;
        }

        top1 = stc1.top();
        top2 = stc2.top();

        if(top1->data + top2->data == key){
            cout << top1->data << " ---> " << top2->data << endl;
            stc1.pop();
            stc2.pop();
            root1 = top1->right;
            root2 = top2->left;
        }
        else if(top1->data + top2->data < key){
            stc1.pop();
            root1 = top1->right;
        }
        else{
            stc2.pop();
            root2 = top2->left;
        }
    }


}

int main()
{
    // formation of BST 1
    Node* root1 = getNode(5); /*             5        */
    root1->left = getNode(3); /*           /   \      */
    root1->right = getNode(7); /*         3     7     */
    root1->left->left = getNode(2); /*    / \   / \    */
    root1->left->right = getNode(4); /*  2  4  6  8    */
    root1->right->left = getNode(6);
    root1->right->right = getNode(8);
 
    // formation of BST 2
    Node* root2 = getNode(10); /*           10         */
    root2->left = getNode(6); /*           /   \        */
    root2->right = getNode(15); /*        6     15      */
    root2->left->left = getNode(3); /*    / \   /  \     */
    root2->left->right = getNode(8); /*  3  8  11  18    */
    root2->right->left = getNode(11);
    root2->right->right = getNode(18);
 
    int x = 16;
    countPairs(root1,root2,x);
    return 0;
}
