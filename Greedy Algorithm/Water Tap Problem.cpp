#include <iostream>
#include <bits\stdc++.h>
#define N 9
using namespace std;

int main()
{
 
  
    int arr[][3] = { { 7, 4, 98 },
                    { 5, 9, 72 },
                    { 4, 6, 10 },
                    { 2, 8, 22 },
                    { 9, 7, 17 },
                    { 3, 1, 66 } };

    int connections = sizeof(arr)/sizeof(arr[0]);
    unordered_map<int,pair<int,int>> fatherTochild;

    set<int> kisiKeBeteNahi;
    for(int i = 0; i<connections ; i++){
        fatherTochild[arr[i][0]] = {arr[i][1],arr[i][2]};        
        if( kisiKeBeteNahi.find(arr[i][0]) == kisiKeBeteNahi.end()){
                kisiKeBeteNahi.insert(arr[i][0]);
            }
    }

    
    for(auto a = fatherTochild.begin(); a != fatherTochild.end(); a++){
        if( kisiKeBeteNahi.find(a->second.first) != kisiKeBeteNahi.end()){
            kisiKeBeteNahi.erase(a->second.first);
        }
    }

    int father;int minima;
    for(auto a = kisiKeBeteNahi.begin(); a != kisiKeBeteNahi.end(); a++){
        father = *a; minima = INT_MAX;
        cout << father << " -->> ";
        while(fatherTochild[father].second != 0){
            //cout << father << " -->> ";
            minima = min(minima,fatherTochild[father].second);
            father = fatherTochild[father].first;
        }
        cout << father ;
        cout << " == " << minima << endl;
    }

    return 0;
}
