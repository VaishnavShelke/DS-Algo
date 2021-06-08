#include <iostream>
#include <bits\stdc++.h>
#define N 9
using namespace std;

// Generate all possible IP adress

int convertToNum(string str){
    int factor = 10; int number = 0;
    for(int i = 0; i<str.size() ; i++){
        number = number*factor + (int)(str[i]-'0');
    }
    return number;
}

bool isValid(string str){
    int num = convertToNum(str);
    
    if(str[0] == '0') return false;
    else if(num>255) {return false;}
    else return true;
}

vector<string> validBlocks(string str,int base){

    int arr[] = {1,2,3};
    int length;
    vector<string> blocks;
    for(int i = 0; i<3 ; i++){
        length = arr[i];
        
        if(base+length>str.size()) break;
        else{
            if(isValid(str.substr(base,length))){
                
                blocks.push_back(str.substr(base,length));
            }
        }
    }
     
    return blocks;
}

void generateIP(string str,int base,int incl,vector<string>& ips){

    if(incl > 4) return;
    if(base>=str.size()){
        if(base == str.size() && incl == 4) {
            for(int i = 0 ; i<ips.size()-1 ; i++) cout<<ips[i] <<".";
            cout<<ips[ips.size()-1];
            cout<<endl;
        }
        return;
    }
    vector<string> blocks = validBlocks(str,base);

    for(auto block: blocks){
        ips.push_back(block);
        generateIP(str,base+block.size(),incl+1,ips);
        ips.pop_back();
    }
    return;
}



int main(){
    string str = "25525";
    vector<string> ips;

    generateIP(str,0,0,ips);
}
