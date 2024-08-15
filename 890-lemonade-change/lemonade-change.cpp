class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill_freq[11] = {};
        for(const int bill : bills){
           if(bill == 5) {
                bill_freq[5] += 1;
           } else if(bill == 10) {
            if (bill_freq[5] == 0) {
               return false;
            }
            bill_freq[10] += 1;
            bill_freq[5] -= 1;
           }  else if(bill == 20) {
               if (bill_freq[10] > 0 and bill_freq[5] > 0) {
                    bill_freq[10] -= 1;
                    bill_freq[5] -= 1;
               } else if(bill_freq[5] > 2) {
                    bill_freq[5] -= 3;
               } else {
                    return false;
               }
           }
        }
        return true;
    }
};