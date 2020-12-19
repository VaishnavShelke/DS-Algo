#include <iostream>
#include <vector>
using namespace std;

// PERMUTATION COEFFICIENT

int main(){
    int c=11,k=10;
    int bottomup[c+1];
    bottomup[0] = 1;
    for(int i = 1;i <= c;i++){
        bottomup[i] = bottomup[i-1]*i;
    }
    int result;
    result = bottomup[c]/(bottomup[c-k]);
    cout << "The value of cPk is " << result;
    return 0;
}
