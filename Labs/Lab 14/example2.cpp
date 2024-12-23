#include <iostream> 
#include <stack> 
#include <list> 
#include <conio.h>
using namespace std; 
int main()
{
    cout << "Example 2: " << endl;
    stack<int, list<int> > stk;

    for (int i = 1; i <= 10; i++) 
        stk.push(i);

    while (!stk.empty()) {
        cout << stk.top() << endl; stk.pop();
    }
    getch(); 
    return 0;
}
