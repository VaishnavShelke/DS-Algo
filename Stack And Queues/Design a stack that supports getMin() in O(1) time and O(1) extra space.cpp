#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Add getmin function to the stack whic returns only the minimum numbe rin the stack in const time and space
/*
    Supercool arithmetic logic;

    When ever a new element is added to the stack and that new element is less than preexisting
    min element.....
    then add this new element in its modified form in the stack...
    As Modified = 2*new-minimum - prev-minimum
    and change minimum-of-stc to new-minimum

    You see that this element in the stack will be always lesser than the new-element/minimum-of-stc

    When you want to pop this you
    can retrive the previous-minimum from this topmost element and the current existing minimum-of-stc
*/

class MyStack{
public:
    int min_element;
    stack<int> cheat;
    void mypush(int i);
    void mypop();
    void mygetmin();
    int mytop();
};

void MyStack :: mygetmin(){
    if(cheat.empty()){
        cout << "Abey Saale ...\n";
        return;
    }
    cout << min_element << " ... Yes i am the minimum element\n";

}
int MyStack :: mytop(){
    if(cheat.empty()){
        cout << "Abey Saale ...\n";
        return INT_MAX;
    }
    if(cheat.top()<min_element){
        return min_element;
    }
    else return cheat.top();
}

void MyStack :: mypush(int data){
    if(cheat.empty()){
        min_element = data;
        cheat.push(data);
        return;
    }
    if(data<min_element){
        int prev_min = min_element;
        int new_min = data;
        int modifiedpush = 2*new_min - prev_min;
        min_element = new_min; 
        cheat.push(modifiedpush);
    }
    else{
        cheat.push(data);
    }

}

void MyStack :: mypop(){
    if(cheat.empty()){
        cout << "Abey Saale ... \n";
        return;
    }
    int topele = cheat.top();
    if(topele < min_element){
        min_element = 2*min_element - topele;
    }
    cheat.pop();
}

int main(){
    MyStack s; 
    s.mypush(3); 
    s.mypush(5); 
    s.mygetmin(); 
    s.mypush(2); 
    s.mypush(1); 
    s.mygetmin(); 
    s.mypop(); 
    s.mygetmin(); 
    s.mypop(); 
    cout << s.mytop();
}
