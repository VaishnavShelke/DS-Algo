#include <iostream>
#include <typeinfo>
using namespace std;

// One More Partitioning Problem
// After the Dutch Flag Problem/Sort 0,1,2 array problem/4 partitioning problem

/* The Structure of the solution is as follows
        { ......-ve........., before-me-negative,.......Un-Explored......,after-me-positive,........+ve.........}
*/
int main(){
    int before_me_negative,after_me_positive;
    int arr[] =  { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    before_me_negative = 0;
    after_me_positive = sizeof(arr)/sizeof(arr[0])-1;
    int sizearr = after_me_positive + 1;
    while(before_me_negative <= after_me_positive){
        if (arr[before_me_negative] < 0) {before_me_negative ++;}
        else {swap(arr[before_me_negative],arr[after_me_positive]); after_me_positive--;}
    }
    cout << "Take a look at this partitioned array " << "\n.....";
    for (int i = 0;i < sizearr; i++){
        cout << arr[i] << " ";
    }
    return 0;

}
