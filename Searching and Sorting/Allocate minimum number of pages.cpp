class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        unordered_map<int,unordered_map<int,int>> memo;
        int sumArr[n+1]; sumArr[n] = 0;
        for(int j = n-1; j>=0 ; j--) sumArr[j] = sumArr[j+1] + arr[j];
        return myfindPages(sumArr, n, m,memo);
    }
    int sumOfPages(int* arr,int base,int n){
    int sum = arr[base]-arr[n];
    return sum;
}

int myfindPages(int* arr,int n,int m,unordered_map<int,unordered_map<int,int>>& memo){

    if(memo.find(n) != memo.end()){
        if(memo[n].find(m) != memo[n].end()){
            return memo[n][m];
        }
    }

    if(m == 1){
        return sumOfPages(arr,0,n);
    }
    if(n == 1){
        return arr[0]-arr[1];
    }
    int mid;
    int high = n-1;int low = 0;
    int maxPages = 0;
    int maxOverall = sumOfPages(arr,0,n);
    int findPg;int sumPg;
    // {12, 34, 67, 90}
    while(high>=low){
        mid = (high+low)/2;
        findPg = myfindPages(arr,mid+1,m-1,memo);
        sumPg = sumOfPages(arr,mid+1,n);
        maxPages = max(findPg,sumPg);
        if(sumPg>findPg){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        maxOverall = min(maxOverall,maxPages);
    }
    memo[n][m] = maxOverall;
    return maxOverall;
}

};
