class Solution {
public:
    int getDistance(vector <int> &cuts , int len) {
        int distance = cuts[0];
        for(int i = 1;i < (int)cuts.size();i++){
            distance = max(distance , cuts[i] - cuts[i - 1]);
        }
        distance = max(distance , len - cuts.back());
        return distance;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        static const int MOD = 1e9 + 7;
        sort(begin(verticalCuts) , end(verticalCuts));
        sort(begin(horizontalCuts) , end(horizontalCuts));
        int distanceVertical = getDistance(verticalCuts , w);
        int distanceHorizontal = getDistance(horizontalCuts , h);
        return (long long)distanceVertical *1LL* distanceHorizontal % MOD;
    }
};