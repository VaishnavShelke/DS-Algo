
int findsquareroot(int number,int low, int high){
    if (high>low){
        int mid = (low + high)/2;

        if (mid*mid == number) return mid;
        else if (mid*mid <number) return findsquareroot(number,low,mid-1);
        else return findsquareroot(number,mid+1,high);
    }
    else return low;
}


int main(){
    int r = 101;
    cout << findsquareroot(r,1,100);
 }


