class Solution {
public:
vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
   int frequency[26] = {};
   for(string item : words2) {
    int last[26] = {};
    for(char c : item) {
     last[c - 'a']++;
    }
    for(int i = 0;i < 26;i++) {
     frequency[i] = max(frequency[i] , last[i]);
    }
   }
   vector <string> answer;
   for(string item : words1) {
    int last[26] = {};
    for(char c : item){
     last[c - 'a']++;
    }
    bool valid = true;
    for(int i = 0;i < 26;i++){
     if(last[i] < frequency[i]){
      valid = false;
     }
    }
    if(valid){
     answer.push_back(item);
    }
   }
   return answer;
 }
};