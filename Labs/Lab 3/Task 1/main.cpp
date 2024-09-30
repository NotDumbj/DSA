#include <iostream>
using namespace std;

void printNumberR(int n);

int main() {
    cout << "Enter the end number to print the range: ";
    int n;
    cin >> n;
    printNumberR(n);
    system("pause");
    return 0;
}

void printNumberR(int n){
    if(n<0){
        return;
    }
    cout << n << endl;
    printNumberR(n-1);
}