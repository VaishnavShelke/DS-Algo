#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Find the max sum such that no two elements considered are maximum
/*
    SPECIAL TYPE OF DYNAMIC PROGRAMMING

    So let us say we are sinning at some ith element
        There are two things that we migh want to do 
            1. Add/Include the element to the basket
                We call that sum storing container as current_including
                    We know that :- current INCluding == previous EXCluding + arr[i];
            2. Suppose we do not want that element
                What we do is
                 current excluding == max of previous including or previous excluding
            3. Now since we will be moving to the next element;
                The current incl/excl will become previous incl/excl RESPECTIVELY to the new
                index element;
            4. after loop is over return 
                Max(including last,excluding last) // You see this value by itself is useless if
                            We go by traditional DP approach
                            Because we dont reallly know in our optimal substructure whether 
                            the previous optimal solution includes or excludes previous element
                Thats why we had to break this problem into 2 DP problem
                to prevent loss of data/state of prev element{included or not}
*/
/*
        This is dynamic because.....
            1. Overlapping subproblem :-
                Since current are derived from previous
            2. Optimal Substructure :-
                Optimal solution from Optimal Solutions

                In a regular DP problem we find we have one variable for which we find
                Optimal solution

                But here we find optimal solution for two
                MAX including current  {Derived from MAX excluding prev}
                MAX excluding current   { Derived from previous excluding And Previous including}
*/

int main(){
    int arr[] = {5, 5, 10, 100, 10, 5};
    int len = sizeof(arr)/sizeof(arr[0]);

    int MS_incl_prev = 5;
    int MS_excl_prev = 0;
    int MS_incl_current;
    int MS_excl_current;
    for(int i = 1;i<len;i++){
        MS_incl_current = MS_excl_prev + arr[i]; 
        MS_excl_current = max(MS_incl_prev,MS_excl_prev);
        MS_incl_prev = MS_incl_current;
        MS_excl_prev = MS_excl_current;
    }

    cout << "The maximum possible sum is ... " << max(MS_incl_prev,MS_excl_prev);
    return 0;
}
