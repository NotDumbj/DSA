#include <iostream>
#include <chrono>
using namespace std;

int Sequential( int x[], int n, int key, int &iter)
{
    for (int i = 0; i< n; i++){
        iter++;
        if (key == x[i]) 
            return (i); 
    }
    return (-1);
}


int main()
{
    int dataSet[] = {5, 6, 2, 9, 7, 0};
    int n = sizeof(dataSet)/sizeof(dataSet[0]);
    int x = 0;

    auto start = chrono::high_resolution_clock::now();

    int iter = 0;
    int result = Sequential(dataSet, n, x, iter);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    
    if(!(result == -1))
        cout << "Element " << x << " found at index #" << result << endl;
    else
        cout << "Element not found." << endl;

    cout << "Number of iterations: " << iter << endl;
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

    
