class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> maxHeap;
        int sum = 0;
        for(auto course : courses) {
            sum += course[0];
            maxHeap.push(course[0]);
            if(sum > course[1]) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};