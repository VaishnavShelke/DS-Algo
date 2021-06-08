#include <iostream>
#include <bits\stdc++.h>
#define N 9
using namespace std;

// Print All Anagramss

bool comparer(const char& itr1,const char& itr2){
    return (int)(itr1)<(int)(itr2);
}

void solver(vector<string> Solver){
    vector<string> solver = Solver;
    for(int i = 0; i<solver.size(); i++){
        sort(solver[i].begin(),solver[i].end(),comparer);
    }
    unordered_map<string,vector<int>> anagram;

    for(int i = 0; i<solver.size() ; i++){
        if(anagram.find(solver[i]) == anagram.end()){
            anagram[solver[i]].push_back(i);
        }
        else anagram[solver[i]].push_back(i);
    }

    unordered_map<string,vector<int>> :: iterator ptr;

    for(ptr = anagram.begin(); ptr != anagram.end(); ptr++){
        for(int i = 0; i<ptr->second.size(); i++){
            cout << Solver[ptr->second[i]] << " ";
        }
        cout << "\n";
    }
    return;
}
int main()
{
    vector<string> my_list = { "cat", "dog", "ogd",
                               "god", "atc" };
    solver(my_list);
    return 0;
}
