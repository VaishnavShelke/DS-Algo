#include <bits/stdc++.h>
using namespace std;


int minOperations(string str1, string ref){

    int outOfplace_0 = 0;
    int outOfplace_1 = 0;

    for(int i = 0; i<str1.size() ; i++){
        if(str1[i] != ref[i]){
            if(ref[i] == '1'){
                outOfplace_0++;
            }
            else{
                outOfplace_1++;
            }
        }
    }
    return max(outOfplace_1,outOfplace_0);
}


// Driver code
int main()
{
    string s = "010", t = "101";
    int n = s.length();
    cout << minOperations(s, t);
 
    return 0;
}
