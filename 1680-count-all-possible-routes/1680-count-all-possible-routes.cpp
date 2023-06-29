class Solution {

private:
    const static int MOD = 1e9 + 7;
    int memo[105][205];

    int solve(int city , int fuel , int finish , const vector <int> &locations) {
        if(fuel < 0) {
            return 0;
        }

        int &ret = memo[city][fuel];

        if(~ret) {
            return ret;
        }

        ret = city == finish ? 1 : 0;

        for (int nextCity = 0; nextCity < int(locations.size()); nextCity++) {
            if (nextCity != city && fuel >= abs(locations[nextCity] - locations[city])) {
                ret = (ret + solve(nextCity, fuel - abs(locations[nextCity] - locations[city]), finish, locations)) % MOD;
            }
        }

        return ret;
    }

public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
            memset(memo , -1 , sizeof memo);
            return solve(start , fuel , finish , locations);
    }
};