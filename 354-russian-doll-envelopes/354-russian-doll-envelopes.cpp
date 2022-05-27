class Solution {
public:
 int maxEnvelopes(vector<vector<int>>& _envelopes) {
    vector<pair<int , int>> envelopes;
    for(auto envelope : _envelopes)
        envelopes.push_back(make_pair(envelope[0] , envelope[1]));
	int size = envelopes.size();
	sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int>b){
		return a.first < b.first || (a.first == b.first && a.second > b.second);
	});
	vector <int> collector;
	for(auto& pair: envelopes){
		auto iter = lower_bound(collector.begin(), collector.end(), pair.second);
		if(iter == collector.end()) collector.push_back(pair.second);
		else if(*iter > pair.second) *iter = pair.second;
	}
	return (int)collector.size();
  }
};