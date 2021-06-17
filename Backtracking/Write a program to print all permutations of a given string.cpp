#include <bits/stdc++.h>
using namespace std;

// Write a program to print all permutations of a given string

void swap(char* c1,char* c2){
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

void permute(string str,int base){

    if(base == str.size()-1){
        cout << str << endl;
        return;
    }
    for(int i = base; i<str.size(); i++){
        swap(&str[base],&str[i]);
        permute(str,base+1);
        swap(&str[base],&str[i]);
    }
    return;
}
// Driver Code
int main()
{
    string str = "ABCD";
    permute(str,0);
    return 0;
}
