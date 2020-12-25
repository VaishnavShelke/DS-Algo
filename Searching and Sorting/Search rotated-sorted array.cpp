int searchrotatedarray(vector<int> arr,int r,int low, int high){
    if (high >= low){
        int mid = (low+high)/2;
        if (arr[mid] == r){
            return mid;
        }
        else if(r > arr[mid]){
            if (r <  arr[high]) return searchrotatedarray(arr,r,mid+1,high);

            else return searchrotatedarray(arr,r,low,mid-1);
        }
        else{
            if (r > arr[low]) return searchrotatedarray(arr,r,low,mid-1);

            else return searchrotatedarray(arr,r,mid+1,high);
}
}
    else return -1;
}
