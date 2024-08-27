import (
	"container/heap"
)

type Edge struct {
	node       int
	probability float64
}

func maxProbability(n int, edges [][]int, succProb []float64, start int, end int) float64 {
	// Initialize graph as an adjacency list
	graph := make([][]Edge, n)
	for i := 0; i < len(edges); i++ {
		u, v := edges[i][0], edges[i][1]
		graph[u] = append(graph[u], Edge{v, succProb[i]})
		graph[v] = append(graph[v], Edge{u, succProb[i]})
	}

	// Probability to reach each node from the start node
	dist := make([]float64, n)
	dist[start] = 1.0

	// Max heap to store the node and its probability
	maxHeap := &MaxHeap{}
	heap.Init(maxHeap)
	heap.Push(maxHeap, Edge{start, 1.0})

	for maxHeap.Len() > 0 {
		current := heap.Pop(maxHeap).(Edge)
		node := current.node
		prob := current.probability

		// If we reached the end node
		if node == end {
			return prob
		}

		// Explore the neighbors
		for _, neighbor := range graph[node] {
			newProb := prob * neighbor.probability
			if newProb > dist[neighbor.node] {
				dist[neighbor.node] = newProb
				heap.Push(maxHeap, Edge{neighbor.node, newProb})
			}
		}
	}

	return 0.0
}

type MaxHeap []Edge

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i].probability > h[j].probability }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(Edge))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
