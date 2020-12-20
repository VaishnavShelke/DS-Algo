#include <iostream>
#include <vector>
using namespace std;

//  FINDING THE NTH CATALAN NUMBER YOUSING THE STEP-UP OR STEP-FRONT WITHOUT CROSSING THE
//  DIAGONAL BOUNDRY APPROACH......
/*  Imagine a 3 cross 3 grid with the leftmost-bottommost vertices as the starting point
    (0,0) now you have to reach (3,3) sucht that,
    1. You can travel only up or right only
    2. And you cannot cross the diagonal y - x > 0
    ~ This is the appproach number one to find the nth catalan and the
    intuition comes from the problem of the possible combination of balanced paranthesis
    given the number of pairs of paranthests to be used
    
    ex: 3 pairs --->>> possible combination -->>  ((())),()()(),(()()),(())(),()(());
*/
int main(){
    int n_cat = 6;
    int route[n_cat+1][n_cat+1];

    for (int y_leap = 0;y_leap <= n_cat;y_leap++){
        for (int x_leap = 0;x_leap <= n_cat;x_leap++){
            if (y_leap>x_leap) {route[y_leap][x_leap] = 0; continue;}
            if (y_leap == 0) {route[y_leap][x_leap] = 1; continue;}

            route[y_leap][x_leap] = route[y_leap][x_leap-1] + route[y_leap-1][x_leap];
        }
    }
    cout << "We have to fin the catalan for " << n_cat <<"\n";
    cout << "The catalan number for the given nt is :" << route[n_cat][n_cat] ;
    return 0;
}
