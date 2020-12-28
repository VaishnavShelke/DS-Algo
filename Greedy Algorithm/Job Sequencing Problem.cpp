#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
using namespace std;


// JOB SEQUENCING PROBLEM
/* Given a set of jobs and corresponding deadlines and profits
    Find the order in which the job should be performed to maximize profits;

    1. Make an object which will store job description {task name,deadline,profit}
    2. Sort the job object in the order of decreasing profit using a custom made comparer function
    3. Make an answer array
        Traverse the sorted job-object array;
        If the job-deadline as pointed by traverse i is not booked book it
        ... If the job deadline is book look for previous dates till the empty schedule is found
*/

class job_description{
public:
    char taskname;
    int deadline,profit;
};

bool comparer(job_description j1,job_description j2){
    return (j1.profit>j2.profit);
}

int main(){
    char answer[20+1];
    fill_n(answer,20+1,'X');

    job_description job[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                              {'d', 1, 25}, {'e', 3, 15}};
    int len = sizeof(job)/sizeof(job[0]);

    sort(job,job + len,comparer);
    int deadline;
    for(int i = 0;i<len;i++){
        if (answer[job[i].deadline] == 'X'){
            answer[job[i].deadline] = job[i].taskname;
            }
        else{
            deadline = job[i].deadline-1;
            while(deadline!=0){
                if (answer[deadline] == 'X'){
                    answer[deadline] = job[i].taskname;
                    break;
                }
                else deadline--;
            }}
                            }
    for(int i = 0; i <21 ;i++) if (answer[i] != 'X') cout << answer[i] << " ";
    return 0;
}
