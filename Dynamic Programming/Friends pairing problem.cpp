#include <iostream>
#include <vector>
using namespace std;

// TO MAKE POSSIBLE PAIR OF TWO OR SINGLE WITH GIVEN POPULATION
/*  There are two possible options for the entry of one person to the population 
        1. Either he can remain single -->> In that case the total combination will remain as same as that previous population
        2. Or he can pair with any one from the previous population -->> In that case
                                    the total number of combinations will be (n-1)*total combinations possible
                                    with the new population minus newly formed pair
    You can add 2 and 3 as both are mutually exclusive events
*/

int main(){
    int t_friends = 4;
    int pos_comb[t_friends+1];
    pos_comb[0] = 1;
    pos_comb[1] = 1;

    for (int pop = 2;pop <= t_friends; pop++){
        pos_comb[pop] = pos_comb[pop-1] + (pop-1)*pos_comb[pop-2];
    }
    cout << "Total possible combinations with " << t_friends << " friends is .... " << pos_comb[t_friends];
    return 0;
}
