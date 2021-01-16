#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Search a word in a 2D grid of characters
/*
    Consider all 8 directions
*/

bool search_me_if_you_can(int j,int i,pair<int,int> direction,string hay[], int height,int width,string needle){
    int needindex = 0;
    while( i>=0 && i<width && j>=0 && j<height){

        if(hay[j][i] == needle[needindex]){
            j += direction.first;
            i += direction.second;
            needindex += 1;
        }
        else return false;

        if(needindex == needle.size()){
            return true;
        }
    }
    return false;

}
int main(){
    string hay[] =   { "BBABBM",  
                       "CBMBBA",  
                       "IBABBG",  
                       "GOZBBI",  
                       "ABBBBC",  
                       "MCIGAM" }; 
    string needle = "MAGIC";
    int height = sizeof(hay)/sizeof(hay[0]);
    int width = hay[0].size();

    vector<pair<int,int>> answercoordinates;
    pair<int,int> directions[] = {make_pair(0,1),make_pair(1,1),make_pair(1,0),make_pair(1,-1),
                                  make_pair(0,-1),make_pair(-1,-1),make_pair(-1,0),make_pair(-1,1) };

    for(int j = 0;j<height; j++){
        for(int i = 0;i<width; i++){
            if(hay[j][i] == needle[0]){
                for(int k = 0; k < 8 ; k++ ){
                        if(search_me_if_you_can(j,i,directions[k], hay , height , width,needle)){
                            answercoordinates.push_back(make_pair(j,i));
                        }

                }
            }
        }
    }

    // Printing the answer

    cout << "The coordinates where the origin of the string is traced are .....\n";
    for(int i = 0;i<answercoordinates.size();i++){
        cout << "x-axis == " << answercoordinates[i].second << "  y-axis == " << answercoordinates[i].first << "\n";
    }
    return 0;
}
