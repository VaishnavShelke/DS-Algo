#include <iostream>
#include <bits\stdc++.h>
#define N 9
using namespace std;

// Smallest window containing all distinct characters

string findSubString(string str){
    unordered_set<char> all;
    for(int i =0; i<str.size() ; i++){
        if(all.find(str[i]) == all.end()){
            all.insert(str[i]);
        }
    }

    int distinctChar = all.size();
    all.clear();
    unordered_map<char,int> count;


    int minCount  = INT_MAX; int length = 0;int index;
    for(int i = 0; i<str.size(); i++){

        length++;
        if(count.find(str[i]) == count.end()){
            count[str[i]] = 1;
            all.insert(str[i]);
        }
        else{
            count[str[i]] += 1;
        }

        if(all.size() == distinctChar){
            while(count[str[i+1-length]] > 1){
                count[str[i+1-length]]--;
                length--;
            }

            if(length<minCount){
                
                index = i; minCount  =  length;
            }
        }
        
    }
    return str.substr(index-minCount+1,index+1);
}
int main()
{
    string str = "cksncsnknscknscnskcnskncskncaakcnskncbcbcdcjscjnscmsbcncsnkca";
    cout << "Smallest window containing all distinct"
            " characters is: "
         << findSubString(str);
    return 0;
}
