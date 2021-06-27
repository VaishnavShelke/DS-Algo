class Graph{
private:
    int V;
public:
    list<pair<int,int>>* adj;
    void DFSuntilK(int u,int depth,int cost,bool* visited,int& minPrice,int k,int destination);
    Graph(int V){
        adj = new list<pair<int,int>>[V]; this->V = V;
    }
    void addEdge(int u,int v,int w){
        adj[u].push_back({v,w});
    }
};

void Graph :: DFSuntilK(int u,int depth,int cost,bool* visited,int& minPrice,int k,int destination){

    //if(cost>minPrice) return;  // Just Unlocking this small piece of code increases the number of test cases passed from 39 to 47 !!!!!
    if(depth > k+1){
        return;
    }
    if(u == destination){
        minPrice = min(minPrice,cost);
        return;
    }

    for(auto v = adj[u].begin() ; v != adj[u].end() ; v++){
        if(!visited[v->first]){
            visited[v->first] = true;
            DFSuntilK(v->first,depth+1,cost+v->second,visited,minPrice,k,destination);
            visited[v->first] = false;
        }
    }
    return;
}

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

    Graph paths(n);

    bool visited[n];

    for(int i = 0 ; i<flights.size() ; i++){
        paths.addEdge(flights[i][0],flights[i][1],flights[i][2]);
    }     

    for(int i = 0; i<n ; i++) visited[i] = false;

    int minPrice = 99999;

    visited[src] = true;
    paths.DFSuntilK(src,0,0,visited,minPrice,k,dst);
    if(minPrice == 99999){return -1;}
    return minPrice;
    }
};
