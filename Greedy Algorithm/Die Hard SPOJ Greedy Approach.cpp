//C++ code for reversing a queue
#include <bits/stdc++.h>
using namespace std;

// Die Hard SPOJ Greedy Approach

int bearGrills(int H,int A){

    int index = 0;
    int count = 0;
    while(1){
        if(index%2 == 0){
            H += 3;
            A += 2; count++;
        }
        else{
            if(A<=10 && H>20){
                H -= 20;
                A += 5; count++;
            }
            else if(H>5 && A>10){
                H -= 5;
                A -= 10; count++;
            }
            else{
                break;
            }
        }
        index++;
    }
    return count;
}

int main(){

    int testcases;
    int initialH,initialA;
    cin>>testcases;

    for(int i = 0; i<testcases ; i++){
        cin>>initialH>>initialA;
        cout << bearGrills(initialH,initialA);
    }
    return 0;
}
