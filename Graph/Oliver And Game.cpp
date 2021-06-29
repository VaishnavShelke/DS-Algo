#include<iostream>
#include<list>
#include<vector>
using namespace std;


class Graph{
private:
    int V;
    list<int>* adj;
    int timer;
public:
    Graph(int V){ this->V = V; adj = new list<int>[V+1]; timer = 0;}
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }

    void fishingnet(int u,bool* visited,int* startTime,int* endTime,int& timer){

        startTime[u] = timer++;
        visited[u] = true;
        for(int v : adj[u]){
            if(!visited[v]){
                fishingnet(v,visited,startTime,endTime,timer);
            }
        }
        endTime[u] = timer++;
        
    }   

};

int main(){
	int houses;
	cin>>houses;

    Graph tree(houses);
	int u,v;
	for(int i = 0; i<houses-1; i++){
        cin>>u>>v;
        tree.addEdge(u,v);
	}

    int startTime[houses+1];
    int endTime[houses+1];
    int timer = 0;
    bool visited[houses+1];
    for(int i = 0; i<= houses ; i++){
        visited[i] = false;
    }
    tree.fishingnet(1,visited,startTime,endTime,timer);
    cout << endl;

    int queries;
    cin>>queries;
    int x,y,dir;
    while(queries){
        cin >> dir >> x >> y;

        if(dir == 0){
            if(startTime[x] < startTime[y] && endTime[x] > endTime[y])
                cout << "YES";
            else    cout << "NO";
        }
        else{
            if(startTime[y] < startTime[x] && endTime[y] > endTime[x]){
                cout << "YES";
            }
            else cout << "NO";
        }
        cout << endl;
        queries--;
    }

}



