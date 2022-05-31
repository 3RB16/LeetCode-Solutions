class Solution {
public:
    bool match(string& s, string& p, int i, int j, vector<vector<int>>& cache){
        if(i == s.size() && j == p.size())
            return true;
        else if(i == s.size()) 
            return (p[j] == '*' && match(s,p,i ,j + 1,cache));
        else if(j == p.size())
            return false;
        
        if(~cache[i][j]) return cache[i][j];
        
        if(p[j] == '*')
            return cache[i][j] = (match(s,p,i ,j + 1,cache)||match(s,p ,i + 1,j,cache));
        
        if(p[j] == '?'|| s[i] == p[j])
            return cache[i][j] = match(s,p,i + 1 , j + 1,cache);
        
        return false;
    }
    
    bool isMatch(string s, string p) {
       vector<vector<int>> cache(s.size(), vector<int>(p.size(), -1));  
       return match(s , p , 0 , 0 , cache);
    }
};