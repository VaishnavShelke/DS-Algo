
#include <bits/stdc++.h>
using namespace std;
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
 
/**
 * *                        LONGEST ALTERNATING SUBSEQUENCE
 **/

int main(){
    int arr[] = { 10, 22, 9, 33,49, 50, 31, 60,57,3,4,5,2,54,4634,436,343,64,63};
    int n = sizeof(arr)/sizeof(arr[0]);

    int lsseaG[n]; lsseaG[0] = 1; int maxG;
    int lsseaS[n]; lsseaS[0] = 1; int maxS;

    for(int j = 1; j < n; j++){
        maxG = 1; maxS = 1;
        for(int i = 0; i<j ; i++){
            if(arr[j]<arr[i]) maxG = max(maxG,lsseaG[i]);
            if(arr[j]>arr[i]) maxS = max(maxS,lsseaS[i]);
        }
        lsseaG[j] = maxS + 1;
        lsseaS[j] = maxG + 1;
    }

    cout << "The length of longest alternating subsequence is ... " << max(lsseaG[n-1],lsseaS[n-1]);
    return 0;
}
