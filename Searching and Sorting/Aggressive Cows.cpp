#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Agressive cows problem

/*
    Given the positions of the posts you have to place cows in those posts such that the
    minimum distance among the cows is maximized

    What we do is check the wether the spacing 
    of let say X is legit or not
    And change the values of X accordingly
    And you can guess where does the binary search comes into play here .........
*/

bool appropriatespacing(int* cowposition,int posts,int cows,int spacing);
int main(){
    int cowposition[] = {1, 2, 4, 8, 9};
    int posts = sizeof(cowposition)/sizeof(cowposition[0]);
    int cows = 3;

    int low = 0; int high = 10e6;
    int mid;

    while(low < high){
        mid = (low + high)/2;
        if(low + 1 == high){
            break;
        }
        if(appropriatespacing(cowposition,posts,cows,mid)){
            low = mid;
            high = high;
        }
        else{
            low = low;
            high = mid;
        }
    }

    cout << "Maximum spacing possible is ... ";
    if(appropriatespacing(cowposition,posts,cows,high)) cout << high;
    else cout << low;

    return 0;

}

bool appropriatespacing(int* cowposition,int posts,int cows,int spacing){
    int ptr = 1;
    cows--;                                                 //{1, 2, 4, 8, 9}
    int prevlen = 0;
    while(ptr < posts && cows > 0){
        if(cowposition[ptr] - cowposition[ptr-1] + prevlen >= spacing){
            prevlen = 0;
            cows--;
        }
        else{
            prevlen += cowposition[ptr] - cowposition[ptr-1];
        }
        ptr++;
    }
    if(cows > 0) return false;
    else return true;
}
