#include <iostream>
#include <bits\stdc++.h>

using namespace std;

//  Finding Largest rectangle in a matrix + Finding the largest rectangular area under the histogram

class build{
    public:
    int left,right,value;
};

int Histogram_rectangle(int* arr,int length){

    vector<build> stak;
  
    build buildings[length];
    for(int i = 0; i<length; i++){
        buildings[i].left = i;
        buildings[i].right = i+1;
        buildings[i].value = arr[i];
    }

    stak.push_back(buildings[0]);
    int maxima = INT_MIN;
    build temp;

    for(int i = 1; i<length ; i++){

        while(buildings[i].value < stak.back().value && !stak.empty()){
            temp = stak.back();
            stak.pop_back();

            maxima = max(maxima,temp.value*(temp.right - temp.left));

            if(!stak.empty()){
                stak.back().right = temp.right;
                buildings[i].left = temp.left;
            }
        }
        
       
        stak.push_back(buildings[i]);

    }

    while(!stak.empty()){
        temp = stak.back();
        stak.pop_back();

        maxima = max(maxima,temp.value*(temp.right - temp.left));

        if(!stak.empty()){
                stak.back().right = temp.right;
            }
    }

    return maxima;
}

int main(){

    int bin[][5] = {
   {1, 1, 1, 1, 1},
   {1, 1, 1, 1, 1},
   {0, 1, 1, 0, 0},
   {1, 1, 1, 1, 1},
};

    int histogram[5];
    for(int i = 0; i<5 ; i++){
        histogram[i] = bin[0][i];
    }
    
    int maxima = Histogram_rectangle(histogram,5);

    for(int i = 1; i<4 ; i++){
        for(int j = 0; j<5 ; j++){
            if(bin[i][j] == 0) histogram[j] = 0;
            else{
                histogram[j] = 1 + histogram[j];
            }
        }

        maxima = max(maxima, Histogram_rectangle(histogram,5));
        
    }

    cout << "Maximum area Rectangle in Binary Matrix is " << maxima;
    return 0;
}
