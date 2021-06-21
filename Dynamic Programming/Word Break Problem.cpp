#include <iostream>
#include<unordered_set>
using namespace std;
 
// Word Break Problem using Memoisation

bool isPresent(string str){

    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};

    for(string s: dictionary){
        if(s == str) return true;
    }

    return false;
}

bool recursiveWordBreak(string str,int base,int* memo,unordered_set<int> wordLengths){

    if(base == str.size()){
        memo[base] = 1;
        return true;
    }
    if(memo[base] != -1){
        return memo[base];
    }


    for(auto lens =  wordLengths.begin(); lens != wordLengths.end(); lens++){
        if(base + *lens > str.size()) continue;
        if(isPresent(str.substr(base,*lens))){
            if(recursiveWordBreak(str,base+*lens,memo,wordLengths)){
                return true;
            }
        }
    }
    memo[base] = 0;
    return false;

}

bool wordBreak(string str){


    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
                            
    unordered_set<int> wordLengths;
    for(string s: dictionary){
        if(wordLengths.find(s.size()) == wordLengths.end()){
            wordLengths.insert(s.size());
        }
    }

    int memo[str.size()+1];
    for(int i = 0; i<= str.size() ; i++) memo[i] = -1;

    bool bhool = recursiveWordBreak(str,0,memo,wordLengths);
    return bhool;
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
