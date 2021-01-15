#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Type the given sentence in Nokia phone

int main(){
    string nokia_dict[] = {"2","22","222", 
                    "3","33","333", 
                    "4","44","444", 
                    "5","55","555", 
                    "6","66","666", 
                    "7","77","777","7777", 
                    "8","88","888", 
                    "9","99","999","9999"
                   };

    string letter = "GEEKS FOR GEEKS"; // feed capital only
    string output = "";
    int index;
    for(int i = 0;i<letter.size();i++){

        if(letter[i] == ' ') output += '0';
        else {
            index = letter[i] - 'A';
            output += nokia_dict[index];
        }
    }
    cout << letter << "Can also be written as ... \n" << output;
    return 0;  
}
