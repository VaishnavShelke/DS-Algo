#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !                       ZIZ ZAG PRINT THE TREE                               
 **/

class leaf{
public: 
    int data;
    leaf *left, *right;
    leaf(){left = NULL; right = NULL;};
    leaf(int data){left = NULL; right = NULL;this->data = data;}
};

leaf* newNode(int data){
    leaf* temp = new leaf;
    temp->data = data;
    return temp;
}

class line{
private:
    queue<pair<leaf*,int>>* qu;
public:
    line(){
        qu  = new queue<pair<leaf*,int>>;
    }
    pair<leaf*,int> front(){
        return qu->front();
    }
    void push(leaf* root,int loc){
        qu->push(make_pair(root,loc));
    }
    void pop(){
        qu->pop();
    }
    bool empty(){
        return qu->empty();
    }
    ~line(){ delete qu;}
};

class dualQueue{
private:
    vector<int> right,left;
public:
    void frontAdd(int i){
        right.push_back(i);
    }
    void frontRemove(){
        right.pop_back();
    }
    void backAdd(int i){
        left.push_back(i);
    }
    void backRemove(){
        left.pop_back();
    }
    void printit(){
        for(int i = right.size()-1; i>=0 ; i--){
            cout << " ---> " << right[i];
        }
        for(int i = 0; i < left.size(); i++){
            cout << " ---> " << left[i];
        }
    }
    void edit(int pos,int val){
        if(pos>0){
            left[pos-1] = val;
        }
        else{
            right[-1*pos] = val;
        }
    }
};


void zigZag(leaf* root){

    leaf* parent;
    queue<leaf*> qu;
    stack<leaf*> stc1,stc2;
    stc1.push(root);

    while(!stc1.empty() || !stc2.empty()){
        while(!stc1.empty()){
            parent = stc1.top();
            stc1.pop();
            cout << " ---> " << parent->data;
            if(parent->left != NULL) stc2.push(parent->left);
            if(parent->right != NULL) stc2.push(parent->right);
        }

        while(!stc2.empty()){
            parent = stc2.top();
            stc2.pop();
            cout << " ---> " << parent->data;
            if(parent->right != NULL) stc1.push(parent->right);
            if(parent->left != NULL) stc1.push(parent->left); 
        }
    }
}

int main()
{
    leaf *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    cout << "Zig Zag Traverse of the given binary tree :\n";
    zigZag(root);
    return 0;
}
