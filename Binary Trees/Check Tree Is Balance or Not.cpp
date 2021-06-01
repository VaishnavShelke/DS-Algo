#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !                     CHECK IF THE TREE IS BALANCE OR NOT                    
 * ?                       HEIGHT BALANCED TREE                               
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

int hDiff(leaf* root){

    if(root == NULL) return 0;
    int h1,h2;

    h1 = hDiff(root->right);
    h2 = hDiff(root->left);

    if(std::abs(h1-h2)>1) throw 10;
    return max(h1,h2)+1;
}

bool checkBalance(leaf* root){
    int maxdepth;
    try{
        maxdepth = hDiff(root);
        return true;
    }
    catch (int){
        return false;
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

    if(checkBalance(root))
        cout << "the Tree is Balanced .... ";
    else
        cout << "The tree is unbalanced .... ";
    
    return 0;
}
