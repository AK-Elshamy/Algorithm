# 📚 Comprehensive Guide to Insertion Sort

## 🔍 What is Insertion Sort?

Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time. It's much like sorting playing cards in your hand—you pick up one card at a time and insert it into its correct position relative to the cards you already have.

> **Highlight:** Insertion sort is efficient for small data sets and nearly sorted arrays!

## 🧠 How Insertion Sort Works: Incremental Thinking

Insertion sort follows a step-by-step approach that's easy to understand:

1. 🏁 Start with the second element (index 1), considering the first element as already sorted
2. 🔄 Compare the current element with the previous elements
3. 📥 Insert the current element into its correct position among the sorted elements
4. 🔁 Repeat for all elements in the array

### 🎬 Visual Representation

Let's visualize the process with an example array: [5, 2, 4, 6, 1, 3]

```
Initial Array: [5, 2, 4, 6, 1, 3]

Pass 1: [5, 2, 4, 6, 1, 3] → [2, 5, 4, 6, 1, 3]
        ^^^^                  ^^^^
        Compare 2 with 5, 2 is smaller, so insert 2 before 5

Pass 2: [2, 5, 4, 6, 1, 3] → [2, 4, 5, 6, 1, 3]
           ^^^^                ^^^^
           Compare 4 with 5, 4 is smaller, so insert 4 before 5

Pass 3: [2, 4, 5, 6, 1, 3] → [2, 4, 5, 6, 1, 3]
              ^^^^             (no change, 6 > 5)
              6 is already in correct position

Pass 4: [2, 4, 5, 6, 1, 3] → [1, 2, 4, 5, 6, 3]
                 ^^^^          ^^^^
                 Compare 1 with all previous, insert at beginning

Pass 5: [1, 2, 4, 5, 6, 3] → [1, 2, 3, 4, 5, 6]
                    ^^^^       ^^^^
                    Compare 3 with previous, insert after 2

Final Sorted Array: [1, 2, 3, 4, 5, 6]
```

## 💻 Implementation in Multiple Languages

### C++

```cpp
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Current element to be compared
        int j = i - 1;
        
        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Insert key at its correct position
    }
}

// Example usage
int main() {
    std::vector<int> arr = {5, 2, 4, 6, 1, 3};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    
    insertionSort(arr);
    
    std::cout << "\nSorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    
    return 0;
}
```

### Java

```java
import java.util.Arrays;

public class InsertionSort {
    public static void insertionSort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            int key = arr[i];  // Current element to be compared
            int j = i - 1;
            
            // Move elements greater than key to one position ahead
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;  // Insert key at its correct position
        }
    }
    
    // Example usage
    public static void main(String[] args) {
        int[] arr = {5, 2, 4, 6, 1, 3};
        
        System.out.println("Original array: " + Arrays.toString(arr));
        
        insertionSort(arr);
        
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
```

### Python

```python
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]  # Current element to be compared
        j = i - 1
        
        # Move elements greater than key to one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key  # Insert key at its correct position

# Example usage
if __name__ == "__main__":
    arr = [5, 2, 4, 6, 1, 3]
    
    print(f"Original array: {arr}")
    
    insertion_sort(arr)
    
    print(f"Sorted array: {arr}")
```

## ⏱️ Time and Space Complexity

- **Time Complexity**:
  - 🔶 **Best Case**: O(n) - Already sorted array
  - 🔴 **Average Case**: O(n²)
  - 🔴 **Worst Case**: O(n²) - Reverse sorted array

- **Space Complexity**: 
  - 🟢 O(1) - In-place sorting algorithm

## 🎯 Key Properties of Insertion Sort

- ✅ **Stable**: Preserves the relative order of equal elements
- ✅ **In-place**: Only requires a constant amount of additional space
- ✅ **Online**: Can sort a list as it receives it
- ✅ **Adaptive**: Performance improves when array is partially sorted

## 🏢 Major Company Interview Questions with Answers

### Question 1: What is the time complexity of insertion sort? When would you choose insertion sort over other sorting algorithms?

**Answer**: The time complexity of insertion sort is O(n²) in the worst and average cases, and O(n) in the best case (when the array is already sorted). I would choose insertion sort when:
- Working with small datasets (typically less than 10-20 elements)
- Handling arrays that are already nearly sorted
- Implementing an online algorithm where items are received one at a time
- Memory usage is a concern (as it's in-place)
- A simple, reliable sorting algorithm is needed for educational purposes

### Question 2: How does insertion sort compare to bubble sort and selection sort?

**Answer**: All three algorithms have a worst-case time complexity of O(n²), but they differ in several ways:
- **Insertion Sort**: Generally performs better in practice than both bubble and selection sort. It's adaptive (runs faster on partially sorted arrays) and is stable.
- **Bubble Sort**: Usually the slowest of the three. It repeatedly steps through the list and swaps adjacent elements that are in the wrong order.
- **Selection Sort**: Finds the minimum element and puts it at the beginning in each pass. It performs a fixed number of comparisons regardless of initial order, making it non-adaptive.

Insertion sort typically requires fewer comparisons than bubble sort and fewer swaps than selection sort for partially sorted data.

### Question 3: Explain how you would modify insertion sort to sort an array in descending order.

**Answer**: To modify insertion sort for descending order, I would change the comparison operator from `>` to `<`. Here's how it would look in Python:

```python
def insertion_sort_descending(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        
        # Change condition from > to <
        while j >= 0 and arr[j] < key:  # Change here
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
```

### Question 4: Can insertion sort be used for linked lists? If yes, would it be more efficient than for arrays?

**Answer**: Yes, insertion sort can be implemented for linked lists. In fact, it can be more efficient for linked lists than for arrays because:
- Insertion in a linked list only requires updating a few pointers, which is O(1)
- No need to shift elements as in arrays
- Can be implemented with O(1) space complexity

The time complexity remains O(n²), but the constant factors are smaller since element shifting is eliminated. The algorithm would maintain a sorted portion of the list and insert each new node into its correct position.

### Question 5: How would you optimize insertion sort for nearly sorted arrays?

**Answer**: For nearly sorted arrays, insertion sort is already quite efficient (approaching O(n)). However, it can be further optimized by:
1. Using binary search instead of linear search to find the correct position for insertion (Binary Insertion Sort)
2. Using a gap sequence to allow elements to move multiple positions at once (like Shell Sort, which is a generalization of insertion sort)
3. Implementing early termination checks if no swaps are needed in a pass

These optimizations don't change the worst-case time complexity but can improve the average case performance, particularly for nearly sorted data.

### Question 6: Implement a version of insertion sort that counts the number of inversions in an array.

**Answer**:
```python
def insertion_sort_count_inversions(arr):
    inversions = 0
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            inversions += 1  # Count each swap as an inversion
            j -= 1
        arr[j + 1] = key
    
    return inversions
```

The number of inversions in an array is a measure of how far the array is from being sorted. For a sorted array, the inversion count is 0, while for a reverse sorted array, it's n(n-1)/2.

### Question 7: What is the space complexity of insertion sort when implemented recursively?

**Answer**: When implemented recursively, insertion sort would have a space complexity of O(n) due to the call stack. Each recursive call would consume additional space on the stack, with a maximum depth of n. This is in contrast to the iterative implementation which has O(1) space complexity.

Here's a sketch of a recursive implementation:
```python
def recursive_insertion_sort(arr, n):
    # Base case: if only one element or empty array
    if n <= 1:
        return
    
    # Sort first n-1 elements
    recursive_insertion_sort(arr, n-1)
    
    # Insert last element at its correct position in sorted array
    last = arr[n-1]
    j = n - 2
    
    while j >= 0 and arr[j] > last:
        arr[j + 1] = arr[j]
        j -= 1
    
    arr[j + 1] = last
```

### Question 8: In a database management system, when would insertion sort be preferred for sorting records?

**Answer**: In a database management system, insertion sort would be preferred when:
1. Sorting small tables or result sets (less than a few hundred records)
2. Records are being added incrementally and need to be maintained in sorted order
3. The data is already nearly sorted (e.g., when only a few new records are added to an already sorted table)
4. Memory is limited, as insertion sort doesn't require additional memory beyond the original data structure
5. The sorting operation needs to be stable (preserve the relative order of records with equal keys)

Modern database systems often use more sophisticated algorithms for large datasets, but insertion sort might be used as part of a hybrid approach, especially for in-memory sorting of small datasets.

### Question 9: How would you implement insertion sort for sorting strings lexicographically?

**Answer**: To implement insertion sort for sorting strings lexicographically, I would follow the same insertion sort algorithm but change the comparison to use string comparison:

```python
def insertion_sort_strings(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        
        # Use string comparison instead of numerical comparison
        while j >= 0 and arr[j] > key:  # String comparison
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
```

This works because most programming languages have built-in comparison operators for strings that compare them lexicographically. For example, in Python, Java, and C++, the `>` operator will compare strings based on their dictionary order.

### Question 10: Explain how binary insertion sort works and implement it.

**Answer**: Binary insertion sort is a variation of insertion sort that uses binary search to find the correct position to insert the current element, which reduces the number of comparisons.

The algorithm steps:
1. Start from the second element
2. Use binary search to find the correct position for the current element in the sorted portion
3. Shift elements to make space for insertion
4. Insert the element and repeat for all remaining elements

```python
def binary_search(arr, key, low, high):
    if high <= low:
        if key > arr[low]:
            return low + 1
        else:
            return low
    
    mid = (low + high) // 2
    
    if key == arr[mid]:
        return mid + 1
    
    if key > arr[mid]:
        return binary_search(arr, key, mid + 1, high)
    
    return binary_search(arr, key, low, mid - 1)

def binary_insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        
        # Find the position where key should be inserted using binary search
        location = binary_search(arr, key, 0, j)
        
        # Shift elements to make room for key
        while j >= location:
            arr[j + 1] = arr[j]
            j -= 1
        
        arr[j + 1] = key
```

While this reduces the number of comparisons from O(n²) to O(n log n), the number of shifts remains O(n²) in the worst case, so the overall time complexity is still O(n²).

## 💯 LeetCode Practice Questions

### Question 1: [LC #75] Sort Colors
Given an array with n objects colored red, white, or blue (represented by 0, 1, and 2), sort them in-place so that objects of the same color are adjacent.

**Example**:
```
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Solution using Insertion Sort**:
```python
def sortColors(nums):
    # Use insertion sort
    for i in range(1, len(nums)):
        key = nums[i]
        j = i - 1
        
        while j >= 0 and nums[j] > key:
            nums[j + 1] = nums[j]
            j -= 1
        nums[j + 1] = key
```

### Question 2: [LC #147] Insertion Sort List
Sort a linked list using insertion sort.

**Example**:
```
Input: 4->2->1->3
Output: 1->2->3->4
```

**Solution**:
```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def insertionSortList(head):
    if not head or not head.next:
        return head
    
    dummy = ListNode(0)  # Create a dummy node to act as the sorted list head
    curr = head  # Node to be inserted
    
    while curr:
        # Save the next node to insert
        next_node = curr.next
        
        # Find the position to insert current node
        prev = dummy
        temp = dummy.next
        
        while temp and temp.val < curr.val:
            prev = temp
            temp = temp.next
        
        # Insert the current node
        curr.next = temp
        prev.next = curr
        
        # Move to next node
        curr = next_node
    
    return dummy.next
```

### Question 3: [LC #280] Wiggle Sort
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

**Example**:
```
Input: [3,5,2,1,6,4]
Output: [1,6,2,5,3,4] or any valid wiggle sort
```

**Solution using modified insertion sort**:
```python
def wiggleSort(nums):
    for i in range(1, len(nums)):
        # If at odd index, should be greater than neighbors
        if i % 2 == 1 and nums[i] < nums[i-1]:
            nums[i], nums[i-1] = nums[i-1], nums[i]
        # If at even index, should be less than neighbors
        elif i % 2 == 0 and i > 0 and nums[i] > nums[i-1]:
            nums[i], nums[i-1] = nums[i-1], nums[i]
```

### Question 4: [LC #969] Pancake Sorting
Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of A. Return the k-values corresponding to a sequence of pancake flips that sort A.

**Example**:
```
Input: [3,2,4,1]
Output: [3,4,2,4,1]
Explanation: 
We perform 5 pancake flips, with k values 3, 4, 2, 4, 1.
```

**Solution using a variation of insertion sort**:
```python
def pancakeSort(arr):
    result = []
    n = len(arr)
    
    # Find the maximum element in arr[0...n-i-1] and move it to the end
    for i in range(n):
        max_idx = arr.index(max(arr[:n-i]))
        
        # If max element is not at the beginning, flip it to the beginning
        if max_idx != 0:
            result.append(max_idx + 1)
            arr[:max_idx+1] = arr[:max_idx+1][::-1]
        
        # Now flip the max element to its final position
        result.append(n - i)
        arr[:n-i] = arr[:n-i][::-1]
    
    return result
```

### Question 5: [LC #452] Minimum Number of Arrows to Burst Balloons
Find the minimum number of arrows that must be shot to burst all balloons. Each arrow can be shot at a point on the x-axis and bursts all balloons whose intervals contain that point.

**Example**:
```
Input: [[10,16],[2,8],[1,6],[7,12]]
Output: 2
```

**Solution using insertion sort and greedy approach**:
```python
def findMinArrowShots(points):
    if not points:
        return 0
    
    # Sort points by end position using insertion sort
    for i in range(1, len(points)):
        key = points[i]
        j = i - 1
        while j >= 0 and points[j][1] > key[1]:
            points[j + 1] = points[j]
            j -= 1
        points[j + 1] = key
    
    arrows = 1
    end = points[0][1]
    
    for point in points[1:]:
        if point[0] > end:
            arrows += 1
            end = point[1]
    
    return arrows
```

### Question 6: [LC #922] Sort Array By Parity II
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even. Sort the array so that A[0] is even, A[1] is odd, A[2] is even, and so on.

**Example**:
```
Input: [4,2,5,7]
Output: [4,5,2,7]
```

**Solution using insertion sort variant**:
```python
def sortArrayByParityII(A):
    result = [0] * len(A)
    even_idx = 0
    odd_idx = 1
    
    for num in A:
        if num % 2 == 0:
            result[even_idx] = num
            even_idx += 2
        else:
            result[odd_idx] = num
            odd_idx += 2
    
    return result
```

### Question 7: [LC #242] Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s.

**Example**:
```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Solution using sorting approach (insertion sort)**:
```python
def isAnagram(s, t):
    if len(s) != len(t):
        return False
    
    # Convert strings to lists for sorting
    s_list = list(s)
    t_list = list(t)
    
    # Sort both lists using insertion sort
    def insertion_sort(arr):
        for i in range(1, len(arr)):
            key = arr[i]
            j = i - 1
            while j >= 0 and arr[j] > key:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = key
    
    insertion_sort(s_list)
    insertion_sort(t_list)
    
    # Compare sorted strings
    return s_list == t_list
```

### Question 8: [LC #1366] Rank Teams by Votes
In a voting system, each voter gives a ranking of all teams from highest to lowest preference. The ordering of teams is decided by who received the most first-place votes. If two or more teams tie in the first-place votes, we consider the second-place votes and so on.

**Example**:
```
Input: ["ABC","ACB","ABC","ACB","ACB"]
Output: "ACB"
```

**Solution using custom insertion sort**:
```python
def rankTeams(votes):
    if len(votes) == 1:
        return votes[0]
    
    # Count votes for each position
    teams = {team: [0] * len(votes[0]) for team in votes[0]}
    
    for vote in votes:
        for position, team in enumerate(vote):
            teams[team][position] -= 1  # Negative because we want to sort in descending order
    
    # Convert to list of tuples (team, scores) for sorting
    teams_list = [(team, scores + [team]) for team, scores in teams.items()]
    
    # Use insertion sort to sort based on scores and then team name
    for i in range(1, len(teams_list)):
        key = teams_list[i]
        j = i - 1
        while j >= 0 and teams_list[j][1] > key[1]:
            teams_list[j + 1] = teams_list[j]
            j -= 1
        teams_list[j + 1] = key
    
    # Return the sorted teams as a string
    return ''.join(team for team, _ in teams_list)
```

## 📊 When to Use Insertion Sort

- ✓ **Small data sets**: Efficient for arrays with fewer than 20 elements
- ✓ **Nearly sorted data**: Performs very well with arrays that are already almost sorted
- ✓ **Online processing**: Good when elements arrive one at a time and need to be inserted into a sorted array
- ✓ **Limited memory**: In-place algorithm with minimal space requirements
- ✓ **Simple implementation**: Easy to code and debug

## 📋 Summary

Insertion Sort is a simple, efficient sorting algorithm for small data sets or nearly sorted arrays. It works by building a sorted array one element at a time, much like sorting a hand of playing cards.

Key takeaways:
- ⏱️ **Time Complexity**: O(n²) worst case, O(n) best case
- 🧮 **Space Complexity**: O(1) in-place sorting
- 👍 **Pros**: Simple, stable, adaptive, good for small datasets
- 👎 **Cons**: Inefficient for large datasets compared to advanced algorithms like Quick Sort or Merge Sort

Insertion Sort may not be the fastest algorithm for large datasets, but its simplicity, stability, and efficiency for small or nearly-sorted datasets make it a valuable tool in a programmer's toolkit.