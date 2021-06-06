#include<iostream>
#include<bits\stdc++.h>
using namespace std;

class grp{
    private: int vertices; vector<int>* tre;
    public: 
        int totEdge; 
        grp(int vertex){ vertices = vertex; tre = new vector<int>[vertices]; totEdge = 0;}
        void addEdge(int u,int v){
            tre[u].push_back(v); tre[v].push_back(u);
            totEdge++;
        }
        void removeRecent(int u,int v){
            tre[u].pop_back();tre[v].pop_back();
            totEdge--;
        }
        bool cycle(int u,bool* visited,int *parent){
            if(visited[u]) return true;
            visited[u] = true;
            for(int child : tre[u]){
                if(child != parent[u]){
                    parent[child] = u;
                    if(cycle(child,visited,parent)) return true;}
            }
            return false;
        }
 
        bool checkCycle(int u){
            bool visited[vertices]; int parentChart[vertices];

            for(int i = 0; i<vertices ; i++) {visited[i] = false; parentChart[i] = i;}
            return cycle(u,&visited[0],&parentChart[0]);
        }

};
class Node{
public:
    int src;int des;int wt;
    Node(){}
    Node(int src,int des,int wt){this->src = src; this->des = des; this->wt = wt;}
};

bool comparers(Node n1, Node n2){
        if(n1.wt > n2.wt) return false;
        else return true;
    }
void sortByWt(Node* edge,int vertex){
        sort(edge,edge+vertex, comparers);
    }


class Graph{
private: 
    int vertex;
    Node* edge;
    int edges;int i;
public: 
    Graph(int nodes,int edges){ vertex = nodes; edge = new Node[edges]; this->edges = edges; i = 0;}
    void addEdge(int src,int des,int wt){
        edge[i] = {src,des,wt};
        i++;
    }

    void kruskalsMST(){
        sortByWt(edge,edges);
        for(int i = 0; i<edges; i++){ cout << edge[i].src << " ---> " << edge[i].des << " === " << edge[i].wt << endl;}
        cout << endl << endl;
        int count = 0;
        grp connections(vertex);
        int cost = 0;
        cout << "MST Graph ...\n"; 
        for(int i = 0; i<edges ;i++){
            connections.addEdge(edge[i].src,edge[i].des);
            if(connections.checkCycle(edge[i].src)){
                connections.removeRecent(edge[i].src,edge[i].des);
            }
            else{
                cout << edge[i].src << " ---> " << edge[i].des << " === " << edge[i].wt << endl;
                count++;
                cost += edge[i].wt;
                if(count == vertex-1){break;}
            }
        }
        cout << "Total Cost of the tree .... " << cost;
        return;
    }
};



int main(){
    Graph graph(9,14);

    graph.addEdge(7,6,1);
    graph.addEdge(6,5,2);
    graph.addEdge(2,5,4);
    graph.addEdge(2,3,7);
    graph.addEdge(0,7,8);
    graph.addEdge(3,4,9);
    graph.addEdge(1,7,11);
    graph.addEdge(8,2,2);
    graph.addEdge(0,1,4);
    graph.addEdge(8,6,6);
    graph.addEdge(7,8,7);
    graph.addEdge(1,2,8);
    graph.addEdge(5,4,10);
    graph.addEdge(3,5,14);

    graph.kruskalsMST();
}
/*
Weight   Src    Dest
1         7      6
2         8      2
2         6      5
4         0      1
4         2      5
6         8      6
7         2      3
7         7      8
8         0      7
8         1      2
9         3      4
10        5      4
11        1      7
14        3      5 */
