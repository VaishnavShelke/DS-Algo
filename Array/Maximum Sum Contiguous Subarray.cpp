#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
using namespace std;

// Maximum sum Contiguous Sub-array Problem 
 /* Basically what you do is that you make a seperate array which finds the max suim array ending at the ith 
        place;
        For example lets say the 3rd position stores the max possible sum subarray ending at the 3rd element
        Now to this list lets add 4th element
        To find the max sum subarray possible upto 4
        it can either be max sum subarray upto 3 + value at 4
        or simply value at 4;
        
        
        Hence after find max possible sum UPTO i for all elements you choose the least of them all
*/

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int sizearr = sizeof(arr)/sizeof(arr[0]);
    int sum_upto[sizearr];
    sum_upto[0] = 0;

    for(int i = 1;i<sizearr; i++){
        sum_upto[i] = max(sum_upto[i-1]+arr[i],arr[i]);
    }
    cout << "Max sum Contiguous Subarray " << *max_element(sum_upto,sum_upto+sizearr);
}
