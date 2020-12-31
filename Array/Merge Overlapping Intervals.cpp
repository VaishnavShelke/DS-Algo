#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// Merge Overlapping intervals

/*

Just Draw a diagram then you will understand

    1. Sort the intervals in the order of increasing starting time
    2. Set 
            start -->> interval[0].first
            end -->> interval[0].second
    3. Now there are two possible cases
            A. The start of the next element is less than the end
                in that case   start -->> start
                               end -->> max(end,interval[0].second
            B. Else.
                add previous start and end to answer
                and.... start -->> interval[i].first
                        end -->> interval[i].second
*/

int main(){
    int arr[][2] = { {6,8}, {1,9}, {2,4}, {4,7} };
    int len = sizeof(arr)/sizeof(arr[0]);
    vector<pair<int,int>> merged,intervals;

    // copying intervals int a vector of pairs

    for(int i = 0; i<len ; i++){
        intervals.push_back(make_pair(arr[i][0],arr[i][1]));
    }

    // Sort the intervals according to the starting time

    sort(intervals.begin(),intervals.end());  // By default the vector of pairs is sorted according to the key

    //now begins the process of merging

    int start = intervals[0].first;
    int ends = intervals[0].second;

    for(int i = 1; i< len ; i++){
        if(intervals[i].first <= ends){
            if(ends < intervals[i].second)
                ends = intervals[i].second;
        }
        else{
            merged.push_back(make_pair(start,ends));
            start = intervals[i].first;
            ends = intervals[i].second;
        }
    }

    merged.push_back(make_pair(start,ends))
    ;
    cout << "Merged intervals are .... \n";
    for(int i = 0; i < merged.size() ; i++){
        printf("( %d, %d)\n",merged[i].first,merged[i].second);
    }
    return 0;
}
