typedef vector<int> vv;
typedef unordered_set<char> stt;

unordered_map<char,int> dbs;
#define mod 1003
vector<vector<int>> flse(151,vector<int> (151,0));
vector<vector<int>> ture(151,vector<int> (151,0));

int ways_fls(string A, int low,int high);

int ways_tru(string A, int low,int high){
    if(low == high){
        return dbs[A[low]];
    }
    if(ture[low][high] > 0) return ture[low][high];
    int cnt = 0;
    for(int i = low; i <= high; i++){
        cnt = cnt%mod;
        if(A[i] == '|'){
            cnt += (ways_tru(A,low,i-1)*ways_tru(A,i+1,high) 
                    + ways_tru(A,low,i-1)*ways_fls(A,i+1,high)
                        + ways_fls(A,low,i-1)*ways_tru(A,i+1,high));
        }
        else if(A[i] == '^'){
            cnt +=  (ways_tru(A,low,i-1)*ways_fls(A,i+1,high) 
                        + ways_fls(A,low,i-1)*ways_tru(A,i+1,high));

        }
        else if(A[i] == '&'){
            cnt +=  (ways_tru(A,low,i-1)*ways_tru(A,i+1,high));
        }
    }
    cnt = cnt%mod;
    
    return ture[low][high] = cnt;
}

int ways_fls(string A, int low,int high){

    if(low == high) return 1-dbs[A[low]];
    if(flse[low][high] > 0) return flse[low][high];
    int cnt = 0;
    for(int i = low; i <= high; i++){
        cnt%mod;
        if(A[i] == '|'){
            cnt += (ways_fls(A,low,i-1)%mod*ways_fls(A,i+1,high)%mod);
        }
        else if(A[i] == '^'){
            cnt +=  (ways_tru(A,low,i-1)%mod*ways_tru(A,i+1,high)%mod 
                        + ways_fls(A,low,i-1)%mod*ways_fls(A,i+1,high)%mod);

        }
        else if(A[i] == '&'){
            cnt +=  (ways_tru(A,low,i-1)%mod*ways_fls(A,i+1,high)%mod 
                        + ways_fls(A,low,i-1)%mod*ways_tru(A,i+1,high)%mod
                            + ways_fls(A,low,i-1)%mod*ways_fls(A,i+1,high)%mod);
        }
    }
    cnt = cnt%mod;
    
    return flse[low][high] = cnt;
}




int Solution::cnttrue(string A) {
    dbs['T'] = 1; dbs['F'] = 0;
    vv tru(A.size());
    vv fls(A.size());
    int low = 0, high = A.size()-1;
    return ways_tru(A,low,high);

}
