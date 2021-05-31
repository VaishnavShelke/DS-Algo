#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// Largest Area Rectangle Under Histogram
class rectangle{
public:
    int home,dist,ht;
    rectangle(){}
    rectangle(int ht,int home, int dist){this->ht = ht; this->home = home; this->dist = dist;}
    int Area(){return(ht*(dist-home));}
};

int main(){
    int buildings[7] = { 2, 3, 4, 5, 6, 7, 8};
    rectangle rect[7];
    for(int i = 0; i<7 ; i++){
        rect[i] = {buildings[i],i,i+1};
    }

    int maxima = INT_MIN;
    rectangle dummy;
    stack<rectangle> stc;
    
    for(int i = 0; i<7 ; i++){
       
        if(stc.empty() || stc.top().ht<buildings[i] ){
            stc.push(rect[i]);
        }
        else{
            while(!stc.empty()&& stc.top().ht > buildings[i]){
                dummy = stc.top();
                stc.pop();
                dummy.dist = i;
                maxima = max(maxima,dummy.Area());
                rect[i].home = dummy.home;
            }
            stc.push(rect[i]);
        }
    }
    

    int dis;
    if(!stc.empty())  dis = stc.top().dist;
    while(!stc.empty()){
        dummy = stc.top();
        stc.pop();
        dummy.dist = dis;
        maxima = max(maxima,dummy.Area());
    } 
    cout<< maxima;
    return 0;

}


