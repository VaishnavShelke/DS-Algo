#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Split the binary string into substrings having equal number of 1s and 0s
// Answer is the maximum number of such MUTUALLY EXCLUSIVE substrings
/*
    string = “0100110101”;
    there are 01,0011,01,01 
*/
int main(){
    int counts = 0,neutrality = 0;
    string str = "0100110101";
    for(int i = 0 ;i<str.size() ;i++){
        if(str[i] == '0') neutrality++;
        else neutrality--;
        if (neutrality == 0){
            counts++;
        }
    }
    cout << "The maximum number of such strings is ..... " << counts;
    return 0;
}
