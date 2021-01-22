
// Maximize the number of segments of length p, q and r
/*
    Note why this is not a Greedy Algorithm Problem
            ...tip... Ensure that there is no wastage i.e length other than the cutoptions
    We will space optimize this DP problem 

    Approach....
        There are two options avaliable to us
            Either to use the given length to cut ONCE....
            Or to use the given length NEVER not even NOW....
*/

int main(){
    int rodlength = 19;
    int cutoptions[] = {2,3,5};
    int cuts = sizeof(cutoptions)/sizeof(cutoptions[0]);
    int first[rodlength+1] ;
    int second[rodlength+1] ;
    map<int,int*> maxpieces;
    maxpieces[0] = first;
    maxpieces[1] = second;

    int row;
    for(int cutl = 0; cutl <= cuts; cutl++){
        for(int lenrem = 0; lenrem <= rodlength; lenrem++){
            
            if(cutl == 0)   {maxpieces[1][lenrem] = 0; continue;}
            if(lenrem == 0) {maxpieces[1][lenrem] = 0; continue;}

            if(lenrem - cutoptions[cutl-1]<0){
                maxpieces[1][lenrem] = maxpieces[0][lenrem];
            }
            else
                maxpieces[1][lenrem] = max(maxpieces[1][lenrem - cutoptions[cutl-1]] + 1,
                                            maxpieces[0][lenrem]);
            }
        maxpieces[0] = maxpieces[1];

        for(int i = 0; i<rodlength+1 ; i++)
            cout << maxpieces[1][i] << " ";
        cout << "\n";

    }

}
