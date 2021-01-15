#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Print all subsequences of a string
// BACKTRACKING APPROACH


void printthemall(string s1,string prt,int i);
int main(){
    string sequence = "ABCD";
    string prt = "";
    printthemall(sequence,prt,0);
}

void printthemall(string s1,string prt,int i){
    if(i == s1.size()){
        cout << prt <<"\n";
        return;
    }
    int arr[] ={0,1};
    for(int j = 0;j<2;j++){
        if(j==1){
            prt += s1[i];
        }
        //cout << prt << " == " << j << "\n";
        printthemall(s1,prt,i+1);
    }
    return;
}
