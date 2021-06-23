#include<iostream>
#include<queue>
using namespace std;

// Find smallest number with given number of digits and sum of digits 

void findSmallest(int digits,int digSum){

    int arr[digits];
    arr[0] = 1; digSum--;
    for(int i = 1; i<digits ; i++) arr[i] = 0;
    int factor = 1;
    int num = 0;
    for(int i = digits-1; i>= 0; i--){
        if(digSum>=9){
            arr[i] = 9;
            digSum = digSum-9;
        }
        else{
            if(digSum != 0) {arr[i] = digSum;
                            digSum = 0;}
        }
        num  = num + arr[i]*factor;
        factor = factor*10;
    }
    cout << num;
    
} 
int main()
{
    int s = 11, m = 9;
    findSmallest(m, s);
    return 0;
}
