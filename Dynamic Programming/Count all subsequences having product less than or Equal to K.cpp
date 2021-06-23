#include<iostream>
#include<vector>

int productSubSeqCount(std::vector<int>& arr,int k){
    int size = arr.size();
    int prod = k;
    int subSequences[size+1][prod+1];

    for(int j = 0; j<=size ; j++){
        for(int i = 0; i<=prod ; i++){
            if(j == 0) {subSequences[j][i] = 0; continue;}
            if(i == 0) {subSequences[j][i] = 0; continue;}
            if(arr[j-1]>i){
                subSequences[j][i] = subSequences[j-1][i];
            }
            else{
                subSequences[j][i] = subSequences[j-1][i] + 1 + subSequences[j-1][i/arr[j-1]];
            }
        }
    }
    return subSequences[size][k];

}
// Driver code
int main()
{
    std::vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int k = 10;
    std::cout << productSubSeqCount(A, k) << std::endl;
}
