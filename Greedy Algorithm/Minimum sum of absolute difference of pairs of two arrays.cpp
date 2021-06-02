#include<iostream>
#include<bits\stdc++.h>

using namespace std;
// Minimum sum of absolute difference of pairs of two arrays

int main()
{
    // Both a[] and b[] must be of same size.
    int a[] = {4, 1, 8, 7};
    int b[] = {2, 3, 6, 5};
    int n = sizeof(a)/sizeof(a[0]);

    sort(a,a + n);
    sort(b,b + n);
    int sum = 0;

    for(int i = 0; i<n ; i++){
        sum += std::abs(a[i]-b[i]);
    }
    printf("Minimum sum of absolute difference of pairs of two arrays %d\n",sum);
    return 0;
}
