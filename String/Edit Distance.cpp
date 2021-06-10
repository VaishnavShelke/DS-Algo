
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
	string str1 = "sunckdjcnday";
	string str2 = "satukcnsjdcnjrday";
 
    int arr1[str1.size()+1]; int arr2[str1.size()+1];
    int* Kn = arr1; int* Kp = arr2;int * temp;

    for(int j = 0; j<= str2.size(); j++){
        for(int i = 0; i<= str1.size(); i++){

            if(j == 0 && i == 0) Kn[i] = 0;
            else if(j == 0) Kn[i] = i;
            else if(i == 0) Kn[i] = j;
            else if(str2[j-1] == str1[i-1]) Kn[i] = Kp[i-1];
            else{
                Kn[i] = min(Kp[i-1],Kn[i-1]);
                Kn[i] = min(Kn[i],Kp[i]);
                Kn[i] = 1 + Kn[i];
            }
        }
        temp = Kn; Kn = Kp; Kp = temp;
    }

    for(int i = 0; i<= str1.size(); i++){
            cout << Kp[i] << " "; 
        }
        cout << endl;
    
 
    return 0;
}
