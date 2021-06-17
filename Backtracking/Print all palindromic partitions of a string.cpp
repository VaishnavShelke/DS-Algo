#include <bits/stdc++.h>
using namespace std;

// Print all palindromic partitions of a string

vector<int>* palindromicLen(string str){

    vector<int>* lengths = new vector<int>[str.size()];
    lengths[str.size()-1].push_back(1);
    int plrdLen;

    for(int i = str.size()-2 ; i>=0 ; i--){

        for(int j = 0; j<lengths[i+1].size() ; j++){
            plrdLen = lengths[i+1][j];
            if(i+1+plrdLen < str.size() && str[i+1+plrdLen] == str[i]){
                lengths[i].push_back(plrdLen+2);
            }
        }
        if(str[i] == str[i+1]){ lengths[i].push_back(2);}
        lengths[i].push_back(1);
    }
    return lengths;
}

void makePalindromes(string str,int base,vector<int>* length,vector<vector<string>>* partitions,vector<string> path){

    if(base == str.size()){
        partitions->push_back(path);
        return;
    }

    for(int i = 0; i<length[base].size() ; i++){
        path.push_back(str.substr(base,length[base][i]));
        makePalindromes(str,base + length[base][i],length,partitions,path);
        path.pop_back();
    }

    return;
}
void partition(string str,vector<vector<string>> partitions){

    vector<int>* lengths = palindromicLen(str);
    vector<string> path;
    makePalindromes(str,0,lengths,&partitions,path);

    for(int j = 0; j<partitions.size() ; j++){
        for(int i = 0 ; i<partitions[j].size(); i++){
            cout << partitions[j][i] << " ";
        }
        cout << endl;
    }
}


// Driver code
int main()
{
    string s = "ababbbabbababa";
    vector<vector<string> > partitions;
    partition(s, partitions);
    return 0;
}
