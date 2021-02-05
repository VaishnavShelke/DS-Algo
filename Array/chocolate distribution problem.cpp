#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Chocolate distribution problem

int main(){
    int chockquant[] = {12, 4, 7, 9, 2, 23, 25, 41, 
                        30, 40, 28, 42, 30, 44, 48, 
                        43, 50};
    int children = 7;
    int packet = sizeof(chockquant)/sizeof(chockquant[0]);

    sort(chockquant,chockquant + packet);
    int minima = 10e6;
    for(int i = children - 1; i<packet; i++){
        if(chockquant[i] - chockquant[i-(children-1)] < minima)
            minima = chockquant[i] - chockquant[i-(children-1)];
    }
    cout << "The minimum wealth distribution is ... "<< minima << "\n";
    return 0;

}
