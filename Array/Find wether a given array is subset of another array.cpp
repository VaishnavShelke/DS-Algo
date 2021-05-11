#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Find wether the given array is subset of another array
// HOW NOT TO SOLVE THIS PROBLEM
// Binary search cannot account for the number of times of occurence a number in an array

void ispartof(int i,int* parentset, int* subset,int sub,bool* ispart){
    int high =  sub-1;
    int low = 0;
    int mid;
    while(high >= low){
        mid = (high + low)/2;
        if(*(parentset+i) == *(subset + mid)){
            *(ispart + mid) = true;
            cout << mid << " ---- ";
            break;
        }
        else if(*(parentset+i) > *(subset + mid)){
            low = mid + 1; 
        }
        else{
            high = mid - 1;
        }
    }
}
int main(){
    int parentset[] = { 1,2,3,4,5,6,7,8,9};
    int subset[] = {3,8,9,3};
    int par = sizeof(parentset)/sizeof(parentset[0]); int sub = sizeof(subset)/sizeof(subset[0]);
    bool ispart[par];

    //    N*logN + n*logN = logN*(N + n);
    //      n*logn + N*logn = logn*(N + n); choose which time complexity is smaller and sort sccordingly

    // Correction the above method has its limitaitons and the binary sort method is invalid as it does not account for the 
    // repetation inthe occurence of digits


    for(int i = 0; i<sub; i++){
        ispart[i] = false;
    }
    sort(subset,subset + sub);

    for(int i = 0; i < par ; i++){
        ispartof(i,&parentset[0],&subset[0],sub,&ispart[0]);
        
    }

    for(int i = 0 ; i<sub ; i++){
        if(ispart[i] == false){
            cout << "NOT A SUBSET";
            return 0;
        }
    }

    cout << "IS A SUBSET";
    return 0;
}

