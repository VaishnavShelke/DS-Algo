#include <bits/stdc++.h>
using namespace std;

// The tug of war Problem

int findSum(vector<int> arr){
	int sum = 0;
	for(int i = 0; i<arr.size() ; i++){
		sum += arr[i];
	}
	return sum;
}

void mytugOfWar(int* arr,int base,int n,vector<int> firstSet,vector<int> secondSet,vector<int>* answer){


	static int mainima = INT_MAX;
	if(base == n){
		int firstSetSum = findSum(firstSet);
		int secondSetSum = findSum(secondSet);
		if(abs(firstSetSum-secondSetSum) < mainima){
			answer[0] = firstSet;
			answer[1] = secondSet;
			mainima = abs(firstSetSum-secondSetSum);
		}
		return;
	}

	if(n%2 == 0){
		if(firstSet.size() < n/2){
			firstSet.push_back(arr[base]);
			mytugOfWar(arr,base+1,n,firstSet,secondSet,answer);
			firstSet.pop_back();
		}
		if(secondSet.size() < n/2){
			secondSet.push_back(arr[base]);
			mytugOfWar(arr,base+1,n,firstSet,secondSet,answer);
			secondSet.pop_back();
		}

	}
	else{
		if(firstSet.size() < (n+1)/2){
			firstSet.push_back(arr[base]);
			mytugOfWar(arr,base+1,n,firstSet,secondSet,answer);
			firstSet.pop_back();
		}
		if(secondSet.size() < (n+1)/2){
			secondSet.push_back(arr[base]);
			mytugOfWar(arr,base+1,n,firstSet,secondSet,answer);
			secondSet.pop_back();
		}
	}
	return;
}



void tugOfWar(int* arr,int n){
	vector<int> firstSet;
	vector<int> secondSet;
	vector<int> answer[2];
	mytugOfWar(arr,0,n,firstSet,secondSet,answer);
	
	cout << "First Set ... " ;
	for(int i = 0; i<answer[0].size() ; i++){
		cout << answer[0][i] << " ";
	}
	cout << endl<< "Second Set ... ";
	for(int i = 0; i<answer[1].size() ; i++){
		cout << answer[1][i] << " ";
	}

}




// Driver program to test above functions
int main()
{
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    tugOfWar(arr, n);
    return 0;
}
