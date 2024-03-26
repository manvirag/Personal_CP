#### Graph:
1. DFS/BFS: ✅ 
2. 0/1 BFS (SP linear): ✅ 
3. Inverse Graph: ✅
   1. https://codeforces.com/problemset/problem/1242/B
   2. You're given an undirected graph of n nodes with n(n-1)/2 total edges (it is complete). You are given m edges, where the length is 1, and the rest of the n(n-1)/2 — m edges are of length 0. Find the Minimum Spanning Tree (MST) of this graph.
   3. It can be shown that our MST will consist of as many edges of 0 that we can add (lets call a collection of nodes with the same length 0 connected to each other a connected component). Therefore, there will be a select number of 1s that we must use to connect these components. It turns out that the number of 1s we need to use is equivalent to the number of connected components in the graph subtracted by 1.
   4. Now, our problem is reduced down to find the number of connected components with the length of 0. Naive DFS or BFS takes O(V + E) time, where V = n and E = n(n-1)/2. It can be shown then, that our current code would be in O(N^2). However, we can make the observation that whenever we visit an element, we don't need to check this element anymore in any of our future traversals. Therefore, we can try to erase this node in every visit. We can simply manage do this with a set.
   5. intuition: if we normally do , to find connected component of zero edges will be n^2 , because each vertex we are checking for all n vertices. What there is any sence in even consider in looping the visited vertex. So maintain a set of all vertice, and only loop on the remaining vectex and which also not have weight 1. 
4. LCA: (Binary lifting)✅
5. SCC: (Kosaraju's algorithm) ✅ 
6. DFS tree: 
   1. 
7. Re-rooting technique:
8. Articulation Bridges and Bridge Tree:
9. Strong orientation:
10. Articulation points
11. Topological
12. Prim’s MST
13. Krushkhal’s MST
14. Dijkstra's Algorithm
15. Bellman Ford
16. Floyd Warshall
17. Euler tour
18. SPFA
19. Cycle detection
    1. Directed/Undirected
20. 2 SAT
21. Maximum Clique
22. Maximum independent set
23. Eulerian path
    1. Directed graph
    2. Undirected
24. Chromatic number
25. Counting labeled graphs
26. Number of Ways to Make a Graph Connected
27. Prufer Code
28. Tree Isomorphism
29. Dinics Algorithm (Max flow)
30. Hopcroft Karp Algorithm
31. Kuhns Algorithm
32. Hungarian Algorithm
33. Chinese Postman Problem
