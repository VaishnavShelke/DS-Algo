#include <bits/stdc++.h>
using namespace std;
 
const int MAX_CHAR = 256;

// Minimum sum of squares of character counts in a given string after removing k characters

class maxHp{
public:
    bool operator()(int a,int b){
        return a<b;
    }
};

int minStringValue(string str,int k){

    int countChar[MAX_CHAR];
    for(int i = 0; i<MAX_CHAR ; i++) countChar[i] = 0;
    for(int i = 0; i<str.size() ; i++) countChar[str[i]]++;

    priority_queue<int,vector<int>,maxHp> maxHeap;

    for(int i = 0; i<MAX_CHAR ; i++){
        if(countChar[i]>0){
            maxHeap.push(countChar[i]);
        }
    }

    if(maxHeap.size() == 1){
        if(maxHeap.top()>k){
            return (maxHeap.top()-k)*(maxHeap.top()-k);
        }
        else return 0;
    }
    int topOccur;
    while(k > 0 && maxHeap.top() != 0){
        topOccur = maxHeap.top(); maxHeap.pop();
        if(topOccur - maxHeap.top() >= k){
            topOccur -= k;
            maxHeap.push(topOccur);
            break;
        }
        else{
            k = k - (topOccur - maxHeap.top() + 1);
            topOccur -= (topOccur - maxHeap.top() + 1) ;
            maxHeap.push(topOccur);
        }
        //cout << k << " ";
    }

    int sumF = 0;
    while(!maxHeap.empty()){
        sumF += maxHeap.top()*maxHeap.top(); maxHeap.pop();
    }
   
    return sumF;
}
// Driver Code
int main()
{
    string str = "abbccc"; // Input 1
    int k = 2;
    cout << minStringValue(str, k) << endl;
 
    str = "aaaa"; // Input 2
    k = 9;
    cout << minStringValue(str, k);
 
    return 0;
}
