#include<bits/stdc++.h>
using namespace std;

// Replace every element with the least greater element on its right

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(){
        left = NULL; right = NULL;
    }
    Node(int data){
        left = NULL; right = NULL; this->data = data;
    }
};

Node* insertNode(Node* root,int newbie,Node** sucessor){

    if(root == NULL){
        return new Node(newbie);
    }
    if(root->data > newbie){
        *sucessor = root;
        root->left = insertNode(root->left, newbie,sucessor);
    }
    else if(root->data < newbie){
        root->right = insertNode(root->right, newbie,sucessor);
    }
    else{
        return root;
    }
    return root;
}
void replace(int* arr,int n){

    Node* sucessor = NULL;
    Node* root = insertNode(NULL,arr[n-1],&sucessor);
    arr[n-1] = -1;
    for(int i = n-2; i>= 0 ;i--){
        sucessor = NULL;
        root = insertNode(root,arr[i],&sucessor);
        if(sucessor == NULL){
            arr[i] = -1;
        }
        else{
            arr[i] = sucessor->data;
        }
    }

}


// Driver Program to test above functions
int main()
{
    int arr[] = { 8,  58, 71, 18, 31, 32, 63, 92,
                  43, 3,  91, 93, 25, 80, 28 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    replace(arr, n);
 
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}
