#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !                          TOP VIEW                               
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

class HorizontalLoc{
public:
    int loc;
};

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
};


void topView(leaf* root){

    dualQueue dq;
    pair<int,int> range = make_pair(+1,0);
    line qu;
    pair<leaf*,int> father;
    leaf* parent;
    qu.push(root,0);

    while(!qu.empty()){
        father = qu.front();
        if(father.second<range.first){
            range.first--;
            dq.frontAdd(father.first->data);
        }
        if(father.second>range.second){
            range.second++;
            dq.backAdd(father.first->data);
        }
        
        parent = father.first;
        qu.pop();
        if(parent->left != NULL){ 
            qu.push(parent->left,father.second -1);
        }
        if(parent->right != NULL) {
            qu.push(parent->right,father.second + 1);
        }
    }

    dq.printit();

}

int main()
{
    // Let us create binary tree shown in above diagram
    leaf* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->left->left = newNode(5);
    root->left->left->left->left = newNode(9);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
    root->right->right->left->right = newNode(11);
    root->right->right->left->right->right = newNode(13);
    int depth = -1;
    topView(root);
    return 0;
}
