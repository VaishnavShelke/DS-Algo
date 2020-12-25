int firstoccurence(vector<int> arr,int r,int low,int high);
int lastoccurence(vector<int> arr,int r,int low,int high);

int firstoccurence(vector<int> arr,int r,int low,int high){
    if (low >= high){
        return 10000;
    }
    int mid = (low + high+1)/2;
    if ((mid == 0 || arr[mid-1]<r) && (arr[mid] == r)){
        return mid;
    }
    else if ( arr[mid] < r){
        return firstoccurence(arr,r,mid+1,high);
    }
    else{
        return firstoccurence(arr,r,low,mid-1);
    }
}

int lastoccurence(vector<int> arr,int r,int low,int high){
    if (low >= high){
        return 10000;
    }
    int mid = (low + high+1)/2;
    if ((mid == 0 || arr[mid+1]>r) && (arr[mid] == r)){
        return mid;
    }
    else if ( arr[mid] < r){
        return lastoccurence(arr,r,low,mid-1);
    }
    else{
        return lastoccurence(arr,r,mid+1,high);
    }
}
