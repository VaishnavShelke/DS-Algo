#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Find maximum meetings in one room

// Similar  to job sequencing problem
// i.e to complete maximum NUMBER {only} of jobs

class meetingspec{
public:
    int starttime;
    int endtime;
    int meetingid;
};

bool comparer(meetingspec m1,meetingspec m2){
    return (m1.endtime<m2.endtime);
}

int main(){
    int start[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924};
    int ends[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 } ;

    int t_meetings = sizeof(start)/sizeof(start[0]);

    meetingspec meetings[t_meetings];
    for(int i = 0;i<t_meetings;i++){
        meetings[i].starttime = start[i];
        meetings[i].endtime = ends[i];
        meetings[i].meetingid = i;
    }

    sort(meetings, meetings + t_meetings,comparer);
    vector<int> answer;
    answer.push_back(meetings[0].meetingid);

    int engagedupto = meetings[0].endtime;
    for(int i = 1; i<t_meetings ;i++){
        if(meetings[i].starttime < engagedupto){
            continue;
        }
        else{
            answer.push_back(meetings[i].meetingid);
            engagedupto = meetings[i].endtime;
        }
    }
    cout << "The order of meetings should be \n";
    for(int i = 0;i<answer.size();i++){
        cout << answer[i] << "\t";
    }
    return 0;
}
