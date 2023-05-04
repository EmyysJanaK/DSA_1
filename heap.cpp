#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root; // initialize the largest as root.
   int left = 2*root+1; // left child.
   int right = 2*root+2; // right child.

   if (left < n && arr[left] > arr[largest])(largest = left);
   if (right < n && arr[right] > arr[largest])(largest = right);
  
   // if largest is not root.
   if (largest != root) {
    swap(arr[root], arr[largest]);
    // recursively heapify the relevant sub-tree.
    heapify(arr, n, largest);
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n/2 -1 ; i >= 0 ; i --){
    heapify(arr,n,i);
   }
   // extracting elements from heap one by one
   for(int i = n-1; i >= 0 ; i--){
    swap(arr[0],arr[i]);
    heapify(arr,i,0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main(){
    int a;
    cout << "Enter the size of the array: ";
    cin >> a;

    int heap_arr[a];
    cout << "Enter " << a << " numbers: ";
    for (int i = 0; i < a; i++) {
        cin >> heap_arr[i];
    }

    
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);
  
    heapSort(heap_arr, n);
  
    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}