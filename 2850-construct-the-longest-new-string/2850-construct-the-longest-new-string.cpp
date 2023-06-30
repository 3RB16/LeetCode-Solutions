class Solution {
public:
    int longestString(int x, int y, int z) {
       int minimum = min(x, y);
       return (z << 1) + (minimum << 2) + ((x != y) << 1);
    }
};