#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !                       BOTTOM VIEW A LITTILE MODIFICATION OVER TOP VIEW                               
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
    void edit(int pos,int val){
        if(pos>0){
            left[pos-1] = val;
        }
        else{
            right[-1*pos] = val;
        }
    }
};


void bottomView(leaf* root){

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
        else if(father.second>range.second){
            range.second++;
            dq.backAdd(father.first->data);
        }
        else{
            dq.edit(father.second,father.first->data);
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
    leaf *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;
}
