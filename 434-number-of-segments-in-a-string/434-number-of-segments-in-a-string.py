class Solution(object):
    def countSegments(self, data):
        count_spaces = 0
        is_word = False
        for index in range(0 , len(data)):
            if data[index] == ' ':
              if(is_word == True):
                count_spaces += 1
                is_word = False
            else:
                is_word = True;
        if(is_word == True):
            count_spaces += 1
        return count_spaces
        
        