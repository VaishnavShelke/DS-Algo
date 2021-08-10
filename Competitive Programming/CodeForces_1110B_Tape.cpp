// https://codeforces.com/problemset/problem/1110/B


#include<bits/stdc++.h>
using namespace std;

vector<int> gaps;

int main(){
    int n,m,k;
    cin >> n >> m;
    cin >> k;
    vector<int> b(n);

    for(int i = 0; i<n ; i++){
        cin >> b[i]; 
        if(i != 0) gaps.push_back(b[i]-b[i-1]);
    }
    sort(gaps.rbegin(),gaps.rend());

    int lltp = b.back() - b[0];

    for(int i = 0; i < (int)gaps.size()  && i < k - 1 ; i++ ){
        lltp -= gaps[i];
    }
    cout << lltp + k;
}
