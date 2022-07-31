class Solution {
public:
    int maximumGroups(vector<int>& grades) {
       if(int(grades.size()) < 3)
           return 1;
        int groups = 0, cnt = 1;
        for(int i = 0; i < int(grades.size()); i += cnt){
            ++groups , ++cnt;
        }
        return groups;
    }
};