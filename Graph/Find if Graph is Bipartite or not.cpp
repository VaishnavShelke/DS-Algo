#include<list>
typedef vector<vector<int>> vvv;
typedef vector<int> vv;



bool BFSCatg(int src,list<int>* adj,vv &catg){

    queue<int> qu;
    int u;
    qu.push(src);

    while(!qu.empty()){
        u = qu.front();
        qu.pop();

        for(int v : adj[u]){
            if(catg[v] == -1){
                catg[v] = 1 - catg[u];
                qu.push(v);
            }
            if(catg[u] == catg[v]){
                return false;
            }
        }
    }
    return true;

}

int Solution::solve(int A, vvv &B) {

    list<int> adj[100005];
    vv catg(100005,-1);

    for(int i = 0; i<B.size() ; i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    for(int i = 1; i<= A ; i++){
        if(catg[i] == -1){
            catg[i] = 0;
            if(!BFSCatg(i,adj,catg)) return false;
        }
    }

    return true;
}
