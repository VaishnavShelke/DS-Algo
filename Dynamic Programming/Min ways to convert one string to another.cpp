#include <iostream>
#include <vector>
using namespace std;

// To convert a given start string into destination string either by replacing , deleting or inserting

/* Approach,
        Assume the last element of the both strings check if they are equal
        1. If they are then all you have to do is to not worry about them and 
            look at how do you transform the previous letters.
        2. If they are unequal you can either
            A.  Delete the last letter from the start       str_length -->> str_length -1 && dest_length -->> dest_length
            B.  Insert a letter in front of last letter in start   str_length -->> str_length && dest_length -->> dest_length -1 
                            Because the inserted element creates a match for last letter in destination string
            C.  Replace the last element in the start       str_length -->> str_length-1 && dest_length -->> dest_length - 1
                            Because the replacement has happened both are matched
*/
int main(){
    string start = "sunday";
    string destination = "saturday";
    int conversion[start.size()+1][destination.size()+1];
    int dummy;
    for(int str_sub = 0;str_sub <= start.size();str_sub++){
        for(int end_sub = 0;end_sub <= destination.size();end_sub++){

            if (str_sub == 0) {conversion[str_sub][end_sub] = end_sub; continue;}
            if (end_sub == 0) {conversion[str_sub][end_sub] = str_sub; continue;}

            if (start[str_sub-1] == destination[end_sub-1]){
                conversion[str_sub][end_sub] = conversion[str_sub-1][end_sub-1];
            }
            else{
             dummy = min(conversion[str_sub-1][end_sub-1],conversion[str_sub-1][end_sub]);
             conversion[str_sub][end_sub] = min(conversion[str_sub][end_sub-1],dummy) + 1;

            }
        }
    }
    cout << "The number of conversions required to convert " << start << " to " << destination <<"\n";
    cout << "is ---->>>> " << conversion[start.size()][destination.size()];
    return 0;
}
