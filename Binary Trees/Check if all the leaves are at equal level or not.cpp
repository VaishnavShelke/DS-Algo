#include <iostream>
#include <bits\stdc++.h>
using namespace std;

// Check if all the leaves are at equal level or not

struct Node {
    int data;
    Node* left, *right;
};
 

Node* getNode(int data)
{

    Node* newNode = (Node*)malloc(sizeof(Node));
 

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool heightAt(Node* root,int depth){

    
    if(root == NULL){
        const static int leafdepth = depth;
        if(depth!=leafdepth){
            return false;
        }
        if(leafdepth == depth) return true;
    }
    
    if(heightAt(root->left,depth+1)&&
                heightAt(root->right,depth+1)){
                    return true;
                }

    return false;
}

bool HeightAT(Node* root){

    int deepest = INT_MIN;
    int sum = 0;
    int deepestsum = INT_MIN;
    return heightAt(root,0);

}
int main()
{
    // binary tree formation
    Node* root = getNode(4);         /*        4        */
    root->left = getNode(2);         /*       / \       */
    root->right = getNode(5);        /*      2   5      */
    root->left->left = getNode(7);   /*     / \ / \     */
    root->left->right = getNode(1);  /*    7  1 2  3    */
    root->right->left = getNode(2);  /*      /          */
    root->right->right = getNode(3); /*     6           */
   // root->left->right->left = getNode(6);
 
    cout << HeightAT(root);
 
    return 0;
}
