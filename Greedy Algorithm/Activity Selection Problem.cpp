#include <iostream>
#include <typeinfo>
#include <algorithm>
using namespace std;

// Activity Selection Problem

class taskschedule{
public:
    int start,ends;
    };
bool comparer(taskschedule t1,taskschedule t2){
    return (t1.ends < t2.ends);
}

int main(){
    taskschedule arr[] = {{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};
    int len = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+len,comparer);
    for(int i = 0; i<len ; i++){
        cout << arr[i].start << " " << arr[i].ends << "\n";
    }
    // The input schedule is now sorted in format of increasing
    // finish time
    int task_undertaken = 1;
    int task_comp = arr[0].ends;
    for(int i = 1; i<len ; i++){
        if(task_comp <= arr[i].start){
            task_undertaken++;
            task_comp = arr[i].ends;
        }
    }

    cout << "The maximum possible tasks that can be performed are....\n.... " << task_undertaken;
    return 0;
}
