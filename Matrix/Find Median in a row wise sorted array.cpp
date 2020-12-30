#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


// Finding the median in a row wise sorted array
/*
    We begin by finding the minimum and the maximum element in the matrix
    1. We find the mid of the min-max and find its position in 
        { an otherwise sorted array having all elements of the matrix}
        each row using upper_bound function and add all those positions.
    2. If the obtained position is less than desired position
     increment min -->> mid + 1
               max -->> max
       Else
               min -->> min
               max -->> mid - 1

*/

const int N = 100;
// Finding a median in a roe wise sorted matrix
/*
Input : 1 3 5
        2 6 9
        3 6 9
*/
pair<int,int>* findminmax(int M[][N],int width,int height){
    int maxima = INT_MIN;
    int minima = INT_MAX;
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i = 0; i < height; i++){
        maxima = max(maxima,M[i][width-1]);
        minima = min(minima,M[i][0]);
    }
    pair<int,int>* p;
    pair<int,int> pr;
    pr = make_pair(minima,maxima);
    p =  &pr;
    return p;
}

int position(int (*M)[N],int width,int height,int mid){
    int pos = 0;

    for(int i = 0; i< height; i++){
        pos += upper_bound(M[i],M[i] + width,mid) - M[i];
    }
    return pos;

}

int main(){

    int matrix[][N] = {{1, 3, 4},
                        {4, 7, 100},
                        {1000, 1221, 132434}};

    int height  = 3;
    int width = 3;

    int desiredpos = (height*width + 1)/2;

    pair<int,int>* result;
    result = findminmax(matrix,width,height);
    int maxima = result->second;
    int minima = result->first;
    int mid;
    int pos;
    while(maxima > minima){
        mid = minima + (maxima - minima)/2;
        pos = position(matrix,width,height,mid);


        if(desiredpos > pos){
            minima = mid + 1;
            maxima = maxima;
        }
        else{
            maxima = mid-1;
            minima = minima;
        }
    }
    cout << "The median is ... " << minima;
    return 0;
}
