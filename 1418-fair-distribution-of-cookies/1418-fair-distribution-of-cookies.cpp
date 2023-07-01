class Solution {
public:
    vector <int> bags;

    int solve(int index , const vector<int>& cookies, int k) {
        int n = int(cookies.size());
        if(index == n) {
            return *max_element(begin(bags) , end(bags));
        }
        int ret = INT_MAX;
        for(int i = 0;i < k;i++){
            bags[i] += cookies[index];
            ret = min(ret , solve(index + 1 ,cookies , k));
            bags[i] -= cookies[index];;
        }
        return ret;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        bags.resize(k , 0);
        return solve(0 , cookies , k);
    }
};