#include<iostream>
using namespace std;

// Copy set bits in a range

void printinBit(int x){
    cout << x << " == ";
    for(int i = 9; i>=1 ; i--){
        if(x & 1<<(i-1)){
            cout << '1';
        }
        else{
            cout << '0';
        }
    }
    cout << endl;
}
void copySetBits(unsigned& x,unsigned y,int l,int r){

    unsigned mask = 1<<(r-l+1);
    mask = mask-1;
    mask = mask<<(l-1);
    y = y&mask;
    x = x|y;
}

// Driver code
int main()
{
   unsigned x = 10, y = 13, l = 2, r = 3;
   copySetBits(x, y, l, r);
   cout << "Modified x is " << x;
   return 0; 
}
