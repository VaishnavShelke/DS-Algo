//

// Linked list node
struct Node
{
    int data;
    struct Node* next;
};

struct Node *newNode(int data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
   
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


long long int multiplyTwoLists(Node* first,Node* second){

    long long num1 = 0,num2 = 0;

    while(first != NULL){
        num1 = num1*10 + first->data; first = first->next;
    }
    while(second != NULL){
        num2 = num2*10 + second->data; second = second->next;
    }

    return num2*num1;
}
   
void printList(struct Node *node)
{
    while(node != NULL)
    {
        cout<<node->data;
        if(node->next)
            cout<<"->";
        node = node->next;
    }
    cout<<"\n";
}
   
int main()
{
    struct Node* first = NULL;
    struct Node* second = NULL;
   
    // create first list 9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    printf("First List is: ");
    printList(first);
   
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is: ");
    printList(second);
   
    // Multiply the two lists and see result
    cout<<"Result is: ";
    cout<<multiplyTwoLists(first, second);
   
    return 0;
}
