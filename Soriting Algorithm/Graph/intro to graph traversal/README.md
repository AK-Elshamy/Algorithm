# Introduction to Graph Traversal

## Table of Contents
- [What is a Graph?](#what-is-a-graph)
- [Graph Representation](#graph-representation)
- [Why Graph Traversal Matters](#why-graph-traversal-matters)
- [Common Graph Traversal Algorithms](#common-graph-traversal-algorithms)
- [Graph Traversal Applications](#graph-traversal-applications)
- [Time and Space Complexity](#time-and-space-complexity)
- [Choosing the Right Algorithm](#choosing-the-right-algorithm)

## What is a Graph?

A graph is a non-linear data structure consisting of:
- **Vertices** (also called nodes): Points or objects in the graph
- **Edges**: Connections between vertices

Graphs can represent a wide variety of relationships and structures. They come in several types:

1. **Directed Graph (Digraph)**: Edges have direction (one-way connections)
2. **Undirected Graph**: Edges have no direction (two-way connections)
3. **Weighted Graph**: Edges have associated values or "weights"
4. **Cyclic Graph**: Contains at least one path that starts and ends at the same vertex
5. **Acyclic Graph**: Contains no cycles

## Graph Representation

Graphs can be represented in code using multiple approaches:

### Adjacency Matrix
```
    A B C D
  +-------+
A | 0 1 1 0 |
B | 1 0 0 1 |
C | 1 0 0 1 |
D | 0 1 1 0 |
  +-------+
```

A 2D array where matrix[i][j] = 1 if there's an edge from vertex i to vertex j, and 0 otherwise.

**Advantages**:
- Simple for dense graphs
- Constant time (O(1)) to check if there's an edge between two vertices

**Disadvantages**:
- Requires O(V²) space (V = number of vertices)
- Inefficient for sparse graphs

### Adjacency List
```
A → B → C
B → A → D
C → A → D
D → B → C
```

A collection of lists or arrays where each vertex maintains a list of its adjacent vertices.

**Advantages**:
- Space-efficient for sparse graphs (O(V + E))
- Faster iteration over adjacent vertices

**Disadvantages**:
- Checking if there's an edge between two vertices takes O(V) time in the worst case

## Why Graph Traversal Matters

Graph traversal is the process of visiting (checking and/or updating) each vertex in a graph exactly once. It's fundamental for:

1. **Pathfinding**: Finding routes between vertices
2. **Connectivity analysis**: Determining if all vertices are connected
3. **Cycle detection**: Finding loops in the graph
4. **Network analysis**: Analyzing relationships in social networks, computer networks, etc.
5. **Web crawling**: Indexing web pages and their connections

## Common Graph Traversal Algorithms

The two primary graph traversal algorithms are:

1. **Breadth-First Search (BFS)**
   - Explores all neighbors at the current depth before moving to vertices at the next depth
   - Uses a queue data structure (FIFO)
   - Finds shortest paths in unweighted graphs

2. **Depth-First Search (DFS)**
   - Explores as far as possible along each branch before backtracking
   - Uses a stack data structure (LIFO) or recursion
   - Efficient for searching deep hierarchies

Both algorithms ensure that each vertex is visited exactly once.

## Graph Traversal Applications

Graph traversal algorithms are used in numerous applications:

- **Social Networks**: Friend recommendations, connection analysis
- **Maps and Navigation**: Finding directions between locations
- **Web Crawlers**: Indexing web pages for search engines
- **Network Routing**: Determining paths for data in networks
- **Dependency Resolution**: Package managers for software
- **Game AI**: Pathfinding for characters, game state analysis
- **Image Processing**: Connected component labeling
- **Puzzle Solving**: Finding solutions to puzzles like mazes

## Time and Space Complexity

For both BFS and DFS:
- **Time Complexity**: O(V + E) where V is the number of vertices and E is the number of edges
  - Each vertex is processed once: O(V)
  - Each edge is traversed once: O(E)
- **Space Complexity**: 
  - O(V) for the queue/stack that stores vertices
  - O(V) for the visited array/set that tracks which vertices have been processed

## Choosing the Right Algorithm

Choose **BFS** when:
- Finding the shortest path in an unweighted graph
- The solution is likely to be close to the source
- The graph is not too wide
- You need to find all nodes at a given distance from the source

Choose **DFS** when:
- Exploring all possible paths
- The graph is very wide
- The solution is likely to be far from the source
- Memory is limited (DFS can use less memory than BFS in some cases)
- Detecting cycles or topological sorting is needed

In practice, the choice between BFS and DFS often depends on the specific problem and graph structure.