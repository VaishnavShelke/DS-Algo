#include <bits/stdc++.h>
using namespace std;
#define ARRAYSIZE(a) (sizeof(a)/sizeof(a[0]))

// Subset Sum Problem

void generateSubsets(int* weight,int base,int size,int sum,vector<int> path){

    if(base>= size){
        return;
    }
    if(sum < 0) return;
    if(sum == 0){
        for(int i =  0; i<path.size(); i++){
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }

    path.push_back(weight[base]);
    generateSubsets(weight,base+1,size,sum-weight[base],path);
    path.pop_back();

    generateSubsets(weight,base+1,size,sum,path);
    return;
}


int main()
{
    int weights[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int size = ARRAYSIZE(weights);
    vector<int> path;
    sort(weights,weights + size);

    generateSubsets(weights,0, size, 53,path);
     
    return 0;
}
