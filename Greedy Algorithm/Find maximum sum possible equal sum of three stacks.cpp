#include <bits/stdc++.h>
using namespace std;

int maxSum(int* stc1,int* stc2,int* stc3,int size1,int size2,int size3){

    int sum1 = 0, sum2 = 0, sum3 = 0;

    for(int i = 0; i<size1 ; i++){ sum1 += stc1[i];}
    for(int i = 0; i<size2 ; i++){ sum2 += stc2[i];}
    for(int i = 0; i<size3 ; i++){ sum3 += stc3[i];}

    int top1 = 0, top2 = 0, top3 = 0;

    while(1){
        while(sum1 != sum2){
            if(top2 > size2 || top1 > size1) return 0;
            if(sum1>sum2){
                sum1 -= stc1[top1];
                top1++;
            }
            else{
                sum2 -= stc2[top2];
                top2++;
            }
        }
        while(sum2 != sum3){
            if(top2 > size2 || top3 > size3) return 0;
            if(sum2>sum3){
                sum2 -= stc2[top2];
                top2++;
            }
            else{
                sum3 -= stc3[top3];
                top3++;
            }
        }

        if(sum3 == sum2 && sum1 == sum3){
            return sum3;
        }
    }
}


int main()
{
    int stack1[] = { 3, 2, 1, 1, 1 };
    int stack2[] = { 4, 3, 2 };
    int stack3[] = { 1, 1, 4, 1 };
 
    int n1 = sizeof(stack1) / sizeof(stack1[0]);
    int n2 = sizeof(stack2) / sizeof(stack2[0]);
    int n3 = sizeof(stack3) / sizeof(stack3[0]);
 
    cout << maxSum(stack1, stack2, stack3, n1, n2, n3)
         << endl;
    return 0;
}
