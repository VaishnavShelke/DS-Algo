class Solution{
public:	
	int maxSubstring(string S)
	{
	    return maxDiff(S);
	}
int maxDiff(string str){

    int maxZero[str.size()+1]; maxZero[0] = 0;
    //int maxOnes[str.size()+1]; maxOnes[0] = 0;
    // "0101000010110"
    for(int i = 0; i<str.size() ; i++){
        if(str[i] == '0'){
            maxZero[i+1] = min(maxZero[i]-1,-1);
            //maxOnes[i+1] = max(maxOnes[i]-1,-1);
        }
        else{
            maxZero[i+1] = min(maxZero[i]+1,1);
            //maxOnes[i+1] = max(maxOnes[i]+1,1);
        }
    }
    int maxVal = 0;
    for(int i = 0; i<=str.size() ; i++){
        maxVal = max(maxVal,-maxZero[i]);
        //maxVal = max(maxVal,maxOnes[i]);
    }
    if(maxVal == 0) maxVal = -1;
    return maxVal;

}
};
