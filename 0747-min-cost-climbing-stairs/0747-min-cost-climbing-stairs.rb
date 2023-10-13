# @param {Integer[]} cost
# @return {Integer}
def min_cost_climbing_stairs(cost)
    @n = cost.length
    @memo = Array.new(@n , nil)
    @cost = cost
    [solve(0) , solve(1)].min
end

def solve(steps)
  return 0 if steps >= @n
  return @memo[steps] if @memo[steps]

  @memo[steps] = @cost[steps] + [solve(steps + 1) , solve(steps + 2)].min
end