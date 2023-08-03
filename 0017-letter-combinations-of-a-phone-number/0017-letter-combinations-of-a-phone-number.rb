# @param {String} digits
# @return {String[]}
def letter_combinations(digits)
    return [] if digits.empty?

    phone_map = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
    output = []

    def backtrack(combination, next_digits, phone_map, output)
        if next_digits.empty?
            output << combination
        else
            letters = phone_map[next_digits[0].to_i - 2]
            letters.each_char do |letter|
                backtrack(combination + letter, next_digits[1..], phone_map, output)
            end
        end
    end

    backtrack("", digits, phone_map, output)
    output
end