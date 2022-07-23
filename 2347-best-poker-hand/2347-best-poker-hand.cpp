class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        set <char> st;
        for(auto it : suits)
            st.insert(it);
        if(st.size() == 1)
            return "Flush";
        map<int , int> f;
        for(auto it : ranks)++f[it];
        bool paired = false;
        for(const auto[i , j] : f){
            if(j >= 3)
                return "Three of a Kind";
            if(j == 2)paired = true;
        }
        return paired ? "Pair" : "High Card";
    }
};