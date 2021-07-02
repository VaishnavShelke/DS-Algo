#include<iostream>
#include<queue>
using namespace std;
#define N 3
 
// Minimize Cash Flow among a given set of friends who have borrowed money from each other

class maxHp{
public:
    bool operator()(int a,int b){
        return a<b;
    }
};

class minHp{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};


void minCashFlow(int graph[N][N]){

    priority_queue<int,vector<int>,maxHp> maxHeap;
    priority_queue<int,vector<int>,minHp> minHeap;

    int balanceSheet[N];
    for(int i = 0; i<N ; i++){
        balanceSheet[i] = 0;
    }

    for(int j = 0; j<N ; j++){
        for(int i = 0; i<N ; i++){
            balanceSheet[i] += graph[j][i];
            balanceSheet[j] -= graph[j][i];
        }
    }
    for(int i = 0; i <N ; i++){
        if(balanceSheet[i]>0){
            maxHeap.push(balanceSheet[i]);
        }
        if(balanceSheet[i]<0){
            minHeap.push(balanceSheet[i]);
        }
    }
    int transactions = 0;
    int borrow; int lend;
    while(!minHeap.empty()){
        borrow = minHeap.top(); minHeap.pop();
        lend = maxHeap.top(); maxHeap.pop();
        if(borrow+lend>0){
            lend = lend + borrow; transactions++;
            maxHeap.push(lend);
        }
        else if(borrow+lend<0){
            borrow = borrow+lend; transactions++;
            minHeap.push(borrow);
        }
        else{
            transactions++;
        }
    }

    cout << transactions;
}

// Driver program to test above function
int main()
{
    int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0},};
 
    // Print the solution
    minCashFlow(graph);
    return 0;
}
