#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !                                 Longest Palindrome                                  
 * *                                               
 * *                    Problem is the child of longest common subsequence
 * *                          Can Be Done With Single String Also...
 **/

int main(){
    string str1 = "GEEKS FOR GEEKS";
    string str2 = str1;
    reverse(str2.begin(),str2.end());

    int arr1[str1.size()+1], arr2[str1.size()+1];
    int* commonSubBack, *commonSubNow;
    commonSubNow = arr1; commonSubBack = arr2;
    int* temp;
    for(int j = 0; j<= str1.size(); j++){
        for(int i = 0; i<= str1.size(); i++){
            if(i == 0 || j == 0) commonSubNow[i] = 0;
            else if(str1[j-1] == str2[i-1]) commonSubNow[i] = commonSubBack[i-1] + 1;
            else{
                commonSubNow[i] = max(commonSubNow[i-1],commonSubBack[i]);
            }
        }
        temp = commonSubNow;
        commonSubNow = commonSubBack;
        commonSubBack = temp;
    }

    cout << "The Length of Longest Palindrome ... " << commonSubBack[str1.size()];
    return 0;

}
