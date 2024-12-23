#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void bubbleSort(int arr[], int n, int &comparisons, int &exchanges) {
    comparisons = 0;
    exchanges = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                exchanges++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int &comparisons, int &exchanges) {
    comparisons = 0;
    exchanges = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
            exchanges++;
        }
    }
}

void insertionSort(int arr[], int n, int &comparisons, int &exchanges) {
    comparisons = 0;
    exchanges = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            exchanges++;
        }
        arr[j + 1] = key;
    }
}

void heapify(int arr[], int n, int i, int &comparisons, int &exchanges) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comparisons++;
        if (arr[left] > arr[largest]) {
            largest = left;
        }
    }

    if (right < n) {
        comparisons++;
        if (arr[right] > arr[largest]) {
            largest = right;
        }
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        exchanges++;
        heapify(arr, n, largest, comparisons, exchanges);
    }
}

void heapSort(int arr[], int n, int &comparisons, int &exchanges) {
    comparisons = 0;
    exchanges = 0;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons, exchanges);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        exchanges++;
        heapify(arr, i, 0, comparisons, exchanges);
    }
}


void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

void displayArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void displayMenu() {
    cout << "\nSorting Algorithm Comparison" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cout << "4. Heap Sort" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice, n;
    int comparisons, exchanges;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

        cout << "Enter the size of the array: ";
        cin >> n;
        if (n <= 0) {
            cout << "Invalid array size! Please enter a positive number." << endl;
            continue;
        }

        int* arr = new int[n];
        generateRandomArray(arr, n);

        cout << "Original Array: ";
        displayArray(arr, n);

        switch (choice) {
        case 1:
            bubbleSort(arr, n, comparisons, exchanges);
            cout << "Sorted using Bubble Sort: ";
            break;
        case 2:
            selectionSort(arr, n, comparisons, exchanges);
            cout << "Sorted using Selection Sort: ";
            break;
        case 3:
            insertionSort(arr, n, comparisons, exchanges);
            cout << "Sorted using Insertion Sort: ";
            break;
        case 4:
            heapSort(arr, n, comparisons, exchanges);
            cout << "Sorted using Heap Sort: ";
            break;
        default:
            cout << "Invalid choice! Please select a valid option." << endl;
            delete[] arr;
            continue;
        }

        displayArray(arr, n);
        cout << "Comparisons: " << comparisons << ", Exchanges: " << exchanges << endl;

        delete[] arr;
    }

    return 0;
}