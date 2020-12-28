#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


// Maximum number of trains that can be stopped on the platformsss in a station in a day
    
/*
    You are given a time table of trains for a station
    It contains 
    1.Arrival time
    2.Departure time
    3.Platform number
    
    It is you choice to host a train on your platform or not
    You can either let a train occupy the platform or simply let it go.
    Like this in a given schedule you have to fit max trains....
    
    Method
        1. Segregate all the trains in different groups on the basis of platform occupied
        2. Run upcoming process on all the groups individually and add answers of all
            3. Sort a given group in the increasing order of departure time
            4. Begin from the first train,
            5. for next train check if the departure time of previous occupied train is lesser than the arrival time of current train or not
                If not discard and move to next train
                ...Else add this new train to your count and set the departure time of this new train as a parameter to
                    compare with future trains.
        6. Perform 3->4->5 on all groups and aad the answers
*/
class traininfo{
public:
    int arrival,departure,platform;
};

bool comparer(traininfo t1,traininfo t2){
    if(t1.platform != t2.platform){
        return (t1.platform < t2.platform);
    }
    else{
        return (t1.departure < t2.departure);
    }
}

/*
Input : n = 3, m = 6
Train no.|  Arrival Time |Dept. Time | Platform No.
    1    |   10:00       |  10:30    |    1
    2    |   10:10       |  10:30    |    1
    3    |   10:00       |  10:20    |    2
    4    |   10:30       |  12:30    |    2
    5    |   12:00       |  12:30    |    3
    6    |   09:00       |  10:05    |    1
*/
int main(){
    traininfo train[] = { {1000, 1030, 1},
                      {1010, 1030, 1},
                      {1000, 1020, 2},
                      {1030, 1230, 2},
                      {1200, 1230, 3},
                      {9000, 1005, 1} };
    int prevdpt;
    int totalT = 0;
    int len = sizeof(train)/sizeof(train[0]);
    sort(train,train + len,comparer);
    int prevplt = 0;
    for(int i = 0; i< len;i++){
        if(train[i].platform != prevplt){
                prevplt = train[i].platform;
                prevdpt = train[i].departure;
                totalT ++;
           }
        else{
            if(train[i].arrival > prevdpt){
                prevdpt = train[i].departure;
                totalT++;
            }
            else continue;
        }
    }
    cout<< totalT;
    return 0;

}
