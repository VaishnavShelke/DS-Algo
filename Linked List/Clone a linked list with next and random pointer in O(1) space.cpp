#include <iostream>
#include <bits\stdc++.h>

using namespace std;

/**
 * !           Find pairs with given sum in doubly linked list                                
 * *          doubly linked list of positive distinct elements    
 **/

struct Node
{
    int data;
    Node *next,*random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};
void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

Node* clone(Node* head1){
    Node* current1 = head1;
    Node* second1;
    Node* baby;

    while(current1 != NULL){
        second1 = current1->next;
        current1->next = new Node(current1->data);
        current1->next->next = second1;
        current1 = second1;
    }
    current1 = head1;

    while(current1 != NULL){
        baby = current1->next;
        baby->random = current1->random->next;
        current1 = baby->next;
    }

    Node* head2 = head1->next;
    Node* current2 = new Node(9999);

    current1 = head1;
    while(current1 != NULL){
        baby = current1->next;
        second1 = baby->next;
        current1->next = second1;
        current1 = second1;
        current2->next = baby;
        current2 = baby;
    }
    return head2;

}

// Driver code
int main()
{
    Node* start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);
 
    // 1's random points to 3
    start->random = start->next->next;
 
    // 2's random points to 1
    start->next->random = start;
 
    // 3's and 4's random points to 5
    start->next->next->random =
                    start->next->next->next->next;
    start->next->next->next->random =
                    start->next->next->next->next;
 
    // 5's random points to 2
    start->next->next->next->next->random =
                                      start->next;
 
    cout << "Original list : \n";
    print(start);
 
    cout << "\nCloned list : \n";
    Node *cloned_list = clone(start);
    print(cloned_list);
 
    return 0;
}
