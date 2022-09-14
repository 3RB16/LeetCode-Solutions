class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = *max_element(arr.begin() , arr.end());
        deque <int> Q;
        for(const int value : arr)
            Q.push_back(value);
        int cnt = 0;
        while(Q.size() > 1){
            int firstValue = Q.front();
            Q.pop_front();
            int secondValue = Q.front();
            Q.pop_front();
            if(firstValue > secondValue) {
              Q.push_front(firstValue); 
              ++cnt;
            } else {
              Q.push_front(secondValue); 
              cnt = 1;
            }
            if(cnt == k)
                return Q[0];
        } 
        return winner;
    }
};