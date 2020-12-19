
/* Observatin approach to solve this problem
   Notice that the consecutive integers follow a pattern 
   of reoccurence of 1s and 2s in vertical fasion*/

int main(){
    int upto = 10000;
    int i = 1;
    int cnt = 0;
    upto += 1;
    while (upto / (int)pow(2,i-1) > 0){
        cnt += (upto/(int)pow(2,i))*(int)pow(2,i-1);
        if (upto % (int)pow(2,i) > (int)pow(2,i-1)) cnt += upto % (int)pow(2,i) - (int)pow(2,i-1);
        else cnt = cnt;
        i++;
    }
    cout << "The total number of bits are: " << cnt;
    return 0;
}
