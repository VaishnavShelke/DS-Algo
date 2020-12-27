#include <bits/stdc++.h>
using namespace std;

// MEARGE TWO MAX HEAP

int main(){
    vector<int> heap1 = { 10, 5, 6, 2 };
    int len1 = heap1.size();
    vector<int> heap2 = { 12, 7, 9 };
    int len2 = heap2.size();
    vector<int> heap3;
    int temp;
    for(int i = 0;i < len1;i++){
        temp = heap1.front();
        heap3.push_back(temp);
        push_heap(heap3.begin(),heap3.end());
        pop_heap(heap1.begin(),heap1.end());
        heap1.pop_back();
    }
    for(int i = 0;i < len2;i++){
        temp = heap2.front();
        heap3.push_back(temp);
        push_heap(heap3.begin(),heap3.end());
        pop_heap(heap2.begin(),heap2.end());
        heap2.pop_back();
    }
    for(int i = 0;i< len1 + len2;i++){
        cout << heap3.front() << " ";
        pop_heap(heap3.begin(),heap3.end());
        heap3.pop_back();
    }
}
