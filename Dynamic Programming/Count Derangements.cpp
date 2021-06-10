#include <iostream>
#include <bits\stdc++.h>
using namespace std;


//      Count Derangements
/**
 * * Now assume we have N numbers, out of which i decide to position 0 at any of other i positions
 * * Now there stands two options for me
 * ?    Either i swaps position with 0
 * ?    Or i doesnt occupies position of 0
 **/

int countdr(int n){

    if(n == 1) return 0;
    if(n == 2) return 1;

    return (n-1)*(countdr(n-2) + countdr(n-1));
}

int main(){
    int numbers = 4;

    cout << "The possible number of derangements are ... " << countdr(numbers);
    return 0;
}
