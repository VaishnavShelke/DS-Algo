#include<iostream>
#include<bits\stdc++.h>
using namespace std;
#define dim 5


/**
 * ! Given a sorted dictionary of an alien language, find order of characters 
 * !                        TOPOLOGICAL SORT                                  
 * // Can be done via array implementation of tree but then it will have some limitation
 * // for example the words should be such that is it precisely possible to make accurate placement of characters
**/
class Graph{
private:
    int nodes;
    unordered_map<char,vector<char>> graph; set<char> members;
public:
    Graph(int total) { this->nodes = total; }
    void addEdge(char u, char v){
        graph[u].push_back(v);
        if(members.find(u) == members.end()) members.insert(u);
        if(members.find(v) == members.end()) members.insert(v);

    }
    void topologicalSort(){
        stack<char> stc;
        set<char> visited;

        set<char> :: iterator itr = members.begin();

        while(itr != members.end()){
            if(visited.find(*itr) == visited.end()) DFS(&visited,&stc,*itr); itr++;
        }

        while(!stc.empty()){ cout << stc.top() << " "; stc.pop();}
    }
    void DFS(set<char>* visited,stack<char>* stc,char u){
        if(visited->find(u) != visited->end()) return;
        for(char child: graph[u]){
            DFS(visited,stc,child);
        }
        stc->push(u);visited->insert(u);
        return;
    }
};

pair<int,int> firstDispute(string w1,string w2);

void printOrder(string* words,int len,int total){
    Graph graph(total);
    pair<char,char> fD;
    for(int i = 1; i<len ; i++){
        fD = firstDispute(words[i-1],words[i]);
        if(fD.first != 'X'){
            graph.addEdge(fD.first,fD.second);
        }
    }
    graph.topologicalSort();
}
pair<int,int> firstDispute(string w1,string w2){
    int a = 0, b= 0;
    while(a<w1.size() && b<w2.size()){
        if(w1[a] != w2[b]) return(make_pair(w1[a],w2[b]));
        a++;b++;
    }
    return make_pair('X','X');
}

int main()
{
    string words[] = {"baa", "abcd", "abca", "cab", "cad"};
    printOrder(words, 5,4);
    return 0;
}
