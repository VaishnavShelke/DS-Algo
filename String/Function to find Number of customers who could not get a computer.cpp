#include <bits/stdc++.h>
using namespace std;

// Function to find Number of customers who could not get a computer

int runCustomerSimulation(int customer,string str){
    
    unordered_set<char> intheHouse; 
    unordered_set<char> bichare;
    for(int i = 0; i<str.size(); i++){

        if(intheHouse.size() < customer){
            if(intheHouse.find(str[i]) != intheHouse.end()){
                intheHouse.erase(str[i]);
            }
            else{
                intheHouse.insert(str[i]);
            }
        }
        else{
            if(intheHouse.find(str[i]) != intheHouse.end()){
                intheHouse.erase(str[i]);
            }
            else{
                if(bichare.find(str[i]) == bichare.end()){
                    bichare.insert(str[i]);
                }
            }

        }
    }
    return bichare.size();
}

// Driver program
int main()
{
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
    return 0;
}
