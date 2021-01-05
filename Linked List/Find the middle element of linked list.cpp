#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Find the middle element of the linked list
// Super intellegent recursive technique by me
/*
    we know that the middle element of linked list is when
    the index of element is == total depth of list/2 + 1;

    we pass two parameters to depth find 
        1. Current element
        2. the index/rank of current element
    the depth{from current -->> NULL} == 1 + depth{from current->next --->>> NULL};

    universal depth = rank of current element + depth{from current->next --->>> NULL, pass rank of current + 1};
    remains constant throught all stacks of recursion 

    meanwhile...
        whenever 
        rank of current element == ( rank of current element + depth{from current->next -->> NULL} )/2 + 1;
        Global var middle-element = current;
*/

class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat){
        data = dat;
    }
};
Node* middle;
void middle_element(Node* h1);


/*
    2 -> 12 -> 5 -> 4 -> 3 -> 2 ->2 -> NULL;
         
*/
/*
 Depth find calculates depth till NULL;
 And also includes current pointer.
*/
int depth_find(Node* current,int ith_stack){
    
    if(current == NULL){
        return 0;
    }
    int universal_depth = ith_stack + depth_find(current->next,ith_stack + 1);
    int depth = 1 + depth_find(current->next,ith_stack+1);
    if(ith_stack == universal_depth/2 + 1)
        middle = current; 
    
    return depth;
}


int depth_find(Node* current,int ith_stack);
void middle_element(Node* h1){
    int depth = depth_find(h1,1);
}



int main(){
    Node* head1;
    Node* head2;

    head1 = new Node(4);
    head1->next = new Node(8);
    head1->next->next = new Node(10);
    head1->next->next->next = new Node(15);
    head1->next->next->next->next = new Node(18);
    head1->next->next->next->next->next = new Node(20);
    // head1->next->next->next->next->next->next = new Node(22);
    

    middle_element(head1);
    
    
    cout << "Middle element of linked list ... \n";
    cout << middle->data;
    return 0;
}

