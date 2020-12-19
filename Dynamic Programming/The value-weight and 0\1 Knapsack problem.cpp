#include <iostream>
#include <vector>
using namespace std;

/* To approach the following problem use the following approach
  1. Either you can add the weight or you can simply ignore it
  2. In case you add the weight to knap scak ensure that the capacity is reduced and 
      the weight is deducted from the avaliable weights and the value is added to the knapsack
  3. In the case you completely ignore the weight make sure that you reduce the avaliable optins without compensating for the value
  4. whichever of the abouve two steps 2 or 3 yeild maximum output valu you perform that
  Special note:
                Ensure that the the index does not get negative i.e you are not adding weight greater than the capacity of the sack
*/


int main(){
    int capacity = 50;
    int weights[] = { 10, 20, 30 };
    int value[] = { 60, 100, 120 };
    int wt_avaliable = sizeof(weights)/sizeof(weights[0]);
    int maxvalpos[wt_avaliable+1][capacity+1];

    for (int wts = 0; wts <= wt_avaliable; wts++){
        for (int cap = 0;cap <= capacity; cap++){
            if (wts == 0) {maxvalpos[wts][cap] = 0; continue;}
            if (cap == 0) {maxvalpos[wts][cap] = 0; continue;}

            if (cap-value[wts-1]) maxvalpos[wts][cap] = max(maxvalpos[wts-1][cap],maxvalpos[wts-1][cap-weights[wts-1]]+value[wts-1]);
            else maxvalpos[wts][cap] = maxvalpos[wts-1][cap];
        }
    }

    cout << "The maximum value possible in the given knapsack " << maxvalpos[wt_avaliable][capacity];
    return 0;
}
