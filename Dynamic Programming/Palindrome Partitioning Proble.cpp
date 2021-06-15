#include <bits/stdc++.h>
using namespace std;


void minPalPartitionBTR(string str, int base,int cuts,int* minCuts,vector<int>* arr){
    
    if(cuts >= *minCuts) return;
    
    if(base == str.size()){
        if(cuts < *minCuts){
            *minCuts = cuts;
        }
        return;
    }

    vector<int> palindromes = arr[base];

    for(int i = 0; i<palindromes.size() ; i++){
        minPalPartitionBTR(str,base + palindromes[i],cuts+1,minCuts,arr);
        if(cuts > *minCuts - 1) break;
    }
    return;
}

vector<int>* LSS(string str){

    vector<int>* arr = new vector<int>[str.size()];

    arr[str.size()-1].push_back(1);
    int index;

    for(int j = str.size()-2 ; j>=0 ; j--){
        for(int i = 0; i<arr[j+1].size() ; i++){
            index =  j + 1 + arr[j+1][i];
            if(index < str.size() && str[j] == str[index]){
                arr[j].push_back(index-j + 1);
            }
        }
        if(str[j] == str[j+1]) arr[j].push_back(2);
        arr[j].push_back(1);
    }

    for(int i = 0; i<str.size() ; i++){
        cout << i << " ---> ";
        for(int j = 0; j<arr[i].size() ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return arr;
}


int minPalPartion(string str){
     vector<int>*  arr = LSS(str);
    
    int minCuts = INT_MAX;
    minPalPartitionBTR(str,0,0,&minCuts,arr);
    return minCuts-1;

}

// Driver code
int main()
{
    string str = "aaabba";
    cout << "Min cuts needed for Palindrome"
            " Partitioning is "
         << endl <<  minPalPartion(str);
    return 0;
}
