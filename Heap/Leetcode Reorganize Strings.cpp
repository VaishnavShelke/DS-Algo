#include <bits/stdc++.h>
using namespace std;
 
const int MAX_CHAR = 26;

// Rearrange characters in a string such that no two adjacent are same

class freqCharacter{
public:
    char character;
    int frequency;
};

class maxHp{
public:
    bool operator()(freqCharacter f1,freqCharacter f2){
        return f1.frequency < f2.frequency;
    }
};

void rearrangeString(string str){

    int charCount[26];
    for(int i = 0; i<26 ; i++) charCount[i] = 0;

    for(int i = 0; i<str.size() ; i++) charCount[str[i] - 'a'] += 1;

    priority_queue<freqCharacter,vector<freqCharacter>,maxHp> maxHeap;

    for(int i = 0; i<26 ; i++){
        if(charCount[i]>0){
            maxHeap.push(freqCharacter{(char)(i+'a'),charCount[i]});
        }
    }

    freqCharacter previous{'#',-1};
    freqCharacter curr;
    string answer = "";
    while(!maxHeap.empty()){
        curr = maxHeap.top();
        maxHeap.pop();
        if(curr.frequency > 0 ) answer += curr.character;
        else break;
        curr.frequency--;
        maxHeap.push(previous);
        previous = curr;
    }
    if(answer.size()<str.size()){
        cout << "-1";
        return;
    }
    cout << answer;

}

int main()
{
    string str = "bhhaaaabbaa";
    rearrangeString(str);
    return 0;
}
