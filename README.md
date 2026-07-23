# Coin Maze Solver
`cd project`
`g++ -O2 maze_solver.cpp -o maze_solver`

Run tiny maze: `./maze_solver test_mazes/tiny_2coins.txt`
Run medium maze: `./maze_solver test_mazes/medium_5coins.txt`
Run weighted maze: `./maze_solver test_mazes/weighted_4coins.txt`
Run stress maze: `./maze_solver test_mazes/stress_8coins.txt`
The program prints uniform and weighted results for every maze.
Tiny maze expected uniform order: `S -> c(3,0) -> c(0,7) -> G`.
Tiny maze expected total steps: `17`.
Tiny maze expected weighted total cost: `17`.