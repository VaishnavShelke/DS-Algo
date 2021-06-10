#include <iostream>
#include <bits\stdc++.h>
using namespace std;
#define N 9

// THE GAME OF EQUALLY SMARTS.....
// We can observe that A wins game for n coins only when B loses for coins n-1 or n-x or n-y. 

bool iPlayToWin(int x,int y,int remaining,int* memo){
    if(remaining == 1) return true;
    if(remaining == 0) return false;
    if(memo[remaining] != INT_MAX) return memo[remaining];
    if(remaining<min(x,y)){
        memo[remaining]  = !iPlayToWin(x,y,remaining-1,memo);
        return memo[remaining];
    }
    else if(remaining<max(x,y)){
        memo[remaining] = !iPlayToWin(x,y,remaining-1,memo) || !iPlayToWin(x,y,remaining-min(x,y),memo);
        return memo[remaining];
    }
    else{
        memo[remaining] = !iPlayToWin(x,y,remaining-1,memo) || !iPlayToWin(x,y,remaining-x,memo) || !iPlayToWin(x,y,remaining-y,memo);
        return memo[remaining];
    }
}

bool findWinner(int x,int y,int n){

    int memo[n+1];
    for(int i = 0 ; i<=n ; i++) memo[i] = INT_MAX;
    return iPlayToWin(x,y,n,memo);
}
int main()
{
    int x = 3, y = 5, n = 9;
  for(int i = 0; i<15 ; i++){
	if (findWinner(x, y, i))
		cout << 'A';
	else
		cout << 'B';
  }
 
    return 0;
}
