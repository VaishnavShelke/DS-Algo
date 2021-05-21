#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Word Ladder Using BFS
int compareStr(string str1, string str2, int leavpos){
    for(int i = 0; i< str1.length(); i++){
        if(i != leavpos && str1[i] != str2[i]){
            return false;
        }
    }
    return true;
}
int shortestChainLen(string start,string target, set<string> D){
    queue<string> qu;
    qu.push(start);
    map<string,int> level;
    string parent;
    int count = 0;
    cout << start << " --->> ";
    set<string>:: iterator it;
    level[start] = 0;
    while(!qu.empty()){
        parent = qu.front();
        qu.pop();
        count ++;
        if(parent == target) break;

        for(it = D.begin(); it != D.end(); it++){
            for(int i = 0; i < start.size(); i++){
                if(compareStr(parent,*it,i)){
                    qu.push(*it);
                    level[*it] = 1 + level[parent];
                }
            }
        }
    
    }
    return level[target];
}

int main(){
    // make dictionary
    set<string> D;
    D.insert("poon");
    D.insert("plee");
    D.insert("same");
    D.insert("poie");
    D.insert("plie");
    D.insert("poin");
    D.insert("plea");
    string start = "toon";
    string target = "plea";
    cout << "Length of shortest chain is: "
         << shortestChainLen(start, target, D);
    return 0;
}
