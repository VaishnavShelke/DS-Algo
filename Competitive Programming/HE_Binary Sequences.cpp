

// https://www.hackerearth.com/problem/algorithm/binary-sequences-779a58ba/similar_problems/

Int his problem we are given z zeroes and o ones,
we have to find the ways we can make a sequences such that the
length of non-decreasing subsequence in array is >= K;


Approach:
  Assume that our vector { size 0 } is empty:
We have a sack in which we have z zeroes and o ones
Now we can pick either a zero or one and append it to the list.....
  
  
  1. Suppose we pick a one and place it ->> Now we have in bag o-1 ones, z zeroes and size of non increasing is 0 + 1;
  2. Suppose we pick a zero and append it ->>
                Either the length of non increasing will not increse in that case we have o ones , z-1 zeroes and size as 0
                Or if the previous sequence before appending only have zeroes then the length will increas
                                                in that case we have o ones, z-1 zeroes and size as Z - z + 1{New Zero added}

                Which of the above two situations do we choose...
                  we choose max( len , Z - z + 1 ) why???
                  because if there are two situation where we have same sack specifications but the increasing subseq lenght is different,
    we go for the situation where the length is higher because that situation will include one with smaller length....
      
      
      

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int Z;
int K;
int dp[51][51][151];

int bag(int zero,int ones,int len){

	if(zero < 0 || ones < 0){
		return 0;
	}
	if(zero == 0 && ones == 0){
		if(len >= K) return 1;
		else return 0;
	}

	if(dp[zero][ones][len] != -1) return dp[zero][ones][len];

	int answer = bag(zero,ones-1,len+1);
	answer = answer + bag(zero-1,ones, max(len,Z-zero+1));
	dp[zero][ones][len] = answer%MOD;
	return answer%MOD;
}

int ways(int zero,int ones, int len){

	K = len;
	Z = zero;
	memset(dp,-1,sizeof(dp));
	dp[0][0][0] = 1;
	int answer = bag(zero,ones,0);
}


int main(){
	int tc;
	int z,o,k;
	cin >> tc;

	while(tc--){
		cin >> z >> o >> k;
		cout << ways(z,o,k) << endl;
	}
}


 
      
  
