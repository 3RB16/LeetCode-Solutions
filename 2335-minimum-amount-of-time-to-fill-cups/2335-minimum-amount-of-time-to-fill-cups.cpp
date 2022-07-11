class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue <int> pq;
        for(auto item : amount)
            if(item)pq.push(item); 
        int seconds = 0;
        while(pq.size() > 1){
            int biggest = pq.top();
            pq.pop();
            int sec_big = pq.top();
            pq.pop();
            ++seconds;
            --biggest , --sec_big;
            if(biggest)pq.push(biggest);
            if(sec_big)pq.push(sec_big);
        }
        if(pq.size())
         seconds += pq.top();
        return seconds;
    }
};
