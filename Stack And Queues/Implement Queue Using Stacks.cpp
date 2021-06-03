#include<iostream>
#include<bits\stdc++.h>

using namespace std;

// Implement Queue using stack

class Queue{
private:
    stack<int> deposit,withdraw; int total;
public:
    Queue(){total = 0;}
    void enQueue(int i){
        deposit.push(i);
        total++;
    }
    int deQueue(){
        if(total == 0) return -999;
        int top;
        if(!withdraw.empty()){
            top = withdraw.top();
            withdraw.pop();
        }
        else{
            while(!deposit.empty()){
                withdraw.push(deposit.top());
                deposit.pop();
            }
            top = withdraw.top();
            withdraw.pop();
        }
        total--;
        return top;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
  
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << "\n";
  
    return 0;
}
