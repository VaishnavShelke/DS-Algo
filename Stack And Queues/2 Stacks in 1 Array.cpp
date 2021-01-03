#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class twostacks{
public:
    int top1,top2,arrsize;
    int arr[200];
    twostacks(int arrsize){
        top1 = -1;
        top2 = arrsize ;
    }
    void push1(int data);
    void push2(int data);
    void pop1();
    void pop2();
    void ptop1();
    void ptop2();
};

void twostacks :: push1(int data){
    if (top1 > top2){
        cout << "Stack Overflow .....\n";
        return;
    }
    top1++;
    arr[top1] = data;
   
}
void twostacks :: push2(int data){
    if (top1 > top2){
        cout << "Stack Overflow .....\n";
        return;
    }
    top2--;
    arr[top2] = data;
    
}
void twostacks :: pop1(){
    if (top1 == -1){
        cout << "Stack Already empty .....\n";
        return;
    }
    else{
        arr[top1] = 0;
        top1--;
    }
}
void twostacks :: pop2(){
    if (top2 == arrsize){
        cout << "Stack Already empty .....\n";
        return;
    }
    else{
        arr[top2] = 0;
        top2++;
    }
}
void twostacks :: ptop1(){
    if(top1 == -1){
        cout << "Empty Stack ...\n";
    }
    else{
        cout << arr[top1] << "\n";
    }
}
void twostacks :: ptop2(){
    if(top2 == arrsize){
        cout << "Empty Stack ...\n";
    }
    else{
        cout << arr[top2] << "\n";
    }
}

int main(){
    twostacks tostack(5);
    tostack.push1(1);
    tostack.push2(5);
    tostack.push1(2);
    tostack.push1(2);
    tostack.push1(2);
    tostack.push2(4);
    cout << "Current stack condition ..\n";
    for(int i = 0;i < 5;i++){
        cout << tostack.arr[i] << " ";
    }
    cout << "\n";
    tostack.pop2();
    tostack.pop2();
    for(int i = 0;i < 5;i++){
        cout << tostack.arr[i] << " ";
    }
    cout << "\n";
    tostack.pop2();
    return 0;
}
