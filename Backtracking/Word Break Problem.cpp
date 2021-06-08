#include <iostream>
#include <bits\stdc++.h>

using namespace std;


// Word Break Problem using back tracking


vector<string> findWords(string str,int base){
    vector<string> dict = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};;

    vector<string> words;
    for(int j = 0; j<dict.size() ; j++){
        for(int i = 0; i<dict[j].size() ; i++){
            if(base+i < str.size() && str[base+i] == dict[j][i]){
                if(i == dict[j].size()-1) words.push_back(dict[j]);
            }
            else break; 
        }
    }
    return words;
}

bool myWordBreak(string str,int base){

    if(base == str.size()) return true;
    
    vector<string> words = findWords(str,base);
    
    for(int i = 0; i<words.size() ; i++){
        if(myWordBreak(str,base+words[i].size())){
            return true;
        }
    }
    return false;
}
bool wordBreak(string str){
    return myWordBreak(str,0);
}
int main()
{
    wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    return 0;

}
