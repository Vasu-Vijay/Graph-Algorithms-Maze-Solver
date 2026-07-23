# Search Algorithm Report

The solver divides the work into two layers. BFS builds shortest step distances between the start, coins, and goal on uniform terrain. Dijkstra builds the weighted equivalent, while A* computes the same weighted distances using the Manhattan-distance heuristic. The `bestOrder` DFS then tries coin orders with best-so-far pruning: whenever a partial route is already at least as expensive as the best complete route found, that entire branch is skipped.

On `medium_5coins.txt`, the best order is `S -> c(3,0) -> c(7,0) -> c(0,7) -> c(3,9) -> c(7,9) -> G`, with total cost 32. Across all 49 key-point pair queries in that maze, Dijkstra expands 2,182 cells and A* expands 872. A* expands fewer cells because its Manhattan heuristic prioritizes cells that are both cheap so far and geometrically closer to the requested target. It remains optimal because each move costs at least one, so Manhattan distance never overestimates the remaining cost.

The 8-coin stress maze has 40,320 possible complete orders. DFS still completes quickly because a good route is found early and expensive partial routes are discarded before they grow into full permutations. This is much more efficient than recalculating shortest paths inside the permutation search.

Terrain edges use the larger terrain value of their two endpoint cells. This makes every weighted edge undirected, so both distance matrices satisfy the required symmetry check.