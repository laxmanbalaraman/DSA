## Graphs

### Bellman-Ford algorithm

<b> Time Complexity: O(VE) </b>

- Single source shortest path.
- Detect -ve cycle in Graph which Dijkstra can't.

<b>Why V - 1 times iteration?</b> <br />
We get shortest path from source to all nodes at a time when all the node are relaxed.
Since there are n - 1 nodes(excluding source for which we already know the distance),it takes a maximum of n - 1 times for all nodes to get relaxed which happens when graph is linear or cyclic (worst case).
The graph must become stable within n - 1 iteration, else it means that we have a -ve cycle and the array never becomes stable.
It makes sense because a negative cycle cannot have shortest path because each node will get updated to a lesser value infinitly so we cannot predict a shortest path.
Using this stability of weight array intuituion, we will be able to detect if a graph has cycle or not using bellman ford algo.
It is single source shortest path because, first the relaxation happens for
adjacent nodes of source node and then for subsequent iteration for rest of the nodes
hence each node will carry the potentially shortest path from source.

### Floyd-Warshall algorithm

<b> Time Complexity: O(V^3) </b>

- All pairs shorted paths
- Detect negative cycle in graph (Prefer Bellman-Ford)

If each distance between two nodes can be reduced by an intermediate node _k_, then we update the cost of the two nodes. Hence we check for all nodes as intermediate nodes update if distance between two given node reduces.
Making all nodes intermediate O(n), and checking simultaneously distance between each node O(n^2) which results to O(n^3).<br/>

If any distance between each node results to -ve, then we can a negative cycle exists in the graph.

1. The Djiktra method can be achieved with less complexity , especially with sparse graphs .
   By using binary heap as a priority queue we achieve O(nmlogn) and with a fibonacci heap we achieve O( (m+nlogn)\*n).
2. The main advantage of this method compared to Djiktra is that it can be implemented in a graph even if we have edges of negative weights

### Kosaraju Algorithm

Time Complexity: O(V + E) - 2 dfs + 1 adj matrix reversal<br/>

- Find strongly connected components in a graph

Strongly connected components are components in graph where there exist a path from any node to any other node.
Basically, Strongly connected components are nothing but cycles in an directed graph. An undirected graph is always a strongly connected components because one can reach any node from any other node.</br>

Intuition is that if u reverse the directions in graph (transpose/converse), the strongly connected component will still remain same. <br/>
We traverse the graph using dfs in the order of its topological sort. The number of times dfs is called during this process is nothing but the strongly connected components. First priority node is taken from the topological sort, and its cycle is visited, then the immediate next priority node that is not yet visited is visited and again its cycle elements are visited. In this way all the cycles (Strongly connected components) are visited.<br/>
