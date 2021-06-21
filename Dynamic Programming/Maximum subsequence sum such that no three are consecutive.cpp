#include<bits/stdc++.h>
using namespace std;

// Maximum subsequence sum such that no three are consecutive

int maxSumWO3Consec(int* arr,int n)
{
    
    int K[n+1][3];

    for(int j = 0; j<= n ; j++){
        for(int i = 0; i<3; i++){

            if(j == 0) { K[j][i] = 0; continue;}
            if(i == 2 && j == 1) { K[j][i] = 0; continue;}

            if(i == 0) {
                K[j][i] = max(K[j-1][2],K[j-1][1]);
                K[j][i] = max(K[j][i],K[j-1][0]);
            }
            else if( i == 1){
                K[j][i] = arr[j-1] + K[j-1][0];
            }
            else{
                K[j][i] = arr[j-1] + K[j-1][1];
            }
        }
    }
     
    int answer = max(K[n][0],K[n][1]);
    return max(answer,K[n][2]);
     
}
 
// Driver code
int main()
{
    int arr[] = {1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << maxSumWO3Consec(arr,n);
 
// this code is contributed by Kushdeep Mittal, But now By Vaishnav Shelke
    return 0;
}
