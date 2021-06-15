#include <bits/stdc++.h>
using namespace std;

// Numeric Key Pad

bool isValid(pair<int,int> next){
    int j = next.first;
    int i = next.second;
    
    if( i < 0 || j < 0 || i>2 || j>3 ){
        return false;
    }
    if( i == 0 && j == 3) return false;
    if( i == 2 && j == 3) return false;
    return true;
}

void findNumbers(char keyPad[4][3],int N){

    int int_keypad[4][3];
    

    for(int j = 0; j<4 ; j++){
        for(int i = 0; i<3 ; i++){
            if(keyPad[j][i] != '*' && keyPad[j][i] != '#'){
                int_keypad[j][i] = (int)(keyPad[j][i] - '0');
            }
            else{
                int_keypad[j][i] = INT_MAX;
            }
        }
    }



    int moves[N+1][10];
    for(int i = 0; i<10 ;i++){
        moves[0][i] = 0;
        moves[1][i] = 1;
    }
    
    pair<int,int> steps[5] = {{1,0} , {-1,0} , {0,1} , {0,-1}, {0,0}};
    pair<int,int> next;
    int sum;
    
    int x,y;
    for(int j = 2; j<=N ; j++){
        for(int i = 0; i<10 ; i++){

            if( i == 0 ){
                moves[j][i] = moves[j-1][8] + moves[j-1][0];
            }
            else{
                x = (i-1)%3;
                y = (i-1)/3;
                sum = 0;
                for(int k = 0; k<5 ; k++){
                    next = {y + steps[k].first,x + steps[k].second};
                    if(isValid(next)){
                        sum += moves[j-1][int_keypad[next.first][next.second]];
                    }
                }
                moves[j][i] = sum;
            }
        }
    }
    
    for(int j = 0; j<=N ; j++){
        sum = 0;
        for(int i = 0; i<10 ; i++){
            sum += moves[j][i];
        }
        cout << sum << endl;
    }

    return ;

}

int main(){
    char keypad[4][3] = {'1','2','3','4','5','6','7','8','9','*','0','#'};
    findNumbers(keypad,5);
    return 0;
}
