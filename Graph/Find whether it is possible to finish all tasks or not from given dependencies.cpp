#include<iostream>
#include<bits\stdc++.h>
using namespace std;

/**Find whether it is possible to finish all tasks or not from given dependencies 
 If there cannot be any topological order of task there cannnot be possible to complete task with prerequisited
** And for a graph not to be topological it has to be Diercted Acyclic Graph
*!FOR A GRAPH TO BE DIRECT ACYCLIC IT HAS TO SATISFY KAHN ALGORITHM 
*? A directed acyclic graph is one in which if at any point we start we reacha definited end hence there is no cycle
*? so if there are n nodes then there should be exactly n legit starting points
*? and starting points necessarily have indegree == 1;
**/
class Graph{
private:
    int vertex;
    vector<int>* llist;
    int* indDegree;
public:

    Graph(int vertex){ this->vertex = vertex; llist = new vector<int>[vertex];
                       indDegree = new int[vertex];for(int i= 0;i<vertex; i++) indDegree[i] = 0;}
    void addEdge(int u,int v){
        llist[u].push_back(v);
        indDegree[v]++;
    }
    bool Dependencies(){
        queue<int> heads;
        for(int i = 0; i<vertex; i++){ if(indDegree[i] == 0) heads.push(i);}

        int count = heads.size();
        int parent;

        while(!heads.empty()){
            parent = heads.front(); 
            heads.pop();

            for(int child : llist[parent]){
                indDegree[child]--;
                if(indDegree[child] == 0) {count++;heads.push(child);}
            }
        }
        if(count == vertex) return true;
        else return false;

        
    }
    
};



// Driver Code
int main()
{
    // Create a graph given in the above diagram
    Graph g(7);
    g.addEdge(5, 3);
    g.addEdge(5, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 1);
    g.addEdge(3, 0);
    g.addEdge(3, 6);
    g.addEdge(1, 0);
    g.addEdge(6, 2);
 

    // Function Call
    if(g.Dependencies()) cout <<"Can finish all task....";
    else cout << "Cannot finish all task....";
 
    return 0;
}
