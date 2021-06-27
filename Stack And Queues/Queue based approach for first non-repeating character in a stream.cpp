#include <iostream>
#include <string>
#include <queue>
#define TOT_CHAR 256
using namespace std;

// Queue based approach for first non-repeating character in a stream

void firstnonrepeating(string str){

    int repeated[TOT_CHAR];
    queue<char> qu;
    for(int i = 0; i<TOT_CHAR ; i++) repeated[i] = 0;

    for(int i = 0; i<str.size() ; i++){

        repeated[str[i]]++;
        if(repeated[str[i]] == 1){
            qu.push(str[i]);
        }
        while(!qu.empty() && repeated[qu.front()]>1){
            qu.pop();
        }
        
        if(qu.empty()){
            cout << "-1" << " ";
        }
        else{
            cout << qu.front() << " ";
        }
    }
}


int main()
{
    char str[] = "aacsdcjsdbcjsdbchjbbc";
    firstnonrepeating(str);
    return 0;
}
// a -1 c c c c c c c s s s s k k k k k k k k k k b b b b b b b b b -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
