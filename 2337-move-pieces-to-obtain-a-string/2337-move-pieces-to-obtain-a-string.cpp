class Solution {
public:
    bool canChange(string start, string target) {
      vector<pair<char , int>> indices;
      for(int i = 0;i < (int)start.size();i++){
        if(start[i] != '_'){
          indices.push_back(make_pair(start[i] , i));
        }
      }
      int index = 0;
      for(int i = 0;i < (int)target.size();i++){
        if(target[i] == '_')continue;
        if(index >= indices.size() || indices[index].first != target[i])
             return false;
        if(indices[index].first == 'L' && indices[index].second < i)
            return false;
        if(indices[index].first == 'R' && indices[index].second > i)
            return false;
        ++index;
      }
      return index == indices.size();
    }
};