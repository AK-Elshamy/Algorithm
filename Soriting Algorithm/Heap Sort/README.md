# Heap Sort Algorithm: Complete Guide
 
## Table of Contents
- [Introduction to Heap Sort](#introduction-to-heap-sort)
- [Understanding Heaps](#understanding-heaps)
  - [Max Heap](#max-heap)
  - [Min Heap](#min-heap)
- [Heap Sort Algorithm Step-by-Step](#heap-sort-algorithm-step-by-step)
- [Implementation](#implementation)
  - [C++ Implementation](#c-implementation)
  - [Java Implementation](#java-implementation)
  - [Python Implementation](#python-implementation)
- [Complexity Analysis](#complexity-analysis)
- [Interview Questions & Answers](#interview-questions--answers)
- [Practice Problems](#practice-problems)

## Introduction to Heap Sort

Heap Sort is an efficient, comparison-based sorting algorithm that uses a binary heap data structure. It's similar to Selection Sort where we find the maximum element and place it at the end, but Heap Sort does this more efficiently using the heap property.

> 🌟 **Key Benefit**: Heap Sort combines the speed of Quick Sort with the reliable O(n log n) worst-case performance of Merge Sort!

## Understanding Heaps

A heap is a specialized tree-based data structure that satisfies the heap property:

### Max Heap

In a **Max Heap** 🔺, the parent node is always **greater than or equal to** its children.

```
       100
      /   \
    19     36
   / \    /  \
  17  3  25  1
```

> 💡 **Max Heap Property**: For every node `i`, the value of `i` is ≥ the values of its children

### Min Heap

In a **Min Heap** 🔻, the parent node is always **less than or equal to** its children.

```
        1
      /   \
    15     5
   / \    / \
  30 40  10 18
```

> 💡 **Min Heap Property**: For every node `i`, the value of `i` is ≤ the values of its children

## Heap Sort Algorithm Step-by-Step

Here's how Heap Sort works (using Max Heap for ascending order):

1. **Build Max Heap** 🔨: Convert the array into a max heap
2. **Extract Elements** 🔄: Repeatedly extract the maximum element from the heap
   - Swap the root (max element) with the last element
   - Reduce heap size by 1
   - Heapify the root to maintain the max heap property

Let's visualize the process with an example:

**Initial Array**: [4, 10, 3, 5, 1]

**Step 1**: Build max heap
```
        10
       /  \
      5    3
     / \
    4   1
```

**Step 2**: Extract elements one by one
- Swap 10 and 1: [4, 5, 3, 1, 10]
- Heapify: [4, 5, 3, 1] (now 10 is sorted)
```
        5
       / \
      4   3
     /
    1
```

Continue this process until all elements are sorted.

## Implementation

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

// To heapify a subtree rooted with node i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // left child
    int right = 2 * i + 2;    // right child
  
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
  
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
  
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);  // Recursively heapify the affected sub-tree
    }
}
  
// Main function to do heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();
  
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        
        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original array is: ";
    printArray(arr);
  
    heapSort(arr);
  
    cout << "Sorted array is: ";
    printArray(arr);
    return 0;
}
```

### Java Implementation

```java
public class HeapSort {
    public void sort(int[] arr) {
        int n = arr.length;
  
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
  
        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
  
            // Call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }
  
    // To heapify a subtree rooted with node i
    void heapify(int[] arr, int n, int i) {
        int largest = i;  // Initialize largest as root
        int left = 2 * i + 1;  // left child
        int right = 2 * i + 2;  // right child
  
        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;
  
        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;
  
        // If largest is not root
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
  
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }
  
    // Driver code
    public static void main(String[] args) {
        int[] arr = {12, 11, 13, 5, 6, 7};
        System.out.print("Original array: ");
        printArray(arr);
        
        HeapSort heapSort = new HeapSort();
        heapSort.sort(arr);
  
        System.out.print("Sorted array: ");
        printArray(arr);
    }
    
    static void printArray(int[] arr) {
        for (int i : arr)
            System.out.print(i + " ");
        System.out.println();
    }
}
```

### Python Implementation

```python
def heapify(arr, n, i):
    # Initialize largest as root
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    # If left child is larger than root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # If right child is larger than largest so far
    if right < n and arr[right] > arr[largest]:
        largest = right

    # If largest is not root
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # swap
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    # Build a max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements one by one
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # swap
        heapify(arr, i, 0)

    return arr

# Example usage
if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 7]
    print(f"Original array: {arr}")
    heap_sort(arr)
    print(f"Sorted array: {arr}")
```

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|-----------------|
| **Best Case** | O(n log n) | O(1) |
| **Average Case** | O(n log n) | O(1) |
| **Worst Case** | O(n log n) | O(1) |

> ✨ **Highlights**:
> - Heap Sort is an in-place algorithm (only requires O(1) extra space)
> - Guaranteed O(n log n) time complexity even in worst case
> - Not stable (relative order of equal elements may change)
> - Typically slower than Quick Sort in practice despite similar complexity

## Interview Questions & Answers

### Q1: What is a heap data structure?
**A**: A heap is a complete binary tree that satisfies the heap property. In a max heap, each parent node is greater than or equal to its children, while in a min heap, each parent is less than or equal to its children. Heaps are commonly implemented as arrays, where for an element at index i, its left child is at 2i+1, right child at 2i+2, and parent at (i-1)/2.

### Q2: What's the difference between a Max Heap and a Min Heap?
**A**: In a Max Heap, the key at the root must be maximum among all keys in the heap, and the same property must be recursively true for all nodes. In a Min Heap, the key at the root must be minimum among all keys, with this property recursively applying to all nodes. Max heaps are typically used for heap sort to sort in ascending order, while min heaps would be used to sort in descending order.

### Q3: Why is Heap Sort preferred over other sorting algorithms in certain scenarios?
**A**: Heap Sort is preferred when a guaranteed O(n log n) time complexity is needed, regardless of the input data. Unlike Quick Sort, it doesn't degrade to O(n²) in worst-case scenarios. It's also an in-place algorithm requiring only O(1) auxiliary space, making it suitable for memory-constrained environments. Additionally, for systems that need to perform frequent insertion and deletion of elements while maintaining a sorted structure, heaps provide an efficient solution.

### Q4: How would you build a min heap from an array of integers?
**A**: To build a min heap:
1. Start with the array as is
2. Beginning from the last non-leaf node (at index n/2-1, where n is array length), call the min-heapify function
3. Continue this process for all nodes up to the root
4. The min-heapify function ensures that for any node i, the subtree rooted at i satisfies the min-heap property by:
   - Finding the smallest among the node and its children
   - If the smallest isn't the node itself, swapping and recursively heapifying the affected subtree

### Q5: Can Heap Sort be implemented as a stable sort? Why or why not?
**A**: No, Heap Sort cannot be implemented as a stable sort without significant modifications that would compromise its efficiency. A stable sort preserves the relative order of equal elements. In Heap Sort, when elements are swapped during the heapify process, their original positions are not tracked or preserved. Equal elements might be swapped multiple times based on heap restructuring without regard to their original positions. Making Heap Sort stable would require additional storage and tracking mechanisms, effectively changing its nature and complexity.

### Q6: What is the time complexity for building a heap and why?
**A**: The time complexity for building a heap is O(n), not O(n log n) as might be initially expected. While heapifying a single node takes O(log n) time, and we do this for approximately n/2 nodes, the actual complexity is O(n) due to:
1. The leaf nodes (approximately n/2) require no heapify operations
2. As we move up the tree, nodes have progressively smaller subtrees to heapify
3. The mathematical analysis involves a sum of decreasing terms that converges to O(n)

This is a common interview trap question—many candidates incorrectly answer O(n log n).

### Q7: How would you find the kth largest element in an array using heaps?
**A**: To find the kth largest element:
1. Build a min heap of size k with the first k elements of the array, taking O(k) time
2. For each remaining element in the array:
   - If it's larger than the root of the min heap, remove the root and insert this element
   - If it's smaller or equal, ignore it
3. After processing all elements, the root of the min heap will contain the kth largest element

This algorithm has O(n log k) time complexity, which is more efficient than sorting the entire array when k is much smaller than n.

### Q8: How would you implement a priority queue using a heap?
**A**: A priority queue can be implemented using a heap as follows:
- For highest-priority-first queues: use a max heap
- For lowest-priority-first queues: use a min heap
- Operations:
  - insert(item, priority): Add the item to the heap based on priority, then bubble up to maintain heap property - O(log n)
  - extractMax()/extractMin(): Remove and return the root element, replace it with the last element, then heapify down - O(log n)
  - peek(): Return the root element without removing it - O(1)
  - decreaseKey()/increaseKey(): Update priority and restore heap property - O(log n)

Priority queues are used in Dijkstra's algorithm, Prim's algorithm, and many scheduling applications.

### Q9: What modifications would you make to implement Heap Sort for sorting in descending order?
**A**: To implement Heap Sort for descending order:
1. Use a min heap instead of a max heap
2. Build the min heap from the input array
3. Repeatedly extract the minimum element and place it at the end of the array
4. After each extraction, reduce the heap size and heapify the root

Alternatively, you could:
1. Use the standard max heap implementation
2. After sorting is complete, reverse the array

The first approach is generally preferred as it avoids the additional reversal step.

### Q10: Compare Heap Sort with Quick Sort and Merge Sort. When would you choose one over the others?
**A**: 
- **Heap Sort**:
  - Guaranteed O(n log n) time complexity
  - In-place with O(1) auxiliary space
  - Not stable
  - Typically slower than Quick Sort due to more comparisons and poor cache locality
  
- **Quick Sort**:
  - Average case O(n log n), worst case O(n²)
  - In-place with O(log n) stack space
  - Not stable in standard implementation
  - Often fastest in practice due to good cache locality
  
- **Merge Sort**:
  - Guaranteed O(n log n) time complexity
  - Requires O(n) auxiliary space
  - Stable
  - Good for external sorting and linked lists

Choose:
- **Heap Sort** when:
  - Guaranteed performance is needed
  - Memory space is at a premium
  - You're concerned about Quick Sort's worst-case behavior
  
- **Quick Sort** when:
  - Average performance matters most
  - In-place sorting is required
  - Input is expected to be random
  
- **Merge Sort** when:
  - Stability is required
  - External sorting is needed
  - Sorting linked lists

## Practice Problems

Here are some LeetCode problems to practice heap operations and sorting:

1. [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
2. [347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
3. [23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
4. [295. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)
5. [973. K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)
6. [703. Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
7. [692. Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/)
8. [1046. Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)
9. [253. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)
10. [1642. Furthest Building You Can Reach](https://leetcode.com/problems/furthest-building-you-can-reach/)
---