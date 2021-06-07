#include<iostream>
#include<bits\stdc++.h>
using namespace std;

#define R 3
#define C 3

// Recursively print all sentences that can be formed from list of word lists 

void printAll(string arr[R][C],int row,vector<string> vect){

    if(row >= R) {
        for(int i = 0; i<vect.size(); i++){
            cout << vect[i] << " ";
        }
        cout << endl;
        return;
    }

    for(auto stra : arr[row]){
        if(stra.empty()) break;
        vect.push_back(stra);
        printAll(arr,row+1,vect);
        vect.pop_back();
    }

    return;
}




int main()
{
    string arr[R][C]  = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};
 
    vector<string> vect;
    printAll(arr,0,vect);
 
   return 0;
}
