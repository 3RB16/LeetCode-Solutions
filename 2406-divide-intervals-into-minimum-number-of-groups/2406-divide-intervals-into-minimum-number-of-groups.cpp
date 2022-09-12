class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(begin(intervals) , end(intervals));
        set<pair<int , int>> st;
        for(int i = 0;i < int(intervals.size());i++)
            st.insert(make_pair(intervals[i][0] , i));
        int cnt = 0;
        for(int i = 0;i < int(intervals.size());i++){
            if(st.count(make_pair(intervals[i][0] , i)) == 0)
                continue;
            ++cnt;
            st.erase(make_pair(intervals[i][0] , i));
            int last = intervals[i][1];
            while(!st.empty()){
                auto it = st.upper_bound(make_pair(last , INT_MAX));
                if(it == st.end())break;
                last = intervals[it->second][1];
                st.erase(it);
            }
        }
        return cnt;
    }
};
