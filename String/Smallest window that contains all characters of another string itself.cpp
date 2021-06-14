#include <bits/stdc++.h>
using namespace std;

// Smallest window that contains all characters of string itself


bool vacancyPresent(unordered_map<char,int> bag,unordered_map<char,int> requiredChar){

    for(auto a = requiredChar.begin(); a != requiredChar.end(); a++){
        if(bag.find(a->first) == bag.end()){
            return true;
        }
        if(bag[a->first] < a->second){
            return true;
        }
    }
    return false;
}

bool isUseless(char chara,unordered_map<char,int>& bag,unordered_map<char,int> requiredChar){

    if(requiredChar.find(chara) == requiredChar.end()){
        return true;
    }
    if(bag.find(chara) == bag.end()) return true;
    if(bag[chara] > requiredChar[chara]){
        bag[chara]--;
        return true;
    }
    return false;
}

string findSubString(string str,string pat){

    int index, maxLen = INT_MAX;

    unordered_map<char,int> requiredChar;

    for(int i = 0; i<pat.size() ; i++){
        if(requiredChar.find(pat[i]) == requiredChar.end()){
            requiredChar[pat[i]] = 1;
        }
        else{
            requiredChar[pat[i]] += 1;
        }
    }

    unordered_map<char,int> bag;
    int length = 0;
    int i = 0;
    for( i = 0; i<str.size() ; i++){

        if(vacancyPresent(bag,requiredChar)){
            if(requiredChar.find(str[i]) != requiredChar.end()){
                if(bag.find(str[i]) == bag.end()){
                    bag[str[i]] = 1;
                }
                else{
                    bag[str[i]] += 1;
                }
            }
            length++;
        }
        else { maxLen = length; break;}
    }
    
    for( i ; i<str.size() ; i++){

        while(isUseless((char)str[i-length+1],bag,requiredChar)){
            length--;
        }
        if(length<maxLen){
            maxLen = length;
            index = i-1;
        }

        if(requiredChar.find(str[i]) != requiredChar.end()){
                bag[str[i]]++;
        }
        length++;
        

    }
    
    return str.substr(index-maxLen+1,maxLen);

}


int main()
{
    string str = "timetopractice";
    string pat = "toc";
 
    cout << "Smallest window is : \n"
         << findSubString(str, pat);
    return 0;
}
