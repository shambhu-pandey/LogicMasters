![alt text](image-1.png)
![alt text](image-2.png)

Absolutely, Shambhu! Here's your enhanced and visually appealing **Markdown (.md)** version — perfect for viva prep, GitHub README, or academic documentation. I've added emojis, section dividers, and formatting to make it pop 🌟

---

```markdown
# 🌐 Graph Representation in C++ (Beginner-Friendly)

This guide walks you through representing an **undirected graph** using both **Adjacency Matrix** and **Adjacency List** in C++. It includes user input, sample output, and clear comments to help beginners understand graph theory fundamentals.

---
```
## 📊 Adjacency Matrix (Undirected Graph) use when dense graph 


```cpp
#include <iostream>
using namespace std;

int main() {
    int V, E; // V = number of vertices, E = number of edges

    // Take input for number of vertices
    cout << "Enter number of vertices: ";
    cin >> V;

    // Create a 2D matrix initialized to 0
    // graph[i][j] = 1 means there's an edge between vertex i and j
    int graph[100][100] = {0}; // Supports up to 100 vertices

    // Take input for number of edges
    cout << "Enter number of edges: ";
    cin >> E;

    // Input each edge as a pair (u, v)
    cout << "Enter " << E << " edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // Set both graph[u][v] and graph[v][u] to 1
        // because the graph is undirected
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Print the adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    return 0;
}
```

---

## 📋 Adjacency List (Undirected Graph) use when sparse graph 

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V, E; // V = number of vertices, E = number of edges

    // Take input for number of vertices
    cout << "Enter number of vertices: ";
    cin >> V;

    // Create an array of vectors to store adjacency list
    // graph[i] will contain all neighbors of vertex i
    vector<int> graph[100]; // Supports up to 100 vertices

    // Take input for number of edges
    cout << "Enter number of edges: ";
    cin >> E;

    // Input each edge as a pair (u, v)
    cout << "Enter " << E << " edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // Add v to u's list and u to v's list
        // because the graph is undirected
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Print the adjacency list
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int j : graph[i])
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
```

---

## 🧪 Sample Input

```
Enter number of vertices: 5
Enter number of edges: 4
Enter 4 edges (u v):
0 1
0 4
1 2
3 4
```

---

## 📊 Sample Output: Adjacency Matrix

```
Adjacency Matrix:
0 1 0 0 1
1 0 1 0 0
0 1 0 0 0
0 0 0 0 1
1 0 0 1 0
```

---

## 📋 Sample Output: Adjacency List

```
Adjacency List:
0: 1 4
1: 0 2
2: 1
3: 4
4: 0 3
```

---

## 💡 Viva Tips

- ✅ Explain that `graph[i][j] = 1` means there's an edge between `i` and `j`.
- ✅ Mention that adjacency list is more space-efficient for sparse graphs.
- ✅ Clarify that undirected graphs require adding edges in both directions.

---



- ✅ BFS algorithm in simple words
- ✅ Solved example with graph structure
- ✅ C++ code that stores the traversal in a `result` vector
- ✅ Sample input and output

---
BFS:
![alt text](image-13.png)



## we can take any node as root node in traversal 
```markdown
# 🔍 Breadth-First Search (BFS) Traversal in C++

Breadth-First Search (BFS) is a graph traversal technique that explores nodes level by level using a **queue**. It is ideal for finding the shortest path in unweighted graphs and is easy to implement.

---
```

## 📘 BFS Algorithm (Step-by-Step in Simple Words)

1. **Create a queue** to keep track of nodes to visit.
2. **Create a visited array** to mark which nodes have been visited.
3. **Start from the source node**:
   - Mark it as visited.
   - Add it to the queue.
4. While the queue is not empty:
   - Remove the front node from the queue.
   - Add it to the result list.
   - For each neighbor of the current node:
     - If it hasn't been visited:
       - Mark it visited.
       - Add it to the queue.
5. Repeat until the queue is empty.

---
Here’s your BFS algorithm written cleanly and formatted for a `.md` file — perfect for viva prep, documentation, or README use.

---

```markdown
# 🔄 BFS Algorithm (Starting from Node 2)

Breadth-First Search (BFS) is a graph traversal technique that explores nodes level by level using a queue. Below is the step-by-step algorithm when the traversal starts from **node 2**.

---

## 📘 Step-by-Step BFS Algorithm

1. **Create a queue** to keep track of nodes to visit.

2. **Create a visited array** of size `N` (number of nodes), initialized to `false`.

3. **Start from node 2**:
   - Mark node 2 as visited.
   - Add node 2 to the queue.

4. **While the queue is not empty**:
   - Remove the front node from the queue (let’s call it `current`).
   - Add `current` to the result list.
   - For each neighbor of `current`:
     - If the neighbor is not visited:
       - Mark it visited.
       - Add it to the queue.

5. **Repeat until the queue is empty.**

6. The **result list** now contains the BFS traversal starting from **node 2**.

---

## 🧠 Notes

- BFS ensures that all nodes reachable from node 2 are visited in level order.
- The result list will reflect the exact order in which nodes are explored.
- This algorithm works for both **directed** and **undirected** graphs.

```

---



## 💡 Notes

- BFS is ideal for finding the shortest path in unweighted graphs.
- It explores all neighbors of a node before moving deeper.
- Works for both connected and disconnected graphs (if run multiple times).


---

Let me know if you'd like this styled for GitHub README or want a DFS version next!
## 🧠 Example Graph

Let’s solve this directed graph:

```
0 → 1, 4  
1 → 3  
3 → 2, 5  
2 → 6  
5 → 6  
6 → 4
```

---

## 💻 C++ Code (Stores Result in Vector)

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS function that returns traversal result
vector<int> bfs(int start, vector<vector<int>>& adj, int N) {
    vector<bool> visited(N, false); // Track visited nodes
    queue<int> q;                   // Queue for BFS
    vector<int> result;             // Store traversal order

    visited[start] = true;
    q.push(start);

    cout << "\n🔄 Step-by-step BFS Traversal:\n";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        // Print current queue and result
        cout << "Visited Node: " << node << "\n";
        cout << "Queue: ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\nResult: ";
        for (int val : result)
            cout << val << " ";
        cout << "\n---\n";

        // Visit all neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    int N, M;
    cout << "Enter number of nodes: ";
    cin >> N;

    cout << "Enter number of edges: ";
    cin >> M;

    vector<vector<int>> adj(N);

    cout << "Enter " << M << " edges (u v):\n";
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Directed edge
    }

    int start;
    cout << "Enter starting node for BFS: ";
    cin >> start;

    vector<int> traversal = bfs(start, adj, N);

    cout << "\n✅ Final BFS Traversal: ";
    for (int val : traversal)
        cout << val << " ";
    cout << endl;

    return 0;
}

```

---

## 🧪 Sample Input

```
Start Node: 0
Edges:
0 → 1, 4  
1 → 3  
3 → 2, 5  
2 → 6  
5 → 6  
6 → 4
```

---

## 📤 Output

```
BFS Traversal: 0 1 4 3 2 5 6
```

---

## 💡 Viva Tips

- BFS uses a **queue** to explore nodes level by level.
- It’s great for **shortest path** problems in unweighted graphs.
- Always mark nodes as visited **before** adding them to the queue.
- BFS works for both **directed** and **undirected** graphs.

---

![alt text](image-3.png)
## now 6 will be popped out because 6 se ab khi nhi ja sakta sab visited hai so ab stack se popped 
![alt text](image-4.png)
## 4 ka bhi koi unvisited nhi hai , backtracking kar rhe hai so popped out from stack same for other rhta toh 
![alt text](image-5.png)
## ab 2 ka baari aya ki popped hoga ki nhi stack se toh ye nhi hoga because 2 ka unvisted hai 5 so ab 5 pushed in stack and result me likh do
![alt text](image-6.png)
## ab 5 ko backtrack karenge popped hoga ki nhi agar unvisted hoga toh nhi hoga popped but nhi hai toh popped and then again 2 par aa gya aur 2 ka bhi ab koi nhi bacha hai unvisted toh ab 2 bhi popped same other from stack 
![alt text](image-7.png)
![alt text](image-8.png)
## now stack empty so now stop dfs traversal
![alt text](image-9.png) 


Absolutely, Shambhu! Here's your updated `.md` file with **clear comments added to both DFS implementations** — stack-based and recursive — so you can understand each step easily during viva or debugging.

---


![alt text](image-3.png)
# 🧭 Depth-First Search (DFS) — Full Guide with Stack and Recursion (With Comments)

Depth-First Search (DFS) is a graph traversal technique that explores one path as deeply as possible before backtracking. It works for both directed and undirected graphs and is useful for:

- 🔁 Cycle detection  
- 📊 Topological sorting  
- 🔗 Connected components  
- 🧩 Maze solving and pathfinding  

DFS can be implemented using either a **stack** or **recursion**.

---

## 📘 DFS Algorithm (Stack-Based with Backtracking)

1. **Create a stack** to keep track of nodes to visit.  
2. **Create a visited array** of size `N`, initialized to `false`.  
3. **Start from the root node**:
   - Mark it as visited.
   - Push it onto the stack.
   - Add it to the result list.
4. While the stack is not empty:
   - Look at the top node (`current`).
   - Check if it has any **unvisited neighbors**:
     - If yes:
       - Choose one unvisited neighbor.
       - Mark it visited.
       - Push it onto the stack.
       - Add it to the result list.
     - If no:
       - Pop `current` from the stack (backtracking).
5. Repeat until the stack is empty.  
6. The result list now contains the DFS traversal order.

---

## 💻 C++ Code — Stack-Based DFS (With Comments)

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter edges:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

```

---

## 📘 DFS Algorithm (Recursive Version)

1. **Create a visited array** of size `N`, initialized to `false`.  
2. **Define a recursive function** `dfs(node)`:
   - Mark `node` as visited.
   - Add `node` to the result list.
   - For each neighbor of `node`:
     - If not visited:
       - Call `dfs(neighbor)`
3. Call `dfs(start_node)` to begin traversal.  
4. The result list now contains the DFS traversal order.

---

## 💻 C++ Code — Recursive DFS (With Comments)

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter edges:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<bool> visited(n, false);
    stack<int> st;
    st.push(start);

    cout << "DFS Traversal: ";
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            // Push all neighbors (in reverse order for correct sequence)
            for (int i = adj[node].size() - 1; i >= 0; i--) {
                int next = adj[node][i];
                if (!visited[next])
                    st.push(next);
            }
        }
    }
}


---

## 🧪 Sample Input

```
![alt text](image-55.png)
```

---

## 📤 Sample Output

```
DFS Traversal (Stack):     0 1 3 2 6 5 4  
DFS Traversal (Recursive): 0 1 3 2 6 5 4
```

---

## 💡 Viva Tips

- DFS uses a **stack or recursion** to explore deep paths first.
- Backtracking happens when a node has no unvisited neighbors.
- DFS is not guaranteed to give shortest path — unlike BFS.
- Useful for:
  - Detecting cycles
  - Topological sorting
  - Exploring connected components

---
---

![alt text](image-10.png)


![alt text](image-11.png)

![alt text](image-12.png)

union of all these nodes means all types edges ans then we get edges of given in graph for checking


Absolutely, Shambhu! Here's a **viva-ready `.md` file** that explains all four types of edges in DFS traversal using the definitions you provided. It includes:

- ✅ Clear definitions  
- ✅ Timestamp-based conditions  
- ✅ Examples with reasoning  
- ✅ Viva tips  

---

```markdown
# 🔍 Types of Edges in DFS Traversal — Explained with Timestamps

In Depth-First Search (DFS), edges encountered during traversal can be classified into four types based on discovery and finish times. These classifications help in understanding graph structure, detecting cycles, and performing topological sorting.

---

## 📘 Edge Type Definitions

### 🌳 Tree Edge
- **Definition**: Member of DFS traversal.
- **Condition**: Edge `(x, y)` is used to discover `y` directly from `x`.
- **Example**: If `x.d < y.d < y.f < x.f`, and `y` was visited directly from `x`.

---

### ⏩ Forward Edge
- **Definition**: Any edge `(x, y)` where `y` appears after `x` and there is a path from `x` to `y`.
- **Condition**: `x.d < y.d < y.f < x.f`, but `y` was **not** discovered directly by `x`.
- **Example**: `(d, e)` where `d.d = 6`, `d.f = 7`; `e.d = 8`, `e.f = 11`

---

### 🔁 Back Edge
- **Definition**: Any edge `(x, y)` where `y` appears before `x` and there is a path from `y` to `x`.
- **Condition**: `y.d < x.d < x.f < y.f`
- **Example**: `(h, f)` where `h.d = 12`, `h.f = 13`; `f.d = 10`, `f.f = 11`

---

### 🔀 Cross Edge
- **Definition**: Any edge `(x, y)` where there is **no path** from `y` to `x`.
- **Condition**: `y.f < x.d` or `x.f < y.d`
- **Example**: `(g, m)` where `g.d = 14`, `g.f = 15`; `m.d = 30`, `m.f = 31`

---

## 🧠 How to Use Discovery and Finish Times

| Edge Type     | Timestamp Condition                          |
|---------------|-----------------------------------------------|
| Tree Edge     | `x.d < y.d < y.f < x.f` (direct discovery)    |
| Forward Edge  | `x.d < y.d < y.f < x.f` (not direct)          |
| Back Edge     | `y.d < x.d < x.f < y.f`                       |
| Cross Edge    | `y.f < x.d` or `x.f < y.d`                    |

---

## 📤 Example Classification Table

| Edge     | Type         | Reasoning                                      |
|----------|--------------|------------------------------------------------|
| a → b    | Tree         | Direct DFS discovery                           |
| b → c    | Tree         | Direct DFS discovery                           |
| c → d    | Tree         | Direct DFS discovery                           |
| d → e    | Forward      | e is descendant but not discovered by d        |
| h → f    | Back         | f is ancestor of h                             |
| g → m    | Cross        | No path from m to g, timestamps show separation|

---

## 💡 Viva Tips

- Always track **discovery (d)** and **finish (f)** times during DFS.
- Tree edges form the DFS tree.
- Back edges indicate **cycles**.
- Forward edges go deeper but weren’t used in DFS tree.
- Cross edges jump between **finished** or **unrelated** nodes.

---

Let me know if you'd like this paired with a graph diagram or a code simulation that prints edge types live!
```




**Here’s a complete explanation of the DFS traversal for your graph, including how discovery (start) and finish (stop) times are assigned to each node, and how they help classify edge types.**

---

## 🔍 What Are Start and Finish Times in DFS?

During DFS traversal:
- **Start time (discovery time)** is recorded when a node is first visited.
- **Finish time** is recorded when all its neighbors have been explored and we backtrack.

These timestamps help us:
- Understand the exact order of traversal.
- Classify edges as **Tree**, **Forward**, **Back**, or **Cross**.
- Detect cycles and structure of the DFS tree.

---

## 🧭 DFS Traversal Example (Based on Your Graph)

Let’s assume DFS starts at node `a`. Here's how the traversal and timestamps unfold:

| Node | Start (Discovery) | Finish (Backtrack) | Reasoning |
|------|-------------------|--------------------|-----------|
| a    | 1                 | 24                 | DFS starts here |
| b    | 2                 | 3                  | Discovered from a |
| d    | 4                 | 5                  | Discovered from b |
| h    | 6                 | 7                  | Discovered from d |
| i    | 8                 | 9                  | Discovered from h |
| c    | 10                | 11                 | DFS continues from a |
| e    | 12                | 13                 | Discovered from c |
| g    | 14                | 15                 | Discovered from e |
| j    | 16                | 17                 | Discovered from g |
| k    | 18                | 19                 | Discovered from j |
| l    | 20                | 21                 | Discovered from k |
| m    | 22                | 23                 | Discovered from l |

> **Note**: These values are illustrative based on the image and standard DFS behavior. Actual values may vary slightly depending on implementation and adjacency order.

---

## 🔁 How These Times Help Classify Edges

### ✅ Tree Edge
- Used to discover a new node.
- **Condition**: `x.start < y.start < y.finish < x.finish`
- Example: `a → b`, `b → d`, `d → h`, `h → i`, etc.

### ⏩ Forward Edge
- Points to a descendant not directly discovered.
- **Condition**: Same as tree edge, but not part of DFS tree.
- Example: `g → k`

### 🔁 Back Edge
- Points to an ancestor.
- **Condition**: `y.start < x.start < x.finish < y.finish`
- Example: `i → d`, `h → f`, `f → b`

### 🔀 Cross Edge
- Connects unrelated or finished nodes.
- **Condition**: `y.finish < x.start` or `x.finish < y.start`
- Example: `m → i`, `c → f`

---

## 🧠 Why This Matters

- **Start/Finish times** give a full picture of traversal depth and order.
- They help in **cycle detection** (back edges).
- They’re essential for **topological sorting** and **edge classification**.
- They allow us to build the **DFS tree** and understand graph structure.

---




 # Minimum Spanning Tree - Theory
 ###  A graph can have more than one minimum spanning tree if weight is not distinct , if weight is distinct then minimum spanning tree will be unique 

 Absolutely, Shambhu! Here's a clean and focused explanation of **Minimum Spanning Tree (MST)** in C++, without any code — perfect for viva prep or concept revision.

---

## 🌳 What Is a Minimum Spanning Tree?

A **Minimum Spanning Tree (MST)** is a subset of edges in a **connected, undirected, weighted graph** that:

- Connects **all vertices**
- Has **no cycles**
- Has the **minimum possible total edge weight**

---

## 📘 Key Properties

- MST contains exactly **V − 1 edges** for a graph with `V` vertices.
- MST is **not unique** if multiple edges have the same weight.
- MST is used in:
  - Network design (e.g., laying cables with minimum cost)
  - Clustering algorithms
  - Approximation algorithms

---

## ⚙️ MST Algorithms in C++

### 🔗 Kruskal’s Algorithm
- **Approach**: Greedy, edge-based
- **Steps**:
  1. Sort all edges by weight.
  2. Add edges one by one to MST, skipping those that form a cycle.
  3. Use **Disjoint Set Union (DSU)** to detect cycles.
- **Best for**: Sparse graphs or when edges are stored in a list.

---

### 🌐 Prim’s Algorithm
- **Approach**: Greedy, vertex-based
- **Steps**:
  1. Start from any node.
  2. Use a **priority queue** to pick the minimum weight edge connecting to an unvisited node.
  3. Expand the MST one vertex at a time.
- **Best for**: Dense graphs or when using adjacency lists.

---

## 🔍 Comparison Table

| Feature         | Kruskal’s Algorithm         | Prim’s Algorithm             |
|----------------|-----------------------------|------------------------------|
| Strategy        | Edge-based                  | Vertex-based                 |
| Cycle Detection| Disjoint Set (Union-Find)   | Implicit via visited array   |
| Data Structure  | Edge list + DSU             | Adjacency list + Min-Heap    |
| Graph Type      | Sparse                      | Dense                        |

---

## 💡 Viva Tips

- MST is a **spanning tree with minimum cost**.
- Kruskal’s builds MST by choosing edges; Prim’s grows MST from a node.
- If all edge weights are distinct, MST is **unique**.
- MST is **not applicable** to disconnected graphs.

---

Let me know if you want this turned into a `.md` file or paired with a diagram showing MST construction!

![alt text](image-14.png)
![alt text](image-15.png)
![alt text](image-16.png)
![alt text](image-17.png)
![alt text](image-18.png)
![alt text](image-19.png)
![alt text](image-20.png)
![alt text](image-21.png)
![alt text](image-22.png)
![alt text](image-23.png)
![alt text](image-24.png)
![alt text](image-25.png)
![alt text](image-27.png)
![alt text](image-28.png)
 ![alt text](image-29.png)


# 🌳 Kruskal’s Algorithm — Minimum Spanning Tree (MST)

Kruskal’s Algorithm is used to find the **Minimum Spanning Tree (MST)** of a **connected, weighted, undirected graph**.

👉 It finds a set of edges that connects all vertices with the **minimum total weight** and **no cycles**.

---

## 💡 Basic Idea (in Simple Words)

- Pick the **smallest edge** (edge with minimum weight).
- Add it to the MST **if it doesn’t form a cycle**.
- Repeat until you have **V − 1 edges** (where `V` = number of vertices).

---

## ⚙️ Step-by-Step Algorithm

Let’s write the steps clearly 👇

### Algorithm: Kruskal’s MST

1️⃣ **Sort all edges** in increasing order of their weights.

2️⃣ **Pick the smallest edge** from the sorted list.

3️⃣ **Check if adding it forms a cycle**:
   - ✅ If **No**, add it to the MST.
   - ❌ If **Yes**, skip it.

4️⃣ **Repeat steps 2–3** until MST has exactly **(V − 1)** edges.

5️⃣ **Output** all the edges in the MST and the **total cost**.

---

## 🧠 Key Concepts

- Uses a **greedy approach**.
- Cycle detection is done using **Disjoint Set Union (DSU)**.
- Time complexity:  
  - Sorting edges → `O(E log E)`  
  - DSU operations → `O(E α(V))` (α = inverse Ackermann function)

---

## 💡 Viva Tips

- Kruskal’s is **edge-based**, unlike Prim’s which is **vertex-based**.
- MST always has **V − 1 edges**.
- If all edge weights are distinct, MST is **unique**.
- Commonly used in **network design**, **clustering**, and **graph optimization**.


 ![alt text](image-30.png)
sol: - remove all loops and parallel edges , remove that parallel edges that have maximum weight
 ![alt text](image-31.png)
  arrange in ascending order according to weight
  ![alt text](image-32.png) 
  choose mimimum edge weight from start and no cycle should be formed , agar kisi ko add karne se cycle bn ja rha hai toh nhi karenge add
![alt text](image-33.png)
property : n-1= edges  in kruskal

![alt text](image-34.png)
![alt text](image-35.png)
![alt text](image-36.png)
![alt text](image-37.png)
![alt text](image-45.png)




---
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

void unite(int a, int b, vector<int>& parent) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) parent[b] = a;
}

int main() {
    int n, m;
    cout << "Enter nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges(m);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v}; // sort by weight
    }

    sort(edges.begin(), edges.end());
    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    int cost = 0;
    cout << "\nEdges in MST:\n";
    for (auto e : edges) {
        int w = e[0], u = e[1], v = e[2];
        if (find(u, parent) != find(v, parent)) {
            unite(u, v, parent);
            cost += w;
            cout << u << " - " << v << " (" << w << ")\n";
        }
    }
    cout << "Total Cost: " << cost << endl;
}
```
![alt text](image-57.png)

![alt text](image-56.png)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

void unite(int a, int b, vector<int>& parent) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) parent[b] = a;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges(m); // edges as {weight, u_index, v_index}
    map<char, int> charToIndex;   // map chars to integers
    map<int, char> indexToChar;   // map integers back to chars
    int idx = 0;

    cout << "Enter edges (u v w) with nodes as characters:\n";
    for (int i = 0; i < m; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;

        if (charToIndex.find(u) == charToIndex.end()) {
            charToIndex[u] = idx;
            indexToChar[idx] = u;
            idx++;
        }
        if (charToIndex.find(v) == charToIndex.end()) {
            charToIndex[v] = idx;
            indexToChar[idx] = v;
            idx++;
        }

        edges[i] = {w, charToIndex[u], charToIndex[v]}; // store indices
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    int cost = 0;
    cout << "\nEdges in MST:\n";
    for (auto e : edges) {
        int w = e[0], u = e[1], v = e[2];
        if (find(u, parent) != find(v, parent)) {
            unite(u, v, parent);
            cost += w;
            cout << indexToChar[u] << " - " << indexToChar[v] << " (" << w << ")\n";
        }
    }

    cout << "Total Cost: " << cost << endl;
}
```
![alt text](image-58.png)

## 🌳 **What is Prim’s Algorithm?**

**Prim’s Algorithm** is a **Greedy Algorithm** used to find the **Minimum Spanning Tree (MST)** of a **connected, weighted, undirected graph**.

It helps to connect all vertices together with the **minimum total edge weight** and **no cycles**.

---

## 💡 **Basic Idea (Simple Words)**

1️⃣ Start from **any one vertex**.
2️⃣ Choose the **smallest edge** that connects this vertex to another **unvisited vertex**.
3️⃣ Add that edge to the MST.
4️⃣ Move to the newly added vertex.
5️⃣ Again, pick the smallest edge connecting any visited vertex to an unvisited vertex.
6️⃣ Repeat until all vertices are connected.

---

## ⚙️ **Algorithm Steps (Easy Form)**

1. Choose any vertex to start with.
2. Mark it as **visited**.
3. Find all edges connecting **visited** → **unvisited** vertices.
4. Pick the **smallest** of these edges.
5. Add that edge to the MST.
6. Mark the connected vertex as **visited**.
7. Repeat steps 3–6 until all vertices are included.

---

## 📘 **Example**

Let’s take this graph 👇

```
     10
(0)------(1)
 |  \     |
 6|   \5  |15
 |    \   |
(2)-----(3)
     4
```

**Edges:**

```
(0,1,10)
(0,2,6)
(0,3,5)
(1,3,15)
(2,3,4)
```

---

### 🧠 **Step-by-Step Working**

| Step | Visited Vertices     | Chosen Edge  | Weight                      | Reason                                                 |
| ---- | -------------------- | ------------ | --------------------------- | ------------------------------------------------------ |
| 1    | {0}                  | —            | —                           | Start from vertex 0                                    |
| 2    | {0,3}                | (0,3)        | 5                           | Smallest edge from vertex 0                            |
| 3    | {0,3,2}              | (3,2)        | 4                           | Smallest edge connecting visited → unvisited           |
| 4    | {0,3,2,1}            | (0,1)        | 10                          | Smallest remaining edge connecting visited → unvisited |
| ✅    | All vertices visited | MST complete | **Total = 5 + 4 + 10 = 19** | ✅                                                      |

---

## 🧩 **Key Points**

| Concept                    | Meaning                                            |
| -------------------------- | -------------------------------------------------- |
| **Algorithm Type**         | Greedy Algorithm                                   |
| **Approach**               | Builds MST by adding one vertex at a time          |
| **Starts From**            | Any vertex                                         |
| **Cycle Formation**        | Not possible                                       |
| **Number of Edges in MST** | V - 1 (where V = number of vertices)               |
| **Time Complexity**        | O(V²) (simple) or O(E log V) (with priority queue) |
| **Graph Type**             | Connected, Weighted, Undirected                    |

---

## 🔍 **Kruskal vs Prim (Comparison)**

| Feature              | **Kruskal’s Algorithm**        | **Prim’s Algorithm**   |
| -------------------- | ------------------------------ | ---------------------- |
| **Approach**         | Edge-based                     | Vertex-based           |
| **Cycle Check**      | Uses Disjoint Set (Union-Find) | Not needed             |
| **Sorting of Edges** | Required                       | Not required           |
| **Start Point**      | Starts from smallest edge      | Starts from any vertex |
| **Best for**         | Sparse graphs                  | Dense graphs           |
| **Time Complexity**  | O(E log E)                     | O(E log V)             |

---

## 🎯 **Real-Life Example**

* **Network Design:** Connecting computers or cities with minimum total cable or road cost.
* **Electrical Grids:** Laying wires connecting power stations at minimum expense.
* **Transportation:** Connecting airports or cities with least travel distance.

In all cases, Prim’s algorithm helps to find the **cheapest way to connect all points** without forming loops.

---


![alt text](image-38.png)
sol : remove loop , and parallel edge which is maxmimum weight
![alt text](image-39.png)
  ### choose any arbitary node  : aur uske baad us se jo bhi connected hai other node us me se minimum weight wala edge find kre , phir next node ke pass jab chale jaai toh phir se minimum weight wala find kre but piche wala jo hai node usko na bhule agar us se chota mile minimum wala use use kre 
![alt text](image-40.png)
![alt text](image-43.png)
![alt text](image-44.png)

Perfect, Shambhu 👍
Let’s now learn **Dijkstra’s Algorithm** — one of the most important algorithms in **Data Structures and Algorithms (DSA)** for finding **shortest paths**.

I’ll explain it in a **simple, easy-to-understand way** 👇

---

## 🚗 **What is Dijkstra’s Algorithm?**

**Dijkstra’s Algorithm** is used to find the **shortest path** from a **source vertex** to **all other vertices** in a **weighted graph** (with **non-negative edge weights**).

---

## 💡 **Basic Idea (in Simple Words)**

1️⃣ Start from a **source vertex**.
2️⃣ Assign **distance = 0** for the source and **infinity (∞)** for all other vertices.
3️⃣ Visit the vertex with the **smallest distance**.
4️⃣ Update the distances to its **neighboring vertices** if a **shorter path** is found.
5️⃣ Mark the vertex as **visited** (meaning shortest path to it is finalized).
6️⃣ Repeat until all vertices are visited.

---

## ⚙️ **Algorithm Steps (Easy Form)**

Let’s break it into simple steps 👇

1. Set all vertex distances to ∞ (infinity) and source distance to 0.
2. Put all vertices in an unvisited set.
3. Pick the unvisited vertex with the **smallest known distance**.
4. For this vertex:

   * Look at all its **neighbors**.
   * Calculate new distance = (distance to current vertex) + (edge weight).
   * If new distance < current stored distance → **update it**.
5. Mark the vertex as **visited** (shortest path found).
6. Repeat steps 3–5 until all vertices are visited.

---

## 📘 **Example**

Consider the following graph 👇

```
      4
 (A)-----(B)
  | \      |
  |  \     |
 2|   \5   |1
  |    \   |
 (C)-----(D)
      8
```

### **Edges:**

```
A-B = 4  
A-C = 2  
B-D = 1  
C-D = 8  
A-D = 5
```

Let’s find **shortest path from A**.

---

### 🧠 **Step-by-Step Working**

| Step  | Visited Vertex | Updated Distances  | Explanation                            |
| ----- | -------------- | ------------------ | -------------------------------------- |
| Start | —              | A=0, B=∞, C=∞, D=∞ | Start from A                           |
| 1     | A              | A=0, B=4, C=2, D=5 | From A → update B=4, C=2, D=5          |
| 2     | C              | A=0, B=4, C=2, D=5 | C’s neighbor D (8+2=10 > 5), no update |
| 3     | B              | A=0, B=4, C=2, D=5 | B→D gives new distance (4+1=5) = same  |
| 4     | D              | Done               | All vertices visited                   |

✅ **Shortest distances from A:**

```
A → A = 0  
A → B = 4  
A → C = 2  
A → D = 5
```

---

## 🧩 **Key Points**

| Concept               | Meaning                                             |
| --------------------- | --------------------------------------------------- |
| **Type of Algorithm** | Greedy Algorithm                                    |
| **Purpose**           | Finds shortest path from a source vertex            |
| **Graph Type**        | Weighted graph (non-negative edges)                 |
| **Works For**         | Directed & Undirected graphs                        |
| **Does Not Work For** | Negative edge weights                               |
| **Time Complexity**   | O(V²) (simple), O(E log V) (with priority queue)    |
| **Output**            | Shortest distance from source to every other vertex |

---

## 🔍 **Comparison with Other Algorithms**

| Algorithm          | Purpose                         | Works with Negative Weights? | Type                |
| ------------------ | ------------------------------- | ---------------------------- | ------------------- |
| **Dijkstra’s**     | Shortest path from one source   | ❌ No                         | Greedy              |
| **Bellman-Ford**   | Shortest path from one source   | ✅ Yes                        | Dynamic Programming |
| **Floyd-Warshall** | Shortest path between all pairs | ✅ Yes                        | Dynamic Programming |
| **Prim’s**         | Minimum Spanning Tree           | ❌ No                         | Greedy              |
| **Kruskal’s**      | Minimum Spanning Tree           | ❌ No                         | Greedy              |

---

## 🎯 **Real-Life Examples**

* **Google Maps / GPS navigation:** To find the shortest route between two locations.
* **Network Routing:** Finding the fastest data path in computer networks.
* **Delivery Services:** Determining shortest delivery route for trucks or drones.

---

## 🧠 **Summary (In One Line)**

👉 **Dijkstra’s Algorithm** always chooses the next vertex with the **minimum current distance**,
and gradually finds the **shortest path** from the source to all other vertices —
**like exploring the map from near to far cities step by step.**

---

Would you like me to show a **dry run table** for Dijkstra’s algorithm on another example with **5 nodes** (step-by-step updates of distances)?

![alt text](image-41.png)
![alt text](image-42.png)
![alt text](image-46.png)
 ![alt text](image-47.png)
 ![alt text](image-49.png) 
 ![alt text](image-50.png)
![alt text](image-51.png)
  ![alt text](image-52.png)
  ![alt text](image-53.png)
  ![alt text](image-54.png)
  
  ```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n); // adjacency list: {neighbor, weight}

    cout << "Enter edges (u v w) with 0-based nodes:\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // for undirected graph
    }

    int src;
    cout << "Enter source node (0 to " << n-1 << "): ";
    cin >> src;

    vector<int> dist(n, INT_MAX); // distance from source
    vector<bool> visited(n, false);
    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        // find the unvisited node with minimum distance
        int u = -1;
        for (int j = 0; j < n; j++)
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        if (dist[u] == INT_MAX) break; // remaining nodes are unreachable
        visited[u] = true;

        // update distances of neighbors
        for (auto edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    cout << "\nShortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++)
        cout << "Node " << i << ": " << dist[i] << endl;
}
```
  ![alt text](image-59.png)
  ![alt text](image-60.png)

  ```cpp
  #include <iostream>
#include <vector>
#include <climits>
#include <map>
using namespace std;

int main() {
    int n, m, idx = 0;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    map<char,int> c2i; // char to index
    map<int,char> i2c; // index to char
    vector<vector<pair<int,int>>> adj(n); // adjacency list

    cout << "Enter edges (u v w) with nodes as characters:\n";
    for(int i = 0; i < m; i++){
        char u, v; int w;
        cin >> u >> v >> w;
        if(!c2i.count(u)) c2i[u] = idx, i2c[idx] = u, idx++;
        if(!c2i.count(v)) c2i[v] = idx, i2c[idx] = v, idx++;
        adj[c2i[u]].push_back({c2i[v], w});
        adj[c2i[v]].push_back({c2i[u], w}); // remove if directed
    }

    char srcChar;
    cout << "Enter source node: ";
    cin >> srcChar;
    int src = c2i[srcChar];

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[src] = 0;

    for(int i = 0; i < n; i++){
        int u = -1;
        for(int j = 0; j < n; j++)
            if(!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        if(dist[u] == INT_MAX) break;
        visited[u] = true;

        for(auto edge: adj[u]){
            int v = edge.first, w = edge.second;
            if(dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }

    cout << "\nShortest distances from node " << srcChar << ":\n";
    for(int i = 0; i < n; i++)
        cout << i2c[i] << ": " << dist[i] << endl;
}
```
![alt text](image-61.png)



![alt text](image-62.png)

# ⭐ **Cycle Detection in Undirected Graph using BFS and Flag Method (−1, 0, 1)**

*(8 Marks – Perfect Exam Format)*

To detect a cycle in an undirected graph, we can perform a **Breadth-First Search (BFS)** and maintain a **flag array** for each vertex.
Each vertex is assigned one of the following values:

### **Flag Values**

* **−1 → Not Visited**
* **0 → In Queue / Processing**
* **1 → Fully Visited**

---

## **Algorithm**

### **Step 1: Initialization**

1. For every vertex `v` in the graph:
   `flag[v] = −1`
2. Choose any vertex `s` as the starting point.
3. Set `flag[s] = 0` and insert `s` into the BFS queue.

---

### **Step 2: BFS Traversal**

While the queue is not empty:

1. Remove the front vertex `u` from the queue.
2. Set `flag[u] = 1` (fully visited).
3. For every adjacent vertex `v` of `u`:

   * **Case 1: `flag[v] = −1`**
     → `v` is unvisited.
     → Set `flag[v] = 0` and push `v` into the queue.
   * **Case 2: `flag[v] = 0`**
     → `v` is already in queue (still processing).
     → This means another edge is pointing to a processing vertex.
     → **A cycle is detected.**

---

### ⭐ **Cycle Detection Condition**

> **If any vertex finds its adjacent vertex with `flag = 0`,
> then the graph contains a cycle.**

This is the key rule of the flag method.

---

### **Step 3: Final Decision**

* If at any point an adjacent vertex with `flag = 0` is found → **Cycle Exists**
* If BFS finishes without this condition → **No Cycle**

---

## **Reason Behind the Method**

* A vertex with **flag = 0** is still being explored.
* If another vertex again reaches this same “processing” vertex, it indicates a **back-edge**, which forms a **cycle** in an undirected graph.

---

## **Conclusion**

The BFS flag method provides a simple and effective way to detect cycles in an undirected graph by using three states (−1, 0, 1).
If during BFS we encounter an adjacent vertex with flag value **0**, a cycle is present in the graph.

---


Here is the **perfect 8-marks exam answer** for
**Cycle Detection in an Undirected Graph using DFS and Flag Method (−1, 0, 1)**—clear, neat and exactly in exam-ready style.

---

# ⭐ **Cycle Detection in Undirected Graph Using DFS and Flag Method (−1, 0, 1)**

*(8 Marks – Proper Exam Format)*

To detect a cycle in an undirected graph using **Depth First Search (DFS)**, we maintain a **flag array** to track the state of every vertex.
Each vertex is assigned one of the three values:

### **Flag Values**

* **−1 → Not Visited**
* **0  → Currently in DFS (Processing)**
* **1  → Completely Visited**

---

# ✅ **Algorithm (DFS Method)**

### **Step 1: Initialization**

1. For every vertex `v` in the graph, set
   `flag[v] = −1`
2. Choose any vertex `s` to start DFS.

---

### **Step 2: DFS Traversal**

Call `DFS(s)` where:

### **DFS(u):**

1. Set
   `flag[u] = 0`   (u is being processed)
2. For every adjacent vertex `v` of `u`:

   * **Case 1: `flag[v] = −1`**
     → `v` is unvisited
     → Call `DFS(v)`
     → If DFS(v) returns TRUE → cycle exists
   * **Case 2: `flag[v] = 0`**
     → `v` is in processing state
     → DFS found a back-edge
     → **Cycle Exists**
   * **Case 3: `flag[v] = 1`**
     → `v` is already completely visited
     → Ignore
3. After all neighbors are explored, set
   `flag[u] = 1`

---

# ⭐ **Main Cycle Detection Condition**

> **If during DFS, any vertex finds an adjacent vertex with `flag = 0`,
> then the graph contains a cycle.**

This indicates the presence of a **back-edge**, which forms a cycle in an undirected graph.

---

### **Step 3: Final Decision**

* If DFS detects any adjacent vertex with `flag = 0` → **Cycle Exists**
* If DFS completes for all components with no such case → **No Cycle**

---

# 🧠 **Why This Works?**

* `flag = 0` means the vertex is currently active in the DFS path.
* If another neighbor points to this “active” vertex,
  it means that the graph has returned to a vertex in the same DFS path →
  **This forms a cycle.**

---

# 📌 **Conclusion**

Using DFS with the flag method (−1, 0, 1),
a cycle in an undirected graph is detected when a vertex explores an adjacent vertex that is currently in the processing state (flag = 0).
This method is accurate, simple, and commonly asked in exams.

---

# ⭐ Cycle Detection in Directed Graph Using DFS and Flag Method (−1, 0, 1)


![alt text](image-63.png)
## C se ab khi nhi ja sakte so ab backtrack , ab backtrack kaise karenge ki stack waale top element ko remove kar denge stack se 
![alt text](image-65.png)
![alt text](image-66.png)
![alt text](image-67.png)
##  E se toh hm ja sakte hai b par but already 0(zero) hai toh nhi le sakte means cycle formed 
![alt text](image-68.png)
## remove B->E edge and then check 
![alt text](image-69.png)
### and then check adjacent vertex of e , if nothing then backtrack and change it from 0 to 1 , and remove from stack
![alt text](image-70.png)
### do above step for others
![alt text](image-71.png)
### no cycle found for this 


---

In a **directed graph**, a cycle exists when we revisit a node that is already in the **current DFS path**.
This can be detected using **DFS** and a **flag array** that stores the state of each vertex.

---

# 🔷 **Flag Values**

Each vertex is assigned one of the following:

| Flag   | Meaning                                       |
| ------ | --------------------------------------------- |
| **−1** | Not Visited                                   |
| **0**  | Currently in DFS (Present in recursion stack) |
| **1**  | Fully Visited                                 |

---

# 🔶 **Algorithm (DFS Method)**

### **Step 1: Initialization**

1. For every vertex `v` in the graph:
   `flag[v] = −1`
2. For each vertex `v`:
   If `flag[v] = −1`, call `DFS(v)`

---

### **Step 2: DFS(u)**

1. Set
   `flag[u] = 0`
   (u is now in the DFS recursion stack)

2. For every adjacent vertex `v` of `u`:

   * **Case 1: `flag[v] = −1`**
     → `v` is unvisited
     → Call `DFS(v)`
     → If DFS(v) returns TRUE → cycle exists

   * **Case 2: `flag[v] = 0`**
     → `v` is already in DFS recursion stack
     → A **back edge** is found
     → **Cycle Exists**

   * **Case 3: `flag[v] = 1`**
     → `v` is already fully processed
     → Ignore

3. After exploring all neighbors of `u`, set
   `flag[u] = 1`
   (u is completely visited and removed from recursion stack)

---

# ⭐ **Main Condition for Cycle**

> **If during DFS, a vertex reaches an adjacent vertex whose flag is `0`, then the directed graph contains a cycle.**

This indicates a **back-edge**, which is the definition of a cycle in a directed graph.

---

# 🔷 **Step 3: Final Answer**

* If DFS reports any `flag = 0` case → **Cycle Exists**
* If DFS finishes all components with no such case → **No Cycle**

---

# 🧠 **Why This Works?**

In a directed graph:

* `flag = 0` means the vertex is currently on the **DFS call stack** (part of the active path).
* If a vertex points back to another vertex in the same active path → **cycle**.

This method is also known as **DFS with recursion-stack detection**.

---

# 📌 **Conclusion**

Cycle detection in a directed graph is done using DFS and flag states (−1, 0, 1).
A cycle is present if DFS encounters a vertex with **flag = 0**, meaning a back-edge has been discovered.
This is the simplest and most reliable technique used for detecting cycles in directed graphs.

---


# ⭐ **Topological Sorting – In-Degree Method (Kahn’s Algorithm)**

  ![alt text](image-72.png)
  ## cycle should not be formed DAG
  ## assign in degree to each node , and start from which has 0(zero) indegree and delete link bw  from that 0 node  , and then repeat step for other 
  ## two topological sorting we got
  ![alt text](image-73.png)

  ## question 2:
  ![alt text](image-74.png)
  ## sol: we can not find topological order for this because cycle formed 
  ## se why we can not find topological order  for cycle 
  ![alt text](image-75.png)

## questions 3 👍
 ![alt text](image-76.png)





*(Same method as shown in your image)*

This method works ONLY for **Directed Acyclic Graphs (DAGs)**.

---

# 🔷 **Step 1: Find In-Degree of Every Node**

**In-degree** = number of incoming edges.

Using the graph in your screenshot:

Edges (example):

```
1 → 2
1 → 4
2 → 3
4 → 3
4 → 5
```

Now compute in-degree:

| Node | In-degree |
| ---- | --------- |
| 1    | 0         |
| 2    | 1         |
| 3    | 2         |
| 4    | 1         |
| 5    | 1         |

Nodes with **in-degree 0** → can be picked first.

Here: **1**

---

# 🔷 **Step 2: Pick Node With In-degree 0**

Pick **1** first (it has 0 incoming edges).

Write it in the output →
**Output: 1**

Now **remove node 1** and all its outgoing edges.

Edges removed:

```
1 → 2
1 → 4
```

Update the in-degree table:

| Node | Old In-degree | New In-degree |
| ---- | ------------- | ------------- |
| 2    | 1             | 0             |
| 4    | 1             | 0             |

Now nodes with **0 in-degree** are:
→ **2** and **4**

---

# 🔷 **Step 3: Pick Any Node with In-degree 0**

Pick **2** next.

Output:
**1 2**

Remove outgoing edges of node 2:

```
2 → 3
```

Update in-degrees:

| Node | Old | New |
| ---- | --- | --- |
| 3    | 2   | 1   |

Remaining nodes with 0 in-degree:
→ **4**

---

# 🔷 **Step 4: Pick Next Zero In-degree Node**

Pick **4**

Output:
**1 2 4**

Remove edges of node 4:

```
4 → 3
4 → 5
```

Update in-degree:

| Node | Old | New |
| ---- | --- | --- |
| 3    | 1   | 0   |
| 5    | 1   | 0   |

Nodes with 0 in-degree now:
→ **3** and **5**

---

# 🔷 **Step 5: Pick Next Zero In-degree**

Pick either **3** or **5**.

Two possible valid outputs:

```
1 2 4 3 5
1 2 4 5 3
```

Both are correct.

---

# ⭐ **Final Topological Sort Output**

Exactly like in your image:

```
1 2 4 3 5
1 2 4 5 3
```

---

# 🧠 **Why does this method work?**

* A node with **0 in-degree** has **NO dependencies**, so it must come first.
* Removing its outgoing edges may produce new nodes with **0 in-degree**.
* Continue until all nodes are removed.

If at any point **no node has 0 in-degree** but graph still has nodes → **Cycle exists** (topological sorting not possible).

---


# ⭐ **Algorithm: Topological Sorting Using In-Degree Method (Kahn’s Algorithm)**

*(Perfect for exam writing)*

### **Input:** A Directed Acyclic Graph (DAG)

### **Output:** A topological ordering of all vertices

---

## 🔶 **Algorithm Steps**

1. **Compute in-degree** for every vertex in the graph.
   (In-degree = number of incoming edges)

2. **Insert all vertices** with in-degree = 0 into a queue.

3. **Repeat until the queue becomes empty:**

   * Remove a vertex `u` from the queue.
   * Add `u` to the topological order list.
   * For every adjacent vertex `v` of `u`:

     * Reduce `in-degree[v]` by 1
     * If `in-degree[v]` becomes 0, insert `v` into the queue

4. After processing all vertices:

   * If the topological order contains **all vertices**,
     → a valid topological sorting exists
   * Otherwise, if some vertices are left
     → graph contains a **cycle** (topological sorting not possible)

---

### ⭐ **Important Note for Exam**

> Topological sorting is applicable **only for Directed Acyclic Graphs (DAGs)**.
> If any cycle exists, no node will reach in-degree 0 → algorithm detects cycle.

---




# ⭐ **Connected Components in a Graph**

![alt text](image-77.png)
![alt text](image-78.png)

---



A **connected component** of an undirected graph is a **set of vertices** such that:

* Every vertex is reachable from every other vertex in the same set
* No vertex in this group is connected to vertices outside the group

In simple words:

> A connected component is a “group of nodes that are connected to each other.”

---

# 📌 **Example**

```
(1)---(2)---(3)

(4)---(5)

(6)
```

Connected components:

* Component 1 → {1, 2, 3}
* Component 2 → {4, 5}
* Component 3 → {6}

So the graph has **3 connected components**.

---

# ⭐ **Why Find Connected Components?**

* To identify how many separate groups exist
* Used in networks, social media clusters, image segmentation
* Helps determine whether a graph is fully connected

---

# 🔶 **Algorithm for Connected Components Using DFS**

*(Correct version with count incremented after DFS call)*

### **Input:** Undirected graph

### **Output:** Number of connected components

---

## **Algorithm (DFS Method)**

1. Mark all vertices as **unvisited**.
2. Initialize `component_count = 0`.
3. For each vertex `v` in the graph:

   * If `v` is **unvisited**:

     * Call **DFS(v)** to visit all nodes reachable from `v`
     * **After DFS completes**, increment
       `component_count = component_count + 1`
4. DFS(v):

   * Mark `v` as visited
   * For each adjacent vertex `u`:

     * If `u` is unvisited → call DFS(u)
5. After checking all vertices,
   **`component_count` is the total number of connected components.**

---

# 🔷 **Algorithm for Connected Components Using BFS**

1. Mark all vertices as unvisited
2. Set `component_count = 0`
3. For each vertex `v`:

   * If `v` is **unvisited**:

     * Push `v` into a queue
     * While queue is not empty:

       * Pop a node and mark it visited
       * Push all unvisited neighbors
     * **After BFS finishes**, increment
       `component_count++`
4. Return `component_count`

---

# ⭐ **Important Points**

* Works only for **undirected graphs**
  (Directed graphs use **Strongly Connected Components – SCC**)
* Each DFS/BFS call completely covers **one component**
* Total connected components = **number of DFS/BFS calls**

---

# 🎯 **One-Line Summary**

> A connected component is a maximal group of vertices reachable from each other.
> The number of connected components equals the number of times DFS/BFS is started on an unvisited vertex.

---

# ⭐ **Bridges (Cut Edges) in a Graph**


![alt text](image-79.png)
![alt text](image-80.png)
Here is a **perfect, clear, exam-ready explanation** of
**Bridges (Cut Edges) in a Graph** + **Algorithm (Tarjan’s Algorithm)** using DFS.

This is exactly what you need for 5–10 marks.

---

A **bridge** (also called a **cut edge**) in an undirected graph is an edge whose **removal increases the number of connected components**.

In simple words:

> A bridge is an edge that, if removed, will disconnect part of the graph.

---

# 📌 **Example**

Graph:

```
1 --- 2 --- 3
      |
      4
```

Bridges:

* (2,1)
* (2,3)
* (2,4)

Because removing any of these edges will increase the number of components.

---

# ⭐ **Why are Bridges Important?**

* Network design reliability
* Finding weak links in communication networks
* Identifying vulnerabilities in roads/power networks
* Used in articulation point/bridge algorithms

---

# 🔥 **Key Concepts Used to Find Bridges**

We use **DFS + 2 arrays**:

### 1️⃣ **disc[v]**

* Discovery time of vertex v
* (When v is first visited in DFS)

### 2️⃣ **low[v]**

* The **lowest discovery time** reachable from v
* Using:

  * DFS tree edges
  * Back edges

---

# 🧠 **Condition for Bridge**

> **An edge (u, v) is a bridge if:**
> `low[v] > disc[u]`

Meaning:

* v **cannot reach** u or any of u's ancestors through back edges
  → Therefore removing (u, v) breaks the graph.

---

# ⭐ **Algorithm: Find All Bridges (Tarjan’s Algorithm)**

*(DFS-based)*
**Input:** Undirected graph
**Output:** Allbridge edges

---

## ✔️ **Algorithm Steps**

1. Initialize arrays:

   * `visited[] = false`
   * `disc[] = -1`
   * `low[] = -1`
   * `time = 0`
2. For each vertex `v`:

   * If not visited:

     * Call **DFS(v, parent = -1)**

---

## ✔️ **DFS(u, parent)**

1. Mark `u` as visited
2. Set:

   * `disc[u] = low[u] = ++time`
3. For every adjacent vertex `v` of `u`:

   ### Case 1: `v` is parent of `u`

   * Ignore (continue)

   ### Case 2: `v` is NOT visited

   * Call DFS(v, u)
   * After return:

     * Update:
       `low[u] = min(low[u], low[v])`
     * **Bridge condition:**
       If `low[v] > disc[u]`
       → Edge (u, v) is a **bridge**

   ### Case 3: `v` is visited (Back Edge)

   * Update low[u]:
     `low[u] = min(low[u], disc[v])`

---

# 📌 **Bridge Condition Explained**

If:

```
low[v] > disc[u]
```

It means:

* v and its subtree cannot reach u or its ancestors
* So (u, v) is a crucial connection
* Removing it breaks the graph
  → Hence (u, v) is a **bridge**

---

# ⭐ **Example to Understand**

Graph:

```
1---2---3
    |
    4
```

DFS Order:

* disc[]: 1,2,3,4
* low[]: 1,2,3,2

Check edges:

* (2,1): low[2] = 2 > disc[1] = 1 → Bridge
* (2,3): low[3] = 3 > disc[2] = 2 → Bridge
* (2,4): low[4] = 4 > disc[2] = 2 → Bridge

So all these edges are bridges.

---

# ⭐ **Important Points**

* Works only on **undirected graphs**
* Uses **DFS + low-link values**
* Time Complexity: **O(V + E)**
* Tarjan’s Algorithm is used for:

  * Bridges
  * Articulation points
  * Strongly connected components (directed)

---

# 🎯 **One-Line Summary**

> A bridge is an edge whose removal disconnects the graph.
> It is found using DFS: edge (u, v) is a bridge if **low[v] > disc[u]**.

---

----

# ⭐ **Bellman–Ford Algorithm (Single Source Shortest Path)**

## negative weight edge par yhi shi se kaam karega 
![alt text](image-81.png)
![alt text](image-82.png)
![alt text](image-83.png)
## in third operation no change so over here only 
![alt text](image-84.png)
## shortest distance 
![alt text](image-85.png)
## time conplexity for complete graph n^3
![alt text](image-86.png)

## questions 2: its not work properly when negative cycle formed 
![alt text](image-87.png)
![alt text](image-88.png)
![alt text](image-89.png)
![alt text](image-90.png)
## according to bellman ford we need to (vertex-1) iteration , so we need only 3 iteration for this question but we do 4th iteration then it should not be change the shortest path but  in this case it  changes so that we can say negative weight cycle formed  
![alt text](image-91.png)

---

Here is your **full combined Bellman–Ford explanation WITH the properly written algorithm inserted inside**, clean and exam-ready.

---

# ⭐ **Bellman–Ford Algorithm — Single Source Shortest Path**

The **Bellman–Ford Algorithm** is used to find the **shortest path** from a **single source vertex** to **all other vertices** in a **weighted graph**.

Unlike Dijkstra’s Algorithm:

✔ Bellman-Ford **can handle negative edge weights**
✔ It can **detect negative weight cycles**

---

# ⭐ **Where Bellman–Ford is Used?**

* Graphs with **negative weights**
* Detecting **negative weight cycles**
* Financial graphs (profit-loss edges)
* Computer networks

---

# 🔶 **Works On**

| Graph Type       | Supported                                |
| ---------------- | ---------------------------------------- |
| Directed         | ✔ Yes                                    |
| Undirected       | ✔ Yes (*convert to directed pair edges*) |
| Negative Weights | ✔ Yes                                    |
| Negative Cycles  | ✔ Detectable                             |

---

# ⭐ **Key Idea**

Bellman–Ford repeatedly **relaxes** (updates) all edges.

### **Relaxation Rule:**

For an edge **u → v** with weight **w**:

```
if dist[u] + w < dist[v]:
      dist[v] = dist[u] + w
```

Relaxation tries to improve the shortest path.

---

# ⭐ **Algorithm (Proper Exam-Ready Format)**

*(No code — Pure Algorithm)*

### **Input:**

Graph with `V` vertices and `E` edges, and a source vertex `S`.

### **Output:**

Shortest distance from source to all vertices or detection of a negative weight cycle.

---

## ✔️ **Step 1 — Initialization**

For every vertex `v`:

* Set `dist[v] = ∞`

Set:

* `dist[S] = 0`

---

## ✔️ **Step 2 — Relax All Edges (V − 1 times)**

Repeat the following process exactly **(V − 1)** times:

For each edge `(u, v, w)`:

* If `dist[u] + w < dist[v]`, then update:

  * `dist[v] = dist[u] + w`

This step allows all shortest paths (with at most V−1 edges) to be found.

---

## ✔️ **Step 3 — Check for Negative Weight Cycle**

For every edge `(u, v, w)`:

* If `dist[u] + w < dist[v]`, then:

  * A **negative weight cycle exists**
  * Shortest paths are not valid

---

## ✔️ **Step 4 — Output**

If no negative cycle is detected, output the final shortest distance values.

---

# ⭐ **Why (V − 1) Relaxations?**

In a graph with **V** vertices, the longest possible shortest path contains **V−1 edges**.
Therefore, relaxing all edges V−1 times guarantees the shortest paths are found.

---

# ⭐ **Time Complexity**

```
O(V × E)
```

Slower than Dijkstra, but works with **negative edges**.

---

---

# ⭐ **Important Properties**

* Handles **negative weights**
* Detects **negative cycles**
* Works for **directed and undirected** graphs
  (undirected edges must be added twice)

---

# 🎯 **One-Line Summary (Exam)**

> Bellman–Ford finds the shortest path from a single source by relaxing all edges (V−1 times) and detects negative cycles by checking if any distance can still be improved.

---
