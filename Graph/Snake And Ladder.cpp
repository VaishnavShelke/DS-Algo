#include <iostream>
#include <bits\stdc++.h>
using namespace std;

// Snake And Ladder

int main()
{
    // Let us construct the board given in above diagram
    int N = 30;
    int moves[N];
    bool visited[N];
    int level[N];
    for (int i = 0; i<N; i++)
        {moves[i] = -1; visited[i] = false;}
  
	// Ladders
	moves[2] = 21;
	moves[11] = 29;

	// Snakes
	moves[22] = 10;


    int u = 0; level[0] = 0; visited[0] = true;
    queue<int> qu;
    qu.push(u); 


    while(!qu.empty()){
        u = qu.front();
        qu.pop();
        if(u == N-1) break;
        if(moves[u] != -1){
            if(!visited[moves[u]]) {level[moves[u]] = level[u]; qu.push(moves[u]); visited[moves[u]] = true;}
        }
        else{
            for(int i = 1; i<= 6; i++){
                if(u+i<N && !visited[u+i]) {qu.push(u+i); level[u+i] = level[u] + 1;visited[u+i] = true;}
                }
            }
        }
        cout << "Min Dice throws required is " << level[N-1];

}
