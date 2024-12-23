#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <conio.h>
using namespace std; 

int set1[] = {1, 2, 3};
int set2[] = {2, 3, 4};
vector<int> set3(10);

int main()
{
    cout << "Example 5: " << endl;

  
    vector<int>::iterator first = set3.begin();

    vector<int>::iterator last = set_union(set1, set1 + 3, set2, set2 + 3, first);

    while (first != last) {
        cout << *first << " "; 
        first++;
    }

    cout << endl;

    getch(); 
    return 0;
}
 
