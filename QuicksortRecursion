#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

// function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Partition function*/

int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // pivot point
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}



// Driver code
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    // generate a random array of size n
    int arr[n];
    srand(time(0));  // seed the random number generator with the current time
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    
    // sort the array and calculate the execution time
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); // calculate the execution time
    
    // print the sorted array and the execution time
    cout << "Sorted array: \n";
    printArray(arr, n);
    cout << "Execution time: " << time_taken << " seconds" << endl;
    
    return 0;
}






