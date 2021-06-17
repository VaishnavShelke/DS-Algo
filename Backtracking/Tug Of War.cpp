#include <bits/stdc++.h>
using namespace std;

// The Knight Tour Problem

bool isValid(int j,int i,int orderVisited[8][8]){

	if(i>=0 && j>=0 && i<8 && j<8 && orderVisited[j][i] == -1) return true;
	return false;
}

bool solveKT(int orderVisited[8][8],int j,int i,int rank){

    if(rank == 8*8){
	 	return true;
	}
    static pair<int,int> moves[] = {{1,2},{1,-2},{2,1},{2,-1},{-1,-2},{-1,2},{-2,1},{-2,-1}};
    int next_i,next_j;

    for(int k = 0; k<8 ; k++){
        next_j = j +  moves[k].first; next_i = i + moves[k].second;
        if(isValid(next_j,next_i,orderVisited)){
            orderVisited[next_j][next_i] = rank;
            if(solveKT(orderVisited,next_j,next_i,rank+1)){
                return true;
            }
            orderVisited[next_j][next_i] = -1;
        }
    }
    return false;
}



// Driver Code
int main()
{
      // Function Call
    int orderVisited[8][8];
    for(int i = 0; i<8 ; i++){
        for(int j = 0; j<8 ; j++){
            orderVisited[i][j] = -1;
        }
    }
    orderVisited[0][0] = 0;
    if(solveKT(orderVisited,0,0,1)){
        cout << "Solution exists ... "<< endl;
        for(int i = 0; i<8 ; i++){
            for(int j = 0; j<8 ; j++){
                cout << " " << std::setw(2) << orderVisited[i][j] << " ";
        }
		cout << endl;
        }
    }
    else{
        cout << "Solution does not exists ... ";
    }
    return 0;
}
