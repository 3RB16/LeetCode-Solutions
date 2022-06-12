class Solution {
public:
    bool isValid(string s) {
        stack <char> opened;
        
        for(auto item : s) {
            if(opened.empty()){
               if(item == '(' || item == '{' || item == '[')
                   opened.push(item);
                else 
                    return false;
            }else if(item == '(' || item == '{' || item == '[') {
                opened.push(item);
            }else if(opened.top() == '(' && item == ')'){
                opened.pop();
            }else if(opened.top() == '[' && item == ']'){
                opened.pop();
            }else if(opened.top() == '{' && item == '}'){
                opened.pop();
            }else{
                return false;
            }
        }
        return opened.empty();
    }
};