#include <bits/stdc++.h>
using namespace std;

// Number of flips to make binary string alternate

int minFlipToMakeStringAlternate(string str){

    int flipCount = 0;
    // Assume begin with one
    for(int i = 0; i<str.size(); i++){
        if(i % 2 == 0 && str[i] != '1'){
            flipCount++;
        }
        if(i % 2 == 1 && str[i] != '0'){
            flipCount++;
        }
    }
    int saveR = flipCount;
    flipCount = 0;

    // Assume begin with zero
    for(int i = 0; i<str.size(); i++){
        if(i % 2 == 1 && str[i] != '1'){
            flipCount++;
        }
        if(i % 2 == 0 && str[i] != '0'){
            flipCount++;
        }
    }

    return min(flipCount,saveR);
}

//  Driver code to test above method
int main()
{
    string str = "000101010101011010111010111011011101010111";
    cout << minFlipToMakeStringAlternate(str);
    return 0;
}
