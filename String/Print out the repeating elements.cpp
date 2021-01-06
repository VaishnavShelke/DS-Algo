#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// Print all duplicates in string

int main(){
    int countoccurences[58] ={};
    string str = "Vaishnav Naresh Shelke";
    int charint;
    for(int i = 0;i<str.size(); i++){
        charint = (int)str[i] - 65;
        countoccurences[charint]++;
    }
    char intchar;
    cout << "The repeating elements are ... \n";
    for(int i = 0; i<58 ; i++){
        intchar = (char)(i+65);
        if(countoccurences[i]>1)
            cout << intchar << " ";
    }
    return 0;
}
