#include <iostream> 
#include <numeric> 
#include <conio.h>
#include <functional>

using namespace std;

int vec[] = {1, 2, 3, 4, 5};

int main()
{
    cout << "Example 7: " << endl;

  
    int sum = accumulate(vec, vec + 5, 0); 
    cout << sum << endl;

    int prod = accumulate(vec, vec + 5, 1, multiplies<int>()); 
    cout << prod << endl;
    getch(); 
    return 0;
}
