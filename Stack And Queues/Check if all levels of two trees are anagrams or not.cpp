#include <bits/stdc++.h>
using namespace std;
  

struct Node
{
    struct Node *left, *right;
    int data;
};
  
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

bool areAnagrams(Node* root1,Node* root2){

    queue<Node*> qu;
    Node* delimiter = newNode(INT_MAX);

    vector<int> v1,v2;

    Node* parent = root1;
    qu.push(parent);
    qu.push(delimiter);

    while (qu.size() != 1)
    {
        if(qu.front() == delimiter){
            v1.push_back(INT_MAX); qu.pop();
            qu.push(delimiter);
        }
        parent = qu.front();
        v1.push_back(parent->data);
        qu.pop();
        

        if(parent->left != NULL) qu.push(parent->left);
        if(parent->right != NULL) qu.push(parent->right);
    }
    while(!qu.empty()) qu.pop();
    parent = root2;
    qu.push(parent);
    qu.push(delimiter);

    while (qu.size() != 1)
    {
        if(qu.front() == delimiter){
            v2.push_back(INT_MAX); qu.pop();
            qu.push(delimiter);
        }
        parent = qu.front();
        v2.push_back(parent->data);
        qu.pop();
        

        if(parent->left != NULL) qu.push(parent->left);
        if(parent->right != NULL) qu.push(parent->right);
    }
     
    vector<int> t1,t2;
    cout << v1.size() << " " << v2.size() << endl;
    if(v1.size()!=v2.size()) return false;
    
    for(int i = 0; i<v1.size(); i++){
        while( i<v1.size() && (v1[i] != INT_MAX || v2[i] != INT_MAX) ){
            t1.push_back(v1[i]);
            t2.push_back(v2[i]);
            i++;
        }
        sort(t1.begin(),t1.end()); sort(t2.begin(),t2.end());
        for(int i = 0; i<t1.size() ; i++){
            if(t1[i] != t2[i]) return false;
        }
        t1.clear();t2.clear();
    }
    return 1;
}

int main()
{
    // Constructing both the trees.
    struct Node* root1 = newNode(1);
    root1->left = newNode(5);
    root1->right = newNode(2);
    root1->right->left = newNode(3);
    root1->right->right = newNode(4);
  
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
  
    areAnagrams(root1, root2)? cout << "Yes" : cout << "No";
    return 0;
}
