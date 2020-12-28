#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
using namespace std;

// FRACTIONAL KNAPSACK PROBLEM
/* 
Sort the products in the order of decreasing price per kg
*/

class product_description{
public:
    int value,weight;
    double ppkg = value/(1.0*weight);
};

bool comparer(product_description p1,product_description p2){
    return (p1.ppkg > p2.ppkg);
}

int main(){
    product_description product[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } } ;
    int capacity = 50;
    int len = sizeof(product)/sizeof(product[0]);
    sort(product,product + len,comparer);
    int i = 0;
    int t_val = 0;
    while(capacity > 0 && i != len){
        if(capacity >= product[i].weight){
            t_val += product[i].value;
            capacity -= product[i].weight;
        }
        else{
            t_val += capacity*(product[i].ppkg);
            break;
        }
        i++;
    }
    cout <<"The maximum total value of the ....\nProduct that can be accomodated in the sack is...." << t_val;
    return 0;

}
