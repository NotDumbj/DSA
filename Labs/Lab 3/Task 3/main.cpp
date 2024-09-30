#include <iostream>
using namespace std;

bool checkPrime(int n, int i = 2);

int main() {
    cout << "Enter a Number: ";
    int n;
    cin >> n;
    cout << "The number you entered is : " << ((checkPrime(n)) ? "Prime" : "Not Prime") << endl;
    system("pause");
    return 0;
}

bool checkPrime(int n, int i){
    if(n <= 0){
        return false;
    }

    if(i * i > n){
        return true;
    }

    if(n % i == 0){
        return false;
    }

    return checkPrime(n, i + 1);
}