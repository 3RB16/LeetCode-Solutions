class MyCalendar {
public:
    vector<pair<int , int>> events;
    MyCalendar() {
        events.clear();
    }

    bool book(int start, int end) {
        for(const auto [event_start, event_end] : events) if (event_start < end && start < event_end){
            return false;
        }
        events.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */