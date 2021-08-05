typedef vector<vector<int>> vvv;
typedef vector<int> vv;

vector<pair<int,pair<int,int>>> v;
vv relset(100005);
int n,m;

int find_set(int v){
    int u = relset[v];
    if(u != v){
        u = find_set(u);
    }
    return u;
}

void merge_set(int a,int b){
    int p1 = find_set(a);
    int p2 = find_set(b);
    relset[p2] = p1;
}

int kruskal(){
    int cnt = 0;
    for(int i = 0; i<v.size() ; i++){
        int a = v[i].second.first;
        int b = v[i].second.second;
        if(find_set(a) != find_set(b)){
            cnt += v[i].first;
            merge_set(a,b);
        }
    }
    return cnt;
}



int Solution::solve(int A, vector<vector<int> > &B) {
	n = A;
	m = (int)B.size();
	v.clear();
	for (int i = 0; i < m; i++) {
		int x,y, cost;
		x = B[i][0];
		y = B[i][1];
		cost = B[i][2];
		v.push_back(make_pair(cost,make_pair(x,y)));
	}
    for (int i = 1; i <= A ; i++){
        relset[i] = i;
    }
	sort(v.begin(),v.end());
	return kruskal();
}
