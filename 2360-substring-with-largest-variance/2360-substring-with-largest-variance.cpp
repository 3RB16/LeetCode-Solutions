class Solution {
public:
    int largestVariance(string s) {
        unordered_set<char>letters(begin(s) , end(s));
        int largest_variance = 0;
        
        for(auto largest : letters) {
            for(auto smallest : letters) {
                if(largest == smallest){
                    continue;
                }
                int count_largest = 0 , count_smallest = 0;
                for(const char letter : s) {
                    count_largest += (letter == largest);
                    count_smallest += (letter == smallest);

                    int difference = count_largest - count_smallest;
                    largest_variance = max(largest_variance ,count_smallest > 0 ? difference : difference - 1);

                    if(count_smallest > count_largest) {
                        count_largest = count_smallest = 0;
                    }
                    
                }
            }
        }

        return largest_variance;
    }
};