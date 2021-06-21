# include <iostream>
using namespace std;
#define NA 696969

// Samllest Length Subarray With sum greater than Given value 

int smallestSubWithSum(int* arr,int n,int x){

    int smallestLen = NA;
    int len = 0;

    int bag = 0;

    for(int i = 0; i<n ; i++){
        if(bag + arr[i] <= 0){
            bag = 0; len = 0;
        }
        else{
            bag = bag + arr[i];
            len++;
        }
        if(bag>x){
            while(bag>x){
                bag -= arr[i-len+1]; len--;
            }
            smallestLen = min(smallestLen,len+1);
        }
    }
    return smallestLen;
}


/* Driver program to test above function */
int main()
{
    int arr1[] = {1, 2, 4};
    int x = 8;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int res1 = smallestSubWithSum(arr1, n1, x);
    (res1 == n1+1)? cout << "Not possible\n" :
                    cout << res1 << endl;
 
    int arr2[] = {1, 10, 5, 2, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    x  = 9;
    int res2 = smallestSubWithSum(arr2, n2, x);
    (res2 == n2+1)? cout << "Not possible\n" :
                    cout << res2 << endl;
 
    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    x  = 280;
    int res3 = smallestSubWithSum(arr3, n3, x);
    (res3 == n3+1)? cout << "Not possible\n" :
                    cout << res3 << endl;
 
    return 0;
}
