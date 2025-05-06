# Merge Sort Algorithm - Complete Guide

## Table of Contents
- [Simple Explanation](#simple-explanation)
- [Visual Representation](#visual-representation)
- [Algorithm Implementation](#algorithm-implementation)
  - [C++](#c)
  - [Java](#java)
  - [Python](#python)
- [Interview Questions](#interview-questions)
- [LeetCode Practice Problems](#leetcode-practice-problems)

## Simple Explanation

Merge Sort is a **divide-and-conquer** algorithm that follows these steps:

1. **DIVIDE** 🔪 - Split the array into halves until you have single elements
2. **CONQUER** ⚔️ - Sort each half recursively
3. **COMBINE** 🔄 - Merge the sorted halves back together

### Key Features

- ✅ **Stable sorting algorithm** - preserves relative order of equal elements
- ✅ **Time Complexity: O(n log n)** - efficient for large datasets
- ✅ **Space Complexity: O(n)** - requires additional memory
- ✅ **Not in-place** - needs extra space for merging

### How It Works (Simplified)

Imagine you have a deck of cards 🃏 that needs sorting:

1. **Split the deck** in half, then split each half again, until you have single cards
2. **Compare and merge** pairs of cards (or small sorted piles) into bigger sorted piles
3. **Continue merging** until you have one complete sorted deck

## Visual Representation

### Merge Sort Process

```
Original Array: [38, 27, 43, 3, 9, 82, 10]

Step 1: Divide until single elements
[38, 27, 43, 3, 9, 82, 10]
        /             \
[38, 27, 43, 3]    [9, 82, 10]
    /     \           /     \
[38, 27]  [43, 3]  [9, 82]  [10]
  /   \    /   \    /   \     |
[38] [27] [43] [3] [9] [82]  [10]

Step 2: Merge while sorting
[38] [27] [43] [3] [9] [82]  [10]
   \  /     \  /     \  /     |
  [27,38]  [3,43]   [9,82]  [10]
      \       /        \     /
   [3,27,38,43]     [9,10,82]
          \             /
     [3,9,10,27,38,43,82]  (Final sorted array)
```

### Merge Process Highlighted

Let's see the merge process in detail for merging [27,38] and [3,43]:

```
Left array: [27, 38]
Right array: [3, 43]

Compare first elements: 27 vs 3
3 is smaller, take it first → [3]
Left: [27, 38], Right: [43]

Compare next elements: 27 vs 43
27 is smaller, take it → [3, 27]
Left: [38], Right: [43]

Compare next elements: 38 vs 43
38 is smaller, take it → [3, 27, 38]
Left: [], Right: [43]

Right array has remaining element
Add it → [3, 27, 38, 43]

Result: [3, 27, 38, 43]
```

## Algorithm Implementation

### C++

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays into one sorted array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    vector<int> L(n1), R(n2);
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Main merge sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    cout << "Original array: ";
    printArray(arr);
    
    mergeSort(arr, 0, arr.size() - 1);
    
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
```

### Java

```java
import java.util.Arrays;

public class MergeSort {
    // Merge two sorted subarrays into one sorted array
    public static void merge(int[] arr, int left, int mid, int right) {
        // Calculate sizes of two subarrays
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        // Create temporary arrays
        int[] L = new int[n1];
        int[] R = new int[n2];
        
        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
        
        // Merge the temporary arrays back into arr
        int i = 0, j = 0; // Initial indices of first and second subarrays
        int k = left;     // Initial index of merged subarray
        
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        // Copy remaining elements of L[] if any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        
        // Copy remaining elements of R[] if any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
    // Main merge sort function
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            // Find the middle point
            int mid = left + (right - left) / 2;
            
            // Sort first and second halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            
            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }
    
    // Driver method
    public static void main(String[] args) {
        int[] arr = {38, 27, 43, 3, 9, 82, 10};
        System.out.println("Original array: " + Arrays.toString(arr));
        
        mergeSort(arr, 0, arr.length - 1);
        
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
```

### Python

```python
def merge_sort(arr):
    if len(arr) > 1:
        # Finding the mid of the array
        mid = len(arr) // 2
        
        # Dividing the array elements into 2 halves
        L = arr[:mid]
        R = arr[mid:]
        
        # Sorting the first half
        merge_sort(L)
        
        # Sorting the second half
        merge_sort(R)
        
        i = j = k = 0
        
        # Copy data to temp arrays L[] and R[]
        while i < len(L) and j < len(R):
            if L[i] <= R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        
        # Checking if any element was left
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
    
    return arr

# Driver code
if __name__ == '__main__':
    arr = [38, 27, 43, 3, 9, 82, 10]
    print(f"Original array: {arr}")
    
    sorted_arr = merge_sort(arr.copy())  # Using copy to preserve original for display
    
    print(f"Sorted array: {sorted_arr}")
```

## Interview Questions

Here are 10 common interview questions about merge sort from major tech companies:

### 1. What is the time complexity of merge sort?

**Answer:** The time complexity of merge sort is **O(n log n)** in all cases (best, average, and worst), where n is the number of elements in the array. This is because:
- Dividing the array takes O(log n) steps
- Each level of recursion processes all n elements
- Therefore, the overall time complexity is O(n log n)

### 2. What is the space complexity of merge sort?

**Answer:** The space complexity of merge sort is **O(n)** because:
- It requires additional space to store the temporarily divided subarrays
- The recursive call stack uses O(log n) space
- The dominant factor is the O(n) space needed for the temporary arrays during merging

### 3. Is merge sort a stable sorting algorithm?

**Answer:** **Yes**, merge sort is a stable sorting algorithm. This means that elements with equal values maintain their relative order in the sorted output as they appeared in the input array. This is because during the merging process, we take elements from the left subarray first when both elements are equal.

### 4. Compare merge sort with quicksort.

**Answer:**
| Feature | Merge Sort | Quick Sort |
|---------|------------|------------|
| Time Complexity | O(n log n) for all cases | Best & Avg: O(n log n), Worst: O(n²) |
| Space Complexity | O(n) | O(log n) |
| Stability | Stable | Typically not stable |
| In-place | No | Yes (with optimizations) |
| Cache Performance | Not as good | Better |
| Adaptivity | Not adaptive | Can be made adaptive |
| Preferred for | Linked lists, external sorting | Internal sorting, arrays |

### 5. How would you optimize merge sort to reduce space complexity?

**Answer:** Several optimizations can reduce merge sort's space complexity:
1. **In-place merge**: Using techniques like block merge to perform merging without extra space
2. **Hybrid approach**: Using insertion sort for small subarrays (typically less than 10-20 elements)
3. **Bottom-up merge sort**: Implementing iteratively rather than recursively to avoid stack space
4. **Memory reuse**: Allocating temporary arrays once and reusing them throughout the algorithm

### 6. When would you choose merge sort over other sorting algorithms?

**Answer:** I would choose merge sort in the following scenarios:
- When stability is required (preserving the relative order of equal elements)
- When sorting linked lists (merge sort can be implemented with O(1) extra space for linked lists)
- When guaranteed O(n log n) worst-case performance is required
- For external sorting when data doesn't fit in memory
- When parallel processing is available (merge sort is naturally parallelizable)

### 7. Explain how merge sort can be applied to a linked list.

**Answer:** Merge sort is particularly efficient for linked lists because:
1. Finding the middle of the list can be done using the slow-fast pointer technique
2. Splitting the list at the middle is just updating a few pointers
3. Merging two sorted linked lists can be done in-place without extra space
4. The overall algorithm still runs in O(n log n) time
5. Unlike array-based merge sort, linked list merge sort can achieve O(1) auxiliary space

The key advantage is that we don't need to create temporary arrays during merging, making it more space-efficient than array-based merge sort.

### 8. How would you implement merge sort for very large datasets that don't fit in memory?

**Answer:** For datasets that don't fit in memory (external sorting):
1. **Chunk Processing**: Divide the data into manageable chunks that fit in memory
2. **Sort Chunks**: Sort each chunk using merge sort or another efficient algorithm
3. **Write to Disk**: Write sorted chunks back to disk
4. **K-way Merge**: Use a priority queue to efficiently merge multiple sorted chunks
5. **Streaming**: Process the data in a streaming fashion to minimize I/O operations

This approach is called external merge sort and has O(n log n) time complexity with controlled memory usage.

### 9. What is the minimum number of comparisons needed to merge two sorted arrays of size m and n?

**Answer:** The minimum number of comparisons needed to merge two sorted arrays of size m and n is **max(0, m+n-1)**.
- In the best case, all elements of one array are smaller than all elements of the other, potentially requiring m+n-1 comparisons
- Each comparison decides the next element to place in the merged array
- To place all m+n elements, we need at least m+n-1 decisions

### 10. How does merge sort perform on partially sorted arrays compared to other algorithms?

**Answer:** Merge sort performs consistently with O(n log n) time complexity regardless of the initial order:
- Unlike insertion sort or timsort, standard merge sort doesn't adapt to take advantage of existing order
- On partially sorted arrays, algorithms like insertion sort (O(n + d) where d is the number of inversions) or timsort (adaptive merge sort) may outperform standard merge sort
- However, merge sort can be modified to be adaptive by checking if subarrays are already sorted before merging

## LeetCode Practice Problems

Here are 8 LeetCode problems that involve merge sort concepts or can be solved using merge sort:

### 1. [#88 - Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

**Problem:** Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

**Solution Approach:** Use the merge portion of merge sort, starting from the end of the arrays to avoid overwriting elements in nums1.

### 2. [#21 - Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

**Problem:** Merge two sorted linked lists and return it as a new sorted list.

**Solution Approach:** Apply the merge process of merge sort to combine the two lists by comparing nodes and building a new sorted list.

### 3. [#148 - Sort List](https://leetcode.com/problems/sort-list/)

**Problem:** Sort a linked list in O(n log n) time and O(1) space.

**Solution Approach:** Implement merge sort for linked lists using the slow-fast pointer technique to find the middle and merge the sorted halves.

### 4. [#315 - Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

**Problem:** For each element, count the number of smaller elements to its right.

**Solution Approach:** Use a modified merge sort to count inversions while sorting the array.

### 5. [#493 - Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)

**Problem:** Count the number of important reverse pairs in an array.

**Solution Approach:** Apply a modified merge sort to efficiently count pairs while sorting.

### 6. [#327 - Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/)

**Problem:** Count the number of range sums that lie in a given range.

**Solution Approach:** Use merge sort on prefix sums to efficiently count ranges within the specified bounds.

### 7. [#23 - Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

**Problem:** Merge k sorted linked lists into one sorted linked list.

**Solution Approach:** Apply divide and conquer technique (similar to merge sort) by repeatedly merging pairs of lists until only one list remains.

### 8. [#912 - Sort an Array](https://leetcode.com/problems/sort-an-array/)

**Problem:** Sort an array of integers.

**Solution Approach:** Implement merge sort to sort the array in O(n log n) time complexity.

---

## Further Reading

- [Introduction to Algorithms (CLRS)](https://mitpress.mit.edu/books/introduction-algorithms-third-edition) - Contains a detailed analysis of merge sort
- [The Art of Computer Programming, Volume 3: Sorting and Searching](https://www-cs-faculty.stanford.edu/~knuth/taocp.html) by Donald Knuth
- [Algorithms, 4th Edition](https://algs4.cs.princeton.edu/) by Robert Sedgewick and Kevin Wayne
