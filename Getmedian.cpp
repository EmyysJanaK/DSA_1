#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    double median;
    if (n % 2 == 0)
        median = (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        median = arr[n/2];
        
    for (size_t i = 0; i < n; i++) {
        std::cout << arr[i] << ' '<<endl;
    }
    
    std::cout << std::setprecision (2) << "median is "<< median << std::endl;

    return 0;
}
