#include <bits/stdc++.h>
using namespace std;
 
// Structure for a Pair
class Pair
{
    public:
    int a;
    int b;
};
 
bool comparer(Pair p1,Pair p2){
    return p1.b<p2.b;
}

int maxChainLength(Pair* arr,int n){

    sort(arr,arr+n,comparer);
    int count = 0;
    int endTime = arr[0].b; count++;
    for(int i = 1; i<n ; i++){
        if(arr[i].a>endTime){
            count++;
            endTime = arr[i].b;
        }
    }   
    return count;
} 
 
/* Driver code */
int main()
{
    Pair arr[] = { {5, 24}, {15, 25},
                        {27, 40}, {50, 60} };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Length of maximum size chain is "
                  << maxChainLength( arr, n );
    return 0;
}
