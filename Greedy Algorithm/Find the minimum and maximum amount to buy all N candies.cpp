#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// Maximum and minimum amount to be spent on buying candies

int main(){
    int candyP[] = {3, 2, 1, 4};
    int freebies = 2;
    int len = sizeof(candyP)/sizeof(candyP[0]);
    sort(candyP,candyP+len);
    int ceiling = len,bottom = 0;

    // Finding minimum spent
    int minimumexp = 0;
    for(int i = 0; i<ceiling; i++){
        minimumexp += candyP[i];
        ceiling -= freebies;
    }
    cout << "Minimum Expenditure in buying candies..." << minimumexp;

    // Finding maximum spent;
    int maxspent = 0;
    for(int i = len-1; i>= bottom;i--){
        maxspent += candyP[i];
        bottom += freebies;
    }

    cout << "\nMaximum Expenditure in buying candies..." << maxspent;
    return 0;

}
