class Solution {
public:
 string longestCommonPrefix(vector<string>& strs) {
    map<string , int>frq;
    for(auto it : strs){
        string ret = "";
        string cur = it;
        for(int i = 0;i < (int)cur.size();i++){
            ret += cur[i];
            frq[ret]++;
        }
    }
    int answer = 0;
    string out = "";
    for(auto i : frq){
        if(i.second >= answer){
            answer = i.second;
            out = i.first;
        }
    }
  return (answer == (int)strs.size()  ? out : "");
 }
};