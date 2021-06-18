#include<bits/stdc++.h>
using namespace std;
 
// Find maximum possible number by doing at most k swaps

void swap(char* c1,char* c2){
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;   
}

void myfindMaximumNum(string& str,int base,int k){

    if(base>=str.size()-1) return;
    if(k == 0) return;
    int maxiMa = str[base];
    for(int i = base; i<str.size(); i++){
        if(str[i] >= maxiMa){
            maxiMa = str[i];
        }
    }

    if(str[base] != maxiMa){
        string archive = str;
        string maximum = str;
        
        for(int i = base + 1; i<str.size() ; i++){
            str = archive;
            if(str[i] == maxiMa){
                swap(&str[i],&str[base]);
                myfindMaximumNum(str,base+1,k-1);
            }
            if(str>maximum){
                maximum = str;
            }
        }
        str = maximum;
    }
    else{
        myfindMaximumNum(str,base+1,k);
    }
}


void findMaximumNum(string str,int k,string& max){
    myfindMaximumNum(max,0,k);
}

int main()
{
    string str = "129814999";
 
    int k = 4;
 
    string max = str;
    findMaximumNum(str, k, max);
 
    cout << max << endl;
 
    return 0;
}
