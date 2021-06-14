#include <bits/stdc++.h>
using namespace std;

// Rearrange characters in a string such that no two adjacent are same

bool comparer(unordered_map<char,int> :: iterator p1,unordered_map<char,int> :: iterator p2){
    return p1->second > p2->second;
}

string rearrangeString(string str){

    unordered_map<char,int> counter;

    for(int i = 0; i<str.size(); i++){
        if(counter.find(str[i]) == counter.end()){
            counter[str[i]] = 1;
        }
        else{
            counter[str[i]] += 1;
        }
    }

    vector<unordered_map<char,int> :: iterator> counterVector;

    for(auto a = counter.begin(); a != counter.end(); a++){
        counterVector.push_back(a);
    }

    if(counterVector.size() > 1) sort(counterVector.begin(), counterVector.end(), comparer);

    string answer(str.size(), ' ');

    for(int i = 0; i<counterVector.size(); i++){
        cout << counterVector[i]->first << " --- " << counterVector[i]->second << endl;
    }

    unordered_map<char,int> :: iterator paintBox;
    int i = 0;int j = 0;

    while(i<str.size()){
        
        if(counterVector[j]->second == 0){ j++;}
        paintBox = counterVector[j];
        while(i<str.size() && paintBox->second>0){
                answer[i] = paintBox->first; paintBox->second--; i = i + 2 ;
        }
    }
    i = 1;
    while(i<str.size()){
        
        if(counterVector[j]->second == 0){ j++;}
        paintBox = counterVector[j];
        while(i<str.size() && paintBox->second>0){
                answer[i] = paintBox->first; paintBox->second--; i = i + 2 ;
        }
    }

    for(int i = 1; i<str.size(); i++){
        if(answer[i] == answer[i-1]){
            return "Not Possible";
        }
    }
    return answer;
}

int main()
{
    string str = "aa";
    string res = rearrangeString(str);
    if (res == "")
        cout << "Not valid string" << endl;
    else
        cout << res << endl;
    return 0;
}
