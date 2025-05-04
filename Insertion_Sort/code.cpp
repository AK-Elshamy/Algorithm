#include <vector>
#include <iostream>

using namespace std;

/**
 * Sorts an array using the Insertion Sort algorithm.
 *
 * @param arr The vector to be sorted.
 */
void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    // Test case 1: Example array
    vector<int> test1 = {5, 2, 4, 6, 1, 3};
    cout << "Original array: ";
    for (int num : test1)
    {
        cout << num << " ";
    }
    cout << endl;

    insertionSort(test1);

    cout << "Sorted array: ";
    for (int num : test1)
    {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2: Empty array
    vector<int> test2;
    cout << "\nSorting empty array..." << endl;
    insertionSort(test2);
    cout << "Result: empty" << endl;

    // Test case 3: Single element array
    vector<int> test3 = {10};
    cout << "\nSorting single element array..." << endl;
    insertionSort(test3);
    cout << "Result: [10]" << endl;

    return 0;
}