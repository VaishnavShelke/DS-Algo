#include <bits/stdc++.h>
using namespace std;


// Find kth largest sum subarray
/* We know that we are going to get a large number of integers and out of those 
 we have to find the kth largest.....
 
    But the problem is the exponential nature of the input elements,     
        You see even if we increase a single number to arr[],the number os subarray sums exponentially increases....
        
    So heapifying all subarraysums is not a good idea.....
    
    Now look at this one.....
        What if i create a min heap which contains only the largest elements found so far.... How do we do that????
        
        1. Lets first initialise a minheap 
        2. We fill this heap initially with k elements of the subarray sum.
        3. Now comes the chance of the other than k elements..
            if the new element is larger than the top element in the min heap
                only then we allow it to enter the heap and we pop the previous top element
        4. This way we ensure that only those elements are added in the heap which 
            are going to increase the average of all heap elements and we pop the least of those k.
            
    SUPER COOL TECHNIQUE IMPLEMENTED USING PRIORITY QUE
*/


int main(){
    int arr[] = {20, -5, -1};
    priority_queue <int, vector<int>, greater<int>> minheap;
    int k = 3;
    int len = sizeof(arr)/sizeof(arr[0]);
    int sumarr[len+1];
    sumarr[0] = 0;
    sumarr[1] = arr[0];
    int subarrsum;
    for(int i = 2;i<len+1;i++) sumarr[i] = sumarr[i-1] + arr[i-1];


    for(int base = 0; base < len+1; base++){
        for(int cap = base+1; cap < len+1;cap++){

            subarrsum = sumarr[cap] - sumarr[base];
            //cout << subarrsum << " " << base << " " << cap <<"\n";
            if(minheap.size() < k){
                minheap.push(subarrsum);
            }
            else{
               if (subarrsum > minheap.top()){
                minheap.pop();
                minheap.push(subarrsum);
               }
            }
        }}
    cout << "\n";
    cout << "Kth largest sum subarray is ........." << minheap.top();
    return 0;

}
