#include<bits/stdc++.h>
using namespace std;

// Stack Permutations (Check if an array is stack permutation of other)

bool checkStackPermutation(int* input,int* output,int n){
    stack<int> stc;
    int index = 0;
    for(int i = 0; i<n ; i++){
        stc.push(input[i]);
        while(!stc.empty() && stc.top() == output[index]){
            stc.pop(); index++;
        }
    }
    if(stc.empty()) return true;
    else return false;
}  


int main()
{
    int input[] = {1, 2, 3};
  
    int output[] = {3, 2, 1};
  
    int n = 3;
  
    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}
