#include <bits/stdc++.h>
using namespace std;



int main(){
    vector<int> vec = {1,9,8,5,6,7,3,4,2,10};
    int len = sizeof(vec)/sizeof(vec[0]);
    int k = 4;
    make_heap(vec.begin(),vec.end());
    for(int i =0; i<vec.size() ; i++ ) cout<< vec[i] << " ";
    cout << "\n";
    for(int i = 1;i <k;i++) {pop_heap(vec.begin(),vec.end()); vec.pop_back();}
    cout << vec.front();
    return 0;
}
