#include <vector> 
#include <algorithm> 
#include <iostream> 
#include <conio.h>
using namespace std; 
int main()
{
    cout << "Example 1 :\n";
    
    vector<int> v;

    for (int i = 0; i < 25; i++) 
        v.push_back(i);
    
    random_shuffle(v.begin(), v.end());

    for (int j = 0; j < 25; j++) 
        cout << v[j] << " ";
    cout << endl; 
    getch(); 
    return 0;
}
