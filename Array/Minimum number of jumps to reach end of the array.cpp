#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
using namespace std;

// Minimum Number of steps to reach the end of array


// APPROACH 1:  GREEDY APPROACH                                  O(N) time complexity O(1) space complexity
/* Assume that you are sitting at the last element of the array
 Now to reach here you choose the farthest launch pad at the back to reach this position
 And you make a jump;
 
 Now from this new launch pad you again look for the farthest newer launch pad;
 
 And so on.....
 */
int main(){
    int arr[] = {5,6};
    int t_steps = 0;
    int len = sizeof(arr)/sizeof(arr[0]);
    int post = len - 1;
    int new_post;
    while(post != 0){
        for(int i = post - 1; i >=0; i-- ){
            if (arr[i] >= post - i) new_post = i;
        }
        post = new_post;
        t_steps ++;
    }
    cout << t_steps;
    return 0;
}


// APPROACH 2:  DYNAMIC PROGRAMMING 

/* Number of steps required to reach the given position is the minimum 
    of the steps required to reach the position.... from where we can reach the given/present position
*/

int main(){
    int arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int total_launch = sizeof(arr)/sizeof(arr[0]);
    int min_steps_to[total_launch+1];
    min_steps_to[0] = 0;
    min_steps_to[1] = 0;
    int minima = 1e6;
    for(int th_step = 2; th_step <= total_launch; th_step++){
            minima = 1e6;
        for(int i = th_step-1; i > 0 ; i--){
            if(arr[i-1] >= th_step-i){
                minima = min(minima,min_steps_to[i]);
            }
            min_steps_to[th_step] = 1+minima;
        }
    }
    cout << min_steps_to[total_launch];
    return 0;
}

