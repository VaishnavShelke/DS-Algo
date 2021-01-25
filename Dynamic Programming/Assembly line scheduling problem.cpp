# include <iostream>

// Assembly line scheduling problem

int main(){
    int workstation[][4] = { { 4, 5, 3, 2 }, 
                   { 2, 10, 1, 4 } }; 
    int transfer[][4] = { { 0, 7, 4, 5 }, 
                   { 0, 9, 2, 8 } }; 
    int entry[] = { 10, 12 }, exit[] = { 18, 7 }; 

    int stations = sizeof(workstation[0])/sizeof(workstation[0][0]);
    int timeupto[2][4];

    // Important fillers ...
    timeupto[0][0] = entry[0];
    timeupto[1][0] = entry[1];

    
    for(int i = 1; i<stations; i++){
            for(int j = 0; j<2 ; j++){
                timeupto[j][i] = min(timeupto[abs(j-1)][i-1] + workstation[abs(j-1)][i-1] + transfer[abs(j-1)][i],
                                        timeupto[j][i-1] + workstation[j][i-1]);
            }
    }
    
    // Important additions
    timeupto[0][stations-1] += exit[0] + workstation[0][stations-1];
    timeupto[1][stations-1] += exit[1] + workstation[1][stations-1];

    cout << "Min time to produce a car is ... " << min(timeupto[0][stations-1],timeupto[1][stations-1]);
    return 0;

}
