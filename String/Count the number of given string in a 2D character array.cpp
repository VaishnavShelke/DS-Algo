#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Count of number of given string in 2D character array
// Four loops approach
/*
    Be careful about palindromes
*/

int main(){
    string hay[] =   { "BBABBM",  
                       "CBMBBA",  
                       "IBABBG",  
                       "GOZBBI",  
                       "ABBBBC",  
                       "MCIGAM" }; 
    string needle = "MAGIC";
    int needlen = needle.size();
    int count = 0;
    int inxm,inxn;

    int lenarr = sizeof(hay)/sizeof(hay[0]);
    for(int j = 0; j < lenarr; j++){
        for(int i = 0; i < hay[j].size() ; i++){
                if(hay[j][i] == needle[0]){
                    
                    // left to right 
                    inxm = i;
                    inxn = 0;
                    while(inxm < hay[j].size() && inxn < needlen){
                        if(hay[j][inxm] == needle[inxn]){
                            inxm++;inxn++;
                        }
                        else break;
                         if(inxn == needlen){
                            count++; break;
                        }
                    }

                    // right to left 
                    inxm = i;
                    inxn = 0;
                    while(inxm >= 0 && inxn < needlen){
                        if(hay[j][inxm] == needle[inxn]){
                            inxm--;inxn++;
                        }
                        else break;
                         if(inxn == needlen){
                            count++; break;
                        }
                    }

                    // top to bottom 
                    inxm = j;
                    inxn = 0;
                    while(inxm < lenarr  && inxn < needlen){
                        if(hay[inxm][i] == needle[inxn]){
                            inxm++;inxn++;
                        }
                        else break;
                         if(inxn == needlen){
                            count++; break;
                        }
                    }

                    // bottom to top
                    inxm = j;
                    inxn = 0;
                    while(inxm >= 0 && inxn < needlen){
                        if(hay[inxm][i] == needle[inxn]){
                            inxm--;inxn++;
                        }
                        else break;
                         if(inxn == needlen){
                            count++; break;
                        }
                    }
                    
                }
        }
    }
    cout << count;
    /*
     Before printing the output check if the sequence/needle is palindromic or not
     if it is palindromic the output half the value obtainde in count.
     This thing came in my mind because i am a smart guy
    */
    return 0;

}
