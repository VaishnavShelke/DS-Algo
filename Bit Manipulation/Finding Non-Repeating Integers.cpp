
/* The approach of this problem involves grouping the array into two distinct groups according to the ith set bit
   First step involves finding the non similar position of set bits in the two numbers that are non repeating,
   This can be easily done by xor operating on the entire array and then finding for the ith set bit;

   Now we kow the position of the dissimilar bit, now group the entire array into two groups, one woth the ith set and other vice versa.
   And xor the two groups individually.
   You see only the ones that are non repeating will remain from each group */

int main(){
    int arr[] = {2,8,5,8,3,2,5,6};
    int xoor = 0;
    for (int i =0;i < 8;i++){
        xoor = xoor^arr[i];
    }
    // find any set bit out of xor
    bool found = true;
    int i = 0;
    while (found){
        if (xoor&(1 << i) > 0){
            found = false;
        }
        else i++;
    }
    int grp1 = 0;
    int grp2 = 0;
    int distinctbit = i;
    for(i = 0;i< 8;i++){
        if (arr[i]&(1 << distinctbit) > 0) grp1 = grp1^arr[i];
        else grp2 = grp2^arr[i];
    }
    cout << "First NonRepeating number : " << grp1;
    cout << "\nSecond Non Repeating number : "<< grp2;
    return 0;
}


