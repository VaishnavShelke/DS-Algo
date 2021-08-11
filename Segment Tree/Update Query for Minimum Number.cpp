#include<bits/stdc++.h>
using namespace std;
#define INF  1000000

int arr[100001];
int segt[400001];

void makeTree(int i,int ss,int se){

    if(ss == se) { segt[i] = arr[se]; return; }

    int mid = (ss + se)/2;
    makeTree(2*i, ss, mid);
    makeTree(2*i + 1,mid+1,se);

    segt[i] = min(segt[2*i],segt[2*i+1]);
    return;
}

int query(int i , int qs, int qe,int ss,int se){

    if( qe < ss || qs > se) return INT_MAX;

    if( ss >= qs && se <= qe) return segt[i];

    int mid = (ss+se)/2;
    return min(query(2*1,qs,qe,ss,mid), query(2*i+1,qs,qe,mid+1,se));
 
}

void update(int si,int up,int ss,int se){

    if(ss == se) {segt[si] = arr[up]; return ; }
    int mid = (se+ss)/2;

    if(up <= mid) update(2*si,up,ss,mid);
    else update(2*si+1,up,mid+1,se);
    
    segt[si] = min(segt[2*si],segt[2*si+1]);
    return;


}


int main(){
    int N;
    cin >> N;
    for(int i = 1; i<=N ; i++) cin >> arr[i];
    makeTree(1,1,N);
    arr[2] = 10000;
    update(1,2,1,N);
    int qu;
    int qs,qe;
    cin >> qu;
    while(qu--){

        cin >> qs >> qe;
        cout << query(1,qs+1,qe+1,1,N) << endl;
    }
}
