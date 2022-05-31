class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int , char>> maxHeap;
        if(a > 0)maxHeap.push(make_pair(a , 'a'));
        if(b > 0)maxHeap.push(make_pair(b , 'b'));
        if(c > 0)maxHeap.push(make_pair(c , 'c'));
        string ans = "";
        while(!maxHeap.empty()){
            auto [val , c] = maxHeap.top();
            maxHeap.pop();
            if(ans.empty()){
               --val;
               ans += c;
            } else if(ans.back() != c) {
              --val;
              ans += c;
            } else {
              if(ans.size() < 2) {
                --val;
                ans += c;
              } else if(ans.size() > 1 && c != ans[ans.size() - 2]){
                --val;
                ans += c;
              } else {
                if(maxHeap.empty())break;
                auto tp = maxHeap.top();
                maxHeap.pop();
                ans += tp.second;
                tp.first--;
                if(tp.first)maxHeap.push(tp);
              }
            }
            if(val){
              maxHeap.push(make_pair(val , c));
            }
        }
        return ans;
    }
};