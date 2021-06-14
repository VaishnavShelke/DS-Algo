#include <bits/stdc++.h>
using namespace std;

// String matching where one string contains wildcard characters

void test(string str1,string str2){

    bool sameSame[str1.size()+1][str2.size()+1];

    sameSame[0][0] = true;
    for(int i = 1; i<= str2.size(); i++) sameSame[0][i] = false;
    for(int j = 1; j<= str1.size(); j++) {
        while(str1[j] == '*'){
            sameSame[j][0] = true; j++;
        }
        sameSame[j][0] = false;
    }


    for(int j = 1; j<=str1.size() ; j++){
        for(int i = 1; i<=str2.size() ; i++){
            if(str1[j] == '*'){
                sameSame[j][i] = sameSame[j-1][i] + sameSame[j][i-1];
            }
            else if(str1[j] == '?'){
                sameSame[j][i] = sameSame[j-1][i-1];
            }
            else{
                if(str1[j] == str2[i]){
                    sameSame[j][i] = sameSame[j-1][i-1];
                }
                else{
                    sameSame[j][i] = false;
                }
            }
        }
    }

    if(sameSame[str1.size()][str2.size()])
        cout << "Yes";
    else    
        cout << "No";

    cout << endl;
    return;
}



int main()
{
    test("g*ks", "geeks"); // Yes
    test("ge?ks*", "geeksforgeeks"); // Yes
    test("g*k", "gee");  // No because 'k' is not in second
    test("*pqrs", "pqrst"); // No because 't' is not in first
    test("abc*bcd", "abcdhghgbcd"); // Yes
    test("abc*c?d", "abcd"); // No because second must have 2
                             // instances of 'c'
    test("*c*d", "abcd"); // Yes
    test("*?c*d", "abcd"); // Yes
    return 0;
}
