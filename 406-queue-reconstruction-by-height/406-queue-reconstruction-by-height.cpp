bool compare(vector<int> &a,vector<int> &b){
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]>b[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),compare);
        vector<vector<int>> reconstructQueue;
        for(int i = 0;i < (int)people.size();i++){
            if(people[i][1] == reconstructQueue.size())
                reconstructQueue.push_back(people[i]);
            else
                reconstructQueue.insert(reconstructQueue.begin()+people[i][1],people[i]);
        }
        return reconstructQueue;
    }
};
