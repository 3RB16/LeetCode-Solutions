# @param {String} s
# @param {String[]} word_dict
# @return {Boolean}
def word_break(s, word_dict)
    h, q, visited = {}, [0], [0] * s.size
    word_dict.each{|w| h[w] = w.size}
    until q.empty?
        start = q.shift
        h.values.each do |wlen|
            if h[s[start...(start + wlen)]]
                return true if start + wlen == s.size
                if visited[start + wlen] == 0
                    q.push(start + wlen)
                    visited[start + wlen] = 1
                end
            end
        end
    end
    false
end