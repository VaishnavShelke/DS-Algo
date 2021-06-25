#include <iostream>
using namespace std;
#define MAX_CHAR 256

// Check if two given strings are isomorphic to each other

int areIsomorphic(string str1,string str2){

    if(str1.size() != str2.size()) return false;
    bool mapped[MAX_CHAR];
    char keyVal[MAX_CHAR];

    for(int i = 0; i<MAX_CHAR ; i++){
        mapped[i] = false;
        keyVal[i] = (char)i;
    }

    for(int i = 0; i<str1.size() ; i++){
        if(mapped[str1[i]]&&mapped[str2[i]]){
            if(keyVal[str1[i]] ==  str2[i] && keyVal[str2[i]] == str1[i]){}
            else{
                return false;
            }
        }
        else{
            if(mapped[str1[i]] || mapped[str2[i]]) return false;
            else{
                mapped[str1[i]] = true; mapped[str2[i]] = true;
                keyVal[str1[i]] = str2[i] ; keyVal[str2[i]] = str1[i];
            }
        }
    }
    return true;

}


int main()
{
   cout << areIsomorphic("aab", "aab") << endl;
   cout << areIsomorphic("aab", "xyz") << endl;
   return 0;
}
