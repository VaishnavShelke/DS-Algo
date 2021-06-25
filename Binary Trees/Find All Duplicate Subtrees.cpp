#include <bits/stdc++.h>
using namespace std;
 
// Find All Duplicate Subtrees

struct Node {
    int data;
    struct Node* left, *right;
};

string inOrderprintAllDups(Node* root,unordered_set<string>& str_Occur,unordered_set<Node*>& headNodes){

    if(root == NULL) return "";

    string str = "(";
    str += inOrderprintAllDups(root->left,str_Occur,headNodes);
    str += (char)root->data;
    str += inOrderprintAllDups(root->right,str_Occur,headNodes);
    str += ")";
    if(str_Occur.find(str) == str_Occur.end()){
        str_Occur.insert(str);
    }
    else{
        headNodes.insert(root);
    }
    return str;
}
 

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printAllDups(Node* root){
    unordered_set<string> str_Occur;
    unordered_set<Node*> headNodes;
    string str = inOrderprintAllDups(root,str_Occur,headNodes);

    unordered_set<int> unique;
    for(auto itr = headNodes.begin() ; itr != headNodes.end(); itr++){
        if(unique.find((*itr)->data) == unique.end()){
            cout << (*itr)->data << " ";
            unique.insert((*itr)->data);
        }
    }
    return;
}


int main()
{
    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->left->left = newNode(4);
    root->right->right = newNode(4);
    printAllDups(root);
    return 0;
}
