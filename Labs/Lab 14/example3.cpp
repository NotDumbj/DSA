#include <iostream> 
#include <bitset> 
#include <conio.h>
using namespace std; 
int main()
{
    cout << "Example 3: " << endl;

    bitset<16> b1("1011011110001011");
    bitset<16> b2; b2 = ~b1;

    for (int i = b2.size() - 1; i >= 0; i--) 
        cout << b2[i];

    cout << endl;
    getch(); 
    return 0;
}
