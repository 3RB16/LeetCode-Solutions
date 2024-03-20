            if (!marked[index]){
                sum -= nums[index] , marked[index] = true;
                unmarked.erase(make_pair(nums[index] , index));
            }
            while(!unmarked.empty() && value-- > 0) {
                auto [value , index] = *unmarked.begin();
                sum -= value, marked[index] = true;
                unmarked.erase(unmarked.begin());
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
[1,2,2,1,2,3,1]
