class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        dictionary = {}
        first_row = "qwertyuiop"
        for i in range(0 , len(first_row)):
            dictionary[first_row[i]] = 1
            
        second_row = "asdfghjkl"
        for i in range(0 , len(second_row)):
            dictionary[second_row[i]] = 2
            
        third_row = "zxcvbnm" 
        for i in range(0 , len(third_row)):
            dictionary[third_row[i]] = 3
            
        words_list = []
        for word in words:
           my_set = set()
        
           for i in range(0 , len(word)):
              my_set.add(dictionary[word[i].lower()])
            
           if(len(my_set) == 1): # now we find our answer
             words_list.append(word)
            
        return words_list
         
        
        
        