class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int , string>> ans;
        for (int i = 0;i < int(heights.size());i++){
            ans.push_back(
                make_pair(heights[i] , names[i])
            );
        }
        
        sort(rbegin(ans), rend(ans));
        
        vector<string> people;
        for(const auto[height , name] : ans)
            people.push_back(name);
        
        return people;
    }
};