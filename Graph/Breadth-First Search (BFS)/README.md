# Breadth-First Search (BFS)

## Table of Contents
- [Introduction to BFS](#introduction-to-bfs)
- [How BFS Works](#how-bfs-works)
- [BFS Algorithm](#bfs-algorithm)
- [Pseudocode](#pseudocode)
- [Implementation Examples](#implementation-examples)
  - [C++ Implementation](#c-implementation)
  - [Java Implementation](#java-implementation)
  - [Python Implementation](#python-implementation)
- [Applications of BFS](#applications-of-bfs)
- [Advantages and Disadvantages](#advantages-and-disadvantages)
- [BFS vs DFS](#bfs-vs-dfs)
- [Practice Problems](#practice-problems)

## Introduction to BFS

Breadth-First Search (BFS) is a graph traversal algorithm that explores all vertices at the current depth level before moving to vertices at the next depth level. It starts at a selected node (the "source" or "root") and explores all neighboring nodes at the present depth before moving on to nodes at the next depth level.

BFS effectively expands like a ripple in water, moving outward from the starting point in all directions simultaneously.

## How BFS Works

1. Start at a source vertex and mark it as visited
2. Add the source vertex to a queue
3. While the queue is not empty:
   - Remove the first vertex from the queue
   - Visit all adjacent unvisited vertices of the removed vertex
   - Mark these adjacent vertices as visited and add them to the queue

BFS uses a **queue** data structure, which follows the First-In-First-Out (FIFO) principle, ensuring that vertices are visited in order of their distance from the source.

## BFS Algorithm

The key distinguishing feature of BFS is that it visits all vertices at distance k from the source before visiting any vertex at distance k+1.

![BFS Visual Example](https://via.placeholder.com/500x300?text=BFS+Visualization)

Given a graph and a source vertex:
1. Initialize a queue and enqueue the source vertex
2. Initialize a visited array/set to keep track of visited vertices
3. Mark the source as visited
4. While the queue is not empty:
   - Dequeue a vertex
   - Process the vertex (print it, store it, etc.)
   - Enqueue all unvisited neighbors and mark them as visited

## Pseudocode

```
BFS(Graph G, Vertex source):
    // Initialize data structures
    Queue q = new Queue()
    Set visited = new Set()
    
    // Start from the source vertex
    q.enqueue(source)
    visited.add(source)
    
    // Process vertices level by level
    while q is not empty:
        vertex = q.dequeue()
        
        // Process current vertex
        process(vertex)
        
        // Visit all adjacent vertices
        for each neighbor of vertex:
            if neighbor is not in visited:
                q.enqueue(neighbor)
                visited.add(neighbor)
```

## Implementation Examples

### C++ Implementation

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// BFS traversal from a given source vertex
void BFS(vector<vector<int>>& graph, int source) {
    int n = graph.size(); // Number of vertices
    vector<bool> visited(n, false); // Mark all vertices as not visited
    queue<int> q; // Create a queue for BFS
    
    // Mark the source node as visited and enqueue it
    visited[source] = true;
    q.push(source);
    
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int current = q.front();
        q.pop();
        cout << current << " ";
        
        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent has not been visited, mark it as visited and enqueue it
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
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
    
    cout << "BFS traversal starting from vertex 0: ";
    BFS(graph, 0);
    
    return 0;
}
```

### Java Implementation

```java
import java.util.*;

public class BFSExample {
    private int V; // Number of vertices
    private LinkedList<Integer>[] adj; // Adjacency list
    
    // Constructor
    BFSExample(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList<>();
    }
    
    // Add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].add(w);
    }
    
    // BFS traversal from a given source s
    void BFS(int s) {
        // Mark all vertices as not visited
        boolean[] visited = new boolean[V];
        
        // Create a queue for BFS
        LinkedList<Integer> queue = new LinkedList<>();
        
        // Mark the source node as visited and enqueue it
        visited[s] = true;
        queue.add(s);
        
        while (queue.size() != 0) {
            // Dequeue a vertex from queue and print it
            s = queue.poll();
            System.out.print(s + " ");
            
            // Get all adjacent vertices of the dequeued vertex s
            // If an adjacent has not been visited, mark it as visited and enqueue it
            for (Integer neighbor : adj[s]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
    }
    
    // Driver code
    public static void main(String[] args) {
        BFSExample g = new BFSExample(7);
        
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
        
        System.out.println("BFS traversal starting from vertex 0:");
        g.BFS(0);
    }
}
```

### Python Implementation

```python
from collections import defaultdict, deque

class Graph:
    def __init__(self):
        # Default dictionary to store the graph
        self.graph = defaultdict(list)
    
    # Function to add an edge to the graph
    def add_edge(self, u, v):
        self.graph[u].append(v)
    
    # BFS traversal from a given source
    def bfs(self, source):
        # Mark all vertices as not visited
        visited = set()
        
        # Create a queue for BFS
        queue = deque()
        
        # Mark the source node as visited and enqueue it
        queue.append(source)
        visited.add(source)
        
        while queue:
            # Dequeue a vertex from queue and print it
            vertex = queue.popleft()
            print(vertex, end=" ")
            
            # Get all adjacent vertices of the dequeued vertex
            # If an adjacent has not been visited, mark it as visited and enqueue it
            for neighbor in self.graph[vertex]:
                if neighbor not in visited:
                    queue.append(neighbor)
                    visited.add(neighbor)

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
    
    print("BFS traversal starting from vertex 0:")
    g.bfs(0)
```

## Applications of BFS

1. **Shortest Path Finding**: In unweighted graphs, BFS can find the shortest path between two vertices.

2. **Network Broadcasting**: BFS models how information spreads in networks.

3. **Web Crawlers**: Search engines use BFS to index web pages.

4. **Social Networking**: Friend suggestions based on degrees of separation.

5. **Garbage Collection**: The "mark" phase in mark-sweep garbage collection.

6. **Finding Connected Components**: Identify all connected vertices in an undirected graph.

7. **Testing Bipartiteness**: Determine if a graph can be colored using only two colors.

8. **Finding All Nodes Within Distance K**: In networks, finding all nodes within a certain distance.

## Advantages and Disadvantages

### Advantages
- ✅ Guarantees the shortest path in unweighted graphs
- ✅ Good for searching nodes that are close to the source
- ✅ Uses less memory than DFS on very deep graphs
- ✅ Can find all nodes at a given distance from the source

### Disadvantages
- ❌ Requires more memory on very wide graphs
- ❌ Not suitable for decision tree problems (game trees)
- ❌ Less efficient than DFS for finding paths to distant nodes
- ❌ Does not automatically detect cycles (though it can be modified to do so)

## BFS vs DFS

| Characteristic | BFS | DFS |
|----------------|-----|-----|
| Data Structure | Queue (FIFO) | Stack (LIFO) |
| Memory Usage | Higher for wide graphs | Higher for deep graphs |
| Path Finding | Finds shortest path in unweighted graphs | May not find shortest path |
| Implementation | Typically iterative | Can be recursive or iterative |
| When to use | When target is likely close to source | When searching all possibilities |
| Completeness | Complete (finds a solution if one exists) | Complete only if graph is finite |
| Branching Factor | Better for small branching factor | Better for large branching factor |

## Practice Problems

1. [Leetcode #200 - Number of Islands](https://leetcode.com/problems/number-of-islands/)
2. [Leetcode #994 - Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)
3. [Leetcode #286 - Walls and Gates](https://leetcode.com/problems/walls-and-gates/)
4. [Leetcode #127 - Word Ladder](https://leetcode.com/problems/word-ladder/)
5. [Leetcode #863 - All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)

These problems provide excellent practice for applying BFS in different contexts and will help solidify your understanding of the algorithm.