/* COUNT THE NUMBER OF BITS THAT NEED TO BE FLIPPED TO MAKE THEM SIMILAR */
    /* Simple ...  Perform xor of the two numbers and check the number of set bits in
       the xor product obtained */

int main(){
    int num1,num2;
    num1 = 45;
    num2 = 6;
    int xoor;
    xoor = num1^num2;
    // Find the number of set bits in xoor

    int cnt = 0;
    while (xoor > 0){
        cnt ++;
        xoor = xoor&(xoor-1);
    }
    cout << "The number of flips required are: " << cnt;
    return 0;
}

