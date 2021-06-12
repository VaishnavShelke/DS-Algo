#include <bits/stdc++.h>
using namespace std;

// Connect n ropes with minimum cost

class comparer{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};


int minCost(int* ropes,int size){

    priority_queue<int,vector<int>,comparer> minHP;

    for(int i = 0; i<size; i++){
        minHP.push(ropes[i]);
    }

    int cost = 0;
    int firstRope,secondRope,Combined;

    while(minHP.size() != 1){

        firstRope = minHP.top();
        minHP.pop();
        secondRope = minHP.top();
        minHP.pop();
        cost += firstRope + secondRope;
        Combined = firstRope + secondRope;
        minHP.push(Combined);
    }
    return cost;
}


int main()
{
    int len[] = { 4, 3, 23,4,5,6,3,4,2,45,6 };
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is "
         << minCost(len, size);
    return 0;
}
