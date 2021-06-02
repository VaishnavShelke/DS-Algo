#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Floyd Warshall Algorithm


int main(){
    int dist[][5] = {{ 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
                     { INT_MAX, 0, 3, INT_MAX, 7},
                     { INT_MAX, 8, 0, 2, INT_MAX},
                     { INT_MAX, 5, INT_MAX, 0, 1},
                     { INT_MAX, 2, INT_MAX, INT_MAX, 0}};
    
    cout <<"The graph is ..... \n";
  
    for(int j = 1; j<5 ; j++){
            for(int i = 1; i<5 ; i++){
                cout << dist[j][i] << "  ";
            }
            cout << endl;
    }

    for(int k = 1; k < 5 ; k++ ){
        for(int j = 1; j<5 ; j++){
            for(int i = 1; i<5 ; i++){
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INT_MAX
                       && dist[i][k] != INT_MAX))
                   dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    cout << "\n\n Finally the shrtest pathe amongst themselves is .... "<< endl;
    for(int j = 1; j<5 ; j++){
            for(int i = 1; i<5 ; i++){
                cout << dist[j][i] << "  ";
            }
            cout << endl;
    }
}
