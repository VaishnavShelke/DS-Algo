#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Bishu and Soldiers
// Given the power of soldires and the power of bishu
// Bishu can kill all the soldiers having power less than or equal to him
// given the power of bishu find the number of soldiers he can kill with this given power
// Count the number of soldires he can kill

int main(){
    int power[] = {2,1,3,5,4,6,8,9,7};
    int soldiers = sizeof(power)/sizeof(power[0]);
    int bishu_power = 0;
    sort(power,power + soldiers);
    int deathcount = upper_bound(power,power+soldiers,bishu_power) - &power[0];
    cout << "The death count of the soldiers is ... " << deathcount;
}
