#include<bits/stdc++.h>
using namespace std;
  
struct GraphNode
{
    int val;
    vector<GraphNode*> neighbours;
};
  
GraphNode *buildGraph()
{
    /*
        Note : All the edges are Undirected
        Given Graph:
        1--2
        | |
        4--3
    */
    GraphNode *node1 = new GraphNode();
    node1->val = 1;
    GraphNode *node2 = new GraphNode();
    node2->val = 2;
    GraphNode *node3 = new GraphNode();
    node3->val = 3;
    GraphNode *node4 = new GraphNode();
    node4->val = 4;
    vector<GraphNode *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbours = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbours = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbours = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbours = v;
    return node1;
}

GraphNode* cloneNode(GraphNode* parent){
    GraphNode* clone = new GraphNode;
    clone->val = parent->val;
    return clone;
} 

GraphNode* cloneGraph(GraphNode* src){

    unordered_set<GraphNode*> visited;
    visited.insert(src);
    queue<GraphNode*> qu,parallelQu;
    GraphNode* u,*Parclone,*clone,*childClone;
    Parclone = cloneNode(src);
    clone = Parclone; 
    parallelQu.push(clone);
    qu.push(src);

    while(!qu.empty()){
        u = qu.front();
        qu.pop();
        clone = parallelQu.front();
        parallelQu.pop();

        for(auto v: u->neighbours){
            if(visited.find(v) == visited.end()) {
                childClone = cloneNode(v);
                clone->neighbours.push_back(childClone);
                visited.insert(v);
                qu.push(v);
                parallelQu.push(childClone);
            }
        }
    }
    return Parclone;
}

void bfs(GraphNode *src)
{
    map<GraphNode*, bool> visit;
    queue<GraphNode*> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        GraphNode *u = q.front();
        cout << "Value of Node " << u->val << "\n";
        cout << "Address of Node " <<u << "\n";
        q.pop();
        vector<GraphNode *> v = u->neighbours;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (!visit[v[i]])
            {
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    cout << endl;
}



int main()
{
    GraphNode *src = buildGraph();
    cout << "BFS Traversal before cloning\n";
    bfs(src);
    GraphNode *newsrc = cloneGraph(src);
    cout << "BFS Traversal after cloning\n";
    bfs(newsrc);
    return 0;
}
