#include <bits/stdc++.h>
using namespace std;
 
// CHOCOLA - Chocolate Breaking the chocolate

class maxHp{
public:
    bool operator()(int a, int b){
        return a<b;
    }
};

int minCutsCost(priority_queue<int,vector<int>,maxHp>& vertiHeap, priority_queue<int,vector<int>,maxHp>& horizontalHeap){
    int v_cuts = 1;
    int h_cuts = 1;
    int cut_cost = 0;
    while(!vertiHeap.empty() && !horizontalHeap.empty()){
        if(vertiHeap.top()>horizontalHeap.top()){
            cut_cost += vertiHeap.top()*h_cuts;
            v_cuts++; vertiHeap.pop();
        }
        else{
            cut_cost += horizontalHeap.top()*v_cuts;
            h_cuts++; horizontalHeap.pop();
        }
       
    }
    while(!vertiHeap.empty()){
        cut_cost += vertiHeap.top()*h_cuts;  vertiHeap.pop();  
    }
    while(!horizontalHeap.empty()){
        cut_cost += horizontalHeap.top()*v_cuts;  horizontalHeap.pop();
    }
    return cut_cost;
}


int main(){
    int vertical_cuts,horizontal_cuts,testcases;
    cin>>testcases;

    while(testcases){
    cin>>vertical_cuts>>horizontal_cuts;


    priority_queue<int,vector<int>,maxHp> vertiHeap,horizontalHeap;

    int x;
    for(int i = 0; i<vertical_cuts-1 ; i++){
        scanf("%d",&x);
        vertiHeap.push(x);
    }

    for(int i = 0; i<horizontal_cuts-1 ; i++){
        scanf("%d",&x);
        horizontalHeap.push(x);
    }
   
    cout << minCutsCost(vertiHeap,horizontalHeap);
    testcases--;
    }
    return 0;
}
