

// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/separating-numbers-6fe976a9/


#include<bits/stdc++.h>
using namespace std;
#define ff  first
#define ss  second 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpp;
typedef unordered_map<int,int> unn;

unn mpp[300001];
int par[300001];
int cost[300001];
vi opration;
vpp edge;
vi ans;


int find(int v){
	if(v == par[v]){ return v;}
	int u = find(par[v]);
	par[v] = u; // Set compression;
	return u;
}

int merge(int a, int b){

	if(mpp[a].size() < mpp[b].size()) swap(a,b);
	int val = 0;
	for(pii c: mpp[b]){
		if(mpp[a].find(c.ff) != mpp[a].end()){
			val += mpp[a][c.ff]*c.ss;
		}
	}

	for(pii c : mpp[b]){
		if(mpp[a].find(c.ff) != mpp[a].end()) mpp[a][c.ff] += mpp[b][c.ff];
		else mpp[a][c.ff] = mpp[b][c.ff];
	}
	par[b] = a;
	return val;

}




void findAns(){

	int inx;
	int cnt = 0;
	pii conn;
	while(opration.size()>0){
		inx = opration.back();
		opration.pop_back();
		conn = edge[inx];
		cnt = merge(find(conn.ff),find(conn.ss));
		ans.push_back(cnt);
	}
	while(ans.size()>0) 
		cout << ans.back() << endl, ans.pop_back();
	return;
}


int main(){
	int N;
	int a,b;
	int op;
	cin >> N;
	for(int i = 0; i<N-1 ; i++){ 
		cin >> a >> b;
		edge.push_back({a,b});
	}
	for(int i = 1; i<=N ; i++) cin >> cost[i];
	for(int i = 1; i<=N ; i++) mpp[i][cost[i]] = 1;
	for(int i = 0; i<N-1 ; i++) { cin >> op ; opration.push_back(op-1); }
	for(int i = 1; i<=N ; i++) par[i] = i;

	findAns();

}
