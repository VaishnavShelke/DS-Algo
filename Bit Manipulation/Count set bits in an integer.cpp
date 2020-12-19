

int main(){
    int number;
    int cnt =0;
    cin >> number;
    while (number >0){
        cnt++;
        number = number&(number-1);

    }
    cout << "Number of set bits are: " << cnt;
}
