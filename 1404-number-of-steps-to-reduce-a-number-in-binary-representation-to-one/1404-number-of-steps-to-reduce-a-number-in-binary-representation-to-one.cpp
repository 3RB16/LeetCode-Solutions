class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while(s != "1"){
           if(s.back() == '0')s.pop_back();
           else {
            while (!s.empty() && s.back() == '1') {
				s.pop_back();
				++steps;
			}

			if (s.empty())
                return steps + 1;
			else
			   s.back() = '1';
           }
           ++steps;
        }
        return steps;
    }
};