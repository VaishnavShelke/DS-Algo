class Solution {
public:
    list<int>* adj[100005];
    int vist[100005];
    
    vector<int> bfs(int u){
        queue<int> qu;
        vector<int> comp;
        qu.push(u);
        while(!qu.empty()){
            u = qu.front();
            vist[u] = 1;
            qu.pop();
            comp.push_back(u);
            for(int v : *(adj[u])){
                if(vist[v] == -1){
                    vist[v] = 1;
                    qu.push(v);
                }
            }
        }
        return comp;
    }
    
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        memset(vist,-1,sizeof(vist));
        memset(adj,NULL,sizeof(adj));
        for(int i = 0; i<s.size() ; i++) adj[i] = new list<int>;
        vector<int> inx;
        string ans = s;
        vector<char> ss;
        for(int i = 0; i<pairs.size() ; i++) 
            adj[pairs[i][0]]->push_back(pairs[i][1]),adj[pairs[i][1]]->push_back(pairs[i][0]);
        
        for(int i = 0; i<s.size() ; i++){
            if(vist[i] == -1){
                ss.clear();
                inx = bfs(i);
                for(int j : inx) ss.push_back(s[j]);
                sort(ss.begin(),ss.end());
                sort(inx.begin(),inx.end());
                for(int j = 0 ;j<inx.size() ; j++)
                    ans[inx[j]] = ss[j];
            }
        }
        for(int i = 0; i<s.size() ; i++) delete adj[i];
        return ans;
    }
};
