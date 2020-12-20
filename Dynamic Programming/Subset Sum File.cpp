#include <iostream>
#include <vector>
using namespace std;

// FIND WETHER IS IT POSSIBLE TO MAKE THE GIVEN SUM USING THE AVALIABLE OPTIONS
/* There are two options for you to make
        either you consider the last option out of available options  opt -->> opt-1 && sum -->> sum - options[opt-1]
        or you simply ignore it;                                      opt -->> opt-1 && sum -->> sum;
*/        

int main(){
    int options[] = {3, 34, 4, 12, 5, 2};
    int t_sum = 31;
    int ava_options = sizeof(options)/sizeof(options[0]);
    bool canmake[ava_options+1][t_sum+1];

    for(int opt = 0; opt <= ava_options;opt++){
        for(int sum = 0; sum <= t_sum;sum++){
            if (sum == 0){canmake[opt][sum] = true; continue;}
            if (opt == 0){canmake[opt][sum] = false;continue;}

            if(sum-options[opt-1]>=0) canmake[opt][sum] = canmake[opt-1][sum] || canmake[opt-1][sum-options[opt-1]];
            else canmake[opt][sum] = canmake[opt-1][sum];

        }
    }
    cout << "So can we make " << t_sum << " with the given options of integers\n";
    cout << "And the answer is ......... " << canmake[ava_options][t_sum] << "\n\n";
    return 0;
}
