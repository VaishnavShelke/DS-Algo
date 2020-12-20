#include <iostream>
#include <vector>
using namespace std;

// FINDING TOTAL POSSIBLE BINARY SEARCH TREES POSSIBLE WITH N KEYS;

/* This approach invloves more mathematical way of calculating the nth catalan number
    ````` Imagine this... */

int main(){
    int n_catalan = 6;
    int ith_cat[n_catalan+1];
    ith_cat[0] = 1;
    int summation = 0;
    for(int n = 1;n <= n_catalan; n++){
        for(int i = 1; i <= n;i++) summation += ith_cat[i-1]*ith_cat[n-i];
        ith_cat[n] = summation;
        summation = 0;
    }
    cout << ith_cat[2] << " ";
    cout << "\n";
    cout << "The number is " << n_catalan << "\n";
    cout << "The ith catalan number is " << ith_cat[n_catalan];
    return 0;
}
