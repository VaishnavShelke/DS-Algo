typedef vector<int> vv;

int Solution::trap(const vv &A) {

    vv ltor(A.size(),0); ltor[0] = A[0];
    vv rtol(A.size(),0); rtol[A.size()-1] = A[A.size()-1];
    vv res(A.size());

    int i = 1, j = A.size()-2;

    while(i<A.size() && j>=0){
        ltor[i] = max(ltor[i-1],A[i]);
        rtol[j] = max(rtol[j+1],A[j]);
        i++; j--;
    }

    for(int i = 0; i<A.size() ; i++) res[i] = min(ltor[i], rtol[i]);

    int cnt = 0;
    for(int i = 0; i<A.size() ; i++) if(res[i] > A[i]) cnt += res[i] - A[i];

    return cnt;
    
}
