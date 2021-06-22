#include<iostream>
using namespace std;

// Power Set

class gfg{
public:
    void printPowerSet(char* set,int n){
        
        for(int counter = 0; counter< (1<<n) ; counter++){
            for(int i = 1; i<= n ;i++){
                if(counter&(1<<(i-1))){
                    cout << set[i-1];
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    gfg g;
    char set[] = {'a','b','c'};
    g.printPowerSet(set, 3);
    return 0;
}
