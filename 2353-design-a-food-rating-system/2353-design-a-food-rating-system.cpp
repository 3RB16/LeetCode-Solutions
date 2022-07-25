class FoodRatings {
  public:
    struct myComparator {
        bool operator()(const pair<int,string> &lhs, const pair<int,string> &rhs) const {
            if(lhs.first == rhs.first)
                return lhs.second < rhs.second;
            return lhs.first > rhs.first;
        }
    };
    unordered_map<string, set<pair<int,string>, myComparator>> cuisinesList;
    unordered_map<string, int>rate;
    unordered_map<string, string>cuis;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            cuisinesList[cuisines[i]].insert(
                make_pair(ratings[i],foods[i])
            );
            cuis[foods[i]] = cuisines[i];
            rate[foods[i]] = ratings[i];
        }

    }

    void changeRating(string food, int newRating) {
        int oldRate = rate[food];
        string cuisine = cuis[food];
        cuisinesList[cuisine].erase(make_pair(oldRate, food));
        rate[food] = newRating;
        cuisinesList[cuisine].insert(make_pair(newRating, food));
    }

    string highestRated(string cuisine) {
        return cuisinesList[cuisine].begin()->second;
    }
};
