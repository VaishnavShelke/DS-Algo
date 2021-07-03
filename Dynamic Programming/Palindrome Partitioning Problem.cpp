#define INF 99999
class Solution{
public:
    int palindromicPartition(string str)
    {
        char* characterArr = &str[0];
        return minPalPartion(characterArr);
    }

void plandromeLensFrom_base(vector<vector<int>>& plandromeLens,char* str){
    // "abbbabbababa"
    int n = strlen(str);
    vector<int> init = {1};
    for(int i = 0; i<n ; i++) plandromeLens.push_back(init);
    for(int j = n-2; j>=0 ; j--){
        for(int i = 0; i<plandromeLens[j+1].size(); i++){
            if(j+plandromeLens[j+1][i]+1<n && str[j+plandromeLens[j+1][i]+1] == str[j]){
                plandromeLens[j].push_back(plandromeLens[j+1][i]+2);
            }
        }
        if(j+1 < n && str[j] == str[j+1]){
            plandromeLens[j].push_back(2);
        }
    }
    /*
    for(int j = 0; j<n ; j++){
        for(int i = 0; i<plandromeLens[j].size(); i++){
            cout << plandromeLens[j][i] << " ";
        }
        cout << endl;
    }
    */
    return;
    
}

int minPalPartion(char* str){
    int n = strlen(str);
    vector<vector<int>> plandromeLens;
    plandromeLensFrom_base(plandromeLens,str);
    int minParts[n+1];
    minParts[n] = 0;

    for(int j = n-1 ; j>=0 ; j--){
        minParts[j] = INF;
        for(int k = 0; k<plandromeLens[j].size(); k++){
            minParts[j] = min(minParts[j],minParts[j+plandromeLens[j][k]]);
        }
        minParts[j]++;
    }
    //for(int i = 0; i<=n ; i++) cout << minParts[i] << " ";
    return minParts[0]-1;
}
};
