class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      stack <int> indices;
      int n = (int)temperatures.size();
      vector <int> answer(n , 0);
      for(int i = n - 1;i >= 0;i--){
         while(!indices.empty() and temperatures[indices.top()] <= temperatures[i]) {
           indices.pop();  
         }
         if(!indices.empty()){
           answer[i] = indices.top() - i;
         }
         indices.push(i); 
      }  
      return answer;  
    }
};