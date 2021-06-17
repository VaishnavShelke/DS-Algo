#include <bits/stdc++.h>
using namespace std;

// Combinational Sum
// Danmmmm... you missed the trickiest part
//                           Remove the repeating numbers first
//                           You would still havev got the answer but then the time would have been too much


void mycombinationSum(vector<int> arr,int base, int sum,vector<int> path,vector<vector<int>>& answer){

    if(base >= arr.size()) return;
    if(sum < 0){
        return;
    }
    if(sum == 0){
        answer.push_back(path);
        return;
    }
    if(arr[base]>sum){
        return;
    }

    path.push_back(arr[base]);
    mycombinationSum(arr,base,sum-arr[base],path,answer);
    path.pop_back();

    mycombinationSum(arr,base+1,sum,path,answer);
    
    return;

}

vector<vector<int>> combinationSum(vector<int> arr,int sum){

    sort(arr.begin(),arr.end());
    vector<int> uniqArr; uniqArr.push_back(arr[0]);
    for(int i = 1; i<arr.size(); i++){
        if(arr[i] != uniqArr[uniqArr.size()-1]){
            uniqArr.push_back(arr[i]);
        }
    }

    vector<vector<int>> answer;
    vector<int> path;
    mycombinationSum(uniqArr,0,sum,path,answer);
    return answer;
}

// Driver code
int main()
{
    vector<int> ar;
    ar.push_back(2);
    ar.push_back(4);
    ar.push_back(6);
    ar.push_back(8);
    ar.push_back(2);
    ar.push_back(2);
    int n = ar.size();
 
    int sum = 8; // set value of sum
    vector<vector<int> > res = combinationSum(ar, sum);
 
    // If result is empty, then
    if (res.size() == 0) {
        cout << "Emptyn";
        return 0;
    }
 
    // Print all combinations stored in res.
    for (int i = 0; i < res.size(); i++) {
        if (res[i].size() > 0) {
            cout << " ( ";
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << ")";
        }
    }
}
