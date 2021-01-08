#include<bits/stdc++.h>
using namespace std;

// Count and nth say
/*
    String operations....
                A lot of string operations.....
*/

string count_and_say(string str){
    int count;
    int j,i = 0;
    int strsize = str.size();
    string temp;
    while(i<strsize){
            count = 1;
            j = i;          //1211
            while(j+1 < strsize && str[j] == str[j+1]){
                count++;
                j++;
            }

            if(j+1<strsize){temp = str.substr(j+1);}
            else temp = "";

            str = str.substr(0,i) + to_string(count) + str[i] + temp;
            
            strsize = str.size();
            i = to_string(count).size() + i + 1;
            
    }
    return str;
}

int main(){
    int nthsay = 8;
    string str = "1";
    
    for(int i = 0;i<nthsay;i++){
        str = count_and_say(str);
        cout << str << "\n";
    }
    return 0;
}
