class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<pair<int , int>> pairs;
        sort(begin(arr) , end(arr));
        int median = arr[(arr.size() - 1) / 2];
        for(auto item : arr){
         pairs.push_back(make_pair(
                          item , abs(item - median)
                         ));
        }
        sort(begin(pairs) , end(pairs) ,[&](const auto pair1 , const auto pair2){
          return pair1.second == pair2.second ? pair1.first > pair2.first : pair1.second > pair2.second;
        });
        vector <int> answer;
        for(int i = 0;i < k;i++){
            answer.push_back(pairs[i].first);
        }
        return answer;
    }
};