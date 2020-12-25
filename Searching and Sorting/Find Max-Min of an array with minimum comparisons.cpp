#include <iostream>
#include <vector>
using namespace std;
#include<map>
#include<algorithm>
#include<typeinfo>
pair<int,int> minmaxfinder(vector<int> arr,int low,int high){

    int mid = (low + high)/2;
    pair<int,int> pair1,pair2,result;

    if (low == high){
        result = make_pair(arr[low],arr[high]);
        return result;
    }

    pair1 = minmaxfinder(arr,low,mid);
    pair2 = minmaxfinder(arr,mid+1,high);
    result = make_pair(min(pair1.first,pair2.first),max(pair1.second,pair2.second));
    return result;


}
