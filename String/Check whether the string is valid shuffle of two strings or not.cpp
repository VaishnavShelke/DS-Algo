#include<bits/stdc++.h>
using namespace std;

// Interleaving of two given strings
/*
    Given string 1 :VAISHNAV  
    Given string 2 :SHREYA
    Check string   : SHVAIREYSHNAVA
                            string 1 and string 2 are interleaved to make the given string
                            check if the order is the same
*/

bool check_if_interleaved(string s1,string s2,string inter){
    int a = 0;int b = 0;
    for(int i = 0;i<inter.size();i++){
        if(a < s1.size() && inter[i] == s1[a]) {a++;}

        else if(b < s2.size() && inter[i] == s2[b]) {b++;}

        else {return false;}
    }
    return true;
}


int main(){
    string str1,str2;
    str1 = "YX";
    str2 = "X";
    string mesh = "XXY";

    if(check_if_interleaved(str1,str2,mesh)){
        cout << "Perfectly Interleaved string.....";
    }
    else{
        cout << "Not Perfectly Interleaved.....";
    }
    return 0;
}
