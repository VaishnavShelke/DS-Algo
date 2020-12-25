int findfixedpoint(vector<int> arr,int low,int high){
        if (low >= high){
            int mid = (low+high)/2;
            if (arr[mid] == mid){
                return mid;
            }
            else if (arr[mid]>mid){
                return findfixedpoint(arr,low,mid-1);
            }
            else{
                return findfixedpoint(arr,mid+1,high);
            }
        }
        else{
            return -1;
        }
}
