// Right shift approach to find the position of the ith set bit

int main(){
    int number = 32;
    int cnt = 0;
    while (number > 0){number = number >> 1; cnt ++;}
    cout << "Position of ith set :" << cnt;
    return 0;
}
