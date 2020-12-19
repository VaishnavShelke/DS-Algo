int main(){
    int number = 33;
    if (number == 0) { cout << "YES"; return 0;}

    if (number&(number -1) != 0) { cout << "NO"; return 0;}
    else { cout << "YES" ; return 0;}
}
