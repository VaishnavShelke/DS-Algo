// A structure to represent a job
// Job Sequencing Problem
struct Job
{
   char id;     // Job Id
   int dead;    // Deadline of job
   int profit;  // Profit if job is over before or on deadline
};
 
bool comparer(Job j1,Job j2){
    return j1.profit > j2.profit;
}

vector<int> printJobScheduling(Job* arr,int n){


    sort(arr, arr + n, comparer);
    int jobCount = 0; int profit = 0;
    int maxDead = INT_MIN;
    for(int i = 0; i<n ; i++){
        maxDead = max(maxDead,arr[i].dead);
    }
    maxDead = min(maxDead,n);
    vector<char> jobSequence;

    for(int i = 0; i<maxDead+1 ; i++) jobSequence.push_back('0');

    int k;
    for(int i = 0; i<n ; i++){
        k = arr[i].dead;
        while(k>maxDead) k--;
        while(k > 0 && jobSequence[k] != '0'){
            k--;
        }
        if(k>0) {
            jobSequence[k] = arr[i].id;
            jobCount++;
            profit += arr[i].profit;
        }

    }

    vector<int> answer;
    answer.push_back(jobCount);
    answer.push_back(profit);

    return answer;
}

// Driver code
int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs \n";
   
    // Function call
    vector<int> ans = printJobScheduling(arr, n);

    cout << ans[0] << " --->> " << ans[1];
    return 0;
}
