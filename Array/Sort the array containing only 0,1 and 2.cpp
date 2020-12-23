#include <iostream>
#include <typeinfo>
using namespace std;

// 3 WAY PARTIONING ALGORITHM
// THE DUTCH NATIONAL FLAG PROBLEM

/* Create 4 partitions 
  1. 0 -> low             --->>> This contains only 0 
  2. low -> mid           --->>> This contains only 1 low included             
  3. mid -> high          --->>> Unknown mid and high included 
  4. high -> end index    --->>> Only 2 high excluded
  
  here the mid is the pointer
  initialize low and mid to 0 and high to end index
  if the.
    1. arr[mid] == 2 then, swap the value with that at high and keep mid as it is;
    2. arr[mid] == 1 then, increase the mid region by 1 hence counter mid ++;
    3. arr[mid] == 0 then, swap the mid value with low one,
                     Increase the counter of mid by one...... Understandable
                     Increase the low by one,,,,,, Because we are certain that the low was standing on 1 and hence it
                            places the value 1 at mids position by swapping
*/

int main(){
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int low ,mid,high;
    low = 0;
    mid = 0;
    high = sizeof(arr)/sizeof(arr[0]) - 1;
    int sizearr = high+1;
    int i = 0;
    while ( mid <= high ){
        if (arr[mid] == 0){ swap(arr[mid],arr[low]); low++; mid++;}
        else if(arr[mid] == 2) { swap(arr[mid],arr[high]); high--;}
        else {swap(arr[mid],arr[mid]); mid++;}

    }
    cout << "The sorted order .... \n";
    for(int i = 0;i<sizearr ; i++) cout << arr[i] << " ";
    return 0;
}
