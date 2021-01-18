#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Find Majority Elements
/*
    Steps involved ...
        Begin with the first element snd set the counter to 1 and majority element as the index of first element(0);
        Now as you traverse through the loop 
            if the current element is equal to previous element
                increase the count by 1
            else    
                decrease the count by 1
            if by doing above if-else the counter value becomes zero
            change the majority element to current index and set counter to 1
        At last you will get some value of majority index
                NOW check whether really the majority index value is majority or not by traversing the array again

    This algorithm is called moores algorithm
*/
/*
        Intuition behind Moores Algorithm

        Consider THERE CERTIANLY IS A MAJORITY ELEMENT IN THE ARRAY
        Now assume that we are sitting at a position at which the counter becomes zero this for certatin means one thing
        either till now among all the elements traversed the number of non majority elements is moer than or equal to majority element
        Also assum that this is the last instance when the count becomes zero;

        Now only possible situation to the remaining array to be traversed is that there are more numbers that 

        Please study yourself

*/

int main(){
    int arr[] = {1,4,5,3,5,6,8,3,7,7,7,7,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    int majority_ele = arr[0];
    int counter = 1;

    for(int i = 1;i<len;i++){
        if(arr[i] == arr[i-1]){
            counter++;
        }
        else{
            counter--;
        }
        if(counter == 0){
            majority_ele = i;
            counter++;
        }
    }

    // Here we obtain tentative majority element
    // Let us check wether the majority_ele is really majority or not
    counter = 0;
    for(int i = 0;i<len ;i++){
        if(arr[i] == arr[majority_ele]) counter++;
    }
    if(counter > len/2) cout << "The Majority Element is ..... " << arr[majority_ele];
    else cout << "No majority element ";
    return 0;
}
