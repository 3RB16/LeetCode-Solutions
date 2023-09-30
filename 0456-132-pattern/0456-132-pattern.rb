# @param {Integer[]} nums
# @return {Boolean}
def find132pattern(nums)
    stack = []
    minimum = -Float::INFINITY
    nums = nums.reverse
    nums.each_with_index do |val,index|
        return true if minimum > val
        minimum = stack.pop while !stack.empty? and stack[-1] < val
        stack.push(val)
    end
    false
end