#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


// Maximum thickness of overlap problem

/*
        TIME FRAME
   | <<--1--->>     <<-----2---->>    <<-3->>   <<4>>
   |    <<-5->>  <<---6--->> <<---------7--------->>
   | <<-8->>                             <<----9---->>

        REORDER ON THE BASIS OF TIME BOTH DEPARTURE AND ARRIVAL COMBINED
    Event time frame :->
        1 Arrival
        8 Arrival
        5 Arrival
                    // Total 3 trains stacked on station
        8 Departure
                    // Total 2 trains stacked till now
        ........And so on
*/

int main(){
    int arrival[] = { 900, 940, 950, 1100, 1500, 1800 };
    int departure[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int len = sizeof(arrival)/sizeof(arrival[0]);
    sort(arrival,arrival+len);
    sort(departure,departure+len);
    int ptrar = 0,ptrde = 0;
    int stacked = 0;
    int maximumstacked = INT_MIN;
    while(ptrar<len || ptrde<len){
        if(ptrar != len){
        if(arrival[ptrar] <= departure[ptrde]){
            stacked++;
            cout << "Arrived" << "\n";
            ptrar++;
        }
        else{
            stacked--;
            cout << "Departed" << "\n";
            ptrde++;
        }
        maximumstacked = max(maximumstacked,stacked);
    }
        else break;    }

    cout << "Max train engaged at a time ...." << maximumstacked;
    return 0;
}
