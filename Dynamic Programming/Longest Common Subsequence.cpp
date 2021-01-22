
// Longest common subsequence

/*
    Using Space optimisation

    Start from the last element while thinking about this problem
    So there are two possible situations we will encounter
        1. The values pointed on both sequences are equal
            in that case we add that element to our subsequence and move on in both subsequence
        2. The values pointed on both sequences are unequal
            in that case we move on in first sequence ONLY
            or move on in second sequence ONLY
            whichever gives maximum subsequence length is chosen
*/

int main(){
    string strx = "CWDCHVCKAHBCJACBH";
    string stry = "ABDIVCBECBAIJNJCD";
                                     
    int spaceopt2[strx.size()+1]; // array to be used for space optimization

    map<int,int*> longestSSupto;  // Map having integer mapped to array/pointer to first integer in array

    longestSSupto[1] = spaceopt2;

    for(int st1 = 0; st1<=stry.size() ;st1++){
        for(int st2 = 0; st2<=strx.size() ;st2++){

            if(st1 == 0) {longestSSupto[1][st2] = 0; continue;}
            if(st2 == 0) {longestSSupto[1][st2] = 0; continue;}
            
            if(stry[st1-1] == strx[st2-1])
                    longestSSupto[1][st2] = longestSSupto[0][st2-1] + 1;
            else
                    longestSSupto[1][st2] = max(longestSSupto[0][st2],
                                                                longestSSupto[1][st2-1]); 
        }
        for(int i = 0; i<= strx.size() ; i++){
            cout << longestSSupto[1][i] << " ";
        }
        cout << "\n";
        longestSSupto[0] = longestSSupto[1];
    }

    return 0;

}
