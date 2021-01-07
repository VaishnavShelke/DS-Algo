#include<bits/stdc++.h>
using namespace std;

//Check if the given string is rotation of Given string or not
/*
    Given string :VAISHNAV  
    L rotation 3 :NAVVAISH
    R rotation 4 :HNAVVAIS
                            All of the three are substrings of VAISHNAVVAISHNAV
                            Note ** check for equal length also.....
*/

bool check_if_rotation(string orig,string rot){
    if(orig.length() != rot.length()) return false;

    orig = orig + orig;
    if(orig.find(rot) == string::npos){      // npos is the greatest possible value returned when the element is not found
        return false;
    }
    else return true;
}

int main(){
    string original = "VAISHNAV";
    string rotation = "NAVVAISH";
    
    if(check_if_rotation(original,rotation)){
        cout << rotation << " is rotation of " << original;
    }
    else{
        cout << rotation << " is not rotation of " << original;
    }
    return 0;
}
