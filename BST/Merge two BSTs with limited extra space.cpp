#include <iostream>
#include <stack>
using namespace std;

// Merge Two BST with O(height1 + height2) extra space


class node
{
    public:
    int data;
    node *left;
    node *right;
};
 
node* newNode (int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void merge(node* root1, node* root2){

    stack<node*> stc1,stc2;
    node* curr1 = root1,*curr2 = root2;

    while(1){

        while(curr1 != NULL) { stc1.push(curr1); curr1 = curr1->left;}
        while(curr2 != NULL) { stc2.push(curr2); curr2 = curr2->left;}

        if(!stc1.empty() && !stc2.empty()){
            root1 = stc1.top();
            root2 = stc2.top();
            if(root1->data > root2->data){
                
                cout << root2->data << " ";
                stc2.pop();
                curr2 = root2->right;
            }
            else{
                cout << root1->data << " ";
                stc1.pop();
                curr1 = root1->right;                
            }
        }

        else{
            if(!stc1.empty() || !stc2.empty()){
                if(stc1.empty()){
                    root2 = stc2.top();
                    stc2.pop();
                    cout << root2->data << " ";
                    curr2 = root2->right;
                }
                else{
                    root1 = stc1.top();
                    stc1.pop();
                    cout << root1->data << " ";
                    curr1 = root1->right;
                }
            }
            else{
                break;
            }
        }
    }       
}

int main()
{
    node *root1 = NULL, *root2 = NULL;

    root1 = newNode(3);
    root1->left = newNode(1);
    root1->right = newNode(5);
 
    root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(6);

    merge(root1, root2);
 
    return 0;
}
