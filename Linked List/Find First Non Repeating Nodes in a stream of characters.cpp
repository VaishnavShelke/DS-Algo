#include <iostream>
#define TOT_CHAR 256
using namespace std;
 
// Find First Non Repeating Nodes in a stream of characters
class Node {
public:
    char a;
    struct Node *next, *prev;
    Node(char data) {
        next = NULL;
        prev = NULL;
        a = data;
    }
};
 
class DLL{
    private:
        Node* head; Node* tail;
    public:
        DLL(){head = NULL; tail = NULL;}
        void addBack(Node* myData){
            if(head == NULL){
                head = myData;
                tail = head;
            }
            else{
                tail->next = myData;
                myData->prev = tail;
                tail = myData;
            }
            
        }

        void remove(Node* target){
            
            if(target == NULL) return;
            if(target->next == NULL || target->prev == NULL){
                
                if(target->next == NULL && target->prev == NULL){
                    head = NULL;tail = NULL;
                    delete target;
                }
                else if(target->prev == NULL){   
                    head = target->next;
                    head->prev = NULL;
                    delete target;
                }
                else{      
                    tail = target->prev;
                    tail->next = NULL;
                    delete target;
                }
            }
            else{
                Node* back = target->prev;
                Node* front = target->next;
                back->next = front;
                front->prev = back;
                delete target; 
            }
            return;
        }

        void popFront(){
           if(head == NULL){
               cout << "\nOperation Invalid.\n";
               return;
           } 
           else if(head == tail){
               delete head;
               head = NULL; tail = NULL;
           }
           else{
               Node* next = head->next;
               delete head;
               head = next;
           }
        }

        char front(){
            
            if(head == NULL){
                return '0';
            }
            else{
                
                return head->a;
            }
        }
}; 

void findFirstNonRepeating(){

    bool repeated[TOT_CHAR];
    Node* VipAccess[TOT_CHAR];

    for(int i = 0; i<TOT_CHAR ; i++){
        repeated[i] = false;
        VipAccess[i] = NULL;
    }

    char str[] = "geeksforgeeksandgeeksquizfor";
    int n = sizeof(str)/sizeof(str[0]);
    DLL firstNonRepeatedFirst;

    for(int i = 0; i<n ; i++){
        if(!repeated[str[i]]){
            VipAccess[str[i]] = new Node(str[i]);
            firstNonRepeatedFirst.addBack(VipAccess[str[i]]);
            repeated[str[i]] = true;
        }
        else{
            firstNonRepeatedFirst.remove(VipAccess[str[i]]);
            VipAccess[str[i]] = NULL;
        }
        char x = str[i];
        cout << "Reading " << x << " from stream \n";
        cout << "First non-repeating character so far is " << firstNonRepeatedFirst.front() << endl;
    }

}
int main()
{
    findFirstNonRepeating();
    return 0;
}
