// isOutOfBounds checks if the coordinates are out of bounds
func isOutOfBounds(i, j, n, m int) bool {
	return i < 0 || i >= n || j < 0 || j >= m
}

// dfs performs a depth-first search to explore all connected land cells
func dfs(grid [][]int, visited [][]bool, i, j, n, m int, component *[][2]int) {
	if isOutOfBounds(i, j, n, m) || visited[i][j] || grid[i][j] == 0 {
		return
	}

	visited[i][j] = true
	*component = append(*component, [2]int{i, j})

	// Explore all four directions
	dfs(grid, visited, i+1, j, n, m, component)
	dfs(grid, visited, i-1, j, n, m, component)
	dfs(grid, visited, i, j+1, n, m, component)
	dfs(grid, visited, i, j-1, n, m, component)
}

// countSubIslands counts the number of sub-islands in grid2 that are also present in grid1
func countSubIslands(grid1, grid2 [][]int) int {
	n := len(grid1)
	m := len(grid1[0])

	// Initialize visited matrices for grid1 and grid2
	visitedGrid1 := make([][]bool, n)
	visitedGrid2 := make([][]bool, n)
	for i := range visitedGrid1 {
		visitedGrid1[i] = make([]bool, m)
		visitedGrid2[i] = make([]bool, m)
	}

	// Mark all visited cells in grid1
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid1[i][j] == 1 && !visitedGrid1[i][j] {
				var component [][2]int // Empty slice since we don't need it for grid1
				dfs(grid1, visitedGrid1, i, j, n, m, &component)
			}
		}
	}

	subIslandCount := 0

	// Check each component in grid2 to determine if it is a sub-island of grid1
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid2[i][j] == 1 && !visitedGrid2[i][j] {
				var component [][2]int
				dfs(grid2, visitedGrid2, i, j, n, m, &component)

				isSubIsland := true
				for _, cell := range component {
					row, col := cell[0], cell[1]
					if !visitedGrid1[row][col] {
						isSubIsland = false
						break
					}
				}
				if isSubIsland {
					subIslandCount++
				}
			}
		}
	}

	return subIslandCount
}
