class Solution {
public:
    bool isPowerOfFour(int n) {
     for(int i  = 0;i < 16;i++){
         if(int(pow(4 , i)) == n)
             return true;
     }
     return false;
    }
};