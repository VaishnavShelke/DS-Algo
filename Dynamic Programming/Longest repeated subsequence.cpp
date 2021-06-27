#include <iostream>
#include <string>
using namespace std;

// Longest repeating subsequence
//  Any i’th character in the two subsequences shouldn’t have the same index in the original string.
// SO THE TWO SEQUENCES CAN SHARE A LETTER BUT ith letter in both subsequences shouldn't come from same place;
// But what is we want both the string characters to be completely different ??? Food For Thought

int findLongestRepeatingSubSeq(string str){

    int longComSeq[str.size()+1][str.size()+1];

    for(int j = 0; j<=str.size() ; j++){
        for(int i = 0; i<=str.size() ; i++){
            if(i == 0 || j == 0) longComSeq[j][i] = 0;
            else if( i != j && str[i-1] == str[j-1]) longComSeq[j][i] = longComSeq[j-1][i-1] + 1;
            else{
                longComSeq[j][i] = max(longComSeq[j-1][i],longComSeq[j][i-1]);
            }
        }
    }

    return longComSeq[str.size()][str.size()];
}

int main()
{
    string str = "aaaa";
    cout << "The length of the largest subsequence that"
            " repeats itself is : "
        << findLongestRepeatingSubSeq(str);
    return 0;
}
