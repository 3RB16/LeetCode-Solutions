class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings) , end(meetings));
        
        set <int> available_rooms;
        for(int i = 0;i < n;i++) {
            available_rooms.insert(i);
        }
        // [end time , room number]
        priority_queue<pair<long long, int> , vector<pair<long long , int>>,greater<pair<long long , int>>> used_rooms;

        vector <int> most_used(n , 0);

        for(vector<int> meeting : meetings) {
            long long start = meeting[0] , end = meeting[1];

            while(!used_rooms.empty() && start >= used_rooms.top().first){
                auto [end_time , room_number] = used_rooms.top();
                used_rooms.pop();
                available_rooms.insert(room_number);
            }

            if(available_rooms.empty()) {
                auto [end_time , room_number] = used_rooms.top();
                used_rooms.pop();
                available_rooms.insert(room_number);
                end = (end - start) + end_time;
            }

            int cur_room = *available_rooms.begin();
            used_rooms.push(
                make_pair(end , cur_room)
            );
            available_rooms.erase(cur_room);
            most_used[cur_room]++;
        }

        int most_booked = 0;
        for(int i = 1;i < n;i++) if(most_used[i] > most_used[most_booked]){
            most_booked = i;
        }

        return most_booked;
    }
};