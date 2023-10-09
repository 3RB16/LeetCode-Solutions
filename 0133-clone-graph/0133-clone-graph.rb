# Definition for a Node.
# class Node
#     attr_accessor :val, :neighbors
#     def initialize(val = 0, neighbors = nil)
#		  @val = val
#		  neighbors = [] if neighbors.nil?
#         @neighbors = neighbors
#     end
# end

# @param {Node} node
# @return {Node}
def cloneGraph(node)
    return nil if node.nil?
    dfs({}, node)
end

def dfs(visited, node)
    unless node.nil? || visited[node.val]
        visited[node.val] = Node.new(node.val)
        visited[node.val].neighbors = node.neighbors.map do |node|
            dfs(visited, node)
        end
    end
    visited[node.val]
end
