#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// The celebrity problem

int main(){
    int people = 4;
    int know[people][people] = { {0, 0, 1, 0},
                                 {0, 0, 1, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 1, 0} };
    int popular[people] = {};

    for(int j = 0; j<people ; j++){
        for(int i = 0; i<people ; i++){
            if(know[j][i] == 1){
                popular[i]++;
            }
        }
    }

    int mostpopular = max_element(popular,popular+people) - popular;
    for(int i = 0; i<people ; i++){
        if(know[mostpopular][i] == 1){
            cout << "No Celebrity";
            return 0;
        }
    }
    cout << "Celebrity Exists";
    return 0;
}
