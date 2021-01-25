# include <iostream>

// Count the Total number of ways to paint the fence such that not more than two consecutive have same colour 
// THE PREVIOUS STATE IS BINARY PROBLEM
/*
    New variety of problem where the previous state which is binary is required

    Le us say some number N, upto this all fences are painted.
    Now there are two possibilities
    1. The Nth is painted same as the previous..
        in that case we have to paint N+1 in some different colour i.e (options-1)*no of ways such that N is repeated
    
    2. The Nth is not painted the same as the previous..
        in that case we CAN paint N+1 in same colour i.e 1*no of ways such that N is single

        or we can painr N+1 in some different colour i.e (options-1)* no of ways such that N is single

    After performing the two steps as given above 
    we have...

        no of ways such that N+1 is repeated == 1*no of ways such that N is single

        no of ways such that N+1 is single == (options-1)*no of ways such that N is repeated 
                                                            + (options-1)* no of ways such that N is single

*/


int main(){
    int posts = 5;
    int colours = 3;

    int previous_is_single = colours;
    int previous_is_double = 0;
    int now_is_single,now_is_double;

    for(int i = 1; i<posts ; i++){
        now_is_single = previous_is_single*(colours-1) + previous_is_double*(colours-1);
        now_is_double = previous_is_single*1;
        previous_is_single = now_is_single;
        previous_is_double = now_is_double;
    }
    
    cout << "Total number of ways to paint the fence such that not more than two consecutive have same coloir ... " << 
                now_is_double + now_is_single;
    return 0;
}
