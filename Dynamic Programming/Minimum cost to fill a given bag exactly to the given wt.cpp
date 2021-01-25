

// Minimum Cost to fill a given bag with weight exactly W
/*
  If there are zero options and the weight which we have to fill is non zero;
  Then the cost should be zero ?????
        But you see our objective is to fill the bag and giving zero options case cost as zero is unfair
        we should penalise such case;
*/
int main(){
    int wtcost[] = {20, 10, 4, 50, 100};
    int t_avaliable = sizeof(wtcost)/sizeof(wtcost[0]);
    int weight = 5;

    int optionsweight[t_avaliable+1][weight+1];

    for(int opt = 0; opt <= t_avaliable ; opt++){
        for(int wt = 0; wt <= weight ; wt++ ){
            if(opt == 0) { optionsweight[opt][wt] = INT_MAX; continue;}
            if(wt == 0) { optionsweight[opt][wt] = 0; continue;}
            if(wtcost[opt-1] == -1){
                optionsweight[opt][wt] = optionsweight[opt-1][wt];
                }
            if(wt - opt >= 0)
                optionsweight[opt][wt] = min(optionsweight[opt][wt - opt] + wtcost[opt-1],optionsweight[opt-1][wt]);
            else
                optionsweight[opt][wt] = optionsweight[opt-1][wt];  
        }
        for(int k = 0; k<= weight; k++){
            cout << optionsweight[opt][k] << " ";
        }
        cout << "\n";
    }
}
