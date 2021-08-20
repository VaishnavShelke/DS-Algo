#include<bits/stdc++.h>
using namespace std;

int kth[200005][23];

void buildTree(int emp){
      int k = log2(emp);

      for(int j = 1; j<= emp ; j++){
            for(int i = 1; i<= k+1 ; i++){
                  if(kth[j][i-1] != -1) kth[j][i] = kth[kth[j][i-1]][i-1];
                  else kth[j][i] = -1;
            }
      }
}


int main(){
      int emp,qu;
      cin >> emp;
      cin >> qu;
      memset(kth,-1,sizeof(kth));

      for(int i = 2; i<=emp ; i++)
            cin >> kth[i][0];
      
      buildTree(emp);

      int x, k;
      int i;
      while(qu--){
            cin >> x >> k;

            while(x != -1 && k){
                  i = floor(log2(k));
                  k -= 1 << i;
                  x = kth[x][i];
            }

            cout << x << endl;
      }

}
