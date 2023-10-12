# @param {String} s1
# @param {String} s2
# @param {Integer} x
# @return {Integer}
def min_operations(s1, s2, x)
    @idxs = (0...s1.length).select { |i| s1[i] != s2[i] }
    return -1 unless @idxs.length % 2 == 0
    
    @x = x / 2.0
    @memo = Array.new(@idxs.length,nil)
    min_cost(0).to_i
end

def min_cost(i)
    return 0 if i == @idxs.length
    return @x if i == @idxs.length - 1
    return @memo[i] if @memo[i]
    
    option1 = @x + min_cost(i+1)
    option2 = @idxs[i+1] - @idxs[i] + min_cost(i+2)
    
    @memo[i] = [option1,option2].min
end