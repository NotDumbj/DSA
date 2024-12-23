#include <iostream>
#include <chrono>
using namespace std;

int Binary( int x[], int n, int key, int &iter)
{
    int low = 0; int hi = n-1;

    while (low <= hi)
    {
        iter++;
        int mid = (low + hi) / 2;
        if (key == x[mid])
            return (mid); 
        if (key < x[mid])
            hi = mid -1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int dataSet[] = {2, 3, 4, 10, 40, 50, 60};
    int n = sizeof(dataSet)/sizeof(dataSet[0]);
    int x = 50;

    auto start = chrono::high_resolution_clock::now();

    int iter = 0;
    int result = Binary(dataSet, n, x, iter);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    if(!(result == -1))
        cout << "Element " << x << " found at index #" << result << endl;
    else
        cout << "Element not found." << endl;

    cout << "Number of iterations: " << result << endl;
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

    
