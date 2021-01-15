#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int counts = 0; 
// Print all permutations of a given string 
// BACKTRACKING APPROACH

void printallperm(string prt,int baseindex);
int main(){
    string input = "ABCD";
    string prt = input;
    printallperm(prt,0);
}

void printallperm(string prt,int baseindex){
    if(baseindex == prt.size()){
        counts++;
        cout << "Sr.No. " << counts << "  " << prt << "\n";
        return;
    }
    for(int i = baseindex;i<prt.size();i++){
        swap(prt[baseindex],prt[i]);
        printallperm(prt,baseindex+1);
        swap(prt[baseindex],prt[i]);
    }
    return;
}
