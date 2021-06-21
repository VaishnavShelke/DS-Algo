#include <iostream>
#include<unordered_map>
using namespace std;
#define NIL 99999
#define min -9999
#define ROW 4
#define COL 4

// Largest area rectangle with sum of all its element as zero

pair<int,int> longestSAwithSum0(int* arr,int size){

    int sumArr[size+1];
    sumArr[0] = 0;int left,right;int maxDiff = min;
    left = min; right = min;
    for(int i = 0; i<size; i++){
        sumArr[i+1] = sumArr[i] + arr[i];
    }
    unordered_map<int,int> sumIndex;

    for(int i = 0; i<size+1 ; i++){
        if(sumIndex.find(sumArr[i]) == sumIndex.end()){
            sumIndex[sumArr[i]] = i;
        }
        else{
            if(maxDiff <= i - sumIndex[sumArr[i]]){
                left = sumIndex[sumArr[i]];
                right = i-1;
                maxDiff = i - sumIndex[sumArr[i]];
            }
        }
    }

    return {left,right};
}

void largestZeroSumBaseL(int l,int& maxRight,int& maxLeft,int& maxUp,int& maxBottom,int& maxSize,int mat[ROW][COL]){
    
    int sumArr[ROW];
    pair<int,int> upBottom;
    for(int i = 0; i<ROW ; i++) sumArr[i] = 0;
    for(int r = l; r<COL ; r++){
        for(int j = 0; j<ROW ; j++) sumArr[j] +=  mat[j][r];

        upBottom = longestSAwithSum0(sumArr,ROW);

        if(upBottom.first != min && upBottom.second != min && (r-l+1)*(upBottom.second-upBottom.first+1)>maxSize){
            maxRight = r;
            maxLeft = l;
            maxUp = upBottom.first;
            maxBottom = upBottom.second;
            maxSize = (r-l+1)*(upBottom.second-upBottom.first+1);
        }
    }

}

void largestZeroSum(int mat[ROW][COL]){

    int maxRight,maxLeft,maxUp,maxBottom,maxSize = -999999;

    for(int l = 0; l<COL ; l++){
        largestZeroSumBaseL(l,maxRight,maxLeft,maxUp,maxBottom,maxSize,mat);
    }

    cout << "The largest size sub Matrix with sum Zero is .... "<<endl;
    printf( "( %d, %d) --->> ( %d, %d)",maxUp,maxLeft,maxBottom,maxRight);

}

int main(){
    int mat[ROW][COL] =  {  { 9, 7, 16, 5 }, 
                            { 1, -6, -7, 3 },
                            { 1, 8, 7, 9 },
                            { 7, -2, 0, 10 } };
    
    largestZeroSum(mat);
    int arr[] = {16,-6,8,-2};
    pair<int,int> upBottom;
    upBottom = longestSAwithSum0(arr,4);
    return 0;
}
