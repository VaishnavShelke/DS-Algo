#include<iostream>
#include<bits\stdc++.h>

using namespace std;

// Convert A BiNARY TREE TO DOUBLY LINKED LIST OR LINKED LIST


class Node{
public:
    int data; Node *left, *right;
    Node(){left = NULL; right = NULL;}
    Node(int data){ this->data = data; left = NULL; right = NULL;}
};

Node* newNode(int data){
    Node* temp = new Node(data);
    return temp;
}

int stringtoInt(string str){
    int sum = 0;int factor = 1;
    for(int i = str.size()-1; i>=0; i--){
        sum = sum + ((int)(str[i]-'0'))*factor; 
        factor = factor*10;
    }
    return sum;
}
int makeNumber(int* index,string str){
    int i = *index;
    string temp = "";

    while(i<str.size() && str[i] != ')' && str[i] != '(' ){
        temp += str[i];i++;
    }
    i--;
    *index = i;
    return stringtoInt(temp);
}
void levelOrder(Node* root){

    queue<Node*> qu;
    qu.push(root);
    Node* parent;
    
    while(!qu.empty()){
        parent = qu.front();
        qu.pop(); cout << " ---> " << parent->data;

        if(parent->left != NULL) qu.push(parent->left);
        if(parent->right != NULL) qu.push(parent->right); 
    }
}

void stringTotree(string str){

    map<int,vector<int>> tre; 
    int index = 0;
    pair<Node*,int> child;
    stack<pair<Node*,int>> stc;
    int number;
    while(index < str.size()){

        if(str[index] != '(' && str[index] != ')'){
            number = makeNumber(&index,str);
            stc.push(make_pair(newNode(number),0));
            index++;
        }
        else if(str[index] == '('){
            index++;
        }
        else if(str[index] == ')'){
            child = stc.top();
            stc.pop();
            if(stc.top().second == 0){
                stc.top().first->left = child.first; stc.top().second++;
            }
            else{
                stc.top().first->right = child.first;
            }
            index++;
        }
        else{index++;}
    }
    Node* root  = stc.top().first;
    cout << "The tree is ... \n";
    levelOrder(root);

}
int main(){
    string str = "4(2(3)(1))(6(5))";
    stringTotree(str);
}
