
typedef vector<int> vv;
int Solution::canJump(vv &A) {
    vv  minr(A.size());
    for(int i = 0; i<A.size() ; i++) minr[i] = i;
    if(A.size() == 1) return 1;
    int upr = A[0];
    for(int i = 1; i<=upr ; i++){
        if(i+A[i] >= A.size()-1) return 1;
        upr = max(upr,i + A[i]);
    }
    return 0;
}
