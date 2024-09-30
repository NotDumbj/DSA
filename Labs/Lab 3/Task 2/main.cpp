#include <iostream>
using namespace std;

int C(int n, int k);

int main() {
    cout << "Enter numbers to find binomial of; ";
    int n, k;
    cout << "\nn: ";
    cin >> n;
    cout << "k: ";
    cin >> k;
    cout << "Binomial Coefficient is : " << C(n, k) << endl;
    system("pause");
    return 0;
}

int C(int n, int k){
    if(k==0 || k==n){
        return 1;
    }

    if((!(n>1))||(!(0 < k && k < n))){
        return 0;
    }

    return C(n-1, k-1) + C(n-1, k);
}