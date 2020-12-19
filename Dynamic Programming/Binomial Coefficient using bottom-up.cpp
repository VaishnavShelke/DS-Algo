#include <iostream>
#include <vector>
using namespace std;

// BINOMIAL COEFFICIENT
// Bottom-Up approach to find the binomial coefficient of the given numbers


int main(){
    int c=11,k=10;
    int bottomup[c+1];
    bottomup[0] = 1;
    for(int i = 1;i <= c;i++){
        bottomup[i] = bottomup[i-1]*i;
    }
    int result;
    result = bottomup[c]/(bottomup[k]*bottomup[c-k]);
    cout << "The value of cCk is " << result;
    return 0;
}
