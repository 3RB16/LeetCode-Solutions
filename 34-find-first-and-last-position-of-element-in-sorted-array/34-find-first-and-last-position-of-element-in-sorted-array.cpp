class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      return search(nums , target);
    }
private:
    vector<int> search(vector <int> arr , int target) {
       int begin = lower_bound(arr.begin() , arr.end() , target) - arr.begin();
       int end = upper_bound(arr.begin() , arr.end() , target) - arr.begin() - 1;
       if(end < arr.size() && arr[end] == target)
           return vector <int> {begin , end};
        return vector <int> {-1 , -1};
    }
};