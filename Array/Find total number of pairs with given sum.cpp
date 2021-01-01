#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// Count the pairs with the given sum
// Sort the array
/*
        Now run a loop from i == 0 -->> len-1;
        calculate find me -->> sum - arr[i]
            and search for find me in i+1 -->> len-1 inclusive
        If it exists then add 
            upper bound - lower bound for find me in i+1 -->> len
        if the element does not exists let it pass...
*/
// Note: The map solution was also possible but we did not do it because luv babbar told not to.

int main(){
    int arr[] = { 1, 5, 7, -1, 5 };
    int sum = 6;
    int len = sizeof(arr)/sizeof(arr[0]);

    sort(arr,arr+len);
    cout << "Lower Bound ... " << *lower_bound(arr,arr+len,5);
    cout << "\nUpper Bound ... " << *upper_bound(arr,arr+len,5);
    cout << "\n";
    int findme;
    int totalpairs = 0;
    for(int i = 0; i< len-1; i++){
        findme = sum-arr[i];
        if(binary_search(arr+i+1,arr+len,findme))

            totalpairs += upper_bound(arr+i+1,arr+len,findme) - lower_bound(arr+i+1,arr+len,findme);
    }
    cout << "The number of pairs which make up sum == " << sum << " is " << totalpairs;
    return 0;
}
