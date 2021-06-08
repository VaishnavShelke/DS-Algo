#include <iostream>
#include <bits\stdc++.h>
#define N 9
using namespace std;


// Find First Repeated String 
string findFirstRepeated(string str){

    string key;
    unordered_map<string,int> dictionary;
    for(int i = 0; i<str.size(); i++){

        key = "";
        while(i < str.size() && str[i]!= ' '){
            key = key + str[i];
            i++;
        }
        if(dictionary.find(key) != dictionary.end())
            dictionary[key] += 1;
        else    
            dictionary.insert(make_pair(key,1));
    }

    
    for(int i = 0; i<str.size(); i++){

        key.erase();
        while(str[i]!= ' '){
            key = key + str[i];
            i++;
        }
        if(dictionary[key] > 1) return key;
    }

    
    return "NoRepetition";
}
int main()
{
    string s="he had had he";
    string firstWord = findFirstRepeated(s);
    if (firstWord != "NoRepetition")
        cout << "First repeated word :: "
             << firstWord << endl;
    else
        cout << "No Repetitionn";
    return 0;
}

