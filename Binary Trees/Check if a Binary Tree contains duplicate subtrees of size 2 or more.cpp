#include <iostream>
#include <bits\stdc++.h>
using namespace std;

//Check if a Binary Tree contains duplicate subtrees of size 2 or more

struct Node
{
    char key;
    Node *left, *right;
};
 
Node* newNode(char key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

string DupSubUtil(Node* root,unordered_set<string>& trees,bool* flag){

    if(root == NULL) return "";
    if(root->left == NULL && root->right == NULL){
        string temp  = "";
        return temp+root->key;
    }
    string first = DupSubUtil(root->left,trees,flag);
    string second = DupSubUtil(root->right,trees,flag);

    string tree = first + root->key + second;

    if(trees.find(tree) == trees.end()){
        trees.insert(tree);
    }
    else{
        *flag = true;
    }
    
    return tree;
}

string dupSubUtil(Node* root){
    
    unordered_set<string> trees;
    bool flag = false;
    string str = DupSubUtil(root,trees,&flag);

    cout << endl;
    if(flag){
        return "";
    }
    else{
        return "Vaishnav";
    }
}
/*           A
        B       C
    D      E       B
                D      
*/
int main()
{
    Node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('B');
    //root->right->right->right = newNode('E');
    root->right->right->left= newNode('D');
 
    string str = dupSubUtil(root);
 
    (str.compare("") == 0) ? cout << " Yes ":
                            cout << " No " ;
    return 0;
}
