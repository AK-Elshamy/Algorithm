# Depth-First Search (DFS)

## Table of Contents
- [Introduction to DFS](#introduction-to-dfs)
- [How DFS Works](#how-dfs-works)
- [DFS Algorithm](#dfs-algorithm)
- [Pseudocode](#pseudocode)
- [Implementation Examples](#implementation-examples)
  - [C++ Implementation](#c-implementation)
  - [Java Implementation](#java-implementation)
  - [Python Implementation](#python-implementation)
- [DFS Variations](#dfs-variations)
- [Applications of DFS](#applications-of-dfs)
- [Advantages and Disadvantages](#advantages-and-disadvantages)
- [DFS vs BFS](#dfs-vs-bfs)
- [Practice Problems](#practice-problems)

## Introduction to DFS

Depth-First Search (DFS) is a graph traversal algorithm that explores as far as possible along each branch before backtracking. Starting from a selected node (the "source"), DFS explores deeper into the graph by visiting an adjacent unvisited vertex, then continues from that vertex, and backtracks only when it reaches a vertex with no unvisited adjacent vertices.

DFS is analogous to walking through a maze with a strategy of always exploring as far as possible and only backtracking when you hit a dead end.

## How DFS Works

1. Start at a source vertex and mark it as visited
2. Visit any one of its adjacent unvisited vertices
3. Continue this process (recursively) until there are no more unvisited vertices
4. Backtrack and explore other unvisited vertices

DFS can be implemented using:
- **Recursion**: Natural approach using function call stack
- **Explicit Stack**: Iterative approach using a stack data structure

Both approaches follow the Last-In-First-Out (LIFO) principle, which is the key characteristic of DFS.

## DFS Algorithm

The distinguishing feature of DFS is its depth-first nature, exploring a path to its full depth before exploring alternatives.

![DFS Visual Example](https://via.placeholder.com/500x300?text=DFS+Visualization)

Given a graph and a source vertex:
1. Mark the source vertex as visited
2. For each unvisited neighbor of the source:
   - Recursively perform DFS on that neighbor
3. When no more unvisited neighbors exist, backtrack

## Pseudocode

### Recursive Implementation
```
DFS(Graph G, Vertex source):
    // Mark current vertex as visited
    visited[source] = true
    
    // Process current vertex
    process(source)
    
    // Visit all adjacent vertices
    for each neighbor of source:
        if neighbor is not visited:
            DFS(G, neighbor)
```

### Iterative Implementation
```
DFS_Iterative(Graph G, Vertex source):
    // Initialize data structures
    Stack s = new Stack()
    Set visited = new Set()
    
    // Start from the source vertex
    s.push(source)
    
    while s is not empty:
        vertex = s.pop()
        
        if vertex is not in visited:
            // Mark as visited and process
            visited.add(vertex)
            process(vertex)
            
            // Add all unvisited neighbors to the stack
            for each neighbor of vertex:
                if neighbor is not in visited:
                    s.push(neighbor)
```

## Implementation Examples

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Recursive DFS
void DFS_recursive(vector<vector<int>>& graph, vector<bool>& visited, int vertex) {
    // Mark the current vertex as visited and print it
    visited[vertex] = true;
    cout << vertex << " ";
    
    // Recur for all the adjacent vertices
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            DFS_recursive(graph, visited, neighbor);
        }
    }
}

// Iterative DFS
void DFS_iterative(vector<vector<int>>& graph, int source) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;
    
    // Push the source vertex
    s.push(source);
    
    while (!s.empty()) {
        // Pop a vertex from stack
        int vertex = s.top();
        s.pop();
        
        // If not visited, mark as visited and process it
        if (!visited[vertex]) {
            cout << vertex << " ";
            visited[vertex] = true;
            
            // Push all adjacent vertices that are not visited
            for (int i = graph[vertex].size() - 1; i >= 0; i--) {
                int neighbor = graph[vertex][i];
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

// Driver code
int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},    // Node 0 is connected to 1, 2
        {0, 3, 4}, // Node 1 is connected to 0, 3, 4
        {0, 5},    // Node 2 is connected to 0, 5
        {1},       // Node 3 is connected to 1
        {1, 6},    // Node 4 is connected to 1, 6
        {2},       // Node 5 is connected to 2
        {4}        // Node 6 is connected to 4
    };
    
    int n = graph.size();
    vector<bool> visited(n, false);
    
    cout << "Recursive DFS traversal starting from vertex 0: ";
    DFS_recursive(graph, visited, 0);
    cout << endl;
    
    cout << "Iterative DFS traversal starting from vertex 0: ";
    DFS_iterative(graph, 0);
    cout << endl;
    
    return 0;
}
```

### Java Implementation

```java
import java.util.*;

public class DFSExample {
    private int V; // Number of vertices
    private LinkedList<Integer>[] adj; // Adjacency list
    
    // Constructor
    DFSExample(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList<>();
    }
    
    // Add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].add(w);
    }
    
    // Recursive DFS
    void DFS_recursive(int v, boolean[] visited) {
        // Mark the current node as visited and print it
        visited[v] = true;
        System.out.print(v + " ");
        
        // Recur for all vertices adjacent to this vertex
        for (Integer neighbor : adj[v]) {
            if (!visited[neighbor])
                DFS_recursive(neighbor, visited);
        }
    }
    
    // Iterative DFS
    void DFS_iterative(int source) {
        // Mark all vertices as not visited
        boolean[] visited = new boolean[V];
        
        // Create a stack for DFS
        Stack<Integer> stack = new Stack<>();
        
        // Push the source vertex
        stack.push(source);
        
        while (!stack.empty()) {
            // Pop a vertex from stack
            source = stack.pop();
            
            // If not visited, mark as visited and process it
            if (!visited[source]) {
                System.out.print(source + " ");
                visited[source] = true;
                
                // Push all adjacent vertices that are not visited
                for (int i = adj[source].size() - 1; i >= 0; i--) {
                    Integer neighbor = adj[source].get(i);
                    if (!visited[neighbor])
                        stack.push(neighbor);
                }
            }
        }
    }
    
    // Driver code
    public static void main(String[] args) {
        DFSExample g = new DFSExample(7);
        
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 0);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 0);
        g.addEdge(2, 5);
        g.addEdge(3, 1);
        g.addEdge(4, 1);
        g.addEdge(4, 6);
        g.addEdge(5, 2);
        g.addEdge(6, 4);
        
        System.out.println("Recursive DFS traversal starting from vertex 0:");
        g.DFS_recursive(0, new boolean[7]);
        
        System.out.println("\nIterative DFS traversal starting from vertex 0:");
        g.DFS_iterative(0);
    }
}
```

### Python Implementation

```python
from collections import defaultdict

class Graph:
    def __init__(self):
        # Default dictionary to store the graph
        self.graph = defaultdict(list)
    
    # Function to add an edge to the graph
    def add_edge(self, u, v):
        self.graph[u].append(v)
    
    # Recursive function for DFS
    def dfs_recursive(self, vertex, visited):
        # Mark the current node as visited and print it
        visited.add(vertex)
        print(vertex, end=" ")
        
        # Recur for all adjacent vertices
        for neighbor in self.graph[vertex]:
            if neighbor not in visited:
                self.dfs_recursive(neighbor, visited)
    
    # DFS traversal using recursion
    def dfs(self, source):
        # Create a set to store visited vertices
        visited = set()
        self.dfs_recursive(source, visited)
    
    # Iterative DFS
    def dfs_iterative(self, source):
        # Create a set to store visited vertices
        visited = set()
        # Create a stack for DFS
        stack = []
        
        # Push the source vertex
        stack.append(source)
        
        while stack:
            # Pop a vertex from stack
            vertex = stack.pop()
            
            # If not visited, mark as visited and process it
            if vertex not in visited:
                print(vertex, end=" ")
                visited.add(vertex)
                
                # Push all adjacent vertices that are not visited
                for neighbor in reversed(self.graph[vertex]):
                    if neighbor not in visited:
                        stack.append(neighbor)

# Driver code
if __name__ == "__main__":
    g = Graph()
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 0)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    g.add_edge(2, 0)
    g.add_edge(2, 5)
    g.add_edge(3, 1)
    g.add_edge(4, 1)
    g.add_edge(4, 6)
    g.add_edge(5, 2)
    g.add_edge(6, 4)
    
    print("Recursive DFS traversal starting from vertex 0:")
    g.dfs(0)
    
    print("\nIterative DFS traversal starting from vertex 0:")
    g.dfs_iterative(0)
```

## DFS Variations

### Pre-order DFS
- Process the current vertex before visiting its children
- Useful for creating a copy of a tree or getting a prefix expression

### Post-order DFS
- Process the current vertex after visiting its children
- Useful for deleting a tree or getting a postfix expression

### In-order DFS (for binary trees)
- Process the left subtree, then the current node, then the right subtree
- Useful for getting elements in sorted order in a binary search tree

## Applications of DFS

1. **Topological Sorting**: For scheduling tasks with dependencies (e.g., course prerequisites).

2. **Cycle Detection**: Finding cycles in directed or undirected graphs.

3. **Path Finding**: Finding paths between two vertices.

4. **Strongly Connected Components**: Identifying strongly connected components in directed graphs.

5. **Maze Generation and Solving**: Creating and solving mazes.

6. **Generating Spanning Trees**: Creating spanning trees of graphs.

7. **Finding Articulation Points and Bridges**: Identifying critical vertices and edges in networks.

8. **Biconnected Components**: Finding components that remain connected when any single vertex is removed.

## Advantages and Disadvantages

### Advantages
- ✅ Uses less memory than BFS for wide graphs
- ✅ Naturally suited for problems that need to search all possibilities
- ✅ Easily implemented using recursion
- ✅ Well-suited for finding nodes far away from the source

### Disadvantages
- ❌ May get stuck in very deep paths
- ❌ Does not guarantee the shortest path
- ❌ Can lead to stack overflow for very deep graphs when implemented recursively
- ❌ Less efficient than BFS for finding shortest paths

## DFS vs BFS

| Characteristic | DFS | BFS |
|----------------|-----|-----|
| Data Structure | Stack (LIFO) | Queue (FIFO) |
| Memory Usage | Higher for deep graphs | Higher for wide graphs |
| Path Finding | May not find shortest path | Finds shortest path in unweighted graphs |
| Implementation | Naturally recursive | Typically iterative |
| When to use | When searching all possibilities | When target is likely close to source |
| Completeness | Complete only if graph is finite | Complete (finds a solution if one exists) |
| Branching Factor | Better for large branching factor | Better for small branching factor |

## Practice Problems

1. [Leetcode #733 - Flood Fill](https://leetcode.com/problems/flood-fill/)
2. [Leetcode #207 - Course Schedule](https://leetcode.com/problems/course-schedule/)
3. [Leetcode #547 - Number of Provinces](https://leetcode.com/problems/number-of-provinces/)
4. [Leetcode #695 - Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
5. [Leetcode #417 - Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/)

These problems provide excellent practice for applying DFS in different contexts and will help soli