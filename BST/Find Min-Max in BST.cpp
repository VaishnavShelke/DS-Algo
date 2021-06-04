#include <bits/stdc++.h>
#include<iostream>
using namespace std;



class Node{
public:
    int data; Node *left, *right;
    Node(){left = NULL; right = NULL;}
    Node(int data){left = NULL; right = NULL; this->data = data;}
};

class BST{
private:
    Node* head;
public:
    BST(){head = NULL;}
    BST(int data){ head = new Node(data);}

    Node* search(int data){
        return searchBST(this->head,data);
    }
    Node* searchBST(Node* current, int key){
        if(current == NULL) return NULL;
        if(current->data == key){
            return current;
        }
        else if(current->data < key){
            return searchBST(current->right,key);
        }
        else{
            return searchBST(current->left,key);
        }
    }

    Node* insertBST(Node* parent,int child){
    
        if(parent == NULL){
            parent = new Node;
            parent->data = child;
            return parent;
        }
        if(parent->data<child){
            parent->right = insertBST(parent->right,child);
        }
        else{
            parent->left = insertBST(parent->left,child);
        }
        return parent;
    }
    void insert(int value){
        head = insertBST(this->head,value);
    }
    
    int findmax(){
        Node* current = this->head;
        while(current->right != NULL){
            current = current->right;
        }
        return current->data;
    }
    int findmin(){
        Node* current = this->head;
        while(current->left != NULL){
            current = current->left;
        }
        return current->data;
    }
    void inorderBST(Node* root){
        if(root == NULL) return;
        inorderBST(root->left);
        cout << root->data << " ";
        inorderBST(root->right);
        return;
    }
    void inorder(){
        inorderBST(this->head);
    }

    Node* ioSucessorBST(Node* ourNode){
        if(ourNode == NULL) return NULL;
        while(ourNode->left != NULL){
            ourNode = ourNode->left;
        }
        return ourNode;
    }
    Node* ioSucessor(int key){
        Node* ourNode = searchBST(this->head,key);
        if(ourNode->right != NULL)
            return ioSucessorBST(ourNode->right);
        else{
            Node* current = this->head;
            stack<Node*> stc;
            while(current->data != key){
                if(current->data>key){
                    stc.push(current);
                    current = current->left;
                }
                else{
                    stc.push(current);
                    current = current->right;
                }
            }
            stc.push(current);
            
            Node* ancestorSucc = NULL;
            while(!stc.empty()){
                current = stc.top();
                stc.pop();
                if(stc.top()->left == current){
                    ancestorSucc = stc.top();break;
                }
            }
            
            return ancestorSucc;

        }
    }

    Node* ioPredecessorBST(Node* ourNode){
        if(ourNode == NULL){
            return NULL;
        }
        while(ourNode->right != NULL){
            ourNode = ourNode->right;
        }
        return ourNode;
    }

    Node* ioPredecessor(int key){
        Node* ourNode = searchBST(this->head,key);
        if(ourNode->left != NULL)
            return ioPredecessorBST(ourNode->left);
        else{
            Node* current = this->head;
            stack<Node*> stc;
            while(current->data != key){
                if(current->data>key){
                    stc.push(current);
                    current = current->left;
                }
                else{
                    stc.push(current);
                    current = current->right;
                }
            }
            stc.push(current);
            
            Node* ancestorSucc = NULL;
            while(!stc.empty()){
                current = stc.top();
                stc.pop();
                if(stc.top()->right == current){
                    ancestorSucc = stc.top();break;
                }
            }
            
            
            return ancestorSucc;


        }
    }

    void parentBST(Node* current,int key,Node** father){
        if(current->data == key) {father = NULL; return;}
        if(current->left!= NULL && current->left->data == key) {*father = current; return;}
        if(current->right!= NULL && current->right->data == key) {*father = current; return;}
        if(current->data>key){
            parentBST(current->left,key,father);
        }
        else{
            parentBST(current->right,key,father);
        }
        return;
    }
    Node* parent(int child){
        Node* father;
        parentBST(this->head,child,&father);
        return father;
    }

    void deleteNode(int data){
        Node* ourNode = searchBST(this->head,data);

        Node* sucessor = ioSucessorBST(ourNode);
        Node* predecessor = ioPredecessorBST(ourNode);

        Node* father;
        if(ourNode->left == NULL && ourNode->right == NULL){
            father = parent(ourNode->data);
            if(father!= NULL){
                if(father->left == ourNode){
                    father->left = NULL;
                }
                else{
                    father->right = NULL;
                }
                delete ourNode;
            }
            else{
                delete ourNode;
            }
        }
        else if(ourNode->left == NULL){
            ourNode->data = predecessor->data;
            father = parent(predecessor->data);
            if(father!= NULL){
                if(father->left == predecessor){
                    father->left = NULL;
                }
                else{
                    father->right = NULL;
                }
                delete predecessor;
            }
            else{
                delete sucessor;
            }

        }
        else{
            ourNode->data = sucessor->data;
            father = parent(sucessor->data);
            if(father!= NULL){
                if(father->left == sucessor){
                    father->left = NULL;
                }
                else{
                    father->right = NULL;
                }
                delete sucessor;
            }
            else{
                delete sucessor;
            }

        }

    }
};

int main()
{
    /* Let us create following BST
            50
        /     \
        30     70
        / \ / \
    20 40 60 80 */

    
    BST* root = new BST;
    root->insert(50);
    root->insert(30);
    root->insert(20);
    root->insert(40);
    root->insert(70);
    root->insert(60);
    root->insert(80);
    root->insert(10);
    root->insert(35);
    root->deleteNode(60);
    root->deleteNode(10);    
    root->deleteNode(35);
    root->inorder();
    return 0;
   
}
