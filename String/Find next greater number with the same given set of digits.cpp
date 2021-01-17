#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Find the next greater number with the same set of digits

int main(){
    string number = "534976";

    // reverse ramp upto
    int temp;
    for(int i = number.size()-1; i> 0; i--){
        if(number[i] > number[i-1]) {temp = i-1;break;}
    }
    swap(number[temp],number[number.size()-1]);
    sort(number.begin()+temp+1,number.end());

    cout << number;
}
