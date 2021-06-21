#include <iostream>
#include<unordered_set>
using namespace std;
 
// Check if the two strings are interleaved or not

void test(string A,string B,string AB){

    bool arr1[B.size()+1];
    bool arr2[B.size()+1];
    bool *isInterleavedNow = arr1;
    bool *isInterleavedBack = arr2;
    bool *temp;
    isInterleavedNow[0] = true;
    for(int j = 0; j<=A.size() ; j++){
        for(int i = 0; i<=B.size() ; i++){
            
            if(i == 0 && j == 0) continue;
            if(j == 0){
                if(B[i-1] == AB[i-1]) isInterleavedNow[i] = isInterleavedNow[i-1];
                else{
                    isInterleavedNow[i] = false;
                }
                continue;
            }
            if(i == 0){
                if(A[j-1] == AB[j-1]) isInterleavedNow[i] = isInterleavedBack[i];
                else{
                    isInterleavedNow[i] = false;
                }   
                continue;             
            }

            if(AB[i+j-1] == A[j-1] || AB[i+j-1] == B[i-1]){
                if(AB[i+j-1] == A[j-1] && AB[i+j-1] == B[i-1]){
                    isInterleavedNow[i] = isInterleavedBack[i] || isInterleavedNow[i-1];
                }
                else if(AB[i+j-1] == A[j-1]){
                    isInterleavedNow[i] = isInterleavedBack[i];
                }
                else{
                    isInterleavedNow[i] = isInterleavedNow[i-1];
                }
            }
            else{
                isInterleavedNow[i] = false;    
            }
            temp = isInterleavedNow;
            isInterleavedNow = isInterleavedBack;
            isInterleavedBack = temp;
        }
    }
    
    cout << isInterleavedBack[B.size()] << endl;
}

int main()
{
    test("XXY", "XXZ", "XXZXXXY");
    test("XY", "WZ", "WZXY");
    test("XY", "X", "XXY");
    test("YX", "X", "XXY");
    test("XXY", "XXZ", "XXXXZY");
    return 0;
}

