class Solution(object):
    def reverseWords(self, s):
        answer = ""
        cur = ""
        s += " "
        for char in s:
            if char == ' ':
                answer += cur[::-1]
                answer += " "
                cur = ""
            else:
                cur += char
        return answer[:len(answer) - 1]
                
        