# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
  @res = []
  permute_nums(nums, [], [])
  @res
end

def permute_nums(nums, used, arr)
  len = nums.length
  if arr.length == len
    @res << arr.dup
    return
  end
  
  (0...len).each do |i|
    unless used[i]
      arr << nums[i]
      used[i] = true
      permute_nums(nums, used, arr)
      arr.pop
      used[i] = false
    end 
  end
end